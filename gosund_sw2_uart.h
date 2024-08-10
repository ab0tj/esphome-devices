#include "esphome.h"
using namespace esphome;

class GosundSW2Uart : public Component, public UARTDevice {
    protected:
        light::LightState *dimmer_{nullptr};

    public:
        GosundSW2Uart(UARTComponent *parent, light::LightState *dimmer)
            : UARTDevice(parent), dimmer_(dimmer) {}    // Need a pointer to the light component we're controlling

    void setup() override {
        // nothing to do here
    }

    void loop() override {
        if (Serial.available() >= 5)
        {
            char buff[5];
            while (Serial.available()) Serial.readBytes(buff, 5);

            float dimmerVal = buff[1] / 100.0;

            id(set_by_touch) = true;    /* Prevent sending the value back to the hardware */
            auto call = dimmer_->turn_on();
            call.set_brightness(dimmerVal);
            call.perform();
            
            ESP_LOGD("gosund_sw2_uart", "Received dimmer value %02X", buff[1]);
        }
    }
};
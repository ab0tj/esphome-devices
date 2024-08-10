#include "esphome.h"
using namespace esphome;

class GosundSW2Output : public Component, public FloatOutput
{
    public:
        void setup() override
        {
            // This will be called by App.setup()
        }

        void write_state(float state) override
        {
            if (id(set_by_touch))
            {   /* Prevent sending the value back to the hardware */
                id(set_by_touch) = false;
                return;
            }

            // Write to HW
            uint8_t dimmerVal = 0;
            
            if (state > 0.0)
            {
                dimmerVal = (127.0 * state) + 0.5;
                dimmerVal |= 0x80;  /* Bit 7 seems to control the relay */
            }

            ESP_LOGD("gosund_sw2_out", "Writing dimmer value %02X", dimmerVal);
            Serial.write(dimmerVal);
        }
};
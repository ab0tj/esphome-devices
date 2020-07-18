A collection of esphome configs for various devices. Saved here for posterity and in the hopes it may help someone else out.

To use, copy the esphome-devices folder into your config/esphome folder. Create a YAML file in your config/esphome folder using the below as an example.
Check the YAML file for the device to find out what substitutions you need to fill in. They look like "${friendly_name}"

```yaml
substitutions:
  device_name: garage_door
  friendly_name: Garage Door

<<: !include esphome-devices/d1_mini_covercontrol.yaml
```

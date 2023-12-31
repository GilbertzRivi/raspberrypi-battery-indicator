# raspberrypi-battery-indicator
battery indicator using esp32 microcontroller and python code

# requirements installation
WORKS ONLY WITH X11 BACKEND!

```sudo apt install python3-full python3-venv``` 

```python3 -m venv battery_venv```

```source battery_venv/bin/activate```

```pip install -r path/to/requirements.txt```

to exit venv: ```deactivate```

# My configuration:
Im using xiao ESP32C3. 
ESP's Analog pin is connected to a voltage divider:

VCC - 10k ohm resistor - Analog pin - 2k ohm resistor - GND

this gives about 2.8V on the analog pin while the battery is full

Im using 4s 14,8V battery, the resistor configuration will be different according to your battery
# you should create a voltage divider that creates voltage safe for your microcontroller when the battery is full!

# reading is inconsistent
Add 10uF cappacitor between VCC and GND on your battery and 1uF cappacitor bettwen analog pin and gnd on your microcontroller and connect gnd of your microcontroller directly to gnd on your battery

# Launch 
edit esp_voltage_reading.ino and add values that work for your configuration and flash the microcontroller, add batteryindicator.py to autostart on rpi, connect your microcontroller to USB/Serial port of rpi.

# My configuration to add this to autostart
Here is a tutorial on creating .desktop files https://dev.to/ha7shu/how-to-create-a-desktop-entry-in-linux-23p9

Create a ```/home/pi/.config/autostart/battery.desktop``` file, as Exec= argument pass ```/home/pi/battery.sh``` file, and into this shell file put ```/bin/bash -c "source /home/pi/battery_venv/bin/activate && python3 /home/pi/batteryindicator.py"```. Other configurations wouldn't work for me and I spend 2 hours on this, so here you are don't waste your time. 😄

Anyway if you want to do it yourself, here is a detailed tutorial: https://github.com/thagrol/Guides/tree/main=

----------------------------------

if you have any questions you can dm me on telegram: @GilbertzRivi

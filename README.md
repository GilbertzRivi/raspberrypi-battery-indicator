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

```VCC - 10k ohm resistor - Analog pin - 2k ohm resistor - GND```

this gives about 2.8V on the analog pin while the battery is full

Im using 4s 14,8V battery, the resistor configuration will be different according to your battery

Here is a online tool to create a voltage divider: https://ohmslawcalculator.com/voltage-divider-calculator Input your source voltage (full battery voltage), and desired resistor values to check the output voltage

IMPORTANT 

Be aware that there are many versions of microcontrollers, some of them have ADC that accept up to 3.3V and some of them accept only up to 1V. Create your voltage divider according to that not to damage your microcontroller!

# what to do when the reading is inconsistent
Add 10uF cappacitor between VCC and GND on your battery and 1uF cappacitor bettwen analog pin and gnd on your microcontroller and connect gnd of your microcontroller directly to gnd on your battery. You can also use bigger cappacitors, its up to you.

# Launch 
edit esp_voltage_reading.ino and add values that work for your configuration and flash the microcontroller, add batteryindicator.py to autostart on rpi, connect your microcontroller to USB/Serial port of rpi.

# How to know what I should put in the "x" variable in esp_voltage_reading.ino?
flash this code:
```
int analogPin = A0; //change this to your pin
unsigned int sum = 0;
float avarage;
void setup(){
  Serial.begin(9600);
  pinMode(analogpin, INPUT);
  for (int i=0; i<10; i++){
    sum += analogRead(analogPin);
    delay(1000);
  }
  avarage = sum/10;
  Serial.println(avarage);
}
void loop(){
}
```
then divide the battery voltage in V by the avarage, for example: 16.28 / 3929, the result (in this example 0.0041435479765844) is the value you should put as x variable in esp_voltage_reading.ino

# My configuration to add this to autostart
Here is a tutorial on creating .desktop files https://dev.to/ha7shu/how-to-create-a-desktop-entry-in-linux-23p9

Create a ```/home/pi/.config/autostart/battery.desktop``` file, as Exec= argument pass ```/home/pi/battery.sh``` file, and into this shell file put ```/bin/bash -c "source /home/pi/battery_venv/bin/activate && python3 /home/pi/batteryindicator.py"```. Other configurations wouldn't work for me and I spend 2 hours on this, so here you are don't waste your time. 😄

Anyway if you want to do it yourself, here is a detailed tutorial: https://github.com/thagrol/Guides/tree/main=

----------------------------------

if you have any questions you can dm me on telegram: @GilbertzRivi

# raspberrypi-battery-indicator
battery indicator using esp32 microcontroller and python code

# My configuration:
ESP's Analog pin is connected to a voltage divider 
VCC - 10k ohm resistor - Analog pin - 2k ohm resistor - GND
this gives about 2.8V on the analog pin while the battery is full

Im using 4s 14,8V battery, the resistor configuration will be different according to your battery
# you should create a voltage divider that creates voltage safe for your microcontroller when the battery is full!

# reading is incosistant
Add 10uF cappacitor between VCC and GND on your battery and 1uF cappacitor bettwen analog pin and gnd on your microcontroller and connect gnd of your microcontroller directly to gnd on your battery

if you have any questions you can dm me on telegram: @GilbertzRivi

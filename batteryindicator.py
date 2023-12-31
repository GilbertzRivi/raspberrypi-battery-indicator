import pystray
import time
import serial
import threading
from PIL import Image, ImageDraw, ImageFont

# set this location to the location of the font of your choice
font_location = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"

image = Image.open('path-to-placeholder-icon.png')

# Serial port setup
ser = serial.Serial(
        port='/dev/ttyACM0', # set it up to the location of your serial port
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1,
)

# function that updates the icon according to serial reading
def update_icon():
    while True:
        if ser.in_waiting > 0:
            # reading serial 
            x = ser.readline()
            x = x.decode('utf-8').rstrip()
            x = str(int(float(x)*100)) + "%"
            # creating icon image
            img = Image.new("RGB", (32,32), (255, 255, 255))
            draw = ImageDraw.Draw(img)
            font = ImageFont.truetype(font_location, 14)
            draw.text((0,8), x, (0,0,0), font=font)
            # update the icon
            icon.icon = img
        # this has to be the same delay as used in your microconttoller 
        time.sleep(1)

if __name__ == '__main__':
    icon = pystray.Icon("battery", image)
    thread = threading.Thread(target=update_icon)
    thread.start()
    icon.run()

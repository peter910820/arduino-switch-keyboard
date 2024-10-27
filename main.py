import serial
from pynput.keyboard import Key, Controller
import time

ser = serial.Serial('COM5', 9600)
keyboard = Controller()

time.sleep(2)
    
while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode().strip()
        if data == "enter":
            keyboard.press(Key.enter)
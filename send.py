import pyautogui as pt
from time import sleep
import pyperclip
import os
from pynput.keyboard import Key, Controller
keyboard = Controller()

sleep(5)
position1 = pt.locateOnScreen("smiley.png", confidence=.6)
x = position1[0]+24
y = position1[1]+28
read = open("transaction.txt","r")
list_mess = read.readlines()
pt.moveTo(x + 200, y , duration=.3)
sleep(0.5)
pt.click()
for i in list_mess:
    i=i.strip()
    pt.write(i, interval=.0001)
    #print(i)
    with keyboard.pressed(Key.shift):
        keyboard.press(Key.enter)
        keyboard.release(Key.enter)
pt.press("enter")

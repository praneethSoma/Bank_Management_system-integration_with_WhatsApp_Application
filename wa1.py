import pyautogui as pt
from time import sleep
import pyperclip
import os
from pynput.keyboard import Key, Controller

keyboard = Controller()

#sleep(5)

#locating multiple locations
position1 = pt.locateOnScreen("smiley.png", confidence=.6)
x = position1[0]+24
y = position1[1]+28
bank1 = x-514
bank2 = y-798
profile1 = x+46
profile2 = y-932

#go to group
def safe_place():
    global bank1 , bank2
    pt.moveTo(bank1, bank2,duration = .2)
    pt.click()

#gets mobile
def get_number():
    global profile1 , profile2
    pt.moveTo(profile1 , profile2, duration = .3)
    pt.tripleClick()
    #scrol down
    pt.moveTo(profile1+1253 , profile2+882, duration = .3)
    pt.tripleClick()
    #move to number
    pt.moveTo(profile1+770 , profile2+605, duration = .3)
    sleep(0.25)
    pt.tripleClick()
    pt.tripleClick()
    pt.rightClick()
    pt.moveRel(12,15)
    pt.click()
    mobile = pyperclip.paste()
    pt.click()
    
    return mobile

#gets message
def get_message():
    global x,y
    pt.moveTo(x,y, duration=.05)
    pt.moveTo(x + 96, y - 83, duration = .3)
    pt.tripleClick()
    pt.rightClick()
    pt.moveRel(12,15)
    pt.click()
    whatsapp_message = pyperclip.paste()
    pt.click()

    return whatsapp_message
    
#Check if there is a new message
def check_for_new_messages():
    while True:
        try:
            global position , x ,y
            position = pt.locateOnScreen("circle.png", confidence = .7)
            #position = [positionz[-2],positionz[-1]]
            if position is not None:
                pt.moveTo(position)
                pt.moveRel(-100,0)
                pt.click()
                message = get_message()
                mobile = get_number()
                mobile = mobile[4:9]+mobile[10:]
                print("message received: " + message + " from " + mobile)
                
                #write the message and number to a file.
                write = open("message.txt","w")
                write.write(mobile)
                write.write(' ')
                write.write(message)
                #write.write(' ')
                #write.write(mobile)
                write.close()
                
                os.system("pass_c.bat")
                
                read = open("reply.txt","r")
                list_mess = read.readlines()
                pt.moveTo(x + 200, y , duration=.4)
                pt.click()
                for i in list_mess:
                    i=i.strip()
                    pt.write(i, interval=.0001)
                    with keyboard.pressed(Key.shift):
                        keyboard.press(Key.enter)
                        keyboard.release(Key.enter)
  
                pt.press("enter")
             
                safe_place()
                #sleep(5)
            else:
                print("No messages")
                #sleep(5)

        except(Exception):
            print("No new messages")

#Beginning
if __name__ == "__main__":
    safe_place()
    check_for_new_messages()

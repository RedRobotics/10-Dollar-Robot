import network
import espnow
import ubinascii
import time
from machine import Pin

# A WLAN interface must be active to send()/recv()
sta = network.WLAN(network.STA_IF)
sta.active(True)
#sta.disconnect()   # Because ESP8266 auto-connects to last Access Point

e = espnow.ESPNow()
e.active(True)

# Set up motors
M1a = Pin(18, Pin.OUT)
M1b = Pin(19, Pin.OUT)

M2a = Pin(25, Pin.OUT)
M2b = Pin(26, Pin.OUT)


data =[0,0,0,0,0,0,0,0,0,0,0,0] # List to store controller data
count = 0
UP = 0
DOWN = 0
LEFT = 0
RIGHT = 0

print("Press CTRL-C now to stop program")
time.sleep(2)
print("Start")

while True:
    host, msg = e.recv()
    if msg:             # msg == None if timeout in recv()
        if msg == b'start': # Look for the start of the message and reset the count
            count = 0
            
        if count != 0:
            data[count] = int(msg) # Load the message data into the list
            
        count +=1
        
        if count == 12: # End of message
            count = 0
            #Uncomment the following line to show all data from the controller
            #print('{:03d}'.format(data[1]),'{:03d}'.format(data[2]),data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11])
   
        if data[3] == 0 and UP == 0:
            UP = 1
            print("UP Pressed")
            M1a.value(0)
            M1b.value(1)
            M2a.value(0)
            M2b.value(1)
            
        elif data[3] == 1 and UP == 1:    
            UP = 0
            print("UP Released")
            M1a.value(0)
            M1b.value(0)
            M2a.value(0)
            M2b.value(0)
           
        if data[4] == 0 and DOWN == 0:
            DOWN = 1
            print("DOWN Pressed")
            M1a.value(1)
            M1b.value(0)
            M2a.value(1)
            M2b.value(0)
            
        elif data[4] == 1 and DOWN == 1:    
            DOWN = 0
            print("DOWN Released")
            M1a.value(0)
            M1b.value(0)
            M2a.value(0)
            M2b.value(0)
            
            
        if data[5] == 0 and LEFT == 0:
            LEFT = 1
            print("LEFT Pressed")
            M1a.value(1)
            M1b.value(0)
            M2a.value(0)
            M2b.value(1)
            
        elif data[5] == 1 and LEFT == 1:    
            LEFT = 0
            print("LEFT Released")
            M1a.value(0)
            M1b.value(0)
            M2a.value(0)
            M2b.value(0)
            
            
        if data[6] == 0 and RIGHT == 0:
            RIGHT = 1
            print("RIGHT Pressed")
            M1a.value(0)
            M1b.value(1)
            M2a.value(1)
            M2b.value(0)
            
        elif data[6] == 1 and RIGHT == 1:    
            RIGHT = 0
            print("RIGHT Released")
            M1a.value(0)
            M1b.value(0)
            M2a.value(0)
            M2b.value(0)
      


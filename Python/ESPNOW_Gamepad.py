import network
import espnow
from machine import Pin, ADC
from time import sleep

Y_Pot = ADC(Pin(36))
Y_Pot.atten(ADC.ATTN_11DB) #  0 - 3.3V range
Y_Pot.width(ADC.WIDTH_9BIT)
X_Pot = ADC(Pin(39))
X_Pot.atten(ADC.ATTN_11DB) #  0 - 3.3V range
X_Pot.width(ADC.WIDTH_9BIT)

UP = Pin(5, Pin.IN, Pin.PULL_UP)
DOWN = Pin(15, Pin.IN, Pin.PULL_UP)
LEFT = Pin(16, Pin.IN, Pin.PULL_UP)
RIGHT = Pin(4, Pin.IN, Pin.PULL_UP)

L1 = Pin(32, Pin.IN, Pin.PULL_UP)
R1 = Pin(23, Pin.IN, Pin.PULL_UP)
L2 = Pin(33, Pin.IN, Pin.PULL_UP)

START = Pin(14, Pin.IN, Pin.PULL_UP)
SELECT = Pin(13, Pin.IN, Pin.PULL_UP)

# A WLAN interface must be active to send()/recv()
sta = network.WLAN(network.STA_IF)  # Or network.AP_IF
sta.active(True)
#sta.disconnect()      # For ESP8266

e = espnow.ESPNow()
e.active(True)
peer = b'\x0A\x0B\x0C\x0D\x0E\x0F'   # MAC address of peer's wifi interface
e.add_peer(peer)      # Must add_peer() before send()
print("Start")

while True:
    Y_Raw = Y_Pot.read()
    X_Raw = X_Pot.read()
    Y = int(Y_Raw/2) # Convert to 8bit
    X = int(X_Raw/2) # Convert to 8bit
    
    e.send(peer, b'start', True)
    
    e.send(peer, str(Y), True)
    e.send(peer, str(X), True)
    
    e.send(peer, str(UP.value()), True)
    e.send(peer, str(DOWN.value()), True)
    e.send(peer, str(LEFT.value()), True)
    e.send(peer, str(RIGHT.value()), True)
    
    e.send(peer, str(L1.value()), True)
    e.send(peer, str(R1.value()), True)
    e.send(peer, str(L2.value()), True)
    e.send(peer, str(START.value()), True)
    e.send(peer, str(SELECT.value()), True)
    
  


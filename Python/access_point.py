# This file is executed on every boot (including wake-boot from deepsleep)
#import esp
#esp.osdebug(None)
import network
import webrepl
webrepl.start()

#Set up ESP32 as access point
ssid = 'MP_AP'
password = '123456789'

ap = network.WLAN(network.AP_IF);
ap.active(True);
ap.config(essid=ssid,authmode=network.AUTH_WPA_WPA2_PSK, password=password)
print(ap.ifconfig())

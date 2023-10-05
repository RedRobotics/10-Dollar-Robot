import network
import ubinascii

wlan_sta = network.WLAN(network.STA_IF)
wlan_sta.active(True)

#  https://stackoverflow.com/questions/71902740/how-to-retrieve-and-format-wifi-mac-address-in-micropython-on-esp32     
print(ubinascii.hexlify(wlan_sta.config('mac'),':').decode().upper())

/*************************************************************

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - ESP32 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME         "Robot Control Pad"
#define BLYNK_AUTH_TOKEN            "YOUR_AUTH_TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  if (value== 1)
  {
    Serial.println("LED On");
    digitalWrite(2, HIGH);
  }

  if (value== 0)
  {
    Serial.println("LED Off");
    digitalWrite(2, LOW);
  }

  // Update state
  Blynk.virtualWrite(V1, value);

}

//Forwards
BLYNK_WRITE(V2)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if (value== 1)
  {
    Serial.println("Forwards");
    digitalWrite(18, 0);
    digitalWrite(19, 1);
    digitalWrite(25, 0);
    digitalWrite(26, 1);
  }

  if (value== 0)
  {
    Serial.println("Stop");
    digitalWrite(18, 0);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 0);
  }
}


//Backwards
BLYNK_WRITE(V3)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if (value== 1)
  {
    Serial.println("Backwards");
    digitalWrite(18, 1);
    digitalWrite(19, 0);
    digitalWrite(25, 1);
    digitalWrite(26, 0);
  }

  if (value== 0)
  {
    Serial.println("Stop");
    digitalWrite(18, 0);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 0);
  }
}


//Left
BLYNK_WRITE(V4)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if (value== 1)
  {
    Serial.println("Left");
    digitalWrite(18, 1);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 1);
  }

  if (value== 0)
  {
    Serial.println("Stop");
    digitalWrite(18, 0);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 0);
  }
}


//Right
BLYNK_WRITE(V5)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if (value== 1)
  {
    Serial.println("Right");
    digitalWrite(18, 0);
    digitalWrite(19, 1);
    digitalWrite(25, 1);
    digitalWrite(26, 0);
  }

  if (value== 0)
  {
    Serial.println("Stop");
    digitalWrite(18, 0);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 0);
  }
}


//Stop
BLYNK_WRITE(V6)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if (value== 1)
  {
    Serial.println("Stop");
    digitalWrite(18, 0);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 0);
  }

  if (value== 0)
  {
    Serial.println("Stop");
    digitalWrite(18, 0);
    digitalWrite(19, 0);
    digitalWrite(25, 0);
    digitalWrite(26, 0);
  }
}



void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(2, OUTPUT); // LED

  pinMode(18, OUTPUT); // Motor 1a
  pinMode(19, OUTPUT); // Motor 1b

  pinMode(25, OUTPUT); // Motor 2a
  pinMode(26, OUTPUT); // Motor 2b

}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

#include <PS4Controller.h>

//Set up variables
int LX = 0;
int LY = 0;
int R_X = 0;
int RY = 0;

int LX_old = 0;
int LY_old = 0;
int RX_old = 0;
int RY_old = 0;
int deadBand = 8;
bool connected = 0;

void setup() {
  Serial.begin(115200);
  PS4.begin("0A:0B:0C:0D:0E:0F");
  Serial.println("Ready.");
  delay(200);
}

void loop() {
  if ((PS4.isConnected()) && (connected != 1)) {
    Serial.println("Connected!");
    Serial.printf("Battery Level : %d\n", PS4.Battery());
    connected = 1;  
  }  

  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    if (PS4.Right()) Serial.println("Right Button");
    if (PS4.Down()) Serial.println("Down Button");
    if (PS4.Up()) Serial.println("Up Button");
    if (PS4.Left()) Serial.println("Left Button");

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
    }

    if (PS4.LStickX()) {
      LX = PS4.LStickX();
      //Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      
      // Use the deadband to make sure the value goes back to zero when you let go of the stick.
      if ((LX < deadBand) && (LX > -deadBand)) {
        LX = 0;
      }
    }
    

    if (PS4.LStickY()) {
      LY = PS4.LStickY();
      //Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      
      // Use the deadband to make sure the value goes back to zero when you let go of the stick.
      if ((LY < deadBand) && (LY > -deadBand)) {
        LY = 0;
      }
    }


    if (PS4.RStickX()) {
      R_X = PS4.RStickX();
      //Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      
      // Use the deadband to make sure the value goes back to zero when you let go of the stick.
      if ((R_X < deadBand) && (R_X > -deadBand)) {
        R_X = 0;
      }  
    }


    if (PS4.RStickY()) {
    RY = PS4.RStickY();
      //Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      
      // Use the deadband to make sure the value goes back to zero when you let go of the stick.
      if ((RY < deadBand) && (RY > -deadBand)) {
        RY = 0;
      } 
    }


    // Only print the values if they have changed
    if ((LX != LX_old) || (LY != LY_old) || (R_X != RX_old) || (RY != RY_old)) {
      Serial.printf("LX = %04d, LY = %04d, RX = %04d, RY = %04d\n", LX, LY, R_X, RY);
    }
    LX_old = LX;
    LY_old = LY;
    RX_old = R_X;
    RY_old = RY;


    if (PS4.Charging()) Serial.println("The controller is charging");
    if (PS4.Audio()) Serial.println("The controller has headphones attached");
    if (PS4.Mic()) Serial.println("The controller has a mic attached");

  }
}

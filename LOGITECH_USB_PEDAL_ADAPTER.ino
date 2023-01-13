//How to run:
//Need to use a Arduinio ProMicro or Leonardo
//Need to download and install Joystick liabry from https://github.com/MHeironimus/ArduinoJoystickLibrary
//Install by click the "Sketch" menu and then Include Library > Add .Zip Liabry and the choose the downloed zip folder

//Accessing the Joystick Libary
#include <Joystick.h>

//Creates the Joystick
Joystick_ Joystick;
               
//Varaible for Rotatinoal y Axis               
int RyAxis_ = 0;  
//Varaible for Rotatinoal z Axis
int RzAxis_ = 0;          
//Varaible for Throttle
int Throttle_ = 0;         

//Starts emulating a game controller connected to a computer
const bool initAutoSendState = true; 

//Starts the program. Initalize the vraiables, pin mdoes, start using libraries.
//Setup only runs once after each power up.
void setup()
 {
   Joystick.begin();
 }
   
//Loop function that allows the program to activily change and respond    
void loop(){
  
  //Reads the vaule from the specific analog pin (A0) on the arduinio board
  RyAxis_ = analogRead(A0);
  //Re-maps a number from one range to another
  RyAxis_ = map(RyAxis_,0,1023,0,255);
  //Sets the throttle range to the variable (RyAxis_) 
  Joystick.setRyAxis(RyAxis_);

  //Reads the vaule from the specific analog pin (A1) on the arduinio board
  RzAxis_ = analogRead(A1);
  //Re-maps a number from one range to another
  RzAxis_ = map(RzAxis_,1023,0,255,0);
  //Sets the throttle range to the variable (RzAxis_)              
  Joystick.setRzAxis(RzAxis_);
  
  //Reads the vaule from the specific analog pin (A2) on the arduinio board
  Throttle_ = analogRead(A2);
  //Re-maps a number from one range to another
  Throttle_ = map(Throttle_,1023,0,255,0);
  //Sets the throttle range to the variable (Throttle_)          
  Joystick.setThrottle(Throttle_);                
  
  //Pauses the program for 50ms
  delay (50);
}
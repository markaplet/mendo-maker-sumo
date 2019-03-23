/*

  __  __                _         __  __       _                 
 |  \/  | ___ _ __   __| | ___   |  \/  | __ _| | _____ _ __ ___ 
 | |\/| |/ _ \ '_ \ / _` |/ _ \  | |\/| |/ _` | |/ / _ \ '__/ __|
 | |  | |  __/ | | | (_| | (_) | | |  | | (_| |   <  __/ |  \__ \
 |_|  |_|\___|_| |_|\__,_|\___/  |_|  |_|\__,_|_|\_\___|_|  |___/


Full working code example. This code should only be used in the event 
that you get really stuck and run out of time. Each person should make 
an attempt to write their own sumobot code. 

*/


// DEFINE IR REMOTE KODES BE SURE IT STARTS WITH 0x
#define keyForward 0x20DFA25D
#define keyRight 0x20DFE21D
#define keyBack 0x20DF629D
#define keyLeft 0x20DF12ED
#define keyStop 0x20DFC23D
#define repeatCode 0XFFFFFFFF

#define motorDelay 100  // To low and motors will shutter


// INCLUDE THE REQUIRED LIBRARIES
#include <IRremote.h>
#include <AFMotor.h>


// DEFINE INFARED SENSOR
const int RECV_PIN = 10; // Use Servo 1 on motor shield
IRrecv irrecv(RECV_PIN);
decode_results IRresults;
unsigned long key_value = 0;


// MOTOR PARAMETERS
int MOTOR_SPEED = 255;  // 0 to 255
AF_DCMotor MOTOR_LEFT(1, MOTOR12_64KHZ);  // M1 on shield
AF_DCMotor MOTOR_RIGHT(2, MOTOR12_64KHZ); // M2 on shield


void setup(){
  Serial.begin(9600);

  // IR SETUP
  irrecv.enableIRIn();
  irrecv.blink13(true);

  // MOTOR SETUP
  MOTOR_LEFT.setSpeed(MOTOR_SPEED);
  MOTOR_RIGHT.setSpeed(MOTOR_SPEED);

  // CONFIRM SETUP COMPLETE
  Serial.println("Setup Complete");
}


void loop() {

  if (irrecv.decode(&IRresults)){

    if (IRresults.value == repeatCode)
      IRresults.value = key_value;

    switch(IRresults.value){
      case keyForward:
      Serial.println("Forward");
      forward();
      break;

      case keyLeft:
      Serial.println("Spin Left");
      spinLeft();
      break;
      
      case keyBack:
      Serial.println("Backward");
      backward();
      break;
      
      case keyRight:
      Serial.println("Spin Right");
      spinRight();
      break;

      case keyStop:
      Serial.println("Stoping");
      stop();
      break;
    }
    key_value = IRresults.value;
    irrecv.resume();
  }
  delay(motorDelay);
  stop();   // Optional 
}


// FUNCTIONS
void stop() {
  MOTOR_LEFT.run(RELEASE);
  MOTOR_RIGHT.run(RELEASE);
}

void forward() {
  stop();
  MOTOR_LEFT.run(FORWARD);
  MOTOR_RIGHT.run(FORWARD);
}

void backward() {
  stop();
  MOTOR_LEFT.run(BACKWARD);
  MOTOR_RIGHT.run(BACKWARD);
}

void spinLeft() {
  stop();
  MOTOR_LEFT.run(FORWARD);
  MOTOR_RIGHT.run(BACKWARD);
}

void spinRight() {
  stop();
  MOTOR_LEFT.run(BACKWARD);
  MOTOR_RIGHT.run(FORWARD);
}
/*
  Opporating Servo Motors
  Sweeps a servo motor from 0 to 180 degrees

  Requires the Servo.h library be included
*/
#include <Servo.h>



/*
  Create a variable for storing the servo position. The position will be changed
  dynamically based on the main loop.

  Also create a variable to hold the pin number our servo is plugged into.
*/
int pos = 0;
int servo_pin = 10;



/*
  The setup function runs once when you press reset or power the board. The
  "void" keyword indicates that the function is not expected to return any
  information to the larger program.

   In this lesson we will create the myservo object and attach it to the correct pin
*/
void setup() {
  myservo.attach(servo_pin);
}


/*
  The loop function runs over and over again forever. This is the main loop for
  your application.

  In this lesson we will sweep the motor from 0 degrees to 180 degrees in steps
  of 1 degree.
*/
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // Add 1 step with each loop
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

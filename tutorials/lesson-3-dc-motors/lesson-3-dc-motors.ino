/*
  Opporating DC Motors
  Turns a DC motor on in the forward directions then backwards.

  Requires the Adafruits AFMotor.h library be included 
  Download it from here: https://learn.adafruit.com/adafruit-motor-shield/using-dc-motors
*/
#include <AFMotor.h>



/* 
  Creating a constant variable and using it throughout your application allows you to 
  update the variable once and the change is reflected everywhere it's used. In general
  defining variables that you may need to adjust on the fly is concidered best practice. 

  In this case MOTOR_SPEED can accept any value beteen 0 and 255. In this lesson we will define 
  just one speed, however in practice we way want different speeds for different actions, and 
  defining them at the top of the application makes it easy to adjust speeds for different configurations.
*/
int MOTOR_SPEED = 200;  // 255 is max speed



/* 
  Create an object for each motor.
  Below we will create 2 motors motor objects. one the the left motor and one for the right motor.
  Since our bots may need to drive both wheels seperatly we created two different objects. Using
  this method allows you to spin one wheel forward wand the second wheel backwards.
*/ 
AF_DCMotor MOTOR_LEFT(1, MOTOR12_64KHZ);
AF_DCMotor MOTOR_RIGHT(2, MOTOR12_64KHZ);



/*
  The setup function runs once when you press reset or power the board. The "void" keyword
  indicates that the function is not expected to return any information to the larger program.

   In this lesson we will setup the serial monitor so we can output debugging information, and 
   we will initialize our motor objects with our base speed. MOTOR_SPEED is a variable set to 200
   so it would be equivelent to writing MOTOR_LEFT.setSpeed(200)
*/
void setup() {
  Serial.begin(9600);
  MOTOR_LEFT.setSpeed(MOTOR_SPEED);
  MOTOR_RIGHT.setSpeed(MOTOR_SPEED);
}


/*
  The loop function runs over and over again forever. This is the main loop for your application. 
*/
void loop() {
  forward();    // This is the forwards function
  delay(2000);  // Drive forward for 2 seconds
  
  backward();   // This is the backwards function
  delay(2000);  // Drive backwards for 2 seconds
}



/*
  This function is outside the main loop, but it could have just as well been written 
  in the main loop above. Breaking a larger application into smaller functions can 
  help improve readability and the maintainability of your code. In this lesson we
  created three functions for driving forwards, backwards, and stoppping the motors.
  Note how both the forward and backward functions call the stop() function. Functions
  can call other functions allowing you to create reusable and modular code.
*/
void forward() {
  Serial.println("Motors Forward");
  stop();   // Be friendly to the motor: stop it before changing direction.
  MOTOR_LEFT.run(FORWARD);
  MOTOR_RIGHT.run(FORWARD);
}

void backward() {
  Serial.println("Motors Backwards");
  stop();   // Be friendly to the motor: stop them before changing directions.
  MOTOR_LEFT.run(BACKWARD);
  MOTOR_RIGHT.run(BACKWARD);
}

void stop() {
  Serial.println("Motors Stopped");
  MOTOR_LEFT.run(RELEASE);
  MOTOR_RIGHT.run(RELEASE);
}


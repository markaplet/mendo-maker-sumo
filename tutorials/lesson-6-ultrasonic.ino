/*
  Detect distance with ultrasonic sensor

  An ultrasonic sensor can detect objects in front of it's field of view. The
  distance to the object is reported back in centimeters. In this lesson we will
  use the ultrasonic sensor to detect an object like a bot and report the
  distance to the serial monitor. Using this information we could instruct our
  bot to attack or deploy an defensive mechanisim, or perhaps an offensive
  flipping mechanic.

  Requires the NewPing.h library be included
  Download it from here: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
*/
#include <NewPing.h>



/*
  Ultrasonic sensors work by sending out ultrasonic waves and measuring time
  lapses between the sending and receiving of the ultrasonic pulse. Ultrasound
  is reliable in any lighting environment and can be used inside or outside.
  Ultrasonic sensors are popular in robotics applications as a method of detecting
  objects or colisions. While ultrasonic sensors work well independent of light,
  smoke, dust, color, they can be tricked by surfaces that absorb ultrasond. for
  example wool can absorb sound waves.

  The ultrasonic sensors we are using have the wiring schematic conviently printed
  on the module. e.g. Vcc (5v Power), Trigger, Echo, Ground. We use pins 9 and 10
  for the echo and triger functions respectivly.
*/
#define US_TRIGGER            10    // Trigger pin on the ultrasonic sensor => use servo 1 pin on shield
#define US_ECHO               9     // Ultrasonic sensor => Use servo 2 pin on shield
#define US_MAX_DISTANCE       60    // Maximum distance to ping (in centimeters)
NewPing sonar(US_TRIGGER, US_ECHO, US_MAX_DISTANCE);  // Create the object




/*
   In this lesson we will setup the serial monitor so we can output the objects
   distance to the serial monitor.
*/
void setup(){
  Serial.begin(9600);
}


void loop() {
   delay(200);            // Delay added to slow the serial monitor output down
   unsigned int uS = sonar.ping_cm(); // Get the distance
   Serial.print(uS);      // print the value of uS (note the use of print() function)
   Serial.println("cm");  // add 'cm' text to make output more clear
}

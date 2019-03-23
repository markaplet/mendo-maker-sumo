# Mendocino Makers Group: Introduction to Sumobots

The goal of this project is to introduce basic robotics concepts through a 1 day instructor lead hardware and coding challenges with the final product being a user controlled sumobot that is capable of competing with our piers.

## Prerequisites

* Laptop with an available USB port
* [Install Arduino IDE](https://www.arduino.cc/en/main/software)
* Infrared (IR) Remote

## Installing Libraries
For this workshop we will install two library files into our Arduino IDE. Libraries are a collection of code that makes it easy for you to connect to a sensor, display, module, etc. 

For this workshop we will need to download the following two libraries:
* [Adafruit Motor Shield v1.0](https://learn.adafruit.com/adafruit-motor-shield/library-install)
* [Arduino IRremote](http://z3t0.github.io/Arduino-IRremote/)

To install a new library into your Arduino IDE, open the IDE and click to the "Sketch" menu and then Include Library > Add .ZIP Library... You will be prompted to select the library you would like to add. Navigate to the .zip file's location and open it. The library should now be available to use.

There are other methods of adding and managing libraries too. Check out the official [Arduino Library Install Guide](https://www.arduino.cc/en/Guide/Libraries) for step by step instructions and more information.

## Parts List

* 1 SainSmart Arduino Uno
* 1 SainSmart Motor Shield
* Laser cut SumoBot Chassis
  * 2 side panels
  * 1 top panel
  * 1 bottom panel
  * 1 front plate
* 2 gear motors
* 2 black, 2 red wire leads for motors
* 2 plastic wheels
* 1 90 degree servo motor
* 1 Ultrasonic sensor
* 1 Infrared receiver and transmitter diode
* 3 9v batteries
* 1 9v battery clip
* 1 USB Cable
* 1 plastic ball bearing holder
* 1 5/8" ball bearing
* 18 prototyping jumper wires
  * 6 male / male
  * 6 male / female
  * 6 female / female
* 4 3/8 #6 screws

## Lesson Plan

If this is your first time experimenting with hardware or new to coding check out the included tutorials. Each lesson covers one aspect of the sumobot integration. At the end you will have a fundamental understanding of how each component works and how you could control them.

Before you begin uploading your code to the arduino you may need to first install the [standard firmata](https://www.instructables.com/id/Arduino-Installing-Standard-Firmata/). Don't worry it's super simple.

* [Lesson 1 - Hello World LED Blink](tutorials/lesson-1-led-blink/lesson-1-led-blink.ino)
* [Lesson 2 - Operating a servo](tutorials/lesson-2-servo-motor/lesson-2-servo-motor.ino)
* [Lesson 3 - Operating a DC motor](tutorials/lesson-3-dc-motors/lesson-3-dc-motors.ino)
* [Lesson 4 - Reading IR Codes](tutorials/lesson-4-ir-codes/lesson-4-ir-codes.ino)
* [Lesson 5 - Decision making based on IR code](tutorials/lesson-5-ir-logic/lesson-5-ir-logic.ino)
* [Lesson 6 - Ultrasonic Sensors](tutorials/lesson-6-ultrasonic/lesson-6-ultrasonic.ino)

Combine all of these skills to build your sumobot! As with most programming exercises, it's best to prototype your bot and code in small chunks checking each new feature or change as you go. It's easier to catch a mistake when you are testing a small piece of code and not disassembling hardware from the chassis.

## Chassis Construction

The sumobot chassis is laser cut from 3mm plywood and can be assembled with nothing more than a screwdriver and possibly some hot glue. While it's pretty durable it is still only wood and can splinter or break if handled roughly. For those that like to see a video, check out [Norfolk.js - Chassis Assembly video](https://www.youtube.com/watch?v=xHns3qxffYM)

1. Mount the ball bearing holder to the bottom plate using two of the 3/8" screws
2. Mount the Arduino Uno to the top plate using two of the 3/8" screws. Orientate the USB plug to the rear of the sumobot
3. Attach a motor to each side plate using two of the 1" bolts and nuts
4. Insert the tabs for the bottom plate into the side plates
5. Insert the top plate tabs into the side plate holes
6. It may be necessary to add a dab of hot glue to the tabs to hold the chassis securely in place
7. Attach the front plate by inserting the tabs of the side plates into the slots of the front panel
8. Carefully attach the wheels to each motor being careful to apply pressure to the wheel and motor and not the chassis itself
9. Press the 5/8" ball bearing into the holder
10. Install the motor shield on top of the Arduino
11. Attach the battery clip to the shields EXT_PWR block

## Wire Connections

* Solder a red and black wire leads onto the tabs near the cap of of the motor
  * Left = red (+)
  * Right = black (-)
* Install motor shield on top of Arduino. It will only fit one way
* Plug the left motor wires into the M1 block of your shield
* Plug the right motor wires into the M2 block of your shield
* M1 and M2 block wiring: red | black | not used | red | black

## Additional Resources

* [Adafruit - Using DC Motors](https://learn.adafruit.com/adafruit-motor-shield/using-dc-motors)
* [Adafruit Motor Shield Library](https://learn.adafruit.com/adafruit-motor-shield/library-install)
  * [Motor Shield Schematic](https://www.14core.com/wp-content/uploads/2015/07/L293D-Wired-4-Motor-with-servo.jpg)
* [Arduino IRremote Library](http://z3t0.github.io/Arduino-IRremote/)
  * [Ifrared Diode Schematic](http://www.circuitbasics.com/wp-content/uploads/2017/05/IR-Receiver-Stand-Alone-Pinout-Diagram.png)
* [Micro Servo Motor Schematic](https://components101.com/sites/default/files/component_pin/Servo-Motor-Wires.png)
* [New Ping Ultrasonic Library](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
  * [Ultrasonic Schematic](https://components101.com/sites/default/files/component_pin/Ultrasonic-sensor-pinout.png)

## Issues

Both the DCMotor Library and the IRRemote library use the TIMER2 resource. When two libraries attempt to use the same resource, it will cause your code to fail in some way. The solution I found was to change two lines in the IRremote library > boarddefs.h to use TIMER1. Remove the comments for `#define IR_USE_TIMER1` on line 152. Then add `//` comments for line 153. The completed change should look like this:

```
#define IR_USE_TIMER1   // tx = pin 9
//#define IR_USE_TIMER2     // tx = pin 3
```

NewPing library also uses TIMER1 resource which [conflicts with other libraries](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Multiple%20Definition%20of%20%22__vector_7%22%20Error). NewPing.h library must be modified to disable the TIMMER_ENABLED value on line 153 by setting it to false

## Final Code

If you get totally stuck, run out of time, or for whatever reason you cannot get your bot programmed, I have written a [very basic starter program](tutorials/completed-code/completed-code.ino) to get you going. Use it only as a last resort. 
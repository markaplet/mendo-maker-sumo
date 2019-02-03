# Mendocino Makers Group: Introduction to Sumobots

The goal of this project is to introduce basic robotics concepts through a 1 day instructor lead hardware and coding challenges with the final product being a user controlled sumobot that is capable of competing with our piers.

## Prerequisites

* Laptop with an available USB port
* [Install Arduino IDE](https://www.arduino.cc/en/main/software)
* Infrared (IR) Remote

## Parts List

* 1 SainSmart Arduino Uno
* 1 SainSmart Motor Shield
* Laser cut SumoBot Chassis
  * 2 side panels
  * 1 top panel
  * 1 bottom panel
  * 1 front plate
* 2 motors
* 2 plastic wheels
* 1 90 degree servo motor
* 1 Ultrasonic sensor with mounting bracket
* 3 9v batteries
* 1 9v battery clip
* 1 6ft. USB Cable
* 1 plastic ball bearing holder
* 1 5/8" ball bearing
* 18 prototyping jumper wires
  * 6 male / male
  * 6 male / female
  * 6 female / female
* 4 3/8 #6 screws

## Lesson Plan

If this is your first time experimenting with hardware or new to coding check out the included tutorials. Each lesson covers one aspect of the sumobot integration. At the end you will have a fundamental understanding of how each component works and how you could control them.

* [Lesson 1 - Hello World LED Blink](tutorials/lesson-1-led-blink.ino)
* [Lesson 2 - Operating a servo](tutorials/lesson-2-servo-motor.ino)
* [Lesson 3 - Operating a DC motor](tutorials/lesson-3-dc-motors.ino)
* [Lesson 4 - Reading IR Codes](tutorials/lesson-4-ir-codes.ino)
* [Lesson 5 - Decision making based on IR code](tutorials/lesson-5-ir-logic.ino)
* [Lesson 6 - Ultrasonic Sensors](tutorials/lesson-6-ultrasonic.ino)

Combine all of these skills to build your sumobot! As with most programming exercises, it's best to prototype your bot and code in small chunks checking each new feature or change as you go. It's easier to catch a mistake when you are testing a small piece of code and not disassembling hardware from the chassis.

## Chassis Construction

The sumobot chassis is laser cut from 3mm plywood and can be assembled with nothing more than a screwdriver and possibly some hot glue. While it's pretty durable it is still only wood and can splinter or break if handled roughly. For those that like to see a video, check out [Norfolk.js - Chassis Assembly video](https://www.youtube.com/watch?v=xHns3qxffYM)

1. Mount the ball bearing holder to the bottom plate using two of the 3/8" screws
2. Mount the Arduino Uno to the top plate using two of the 3/8" screws
3. Attach a motor to each side plate using two of the 1"  bolts and nuts
4. Insert the tabs for the bottom plate into the side plates
5. Insert the top plate tabs into the side plate holes
6. It may be necessary to add a dab of hot glue to the tabs to hold the chassis securely in place
7. Attach the front plate by inserting the tabs of the side plates into the slots of the front panel
8. Carefully attach the wheels to each motor being careful to apply pressure to the wheel and motor and not the chassis itself
9. Press the 5/8" ball bearing into the holder
10. Install the motor shield on top of the Arduino
11. Attach the battery clip to the shields EXT_PWR block

## Additional Resources

* [Adafruit - Using DC Motors](https://learn.adafruit.com/adafruit-motor-shield/using-dc-motors)
  * [Motor Shield Schematic](https://www.14core.com/wp-content/uploads/2015/07/L293D-Wired-4-Motor-with-servo.jpg)
* [Arduino IRremote Library](http://z3t0.github.io/Arduino-IRremote/)
  * [Ifrared Diode Schematic](http://www.circuitbasics.com/wp-content/uploads/2017/05/IR-Receiver-Stand-Alone-Pinout-Diagram.png)
  * [Micro Servo Motor Schematic](https://components101.com/sites/default/files/component_pin/Servo-Motor-Wires.png)
  * [New Ping Ultrasonic Library](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
    * [Ultrasonic Schematic](https://components101.com/sites/default/files/component_pin/Ultrasonic-sensor-pinout.png)


## Issues

Both the DCMotor Library and the IRRemote library use the TIMER2 resource. This creates a problem when two libraries attempt to use the same resource and will cause your code to fail. The solution I found was to change  IRremoteInt.h to use TIMER1. Remove the comments for `#define IR_USE_TIMER1` on line 224. Then add `//` comments for line 225.

NewPing library also uses TIMER1 resource which [conflicts with other libraries](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Multiple%20Definition%20of%20%22__vector_7%22%20Error). NewPing.h library must be modified to disable the TIMMER_ENABLED value on line 153 by setting it to false

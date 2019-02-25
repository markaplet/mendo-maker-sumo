/*
  Finding IR Remote Codes

  Each time you press a button on the remote control, a unique hexadecimal code
  is generated. This is the information that is modulated and sent over IR to
  the receiver. In order to decipher which key is pressed, the receiving
  microcontroller needs to know which code corresponds to each key on the remote.

  Different remotes send different codes for the keypresses, so you’ll need to
  determine the code generated for each key on your particular remote. In this
  sketch we will read the keypresses and print the hexadecimal codes to the
  serial monitor when you press a key.

  IR Diodes come in different shapes and configurations. Each type may  have
  a specific pin schematic. They will generally have the following three pins.
  Signal, Ground, and 5v power. See the readme fiel for a link to the
  schematic for the IR Diode included in this kit.

  Requires the IRremote.h library be included
  Download it from here: http://z3t0.github.io/Arduino-IRremote/
*/
#include <IRremote.h>




/*
  Creating a constant variable and using it throughout your application allows
  you to update the variable once and the change is reflected everywhere it's
  used. In general defining variables that you may need to adjust on the fly
  is concidered best practice.

  In this sketch RECV_PIN is set to 10, but it could be any digital signal pin
  that is available on your board. We will read the signal pin and store the
  decoded code in the 'results' variable.
*/
const int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;




/*
  The setup function runs once when you press reset or power the board. The
  "void" keyword indicates that the function is not expected to return any
  information to the larger program.

   In this lesson we will setup the serial monitor so we can output the codes
   we decoded to the serial monitor.
*/
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}




/*
  The loop function runs over and over again forever.
  This is the main loop for your application.

  Open the serial monitor and press the keys you wish to use for controlling
  your bot. The code will be displayed on the serial monitor. Record the
  hexadecimal code printed for each key press. NOTE: Different brand
  remotes will send different codes. It may look like FF5AA5 or 20DFA25D.
  Note that you may receive a FFFFFFFF code when you press a key continuously.
  Some remotes send the same code ofer and over again, some remotes send a
  FFFFFFF to indicate that the key is continuously being pressed.

  NOTE: The value for the code is actually a hexadecimal value and when we want
  to use the value for say a comparison we will have to prepend '0x' to the number.
  For example. If the value we wrote down from the serial monitor is '20DFA25D'
  we will need to use '0x20DFA25D' in our program.

  This loop will constantly read the sent key and decode the hexadecimal value
  and print it to the serial monitor.
*/
void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}

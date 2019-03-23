/*
  Do something when IR Remote keys are pressed.

  Armed with our remote's unique hexadecimal codes we can use the information
  to control our bots. In this lesson we will create some flow logic in the form
  of a 'switch statement' and assign a function to each key press.

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
decode_results IRresults;
unsigned long key_value = 0;




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

  In this sketch we will create two switch blocks that will execute only when
  the defined key (code) on the remote is pressed. In our example we will print
  a message to the serial monitor indicating what case we are in. In your bots
  code, you would likely replace it with your bots driving functions.
*/
void loop() {

  if (irrecv.decode(&IRresults)){

    if (IRresults.value == 0XFFFFFFFF)
      IRresults.value = key_value;

    switch(IRresults.value){
      case 0x20DFA25D:    // Replace with your code for forward
        Serial.println("UP:FORWARD");
        // add code for driving forward here
      break;

      case 0x20DF629D:  // Replace with your code for forward
        Serial.println("DOWN:BACKWARD");
        // add code for driving backwards here
      break;
    }
    key_value = IRresults.value;
    irrecv.resume();
  }

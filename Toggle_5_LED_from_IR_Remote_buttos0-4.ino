// Control 5 LED's using Unused IR Remote keys



// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;// Connect the signal out pin of TSOP 1838 to Digital pin 4 of Arduino.

// Define LED pin constants
const int redPin = 7; // Connect the Red LED to Digital pin 7 of Arduino.
const int yellowPin = 8;// Connect the Yellow LED to Digital pin 8 of Arduino.
const int bluePin = 9; // Connect the Blue LED to Digital pin 9 of Arduino.
const int greenPin = 10;// Connect the Green LED to Digital pin 10 of Arduino.
const int whitePin = 11;// Connect the white LED to Digital pin 11 of Arduino.



// Define integer to remember toggle state
int togglestate = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(whitePin, OUTPUT);
}


void loop() {
  if (irrecv.decode(&results)) {

    switch (results.value) {
      case 0xFF6897: //code from remote button-0
        if(togglestate==0){
          digitalWrite(redPin,HIGH);
          togglestate =1;
        }
        else{
          digitalWrite(redPin,LOW);
          togglestate =0;
        }
        
        break;

      case 0xFF30CF: //code from remote button-1

        if (togglestate == 0) {
          digitalWrite(yellowPin, HIGH);
          togglestate = 1;
        }
        else {
          digitalWrite(yellowPin, LOW);
          togglestate = 0;
        }
        break;


      case 0xFF18E7: //code from remote Button-2

        if (togglestate == 0) {
          digitalWrite(bluePin, HIGH);
          togglestate = 1;
        }
        else {
          digitalWrite(bluePin, LOW);
          togglestate = 0;
        }
        break;


      case 0xFF7A85: //code from remote button-3
        if (togglestate == 0) {
          digitalWrite(greenPin, HIGH);
          togglestate = 1;
        }
        else {
          digitalWrite(greenPin, LOW);
          togglestate = 0;
        }
        break;

      case 0xFF10EF: //code from remote button-4
        if (togglestate == 0) {
          digitalWrite(whitePin, HIGH);
          togglestate = 1;
        }
        else {
          digitalWrite(whitePin, LOW);
          togglestate = 0;
        }
        break;
    }
    irrecv.resume();
  }

}

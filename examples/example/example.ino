#include <SigGen.h>

led1Pin = 10;  // LED connected to digital pin 10 (PWM)
led2Pin = 11;  // LED connected to digital pin 11 (PWM)

SigGen sine;    // Create real time sine wave object
SigGen square;  // Create real time square wave object

void setup() {
  pinMode(led1Pin, OUTPUT);  // sets the pin as output
  pinMode(led2Pin, OUTPUT);  // sets the pin as output
}

void loop() {
  analogWrite(led1Pin, wave.sine());    // Fade LED
  analogWrite(led2Pin, wave.square());  // Blink LED
}

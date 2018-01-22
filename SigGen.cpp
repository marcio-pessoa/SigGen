/* SigGen.cpp - Signal Generator
 * 
 */

#include "Arduino.h"
#include "SigGen.h"

/* SigGen
 * 
 * Description
 *   Blink LED without delay function.
 * 
 *   RealTime (int pin, int millis_period, boolean state)
 * 
 * Parameters
 *   pin: Arduino LED pin
 *   millis_period: Time period to define blink delay (milliseconds)
 *   state: Initial LED state
 * 
 * Returns
 *   void
 */
SigGen::SigGen() {
  _millis_period = 1000;
  _millis_elapsed = 0;
}

/* sine
 * 
 * Description
 *   Sine wave.
 * 
 *   object.sine()
 * 
 * Parameters
 *   void
 * 
 * Returns
 *   float: sine signal
 */
void SigGen::period(unsigned int period) {
  _millis_period = period;
}

/* sine
 * 
 * Description
 *   Sine wave.
 * 
 *   object.sine()
 * 
 * Parameters
 *   void
 * 
 * Returns
 *   float: sine signal
 */
float SigGen::sine() {
  float x = ((-cos((step() * PI) * 2)) + 1) / 2;
  return x;
}

/* square
 * 
 * Description
 *   Square wave.
 * 
 *   object.square()
 * 
 * Parameters
 *   void
 * 
 * Returns
 *   float: square signal
 */
float SigGen::square() {
  bool x;
  if (step() < .5) {
    x = 0;
  }
  else {
    x = 1;
  }
  return x;
}

/* step
 * 
 * Description
 *   A time baseline to provide x axis to signal generation.
 * 
 *   step()
 * 
 * Parameters
 *   void
 * 
 * Returns
 *   float: time baseline from 0 to 1.
 */
float SigGen::step() {
  long millis_current = millis();
  // Build a linear x variable (0 ~ 1)
  float x = (float)(millis_current - _millis_elapsed) / _millis_period;
  // Reset counter
  if (millis_current - _millis_elapsed >= _millis_period) {
    _millis_elapsed = millis_current;
  }
  return x;
}

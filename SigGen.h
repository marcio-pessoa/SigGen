/* SigGen.h - Signal Waveform Generator
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 * 
 * Waveform example with duration 1000 milliseconds:
 * 
 *   1 ┐    ┌────┐
 *     │    │    │
 *     └────┘    └
 *     0   500   1000
 * 
 * Change log
 * 2015-07-03
 *         * square
 *         Added method square to generate square waveform.
 *         * step
 *         Added this private method to provide common base time to signals.
 * 
 * 2015-07-03
 *         * sine
 *         Added method sine to generate sine waveform.
 * 
 * 2015-06-13
 *         Experimental version.
 */

#ifndef SigGen_h
#define SigGen_h

#include "Arduino.h"

// If PI constant is not defined, plese uncoment the follow line:
// const float PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;

class SigGen
{
  public:
    SigGen();
    float sine();
    float square();
    void period(unsigned int period);
  private:
    float step();
    unsigned int _millis_period;
    unsigned long _millis_elapsed;
};

#endif

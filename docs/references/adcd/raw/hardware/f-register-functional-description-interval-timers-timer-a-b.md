# F / Register Functional Description / Interval Timers (Timer A, B)


Each interval timer consists of a 16-bit read-only timer counter and a
16-bit write-only timer latch.  Data written to the timer is latched into
the timer latch, while data read from the timer is the present contents of
the timer counter.

The latch is also called a prescalar in that it represents the countdown
value which must be counted before the timer reaches an underflow (no more
counts) condition.  This latch (prescalar) value is a divider of the input
clocking frequency. The timers can be used independently or linked for
extended operations.  Various timer operating modes allow generation of
long time delays, variable width pulses, pulse trains, and variable
frequency waveforms.  Utilizing the CNT input, the timers can count
external pulses or measure frequency, pulse width, and delay times of
external signals.

Each timer has an associated  [control register](../Hardware_Manual_guide/node0145.html) , providing independent
control over each of the following functions:

 [Start/Stop](../Hardware_Manual_guide/node0134.html)        [One-shot/continuous](../Hardware_Manual_guide/node0137.html) 
 [PB on/off](../Hardware_Manual_guide/node0135.html)         [Force load](../Hardware_Manual_guide/node0138.html) 
 [Toggle/pulse](../Hardware_Manual_guide/node0136.html) 


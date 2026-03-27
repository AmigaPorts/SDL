# 8 / / Reading Controllers / Interpreting Controller Position


Interpreting the position of the proportional controller normally requires
some preliminary work during the  [vertical blanking](../Hardware_Manual_guide/node0169.html)  interval.

During  [vertical blanking](../Hardware_Manual_guide/node0169.html) , you write a value into an address called
 [POTGO](../Hardware_Manual_guide/node018B.html) . For a standard X-Y joystick, this value is hex 0001. Writing to
this register starts the operation of some special hardware that reads the
potentiometer values and sets the values contained in the  [POT registers](../Hardware_Manual_guide/node0187.html) 
(described below) to zero.

The read circuitry stays in a reset state for the first seven or eight
horizontal video scan lines. Following the reset interval, the circuit
allows a charge to begin building up on a timing capacitor whose charge
rate will be controlled by the position of the external controller
resistance. For each horizontal scan line thereafter, the circuit compares
the charge on the timing capacitor to a preset value. If the charge is
below the preset, the  [POT counter](../Hardware_Manual_guide/node0187.html)  is incremented. If the charge is above
the preset, the counter value will be held until the next  [POTGO](../Hardware_Manual_guide/node018B.html)  is
issued.


```c
     [Figure 8-5: Effects of Resistance on Charging Rate](../Hardware_Manual_guide/node02E6.html) 
```
You normally issue  [POTGO](../Hardware_Manual_guide/node018B.html)  at the beginning of a video screen, then read
the values in the  [POT registers](../Hardware_Manual_guide/node0187.html)  during the next  [vertical blanking](../Hardware_Manual_guide/node0169.html) 
period, just before issuing  [POTGO](../Hardware_Manual_guide/node018B.html)  again.

Nothing in the system prevents the counters from overflowing (wrapping
past a count of 255). However, the system is designed to insure that the
counter cannot overflow within the span of a single screen. This allows
you to know for certain whether an overflow is indicated by the controller.


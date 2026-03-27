# F / Control Registers / Control Register B



   CONTROL REGISTER B:

  BIT  NAME     FUNCTION
  ---  ----     --------
   0   [START](../Hardware_Manual_guide/node0134.html)    1 = start Timer B, 0 = stop Timer B.
```c
                    This bit is automatically reset (= 0) when
                    underflow occurs during one-shot mode.
```
   1   [PBON](../Hardware_Manual_guide/node0135.html)     1 = Timer B output on PB7, 0 = PB7 is normal
                    operation.
   2   [OUTMODE](../Hardware_Manual_guide/node0136.html)  1 = toggle, 0 = pulse.
   3   [RUNMODE](../Hardware_Manual_guide/node0137.html)  1 = one-shot mode, 0 = continuous mode.
   4   [LOAD](../Hardware_Manual_guide/node0138.html)     1 = force load (this is a strobe input, there is no
```c
                    data storage;  bit 4 will always read back a
                    zero and writing a 0 has no effect.)
```
  6,5  [INMODE](../Hardware_Manual_guide/node0139.html)   Bits CRB6 and CRB5 select one of four possible

                input modes for Timer B, as follows:

                CRB6  CRB5   Mode Selected
                ----  ----   ---------------------------------------
                 0     0     Timer B counts 02 pulses
                 0     1     Timer B counts positive CNT transitions
                 1     0     Timer B counts Timer A underflow pulses
                 1     1     Timer B counts Timer A underflow pulses
                               while CNT pin is held high.
   7   [ALARM](../Hardware_Manual_guide/node013C.html#line4)     1 = writing to TOD registers sets Alarm

```c
                 0 = writing to TOD registers sets TOD clock.
                     Reading TOD registers always reads TOD clock,
                     regardless of the state of the Alarm bit.
```

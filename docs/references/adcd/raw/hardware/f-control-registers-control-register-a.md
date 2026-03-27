# F / Control Registers / Control Register A



  BIT  NAME     FUNCTION
  ---  ----     --------
   0   [START](../Hardware_Manual_guide/node0134.html)    1 = start Timer A, 0 = stop Timer A.
```c
                    This bit is automatically reset (= 0) when
                    underflow occurs during one-shot mode.
```
   1   [PBON](../Hardware_Manual_guide/node0135.html)     1 = Timer A output on PB6, 0 = PB6 is normal operation.
   2   [OUTMODE](../Hardware_Manual_guide/node0136.html)  1 = toggle, 0 = pulse.
   3   [RUNMODE](../Hardware_Manual_guide/node0137.html)  1 = one-shot mode, 0 = continuous mode.
   4   [LOAD](../Hardware_Manual_guide/node0138.html)     1 = force load (this is a strobe input, there is no
```c
                    data storage;  bit 4 will always read back a zero
                    and writing a 0 has no effect.)
```
   5   [INMODE](../Hardware_Manual_guide/node0139.html)   1 = Timer A counts positive CNT transitions,
```c
                0 = Timer A counts 02 pulses.
```
   6   [SPMODE](../Hardware_Manual_guide/node013E.html)   1 = Serial port=output (CNT is the source of the shift
```c
                    clock)
                0 = Serial port=input  (external shift clock is
                    required)
```
   7   UNUSED


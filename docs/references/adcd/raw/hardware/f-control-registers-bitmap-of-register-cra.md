# F / Control Registers / Bitmap of Register CRA



REG# NAME UNUSED  SPMODE  INMODE  LOAD   RUNMODE  OUTMODE   PBON    START
---- ---- ------  ------  ------  ----   -------  -------   ----    -----
 E   CRA  unused  0=input  0=02  1=force  0=cont. 0=pulse  0=PB6OFF 0=stop

```c
          unused  1=output 1=CNT   load   1=one-  1=toggle 1=PB6ON  1=start
                                 (strobe)   shot

                           |<--------  [Timer](../Hardware_Manual_guide/node0133.html)  A Variables --------------->|
```
All unused register bits are unaffected by a write and forced to 0 on a
read.


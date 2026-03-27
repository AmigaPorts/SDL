# F / Control Registers / Bitmap Of Register CRB



REG# NAME ALARM    INMODE     LOAD      RUNMODE  OUTMODE  PBON    START
---- ---- -----    ------     ----      -------  -------  ----    -----
 F   CRB  0=TOD    00=02      1=force   0=cont.  0=pulse  0=PB7OFF 0=stop

```c
          1=Alarm  01=CNT       load    1=one-   1=toggle 1=PB7ON  1=start
                   10=Timer A  (strobe)   shot
                   11=CNT+
                     Timer A

                   |<---------------  [Timer B](../Hardware_Manual_guide/node0133.html)  Variables ------------>|
```
All unused register bits are unaffected by a write and forced to 0 on a
read.


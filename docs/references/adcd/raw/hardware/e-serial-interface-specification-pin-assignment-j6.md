# E / / Serial Interface Specification / Pin Assignment (J6)




              RS-232-C
   NAME   DIR  STD  NOTES
   ----   ---  ---  --------------------------
   FGND         y   Frame ground -- do not tie to signal ground
   TXD     O    y   Transmit data
   RXD     I    y   Receive data
   RTS     O    y   Request to send
   CTS     I    y   Clear to send
   DSR     I    y   Data set ready
   GND          y   Signal ground -- do not tie to frame ground
   CD      I    y   Carrier detect
   -5V          n*  50 ma maximum   *** WARNING -5V ***
   AUDO    O    n*  Audio output from left (channels 0, 3) port,
                    intended to send audio to the modem.
   AUDI    I    n*  Audio input to right (channels 1, 2) port,
```c
                    intended to receive audio from the modem; this
                    input is mixed with the analog output of the
                    right (channels 1, 2). It is not digitized or
                    used by the computer in any way.
```
   DTR     O    y   Data terminal ready.
   RI      I    y   Ring Indicator (A500/A2000 only) shared with printer
                    "select" signal.
   RESB*   O    n*  Amiga system reset.


NOTES:

```c
     n*:  See  [warning](../Hardware_Manual_guide/node0105.html#line4)  above
     See part 1 of this appendix for  [pin numbers](../Hardware_Manual_guide/node00F5.html) .
```

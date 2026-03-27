---
title: E / Amiga I/O Connector Pins / RS232 and MIDI Port
manual: hardware
chapter: hardware
section: e-amiga-i-o-connector-pins-rs232-and-midi-port
functions: []
libraries: []
---

# E / Amiga I/O Connector Pins / RS232 and MIDI Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

RS232 and MIDI Port
-------------------

                   A500/
                   A2000/ CBM
PIN  RS232  A1000  A3000  PCs   HAYES  DESCRIPTION
---------------------------------------------------
1    GND    GND    GND    GND   GND    [FRAME GROUND](hardware/e-serial-interface-specification-pin-assignment-j6.md) 
2    TXD    RXD    RXD    RXD   RXD    TRANSMIT DATA
3    RXD    RXD    RXD    RXD   RXD    RECEIVE DATA
4    RTS    RTS    RTS    RTS   -      REQUEST TO SEND
5    CTS    CTS    CTS    CTS   CTS    CLEAR TO SEND
6    DSR    DSR    DSR    DSR   DSR    DATA SET READY
7    GND    GND    GND    GND   GND    [SYSTEM GROUND](hardware/e-serial-interface-specification-pin-assignment-j6.md) 
8    CD     CD     CD     DCD   DCD    CARRIER DETECT
9    -      -      +12v   +12v  -      + 12 VOLT POWER
10   -      -      -12v   -12v  -      - 12 VOLT POWER
11   -      -      AUDO   -     -      [AUDIO OUTPUT](hardware/e-serial-interface-specification-pin-assignment-j6.md)  (A500, A2000, A3000)
12   S.SD   -      -      -     SI     SPEED INDICATE
13   S.CTS  -      -      -     -
14   S.TXD  -5Vdc  -      -     -      [- 5 VOLT POWER](hardware/e-serial-interface-specification-pin-assignment-j6.md) 
15   TXC    AUDO   -      -     -      [AUDIO OUTPUT](hardware/e-serial-interface-specification-pin-assignment-j6.md)  (A1000)
16   S.RXD  AUDI   -      -     -      [AUDIO INPUT](hardware/e-serial-interface-specification-pin-assignment-j6.md)  (A1000)
17   RXC    EB     -      -     -      BUFFERED PORT CLOCK 716kHz
18   -      INT2*  AUDI   -     -      INTERRUPT LINE A1000/AUDIO INPUT
```c
                                           (A500, 2000, 3000)
```
19   S.RTS  -      -      -     -
20   DTR    DTR    DTR    DTR DTR      DATA TERMINAL READY
21   SQD    +5            -     -      + 5 VOLT POWER
22   RI     -      RI     RI    RI     [RING INDICATOR](hardware/e-serial-interface-specification-pin-assignment-j6.md) 
23   SS     +12Vdc -      -     -      +12 VOLT POWER
24   TXC1   C2*    -      -     -      3.58 MHZ CLOCK
25   -      RESB*  -      -     -      BUFFERED SYSTEM RESET


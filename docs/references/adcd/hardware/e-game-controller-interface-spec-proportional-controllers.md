---
title: E / / Game Controller Interface Spec / Proportional Controllers
manual: hardware
chapter: hardware
section: e-game-controller-interface-spec-proportional-controllers
functions: []
libraries: []
---

# E / / Game Controller Interface Spec / Proportional Controllers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Resistive (potentiometer) element linear taper proportional controllers
are supported up to 528k Ohms max (470k +/- 10% recommended).  The
 [JOY[0/1]DAT](../Hardware_Manual_guide/node0038.html)  registers contain digital translation values for y in the
high byte and x in the low byte. A higher count value indicates a higher
external resistance. The Amiga performs an integrating analog-to-digital
conversion as follows:


```c
    1.  For the first 7 (NTSC) or 8 (PAL) horizontal display lines,
    the analog input capacitors are discharged and the positions
    counters reflected in the  [POT[O/1]DAT](../Hardware_Manual_guide/node003A.html)  registers are held reset.

    For the remainder of the display field, the input capacitors are
    allowed to recharge through the resistive element in the external
    control device.

    2.  The gradually increasing voltage is continuously compared to
    an internal reference level while counter keeps track of the
    number of lines since the end of the reset interval.

    3.  When the input voltage finally exceeds the  internal threshold
    for a given input channel, the current counter value is latched
    into the  [POT[O/1]DAT](../Hardware_Manual_guide/node003A.html)  register corresponding to that channel.

    4.  During the vertical blanking interval, the  software examines
    the resulting  [POT[O/1]DAT](../Hardware_Manual_guide/node003A.html)  register values and interprets the
    counts in terms of joystick position.
```
   NOTE:
   -----
   The POTY and POTX inputs are designated as "right mouse button" and
   "unused mouse button" respectively.  An opened switch corresponds to
   high resistance, a closed switch to a low resistance.  The buttons
   are also available in  [POTGO and POTGOR](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)  registers.  It is recommended
   that ROM kernel calls be used for future hardware compatibility.

It is important to realize that the proportional controller is more of a
"pointing" device than an absolute position input.  It is up to the
software to provide the calibration, range limiting and averaging
functions needed to support the application's control requirements.

The  [POT[0/1]DAT](../Hardware_Manual_guide/node003A.html)  registers are typically read during video blanking, but
MAY be available prior to that.


CONNECTOR PIN USAGE FOR PROPORTIONAL INPUTS
-------------------------------------------

   PIN  MNEMONIC  DESCRIPTION              HARDWARE REGISTER/NOTES
   ---  --------  -----------              -----------------------
   1    XBUT      Extra Button
   2    Unused
   3     LBUT*    Left button              See  [Digital Joystick](hardware/e-game-controller-interface-specification-digital-joysticks.md) 
   4     RBUT*    Right button             See  [Digital Joystick](hardware/e-game-controller-interface-spec-proportional-controllers.md) 
   5     POTX     X analog in              POT[0/1]DAT<7:0>, POTGO, POTGOR
   6    Unused
   7     +5V      125ma max, 200 ma surge
   8    Ground
   9     POTY     Y analog in              POT[0,1]DAT<15:8>, POTGO, POTGOR


               ___________
      PORT 0  /         5 \        POT0X
             |  o o o o o -|- - - - - - - -
              \        9  /  POT0Y         |
               \ o o o o-/- - - -
                \_______/        |         |
                             ____v____ ____v____
                            |         |         |
                            |  POT0Y  |  POT0X  | POT0DAT
                            | COUNTER | COUNTER | DFF012
                            |_________|_________|

               ___________
      PORT 1  /         5 \        POT1X
             |  o o o o o -|- - - - - - - -
              \        9  /  POT1Y         |
               \ o o o o-/- - - -
                \_______/        |         |
                             ____v____ ____v____
                            |         |         |
                            |  POT1Y  |  POT1X  | POT0DAT
                            | COUNTER | COUNTER | DFF014
                            |_________|_________|


                             _________________
                            |               | | POTGO
                            |_______________|_| DFF034

                             _________________
                            |                 | POTINP
                            |_________________| DFF016


                 Figure E-2: Pot Counters

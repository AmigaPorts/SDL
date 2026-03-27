---
title: E / / Game Controller Interface Specification / Light Pen
manual: hardware
chapter: hardware
section: e-game-controller-interface-specification-light-pen
functions: []
libraries: []
---

# E / / Game Controller Interface Specification / Light Pen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A light pen is an optoelectronic device whose light-sensitive portion is
placed in proximity to a CRT.  As the electron beam sweeps past the light
pen, a trigger pulse is generated which can be enabled to latch the
horizontal and vertical beam positions.  There is no hardware bit to
indicate this trigger, but this can be determined in the  [two ways](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)  as
shown in chapter 8, "Interface Hardware."

Light pen position is usually read during blanking, but MAY be available
prior to that.


CONNECTOR PIN USAGE FOR LIGHT PEN INPUTS
----------------------------------------

   PIN   MNEMONIC   DESCRIPTION              HARDWARE REGISTER/NOTES
   ---   --------   -----------              -----------------------
   1     Unused
   2     Unused
   3     Unused
   4     Unused
   5     LPENPR*    Light pen pressed        See  [Proportional Inputs](hardware/e-game-controller-interface-spec-proportional-controllers.md) 
   6     LPENTG*    Light pen trigger        VPOSR, VHPOSR
   7      +5V       125ma max, 200 ma surge  Both ports
   8     Ground
   9     Unused

   * Note: depending on the maker, the light pen input may be either.


```c
             _____________________________
            |                             | VPOSR read only
            |                             | DFF004
            |_____________________________|

             _____________________________
            |                             | VHPOSR read only
            |                             | DFF006
            |_____________________________|

             _____________________________
            |                             | BPLCON0 write only
            |                      |      | DFF104
            |_|_|_|_|_|_|_|_|_|_|_|||_|_|_|

            15                     3     0
                                   ^
                                   |_ _ _ _ light pen enable

             _____________________________
            |                             | POTINP read only
            |                             | DFF104
            |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
                         ^
            15           |               0

                         | PEN PRESS = POT0X

                         |_ _ _ _ _ _ _ _
                                         |
                         ___________
                PORT 1  /         5 \    |
                       |  o o o o o -|- -
                        \  6        /
                         \ o o o o /
                          \|______/
               light
                pen _ _ _ _|

             _ _ _ _ _
                      |

                      |
                     _v_ _ _ latches V & H positions


                 Figure E-3: Light Pen
```

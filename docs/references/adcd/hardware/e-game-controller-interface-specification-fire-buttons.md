---
title: E / / Game Controller Interface Specification / Fire Buttons
manual: hardware
chapter: hardware
section: e-game-controller-interface-specification-fire-buttons
functions: []
libraries: []
---

# E / / Game Controller Interface Specification / Fire Buttons

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The fire buttons are normally opened switches routed to the 8520 adapter
PRA0 as follows:


```c
        PRA0 bit 7 = Fire* left controller port
        PRA0 bit 6 = Fire* right controller port
```
Before reading this register, the corresponding bits of the data direction
register must be cleared to define input mode:


        DDRA0<7:6> cleared as appropriate
   NOTE:
   -----
   Do not disturb the settings of other bits in DDRA0 (Use of ROM kernel
   calls is recommended).

Fire buttons are always valid and may be read at any time.


CONNECTOR PIN USAGE FOR FIRE BUTTON INPUTS
------------------------------------------

   PIN   MNEMONIC   DESCRIPTION
   ---   --------   -----------
   1      -x-
   2      -x-
   3      -x-
   4      -x-
   5      -x-
   6      FIRE*     Left mouse button/fire button
   7      -x-
   8      ground
   9      -x-

            ___________                   ___________
   PORT 0  /           \         PORT 1  /           \
          |  o o o o o  |               |  o o o o o  |
           \  6        /                 \  6        /
            \ o o o o /                   \ o o o o /
             \|______/                     \|______/
   FIRE 0\
   _ _ _ _ _ _|                             |
  |                              FIRE 1\
         _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
  | 7   |                                                   0
     ___v___________________________________________________
  | |       |       |                                       | PRA
    |FIRE 1\|FIRE 0\|                                       | $BFE001
  | |_______|___ ___|_______|_______|_______|_______|_______|
                ^
  |_ _ _ _ _ _ _|


     _______________________________________________________
    |       |       |                                       | Data
    |   0   |   0   |   0       0       0       0       0   | direction
    |_______|_______|_______|_______|_______|_______|_______| DDRA
                                                              $BFE201
        IN      IN     OUT     OUT     OUT     OUT     OUT


                 Figure E-1: Reading Fire Buttons

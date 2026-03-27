---
title: G Keyboard Interface / Matrix Table
manual: hardware
chapter: hardware
section: g-keyboard-interface-matrix-table
functions: []
libraries: []
---

# G Keyboard Interface / Matrix Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

              Row 5   Row 4   Row 3   Row 2   Row 1   Row 0
   Column    (Bit 7) (Bit 6) (Bit 5) (Bit 4) (Bit 3) (Bit 2)
```c
           +-------+-------+-------+-------+-------+-------+
     15    |(spare)|(spare)|(spare)|(spare)|(spare)|(spare)|
```
   (PD.7)  |       |       |       |       |       |       |
```c
           | (0E)  | (1C)  | (2C)  | (47)  | (48)  | (49)  |
           +-------+-------+-------+-------+-------+-------+
     14    |   *   |<SHIFT>| CAPS  |  TAB  |   ~   |  ESC  |
```
   (PD.6)  |note 1 |note 2 | LOCK  |       |   `   |       |
```c
           | (5D)  | (30)  | (62)  | (42)  | (00)  | (45)  |
           +-------+-------+-------+-------+-------+-------+
     13    |   +   |   Z   |   A   |   Q   |   !   |   (   |
```
   (PD.5)  |note 1 |       |       |       |   1   |note 1 |
```c
           | (5E)  | (31)  | (20)  | (10)  | (01)  | (5A)  |
           +-------+-------+-------+-------+-------+-------+
     12    |  9    |   X   |   S   |   W   |   @   |  F1   |
```
   (PD.4)  |note 3 |       |       |       |   2   |       |
```c
           | (3F)  | (32)  | (21)  | (11)  | (02)  | (50)  |
           +-------+-------+-------+-------+-------+-------+
     11    |  6    |   C   |   D   |   E   |   #   |  F2   |
```
   (PD.3)  |note 3 |       |       |       |   3   |       |
```c
           | (2F)  | (33)  | (22)  | (12)  | (03)  | (51)  |
           +-------+-------+-------+-------+-------+-------+
     10    |  3    |   V   |   F   |   R   |   $   |  F3   |
```
   (PD.2)  |note 3 |       |       |       |   4   |       |
```c
           | (1F)  | (34)  | (23)  | (13)  | (04)  | (52)  |
           +-------+-------+-------+-------+-------+-------+
      9    |  .    |   B   |   G   |   T   |   %   |  F4   |
```
   (PD.1)  |note 3 |       |       |       |   5   |       |
```c
           | (3C)  | (35)  | (24)  | (14)  | (05)  | (53)  |
           +-------+-------+-------+-------+-------+-------+
      8    |  8    |   N   |   H   |   Y   |   ^   |  F5   |
```
   (PD.0)  |note 3 |       |       |       |   6   |       |
```c
           | (3E)  | (36)  | (25)  | (15)  | (06)  | (54)  |
           +-------+-------+-------+-------+-------+-------+
      7    |  5    |   M   |   J   |   U   |   &   |   )   |
```
   (PC.7)  |note 3 |       |       |       |   7   |note 1 |
```c
           | (2E)  | (37)  | (26)  | (16)  | (07)  | (5B)  |
           +-------+-------+-------+-------+-------+-------+
      6    |  2    |   <   |   K   |   I   |   *   |  F6   |
```
   (PC.6)  |note 3 |   ,   |       |       |   8   |       |
```c
           | (1E)  | (38)  | (27)  | (17)  | (08)  | (55)  |
           +-------+-------+-------+-------+-------+-------+
      5    | ENTER |   >   |   L   |   O   |   (   |   /   |
```
   (PC.5)  |note 3 |   .   |       |       |   9   |note 1 |
```c
           | (43)  | (39)  | (28)  | (18)  | (09)  | (5C)  |
           +-------+-------+-------+-------+-------+-------+
      4    |  7    |   ?   |   :   |   P   |   )   |  F7   |
```
   (PC.4)  |note 3 |   /   |   ;   |       |   0   |       |
```c
           | (3D)  | (3A)  | (29)  | (19)  | (0A)  | (56)  |
           +-------+-------+-------+-------+-------+-------+
      3    |  4    |(spare)|   "   |   {   |   _   |  F8   |
```
   (PC.3)  |note 3 |       |   '   |   [   |   -   |       |
```c
           | (2D)  | (3B)  | (2A)  | (1A)  | (0B)  | (57)  |
           +-------+-------+-------+-------+-------+-------+
      2    |  1    | SPACE | <RET> |   }   |   +   |  F9   |
```
   (PC.2)  |note 3 |  BAR  |note 2 |   ]   |   =   |       |
```c
           | (1D)  | (40)  | (2B)  | (1B)  | (0C)  | (58)  |
           +-------+-------+-------+-------+-------+-------+
      1    |  0    | BACK  |  DEL  |RETURN |   |   |  F10  |
```
   (PC.1)  |note 3 | SPACE |       |       |   \   |       |
```c
           | (0F)  | (41)  | (46)  | (44)  | (0D)  | (59)  |
           +-------+-------+-------+-------+-------+-------+
      0    |  -    | CURS  | CURS  | CURS  | CURS  | HELP  |
```
   (PC.0)  |note 3 | DOWN  | RIGHT | LEFT  |  UP   |       |

```c
           | (4A)  | (4D)  | (4E)  | (4F)  | (4C)  | (5F)  |
           +-------+-------+-------+-------+-------+-------+
```
   note 1: A500, A2000 and A3000 keyboards only (numeric pad )
   note 2: International keyboards only (these keys are cutouts of the
```c
           larger key on the US ASCII version.)  The key that generates
           $30 is cut out of the left Shift key.  Key $2B is cut out of
           return.  These keys are labeled with country-specific markings.
```
   note 3: Numeric pad.


The following table shows which keys are independently readable.  These
keys never generate ghosts or phantoms.



```c
        (Bit 6) (Bit 5) (Bit 4) (Bit 3) (Bit 2) (Bit 1) (Bit 0)
       +-------+-------+-------+-------+-------+-------+-------+
       | LEFT  | LEFT  | LEFT  | CTRL  | RIGHT | RIGHT | RIGHT |
       | AMIGA | ALT   | SHIFT |       | AMIGA |  ALT  | SHIFT |
       | (66)  | (64)  | (60)  | (63)  | (67)  | (65)  | (61)  |
       +-------+-------+-------+-------+-------+-------+-------+
```

---
title: Building the +2 Interface
manual: amiga-mail
chapter: amiga-mail
section: building-the-2-interface
functions: []
libraries: []
---

# Building the +2 Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The interface that these two extra joystick ports require is quite
straightforward in design and does not require any power.  Essentially,
two male 9-pin "d-sub" connectors (the type commonly used for
joystick ports) are wired directly to a 25-pin "d-sub" connector.

The gender of the 25-pin connector depends on the Amiga model.  Amiga
1000 computers have a non-standard, male 25-pin parallel port, so the
Amiga 1000 adapters will need a female connector.  All other Amigas
have standard female 25-pin parallel ports, so adapters for A500, A600,
A2000, A3000, A3000T, and CDTV units should have a male 25-pin
connector.

The only difference between the requirements for the A1000 "+2"
adapter and the "+2" adapter for the rest of the Amiga/CDTV product
line is the gender.  The "+2" adapter only uses parallel port pins
that all Amigas/CDTVs have in common.  These particular pins were
chosen so that one "+2" adapter and a gender changer could connect
two joysticks to any existing Amiga.  Because some of the unused pins
carry voltages, only wire the pins specified in the chart!  Doing
otherwise can destroy components inside the Amiga!


  Parallel function   Parallel port   JOY3    JOY4    Joystick function
```c
                      (25 pin male)   (9pm)   (9pm)
```
  ---------------------------------------------------------------------
  Data bit 0                2           1               JOY3 UP
  Data bit 1                3           2               JOY3 DOWN
  Data bit 2                4           3               JOY3 LEFT
  Data bit 3                5           4               JOY3 RIGHT

  Data bit 4                6                   1       JOY4 UP
  Data bit 5                7                   2       JOY4 DOWN
  Data bit 6                8                   3       JOY4 LEFT
  Data bit 7                9                   4       JOY4 RIGHT

  Busy                      11                  6       JOY4 FIRE
  Select (Online)           13          6               JOY3 FIRE

  ground                    18                  8       JOY4 GROUND
  ground                    19          8               JOY3 GROUND



                        The "+2" Interface

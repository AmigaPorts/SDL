---
title: Housing the Interface
manual: amiga-mail
chapter: amiga-mail
section: housing-the-interface
functions: []
libraries: []
---

# Housing the Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For development purposes, you can construct a "+2" adapter from two
25-pin male d-sub connectors.  One connector attaches to the parallel
port, while the other accepts the two 9-pin female joystick plugs.
Simply build the "number 3" joystick connector into the leftmost 9
pins, and the "number 4" connector into the rightmost 9 pins.  The
pin-outs for this setup are in the "Non-Production +2 Interface"
chart below.


  Parallel function   Parallel port   JOY3    JOY4    Joystick function
```c
                      (25 pin male)   (9pm)   (9pm)
```
  ---------------------------------------------------------------------
  Data bit 0                2           1               JOY3 UP
  Data bit 1                3           2               JOY3 DOWN
  Data bit 2                4           3               JOY3 LEFT
  Data bit 3                5           4               JOY3 RIGHT

  Data bit 4                6                   9       JOY4 UP
  Data bit 5                7                   10      JOY4 DOWN
  Data bit 6                8                   11      JOY4 LEFT
  Data bit 7                9                   12      JOY4 RIGHT

  Busy                      11                  22      JOY4 FIRE
  Select (Online)           13          14              JOY3 FIRE

  ground                    18                  24      JOY4 GROUND
  ground                    19          16              JOY3 GROUND




                  The Non-Productive "+2" Interface
This arrangement is attractive to developers primarily because it has
few parts and it's easy to construct.  It is appropriate only for
developer use and testing.  Do not consider it for any sort of user
distribution, because the connectors for certain brands of joysticks
are too big to fit side by side into a 25-pin connector.  Users will
become quite irate upon finding that they can't use their "wiz-stik
5000" with their 4 player game adapter.

With this in mind, adapters intended for use by end users should be
built into some sort of casework.  The box should include two suitably
spaced joystick connectors, and a cable that allows the user to easily
attach the adapter to the parallel port.  Be sure that the cable is
long enough to allow users to place the adapter where they can get to
it easily.

Alternatively, the device could simply be a pair of long cables in a
"Y" shape, with a parallel connector at the base of the "Y", and
joystick connector on the other ends.  Such an adapter would probably
be the cheapest way to go.

Developers must caution end users to turn their computer's power off
before plugging in a "+2" adapter.  This will prevent users from
accidentally destroying the 8520 chips which control the parallel port.
To further prevent 8520 damage, developers should choose 25-pin
connectors without a metal case or shield.  While plugging the device
in, it's rather easy to accidentally brush (and short) the metal
shields of certain connectors against the pins of the parallel port.

No matter what the decision regarding implementation, remember that
game players can be quite rough.  All cables should be suitably long,
and all connectors should utilize a proper strain relief system.


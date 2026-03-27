---
title: A Register Summary / JOYTEST
manual: hardware
chapter: hardware
section: a-register-summary-joytest
functions: []
libraries: []
---

# A Register Summary / JOYTEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
JOYTEST    036      W       D     Write to all four joystick-mouse counters

                                  at once.

                 Mouse counter write test data:

                 BIT#  15,14,13,12,11,10,09,08  07,06,05,04,03,02,01,00
                       -----------------------  -----------------------
                 0DAT  Y7 Y6 Y5 Y4 Y3 Y2 xx xx  X7 X6 X5 X4 X3 X2 xx xx
                 1DAT  Y7 Y6 Y5 Y4 Y3 Y2 xx xx  X7 X6 X5 X4 X3 X2 xx xx

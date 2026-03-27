---
title: 8 / / Reading Proportional Controllers / Potentiometer Specifications
manual: hardware
chapter: hardware
section: 8-reading-proportional-controllers-potentiometer
functions: []
libraries: []
---

# 8 / / Reading Proportional Controllers / Potentiometer Specifications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The resistance of the potentiometers should be a linear taper. Based on
the design of the integrating analog-to-digital converter used, the
maximum resistance should be no more than 528K (470K +/- 10 percent is
suggested) for either the X or Y pots. This is based on a charge capacitor
of 0.047uf, +/- 10 percent, and a maximum time of 16.6 milliseconds for
charge to full value, ie. one video frame time.

All potentiometers exhibit a certain amount of "jitter". For acceptable
results on a wide base of configurations, several input readings will need
to be averaged.


```c
     [Figure 8-6: Potentiometer Charging Circuit](hardware/hard-pics-8-6-pic.md) 
```

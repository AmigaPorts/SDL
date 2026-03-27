---
title: E / Explanation of I/O Connectors / Game Controller Interface Spec
manual: hardware
chapter: hardware
section: e-explanation-of-i-o-connectors-game-controller-interface
functions: []
libraries: []
---

# E / Explanation of I/O Connectors / Game Controller Interface Spec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The two 9-pin D-type connectors with pins (male) are used to
interface to four types of devices:


```c
    1.  Mouse or trackball, 3 buttons max.
    2.  Digital joystick, 2 buttons max.
    3.  Proportional (pot or proportional joystick), 2 buttons max.
    4.  Light pen, including pen-pressed-to-screen button.
```
The connector pin assignments are discussed in sections organized
by similar hardware and/or software operating requirements as shown
in the previous list.  Signal names follow those used elsewhere
in this appendix, when possible.


```c
    J11 is the right controller port connector ( [JOY1DAT](hardware/a-register-summary-joy0dat-joy1dat.md) , [POT1DAT](hardware/a-register-summary-pot0dat-pot1dat.md) ).
    J12 is the left controller port connector ( [JOY0DAT](hardware/a-register-summary-joy0dat-joy1dat.md) , [POT0DAT](hardware/a-register-summary-pot0dat-pot1dat.md) ).
```
   NOTE:
   -----
   While most of the hardware discussed below is directly accessible,
   hardware should be accessed through ROM kernel software. This will
   keep future hardware changes transparent to the user.

 [Mouse/Trackball](hardware/e-game-controller-interface-specification-mouse-trackball.md)        [Proportional Controllers](hardware/e-game-controller-interface-spec-proportional-controllers.md) 
 [Digital Joysticks](hardware/e-game-controller-interface-specification-digital-joysticks.md)      [Light Pen](hardware/e-game-controller-interface-specification-light-pen.md) 
 [Fire Buttons](hardware/e-game-controller-interface-specification-fire-buttons.md) 


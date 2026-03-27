---
title: 8 Interface Hardware / Controller Port Interface
manual: hardware
chapter: hardware
section: 8-interface-hardware-controller-port-interface
functions: []
libraries: []
---

# 8 Interface Hardware / Controller Port Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each Amiga has two  [nine-pin connectors](hardware/e-explanation-of-i-o-connectors-game-controller-interface.md)  that can be used for input or
output with a variety of controllers.  Usually, the  [nine-pin connectors](hardware/e-explanation-of-i-o-connectors-game-controller-interface.md) 
are used with a mouse or joystick but they will also accept input from
light pens, paddles, trackballs, and other popular input devices.

Figure 8-1 shows one of the two connectors and the corresponding face-on
view of a standard controller plug, while table 8-1 gives the pin
assignments for some typical controllers.

```c
     [Figure 8-1: Controller Plug and Computer Connector](hardware/hard-pics-8-1-pic.md) 


                  Table 8-1: Typical Controller Connections

                       Mouse,
                     Trackball,  Proportional      X-Y
                      Driving     Controller   Proportional
```
  Pin    Joystick    Controller     (Pair)       Joystick    Light Pen
  ---    --------    ----------  ------------  ------------  ---------
  1      Forward     V-pulse       ---           Button 3**  ---

  2      Back        H-pulse       ---           ---         ---

  3      Left        VQ-pulse      Left button   Button 1    ---

  4      Right       HQ-pulse      Right button  Button 2    ---

  5*     ---         Middle        Right POT     POT X       Pen pressed

                     button**                                to screen
  6*     Button 1    Left button   ---           ---         Beam trigger

  7      ---         +5V           +5V           +5V         +5V

  8      GND         GND           GND           GND         GND

  9*     Button 2**  Right button  Left POT      POT Y       Button 2**




                *  These pins may also be configured as outputs
                ** These buttons are optional
 [Registers Used with the Controller Port](hardware/8-controller-port-interface-registers-used-with-controller.md) 
 [Reading Mouse/Trackball Controllers](hardware/8-controller-port-interface-reading-mouse-trackball.md) 
 [Reading Digital Joystick Controllers](hardware/8-controller-port-interface-reading-digital-joystick.md) 
 [Reading Proportional Controllers](hardware/8-controller-port-interface-reading-proportional-controllers.md) 
 [Reading a Light Pen](hardware/8-controller-port-interface-reading-a-light-pen.md) 
 [Digital I/O on the Controller Port](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md) 


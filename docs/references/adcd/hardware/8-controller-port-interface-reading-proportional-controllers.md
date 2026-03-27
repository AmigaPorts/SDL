---
title: 8 / Controller Port Interface / Reading Proportional Controllers
manual: hardware
chapter: hardware
section: 8-controller-port-interface-reading-proportional-controllers
functions: []
libraries: []
---

# 8 / Controller Port Interface / Reading Proportional Controllers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each of the game  [controller ports](hardware/8-interface-hardware-controller-port-interface.md)  can handle two variable-resistance
input devices, also known as proportional input devices. This section
describes how the positions of the proportional input devices can be
determined. There are two common types of proportional controllers:  the
"paddle" controller pair and the X-Y proportional joystick. A paddle
controller pair consists of two individual enclosures, each containing a
single resistor and fire-button and each connected to a common
 [controller port](hardware/8-interface-hardware-controller-port-interface.md)  input connector. Typical connections are shown in Figure
8-4.

    LEFT PADDLE                          RIGHT PADDLE

          resistive element                    resistive element

     ____/\  /\  /\  /\  /\____           ____/\  /\  /\  /\  /\____
    |      \/  \/  \/  \/                |      \/  \/  \/  \/
    |+5           ^                      |+5           ^
    |             |_ _ _ _ _ _           |             |_ _ _ _ _ _
                              |                                    |
  pin 7                     pin 9      pin 7                     pin 9



    |                         |          |                         |
    |<- - - fire button - - ->|          |<- - - fire button - - ->|
    |                         |          |                         |
  pin 8                     pin 3      pin 8                     pin 3




                Figure 8-4: Typical Paddle Wiring Diagram
In an X-Y proportional joystick, the resistive elements are connected
individually to the X and Y axes of a single controller stick.

 [Reading Proportional Controller Buttons](hardware/8-reading-controllers-reading-proportional-controller.md) 
 [Interpreting Proportional Controller Position](hardware/8-reading-controllers-interpreting-controller-position.md) 
 [Proportional Controller Registers](hardware/8-reading-controllers-proportional-controller-registers.md) 
 [Potentiometer Specifications](hardware/8-reading-proportional-controllers-potentiometer.md) 


---
title: 8 / / Reading Mouse/Trackball Controllers / Mouse Buttons
manual: hardware
chapter: hardware
section: 8-reading-mouse-trackball-controllers-mouse-buttons
functions: []
libraries: []
---

# 8 / / Reading Mouse/Trackball Controllers / Mouse Buttons

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two buttons on the standard Amiga mouse. However, the control
circuitry and software support up to three buttons.

   *  The left button on the Amiga mouse is connected to  [CIAAPRA](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md) 

```c
      ($BFE001). Port 1 uses bit 6 and port 2 uses bit 7. A logic
      state of 1 means "switch open." A logic state of 0 means "switch
      closed." (See  [Appendix F](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  for more information.)
```
   *  Button 2 (right button on Amiga mouse) is connected to pin 9 of

```c
      the  [controller ports](hardware/8-interface-hardware-controller-port-interface.md) , one of the proportional pins.  See
       [Digital Input/Output on the Controller Port](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)  for details.
```
   *  Button 3, when used, is connected to pin 5, the other

```c
      proportional  [controller input](hardware/8-interface-hardware-controller-port-interface.md) .
```

---
title: 8 / Controller Port Interface / Reading Mouse/Trackball Controllers
manual: hardware
chapter: hardware
section: 8-controller-port-interface-reading-mouse-trackball
functions: []
libraries: []
---

# 8 / Controller Port Interface / Reading Mouse/Trackball Controllers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Pulses entering the mouse inputs are converted to separate horizontal and
vertical counts.  The 8 bit wide horizontal and vertical
 [counter registers](hardware/8-reading-mouse-trackball-controllers-reading-the-counters.md)  can track mouse movement without processor
intervention.

The mouse uses quadrature inputs.  For each direction, a mechanical wheel
inside the mouse will produce two pulse trains, one 90 degrees out of
phase with the other (see Figure 8-2 for details).  The phase relationship
determines direction.


  Case 1: Count Up:
          ________            ________            ________            __
         /        \          /        \          /        \          /
  V  ___/          \________/          \________/          \________/
               ________            ________            ________
              /        \          /        \          /        \
  VQ ________/          \________/          \________/          \_______
          ___       ___       ___       ___       ___       ___       __
         /   \     /   \     / 1 \  0  /   \     /   \     /   \     /
  D0 ___/     \___/     \___/     \___/     \___/     \___/     \___/
     ________            ________            ________            _______
             \          /      1 \  0       /        \          /
  D1          \________/          \________/          \________/


  Case 2: Count Down:
          ________            ________            ________            __
         /        \          /        \          /        \          /
  V  ___/          \________/          \________/          \________/
     ________            ________            ________            _______
             \          /        \          /        \          /
  VQ          \________/          \________/          \________/
     ___       ___       ___       ___       ___       ___       ___
        \     /   \     /   \     /   \     /   \     /   \     /   \
  D0     \___/     \___/     \___/     \___/     \___/     \___/     \__
               ________            ________            ________
              /        \          /        \          /        \
  D1 ________/          \________/          \________/          \_______
          ___
             \
  D2          \___ etc           V    VQ   :   D1   D0


                                 ---------------------
                                 0    0    :    1    0
                                 0    1    :    0    1
                                 1    0    :    1    1
                                 1    1    :    0    0


                       Figure 8-2: Mouse Quadrature
The counters increment when the mouse is moved to the right or "down"
(toward you).

The counters decrement when the mouse is moved to the left or "up" (away
from you).

 [Reading the Counters](hardware/8-reading-mouse-trackball-controllers-reading-the-counters.md) 
 [Counter Limitations](hardware/8-reading-mouse-trackball-controllers-counter-limitations.md) 
 [Mouse Buttons](hardware/8-reading-mouse-trackball-controllers-mouse-buttons.md) 


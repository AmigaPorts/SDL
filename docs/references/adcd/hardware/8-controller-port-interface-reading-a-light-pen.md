---
title: 8 / Controller Port Interface / Reading A Light Pen
manual: hardware
chapter: hardware
section: 8-controller-port-interface-reading-a-light-pen
functions: []
libraries: []
---

# 8 / Controller Port Interface / Reading A Light Pen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A light pen can be connected to one of the  [controller ports](hardware/8-interface-hardware-controller-port-interface.md) . On the
A1000, the light pen must be connected to port 1. Changing ports requires
a minor internal modification. On the A500, A2000 and A3000 the default is
port 2. An internal jumper can select port 1.  Regardless of the port
used, the light pen design is the same.

The signal called "pen-pressed-to-screen" is typically actuated by a
switch in the nose of the light pen. Note that this switch is connected to
one of the potentiometer inputs and must be read as same as the right or
middle  [mouse button](hardware/8-reading-mouse-trackball-controllers-mouse-buttons.md) .

The principles of light pen operation are as follows:

   1. Just as the system exits  [vertical blank](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) , the capture circuitry

      for the light pen is automatically enabled.
   2. The video beam starts to create the picture, sweeping from left

      to right for each horizontal line as it paints the picture from
      the top of the screen to the bottom.
   3. The sensors in the light pen see a pulse of light as the video

```c
      beam passes by. The pen converts this light pulse into an
      electrical pulse on the "Beam Trigger" line (pin 6).
```
   4. This trigger signal tells the internal circuitry to capture and

```c
      save the current contents of the beam register,  [VPOSR](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md) . This
      allows you to determine where the pen was placed by reading the
      exact horizontal and vertical value of the counter beam at the
      instant the beam passed the light pen.
```
 [Reading the Light Pen Registers](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md) 


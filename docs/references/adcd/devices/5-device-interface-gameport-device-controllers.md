---
title: 5 / Device Interface / Gameport Device Controllers
manual: devices
chapter: devices
section: 5-device-interface-gameport-device-controllers
functions: []
libraries: []
---

# 5 / Device Interface / Gameport Device Controllers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga has five gameport device controller types.


```c
                 GAMEPORT DEVICE CONTROLLERS

         Controller Type         Description
         ---------------         -----------
         GPCT_MOUSE              Mouse controller
         GPCT_ABSJOYSTICK        Absolute (digital) joystick
         GPCT_RELJOYSTICK        Relative (digital) joystick
         GPCT_ALLOCATED          Custom controller
         GPCT_NOCONTROLLER       No controller
```
To use the gameport device, you must define the type of device connected
to the gameport and define how the device is to respond. The gameport
device can be set up to return the controller status immediately or only
when certain conditions have been met.

When a gameport device unit reponds to a request for input, it creates an
input event. The contents of the input event will vary based on the type
of device and the trigger conditions you have declared.

   *  A mouse controller can report input events for one, two, or three

```c
      buttons and for positive or negative (x,y) movements. A trackball
      controller or car-driving controller is generally of the same type
      and can be declared as a mouse controller.
```
   *  An absolute joystick reports one single event for each change of its

      current location. If, for example, the joystick is centered and the
      user pushes the stick forward and holds it in that position, only one
      single forward-switch event will be generated.
   *  A relative joystick, on the other hand, is comparable to an absolute

      joystick with "autorepeat" installed. As long as the user holds the
      stick in a position other than centered, the gameport device
      continues to generate position reports.
   *  There is currently no system software support for proportional

```c
      joysticks or proportional controllers (e.g., paddles). If you write
      custom code to read proportional controllers or other controllers
      (e.g., light pen) make certain that you issue [GPD_SETCTYPE](autodocs-2.0/gameport-device-gpd-setctype.md) (explained
      below) with controller type GPCT_ALLOCATED to insure that other
      applications know the connector is being used.
```
   GPCT_NOCONTROLLER.
   ------------------
   The controller type GPCT_NOCONTROLLER is not a controller at all, but
   a flag to indicate that the unit is not being used at the present
   time.


---
title: 6 / Writing Events to Input Device Stream / Setting Position Of Mouse
manual: devices
chapter: devices
section: 6-writing-events-to-input-device-stream-setting-position-of
functions: []
libraries: []
---

# 6 / Writing Events to Input Device Stream / Setting Position Of Mouse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One use of writing input events to the input device is to set the
position of the mouse pointer.  The mouse pointer can be positioned by
using the input classes IECLASS_POINTERPOS and [IECLASS_NEWPOINTERPOS](autodocs-2.0/includes-devices-inputevent-h.md) .

There are two ways to set the position of the mouse pointer using the
pre-V36 Kickstart input class IECLASS_POINTERPOS:

   *  At an absolute position on the current screen.

   *  At a position relative to the current mouse pointer position on the

      current screen.
In both cases, you set the Class field of the [InputEvent](devices/6-device-interface-input-device-event-types.md) structure to
IECLASS_POINTERPOS, ie_X with the new x-coordinate and ie_Y with the new
y-coordinate.   Absolute positioning is done by setting ie_Qualifier to
NULL and relative positioning is done by setting ie_Qualifier to
RELATIVE_MOUSE.

Once the proper values are set, pass an [IOStdReq](devices/6-input-device-device-interface.md) to the input device with
a pointer to the [InputEvent](devices/6-device-interface-input-device-event-types.md) structure set in io_Data and io_Command set to
[IND_WRITEEVENT](autodocs-2.0/input-device-ind-writeevent.md).

There are three ways to set the mouse pointer position using
IECLASS_NEWPOINTERPOS:

   *  At an absolute x-y coordinate on a screen-you specify the exact

      location of the pointer and which screen.
   *  At an relative x-y coordinate-you specify where it will go in

      relation to the current pointer position and which screen.
   *  At a normalized position on a tablet device-you specify the maximum

      x-value and y-value of the tablet and an x-y coordinate between them
      and the input device will normalize it to fit.
The basic steps required are the same for all three methods.

   *  Get a pointer to the screen where you want to position the pointer.

      This is not necessary for the tablet device.
   *  Set up a structure to indicate the new position of the pointer.

For absolute and relative positioning, you set up an [IEPointerPixel](devices/6-device-interface-input-device-event-types.md)
structure with iepp_Position.X set to the new x-coordinate,
iepp_Position.Y set to the new y-coordinate and iepp_Screen set to the
screen pointer. You set up an [InputEvent](devices/6-device-interface-input-device-event-types.md) structure with ie_SubClass set to
IESUBCLASS_PIXEL, a pointer to the IEPointerPixel structure set in
ie_EventAddress, IECLASS_NEWPOINTERPOS set in Class, and ie_Qualifier set
to either IEQUALIFIER_RELATIVEMOUSE for relative positioning or NULL for
absolute positioning.

For tablet positioning, you set up an [IEPointerTablet](devices/6-device-interface-input-device-event-types.md) structure with
iept_Range.X set to the maximum x-coordinate and iept_Range.Y set to the
maximum y-coordinate, and iept_Value.X set to the new x-coordinate and
iept_Value.Y set to the new y-coordinate. You set up an [InputEvent](devices/6-device-interface-input-device-event-types.md)
structure with a pointer to the IEPointerTablet structure set in
ie_EventAddress, ie_SubClass to IESUBCLASS_TABLET and Class set to
IECLASS_NEWPOINTERPOS.

Finally, for all three methods, pass an [IOStdReq](devices/6-input-device-device-interface.md) to the device with a
pointer to the [InputEvent](devices/6-device-interface-input-device-event-types.md) structure set in io_Data and io_Command set to
[IND_WRITEEVENT](autodocs-2.0/input-device-ind-writeevent.md).

The following example sets the mouse pointer at an absolute position on a
public screen using IECLASS_NEWPOINTERPOS.  Notice that it uses V36
functions wherever possible.


```c
     [Set_Mouse.c](devices/devices-dev-examples-set-mouse-c.md) 
```

---
title: 6 Input Device
manual: devices
chapter: devices
section: 6-input-device
functions: [PeekQualifier]
libraries: [input.device]
---

# 6 Input Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The input device is the central collection point for input events
disseminated throughout the system. The best way to describe the input
device is a manager of a stream with feeders.  The input device itself and
other modules such as the file system add events to the stream; so do
input device "users" - programs or other devices that use parts of the
stream or change it in some way.  Feeders of the input device include the
keyboard, timer and gameport devices.  The keyboard, gameport, and timer
devices are special cases in that the input device opens them and asks
them for input. Users of the input device include Intuition and the
console device.


```c
                     NEW FEATURES FOR VERSION 2.0

                    Feature              Description
             ---------------------    -----------------
             [IECLASS_NEWPOINTERPOS](devices/6-writing-events-to-input-device-stream-setting-position-of.md)    Input Event Class
             IECLASS_MENUHELP         Input Event Class
             IECLASS_CHANGEWINDOW     Input Event Class
             IESUBCLASS_COMPATIBLE    Input Event SubClass
             IESUBCLASS_PIXEL         Input Event SubClass
             IESUBCLASS_TABLET        Input Event SubClass
             [PeekQualifier()](autodocs-2.0/input-device-peekqualifier.md)          Function
```
   Compatibility Warning:
   ----------------------
   The new features for the 2.0 input device are not backwards
   compatible.

 [Input Device Commands and Functions](devices/6-input-device-input-device-commands-and-functions.md) 
 [Device Interface](devices/6-input-device-device-interface.md) 
 [Using the Mouse Port With the Input Device](devices/6-input-device-using-the-mouse-port-with-the-input-device.md) 
 [Adding an Input Handler](devices/6-input-device-adding-an-input-handler.md) 
 [Writing Events to the Input Device Stream](devices/6-input-device-writing-events-to-the-input-device-stream.md) 
 [Setting the Key Repeat Threshold](devices/6-input-device-setting-the-key-repeat-threshold.md) 
 [Setting the Key Repeat Interval](devices/6-input-device-setting-the-key-repeat-interval.md) 
 [Determining the Current Qualifiers](devices/6-input-device-determining-the-current-qualifiers.md) 
 [Input Device and Intuition](devices/6-input-device-input-device-and-intuition.md) 
 [Example Input Device Program](devices/devices-dev-examples-swap-buttons-c.md) 
 [Additional Information on the Input Device](devices/6-input-device-additional-information-on-the-input-device.md) 

---

## See Also

- [PeekQualifier — input.device](../autodocs/input.device.md#peekqualifier)

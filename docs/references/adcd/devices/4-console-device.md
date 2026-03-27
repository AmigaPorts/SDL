---
title: 4 Console Device
manual: devices
chapter: devices
section: 4-console-device
functions: []
libraries: []
---

# 4 Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The console device provides the text-oriented interface for Intuition
windows.  It acts like an enhanced ASCII terminal obeying many of the
standard ANSI sequences as well as special sequences unique to the Amiga.
The console device also provides a copy-and-paste facility and an internal
character map to redraw a window when it is resized.


```c
                  NEW CONSOLE FEATURES FOR VERSION 2.0

               Feature                       Description
               -------                       -----------
              [CONU_LIBRARY](devices/4-device-interface-opening-the-console-device.md)                    New #define
              [CONU_STANDARD](devices/4-device-interface-opening-the-console-device.md)                   New #define
              [CONU_CHARMAP](devices/4-device-interface-opening-the-console-device.md)                    Console Unit
              [CONU_SNIPMAP](devices/4-device-interface-opening-the-console-device.md)                    Console Unit
              [CONFLAG_DEFAULT](devices/4-device-interface-opening-the-console-device.md)                 Console Flag
              [CONFLAG_NODRAW_ON_NEWSIZE](devices/4-device-interface-opening-the-console-device.md)       Console Flag
```
   Compatibility Warning:
   ----------------------
   The new features for the 2.0 console device are not backwards
   compatible.

 [Console Device Commands and Functions](devices/4-console-device-console-device-commands-and-functions.md) 
 [Device Interface](devices/4-console-device-device-interface.md) 
 [About Console I/O](devices/4-console-device-about-console-i-o.md) 
 [Writing to the Console Device](devices/4-console-device-writing-to-the-console-device.md) 
 [Reading from the Console Device](devices/4-console-device-reading-from-the-console-device.md) 
 [Copy and Paste Support](devices/4-console-device-copy-and-paste-support.md) 
 [Selecting Raw Input Events](devices/4-console-device-selecting-raw-input-events.md) 
 [Input Event Reports](devices/4-console-device-input-event-reports.md) 
 [Using the Console Device Without a Window](devices/4-console-device-using-the-console-device-without-a-window.md) 
 [Where Is All the Keymap Information?](devices/4-console-device-where-is-all-the-keymap-information.md) 
 [Console Device Caveats](devices/4-console-device-console-device-caveats.md) 
 [Console Device Example Code](devices/devices-dev-examples-console-c.md) 
 [Additional Information on the Console Device](devices/4-console-device-additional-information-on-the-console.md) 


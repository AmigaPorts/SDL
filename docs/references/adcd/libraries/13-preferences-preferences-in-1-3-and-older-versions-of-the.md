---
title: 13 Preferences / Preferences in 1.3 and Older Versions of the OS
manual: libraries
chapter: libraries
section: 13-preferences-preferences-in-1-3-and-older-versions-of-the
functions: [DoubleClick]
libraries: [intuition.library]
---

# 13 Preferences / Preferences in 1.3 and Older Versions of the OS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In 1.3, the Preferences program allows the user to see and change many
system wide parameters, like the Workbench colors, pointer image, printer
settings etc.  When a Preferences item is changed, the new setting can be
used temporarily (until a reset occurs) or stored permanently in the
devs:system-configuration file.   Under 1.3, all Preferences items are
stored in this file which the system reads at boot time to find out how to
set various system-wide options.

The 1.3 Preferences system allows the user to change the following items:

  * Date and time of day. These are automatically saved in the

    battery-backed clock, if one is present.
  * Key repeat speed - the speed at which a key repeats when held down.

  * Key repeat delay - the amount of delay before a key begins repeating.

  * Mouse speed - how fast the pointer moves when the user moves the

    mouse.
  * Double-click delay - maximum time allowed between the two clicks of a

```c
    mouse double click.  For information about how to test for
    double-click timeout, see the description of the [DoubleClick()](libraries/10-the-mouse-mouse-usage-example.md)
    function in the Amiga ROM Kernel Reference Manual:
    [Includes and Autodocs](autodocs-2.0/intuition-library-doubleclick.md).
```
  * Text size - size of the default font characters.  The user can choose

```c
    64-column mode (64 characters on a line in high-resolution and 32
    characters in low-resolution mode) or 80 column mode (80 characters
    on a line in high-resolution and 40 characters in low-resolution
    mode).  The first variable in the [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) structure is
    FontHeight, which is the height of the characters in display lines.
    If this is equal to the constant TOPAZ_EIGHTY, the user has chosen
    the 80-column mode.  If it is equal to TOPAZ_SIXTY, the user has
    chosen the 64-column mode.  Note that certain utility programs allow
    the user to change the default font under 1.3, so you cannot rely on
    the default font being Topaz 8 or 9.
```
  * Display centering - allows the user to center the image on the video

    display.
  * Serial port - the user can change the baud rate and other serial port

    parameters to accommodate whatever device is attached to the serial
    connector.  Normally you use these values as defaults when you open
    the serial device.  If you change the baud rate or other serial port
    options locally, it is good practice to reset them to the values
    specified in Preferences before quitting.
  * Workbench colors - the user can change any of the four colors in the

    1.3 Workbench screen by adjusting the amounts of red, green and blue
    in each color.
  * Printer - the user can select from a number of printers supported by

    the Amiga and also indicate whether the printer is connected to the
    serial connector or the parallel connector.
  * Print characteristics - the user can select paper size, right and

    left margin, continuous feed or single sheets, draft or letter
    quality, pitch and line spacing.  For graphic printing, the user can
    specify the density, scaling method, select a vertical or horizontal
    dump, etc.
 [Reading 1.3 Preferences](libraries/13-preferences-in-1-3-and-older-versions-reading-1-3.md)         [Setting 1.3 Preferences](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md) 
 [Preferences Structure in 1.3](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md)    [Alternatives to SetPrefs](libraries/13-preferences-in-1-3-and-older-versions-alternatives-to.md) 

---

## See Also

- [DoubleClick — intuition.library](../autodocs/intuition.library.md#doubleclick)

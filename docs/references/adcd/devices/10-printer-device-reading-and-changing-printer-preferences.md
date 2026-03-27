---
title: 10 Printer Device / Reading and Changing Printer Preferences Settings
manual: devices
chapter: devices
section: 10-printer-device-reading-and-changing-printer-preferences
functions: []
libraries: []
---

# 10 Printer Device / Reading and Changing Printer Preferences Settings

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The user preferences can be read and changed without running the Workbench
Preferences tool.  Reading printer preferences can be done by referring to
PD->pd_Preferences.  Listed on the next page are the printer Preferences
fields and their valid ranges.

Text Preferences
----------------

    PrintPitch        -  PICA, ELITE, FINE
    PrintQuality      -  DRAFT, LETTER
    PrintSpacing      -  SIX_LPI, EIGHT_LPI
    PrintLeftMargin   -  1 to PrintRightMargin
    PrintRightMargin  -  PrintLeftMargin to 999
    PaperLength       -  1 to 999
    PaperSize         -  US_LETTER, US_LEGAL, N_TRACTOR, W_TRACTOR,CUSTOM
    PaperType         -  FANFOLD, SINGLE
Graphic Preferences
-------------------

    PrintImage        -  IMAGE_POSITIVE, IMAGE_NEGATIVE
    PrintAspect       -  ASPECT_HORIZ, ASPECT_VERT
    PrintShade        -  SHADE_BW, SHADE_GREYSCALE, SHADE_COLOR
    PrintThreshold    -  1 to 15
    PrintFlags        -  CORRECT_RED, CORRECT_GREEN, CORRECT_BLUE,
                         CENTER_IMAGE, IGNORE_DIMENSIONS,
                         BOUNDED_DIMENSIONS, ABSOLUTE_DIMENSIONS,
                         PIXEL_DIMENSIONS, MULTIPLY_DIMENSIONS,
                         INTEGER_SCALING, ORDERED_DITHERING,
                         HALFTONE_DITHERING, FLOYD_DITHERING,
                         ANTI_ALIAS, GREY_SCALE2
    PrintMaxWidth     -  0 to 65535
    PrintMaxHeight    -  0 to 65535
    PrintDensity      -  1 to 7
    PrintXOffset      -  0 to 255
This example program changes various settings in the printer device's
copy of preferences.


```c
     [Set_Prefs.c](devices/devices-dev-examples-set-prefs-c.md) 
```
   Do Your Duty.
   -------------
   The application program is responsible for range checking if the user
   is able to change the preferences from within the application.


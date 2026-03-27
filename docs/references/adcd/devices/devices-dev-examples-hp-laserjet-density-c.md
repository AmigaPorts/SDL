---
title: Devices/Dev_examples/HP_Laserjet_density.c
manual: devices
chapter: devices
section: devices-dev-examples-hp-laserjet-density-c
functions: []
libraries: []
---

# Devices/Dev_examples/HP_Laserjet_density.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
        Density module for HP_LaserJet
*/

#include <exec/types.h>
#include <devices/printer.h>
#include <devices/prtbase.h>

SetDensity(density_code)
ULONG density_code;
{
```c
        extern struct PrinterData *PD;
        extern struct PrinterExtendedData *PED;
        extern char StartCmd[];

        /* SPECIAL_DENSITY     0   1   2    3    4    5    6    7 */
        static int XDPI[8] = {75, 75, 100, 150, 300, 300, 300, 300};
        static char codes[8][3] = {
        {'0','7','5'},{'0','7','5'},{'1','0','0'},{'1','5','0'},
        {'3','0','0'},{'3','0','0'},{'3','0','0'},{'3','0','0'},
        };

        density_code /= SPECIAL_DENSITY1;
        PED->ped_MaxXDots = XDPI[density_code] * 8; /* 8 inches */

        /* default is 10.0, US_LEGAL is 14.0 */
        PED->ped_MaxYDots =
                PD->pd_Preferences.PaperSize == US_LEGAL ? 14 : 10;
        PED->ped_MaxYDots *= XDPI[density_code];

        PED->ped_XDotsInch = PED->ped_YDotsInch = XDPI[density_code];
        StartCmd[8] = codes[density_code][0];
        StartCmd[9] = codes[density_code][1];
        StartCmd[10] = codes[density_code][2];
```
}


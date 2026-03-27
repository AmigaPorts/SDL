# 13 / Preferences in 1.3 and Older Versions / Alternatives to SetPrefs


Since the Amiga is a multitasking system, it is rarely correct for a
single Amiga application to modify the user's system-wide Preferences.
Instead, use methods such as the following to modify only your own
application's appearance or behavior.

  * Custom screen applications can control their own display mode,

```c
    resolution, palette, and fonts. Use functions such a [LoadRGB4()](../Libraries_Manual_guide/node0331.html) to
    change your own screen's palette, and [SetFont()](../Libraries_Manual_guide/node03D6.html) to change your own
    screen and window fonts. Workbench applications should never change
    the attributes of the user's Workbench.
```
  * The mouse pointer for a window may be changed with [SetPointer()](../Libraries_Manual_guide/node01ED.html#line4).

  * Serial device settings can be changed with the command

    SDCMD_SETPARAMS.
  * Printer device settings may be changed by altering the printer's copy

    of the Preferences structure when you have the printer open. Note
    that Amiga applications should only keep the printer open while they
    are printing.  This allows other applications to print, and also
    allows user changes to Printer Preferences to take effect.
See the [Inutition](../Libraries_Manual_guide/node0002.html) and [graphics](../Libraries_Manual_guide/node0004.html) chapters of this manual, and the
"[Printer Device](../Devices_Manual_guide/node003E.html)" and "[Serial Device](../Devices_Manual_guide/node009A.html)" chapters of the Amiga ROM Kernel
Reference Manual: Devices for more information.


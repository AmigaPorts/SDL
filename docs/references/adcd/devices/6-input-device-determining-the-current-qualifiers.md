---
title: 6 Input Device / Determining the Current Qualifiers
manual: devices
chapter: devices
section: 6-input-device-determining-the-current-qualifiers
functions: [PeekQualifier]
libraries: [input.device]
---

# 6 Input Device / Determining the Current Qualifiers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some applications need to know whether the user is holding down a
qualifier key or a mouse button during an operation.  To determine the
current qualifiers, you call the input device function [PeekQualifier()](autodocs-2.0/input-device-peekqualifier.md).

[PeekQualifier()](autodocs-2.0/input-device-peekqualifier.md) returns what the input device considers to be the current
qualifiers at the time PeekQualifier() is called (e.g., keyboard
qualifiers and mouse buttons).   This does not include any qualifiers
which have been added, removed or otherwise modified by input handlers.

In order to call the function, you must set a pointer to the input device
base address.  The pointer must be declared in the global data area of
your program.  Once you set the pointer, you can call the function. You
must open the device in order to access the device base address.

[PeekQualifier()](autodocs-2.0/input-device-peekqualifier.md) returns an unsigned word with bits set according to the
qualifiers in effect at the time the function is called.  It takes no
parameters.

   struct Library *InputBase;      /* Input device base address pointer */

   VOID main(VOID)
   {
   struct IOStdReq   *InputIO;     /* I/O request block */
   UWORD  Quals;                   /* qualifiers */
     .
     .
     .
   if (!OpenDevice("input.device",NULL,(struct IORequest *)InputIO,NULL))
```c
        {
        /* Set input device base address in InputBase */
        InputBase = (struct Library *)InputIO->io_Device;

        /* Call the function */
        Quals = PeekQualifier();
        .
        .
        .
        CloseDevice(InputIO);
        }
```
   }
The qualifiers returned are listed in the table below.



           Bit     Qualifier               Key or Button
           ---     ---------               -------------
            0      IEQUALIFIER_LSHIFT      Left Shift
            1      IEQUALIFIER_RSHIFT      Right Shift
            2      IEQUALIFIER_CAPSLOCK    Caps Lock
            3      IEQUALIFIER_CONTROL     Control
            4      IEQUALIFIER_LALT        Left Alt
            5      IEQUALIFIER_RALT        Right Alt
            6      IEQUALIFIER_LCOMMAND    Left-Amiga
            7      IEQUALIFIER_RCOMMAND    Right-Amiga
            12     IEQUALIFIER_MIDBUTTON   Middle Mouse
            13     IEQUALIFIER_RBUTTON     Right Mouse
            14     IEQUALIFIER_LEFTBUTTON  Left Mouse

---

## See Also

- [PeekQualifier — input.device](../autodocs/input.device.md#peekqualifier)

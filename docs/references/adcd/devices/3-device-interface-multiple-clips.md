---
title: 3 / Device Interface / Multiple Clips
manual: devices
chapter: devices
section: 3-device-interface-multiple-clips
functions: [OpenDevice]
libraries: [exec.library]
---

# 3 / Device Interface / Multiple Clips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The clipboard supports multiple clips, i.e., the clipboard device can
contain more than one distinct piece of data.  This is not to be confused
with the IFF CAT CLIP, which allows for different representation of the
same data.

The multiple clips are implemented as different units in the clipboard
device.  The unit is specified at [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) time.


```c
    struct IOClipReq *ClipIO;
    LONG unit;

    OpenDevice("clipboard.device", unit, ClipIO, 0);
```
By default, applications should use clipboard unit 0. However, it is
recommended that each application provide a mechanism for selecting the
unit number which will be used when the clipboard is opened. This will
allow the user to create a convention for storing different types of data
in the clipboard. Applications should never write to clipboard unit 0
unless the user requests it (e.g., selecting COPY or CUT within an
application).

Clipboard units 1-255 can be used by the more advanced user for:

   *  Sharing data between applications within an ARexx Script.

   *  Customizing applications to store different kinds of data in

      different clipboard units.
   *  Customizing an application to use multiple cut/copy/paste buffers.

   *  Specialized utilities which might display and/or automatically modify

      the contents of a clipboard unit.
All applications which provide CUT, COPY and PASTE capabilities, should,
at a minimum, provide support for clipboard unit 0.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)

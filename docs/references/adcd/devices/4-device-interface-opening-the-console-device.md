---
title: 4 / Device Interface / Opening The Console Device
manual: devices
chapter: devices
section: 4-device-interface-opening-the-console-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 4 / Device Interface / Opening The Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Four primary steps are required to open the console device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [IOStdReq](devices/4-console-device-device-interface.md). The IOStdReq

```c
      structure is created by the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function. CreateExtIO will
      initialize your I/O request to point to your reply port.
```
   *  Open an Intuition window and set a pointer to it in the io_Data field

```c
      of the [IOStdReq](devices/4-console-device-device-interface.md) and the size of the window in the io_Length field.
      This is the window to which the console will be attached.  The window
      must be SIMPLE_REFRESH for use with the CONU_CHARMAP and CONU_SNIPMAP
      units.
```
   *  Open the console device.  Call [OpenDevice()](autodocs-2.0/console-device-opendevice.md) passing it the I/O

      request and the type of console unit set in the unit and flags
      fields. Console unit types and flag values are listed below.
Console device units:

   *  CONU_LIBRARY  - Return the device library vector pointer used for

      calling console device functions.  No console is opened.
   *  CONU_STANDARD - Open a standard console.

   *  CONU_CHARMAP  - Open a console with a character map.

   *  CONU_SNIPMAP  - Open a console with a character map and

      copy-and-paste support.
See the include file devices/[conunit.h](autodocs-2.0/includes-devices-conunit-h.md) for the unit definitions
and the Amiga ROM Kernel Reference Manual: Includes and Autodocs for an
explanation of each unit.

   No Changes Required
   -------------------
   CONU_STANDARD has a numeric value of zero to insure compatibility
   with pre-V36 applications.  CONU_LIBRARY has a numeric value of
   negative one and is also compatible with pre-V36 applications.

Console device flags:

   *  CONFLAG_DEFAULT - The console device will redraw the window when it

      is resized.
   *  CONFLAG_NODRAW_ON_NEWSIZE - The console device will not redraw the

      window when it is resized
The character map units, CONU_CHARMAP and CONU_SNIPMAP, are the only units
which use the flags parameter to set how the character map is used.
CONU_STANDARD units ignore the flags parameter.

See the include file devices/[conunit.h](autodocs-2.0/includes-devices-conunit-h.md) for the flag definitions and the
Amiga ROM Kernel Reference Manual: Includes and Autodocs for an
explanation of the flags.


```c
    struct MsgPort *ConsoleMP;   /* Message port pointer */
    struct IOStdReq *ConsIO;     /* I/O structure pointer */
    struct Window   *win = NULL; /* Window pointer */

    struct NewWindow nw =
    {
        10, 10,                    /* starting position (left,top) */
        620,180,                   /* width, height */
        -1,-1,                     /* detailpen, blockpen */
        CLOSEWINDOW,               /* flags for idcmp */
        WINDOWDEPTH|WINDOWSIZING|
        WINDOWDRAG|WINDOWCLOSE|
        SIMPLE_REFRESH|ACTIVATE,    /* window flags */
        NULL,                      /* no user gadgets */
        NULL,                      /* no user checkmark */
        "Console Test",            /* title */
        NULL,                      /* pointer to window screen */
        NULL,                      /* pointer to super bitmap */
        100,45,                    /* min width, height */
        640,200,                   /* max width, height */
        WBENCHSCREEN               /* open on workbench screen */
    };

        /* Create reply port console */
    if (!(ConsoleMP = CreatePort("RKM.Console",0)))
        cleanexit("Can't create write port\n",RETURN_FAIL);

        /* Create message block for device I/O */
    if (!(ConsIO = CreateExtIO(ConsoleMP,sizeof(struct IOStdReq))))
        cleanexit("Can't create IORequest\n",RETURN_FAIL);

        /* Open a window - we assume intuition.library is already open */
    if (!(win = OpenWindow(&nw)))
        cleanexit("Can't open window\n",RETURN_FAIL);

        /* Set window pointer and size in I/O request */
    ConsIO->io_Data = (APTR) win;
    ConsIO->io_Length = sizeof(struct Window);

        /* Open the console device */
    if (error = OpenDevice("console.device",CONU_CHARMAP,ConsIO,
                                            CONFLAG_DEFAULT))
        cleanexit("Can't open console.device\n",RETURN_FAIL);
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)

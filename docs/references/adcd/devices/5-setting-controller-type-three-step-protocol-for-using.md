---
title: 5 / Setting Controller Type /Three Step Protocol for Using Gameport Device
manual: devices
chapter: devices
section: 5-setting-controller-type-three-step-protocol-for-using
functions: [Forbid, Permit]
libraries: [exec.library]
---

# 5 / Setting Controller Type /Three Step Protocol for Using Gameport Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Step 1:

```c
    Send [GPD_ASKCTYPE](devices/5-setting-and-reading-controller-type-determining-the.md) to the device and check for a GPCT_NOCONTROLLER
    return. Never issue [GPD_SETCTYPE](autodocs-2.0/gameport-device-gpd-setctype.md) without checking whether the desired
    gameport unit is in use.
```
Step 2:

```c
    If GPCT_NOCONTROLLER is returned, you have access to the gameport.
    Set the allocation flag to GPCT_MOUSE, GPCT_ABSJOYSTICK or
    GPCT_RELJOYSTICK if you use a system supported controller, or
    GPCT_ALLOCATED if you use a custom controller.

    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    BOOL set_controller_type(type)
    BYTE type;
    {

    BOOL success = FALSE;
    BYTE controller_type = 0;

    Forbid();                           /*critical section start */
    GameIO->io_Command = GPD_ASKCTYPE;  /* inquire current status */
    GameIO->io_Length = 1;
    GameIO->io_Flags = IOF_QUICK;
    GameIO->io_Data = (APTR)&controller_type; /* put answer in here */
    DoIO(GameIO);

    /* No one is using this device unit, let's claim it */
    if (controller_type == GPCT_NOCONTROLLER)
        {
        GameIO->io_Command = GPD_SETCTYPE;/* set controller type */
        GameIO->io_Length = 1;
        GameIO->io_Data = (APTR)&type;  /* set to input param */
        DoIO( GameIO);
        success = TRUE;
        UnitOpened = TRUE;
        }
    Permit(); /* critical section end */

    /* success can be TRUE or FALSE, see above */
    return(success);
    }
```
Step 3:

```c
    The program must set the controller type back to GPCT_NOCONTROLLER
    upon exiting your program:

    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    void free_gp_unit()
    {
    BYTE type = GPCT_NOCONTROLLER;
    GameIO->io_Command = GPD_SETCTYPE;  /* set controller type */
    GameIO->io_Length = 1;
    GameIO->io_Data = (APTR)&type;      /* set to unused */
    DoIO( GameIO);
    }
```
This three step protocol allows applications to share the gameport device
in a system compatible way.


```c
    A Word About The Functions.
    ---------------------------
    The functions shown above are designed to be included in any
    application using the gameport device.  The first function,
    set_controller_type(), would be the first thing done after opening
    the gameport device. The second function, free_gp_unit(), would be
    the last thing done before closing the device.
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)

---
title: 32 / Expansion Board Drivers / Disk Based Drivers
manual: libraries
chapter: libraries
section: 32-expansion-board-drivers-disk-based-drivers
functions: [InitResident]
libraries: [exec.library]
---

# 32 / Expansion Board Drivers / Disk Based Drivers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Disk-based expansion board drivers and their icons are generally placed in
the SYS:Expansion drawer of the user's SYS: disk or partition.  The icon
Tool Type field must contain the unique Hardware Manufacturer number, and
the Product number of the expansion board(s) the driver is written for.
(For more about icon Tool Type fields refer to the chapter on
"[Workbench and Icon Library](libraries/14-the-icon-library-the-tool-types-array.md)".)

The BindDrivers command issued during the disk startup-sequence attempts
to match disk-based drivers with their expansion boards.  To do this,
BindDrivers looks in the Tool Types field of all icon files in
SYS:Expansion.  If the Tool Type "PRODUCT" is found in the icon, then this
is an icon file for a driver.  Binddrivers will then attempt to match the
manufacturer and product number in this PRODUCT Tool Type with those of a
board that was configured at expansion time.

For example, suppose you are manufacturer #1019.  You have two products,
#1 and #2 which both use the same driver.  The icon for your driver for
these two products would have a Tool Type set to "PRODUCT=1019/1|1019/2".
This means: I am an icon for a driver that works with product number 1 or
2 from manufacturer 1019, now bind me.  Spaces are not legal.  Here are
two other examples:


```c
        PRODUCT=1208/11    is the Tool Type for a driver for product
                           11 from manufacturer number 1208.

        PRODUCT=1017       is the Tool Type for a driver for any
                           product from manufacturer number 1017.
```
If a matching board is found for the disk-based driver, the driver code is
loaded and then initialized with the Exec [InitResident()](autodocs-2.0/exec-library-initresident.md) function.  From
within its initialization code, the driver can get information about the
board it is bound to by calling the expansion.library function
[GetCurrentBinding()](autodocs-2.0/expansion-library-getcurrentbinding.md).  This function will provide the driver with a copy of
a [CurrentBinding](autodocs-2.0/includes-libraries-configvars-h.md) structure, including a pointer to a [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure
(possibly linked to additional ConfigDevs via the [cd_NextCD](libraries/32-expansion-library-the-expansion-sequence.md) field) of the
expansion board(s) that matched the manufacturer and product IDs.


```c
    /* this structure is used by GetCurrentBinding() */
    /* and SetCurrentBinding()                       */
    struct CurrentBinding {
        struct ConfigDev *cb_ConfigDev;    /* first configdev in chain */
        UBYTE *          cb_FileName;      /* file name of driver */
        UBYTE *          cb_ProductString; /* product # string */
        UBYTE **         cb_ToolTypes;     /* tooltypes from disk object */
    };
```
[GetCurrentBinding()](autodocs-2.0/expansion-library-getcurrentbinding.md) allows the driver to find out the base address and
other information about its board(s).  The driver must unset the CONFIGME
bit in the cd_Flags field of the [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure for each board it
intends to drive, and record the driver's Exec node pointer in the
cd_Driver structure.  This node should contain the LN_NAME and LN_TYPE
(i.e., NT_DEVICE, NT_TASK, etc.) of the driver.


```c
    Important Note:
    ---------------
    The [GetCurrentBinding()](autodocs-2.0/expansion-library-getcurrentbinding.md) function, and driver binding in general, must
    be bracketed by an [ObtainConfigBinding()](autodocs-2.0/expansion-library-obtainconfigbinding.md) and [ReleaseConfigBinding()](autodocs-2.0/expansion-library-releaseconfigbinding.md)
    semaphore. The BindDrivers command obtains this semaphore and
    performs a [SetCurrentBinding()](autodocs-2.0/expansion-library-setcurrentbinding.md) before calling [InitResident()](autodocs-2.0/exec-library-initresident.md),
    allowing the driver to simply do a GetCurrentBinding().
```
Full source code for a disk-based Expansion or DEVS: sample device driver
may be found in the Addison-Wesley Amiga ROM Kernel Reference Manual:
Devices.  Autodocs for expansion.library functions may be found in the
Addison-Wesley Amiga ROM Kernel Reference Manual: Includes and Autodocs.

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)

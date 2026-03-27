---
title: Buffer Management
manual: amiga-mail
chapter: amiga-mail
section: buffer-management
functions: [OpenDevice]
libraries: [exec.library]
---

# Buffer Management

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Unlike most other Exec Device drivers, SANA-II drivers have no internal
buffers. Instead, they read/write to/from an abstract data structure
allocated by the driver user. The driver accesses these buffers only via
functions that the driver user provides to the driver. The driver user
must provide two functions--one copies data to the abstract data structure
and one copies data from the abstract data structure. The driver user can
therefore choose the data structure used for buffer management by both the
driver and driver user in order to have efficient memory and CPU usage
overall.

The IOSana2Req contains a pointer to data and the length of said data. A
driver is not allowed to make assumptions about how the data is stored.
The driver cannot directly manipulate or examine the buffer in any manner.
The driver can only access the buffer by calling the functions provided by
the driver user.

Before calling OpenDevice(), the driver user points ios2_BufferManagement
to a list of tags (defined in <devices/sana2.h>) which include pointers to
the buffer management functions required by the driver (defined below).
The driver will fail to open if the driver user does not supply all of the
required functions.  If the device opens successfully, the driver sets
ios2_BufferManagement to a value which this opener must use in all future
calls to the driver.  This "magic cookie" is used from then on to access
these functions (a "magic cookie" is a value which one software entity
passes to another but which is only meaningful to one of the software
entities).  The driver user may not use the "magic cookie" in any way--it
is for the driver to do with as it wishes.  The driver could in theory
choose to just copy the tag list to driver-owned memory and then parse the
list for every IORequest, but it is much more efficient for the driver to
create some sort of table of functions and to point ios2_BufferManagement
to that table.

The specification currently includes only two tags for the OpenDevice()
ios2_BufferManagement tag list:


    S2_CopyToBuff  - This is a pointer to a function which conforms to
             the CopyToBuff Autodoc.

    S2_CopyFromBuff - This is a pointer to a function which conforms to
             the CopyFromBuff Autodoc.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)

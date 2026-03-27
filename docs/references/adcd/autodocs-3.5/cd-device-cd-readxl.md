---
title: cd.device/CD_READXL
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-readxl
functions: [AbortIO, OpenDevice]
libraries: [exec.library, timer.device]
---

# cd.device/CD_READXL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       CD_READXL -- [Read](autodocs-3.5/dos-library-read-2.md) from CD-ROM into memory via transfer list.
```
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_READXL
       io_Data         pointer to transfer list (i.e. struct [List](autodocs-3.5/include-exec-lists-h.md) *).
       io_Length       maximum transfer length (WORD multiple) or 0.
       io_Offset       byte offset from the start of the disk describing
                       where to read data from, must be a WORD multiple.
```
   RESULTS

```c
       io_Error        0 for success, or an error code as described in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual       if io_Error is 0, number of bytes actually transferred
```
   FUNCTION

```c
       This command starts reading data off the disk at the specified
       location and deposits it into memory according to the nodes in a
       transfer list.  The pointer to the list of transfer nodes is placed
       in io_Data.  If you have a non-circular transfer list, simply set
       io_Length to 0 (0 is special and means ignore io_Length) -- your
       transfer will end when your transfer list has been exhausted.  If you
       have a circular transfer list, the list will never end.  In this case,
       the transfer will terminate when io_Length bytes have been
       transferred.

       The fields in the [CDXL](autodocs-3.5/include-devices-cd-h.md) node structure are:

       struct  [CDXL](autodocs-3.5/include-devices-cd-h.md) {

           struct [MinNode](autodocs-3.5/include-exec-nodes-h.md)  Node;         /* double linkage                */
           char           *Buffer;       /* data destination              */
           [LONG](autodocs-3.5/include-exec-types-h.md)            Length;       /* must be even # bytes          */
           [LONG](autodocs-3.5/include-exec-types-h.md)            Actual;       /* bytes transferred             */
           [APTR](autodocs-3.5/include-exec-types-h.md)            IntData;      /* interrupt server data segment */
           VOID            (*IntCode)(); /* interrupt server code entry   */
           };

       The philosophy here is that you set up the buffers you want filled,
       create [CDXL](autodocs-3.5/include-devices-cd-h.md) nodes describing the locations and sizes of these
       buffers, link all the nodes together in the order that you'd like
       (even make a circular list for animations), and execute the command.
       The data will be streamed into the appropriate buffers until the
       list has been exhausted, an entry with a Length of zero is
       encountered, io_Length bytes have been transferred (if io_Length is
       non-zero), or the command is aborted with [AbortIO()](autodocs-3.5/timer-device-abortio-2.md).

       If you fill in the (*IntCode)() field with a pointer to an interrupt
       routine, your routine will be called when the transfer for the node
       is complete.  Your code will be called before the driver proceeds to
       the next node.  The interrupt should follow the same rules as standard
       interrupts (see [AddIntServer](autodocs-3.5/exec-library-addintserver-2.md) of Exec autodocs).  Register A2 will
       contain a pointer to the node just completed.  You may manipulate the
       list from within the interrupt. Your code must be brief (this is an
       interrupt).  When returning from this interrupt, D0 should be cleared
       and an RTS instruction should be used to return.

       Servers are called with the following register conventions:

           D0 - scratch
           D1 - scratch

           A0 - scratch
           A1 - server is_Data pointer (scratch)
           A2 - pointer to [CDXL](autodocs-3.5/include-devices-cd-h.md) node just completed

           A5 - jump vector register (scratch)

           all other registers must be preserved
```
   EXAMPLE

   NOTES

       Try to make sure that small buffers are not overused.  Each time
       a node is completed, an interrupt is generated.  If you find that
       your computer is acting sluggish, or the CD_READXL command is
       aborting, you are probably generating too many interrupts.  It is
       not efficient to have more than a few of these interrupts generated
       within a vertical blank.

       Unlike the READ command, the READXL command will not retry a sector
       if there is an error.  Since the READXL command's purpose is primarily
       for animations, data streaming is considered more important than the
       data itself.  An error will be returned in io_Error if a data error
       did occur.  This command will never drop to a lower speed in the event
       of an error.
   BUGS

   SEE ALSO

```c
       [CMD_READ](autodocs-3.5/trackdisk-device-cmd-read-2.md), [CD_SEEK](autodocs-3.5/cd-device-cd-seek.md), Autodocs - [AddIntServer](autodocs-3.5/exec-library-addintserver-2.md)
```

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)

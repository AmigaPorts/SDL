---
title: cd.device/CD_EJECT
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-eject
functions: []
libraries: []
---

# cd.device/CD_EJECT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       CD_EJECT -- [Open](autodocs-3.5/dos-library-open-2.md) or close the CD's drive door
```
   IO REQUEST

```c
       io_Command      CD_EJECT
       io_Data         NULL
       io_Length       requested state of drive door (0 == close, 1 == open)
       io_Offset       0
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual       previous state of drive door
```
   FUNCTION

       This command causes the CD-ROM drive's door to open or close.
       The desired state of the drive door is placed in io_Length.  The
       previous state of the drive door is returned in io_Actual.
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO


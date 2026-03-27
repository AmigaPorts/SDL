---
title: 3 Clipboard Device / Monitoring Clipboard Changes
manual: devices
chapter: devices
section: 3-clipboard-device-monitoring-clipboard-changes
functions: []
libraries: []
---

# 3 Clipboard Device / Monitoring Clipboard Changes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some applications require notification of changes to data on the
clipboard. Typically, these applications will need to do some processing
when this occurs. You can set up such an environment through the
[CBD_CHANGEHOOK](autodocs-2.0/clipboard-device-cbd-changehook.md) command. CBD_CHANGEHOOK allows you to specify a hook to be
called when the data on the clipboard changes.

For example, a show clipboard utility would need to know when the data on
the clipboard is changed so that it can display the new data.  The hook it
would specify would read the new clipboard data and display it for the
user.

You specify a hook for the clipboard device by initializing a Hook
structure and then passing an IOClipReq to the device with [CBD_CHANGEHOOK](autodocs-2.0/clipboard-device-cbd-changehook.md)
set in io_Command, 1 set in io_Length, and the address of the Hook
structure set in io_Data.


```c
    ULONG HookEntry ();            /* Declare the hook assembly function */
    struct IOClipReq *ClipIO;      /* Declare the IOClipReq */
    struct Hook *ClipHook;         /* Declare the Hook */

    /* Prepare the hook */
    ClipHook->h_Entry = HookEntry; /* C intrfce in asmbly rout. HookEntry*/
    ClipHook->h_SubEntry = HookFunc;/* Call function when Hook activated */
    ClipHook->h_Data = FindTask(NULL);/* Set pointer to current task */

    ClipIO->io_Data = (char *) ClipHook;/* Point to hook struct */
    ClipIO->io_Length = 1;              /* Add hook to clipboard */
    ClipIO->io_Command = CBD_CHANGEHOOK;
    DoIO(clipIO);
```
The above code fragment assumes that an assembly language routine
HookEntry() has been coded:


```c
    ; entry interface for C code
    _HookEntry:
            move.l  a1,-(sp)            ; push message packet pointer
            move.l  a2,-(sp)            ; push object pointer
            move.l  a0,-(sp)            ; push hook pointer
            move.l  h_SubEntry(a0),a0   ; fetch C entry point ...
            jsr     (a0)                ; ... and call it
            lea     12(sp),sp           ; fix stack
            rts
```
It also assumes that the function HookFunc() has been coded.  One of the
example programs at the end of this chapter has hook processing in it.
See the include file utility/[hooks.h](autodocs-2.0/includes-utility-hooks-h.md) and The Amiga ROM Kernel Reference
Manual: [Libraries](libraries/37-utility-library-callback-hooks.md) for further information on hooks.

You remove a hook by passing an [IOClipReq](devices/3-clipboard-device-device-interface.md) to the device with the address
of the Hook structure set in io_Data, 0 set in io_Length and
[CBD_CHANGEHOOK](autodocs-2.0/clipboard-device-cbd-changehook.md) set in io_Command.


```c
    ClipIO->io_Data = (char *) ClipHook;  /* point to hook struct */
    ClipIO->io_Length = 0;                /* Remove hook from clipboard */
    ClipIO->io_Command = CBD_CHANGEHOOK;
    (DoIO (clipIO))
```
You must remove the hook or it will continue indefinitely.

 [Caveats For CBD_CHANGEHOOK](devices/3-monitoring-clipboard-changes-caveats-for-cbd-changehook.md) 


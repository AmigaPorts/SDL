---
title: 34 / Keymap Functions / Accessing the Keymap For the Current Console
manual: libraries
chapter: libraries
section: 34-keymap-functions-accessing-the-keymap-for-the-current
functions: []
libraries: []
---

# 34 / Keymap Functions / Accessing the Keymap For the Current Console

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The function AskKeyMap() shown below does not return a pointer to a table
of pointers to currently assigned key mapping. Instead, it copies the
current set of pointers to a user-designated area of memory.  AskKeyMap()
returns a TRUE or FALSE value that says whether or not the function
succeeded.

The function SetKeyMap(), also shown below, copies the designated key map
data structure to the console device.  Thus this routine is complementary
to AskKeymap() in that it can restore an original key mapping as well as
establish a new one.



```c
    Ask/SetKeyMap() functions.
    --------------------------
    These functions assume that you have already opened the console.device
    and that request is a valid IOStdReq structure for the newly opened
    console. These functions are not part of the keymap.library, nor of
    the console.device.  These merely demonstrate [CD_ASKKEYMAP](libraries/34-keymap-library-keymap-functions.md) and
    [CD_SETKEYMAP](libraries/34-keymap-library-keymap-functions.md) which are console.device commands.
```
/* These functions require that you have created a port and an IO request,
 * and have opened the console device as shown in the Console Device
 * chapter of the Devices volume of this manual set.
 */
#include <devices/keymap.h>

BOOL AskKeyMap(struct IOStdReq *request, struct KeyMap *keymap)
{
```c
    request->io_Command = CD_ASKKEYMAP;
    request->io_Length = sizeof(struct KeyMap);
    request->io_Data = (APTR)keymap;  /* where to put it */
    DoIO(request);
    if(request->io_Error) return(FALSE);
    else  return(TRUE); /* if no error, it worked. */
```
}

BOOL SetKeyMap(struct IOStdReq *request,struct KeyMap *keymap)
{
```c
    request->io_Command = CD_SETKEYMAP;
    request->io_Length = sizeof(struct KeyMap);
    request->io_Data = (APTR)keymap;      /* where to get it */
    DoIO(request);
    if(request->io_Error) return(FALSE);
    else  return(TRUE);     /* if no error, it worked. */
```
}


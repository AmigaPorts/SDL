---
title: I-43/Hooks1.c
manual: amiga-mail
chapter: amiga-mail
section: i-43-hooks1-c
functions: [Output]
libraries: [dos.library]
---

# I-43/Hooks1.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* hooks1.c
 * Simple hook example
 * Copyright (C) 1991-1999 Amiga, Inc.
 *
 */

#include <exec/types.h>
#include <exec/libraries.h>
#include <utility/hooks.h>
#include <clib/exec_protos.h>
#include <clib/utility_protos.h>

extern struct Library *SysBase;
struct Library *UtilityBase;

#define ASM     __asm
#define REG(x)  register __ ## x

/* This function converts register-parameter Hook calling
 * convention into standard C conventions.  It requires a C
 * compiler that supports registerized parameters, such as
 * SAS/C 5.xx or greater.
 */
ULONG ASM
hookEntry(REG(a0) struct Hook *h, REG(a2) VOID *o, REG(a1) VOID *msg)
{
```c
    return ((*h->h_SubEntry)(h, o, msg));
```
}

/* This simple function is used to initialize a Hook */
VOID InitHook (struct Hook *h, ULONG (*func)(), VOID *data)
{
```c
    /* Make sure a pointer was passed */
    if (h)
    {
        /* Fill in the Hook fields */
        h->h_Entry = (ULONG (*)()) hookEntry;
        h->h_SubEntry = func;
        h->h_Data = data;
    }
```
}

/* This function only prints out a message to the serial port indicating that
 * we are inside the callback function.  Note that we cannot use printf() or
 * any other functions that use standard I/O with any of the system modules that
 * support callback Hooks, because there is no guarantee that there would
 * be a valid Output() channel. */

ULONG MyFunction (struct Hook *h, VOID *o, VOID *msg)
{
```c
    /* Obtain access to the global data segment */
    geta4();

    /* Debugging function to send a string to the serial port */
    KPrintF("Inside MyFunction()\n");

    return (1);
```
}

int main (int argc, char **argv)
{
```c
    struct Hook h;

    /* Open the utility library */
    if (UtilityBase = OpenLibrary ("utility.library", 36))
    {
        /* Initialize the callback Hook */
        InitHook (&h, MyFunction, NULL);

        /* Use the utility library function to invoke the Hook */
        CallHookPkt (&h, NULL, NULL);

        /* Close utility library now that we're done with it */
        CloseLibrary (UtilityBase);
    }
    else
    {
        /* Display an error message */
        printf ("Couldn't open utility.library\n");
    }
```
}

---

## See Also

- [Output — dos.library](../autodocs/dos.library.md#output)

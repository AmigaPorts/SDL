---
title: Lib_examples/hooks1.c
manual: libraries
chapter: libraries
section: lib-examples-hooks1-c
functions: []
libraries: []
---

# Lib_examples/hooks1.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* hooks1.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfis -j73 hooks1.c
Blink FROM LIB:c.o,hooks1.o TO hooks1 LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
*/


```c
    #include <exec/types.h>
    #include <exec/libraries.h>
    #include <utility/hooks.h>
    #include <dos.h>

    #include <clib/exec_protos.h>
    #include <clib/dos_protos.h>
    #include <clib/utility_protos.h>

    #include <stdio.h>

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
        return ((*(ULONG (*)(struct Hook *,VOID *,VOID *))(h->h_SubEntry))(h, o, msg));
    }

    /* This simple function is used to initialize a Hook */
    VOID InitHook (struct Hook *h, ULONG (*func)(), VOID *data)
    {
        /* Make sure a pointer was passed */
        if (h)
        {
            /* Fill in the Hook fields */
            h->h_Entry = (ULONG (*)()) hookEntry;
            h->h_SubEntry = func;
            h->h_Data = data;
        }
    }

    /* This function only prints out a message indicating that we are
     * inside the callback function.
     */

    ULONG MyFunction (struct Hook *h, VOID *o, VOID *msg)
    {
        /* Obtain access to the global data segment */
        geta4();

        /* Debugging function to send a string to the serial port */
        printf("Inside MyFunction()\n");

        return (1);
    }

    int main (int argc, char **argv)
    {
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
        else printf ("Couldn't open utility.library\n");
    }
```

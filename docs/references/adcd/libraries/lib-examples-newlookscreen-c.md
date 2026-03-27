---
title: lib_examples/newlookscreen.c
manual: libraries
chapter: libraries
section: lib-examples-newlookscreen-c
functions: []
libraries: []
---

# lib_examples/newlookscreen.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* newlookscreen.c
** open a screen with the "new look".
**
** SAS/C 5.10a
** lc -b1 -cfist -v -y newlookscreen
** blink LIB:c.o newlookscreen.o TO newlookscreen LIB LIB:lc.lib LIB:amiga.lib
*/

#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/screens.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *IntuitionBase;

/* Simple routine to demonstrate opening a screen with the new look.
** Simply supply the tag SA_Pens along with a minimal pen specification,
** Intuition will fill in all unspecified values with defaults.
** Since we are not supplying values, all are Intuition defaults.
*/
VOID main(int argc, char **argv)
{
UWORD pens[] = { ~0 };
struct Screen *my_screen;

IntuitionBase = OpenLibrary("intuition.library",0);
if (NULL != IntuitionBase)
```c
    {
    if (IntuitionBase->lib_Version >= 37)
        {
        /* The screen is opened two bitplanes deep so that the
        ** new look will show-up better.
        */
        if (NULL != (my_screen = OpenScreenTags(NULL,
                                     SA_Pens, (ULONG)pens,
                                     SA_Depth, 2,
                                     TAG_DONE)))
            {
            /* screen successfully opened */
            Delay(30L);  /* normally the program would be here */

            CloseScreen(my_screen);
            }
        }
    CloseLibrary(IntuitionBase);
    }
```
}


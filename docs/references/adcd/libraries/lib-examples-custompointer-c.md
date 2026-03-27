---
title: Lib_examples/custompointer.c
manual: libraries
chapter: libraries
section: lib-examples-custompointer-c
functions: []
libraries: []
---

# Lib_examples/custompointer.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* custompointer.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 custompointer.c
Blink FROM LIB:c.o,custompointer.o TO custompointer LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** The program shows how to set the pointer for a window.  In this
** example, the pointer imagery is changed to a stopwatch symbol which
** could be used to indicate a busy period.
**
** custompointer.c - Show the use of a custom busy pointer, as well as
** using a requester to block input to a window.
*/
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <exec/libraries.h>
#include <intuition/intuition.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *IntuitionBase;


UWORD __chip waitPointer[] =


```c
    {
    0x0000, 0x0000,     /* reserved, must be NULL */

    0x0400, 0x07C0,
    0x0000, 0x07C0,
    0x0100, 0x0380,
    0x0000, 0x07E0,
    0x07C0, 0x1FF8,
    0x1FF0, 0x3FEC,
    0x3FF8, 0x7FDE,
    0x3FF8, 0x7FBE,
    0x7FFC, 0xFF7F,
    0x7EFC, 0xFFFF,
    0x7FFC, 0xFFFF,
    0x3FF8, 0x7FFE,
    0x3FF8, 0x7FFE,
    0x1FF0, 0x3FFC,
    0x07C0, 0x1FF8,
    0x0000, 0x07E0,

    0x0000, 0x0000,     /* reserved, must be NULL */
    };
```
/*
** The main() routine
*/
VOID main(int argc, char **argv)
{
struct Window *win;
struct Requester null_request;
extern UWORD __chip waitPointer[];

if (IntuitionBase = OpenLibrary("intuition.library",37))
```c
    {
    /* the window is opened as active (WA_Activate) so that the busy
    ** pointer will be visible.  If the window was not active, the
    ** user would have to activate it to see the change in the pointer.
    */
    if (win = OpenWindowTags(NULL,
                             WA_Activate, TRUE,
                             TAG_END))
        {
        /* a NULL requester can be used to block input
        ** in a window without any imagery provided.
        */
        InitRequester(&null_request);

        Delay(50);  /* simulate activity in the program. */

        /* Put up the requester to block user input in the window,
        ** and set the pointer to the busy pointer.
        */
        if (Request(&null_request, win))
            {
            SetPointer(win, waitPointer, 16, 16, -6, 0);

            Delay(100);  /* simulate activity in the program. */

            /* clear the pointer (which resets the window to the default
            ** pointer) and remove the requester.
            */
            ClearPointer(win);
            EndRequest(&null_request, win);
            }

        Delay(100);  /* simulate activity in the program. */

        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
```
}


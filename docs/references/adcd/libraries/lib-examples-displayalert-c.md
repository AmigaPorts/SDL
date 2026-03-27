---
title: Lib_examples/displayalert.c
manual: libraries
chapter: libraries
section: lib-examples-displayalert-c
functions: []
libraries: []
---

# Lib_examples/displayalert.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* displayalert.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 displayalert.c
Blink FROM LIB:c.o,displayalert.o TO displayalert LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** This program demonstrates an alert.  An explanation of the positioning
** values for the alert strings is in the comment that precedes the
** alertMsg string.
**
** displayalert.c -  This program implements a recoverable alert
*/
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif


/* Each string requires its own positioning information, as explained
** in the manual.  Hex notation has been used to specify the positions of
** the text. Hex numbers start with a backslash, an "x" and the characters
** that make up the number.
**
** Each line needs 2 bytes of X position, and 1 byte of Y position.
**   In our 1st line: x = \x00\xF0 (2 bytes) and y = \x14 (1 byte)
**   In our 2nd line: x = \x00\xA0 (2 bytes) and y = \x24 (1 byte)
** Each line is null terminated plus a continuation character (0=done).
** This example assumes that the complier will concatenate adjacent
** strings into a single string with no extra NULLs.  The compiler does
** add the terminating NULL at the end of the entire string...The entire
** alert must end in TWO NULLs, one for the end of the string, and one
** for the NULL continuation character.
*/

UBYTE *alertMsg =

```c
    "\x00\xF0\x14" "OH NO, NOT AGAIN!" "\x00\x01"
    "\x00\x80\x24" "PRESS MOUSEBUTTON:   LEFT=TRUE   RIGHT=FALSE" "\x00";
```
struct Library *IntuitionBase;

VOID main(int argc, char **argv)
{
if (IntuitionBase = OpenLibrary("intuition.library",33))
```c
    {
    if (DisplayAlert(RECOVERY_ALERT, alertMsg, 52))
        printf("Alert returned TRUE\n");
    else
        printf("Alert returned FALSE\n");

    CloseLibrary(IntuitionBase);
    }
```
}


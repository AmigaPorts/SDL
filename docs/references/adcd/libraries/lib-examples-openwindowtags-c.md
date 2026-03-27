---
title: Lib_examples/openwindowtags.c
manual: libraries
chapter: libraries
section: lib-examples-openwindowtags-c
functions: [OpenWindowTagList]
libraries: [intuition.library]
---

# Lib_examples/openwindowtags.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* openwindowtags.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 openwindowtags.c
Blink FROM LIB:c.o,openwindowtags.o TO openwindowtags LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** Here's an example showing how to open a new window using the
** OpenWindowTagList() function with window attributes set up
** in a TagItem array.
**
** openwindowtags.c - open a window using tags.
*/

#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>
#include <intuition/screens.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

#define MY_WIN_LEFT   (20)
#define MY_WIN_TOP    (10)
#define MY_WIN_WIDTH  (300)
#define MY_WIN_HEIGHT (110)

void handle_window_events(struct Window *);

struct Library *IntuitionBase;

struct TagItem win_tags[] =

```c
    {
    {WA_Left,       MY_WIN_LEFT},
    {WA_Top,        MY_WIN_TOP},
    {WA_Width,      MY_WIN_WIDTH},
    {WA_Height,     MY_WIN_HEIGHT},
    {WA_CloseGadget,TRUE},
    {WA_IDCMP,      IDCMP_CLOSEWINDOW},
    {TAG_DONE, NULL},
    };
```
/*
** Open a simple window using OpenWindowTagList()
*/
VOID main(int argc, char **argv)
{
struct Window *win;

/* these calls are only valid if we have Intuition version 37 or greater */
IntuitionBase = OpenLibrary("intuition.library",37);
if (IntuitionBase!=NULL)
```c
    {
    win = OpenWindowTagList(NULL,win_tags);
    if (win==NULL)
        {
        /* window failed to open */
        }
    else
        {
        /* window successfully opened here */
        handle_window_events(win);

        CloseWindow(win);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
```
}

/* Normally this routine would contain an event loop like the one given
** in the chapter "Intuition Input and Output Methods".  Here we just
** wait for any messages we requested to appear at the Window's port.
*/
VOID handle_window_events(struct Window *win)
{
WaitPort(win->UserPort);
}

---

## See Also

- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)

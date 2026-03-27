---
title: Lib_examples/winpubscreen.c
manual: libraries
chapter: libraries
section: lib-examples-winpubscreen-c
functions: [Wait, WaitPort]
libraries: [exec.library]
---

# Lib_examples/winpubscreen.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* winpubscreen.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 winpubscreen.c
Blink FROM LIB:c.o,winpubscreen.o TO winpubscreen LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** winpubscreen.c
** open a window on the default public screen (usually the Workbench screen)
*/

#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *IntuitionBase;

/* our function prototypes */
VOID handle_window_events(struct Window *win);


/*
** Open a simple window on the default public screen,
** then leave it open until the user selects the close gadget.
*/
VOID main(int argc, char **argv)
{
struct Window *test_window = NULL;
struct Screen *test_screen = NULL;

IntuitionBase = OpenLibrary("intuition.library",37);
if (IntuitionBase)
```c
    {
    /* get a lock on the default public screen */
    if (test_screen = LockPubScreen(NULL))
            {
            /* open the window on the public screen */
            test_window = OpenWindowTags(NULL,
                    WA_Left,  10,    WA_Top,    20,
                    WA_Width, 300,   WA_Height, 100,
                    WA_DragBar,         TRUE,
                    WA_CloseGadget,     TRUE,
                    WA_SmartRefresh,    TRUE,
                    WA_NoCareRefresh,   TRUE,
                    WA_IDCMP,           IDCMP_CLOSEWINDOW,
                    WA_Title,           "Window Title",
                    WA_PubScreen,       test_screen,
                    TAG_END);

            /* Unlock the screen.  The window now acts as a lock on
            ** the screen, and we do not need the screen after the
            ** window has been closed.
            */
            UnlockPubScreen(NULL, test_screen);

            /* if we have a valid window open, run the rest of the
            ** program, then clean up when done.
            */
            if (test_window)
                {
                handle_window_events(test_window);
                CloseWindow(test_window);
                }
            }
    CloseLibrary(IntuitionBase);
    }
```
}

/*
** Wait for the user to select the close gadget.
*/
VOID handle_window_events(struct Window *win)
{
struct IntuiMessage *msg;
BOOL done = FALSE;

while (! done)
```c
    {
    /* We have no other ports of signals to wait on,
    ** so we'll just use WaitPort() instead of Wait()
    */
    WaitPort(win->UserPort);

    while ( (! done) &&
            (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        /* use a switch statement if looking for multiple event types */
        if (msg->Class == IDCMP_CLOSEWINDOW)
            done = TRUE;

        ReplyMsg((struct Message *)msg);
        }
    }
```
}

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)

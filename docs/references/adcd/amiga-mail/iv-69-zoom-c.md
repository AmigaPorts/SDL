---
title: IV-69/zoom.c
manual: amiga-mail
chapter: amiga-mail
section: iv-69-zoom-c
functions: []
libraries: []
---

# IV-69/zoom.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Zoom.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 Zoom.c
slink FROM LIB:c.o,Zoom.o TO Zoom LIBRARY LIB:sc.lib,LIB:amiga.lib
quit
*/
/*
Copyright (c) 1991-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/

#include <intuition/intuition.h>
#include <intuition/screens.h>

#ifdef LATTICE
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
/* disable SAS/C CTRL-C handing */

int             CXBRK(void)
{
```c
    return (0);
```
}

int             chkabort(void)
{
```c
    return (0);
```
}
#endif

struct IntuitionBase *IntuitionBase;

LONG            main(void);

LONG main(void)
{
```c
    struct IBox     ibox;    /* The structure we'll use to specify the zoom'ed
                              * dimension. */
    struct Screen  *wbscreen;
    struct Window  *window;
    struct Message *msg;     /* Make this an IntuiMessage when you want to use
                              * it */


    if (IntuitionBase = OpenLibrary("intuition.library", 37))
    {

        /* Lock workbench screen so we can watch it closely */
        if (wbscreen = LockPubScreen("Workbench"))
        {

            /*
             * Generate a nice position for the zoom'ed window. Note that this
             * specifies the INITIAL position of the window. Since we don't
             * have a size gadget, the user can't change the height and width,
             * but the offset is changed as the window is dragged.
             */
            ibox.Left = wbscreen->Width - 180;   /* far right corner */
            ibox.Top = wbscreen->BarHeight + 1;  /* Just below screen bar */
            ibox.Width = 180;
            /* ght of the window topborder */
            ibox.Height = wbscreen->WBorTop + wbscreen->Font->ta_YSize + 1;

            /* open a window with tags */
            if (window = OpenWindowTags(NULL,    /* no NewWindow structure,
                                                  * tags only */
                                        WA_Left, 0,     /* Open at far left
                                                         * corner */
                                        WA_Top, wbscreen->BarHeight + 1,
                                        WA_Width, 200,
                                        WA_Height, 100,
                                        WA_Title, (LONG) "A simple window",
                WA_Flags, WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                     WFLG_ACTIVATE | WFLG_SIMPLE_REFRESH | WFLG_NOCAREREFRESH,

                                        /* Only interested in closewindow      */
                                        WA_IDCMP, IDCMP_CLOSEWINDOW,

                                        /* pass the alternate zoom dimension   */
                                        WA_Zoom, (LONG) & ibox,

                                        TAG_DONE))
            {

                /* And just wait for windowclose */
                WaitPort(window->UserPort);
                /* clear the message port */
                while (msg = GetMsg(window->UserPort))
                    ReplyMsg(msg);

                CloseWindow(window);
            }
            UnlockPubScreen(NULL, wbscreen);
        }
        CloseLibrary(IntuitionBase);
    }
```
}


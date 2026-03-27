---
title: IV-69/hide.c
manual: amiga-mail
chapter: amiga-mail
section: iv-69-hide-c
functions: [CreateMsgPort, TextExtent]
libraries: [exec.library, graphics.library]
---

# IV-69/hide.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Hide.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 Hide.c
slink FROM LIB:c.o,Hide.o TO Hide LIBRARY LIB:sc.lib,LIB:amiga.lib
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
#include <graphics/text.h>
#include <libraries/gadtools.h>
#include <workbench/startup.h>
#include <workbench/workbench.h>
#include "hide.h"

#ifdef LATTICE
#include <clib/alib_protos.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/graphics_protos.h>
#include <clib/wb_protos.h>

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
struct GfxBase *GfxBase;
struct WorkbenchBase *WorkbenchBase;
struct Library *GadToolsBase;

LONG            main(void);

LONG
main(void)
{
```c
    struct Window  *window;
    struct IntuiMessage *imsg;
    struct Gadget  *gadgetcontext;
    struct Gadget  *gadget, *hidegadget;
    struct MsgPort *appport;
    struct NewGadget ng;
    struct TextExtent textextent;
    struct AppIcon *appicon = NULL;
    struct AppMessage *appmsg;
    UWORD           left, top;
    void           *visualinfo;
    ULONG           signal, windowsignal, waitmask;
    BOOL            ABORT = FALSE;
    BOOL            CONTINUE, ICONIFY;

    if (IntuitionBase = OpenLibrary("intuition.library", 37))
    {
        /* Open GfxBase to use TextExtent() so we can handle proportional fonts */
        if (GfxBase = OpenLibrary("graphics.library", 37))
        {
            /* Open gadtools for that lonely gadget */
            if (GadToolsBase = OpenLibrary("gadtools.library", 37))
            {
                if (WorkbenchBase = OpenLibrary("workbench.library", 37))
                {
                    /* Message to receive appmessage on */
                    if (appport = CreateMsgPort())
                    {
                        /* open a window with tags */
                        left = top = 50;
                        do
                        {
                            /* no NewWindow structure, tags only */
                            if (window = OpenWindowTags(NULL,
                                         /* Open at far left corner */
                                         WA_Left, left,
                                         WA_Top, top,
                                         WA_Width, 150,
                                         WA_Height, 80,
                                         WA_Title, (LONG) "hide",
                                         WA_Flags, WFLG_DRAGBAR |
                                             WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                                             WFLG_ACTIVATE | WFLG_SMART_REFRESH |
                                             WFLG_NOCAREREFRESH,
                                         WA_IDCMP,
                                             IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
                                         TAG_DONE))
                            {
                                windowsignal = 1L << window->UserPort->mp_SigBit;
                                /*
                                 * Get the visual info gadtools needs for the
                                 * screen we opened on
                                 */
                                if (visualinfo = GetVisualInfoA(window->WScreen, NULL))
                                {

                                    /*
                                     * Create a simple gadtools button and sort
                                     * of lay it out
                                     */
                                    if (gadget = CreateContext(&gadgetcontext))
                                    {

                                        /*
                                         * Use TextExtent to handle
                                         * proportional fonts
                                         */
                                        TextExtent(&(window->WScreen->RastPort),
                                                   "Hide", 4, &textextent);
                                        ng.ng_Width = textextent.te_Width + 8;
                                        ng.ng_LeftEdge = (window->Width / 2)
                                                              - (ng.ng_Width / 2);
                                        ng.ng_Height = textextent.te_Height + 4;
                                        ng.ng_TopEdge = (
                                            (window->Height - window->BorderTop
                                                - window->BorderBottom) / 2)
                                            + (ng.ng_Height / 2);
                                        ng.ng_TextAttr = window->WScreen->Font;
                                        ng.ng_GadgetText = "Hide";
                                        ng.ng_VisualInfo = visualinfo;
                                        ng.ng_GadgetID = 1;
                                        ng.ng_Flags = PLACETEXT_IN;
                                        hidegadget = gadget =
                                            CreateGadget(BUTTON_KIND, gadget,
                                                         &ng, TAG_END);
                                        AddGList(window, gadget, -1, -1, NULL);
                                        RefreshGList(gadget, window, NULL, -1);
                                        GT_RefreshWindow(window, NULL);

                                        CONTINUE = TRUE;
                                        waitmask = windowsignal|
                                                       1L << appport->mp_SigBit;
                                        do
                                        {
                                            signal = Wait(waitmask);

                                          if (signal & windowsignal)
                                            {
                                                while (imsg = (struct IntuiMessage *)
                                                    GetMsg(window->UserPort))
                                                {
                                                    if (imsg->Class ==
                                                            IDCMP_CLOSEWINDOW)
                                                    {
                                                        ABORT = TRUE;
                                                        CONTINUE = FALSE;
                                                        ICONIFY = FALSE;
                                                    }
                                                    else
                                                    if (imsg->Class == IDCMP_GADGETUP)
                                                        ICONIFY = TRUE;
                                                    ReplyMsg((struct Message *) imsg);
                                                }
                                            }
                                            if (signal & (1L << appport->mp_SigBit))
                                            {
                                                while (appmsg = (struct AppMessage *)
                                                    GetMsg(appport))
                                                {

                                                    /*
                                                     * If am->NumArgs is zero
                                                     * the user double-clicked
                                                     * on our icon, otherwise
                                                     * one or more icons were
                                                     * dropped on top of it.
                                                     */
                                                    if (appmsg->am_NumArgs == 0)
                                                    {
                                                        RemoveAppIcon(appicon);
                                                        CONTINUE = FALSE;
                                                    }
                                                    ReplyMsg(
                                                        (struct Message *) appmsg);
                                                }
                                            }
                                            if (ICONIFY)
                                            {

                                                /*
                                                 * Add appicon, close window if
                                                 * succesful
                                                 */
                                                appicon = AddAppIcon(1, NULL, "Hide",
                                                    appport, NULL, &AppIconDObj, NULL);
                                                if (appicon == NULL)
                                                {
                                                    DisplayBeep(window->WScreen);
                                                }
                                                else
                                                {
                                                    RemoveGadget(window, hidegadget);
                                                    left = window->LeftEdge;
                                                    top = window->TopEdge;
                                                    CloseWindow(window);
                                                    window = NULL;
                                                    /* there is no window
                                                     * message port anymore */
                                                    waitmask =
                                                        1L << appport->mp_SigBit;
                                                }
                                                ICONIFY = FALSE;
                                            }
                                        } while (CONTINUE == TRUE);
                                        if (window)
                                            RemoveGadget(window, hidegadget);
                                        FreeGadgets(gadgetcontext);
                                    }
                                    FreeVisualInfo(visualinfo);
                                }


                                if (window)
                                {
                                    left = window->LeftEdge;
                                    top = window->TopEdge;
                                    CloseWindow(window);
                                }
                            }
                        } while (ABORT == FALSE);
                        DeleteMsgPort(appport);
                    }
                    CloseLibrary(WorkbenchBase);
                }
                CloseLibrary(GadToolsBase);
            }
            CloseLibrary(GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
    return (0);
```
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)

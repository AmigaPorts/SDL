---
title: IV-69/jumpy.c
manual: amiga-mail
chapter: amiga-mail
section: iv-69-jumpy-c
functions: [TextExtent]
libraries: [graphics.library]
---

# IV-69/jumpy.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Jumpy.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 Jumpy.c
slink FROM LIB:c.o,Jumpy.o TO Jumpy LIBRARY LIB:sc.lib,LIB:amiga.lib
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

#ifdef LATTICE
#include <string.h>
#include <clib/alib_protos.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/graphics_protos.h>
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
struct Library *GadToolsBase;
struct Library *IconBase;
struct Library *CxBase;

LONG            main(LONG, UBYTE **);

LONG
main(LONG argc, UBYTE ** argv)
{
```c
    struct Window       *window;
    struct IntuiMessage *imsg;
    struct Gadget       *gadgetcontext;
    struct Gadget       *gadget, *nextscreengadget;
    struct NewGadget     ng;
    struct TextExtent    textextent;
    UWORD                left, top;
    void                *visualinfo;
    UBYTE               *startupname;
    UBYTE                namebuffer[MAXPUBSCREENNAME];
    UBYTE              **tooltypes;
    BOOL                 ABORT = FALSE;

    if (IntuitionBase = OpenLibrary("intuition.library", 37))
    {
        /* Open GfxBase to use TextExtent() so we can handle proportional fonts */
        if (GfxBase = OpenLibrary("graphics.library", 37))
        {
            if (GadToolsBase = OpenLibrary("gadtools.library", 37))
            {

                /*
                 * Open commodities & icon.library so we can use ArgArray
                 * functions
                 */
                if (CxBase = OpenLibrary("commodities.library", 37))
                {
                    if (IconBase = OpenLibrary("icon.library", 37))
                    {
                        left = 50;
                        top = 50;                /* Initial offset */
                        /* Note that these are functions in amiga.lib */
                        if (tooltypes = ArgArrayInit(argc, argv))
                        {
                            startupname =
                                ArgString(tooltypes, "PUBSCREEN", "Workbench");
                            strcpy(namebuffer, startupname);
                            ArgArrayDone();
                        }
                        else
                            strcpy(namebuffer, "Workbench");
                        do
                        {
                            /* open a window with tags */
                            /* no NewWindow structure, tags only */
                            if (window = OpenWindowTags(NULL,
                                        /* Open at far left corner */
                                        WA_Left,  left,
                                        WA_Top,   top,
                                        WA_Width, 150,
                                        WA_Height, 80,
                                        WA_Title, (LONG) "jumpy",
                                        WA_PubScreenName, (LONG) namebuffer,
                                        /* if no pubscreen with this name exists... */
                                        WA_PubScreenFallBack, TRUE,
                                        /* ...fall back on default pubscreen */
                                        WA_Flags, WFLG_DRAGBAR | WFLG_DEPTHGADGET |
                                            WFLG_CLOSEGADGET | WFLG_ACTIVATE |
                                            WFLG_SMART_REFRESH | WFLG_NOCAREREFRESH,
                                        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
                                        TAG_DONE))
                            {

                                /*
                                 * Get the visual info gadtools needs for the
                                 * screen we opened on
                                 */
                                if (visualinfo = GetVisualInfoA(window->WScreen, NULL))
                                {

                                    /*
                                     * Create a simple gadtools button and sort
                                     * of lay it out. Note this doesn't do any
                                     * checking for legal (window) dimensions.
                                     */
                                    if (gadget = CreateContext(&gadgetcontext))
                                    {

                                        /*
                                         * Use TextExtent to handle
                                         * proportional fonts
                                         */
                                        TextExtent(&(window->WScreen->RastPort),
                                                   "Jump", 4, &textextent);
                                        ng.ng_Width = textextent.te_Width + 8;
                                        ng.ng_LeftEdge = (window->Width / 2) -
                                                          (ng.ng_Width / 2);
                                        ng.ng_Height = textextent.te_Height + 4;
                                        ng.ng_TopEdge = (
                                            (window->Height - window->BorderTop -
                                                window->BorderBottom) / 2) +
                                            (ng.ng_Height / 2);
                                        ng.ng_TextAttr = window->WScreen->Font;
                                        ng.ng_GadgetText = "Jump";
                                        ng.ng_VisualInfo = visualinfo;
                                        ng.ng_GadgetID = 1;
                                        ng.ng_Flags = PLACETEXT_IN;
                                        nextscreengadget = gadget =
                                            CreateGadget(BUTTON_KIND, gadget, &ng,
                                                         TAG_END);
                                        AddGList(window, gadget, -1, -1, NULL);
                                        RefreshGList(gadget, window, NULL, -1);
                                        GT_RefreshWindow(window, NULL);

                                        WaitPort(window->UserPort);
                                        while (imsg = (struct IntuiMessage *)
                                            GetMsg(window->UserPort))
                                        {
                                            if (imsg->Class == IDCMP_CLOSEWINDOW)
                                                ABORT = TRUE;
                                            else if (imsg->Class = IDCMP_GADGETUP)
                                                NextPubScreen(window->WScreen,
                                                              namebuffer);
                                            ReplyMsg((struct Message *) imsg);
                                        }
                                        RemoveGadget(window, nextscreengadget);
                                        FreeGadgets(gadgetcontext);
                                    }
                                    FreeVisualInfo(visualinfo);
                                }
                                left = window->LeftEdge;
                                top = window->TopEdge;
                                CloseWindow(window);
                            }
                        } while (ABORT == FALSE);

                        CloseLibrary(IconBase);
                    }
                    CloseLibrary(CxBase);
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

- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)

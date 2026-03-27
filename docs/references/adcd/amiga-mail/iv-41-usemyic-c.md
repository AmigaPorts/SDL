---
title: IV-41/usemyIC.c
manual: amiga-mail
chapter: amiga-mail
section: iv-41-usemyic-c
functions: []
libraries: []
---

# IV-41/usemyIC.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
 *
 * Compiled with SAS/C 6.56 NMINC STRMERGE OPTSIZE OPTIMIZE OPTGLOBAL NOSTKCHK
 * (must be linked with mytextlabelclass.o, classface.o and hookface.o)
 *
 * Written by David N. Junod
 */

#include <exec/types.h>
#include <exec/libraries.h>
#include <intuition/intuition.h>
#include <intuition/classes.h>
#include <intuition/classusr.h>
#include <intuition/cghooks.h>
#include <intuition/gadgetclass.h>
#include <intuition/imageclass.h>
#include <graphics/gfx.h>
#include <graphics/gfxmacros.h>
#include <libraries/gadtools.h>
#include <utility/tagitem.h>
#include <clib/macros.h>
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>
#include <clib/graphics_protos.h>
#include <clib/utility_protos.h>
#include <string.h>

extern struct Library *SysBase, *DOSBase;
struct Library *IntuitionBase, *GfxBase, *UtilityBase;

Class          *initmyTextLabelClass(VOID);
ULONG           freemyTextLabelClass(Class * cl);

VOID
main(VOID)
{
```c
    Class          *cl;
    struct Image   *im;
    struct Window  *win;
    struct RastPort *rp;
    UWORD           top, left, height;

    /* Make sure we're at least using Version 2.0 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36))
    {
        GfxBase = OpenLibrary("graphics.library", 36);
        UtilityBase = OpenLibrary("utility.library", 36);

        /* Open a window, without system gadgets or IDCMP events */
        if (win = OpenWindowTags(NULL,
                                 WA_Left, 10,
                                 WA_Top, 10,
                                 WA_Width, 320,
                                 WA_Height, 100,
                                 TAG_DONE))
        {
            /* Cache the pointer to the RastPort */
            rp = win->RPort;

            /* Cache the upper-left coordinates of the window */
            top = win->BorderTop + INTERHEIGHT;
            left = win->BorderRight + INTERWIDTH;

            /* Cache the height of the font */
            height = rp->TxHeight + INTERHEIGHT;

            /* Initialize the custom image class. */
            if (cl = initmyTextLabelClass())
            {
                /* Create a new image structure, using the given string. */
                if (im = NewObject(cl, NULL,
                                   IA_Data, (ULONG) "Line _1",
                                   TAG_DONE))
                {
                    /* Paint using the provided text string. */
                    DrawImageState(rp, im, left, top,
                                   IDS_NORMAL, NULL);

                    /* Replace the text string, and paint it. */
                    im->ImageData = (USHORT *) "Line _2";
                    DrawImageState(rp, im, left, top + height,
                                   IDS_NORMAL, NULL);

                    /* Replace the text string, and paint it. */
                    im->ImageData = (USHORT *) "Line _3";
                    DrawImageState(rp, im, left, top + (height * 2),
                                   IDS_NORMAL, NULL);

                    /* Free the image. */
                    DisposeObject(im);
                }

                /* Free the image class. */
                freemyTextLabelClass(cl);
            }

            Delay(250);
            CloseWindow(win);
        }

        CloseLibrary(UtilityBase);
        CloseLibrary(GfxBase);
        CloseLibrary(IntuitionBase);
    }
```
}


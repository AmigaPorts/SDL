---
title: Lib_examples/simplegad.c
manual: libraries
chapter: libraries
section: lib-examples-simplegad-c
functions: []
libraries: []
---

# Lib_examples/simplegad.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* simplegad.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 simplegad.c
Blink FROM LIB:c.o,simplegad.o TO simplegad LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** The example below demonstrates a simple application gadget.  The
** program declares a Gadget structure set up as a boolean gadget with
** complement mode highlighting.  The gadget is attached to the window
** when it is opened by using the WA_Gadgets tag in the OpenWindowTags()
** call.
**
** simplegad.c - show the use of a button gadget.
*/

#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *IntuitionBase;

#define BUTTON_GAD_NUM   (3)
#define MYBUTTONGADWIDTH (100)
#define MYBUTTONGADHEIGHT (50)

/* NOTE that the use of constant size and positioning values are
** not recommended; it just makes it easy to show what is going on.
** The position of the gadget should be dynamically adjusted depending
** on the height of the font in the title bar of the window.
*/

UWORD buttonBorderData[] =

```c
    {
    0,0, MYBUTTONGADWIDTH + 1,0, MYBUTTONGADWIDTH + 1,MYBUTTONGADHEIGHT + 1,
    0,MYBUTTONGADHEIGHT + 1, 0,0,
    };
```
struct Border buttonBorder =

```c
    {
    -1,-1,1,0,JAM1,5,buttonBorderData,NULL,
    };
```
struct Gadget buttonGad =

```c
    {
    NULL, 20,20, MYBUTTONGADWIDTH,MYBUTTONGADHEIGHT,
    GFLG_GADGHCOMP, GACT_RELVERIFY | GACT_IMMEDIATE,
    GTYP_BOOLGADGET, &buttonBorder, NULL, NULL,0,NULL,BUTTON_GAD_NUM,NULL,
    };
```
/*
** routine to show the use of a button (boolean) gadget.
*/
VOID main(int argc, char **argv)
{
struct Window *win;
struct IntuiMessage *msg;
struct Gadget *gad;
ULONG  class;
BOOL done;

/* make sure to get intuition version 37, for OpenWindowTags() */
IntuitionBase = OpenLibrary("intuition.library", 37);
if (IntuitionBase)
```c
    {
    if (win = OpenWindowTags(NULL,
                            WA_Width, 400,
                            WA_Height, 100,
                            WA_Gadgets, &buttonGad,
                            WA_Activate, TRUE,
                            WA_CloseGadget, TRUE,
                            WA_IDCMP, IDCMP_GADGETDOWN | IDCMP_GADGETUP |
                                      IDCMP_CLOSEWINDOW,
                            TAG_END))
        {
        done = FALSE;
        while (done == FALSE)
            {
            Wait(1L << win->UserPort->mp_SigBit);
            while ( (done == FALSE) &&
                    (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
                {
                /* Stash message contents and reply, important when message
                ** triggers some lengthy processing
                */
                class = msg->Class;

                /* gadget address is ONLY valid for gadget messages! */
                if ((class == IDCMP_GADGETUP) || (class == IDCMP_GADGETDOWN))
                    gad = (struct Gadget *)(msg->IAddress);

                ReplyMsg((struct Message *)msg);

                /* switch on the type of the event */
                switch (class)
                    {
                    case IDCMP_GADGETUP:
                        /* caused by GACT_RELVERIFY */
                        printf("received an IDCMP_GADGETUP, gadget number %d\n",
                               gad->GadgetID);
                        break;
                    case IDCMP_GADGETDOWN:
                        /* caused by GACT_IMMEDIATE */
                        printf("received an IDCMP_GADGETDOWN, gadget number %d\n",
                               gad->GadgetID);
                        break;
                    case IDCMP_CLOSEWINDOW:
                        /* set a flag that we are done processing events... */
                        printf("received an IDCMP_CLOSEWINDOW\n");
                        done = TRUE;
                        break;
                    }
                }
            }
        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
```
}


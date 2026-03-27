---
title: Lib_examples/UserCopperExample.c
manual: libraries
chapter: libraries
section: lib-examples-usercopperexample-c
functions: [Forbid, Permit, RemakeDisplay, RethinkDisplay]
libraries: [exec.library, intuition.library]
---

# Lib_examples/UserCopperExample.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*  The example program below shows the use of user Copper lists
    under Intuition.

    UserCopperExample.c
    User Copper List Example
    For SAS/C 5.10a,
    compile with:  LC -b1 -cfist -L -v -y UserCopperExample.c
    link with lc.lib and amiga.lib
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <graphics/gfxbase.h>
#include <graphics/gfxmacros.h>
#include <graphics/copper.h>
#include <graphics/videocontrol.h>
#include <intuition/intuition.h>
#include <intuition/preferences.h>
#include <hardware/custom.h>
#include <libraries/dos.h>

#include <clib/exec_protos.h>           /*  Prototypes.  */
#include <clib/graphics_protos.h>
#include <clib/intuition_protos.h>
#include <clib/dos_protos.h>

#include <stdlib.h>

/*  Use this structure to gain access to the custom registers.  */
extern struct Custom far custom;

/*  Global variables.  */
struct GfxBase        *GfxBase = NULL;
struct IntuitionBase  *IntuitionBase = NULL;
struct Screen         *screen = NULL;
struct Window         *window = NULL;

VOID main( VOID ), cleanExit( WORD );
WORD openAll( VOID ), loadCopper( VOID );


/*
 *   The main() routine -- just calls subroutines
 */
VOID main( VOID )
{
WORD ret_val;
struct IntuiMessage     *intuiMessage;

```c
        /*  Open the libraries, a screen and a window.  */
        ret_val = openAll();
        if (RETURN_OK == ret_val)
        {
                /*  Create and attach the user Copper list.  */
                ret_val = loadCopper();
                if (RETURN_OK == ret_val)
                {
                        /*  Wait until the user clicks in the close gadget.  */
                        (VOID) Wait(1<<window->UserPort->mp_SigBit);

                        while (intuiMessage = (struct IntuiMessage *)GetMsg(window->UserPort))
                                ReplyMsg((struct Message *)intuiMessage);
                }
        }
        cleanExit(ret_val);
```
}


/*
 * openAll() -- opens the libraries, screen and window
 */
WORD openAll( VOID )
{
#define MY_WA_WIDTH 270 /*  Width of window.  */

```c
        WORD ret_val = RETURN_OK;

        /*  Prepare to explicitly request Topaz 60 as the screen font.  */
        struct TextAttr topaz60 =
        {
                (STRPTR)"topaz.font",
                (UWORD)TOPAZ_SIXTY, (UBYTE)0, (UBYTE)0
        };

        GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 37L);
        if (GfxBase == NULL)
                ret_val = ERROR_INVALID_RESIDENT_LIBRARY;
        else
        {
                IntuitionBase = (struct IntuitionBase *)
                        OpenLibrary("intuition.library", 37L);

                if (IntuitionBase == NULL)
                        ret_val = ERROR_INVALID_RESIDENT_LIBRARY;
                else
                {
                        screen = OpenScreenTags( NULL,
                                 SA_Overscan, OSCAN_STANDARD,
                                 SA_Title,    "User Copper List Example",
                                 SA_Font,     (ULONG)&topaz60,
                                 TAG_DONE);

                        if (NULL == screen)
                                ret_val = ERROR_NO_FREE_STORE;
                        else
                        {
                                window = OpenWindowTags( NULL,
                                         WA_CustomScreen, screen,
                                         WA_Title,        "<- Click here to quit.",
                                         WA_IDCMP,        CLOSEWINDOW,
                                         WA_Flags,        WINDOWDRAG|WINDOWCLOSE|INACTIVEWINDOW,
                                         WA_Left,         (screen->Width-MY_WA_WIDTH)/2,
                                         WA_Top,          screen->Height/2,
                                         WA_Height,       screen->Font->ta_YSize + 3,
                                         WA_Width,        MY_WA_WIDTH,
                                         TAG_DONE);

                                if (NULL == window)
                                        ret_val = ERROR_NO_FREE_STORE;
                        }
                }
        }

        return(ret_val);
```
}


/*
 * loadCopper() -- creates a Copper list program and adds it to the system
 */
WORD loadCopper( VOID )
{
register USHORT   i, scanlines_per_color;
```c
         WORD     ret_val    = RETURN_OK;
```
struct   ViewPort *viewPort;
struct   UCopList *uCopList  = NULL;
struct   TagItem  uCopTags[] =

```c
          {
                { VTAG_USERCLIP_SET, NULL },
                { VTAG_END_CM, NULL }
          };
```
UWORD    spectrum[] =

```c
          {
                0x0604, 0x0605, 0x0606, 0x0607, 0x0617, 0x0618, 0x0619,
                0x0629, 0x072a, 0x073b, 0x074b, 0x074c, 0x075d, 0x076e,
                0x077e, 0x088f, 0x07af, 0x06cf, 0x05ff, 0x04fb, 0x04f7,
                0x03f3, 0x07f2, 0x0bf1, 0x0ff0, 0x0fc0, 0x0ea0, 0x0e80,
                0x0e60, 0x0d40, 0x0d20, 0x0d00
          };
```
#define NUMCOLORS 32

```c
        /*  Allocate memory for the Copper list.  */
        /*  Make certain that the initial memory is cleared.  */
        uCopList = (struct UCopList *)
                AllocMem(sizeof(struct UCopList), MEMF_PUBLIC|MEMF_CLEAR);

        if (NULL == uCopList)
                ret_val = ERROR_NO_FREE_STORE;
        else
        {
                /*  Initialize the Copper list buffer.  */
                CINIT(uCopList, NUMCOLORS);

                scanlines_per_color = screen->Height/NUMCOLORS;

                /*  Load in each color.  */
                for (i=0; i<NUMCOLORS; i++)
                        {
                        CWAIT(uCopList, (i*scanlines_per_color), 0);
                        CMOVE(uCopList, custom.color[0], spectrum[i]);
                        }

                CEND(uCopList); /*  End the Copper list  */

                viewPort = ViewPortAddress(window);     /*  Get a pointer to the ViewPort.  */
                Forbid();       /*  Forbid task switching while changing the Copper list.  */
                viewPort->UCopIns=uCopList;
                Permit();       /*  Permit task switching again.  */

                /*  Enable user copper list clipping for this ViewPort.  */
                (VOID) VideoControl( viewPort->ColorMap, uCopTags );

                RethinkDisplay();       /*  Display the new Copper list.  */

                return(ret_val);
        }
```
}


/*
 *  cleanExit() -- returns all resources that were used.
 */
VOID cleanExit( WORD retval )
{
struct ViewPort *viewPort;

if (NULL != IntuitionBase)
{
```c
        if (NULL != screen)
        {
                if (NULL != window)
                {
                        viewPort = ViewPortAddress(window);
                        if (NULL != viewPort->UCopIns)
                        {
                                /*  Free the memory allocated for the Copper.  */
                                FreeVPortCopLists(viewPort);
                                RemakeDisplay();
                        }
                        CloseWindow(window);
                }
                CloseScreen(screen);
        }
        CloseLibrary((struct Library *)IntuitionBase);
```
}

if (NULL != GfxBase)

```c
        CloseLibrary((struct Library *)GfxBase);
```
exit((int)retval);
}

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)

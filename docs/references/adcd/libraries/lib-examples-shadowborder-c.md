---
title: Lib_examples/shadowborder.c
manual: libraries
chapter: libraries
section: lib-examples-shadowborder-c
functions: []
libraries: []
---

# Lib_examples/shadowborder.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* shadowborder.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 shadowborder.c
Blink FROM LIB:c.o,shadowborder.o TO shadowborder LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** The following example draws a double border using two pens to create a
** shadow effect.  The border is drawn in two positions to show the
** flexibility in positioning borders, note that it could also be attached
** to a menu, gadget or requester.
**
** shadowborder.c - program to show the use of an Intuition Border.
*/
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *IntuitionBase = NULL;

#define MYBORDER_LEFT   (0)
#define MYBORDER_TOP    (0)

/* This is the border data. */
WORD myBorderData[] =


```c
    {
    0,0, 50,0, 50,30, 0,30, 0,0,
    };
```
/*
** main routine. Open required library and window and draw the images.
** This routine opens a very simple window with no IDCMP.  See the
** chapters on "Windows" and "Input and Output Methods" for more info.
** Free all resources when done.
*/
VOID main(int argc, char **argv)
{
struct Screen   *screen;
struct DrawInfo *drawinfo;
struct Window   *win;
struct Border    shineBorder;
struct Border    shadowBorder;

ULONG mySHADOWPEN = 1;  /* set default values for pens */
ULONG mySHINEPEN  = 2;  /* in case can't get info...   */

IntuitionBase = OpenLibrary("intuition.library",37);
if (IntuitionBase)
```c
    {
    if (screen = LockPubScreen(NULL))
        {
        if (drawinfo = GetScreenDrawInfo(screen))
            {
            /* Get a copy of the correct pens for the screen.
            ** This is very important in case the user or the
            ** application has the pens set in a unusual way.
            */
            mySHADOWPEN = drawinfo->dri_Pens[SHADOWPEN];
            mySHINEPEN  = drawinfo->dri_Pens[SHINEPEN];

            FreeScreenDrawInfo(screen,drawinfo);
            }
        UnlockPubScreen(NULL,screen);
        }

    /* open a simple window on the workbench screen for displaying
    ** a border.  An application would probably never use such a
    ** window, but it is useful for demonstrating graphics...
    */
    if (win = OpenWindowTags(NULL,
                        WA_PubScreen,  screen,
                        WA_RMBTrap,      TRUE,
                        TAG_END))
        {
        /* set information specific to the shadow component of the border */
        shadowBorder.LeftEdge   = MYBORDER_LEFT + 1;
        shadowBorder.TopEdge    = MYBORDER_TOP + 1;
        shadowBorder.FrontPen   = mySHADOWPEN;
        shadowBorder.NextBorder = &shineBorder;

        /* set information specific to the shine component of the border */
        shineBorder.LeftEdge    = MYBORDER_LEFT;
        shineBorder.TopEdge     = MYBORDER_TOP;
        shineBorder.FrontPen    = mySHINEPEN;
        shineBorder.NextBorder  = NULL;

        /* the following attributes are the same for both borders. */
        shadowBorder.BackPen    = shineBorder.BackPen   = 0;
        shadowBorder.DrawMode   = shineBorder.DrawMode  = JAM1;
        shadowBorder.Count      = shineBorder.Count     = 5;
        shadowBorder.XY         = shineBorder.XY        = myBorderData;

        /* Draw the border at 10,10 */
        DrawBorder(win->RPort,&shadowBorder,10,10);

        /* Draw the border again at 100,10 */
        DrawBorder(win->RPort,&shadowBorder,100,10);

        /* Wait a bit, then quit.
        ** In a real application, this would be an event loop, like the
        ** one described in the Intuition Input and Output Methods chapter.
        */
        Delay(200);

        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
```
}


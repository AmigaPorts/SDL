---
title: Lib_examples/intuitext.c
manual: libraries
chapter: libraries
section: lib-examples-intuitext-c
functions: []
libraries: []
---

# Lib_examples/intuitext.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* intuitext.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 intuitext.c
Blink FROM LIB:c.o,intuitext.o TO intuitext LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

** intuitext.c - program to show the use of an Intuition IntuiText object.
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

#define MYTEXT_LEFT (0)
#define MYTEXT_TOP  (0)

/*
** main routine. Open required library and window and draw the images.
** This routine opens a very simple window with no IDCMP.  See the
** chapters on "Windows" and "Input and Output Methods" for more info.
** Free all resources when done.
*/
VOID main(int argc, char **argv)
{
struct Screen    *screen;
struct DrawInfo  *drawinfo;
struct Window    *win;
struct IntuiText  myIText;
struct TextAttr   myTextAttr;

ULONG myTEXTPEN;
ULONG myBACKGROUNDPEN;

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
            myTEXTPEN = drawinfo->dri_Pens[TEXTPEN];
            myBACKGROUNDPEN  = drawinfo->dri_Pens[BACKGROUNDPEN];

            /* create a TextAttr that matches the specified font. */
            myTextAttr.ta_Name  = drawinfo->dri_Font->tf_Message.mn_Node.ln_Name;
            myTextAttr.ta_YSize = drawinfo->dri_Font->tf_YSize;
            myTextAttr.ta_Style = drawinfo->dri_Font->tf_Style;
            myTextAttr.ta_Flags = drawinfo->dri_Font->tf_Flags;

            /* open a simple window on the workbench screen for displaying
            ** a text string.  An application would probably never use such a
            ** window, but it is useful for demonstrating graphics...
            */
            if (win = OpenWindowTags(NULL,
                                WA_PubScreen,    screen,
                                WA_RMBTrap,      TRUE,
                                TAG_END))
                {
                myIText.FrontPen    = myTEXTPEN;
                myIText.BackPen     = myBACKGROUNDPEN;
                myIText.DrawMode    = JAM2;
                myIText.LeftEdge    = MYTEXT_LEFT;
                myIText.TopEdge     = MYTEXT_TOP;
                myIText.ITextFont   = &myTextAttr;
                myIText.IText       = "Hello, World.  ;-)";
                myIText.NextText    = NULL;

                /* Draw the text string at 10,10 */
                PrintIText(win->RPort,&myIText,10,10);

                /* Wait a bit, then quit.
                ** In a real application, this would be an event loop,
                ** like the one described in the Intuition Input and
                ** Output Methods chapter.
                */
                Delay(200);

                CloseWindow(win);
                }
            FreeScreenDrawInfo(screen,drawinfo);
            }
        UnlockPubScreen(NULL,screen);
        }
    CloseLibrary(IntuitionBase);
    }
```
}


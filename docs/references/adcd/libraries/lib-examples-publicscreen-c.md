---
title: Lib_examples/publicscreen.c
manual: libraries
chapter: libraries
section: lib-examples-publicscreen-c
functions: [OpenScreenTagList]
libraries: [intuition.library]
---

# Lib_examples/publicscreen.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* publicscreen.c
** open a screen with the pens from a public screen.
**
** SAS/C 5.10a
** lc -b1 -cfist -v -y publicscreen
** blink FROM LIB:c.o publicscreen.o TO publicscreen LIB LIB:lc.lib LIB:amiga.lib
*/
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/screens.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

VOID usePubScreenPens(void);

struct Library *IntuitionBase;

/* main(): open libraries, clean up when done.
*/
VOID main(int argc, char **argv)
{
IntuitionBase = OpenLibrary("intuition.library",0);
if ( IntuitionBase != NULL )
```c
    {
    /* Check the version number; Release 2 is */
    /* required for public screen functions   */
    if (IntuitionBase->lib_Version >= 37)
        {
        usePubScreenPens();
        }
    CloseLibrary(IntuitionBase);
    }
```
}

/* Open a screen that uses the pens of an existing public screen
** (the Workbench screen in this case).
*/
VOID usePubScreenPens(void)
{
struct Screen *my_screen;
struct TagItem screen_tags[2];
UBYTE *pubScreenName = "Workbench";

struct Screen *pub_screen = NULL;
struct DrawInfo *screen_drawinfo = NULL;

/* Get a lock on the Workbench screen */
pub_screen = LockPubScreen(pubScreenName);
if ( pub_screen != NULL )

```c
    {
    /* get the DrawInfo structure from the locked screen */
    screen_drawinfo = GetScreenDrawInfo(pub_screen);
    if ( screen_drawinfo != NULL)
        {
        /* the pens are copied in the OpenScreenTagList() call,
        ** so we can simply use a pointer to the pens in the tag list.
        **
        ** This works better if the depth and colors of the new screen
        ** matches that of the public screen.  Here we are forcing the
        ** workbench screen pens on a monochrome screen (which may not
        ** be a good idea).  You could add the tag:
        **      (SA_Depth, screen_drawinfo->dri_Depth)
        */
        screen_tags[0].ti_Tag  = SA_Pens;
        screen_tags[0].ti_Data = (ULONG)(screen_drawinfo->dri_Pens);
        screen_tags[0].ti_Tag  = TAG_END;
        screen_tags[0].ti_Data = NULL;

        my_screen = OpenScreenTagList(NULL, screen_tags);
        if (my_screen != NULL)
            {
            /* We no longer need to hold the lock on the public screen
            ** or a copy of its DrawInfo structure as we now have our
            ** own screen.  Release the screen.
            */
            FreeScreenDrawInfo(pub_screen,screen_drawinfo);
            screen_drawinfo = NULL;
            UnlockPubScreen(pubScreenName,pub_screen);
            pub_screen = NULL;

            Delay(90);   /* should be rest_of_program */

            CloseScreen(my_screen);
            }
        }
    }
```
/* These are freed in the main loop if OpenScreenTagList() does
** not fail.  If something goes wrong, free them here.
*/
if ( screen_drawinfo != NULL )
```c
    FreeScreenDrawInfo(pub_screen,screen_drawinfo);
```
if ( pub_screen!= NULL )
```c
    UnlockPubScreen(pubScreenName,pub_screen);
```
}

---

## See Also

- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)

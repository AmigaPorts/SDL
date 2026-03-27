---
title: lib_examples/screen34to37.c
manual: libraries
chapter: libraries
section: lib-examples-screen34to37-c
functions: [OpenScreen]
libraries: [intuition.library]
---

# lib_examples/screen34to37.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* screen34to37.c - Execute me to compile me with SAS 5.10
LC -b1 -cfistq -v -y -j73 screen34to37.c
blink FROM LIB:c.o screen34to37.o TO screen34to37 LIB LIB:lc.lib LIB:amiga.lib
quit
*/

#define INTUI_V36_NAMES_ONLY         /* We'll use the newer Intuition names. */

#include <exec/types.h>              /* Amiga data types.              */
#include <intuition/intuition.h>     /* Lots of important Intuition    */
#include <intuition/screens.h>       /* structures we will be using.   */

#include <clib/exec_protos.h>        /* Function prototypes            */
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }    /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }    /* really */
#endif

struct Library *IntuitionBase;       /* Intuition library base          */

/* Simple example to show how to open a custom screen that gives the new look
 * under V37, yet still works with older version of the operating system.
 * Attach the tag SA_Pens and a minimal pen specification to ExtNewScreen,
 * and call the old OpenScreen() function.  The tags will be ignored by
 * V34 and earlier versions of the OS.  In V36 and later the tags are
 * accepted by Intuition.
*/

VOID main(int argc, char **argv)
{
UWORD pens[] = { ~0 };               /* This is the minimal pen specification*/
struct Screen      *my_screen;       /* Pointer to our new, custom screen    */
struct ExtNewScreen myscreen_setup;  /* Same as NewScreen with tags attached */
struct TagItem      myscreen_tags[2];/* A small tag array                    */

/* Open the library before you call any functions */
IntuitionBase = OpenLibrary("intuition.library",0);
if (NULL != IntuitionBase)
   {
```c
      /* Fill in the tag list with the minimal pen specification */
      myscreen_tags[0].ti_Tag=SA_Pens;
      myscreen_tags[0].ti_Data=(ULONG) pens;
      myscreen_tags[1].ti_Tag=TAG_DONE;

      /* The screen is opened two bitplanes deep so that the
      ** new look will show-up better.
      **/
      myscreen_setup.LeftEdge=0;
      myscreen_setup.TopEdge=0;
      myscreen_setup.Width=640;              /* Smaller values here reduce   */
      myscreen_setup.Height=STDSCREENHEIGHT; /* drawing area and save memory.*/
      myscreen_setup.Depth=2;                /* Two planes means 4 colors.   */
      myscreen_setup.DetailPen=0;            /* Normal V34 pen colors.       */
      myscreen_setup.BlockPen=1;
      myscreen_setup.ViewModes=HIRES;
      myscreen_setup.Type=CUSTOMSCREEN | NS_EXTENDED; /* Extended NewScreen flag */
      myscreen_setup.Font=NULL;
      myscreen_setup.DefaultTitle="My Screen";
      myscreen_setup.Gadgets=NULL;
      myscreen_setup.CustomBitMap=NULL;
      /* Attach the pen specification tags to the ExtNewScreen structure */
      myscreen_setup.Extension=myscreen_tags;

      if (NULL != (my_screen =
        OpenScreen((struct NewScreen *)&myscreen_setup)));
          {
          /* screen successfully opened */

          Delay(200L);  /* normally the program would be here */

          CloseScreen(my_screen);
          }
      CloseLibrary(IntuitionBase);
```
   }
}

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)

---
title: Lib_examples/easyintuition.c
manual: libraries
chapter: libraries
section: lib-examples-easyintuition-c
functions: [OpenScreen, OpenWindow]
libraries: [intuition.library]
---

# Lib_examples/easyintuition.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* Here's the same example as above written for both Release 2 and
 * earlier versions of the operating system.  The main difference
 * here is that this example avoids using any new Release 2
 * functions, but does pass extended structures to the older
 * Intuition functions so that some new Release 2 features may be
 * accessed in a backward-compatible manner.
 */

/* easyintuition.c  Simple backward-compatible V37 Intuition example    */
/*                                                                      */
/* This example uses extended structures with the pre-V37 OpenScreen()  */
/* and OpenWindow() functions to compatibly open an Intuition display.  */
/* Enhanced V37 options specified via tags are ignored on 1.3 systems.  */
/* Compiled with Lattice C v5.10: lc -L easyintuition.c                 */

/* Force use of new variable names to help prevent errors  */
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>             /* The Amiga data types file.         */
#include <intuition/intuition.h>    /* Intuition data strucutres, etc.    */
#include <libraries/dos.h>          /* Official return codes defined here */

#include <clib/exec_protos.h>       /* Exec function prototypes           */
#include <clib/intuition_protos.h>  /* Intuition function prototypes      */

#ifdef LATTICE                      /* Disable Ctrl-C handling in SAS/C   */
int CXBRK(void)  {return(0);}
void chkabort(void) {return;}
#endif

/* Use lowest non-obsolete version that supplies the functions needed. */
#define INTUITION_REV 33L

/* Declare the prototypes of our own functions. Prototypes for system  */
/* functions are declared in the header files in the clib directory    */
VOID cleanExit( struct Screen *, struct Window *, LONG );
BOOL handleIDCMP( struct Window *);

struct Library *IntuitionBase = NULL;

/* We can specify that we want the V37-compatible 3D look when
 * running under V37 by adding an SA_Pens tag.
 */
WORD pens[] = {~0};	/* empty pen array to get default 3D look */
struct TagItem ourscreentags[] = {
	{ SA_Pens, (ULONG)pens },
	{ TAG_DONE }};

/* ExtNewScreen is an extended NewScreen structure.
 * NS_EXTENDED flags that there is a tag pointer to additional
 * tag information at the end of this structure.  The tags will
 * be parsed by Release 2 but ignored by earlier OS versions.
 */
struct ExtNewScreen fullHires =

```c
    {
    0,                /* LeftEdge must be zero prior to Release 2 */
    0,                /* TopEdge */
    640,              /* Width (high-resolution) */
    STDSCREENHEIGHT,  /* Height (non-interlace)  */
    2,                /* Depth (4 colors will be available) */
    0,1,              /* Default DetailPen and BlockPen  */
    HIRES,            /* the high-resolution display mode */
    CUSTOMSCREEN | NS_EXTENDED,     /* the screen type */
    NULL,             /* no special font */
    "Our Screen",     /* the screen title */
    NULL,             /* no custom screen gadgets (not supported) */
    NULL,             /* no CustomBitMap */
    ourscreentags     /* tags for additional V37 features */
    };
```
/* Position and sizes for our window */
#define WIN_LEFTEDGE   20
#define WIN_TOPEDGE    20
#define WIN_WIDTH     400
#define WIN_MINWIDTH   80
#define WIN_HEIGHT    150
#define WIN_MINHEIGHT  20

/* Under V37, we'll get a special screen title when our window is active */
UBYTE activetitle[] = {"Our Screen - EasyWindow is Active"};

struct TagItem ourwindowtags[] = {
	{ WA_ScreenTitle, (ULONG)&activetitle[0] },
	{ TAG_DONE }};

/* ExtNewWindow is an extended NewWindow structure.
 * NW_EXTENDED indicates that there is a tag pointer to additional tag
 * information at the end of this structure.  The tags will be parsed
 * by Release 2 but ignored by earlier OS versions.
 */
struct ExtNewWindow easyWindow =


```c
    {
    WIN_LEFTEDGE,
    WIN_TOPEDGE,
    WIN_WIDTH,
    WIN_HEIGHT,
    -1,-1,             /* Means use the screen's Detail and Block pens   */

    IDCMP_CLOSEWINDOW, /* This field specifies the events we want to get */

    /* These flags specify system gadgets and other window attributes    */
    /* including the EXTENDED flag which flags this as an ExtNewWindow   */
    WFLG_CLOSEGADGET | WFLG_SMART_REFRESH | WFLG_ACTIVATE | WFLG_DRAGBAR |
    WFLG_DEPTHGADGET | WFLG_SIZEGADGET  | WFLG_NOCAREREFRESH |
    WFLG_NW_EXTENDED,

    NULL,             /* Pointer to the first gadget  */
    NULL,             /* No checkmark.                */
    "EasyWindow",     /* Window title.                */
    NULL,             /* Attach a screen later.       */
    NULL,             /* Let Intuition set up BitMap  */
    WIN_MINWIDTH,     /* Minimum width.       */
    WIN_MINHEIGHT,    /* Minimum height.      */
    -1,               /* Maximum width (screen size)  */
    -1,               /* Maximum height (screen size) */
    CUSTOMSCREEN,     /* A screen of our own. */
    ourwindowtags     /* tags for additional V37 features */
    };
```
VOID main(int argc, char *argv[])
{
```c
    /* Declare variables here */
    ULONG signalmask, winsignal, signals;
    BOOL done = FALSE;
    struct Screen *screen1 = NULL;
    struct Window *window1 = NULL;

    /* Open Intuition Library.  NOTE - We are accepting version 33 (1.2)
     * or higher because we are opening our display in a compatible manner.
     * However - If you add to this example, do NOT use any NEW V37
     * functions unless IntuitionBase->lib_Version is >= 37
     */
    IntuitionBase = OpenLibrary( "intuition.library",INTUITION_REV );
    if (IntuitionBase == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Open any other required libraries and make */
    /* any assignments that were postponed above  */

    /* Open the screen */
    screen1 = OpenScreen(&fullHires);
    if (screen1 == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Attach the window to the open screen ... */
    easyWindow.Screen = screen1;

    /* ... and open the window */
    window1 = OpenWindow(&easyWindow);
    if (window1 == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Set up the signals for the events we want to hear about ...   */
    winsignal = 1L << window1->UserPort->mp_SigBit;  /* window IDCMP */
    signalmask = winsignal;     /* we will only wait on IDCMP events */

    /* Here's the main input event loop where we wait for events.    */
    /* We have asked Intuition to send us CLOSEWINDOW IDCMP events   */
    /* Exec will wake us if any event we are waiting for occurs.     */
    while( !done )
    {
        signals = Wait(signalmask);

        /* An event occurred - now act on the signal(s) we received.*/
        /* We were only waiting on one signal (winsignal) in our    */
        /* signalmask, so we actually know we received winsignal.   */
        if(signals & winsignal)
            done = handleIDCMP(window1);    /* done if close gadget */
    }
    cleanExit(screen1, window1, RETURN_OK); /* Exit the program     */
```
}


BOOL handleIDCMP( struct Window *win )
{
```c
    BOOL done = FALSE;
    struct IntuiMessage *message;
    ULONG class;

    /* Examine pending messages */
    while( message = (struct IntuiMessage *)GetMsg(win->UserPort) )
    {
        class = message->Class;   /* get all data we need from message */

        /* When we're through with a message, reply */
        ReplyMsg( (struct Message *)message);

        /* See what events occurred */
        switch( class )
        {
            case IDCMP_CLOSEWINDOW:
                done = TRUE;
                break;
            default:
                break;
        }
    }
    return(done);
```
}


VOID cleanExit( struct Screen *scrn, struct Window *wind, LONG returnValue )
{
```c
    /* Close things in the reverse order of opening */
    if (wind) CloseWindow( wind );      /* Close window if opened */
    if (scrn) CloseScreen( scrn );      /* Close screen if opened */

    /* Close the library, and then exit */
    if (IntuitionBase) CloseLibrary( IntuitionBase );
    exit(returnValue);
```
}

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)

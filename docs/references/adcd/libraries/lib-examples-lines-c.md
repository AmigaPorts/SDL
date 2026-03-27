---
title: Lib_examples/lines.c
manual: libraries
chapter: libraries
section: lib-examples-lines-c
functions: [GetScreenData, LockPubScreen, OpenWindow, OpenWindowTagList, WaitPort]
libraries: [exec.library, intuition.library]
---

# Lib_examples/lines.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* lines.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 lines.c
Blink FROM LIB:c.o,lines.o TO lines LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** This example shows how to implement a superbitmap, and uses a host of
** Intuition facilities.  Further reading of other Intuition and graphics
** chapters may be required for a complete understanding of this example.
**
** lines.c -- implements a superbitmap with scroll gadgets
** This program requires V37, as it uses calls to OpenWindowTags(),
** LockPubScreen().
*/


/* Enforces use of new prefixed Intuition flag names */
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <exec/memory.h>
#include <intuition/intuition.h>

#include <clib/exec_protos.h>
#include <clib/layers_protos.h>
#include <clib/graphics_protos.h>
#include <clib/intuition_protos.h>

/* Random number function in amiga.lib (see amiga.lib.doc) */
UWORD RangeRand( unsigned long maxValue );

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

#define WIDTH_SUPER     (800)
#define HEIGHT_SUPER    (600)

#define UP_DOWN_GADGET    (0)
#define LEFT_RIGHT_GADGET (1)
#define NO_GADGET         (2)

#define MAXPROPVAL (0xFFFFL)

#define GADGETID(x) (((struct Gadget *)(msg->IAddress))->GadgetID)

#define LAYERXOFFSET(x) (x->RPort->Layer->Scroll_X)
#define LAYERYOFFSET(x) (x->RPort->Layer->Scroll_Y)

/* A string with this format will be found by the version command
** supplied by Amiga, Inc.  This will allow users to give version
** numbers with error reports.
*/
UBYTE vers[] = "$VER: lines 37.2";

struct Library *GfxBase;
struct Library *IntuitionBase;
struct Library *LayersBase;

struct Window      *Win = NULL;          /* window pointer */
struct PropInfo     BotGadInfo = {0};
struct Image        BotGadImage = {0};
struct Gadget       BotGad = {0};
struct PropInfo     SideGadInfo = {0};
struct Image        SideGadImage = {0};
struct Gadget       SideGad = {0};


/* Prototypes for our functions */
VOID initBorderProps(struct Screen *myscreen);
VOID doNewSize(void);
VOID doDrawStuff(void);
VOID doMsgLoop(void);
VOID superWindow(struct Screen *myscreen);


/*
** main
** Open all required libraries and get a pointer to the default public screen.
** Cleanup when done or on error.
*/
VOID main(int argc, char **argv)
{
struct Screen *myscreen;

/* open all of the required libraries for the program.
**
** require version 37 of the Intuition library.
*/

if (IntuitionBase = OpenLibrary("intuition.library",37L))
```c
    {
    if (GfxBase = OpenLibrary("graphics.library",33L))
        {
        if (LayersBase = OpenLibrary("layers.library",33L))
            {
            /* LockPubScreen()/UnlockPubScreen is only available under V36
            ** and later... Use GetScreenData() under V34 systems to get a
            ** copy of the screen structure...
            */
            if (NULL != (myscreen = LockPubScreen(NULL)))
                {
                superWindow(myscreen);
                UnlockPubScreen(NULL,myscreen);
                }
            CloseLibrary(LayersBase);
            }
        CloseLibrary(GfxBase);
        }
    CloseLibrary(IntuitionBase);
    }
```
}


/*
** Create, initialize and process the super bitmap window.
** Cleanup if any error.
*/
VOID superWindow(struct Screen *myscreen)
{
struct BitMap *bigBitMap;
WORD planeNum;
WORD allocatedBitMaps;

/* set-up the border prop gadgets for the OpenWindow() call. */
initBorderProps(myscreen);

/* The code relies on the allocation of the BitMap structure with
** the MEMF_CLEAR flag.  This allows the assumption that all of the
** bitmap pointers are NULL, except those successfully allocated
** by the program.
*/
if (bigBitMap = AllocMem(sizeof(struct BitMap), MEMF_PUBLIC | MEMF_CLEAR))

```c
    {
    InitBitMap(bigBitMap, myscreen->BitMap.Depth, WIDTH_SUPER, HEIGHT_SUPER);

    allocatedBitMaps = TRUE;
    for (planeNum = 0;
         (planeNum < myscreen->BitMap.Depth) && (allocatedBitMaps == TRUE);
             planeNum++)
        {
        bigBitMap->Planes[planeNum] = AllocRaster(WIDTH_SUPER, HEIGHT_SUPER);
        if (NULL == bigBitMap->Planes[planeNum])
            allocatedBitMaps = FALSE;
        }

    /* Only open the window if the bitplanes were successfully
    ** allocated.  Fail silently if they were not.
    */
    if (TRUE == allocatedBitMaps)
        {
        /* OpenWindowTags() and OpenWindowTagList() are only available
        ** when the library version is at least V36.  Under earlier
        ** versions of Intuition, use OpenWindow() with a NewWindow
        ** structure.
        */
        if (NULL != (Win = OpenWindowTags(NULL,
                WA_Width,  150,
                WA_Height, 4 * (myscreen->WBorTop + myscreen->Font->ta_YSize + 1),
                WA_MaxWidth,  WIDTH_SUPER,
                WA_MaxHeight, HEIGHT_SUPER,
                WA_IDCMP, IDCMP_GADGETUP | IDCMP_GADGETDOWN |
                    IDCMP_NEWSIZE | IDCMP_INTUITICKS | IDCMP_CLOSEWINDOW,
                WA_Flags, WFLG_SIZEGADGET | WFLG_SIZEBRIGHT | WFLG_SIZEBBOTTOM |
                    WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                    WFLG_SUPER_BITMAP | WFLG_GIMMEZEROZERO | WFLG_NOCAREREFRESH,
                WA_Gadgets, &(SideGad),
                WA_Title, &vers[6], /* take title from version string */
                WA_PubScreen, myscreen,
                WA_SuperBitMap, bigBitMap,
                TAG_DONE)))
            {
            /* set-up the window display */
            SetRast(Win->RPort,0); /* clear the bitplanes */
            SetDrMd(Win->RPort,JAM1);
```
	    doNewSize();    /* adjust props to represent portion visible */
```c
            doDrawStuff();

            /* process the window, return on IDCMP_CLOSEWINDOW */
            doMsgLoop();

            CloseWindow(Win);
            }
        }

    for (planeNum = 0; planeNum < myscreen->BitMap.Depth; planeNum++)
        {
        /* free only the bitplanes actually allocated... */
        if (NULL != bigBitMap->Planes[planeNum])
            FreeRaster(bigBitMap->Planes[planeNum], WIDTH_SUPER, HEIGHT_SUPER);
        }
    FreeMem(bigBitMap,sizeof(struct BitMap));
    }
```
}

/*
** Set-up the prop gadgets--initialize them to values that fit
** into the window border.  The height of the prop gadget on the side
** of the window takes the height of the title bar into account in its
** set-up. note the initialization assumes a fixed size "sizing" gadget.
**
** Note also, that the size of the sizing gadget is dependent on the
** screen resolution.  The numbers given here are only valid if the
** screen is NOT lo-res.  These values must be re-worked slightly
** for lo-res screens.
**
** The PROPNEWLOOK flag is ignored by 1.3.
*/
VOID initBorderProps(struct Screen *myscreen)
{
/* initializes the two prop gadgets.
**
** Note where the PROPNEWLOOK flag goes.  Adding this flag requires
** no extra storage, but tells the system that our program is
** expecting the new-look prop gadgets under 2.0.
*/
BotGadInfo.Flags     = AUTOKNOB | FREEHORIZ | PROPNEWLOOK;
BotGadInfo.HorizPot  = 0;
BotGadInfo.VertPot   = 0;
BotGadInfo.HorizBody = -1;
BotGadInfo.VertBody  = -1;

BotGad.LeftEdge     = 3;
BotGad.TopEdge      = -7;
BotGad.Width        = -23;
BotGad.Height       = 6;

BotGad.Flags        = GFLG_RELBOTTOM | GFLG_RELWIDTH;
BotGad.Activation   = GACT_RELVERIFY | GACT_IMMEDIATE | GACT_BOTTOMBORDER;
BotGad.GadgetType   = GTYP_PROPGADGET | GTYP_GZZGADGET;
BotGad.GadgetRender = (APTR)&(BotGadImage);
BotGad.SpecialInfo  = (APTR)&(BotGadInfo);
BotGad.GadgetID     = LEFT_RIGHT_GADGET;

SideGadInfo.Flags     = AUTOKNOB | FREEVERT | PROPNEWLOOK;
SideGadInfo.HorizPot  = 0;
SideGadInfo.VertPot   = 0;
SideGadInfo.HorizBody = -1;
SideGadInfo.VertBody  = -1;

/* NOTE the TopEdge adjustment for the border and the font for V36.
*/
SideGad.LeftEdge   = -14;
SideGad.TopEdge    = myscreen->WBorTop + myscreen->Font->ta_YSize + 2;
SideGad.Width      = 12;
SideGad.Height     = -SideGad.TopEdge - 11;

SideGad.Flags        = GFLG_RELRIGHT | GFLG_RELHEIGHT;
SideGad.Activation   = GACT_RELVERIFY | GACT_IMMEDIATE | GACT_RIGHTBORDER;
SideGad.GadgetType   = GTYP_PROPGADGET | GTYP_GZZGADGET;
SideGad.GadgetRender = (APTR)&(SideGadImage);
SideGad.SpecialInfo  = (APTR)&(SideGadInfo);
SideGad.GadgetID     = UP_DOWN_GADGET;
SideGad.NextGadget   = &(BotGad);
}


/*
** This function does all the work of drawing the lines
*/
VOID doDrawStuff()
{
WORD x1,y1,x2,y2;
WORD pen,ncolors,deltx,delty;

ncolors = 1 << Win->WScreen->BitMap.Depth;
deltx = RangeRand(6)+2;
delty = RangeRand(6)+2;

pen = RangeRand(ncolors-1) + 1;
SetAPen(Win->RPort,pen);
for(x1=0, y1=0, x2=WIDTH_SUPER-1, y2=HEIGHT_SUPER-1;
	x1 < WIDTH_SUPER;
		x1 += deltx, x2 -= deltx)

```c
    {
    Move(Win->RPort,x1,y1);
    Draw(Win->RPort,x2,y2);
    }
```
pen = RangeRand(ncolors-1) + 1;
SetAPen(Win->RPort,pen);
for(x1=0, y1=0, x2=WIDTH_SUPER-1, y2=HEIGHT_SUPER-1;
	y1 < HEIGHT_SUPER;
		y1 += delty, y2 -= delty)
```c
    {
    Move(Win->RPort,x1,y1);
    Draw(Win->RPort,x2,y2);
    }
```
}

/*
** This function provides a simple interface to ScrollLayer
*/
VOID slideBitMap(WORD Dx,WORD Dy)
{
ScrollLayer(0,Win->RPort->Layer,Dx,Dy);
}

/*
** Update the prop gadgets and bitmap positioning when the size changes.
*/
VOID doNewSize()
{
ULONG tmp;

tmp = LAYERXOFFSET(Win) + Win->GZZWidth;
if (tmp >= WIDTH_SUPER)

```c
    slideBitMap(WIDTH_SUPER-tmp,0);
```
NewModifyProp(&(BotGad),Win,NULL,AUTOKNOB | FREEHORIZ,

```c
    ((LAYERXOFFSET(Win) * MAXPROPVAL) /
        (WIDTH_SUPER - Win->GZZWidth)),
    NULL,
    ((Win->GZZWidth * MAXPROPVAL) / WIDTH_SUPER),
    MAXPROPVAL,
    1);
```
tmp = LAYERYOFFSET(Win) + Win->GZZHeight;
if (tmp >= HEIGHT_SUPER)

```c
    slideBitMap(0,HEIGHT_SUPER-tmp);
```
NewModifyProp(&(SideGad),Win,NULL,AUTOKNOB | FREEVERT,
```c
    NULL,
    ((LAYERYOFFSET(Win) * MAXPROPVAL) /
        (HEIGHT_SUPER - Win->GZZHeight)),
    MAXPROPVAL,
    ((Win->GZZHeight * MAXPROPVAL) / HEIGHT_SUPER),
    1);
```
}

/*
** Process the currently selected gadget.
** This is called from IDCMP_INTUITICKS and when the gadget is released
** IDCMP_GADGETUP.
*/
VOID checkGadget(UWORD gadgetID)
{
ULONG tmp;
WORD dX = 0;
WORD dY = 0;

switch (gadgetID)
```c
    {
    case UP_DOWN_GADGET:
        tmp = HEIGHT_SUPER - Win->GZZHeight;
        tmp = tmp * SideGadInfo.VertPot;
        tmp = tmp / MAXPROPVAL;
        dY = tmp - LAYERYOFFSET(Win);
        break;
    case LEFT_RIGHT_GADGET:
        tmp = WIDTH_SUPER - Win->GZZWidth;
        tmp = tmp * BotGadInfo.HorizPot;
        tmp = tmp / MAXPROPVAL;
        dX = tmp - LAYERXOFFSET(Win);
        break;
    }
```
if (dX || dY)
```c
    slideBitMap(dX,dY);
```
}

/*
** Main message loop for the window.
*/
VOID doMsgLoop()
{
struct IntuiMessage *msg;
WORD flag = TRUE;
UWORD currentGadget = NO_GADGET;

while (flag)
```c
    {
    /* Whenever you want to wait on just one message port */
    /* you can use WaitPort(). WaitPort() doesn't require */
    /* the setting of a signal bit. The only argument it  */
    /* requires is the pointer to the window's UserPort   */
    WaitPort(Win->UserPort);
    while (msg = (struct IntuiMessage *)GetMsg(Win->UserPort))
        {
        switch (msg->Class)
            {
            case IDCMP_CLOSEWINDOW:
                flag = FALSE;
                break;
            case IDCMP_NEWSIZE:
                doNewSize();
    		doDrawStuff();
                break;
            case IDCMP_GADGETDOWN:
                currentGadget = GADGETID(msg);
                break;
            case IDCMP_GADGETUP:
                checkGadget(currentGadget);
                currentGadget = NO_GADGET;
                break;
            case IDCMP_INTUITICKS:
                checkGadget(currentGadget);
                break;
            }
        ReplyMsg((struct Message *)msg);
        }
    }
```
}

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)

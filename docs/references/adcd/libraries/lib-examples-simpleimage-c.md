---
title: Lib_examples/simpleimage.c
manual: libraries
chapter: libraries
section: lib-examples-simpleimage-c
functions: [AllocMem]
libraries: [exec.library]
---

# Lib_examples/simpleimage.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* simpleimage.c - program to show the use of a simple Intuition Image.
**
** compiled with:
** lc -b1 -cfist -v -y simpleimage.c
** blink FROM LIB:c.o+"simpleimage.o" TO "simpleimage" LIB LIB:lc.lib LIB:amiga.lib
*/
#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct IntuitionBase *IntuitionBase = NULL;

#define MYIMAGE_LEFT    (0)
#define MYIMAGE_TOP     (0)
#define MYIMAGE_WIDTH   (24)
#define MYIMAGE_HEIGHT  (10)
#define MYIMAGE_DEPTH   (1)

/* This is the image data.  It is a one bit-plane open rectangle which is 24
** pixels wide and 10 high.  Make sure that it is in CHIP memory, or allocate
** a block of chip memory with a call like this: AllocMem(data_size,MEMF_CHIP),
** and then copy the data to that block.  See the Exec chapter on Memory
** Allocation for more information on AllocMem().
*/
UWORD __chip myImageData[] =

```c
    {
    0xFFFF, 0xFF00,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xC000, 0x0300,
    0xFFFF, 0xFF00,
    };
```
/*
** main routine. Open required library and window and draw the images.
** This routine opens a very simple window with no IDCMP.  See the
** chapters on "Windows" and "Input and Output Methods" for more info.
** Free all resources when done.
*/
VOID main(int argc, char *argv[])
{
struct Window *win;
struct Image myImage;

IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",37);
if (IntuitionBase != NULL)
```c
    {
    if (NULL != (win = OpenWindowTags(NULL,
                        WA_Width,       200,
                        WA_Height,      100,
                        WA_RMBTrap,     TRUE,
                        TAG_END)))
        {
        myImage.LeftEdge    = MYIMAGE_LEFT;
        myImage.TopEdge     = MYIMAGE_TOP;
        myImage.Width       = MYIMAGE_WIDTH;
        myImage.Height      = MYIMAGE_HEIGHT;
        myImage.Depth       = MYIMAGE_DEPTH;
        myImage.ImageData   = myImageData;
        myImage.PlanePick   = 0x1;              /* use first bit-plane     */
        myImage.PlaneOnOff  = 0x0;              /* clear all unused planes */
        myImage.NextImage   = NULL;

        /* Draw the 1 bit-plane image into the first bit-plane (color 1) */
        DrawImage(win->RPort,&myImage,10,10);

        /* Draw the same image at a new location */
        DrawImage(win->RPort,&myImage,100,10);

        /* Wait a bit, then quit.
        ** In a real application, this would be an event loop, like the
        ** one described in the Intuition Input and Output Methods chapter.
        */
        Delay(200);

        CloseWindow(win);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
```
}

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)

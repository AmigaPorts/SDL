---
title: Devices/Dev_examples/Set_Mouse.c
manual: devices
chapter: devices
section: devices-dev-examples-set-mouse-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# Devices/Dev_examples/Set_Mouse.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Set_Mouse.c
 *
 * This example sets the mouse at x=100 and y=200
 *
 * Compile with SAS C 5.10: LC -b1 -cfistq -v -y -L
 * Requires Kickstart 36 or greater.
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <devices/input.h>
#include <devices/inputevent.h>
#include <intuition/screens.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct IntuitionBase *IntuitionBase;

void main(void)
{
struct IOStdReq   *InputIO;           /* I/O request block */
struct MsgPort    *InputMP;           /* Message port */
struct InputEvent *FakeEvent;         /* InputEvent pointer */
struct IEPointerPixel *NeoPix;      /* New mouse position pointer */
struct Screen *PubScreen;             /* Screen pointer */

if (InputMP = CreateMsgPort())
```c
    {
    if (FakeEvent = AllocMem(sizeof(struct InputEvent),MEMF_PUBLIC))
        {
        if (NeoPix  = AllocMem(sizeof(struct IEPointerPixel),MEMF_PUBLIC))
            {
            if (InputIO = CreateIORequest(InputMP,sizeof(struct IOStdReq)))
                {
                if (!OpenDevice("input.device",NULL,
                               (struct IORequest *)InputIO,NULL))
                    {
                        /* Open Intuition library */
                    if (IntuitionBase=(struct IntuitionBase *)
                                      OpenLibrary("intuition.library",36L))
                        {
                        /* Get pointer to screen and lock screen */
                        if (PubScreen=(struct Screen *)LockPubScreen(NULL))
                            {
                            /* Set up IEPointerPixel fields */
                            /* WB screen */
                            NeoPix->iepp_Screen=(struct Screen *)PubScreen;
                            /* put pointer at x = 100 */
                            NeoPix->iepp_Position.X = 100;
                            /* put pointer at y = 200 */
                            NeoPix->iepp_Position.Y = 200;

                            /* Set up InputEvent fields */
                            /* IEPointerPixel */
                            FakeEvent->ie_EventAddress = (APTR)NeoPix;
                            FakeEvent->ie_NextEvent = NULL;
                            /* new mouse pos */
                            FakeEvent->ie_Class = IECLASS_NEWPOINTERPOS;
                            /* on pixel */
                            FakeEvent->ie_SubClass = IESUBCLASS_PIXEL;
                            FakeEvent->ie_Code = IECODE_NOBUTTON;
                            /* absolute positioning */
                            FakeEvent->ie_Qualifier = NULL;

                            /* InputEvent */
                            InputIO->io_Data = (APTR)FakeEvent;
                            InputIO->io_Length = sizeof(struct InputEvent);
                            InputIO->io_Command = IND_WRITEEVENT;
                            DoIO((struct IORequest *)InputIO);
                            /* Unlock screen */
                            UnlockPubScreen(NULL,PubScreen);
                            }
                        else
                            printf("Could not get pointer to screen\n");
                        /* Close intuition library */
                        CloseLibrary(IntuitionBase);
                        }
                    else
                        /* Can't open V36 (or higher) intuition.library */
                        printf("Error:Can't open V36 intuition.library\n");

                    CloseDevice((struct IORequest *)InputIO);
                    }
                else
                    printf("Error: Could not open input.device\n");

                DeleteIORequest(InputIO);
                }
            else
                printf("Error: Could not create IORequest\n");

            FreeMem(NeoPix,sizeof(struct IEPointerPixel));
            }
        else
            printf("Error: Could not allocate memory for NeoPix\n");

        FreeMem(FakeEvent,sizeof(struct InputEvent));
        }
    else
        printf("Error: Could not allocate memory for FakeEvent\n");

    DeleteMsgPort(InputMP);
    }
```
else
```c
    printf("Error: Could not create message port\n");
```
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)

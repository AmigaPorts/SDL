---
title: Devices/Dev_examples/Swap_Buttons.c
manual: devices
chapter: devices
section: devices-dev-examples-swap-buttons-c
functions: []
libraries: []
---

# Devices/Dev_examples/Swap_Buttons.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Swap_Buttons.c
 *
 * This example swaps the function of the left and right mouse buttons
 * The C code is just the wrapper that installs and removes the
 * input.device handler that does the work.
 *
 * The handler is written in assembly code since it is important that
 * handlers be as fast as possible while processing the input events.
 *
 * Compile and link as follows:
 *
 * SAS C 5.10:
 *  LC -b1 -cfirst -v -w Swap_Buttons.c
 *
 * Adapt assemble:
 *  HX68 InputHandler.a to InputHandler.o
 *
 * BLink:
 *  BLink from LIB:c.o+Swap_Buttons.o+InputHandler.o LIB LIB:lc.lib
 *  LIB:amiga.lib TO Swap_Buttons
 *
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/interrupts.h>
#include <devices/input.h>
#include <intuition/intuition.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

UBYTE NameString[]="Swap Buttons";

struct NewWindow mywin={50,40,124,18,0,1,CLOSEWINDOW,

```c
                      WINDOWDRAG|WINDOWCLOSE|SIMPLE_REFRESH|NOCAREREFRESH,
                      NULL,NULL,NameString,NULL,NULL,0,0,0,0,WBENCHSCREEN};
```
extern VOID ButtonSwap();

extern struct IntuitionBase *IntuitionBase;

/*
 * This routine opens a window and waits for the one event that
 * can happen (CLOSEWINDOW)  This is just to let the user play with
 * the swapped buttons and then close the program...
 */
VOID WaitForUser(VOID)
{
struct Window  *win;

if (IntuitionBase=(struct IntuitionBase *)
```c
                                OpenLibrary("intuition.library",33L))
    {
    if (win=OpenWindow(&mywin))
        {
        WaitPort(win->UserPort);
        ReplyMsg(GetMsg(win->UserPort));

        CloseWindow(win);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
```
}

VOID main(VOID)
{
struct IOStdReq  *inputReqBlk;
struct MsgPort   *inputPort;
struct Interrupt *inputHandler;

if (inputPort=CreatePort(NULL,NULL))
```c
    {
    if (inputHandler=AllocMem(sizeof(struct Interrupt),
                               MEMF_PUBLIC|MEMF_CLEAR))
        {
        if (inputReqBlk=(struct IOStdReq *)CreateExtIO(inputPort,
                                                 sizeof(struct IOStdReq)))
            {
            if (!OpenDevice("input.device",NULL,
                             (struct IORequest *)inputReqBlk,NULL))
                {
                inputHandler->is_Code=ButtonSwap;
                inputHandler->is_Data=NULL;
                inputHandler->is_Node.ln_Pri=100;
                inputHandler->is_Node.ln_Name=NameString;
                inputReqBlk->io_Data=(APTR)inputHandler;
                inputReqBlk->io_Command=IND_ADDHANDLER;
                DoIO((struct IORequest *)inputReqBlk);

                WaitForUser();

                inputReqBlk->io_Data=(APTR)inputHandler;
                inputReqBlk->io_Command=IND_REMHANDLER;
                DoIO((struct IORequest *)inputReqBlk);

                CloseDevice((struct IORequest *)inputReqBlk);
                }
            else
                printf("Error: Could not open input.device\n");

            DeleteExtIO((struct IORequest *)inputReqBlk);
            }
        else
            printf("Error: Could not create I/O request\n");

        FreeMem(inputHandler,sizeof(struct Interrupt));
        }
    else
        printf("Error: Could not allocate interrupt struct memory\n");

    DeletePort(inputPort);
    }
```
else
```c
    printf("Error: Could not create message port\n");
```
}

************************************************************************
*       InputHandler.a
*
* InputHandler that does a Left/Right mouse button swap...
*
* See Swap_Buttons.c for details on how to compile/assemble/link...
*
************************************************************************
*
* Required includes...
*
        INCDIR  "include:"
        INCLUDE "exec/types.i"
        INCLUDE "exec/io.i"
        INCLUDE "devices/inputevent.i"
*
************************************************************************
*
* Make the entry point external...
*
        xdef    _ButtonSwap
*
************************************************************************
*
* This is the input handler that will swap the
* mouse buttons for left handed use.
*
* The event list gets passed to you in  a0.
* The is_Data field is passed to you in a1.
* This example does not use the is_Data field...
*
* On exit you must return the event list in d0.  In this way
* you could add or remove items from the event list.
*
* The handler gets called here...
*
*
_ButtonSwap:    move.l  a0,-(sp)        ; Save the event list
*
* Since the event list could be a linked list, we start a loop
* here to handle all of the events passed to us.
*
CheckLoop:      move.w  ie_Qualifier(a0),d1             ; Get qualifiers...
```c
                move.w  d1,d0                           ; Two places...
```
*
* Since we are changing left and right mouse buttons, we need to make
* sure that we change the qualifiers on all of the messages.  The
* left and right mouse buttons are tracked in the message qualifiers
* for use in such things as dragging.  To make sure that we continue
* to drag correctly, we change the qualifiers.
*
CheckRight:     btst    #IEQUALIFIERB_RBUTTON,d1        ; Check for right
```c
                beq.s   NoRight
                bset    #IEQUALIFIERB_LEFTBUTTON,d0     ; Set the left...
                beq.s   CheckLeft
```
NoRight:        bclr    #IEQUALIFIERB_LEFTBUTTON,d0     ; Clear the left...
*
CheckLeft:      btst    #IEQUALIFIERB_LEFTBUTTON,d1     ; Check for left
```c
                beq.s   NoLeft
                bset    #IEQUALIFIERB_RBUTTON,d0        ; Set the right...
                beq.s   SaveQual
```
NoLeft:         bclr    #IEQUALIFIERB_RBUTTON,d0        ; Clear the right..
*
SaveQual:       move.w  d0,ie_Qualifier(a0)             ; Save back...
*
* The actual button up/down events are transmitted as the
* code field in RAWMOUSE events.  The code field must the be
* checked and modified when needed on RAWMOUSE events.  If the
* event is not a RAWMOUSE, we are done with it.
*
```c
                cmp.b   #IECLASS_RAWMOUSE,ie_Class(a0)  ; Check for mouse
                bne.s   NextEvent                       ; If not, next...
```
*
```c
                move.w  ie_Code(a0),d0                  ; Get code...
                move.w  d0,d1                           ; Save...
                and.w   #$7F,d0                         ; Mask UP_PREFIX
                cmp.w   #IECODE_LBUTTON,d0              ; Check for Left...
                beq.s   SwapThem                        ; If so, swap...
                cmp.w   #IECODE_RBUTTON,d0              ; Check for Right..
                bne.s   NextEvent                       ; If not, next...
```
*
SwapThem:       eor.w   #1,d1                           ; Flip bottom bit
```c
                move.w  d1,ie_Code(a0)                  ; Save it...
```
*
* The event list is linked via a pointer to the next event
* in the first element of the structure.  That is why it is not
* nessesary to use:  move.l ie_NextEvent(a0),d0
*
* The reason I move to d0 first is that this also checks for zero.
* The last event in the list will have a NULL ie_NextEvent field.
* This is NOT as standard EXEC list where the node after the last
* node is NULL.  Input events are single-linked for performance.
*
NextEvent:      move.l  (a0),d0                         ; Get next event
```c
                move.l  d0,a0                           ; into a0...
                bne.s   CheckLoop                       ; Do some more.
```
*
* All done, just return the event list...  (in d0)
*

```c
                move.l  (sp)+,d0        ; Get event list back...
                rts                     ; return from handler...
```

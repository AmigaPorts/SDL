---
title: Devices/Dev_examples/Key_Reset.c
manual: devices
chapter: devices
section: devices-dev-examples-key-reset-c
functions: []
libraries: []
---

# Devices/Dev_examples/Key_Reset.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Key_Reset.c
 *
 * This is in two parts...
 *
 * Compile this C code with SAS C 5.10:
 *      lc -b1 -cfistq -v -y Key_Reset
 *
 * Assemble the ASM code with Adapt
 *  HX68 KeyHandler.a to KeyHandler.o
 *
 * Link with:
 * Blink FROM LIB:c.o+Key_Reset.o+KeyHandler.o TO
 *        Key_Reset LIB LIB:lc.lib LIB:amiga.lib
 */

/*
 * Keyboard device reset handler example...
 */
#include <exec/types.h>
#include <exec/io.h>
#include <exec/ports.h>
#include <exec/memory.h>
#include <devices/keyboard.h>
#include <intuition/intuition.h>
#include <exec/interrupts.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/intuition_protos.h>
#include <clib/dos_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
void main();
#endif

extern VOID ResetHandler();

UBYTE NameString[]="Reset Handler Test";

struct NewWindow mywin={0,0,178,10,0,1,CLOSEWINDOW,

```c
                      WINDOWDRAG|WINDOWCLOSE|SIMPLE_REFRESH|NOCAREREFRESH
                      NULL,NULL,NameString,NULL,NULL,0,0,0,0,WBENCHSCREEN};
```
extern struct IntuitionBase *IntuitionBase;

struct MyData

```c
    {
    struct Task  *MyTask;
           ULONG MySignal;
    };
```
/*
 * This routine opens a window and waits for the one event that
 * can happen (CLOSEWINDOW)
 */
short WaitForUser(ULONG MySignal)
{
struct Window  *win;

```c
       short   ret=0;
```
if (IntuitionBase=(struct IntuitionBase *)
```c
                   OpenLibrary("intuition.library",0L))
    {
    if (win=(struct Window *)OpenWindow(&mywin))
        {
        ret=(MySignal==Wait(MySignal | (1L << win->UserPort->mp_SigBit)));
        CloseWindow(win);
        }
    else
        printf("Error: Could not open window\n");
    CloseLibrary((struct Library *)IntuitionBase);
    }
```
else
```c
    printf("Error: Could not open intution.library\n");
```
return(ret);
}

VOID main(int argc, char *argv[])
{
struct IOStdReq  *KeyIO;
struct MsgPort   *KeyMP;
struct Interrupt *keyHandler;
struct MyData    MyDataStuff;

```c
       ULONG     MySignal;
```
if ((MySignal=AllocSignal(-1L))!=-1)
```c
    {
    MyDataStuff.MyTask=FindTask(NULL);
    MyDataStuff.MySignal=1L << MySignal;

    if (KeyMP=CreatePort(NULL,NULL))
        {
        if (keyHandler =
                AllocMem(sizeof(struct Interrupt),MEMF_PUBLIC|MEMF_CLEAR))
            {
            if (KeyIO=(struct IOStdReq *)
                      CreateExtIO(KeyMP,sizeof(struct IOStdReq)))
                {
                if (!OpenDevice("keyboard.device",NULL,(struct IORequest *)
                                                        KeyIO,NULL))
                    {
                    keyHandler->is_Code=ResetHandler;
                    keyHandler->is_Data=(APTR)&MyDataStuff;

                    /*
                     * Note that only software interrupt priorities
                     * can be used for the .ln_Pri on the reset
                     * handler...
                     */
                    keyHandler->is_Node.ln_Pri=16;

                    keyHandler->is_Node.ln_Name=NameString;
                    KeyIO->io_Data=(APTR)keyHandler;
                    KeyIO->io_Command=KBD_ADDRESETHANDLER;
                    DoIO((struct IORequest *)KeyIO);

                    if (WaitForUser(MyDataStuff.MySignal))
                        {
                        if (argc) /* Check for CLI */
                            {
                            printf("System going down\n");
                            printf("Cleaning up...\n");
                            /* Show a delay, like cleanup... */
                            Delay(20);
                            printf("*Poof*\n");
                            }
                        /* We are done with our cleanup */

                        KeyIO->io_Data=(APTR)keyHandler;
                        KeyIO->io_Command=KBD_RESETHANDLERDONE;
                        DoIO((struct IORequest *)KeyIO);
                        /*
                         * Note that since the above call
                         * tells the system it is safe to reboot
                         * and will cause the reboot if this
                         * task was the last to say so, the call
                         * never really returns...  The system
                         * just reboots...
                         */
                        }

                    KeyIO->io_Data=(APTR)keyHandler;
                    KeyIO->io_Command=KBD_REMRESETHANDLER;
                    DoIO((struct IORequest *)KeyIO);

                    CloseDevice((struct IORequest *)KeyIO);
                    }
                else
                    printf("Error: Could not open keyboard.device\n");

                DeleteExtIO((struct IORequest *)KeyIO);
                }
            else
                printf("Error: Could not create I/O request\n");

            FreeMem(keyHandler,sizeof(struct Interrupt));
            }
        else
            printf("Error: Could not allocate memory for interrupt\n");

        DeletePort(KeyMP);
        }
    else
        printf("Error: Could not create message port\n");

    FreeSignal(MySignal);
    }
```
else
```c
    printf("Error: Could not allocate signal\n");
```
}
\kern -20pt
************************************************************************
*       KeyHandler.a
*
* Keyboard reset handler that signals the task in the structure...
*
* See Key_Reset.c for details on how to compile/assemble/link...
*
************************************************************************
* Required includes...
*
        INCDIR  "include:"
        INCLUDE "exec/types.i"
        INCLUDE "exec/io.i"
        INCLUDE "devices/keyboard.i"
*
```c
        xref    _AbsExecBase    ; We get this from outside...
        xref    _LVOSignal      ; We get this from outside...
```
*
************************************************************************
* Make the entry point external...
*
        xdef    _ResetHandler
*
************************************************************************
*
* This is the input handler
* The is_Data field is passed to you in a1.
*
* This is the structure that is passed in A1 in this example...
*
        STRUCTURE       MyData,0
        APTR            MyTask
        ULONG           MySignal
*
************************************************************************
* The handler gets called here...
*
_ResetHandler:  move.l  MySignal(a1),d0 ; Get signal to send
```c
                move.l  MyTask(a1),a1           ; Get task
```
*
* Now signal the task...
*
```c
                move.l  a6,-(sp)        ; Save the stack...
                move.l  _AbsExecBase,a6 ; Get ExecBase
                jsr     _LVOSignal(a6)  ; Send the signal
                move.l  (sp)+,a6        ; Restore A6
```
*
* Return to let other handlers execute.
*
```c
                rts                     ; return from handler...
```
*
                END
************************************************************************


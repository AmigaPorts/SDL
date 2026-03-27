---
title: Devices/Dev_examples/Keyboard_Events.c
manual: devices
chapter: devices
section: devices-dev-examples-keyboard-events-c
functions: []
libraries: []
---

# Devices/Dev_examples/Keyboard_Events.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* Shown below is an example keyboard.device read-event program:   */
/*
 * Keyboard_Events.c
 *
 * This example does not work very well in a system where
 * input.device is active since input.device also actively calls for
 * keyboard events via this call. For that reason, you will not get all of
 * the keyboard events. Neither will the input device;no one will be happy.
 *
 * Compile with SAS 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/io.h>
#include <exec/ports.h>
#include <exec/memory.h>
#include <devices/inputevent.h>
#include <devices/keyboard.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

VOID Display_Event(struct InputEvent *keyEvent)
{
printf("Got key event: KeyCode: %2x  Quailifiers: %4x\n",
```c
               keyEvent->ie_Code,
               keyEvent->ie_Qualifier);
```
}

VOID main(int argc, char *argv[])
{
struct IOStdReq   *keyRequest;
struct MsgPort    *keyPort;
struct InputEvent *keyEvent;

```c
       SHORT      loop;
```
if (keyPort=CreatePort(NULL,NULL))
  {
  if (keyRequest=
```c
          (struct IOStdReq *)CreateExtIO(keyPort,sizeof(struct IOStdReq)))
      {
      if (!OpenDevice("keyboard.device",NULL,
                        (struct IORequest *)keyRequest,NULL))
          {
          if (keyEvent=AllocMem(sizeof(struct InputEvent),MEMF_PUBLIC))
              {
              for (loop=0;loop<4;loop++)
                   {
                   keyRequest->io_Command=KBD_READEVENT;
                   keyRequest->io_Data=(APTR)keyEvent;

                   /*
                    * We want 1 event, so we just set the
                    * length field to the size, in bytes
                    * of the event.  For multiple events,
                    * set this to a multiple of that size.
                    * The keyboard device NEVER fills partial
                    * events...
                    */

                   keyRequest->io_Length=sizeof(struct InputEvent);
                   DoIO((struct IORequest *)keyRequest);

                       /* Check for CLI startup... */
                   if (argc)
                       Display_Event(keyEvent);
                   }

              FreeMem(keyEvent,sizeof(struct InputEvent));
              }
          else
              printf("Error:Could not allocate memory for InputEvent\n");

          CloseDevice((struct IORequest *)keyRequest);
          }
      else
          printf("Error: Could not open keyboard.device\n");

      DeleteExtIO((struct IORequest *)keyRequest);
      }
```
  else

```c
      printf("Error: Could not create I/O request\n");
```
  DeletePort(keyPort);
  }
  else
```c
    printf("Error: Could not create message port\n");
```
}


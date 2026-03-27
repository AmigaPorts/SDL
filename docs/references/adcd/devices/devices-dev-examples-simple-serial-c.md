---
title: Devices/Dev_examples/Simple_Serial.c
manual: devices
chapter: devices
section: devices-dev-examples-simple-serial-c
functions: [AbortIO, CreateMsgPort, DoIO, OpenDevice, SendIO]
libraries: [exec.library, timer.device]
---

# Devices/Dev_examples/Simple_Serial.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Simple_Serial.c
 *
 * This is an example of using the serial device.  First, we will attempt
 * to create a message port with CreateMsgPort().  Next, we will attempt
 * to create the IORequest with CreateExtIO().  Then, we will attempt to
 * open the serial device with OpenDevice().  If successful, we will write
 * a NULL-terminated string to it and reverse our steps.  If we encounter
 * an error at any time, we will gracefully exit.
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/io.h>
#include <devices/serial.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void main(void)
{
struct MsgPort *SerialMP;       /* pointer to our message port */
struct IOExtSer *SerialIO;      /* pointer to our IORequest */

/* Create the message port */
if (SerialMP=CreateMsgPort())
```c
    {
    /* Create the IORequest */
    if (SerialIO = (struct IOExtSer *)
                    CreateExtIO(SerialMP,sizeof(struct IOExtSer)))
        {
        /* Open the serial device */
        if (OpenDevice(SERIALNAME,0,(struct IORequest *)SerialIO,0L))

            /* Inform user that it could not be opened */
            printf("Error: %s did not open\n",SERIALNAME);
        else
            {
            /* device opened, write NULL-terminated string */
            SerialIO->IOSer.io_Length   = -1;
            SerialIO->IOSer.io_Data     = (APTR)"Amiga ";
            SerialIO->IOSer.io_Command  = CMD_WRITE;
            if (DoIO((struct IORequest *)SerialIO))     /* execute write */
                printf("Write failed.  Error - %ld\n",SerialIO->IOSer.io_Error);

            /* Close the serial device */
            CloseDevice((struct IORequest *)SerialIO);
            }
        /* Delete the IORequest */
        DeleteExtIO(SerialIO);
        }
    else
        /* Inform user that the IORequest could be created */
        printf("Error: Could create IORequest\n");

    /* Delete the message port */
    DeleteMsgPort(SerialMP);
    }
```
else
```c
    /* Inform user that the message port could not be created */
    printf("Error: Could not create message port\n");
```
}

/*
   DoIO() vs. SendIO().
   --------------------
   The above example code contains some simplifications.  The DoIO()
   function in the example is not always appropriate for executing the
   CMD_READ or CMD_WRITE commands.  DoIO() will not return until the I/O
   request has finished.  With serial handshaking enabled, a write
   request may never finish.  Read requests will not finish until
   characters arrive at the serial port.  The following sections will
   demonstrate a solution using the SendIO() and AbortIO() functions.

*/

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)

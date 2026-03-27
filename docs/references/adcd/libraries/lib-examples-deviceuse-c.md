---
title: Lib_examples/DeviceUse.c
manual: libraries
chapter: libraries
section: lib-examples-deviceuse-c
functions: [CreateIORequest, CreateMsgPort, DeleteIORequest, DeleteMsgPort, DoIO, GetMsg, OpenDevice, SendIO, Wait, WaitPort]
libraries: [exec.library]
---

# Lib_examples/DeviceUse.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* DeviceUse.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 DeviceUse.c
Blink FROM LIB:c.o,DeviceUse.o TO DeviceUse LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

/* The following short example demonstrates use of an Amiga device.  The */
/* example opens the serial.device and then demonstrates both            */
/* synchronous (DoIO()) and asynchronous (SendIO()) use of the serial    */
/* command SDCMD_QUERY.  This command is used to determine the status of */
/* the serial device lines and registers.  The example uses the backward */
/* compatible amiga.lib functions for creation and deletion of the       */
/* message port and I/O request.                                         */

/* DeviceUse.c - an example of using an Amiga device (here, serial device)    */
/*    - attempt to create a message port with CreatePort()   (from amiga.lib) */
/*    - attempt to create the I/O request with CreateExtIO() (from amiga.lib) */
/*    - attempt to open the serial device with Exec OpenDevice()              */
/*                                                                            */
/* If successful, use the serial command SDCMD_QUERY, then reverse our steps. */
/* If we encounter an error at any time, we will gracefully exit.  Note that  */
/* applications which require at least V37 OS should use the Exec functions   */
/* CreateMsgPort()/DeleteMsgPort() and CreateIORequest()/DeleteIORequest()    */
/* instead of the similar amiga.lib functions which are used in this example. */

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/io.h>
#include <devices/serial.h>

#include <clib/exec_protos.h> /* Prototypes for Exec library functions */
#include <clib/alib_protos.h> /* Prototypes for amiga.lib functions    */

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void main(void)
{
```c
    struct MsgPort  *serialMP;      /* for pointer to our message port */
    struct IOExtSer *serialIO;      /* for pointer to our I/O request  */
    struct IOExtSer *reply;         /* for use with GetMsg             */

    if (serialMP=CreatePort(NULL,NULL)) /* Create the message port. */
    {
        /* Create the I/O request. Note that <devices/serial.h> defines the type */
        /* of IORequest required by the serial device--an IOExtSer. Many devices */
        /* require specialized extended IO requests which start with an embedded */
        /* struct IORequest. The generic Exec and amiga.lib device IO functions  */
        /* are prototyped for IORequest, so some pointer casting is necessary.   */

        if (serialIO = (struct IOExtSer *)CreateExtIO(serialMP,sizeof(struct IOExtSer)))
        {
            /* Open the serial device (non-zero return value means failure here). */
            if (OpenDevice( SERIALNAME, 0, (struct IORequest *)serialIO, 0L))
                printf("Error: %s did not open\n",SERIALNAME);
            else
            {
                /* Device is open */                         /* DoIO - demonstrates synchronous */
                serialIO->IOSer.io_Command  = SDCMD_QUERY;   /* device use, returns error or 0. */
                if (DoIO((struct IORequest *)serialIO))
                    printf("Query  failed. Error - %d\n",serialIO->IOSer.io_Error);
                else
                    /* Print serial device status - see include file for meaning */
                    /* Note that with DoIO, the Wait and GetMsg are done by Exec */
                    printf("Serial device status: $%x\n\n",serialIO->io_Status);

                serialIO->IOSer.io_Command  = SDCMD_QUERY; /* SendIO - demonstrates asynchronous */
                SendIO((struct IORequest *)serialIO);      /* device use (returns immediately).  */

                /* We could do other things here while the query is being done.      */
                /* And to manage our asynchronous device IO:                         */
                /*   - we can CheckIO(serialIO) to check for completion              */
                /*   - we can AbortIO(serialIO) to abort the command                 */
                /*   - we can WaitPort(serialMP) to wait for any serial port reply   */
                /*  OR we can WaitIO(serialIO) to wait for this specific IO request  */
                /*  OR we can Wait(1L << serialMP_>mp_SigBit) for reply port signal  */

                Wait(1L << serialMP->mp_SigBit);

                while(reply = (struct IOExtSer *)GetMsg(serialMP))
                {    /* Since we sent out only one serialIO request the while loop is */
                     /* not really needed--we only expect one reply to our one query  */
                     /* command, and the reply message pointer returned by GetMsg()   */
                     /* will just be another pointer to our one serialIO request.     */
                     /* With Wait() or WaitPort(), you must GetMsg() the message.     */
                    if(reply->IOSer.io_Error)
                        printf("Query  failed. Error - %d\n",reply->IOSer.io_Error);
                    else
                        printf("Serial device status: $%x\n\n",reply->io_Status);
                }
                CloseDevice((struct IORequest *)serialIO);  /* Close the serial device.    */
            }
            DeleteExtIO(serialIO);                          /* Delete the I/O request.     */
        }
        else printf("Error: Could create I/O request\n");   /* Inform user that the I/O    */
                                                            /* request could be created.   */
        DeletePort(serialMP);                               /* Delete the message port.    */
    }
    else printf("Error: Could not create message port\n");  /* Inform user that the message*/
```
}                                                           /* port could not be created.  */

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)

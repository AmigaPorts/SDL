---
title: Devices/Dev_examples/Pre_V36_Device_Use.c
manual: devices
chapter: devices
section: devices-dev-examples-pre-v36-device-use-c
functions: [OpenDevice]
libraries: [exec.library]
---

# Devices/Dev_examples/Pre_V36_Device_Use.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Pre_V36_Device_Use.c
 *
 * This is an example of using the serial device.
 * First, we will attempt to create a message port with CreatePort()
 * Next, we will attempt to create the I/O request with CreateExtIO()
 * Then, we will attempt to open the serial device with OpenDevice()
 * If successful, we will send the SDCMD_QUERY command to it
 * and reverse our steps.
 * If we encounter an error at any time, we will gracefully exit.
 *
 * Compile with SAS C 5.10  lc -cfistq -v -y -L
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
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void main(void)
{
struct MsgPort *SerialMP;       /* pointer to our message port */
struct IOExtSer *SerialIO;      /* pointer to our I/O request */

    /* Create the message port */
if (SerialMP=CreatePort(NULL,NULL))
```c
    {
        /* Create the I/O request */
    if (SerialIO = (struct IOExtSer *)CreateExtIO(SerialMP,sizeof(struct IOExtSer)))
        {
            /* Open the serial device */
        if (OpenDevice(SERIALNAME,0,(struct IORequest *)SerialIO,0L))

            /* Inform user that it could not be opened */
            printf("Error: %s did not open\n",SERIALNAME);
        else
            {
            /* device opened, send query command to it */
            SerialIO->IOSer.io_Command  = SDCMD_QUERY;
            if (DoIO((struct IORequest *)SerialIO))

                /* Inform user that query failed */
                printf("Query  failed. Error - %d\n",SerialIO->IOSer.io_Error);
            else
                /* Print serial device status - see include file for meaning */
                printf("\n\tSerial device status: %x\n\n",SerialIO->io_Status);

            /* Close the serial device */
            CloseDevice((struct IORequest *)SerialIO);
            }
        /* Delete the I/O request */
        DeleteExtIO(SerialIO);
        }
    else
        /* Inform user that the I/O request could be created */
        printf("Error: Could create I/O request\n");

    /* Delete the message port */
    DeletePort(SerialMP);
    }
```
else
```c
    /* Inform user that the message port could not be created */
    printf("Error: Could not create message port\n");
```
}

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)

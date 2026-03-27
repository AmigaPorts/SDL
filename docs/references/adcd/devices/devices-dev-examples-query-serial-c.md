---
title: Devices/Dev_examples/Query_Serial.c
manual: devices
chapter: devices
section: devices-dev-examples-query-serial-c
functions: []
libraries: []
---

# Devices/Dev_examples/Query_Serial.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Query_Serial.c
 *
 * We will try to open the serial device and if unsuccessful,
 * will return the name of the owner.
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <resources/misc.h>
#include <devices/serial.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/dos_protos.h>
#include <clib/misc_protos.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *MiscBase;

struct MsgPort  *SerialMP;         /* Message port pointer */
struct IOExtSer *SerialIO;         /* I/O request pointer */

void main(void)
{
UWORD status;    /* return value of SDCMD_QUERY */
UBYTE *user;     /* name of serial port owner if not us */

if (SerialMP=CreatePort(NULL,NULL) )
```c
    {
    if (SerialIO=(struct IOExtSer *)CreateExtIO(SerialMP,sizeof(struct IOExtSer)) )
        {
        if (OpenDevice(SERIALNAME,0L,(struct IORequest *)SerialIO,0))
            {
            printf("\n%s did not open",SERIALNAME);

            MiscBase= (struct Library *)OpenResource(MISCNAME);

            /* Find out who has the serial device */
            if ((user = AllocMiscResource(MR_SERIALPORT,"Us")) == NULL)
                {
                printf("\n");
                FreeMiscResource(MR_SERIALPORT);
                }
            else
                printf(" because %s owns it \n\n",user);
            }
        else
            {
            SerialIO->IOSer.io_Command  = SDCMD_QUERY;
            DoIO((struct IORequest *)SerialIO);             /* execute query */

            status = SerialIO->io_Status;                    /* store returned status */

            printf("\tThe serial port status is %x\n",status);

            CloseDevice((struct IORequest *)SerialIO);
            }

        DeleteExtIO(SerialIO);
        }
    else
        printf("Can't create I/O request\n");

    DeletePort(SerialMP);
    }
```
else
```c
    printf("Can't create message port\n");
```
}


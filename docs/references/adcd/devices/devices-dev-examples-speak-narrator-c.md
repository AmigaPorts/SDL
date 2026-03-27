---
title: Devices/Dev_examples/Speak_Narrator.c
manual: devices
chapter: devices
section: devices-dev-examples-speak-narrator-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# Devices/Dev_examples/Speak_Narrator.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Speak_Narrator.c
 *
 * This example program sends a string of phonetic text to the narrator
 * device twice, changing some of the characteristics the second time.
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Requires Kickstart V37 or greater.
 */

#include <exec/types.h>
#include <exec/exec.h>
#include <dos/dos.h>
#include <devices/narrator.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/dos_protos.h>

#include <string.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void main(void)
{
struct  MsgPort     *VoiceMP;
struct  narrator_rb *VoiceIO;
UBYTE   *PhoneticText    = "DHIHS IHZ AHMIY5GAH SPIY5KIHNX.";
BYTE    audio_chan[4]   = {3, 5, 10, 12};

if (VoiceMP=CreateMsgPort())  /* Create the message port */
  {                           /* Create the I/O request */
  if (VoiceIO = CreateIORequest(VoiceMP,sizeof(struct narrator_rb)))
```c
    {
    /*Set the NEWIORB bit in the flags field to use the new fields*/
    VoiceIO->flags = NDF_NEWIORB;

    /* Open the narrator device */
    if (OpenDevice("narrator.device",0,(struct IORequest *)VoiceIO,0L))
        /* Inform user that it could not be opened */
        printf("Error: narrator.device did not open\n");
    else
        {
         /* Speak the string using the default parameters */
         VoiceIO->ch_masks = &audio_chan[0];
         VoiceIO->nm_masks = sizeof(audio_chan);
         VoiceIO->message.io_Command = CMD_WRITE;
         VoiceIO->message.io_Data = PhoneticText;
         VoiceIO->message.io_Length = strlen(PhoneticText);
         DoIO(VoiceIO);

         /* Now change some of the characteristics:
          *    Raise the first formant, lower the third formant,
          *    and move 50% of the way towards AO.
          * and speak it again.
          */

        VoiceIO->A1adj = -32;          /* Shut off first formant  */
        VoiceIO->A3adj =  11;          /* Raise the third formant */
        VoiceIO->centralize = 50;      /* Move 50% of the way     */
        VoiceIO->centphon = "AO";      /* towards AO              */
        DoIO(VoiceIO);

        /* Close the narrator device */
        CloseDevice((struct IORequest *)VoiceIO);
        }
    /* Delete the IORequest */
    DeleteIORequest(VoiceIO);
    }
```
  else

```c
    /* Inform user that the I/O request could be created */
    printf("Error: Could not create I/O request\n");
```
  /* Delete the message port */
  DeleteMsgPort(VoiceMP);
  }
else
  /* Inform user that the message port could not be created */
  printf("Error: Could not create message port\n");
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)

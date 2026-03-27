---
title: Devices/Dev_examples/Audio.c
manual: devices
chapter: devices
section: devices-dev-examples-audio-c
functions: [WaitPort]
libraries: [exec.library]
---

# Devices/Dev_examples/Audio.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Audio.c
 *
 * Audio example
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <devices/audio.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <graphics/gfxbase.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/dos_protos.h>
#include <clib/graphics_protos.h>

#include <stdlib.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct GfxBase *GfxBase;

/*-----------------------------------------------------------*/
/* The whichannel array is used when we allocate a channel.  */
/* It tells the audio device which channel we want. The code */
/* is 1 =channel0, 2 =channel1, 4 =channel2, 8 =channel3.    */
/* If you want more than one channel, add the codes up.      */
/* This array says "Give me channel 0. If it's not available */
/* then try channel 1; then try channel 2 and then channel 3 */
/*-----------------------------------------------------------*/
UBYTE           whichannel[] = { 1,2,4,8 };

void main(int argc, char **argv)
{
struct IOAudio *AudioIO;    /* Pointer to the I/O block for I/O commands */
struct MsgPort *AudioMP;    /* Pointer to a port so the device can reply */
struct Message *AudioMSG;   /* Pointer for the reply message             */
ULONG           device;
BYTE           *waveptr;              /* Pointer to the sample bytes     */
LONG            frequency = 440;      /* Frequency of the tone desired   */
LONG            duration  = 3;        /* Duration in seconds             */
LONG            clock     = 3579545;  /* Clock constant, 3546895 for PAL */
LONG            samples   = 2;        /* Number of sample bytes          */
LONG            samcyc    = 1;        /* Number of cycles in the sample  */

/*-----------------------------------------------------------------------*/
/* Ask the system if it is PAL or NTSC and set clock constant accordingly*/
/*-----------------------------------------------------------------------*/
GfxBase = (struct GfxBase *)OpenLibrary("graphics.library",0L);
if (GfxBase == 0L)
```c
    goto killaudio;
```
if (GfxBase->DisplayFlags & PAL)
```c
    clock = 3546895;        /* PAL clock */
```
else

```c
    clock = 3579545;        /* NTSC clock */
```
if (GfxBase)

```c
    CloseLibrary((struct Library *) GfxBase);
```
/*-----------------------------------------------------------------------*/
/*  Create an audio I/O block so we can send commands to the audio device*/
/*-----------------------------------------------------------------------*/
AudioIO = (struct IOAudio *)
```c
           AllocMem( sizeof(struct IOAudio),MEMF_PUBLIC | MEMF_CLEAR);
```
if (AudioIO == 0)
```c
    goto killaudio;
```
printf("IO block created...\n");

/*-------------------------------------------------------------------*/
/* Create a reply port so the audio device can reply to our commands */
/*-------------------------------------------------------------------*/
AudioMP = CreatePort(0,0);
if (AudioMP == 0)
```c
    goto killaudio;
```
printf("Port created...\n");

/*----------------------------------------------------------------------*/
/* Set up the audio I/O block for channel allocation:                   */
/* ioa_Request.io_Message.mn_ReplyPort is the address of a reply port.  */
/* ioa_Request.io_Message.mn_Node.ln_Pri sets the precedence (priority) */
/*   of our use of the audio device. Any tasks asking to use the audio  */
/*   device that have a higher precedence will steal the channel from us.*/
/* ioa_Request.io_Command is the command field for I/O.                  */
/* ioa_Request.io_Flags is used for the I/O flags.                       */
/* ioa_AllocKey will be filled in by the audio device if the allocation */
/*   succeeds. We must use the key it gives for all other commands sent.*/
/* ioa_Data is a pointer to the array listing the channels we want.     */
/* ioa_Length tells how long our list of channels is.                   */
/*----------------------------------------------------------------------*/
AudioIO->ioa_Request.io_Message.mn_ReplyPort   = AudioMP;
AudioIO->ioa_Request.io_Message.mn_Node.ln_Pri = 0;
AudioIO->ioa_Request.io_Command                = ADCMD_ALLOCATE;
AudioIO->ioa_Request.io_Flags                  = ADIOF_NOWAIT;
AudioIO->ioa_AllocKey                          = 0;
AudioIO->ioa_Data                              = whichannel;
AudioIO->ioa_Length                            = sizeof(whichannel);
printf("I/O block initialized for channel allocation...\n");

/*-----------------------------------------------*/
/* Open the audio device and allocate a channel  */
/*-----------------------------------------------*/
device = OpenDevice(AUDIONAME,0L, (struct IORequest *) AudioIO ,0L);
if (device != 0)
```c
    goto killaudio;
```
printf("%s opened, channel allocated...\n",AUDIONAME);

/*----------------------------------------------*/
/* Create a very simple audio sample in memory. */
/* The sample must be CHIP RAM                  */
/*----------------------------------------------*/
waveptr = (BYTE *)AllocMem( samples , MEMF_CHIP|MEMF_PUBLIC);
if (waveptr == 0)
```c
    goto killaudio;
```
waveptr[0] =  127;
waveptr[1] = -127;
printf("Wave data ready...\n");

/*------------------------------------------------------------*/
/* Set up audio I/O block to play a sample using CMD_WRITE.   */
/* The io_Flags are set to ADIOF_PERVOL so we can set the     */
/*    period (speed) and volume with the our sample;          */
/* ioa_Data points to the sample; ioa_Length gives the length */
/* ioa_Cycles tells how many times to repeat the sample       */
/* If you want to play the sample at a given sampling rate,   */
/* set ioa_Period = clock/(given sampling rate)               */
/*------------------------------------------------------------*/
AudioIO->ioa_Request.io_Message.mn_ReplyPort =AudioMP;
AudioIO->ioa_Request.io_Command          =CMD_WRITE;
AudioIO->ioa_Request.io_Flags            =ADIOF_PERVOL;
AudioIO->ioa_Data                        =(BYTE *)waveptr;
AudioIO->ioa_Length                      =samples;
AudioIO->ioa_Period                      =clock*samcyc/(samples*frequency);
AudioIO->ioa_Volume                      =64;
AudioIO->ioa_Cycles                      =frequency*duration/samcyc;
printf("I/O block initialized to play tone...\n");

/*-------------------------------------------------------*/
/* Send the command to start a sound using BeginIO()     */
/* Go to sleep and wait for the sound to finish with     */
/* WaitPort().  When we wake-up we have to get the reply */
/*-------------------------------------------------------*/
printf("Starting tone now...\n");
BeginIO((struct IORequest *) AudioIO );
WaitPort(AudioMP);
AudioMSG = GetMsg(AudioMP);

printf("Sound finished...\n");

killaudio:

printf("Killing audio device...\n");
if (waveptr != 0)
```c
    FreeMem(waveptr, 2);
```
if (device == 0)
```c
    CloseDevice( (struct IORequest *) AudioIO );
```
if (AudioMP != 0)
```c
    DeletePort(AudioMP);
```
if (AudioIO != 0)
```c
    FreeMem( AudioIO,sizeof(struct IOAudio) );
```
}

---

## See Also

- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)

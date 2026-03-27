---
title: Devices/Dev_examples/Audio_8SVX.c
manual: devices
chapter: devices
section: devices-dev-examples-audio-8svx-c
functions: [Wait]
libraries: [exec.library]
---

# Devices/Dev_examples/Audio_8SVX.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Audio_8SVX.c
 *
 * 8SVX example - double buffers >128K samples
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
#include <iff/iff.h>
#include <iff/8svx.h>

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

#define VHDR MakeID('V','H','D','R')
#define BODY MakeID('B','O','D','Y')
#define MY8S MakeID('8','S','V','X')

void              kill8svx(char *);
void              kill8(void);

/*--------------------*/              /* These globals are needed */
/*   G L O B A L S    */              /* by the clean up routines */
/*--------------------*/
struct IOAudio     *AIOptr1,          /* Pointers to Audio IOBs      */
```c
                   *AIOptr2,
                   *Aptr;
```
struct Message     *msg;              /* Msg, port and device for    */
struct MsgPort     *port,             /* driving audio               */

```c
                   *port1,*port2;
       ULONG        device;
       UBYTE       *sbase,*fbase;     /* For sample memory allocation */
       ULONG        fsize,ssize;      /* and freeing                  */
```
struct FileHandle  *v8handle;

```c
       UBYTE        chan1[]  = {  1 };/* Audio channel allocation arrays */
       UBYTE        chan2[]  = {  2 };
       UBYTE        chan3[]  = {  4 };
       UBYTE        chan4[]  = {  8 };
       UBYTE       *chans[] = {chan1,chan2,chan3,chan4};

       BYTE         oldpri,c;         /* Stuff for bumping priority */
```
struct Task        *mt=0L;
struct GfxBase     *GfxBase = NULL;


/*-----------*/
/*  M A I N  */
/*-----------*/

void main(int argc,char **argv)
{

/*-------------*/
/* L O C A L S */
/*-------------*/


```c
       char         *fname;               /* File name and data pointer*/
       UBYTE        *p8data;              /* for file read.            */
       ULONG         clock;               /* Clock constant            */
       ULONG         length[2];           /* Sample lengths            */
       BYTE          iobuffer[8],         /* Buffer for 8SVX header    */
                    *psample[2];          /* Sample pointers           */
       Chunk        *p8Chunk;             /* Pointers for 8SVX parsing */
       Voice8Header *pVoice8Header;
       ULONG         y,rd8count,speed;    /* Counters, sampling speed  */
       ULONG         wakebit;             /* A wakeup mask             */
```
/*-------------*/
/*   C O D E   */
/*-------------*/

/*------------------------------*/
/* Check Arguments, Initialize  */
/*------------------------------*/

fbase=0L;
sbase=0L;
AIOptr1=0L;
AIOptr2=0L;
port=0L;
port1=0L;
port2=0L;
v8handle=0L;
device=1L;

if (argc < 2)
```c
    {
    kill8svx("No file name given.\n");
    exit(1L);
    }
```
fname=argv[1];

/*---------------------------*/
/* Initialize Clock Constant */
/*---------------------------*/

GfxBase=(struct GfxBase *)OpenLibrary("graphics.library",0L);
if (GfxBase==0L)

```c
    {
    puts("Can't open graphics library\n");
    exit(1L);
    }
```
if (GfxBase->DisplayFlags & PAL)
```c
    clock=3546895L;        /* PAL clock */
```
else

```c
    clock=3579545L;        /* NTSC clock */
```
if (GfxBase)

```c
    CloseLibrary( (struct Library *) GfxBase);
```
/*---------------*/
/* Open the File */
/*---------------*/

v8handle= (struct FileHandle *) Open(fname,MODE_OLDFILE);
if (v8handle==0)

```c
    {
    kill8svx("Can't open 8SVX file.\n");
    exit(1L);
    }
```
/*-------------------------------------------*/
/* Read the 1st 8 Bytes of the File for Size */
/*-------------------------------------------*/
rd8count=Read((BPTR)v8handle,iobuffer,8L);
if (rd8count==-1)

```c
    {
    kill8svx ("Read error.\n");
    exit(1L);
    }
```
if (rd8count<8)

```c
    {
    kill8svx ("Not an IFF 8SVX file, too short\n");
    exit(1L);
    }
```
/*-----------------*/
/* Evaluate Header */
/*-----------------*/
p8Chunk=(Chunk *)iobuffer;
if (p8Chunk->ckID != FORM )

```c
    {
    kill8svx("Not an IFF FORM.\n");
    exit(1L);
    }
```
/*--------------------------------------------*/
/* Allocate Memory for File and Read it in.   */
/*--------------------------------------------*/
fbase= (UBYTE *)AllocMem(fsize=p8Chunk->ckSize , MEMF_PUBLIC|MEMF_CLEAR);
if (fbase==0)

```c
    {
    kill8svx("No memory for read.\n");
    exit(1L);
    }
```
p8data=fbase;

rd8count=Read((BPTR)v8handle,p8data,p8Chunk->ckSize);
if (rd8count==-1)

```c
    {
    kill8svx ("Read error.\n");
    exit(1L);
    }
```
if (rd8count<p8Chunk->ckSize)

```c
    {
    kill8svx ("Malformed IFF, too short.\n");
    exit(1L);
    }
```
/*-------------------*/
/* Evaluate IFF Type */
/*-------------------*/
if (MakeID( *p8data, *(p8data+1) , *(p8data+2) , *(p8data+3) ) != MY8S )

```c
    {
    kill8svx("Not an IFF 8SVX file.\n");
    exit(1L);
    }
```
/*----------------------*/
/* Evaluate 8SVX Chunks */
/*----------------------*/
p8data=p8data+4;

while( p8data < fbase+fsize )
  {
  p8Chunk=(Chunk *)p8data;

  switch(p8Chunk->ckID)

```c
    {
    case VHDR:
      /*------------------------------------------------*/
      /* Get a pointer to the 8SVX header for later use */
      /*------------------------------------------------*/
      pVoice8Header=(Voice8Header *)(p8data+8L);
      break;

    case BODY:
      /*-------------------------------------------------*/
      /* Create pointers to 1-shot and continuous parts  */
      /* for the top octave and get length. Store them.  */
      /*-------------------------------------------------*/
        psample[0] = (BYTE *)(p8data + 8L);
        psample[1] = psample[0] + pVoice8Header->oneShotHiSamples;
        length[0] = (ULONG)pVoice8Header->oneShotHiSamples;
        length[1] = (ULONG)pVoice8Header->repeatHiSamples;
        break;

    default:
      break;
    }
    /* end switch */
```
  p8data = p8data + 8L + p8Chunk->ckSize;

  if (p8Chunk->ckSize&1L == 1)
```c
      p8data++;
```
  }

/* Play either the one-shot or continuous, not both */
if (length[0]==0)
```c
    y=1;
```
else

```c
    y=0;
```
/*---------------------------------------*/
/* Allocate chip memory for samples and  */
/* copy from read buffer to chip memory. */
/*---------------------------------------*/
if (length[y]<=102400)
```c
    ssize=length[y];
```
else

```c
    ssize=102400;
```
sbase=(UBYTE *)AllocMem( ssize , MEMF_CHIP | MEMF_CLEAR);
if (sbase==0)

```c
    {
    kill8svx("No chip memory.\n");
    exit(1L);
    }
```
CopyMem(psample[y],sbase,ssize);
psample[y]+=ssize;

/*----------------------------------*/
/* Calculate playback sampling rate */
/*----------------------------------*/
speed =  clock / pVoice8Header->samplesPerSec;

/*-------------------*/
/* Bump our priority */
/*-------------------*/
mt=FindTask(NULL);
oldpri=SetTaskPri(mt,21);

/*--------------------------------*/
/* Allocate two audio I/O blocks  */
/*--------------------------------*/
AIOptr1=(struct IOAudio *)
```c
      AllocMem( sizeof(struct IOAudio),MEMF_PUBLIC|MEMF_CLEAR);
```
if (AIOptr1==0)

```c
    {
    kill8svx("No IO memory\n");
    exit(1L);
    }
```
AIOptr2=(struct IOAudio *)
```c
      AllocMem( sizeof(struct IOAudio),MEMF_PUBLIC|MEMF_CLEAR);
```
if (AIOptr2==0)

```c
    {
    kill8svx("No IO memory\n");
    exit(1L);
    }
```
/*----------------------*/
/* Make two reply ports */
/*----------------------*/

port1=CreatePort(0,0);
if (port1==0)

```c
    {
    kill8svx("No port\n");
    exit(1L);
    }
```
port2=CreatePort(0,0);
if (port2==0)

```c
    {
    kill8svx("No port\n");
    exit(1L);
    }
```
c=0;
while(device!=0 && c<4)
  {
  /*---------------------------------------*/
  /* Set up audio I/O block for channel    */
  /* allocation and Open the audio device  */
  /*---------------------------------------*/
  AIOptr1->ioa_Request.io_Message.mn_ReplyPort   = port1;
  AIOptr1->ioa_Request.io_Message.mn_Node.ln_Pri = 127;  /* No stealing! */
  AIOptr1->ioa_AllocKey                          = 0;
  AIOptr1->ioa_Data                              = chans[c];
  AIOptr1->ioa_Length                            = 1;

  device=OpenDevice(AUDIONAME,0L,(struct IORequest *)AIOptr1,0L);
  c++;
  }

if (device!=0)

```c
    {
    kill8svx("No channel\n");
    exit(1L);
    }
```
/*-------------------------------------------*/
/* Set Up Audio IO Blocks for Sample Playing */
/*-------------------------------------------*/

AIOptr1->ioa_Request.io_Command   =CMD_WRITE;
AIOptr1->ioa_Request.io_Flags     =ADIOF_PERVOL;

/*--------*/
/* Volume */
/*--------*/

AIOptr1->ioa_Volume=60;

/*---------------*/
/* Period/Cycles */
/*---------------*/

AIOptr1->ioa_Period =(UWORD)speed;
AIOptr1->ioa_Cycles =1;

*AIOptr2 = *AIOptr1;   /* Make sure we have the same allocation keys, */

```c
                       /* same channels selected and same flags       */
                       /* (but different ports...)                    */
```
AIOptr1->ioa_Request.io_Message.mn_ReplyPort   = port1;
AIOptr2->ioa_Request.io_Message.mn_ReplyPort   = port2;

/*--------*/
/*  Data  */
/*--------*/

AIOptr1->ioa_Data            =(UBYTE *)sbase;
AIOptr2->ioa_Data            =(UBYTE *)sbase + 51200;


/*-----------------*/
/*  Run the sample */
/*-----------------*/

if (length[y]<=102400)
```c
    {
    AIOptr1->ioa_Length=length[y];         /* No double buffering needed */
    BeginIO((struct IORequest *)AIOptr1);  /* Begin the sample, wait for */
    wakebit=0L;                            /* it to finish, then quit.   */
    wakebit=Wait(1 << port1->mp_SigBit);
    while((msg=GetMsg(port1))==0){};
    }
```
else

```c
    {
    length[y]-=102400;                    /* It's a real long sample so  */
    AIOptr1->ioa_Length=51200L;           /* double buffering is needed  */
    AIOptr2->ioa_Length=51200L;
    BeginIO((struct IORequest *)AIOptr1); /* Start up the first 2 blocks */
    BeginIO((struct IORequest *)AIOptr2);
    Aptr=AIOptr1;
    port=port1;                           /* Set the switch... */

    while(length[y]>0)
      {                                   /* Wait() for one IO to finish */
      wakebit=Wait(1 << port->mp_SigBit); /* reuse the IO block & queue  */
      while((msg=GetMsg(port))==0){};     /* it up again while the 2nd IO*/
                                          /* block plays.Switch & repeat */
      /* Set length of next IO block */
      if (length[y]<=51200)
          Aptr->ioa_Length=length[y];
      else
          Aptr->ioa_Length=51200L;

      /* Copy sample fragment from read buffer to chip memory */
      CopyMem(psample[y],Aptr->ioa_Data,Aptr->ioa_Length);

      /* Adjust size and pointer of read buffer*/
      length[y]-=Aptr->ioa_Length;
      psample[y]+=51200;

      BeginIO((struct IORequest *)Aptr);

      if (Aptr==AIOptr1)
          {
          Aptr=AIOptr2;                /* This logic handles switching  */
          port=port2;                  /* between the 2 IO blocks and   */
          }                            /* the 2 ports we are using.     */
      else
          {
          Aptr=AIOptr1;
          port=port1;
          }
      }

    /*-------------------------------------------------*/
    /* OK we are at the end of the sample so just wait */
    /* for the last two parts of the sample to finish  */
    /*-------------------------------------------------*/
    wakebit=Wait(1 << port->mp_SigBit);
    while((msg=GetMsg(port))==0){};
    if (Aptr==AIOptr1)
        {
        Aptr=AIOptr2;                  /* This logic handles switching  */
        port=port2;                    /* between the 2 IO blocks and   */
        }                              /* the 2 ports we are using.     */
    else
        {
        Aptr=AIOptr1;
        port=port1;
        }
    wakebit=Wait(1 << port->mp_SigBit);
    while((msg=GetMsg(port))==0){};
    }
```
kill8();
exit(0L);
}

/*----------------*/
/* Abort the Read */
/*----------------*/
void
kill8svx(kill8svxstring)
char *kill8svxstring;
{
puts(kill8svxstring);
kill8();
}

/*-------------------------*/
/* Return system resources */
/*-------------------------*/
void kill8()
{
if (device ==0)
```c
    CloseDevice((struct IORequest *)AIOptr1);
```
if (port1  !=0)
```c
    DeletePort(port1);
```
if (port2  !=0)
```c
    DeletePort(port2);
```
if (AIOptr1!=0)
```c
    FreeMem( AIOptr1,sizeof(struct IOAudio) );
```
if (AIOptr2!=0)

```c
    FreeMem( AIOptr2,sizeof(struct IOAudio) );
```
if (mt!=0)

```c
    SetTaskPri(mt,oldpri);
```
if (sbase !=0)
```c
    FreeMem (sbase, ssize);
```
if (fbase !=0)
```c
    FreeMem(fbase,fsize);
```
if (v8handle!=0)
```c
    Close((BPTR)v8handle);
```
}

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)

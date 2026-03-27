---
title: Devices/apps/Play8SVX/Play8SVX.c
manual: devices
chapter: devices
section: devices-apps-play8svx-play8svx-c
functions: [AllocIFF, FindProp, WaitIO]
libraries: [exec.library, iffparse.library]
---

# Devices/apps/Play8SVX/Play8SVX.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/** Play8SVX.c **************************************************************
 *
 * Read and play sound sample from an IFF file.  21Jan85
 *
 * By Steve Hayes, Electronic Arts.
 * This software is in the public domain.
 *
 * Modified 05/91 for use with iffparse & to play notes - CAS_CBM
 * requires linkage with several IFF modules - see Makefile
 ****************************************************************************/

#include "iffp/8svxapp.h"

#include <exec/execbase.h>
#include <graphics/gfxbase.h>
#include <clib/alib_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

/* prototypes for our functions */
void cleanup(void);
void bye(UBYTE *s,int error);
void DUnpack(BYTE source[], LONG n, BYTE dest[]);
BYTE D1Unpack(BYTE source[], LONG n, BYTE dest[], BYTE x);
LONG LoadSample(struct EightSVXInfo *esvx, UBYTE *filename);
void UnloadSample(struct EightSVXInfo *esvx);
LONG LoadSBody(struct EightSVXInfo *esvx);
void UnloadSBody(struct EightSVXInfo *esvx);

LONG ShowSample(struct EightSVXInfo *esvx);

LONG OpenAudio(void);
void CloseAudio(void);
LONG PlaySample(struct EightSVXInfo *esvx,
		LONG octave, LONG note, UWORD volume, ULONG delay);

struct IOAudio *playbigsample(struct IOAudio *aio0, struct IOAudio *aio1,
		BYTE *samptr, LONG ssize, ULONG period, UWORD volume);

#define MINARGS 2
char *vers = "\0$VER: Play8SVX 37.5";
char *Copyright = "Play8SVX v37.5 (Freely Redistributable)";
char *usage = "Usage: Play8SVX 8SVXname";


/* globals */
struct Library *IFFParseBase   = NULL;
struct Library *GfxBase = NULL;

BOOL   FromWb;

/* 8SVX Property chunks to be grabbed
 */
LONG	esvxprops[] = {
		ID_8SVX, ID_VHDR,
		ID_8SVX, ID_NAME,
		ID_8SVX, ID_ATAK,
		ID_8SVX, ID_RLSE,
		ID_8SVX, ID_AUTH,
		ID_8SVX, ID_Copyright,
		TAG_DONE
		};

/* 8SVX Collection chunks (more than one in file) to be gathered */
LONG	esvxcollects[] = {
		ID_8SVX, ID_ANNO,
		TAG_DONE
		};

/* 8SVX Chunk to stop on */
LONG	esvxstops[] = {
		ID_8SVX, ID_BODY,
		TAG_DONE
		};


UBYTE nomem[]  = "Not enough memory\n";
UBYTE noiffh[] = "Can't alloc iff\n";



/* For our allocated EightSVXInfo */
struct EightSVXInfo  *esvx = NULL;


/*
 * MAIN
 */
void main(int argc, char **argv)
   {
   UBYTE *esvxname=NULL;
   ULONG oct;
   LONG error=0L;

   FromWb = argc ? FALSE : TRUE;

   if((argc<MINARGS)||(argv[argc-1][0]=='?'))
	{
	printf("%s\n%s\n",Copyright,usage);
```c
        bye("",RETURN_OK);
```
	}

   esvxname = argv[1];

/* Open Libraries */
   if(!(IFFParseBase = OpenLibrary("iffparse.library",0)))


```c
      bye("Can't open iffparse library.\n",RETURN_WARN);
```
/*
 * Alloc one EightSVXInfo struct
 */
```c
    if(!(esvx = (struct EightSVXInfo *)
```
	AllocMem(sizeof(struct EightSVXInfo),MEMF_PUBLIC|MEMF_CLEAR)))
		bye(nomem,RETURN_FAIL);

/*
 * Here we set up our EightSVXInfo fields for our
 * application.
 * Above we have defined the propery and collection chunks
 * we are interested in (some required like VHDR).
 * We want to stop on BODY.
 */
```c
    esvx->ParseInfo.propchks	= esvxprops;
    esvx->ParseInfo.collectchks	= esvxcollects;
    esvx->ParseInfo.stopchks	= esvxstops;
```
/*
 * Alloc the IFF handle for the frame
 */
```c
    if(!(esvx->ParseInfo.iff = AllocIFF())) bye(noiffh,RETURN_FAIL);


    if(!(error = LoadSample(esvx, esvxname)))
```
	{
	ShowSample(esvx);

	if(!(error = OpenAudio()))
	    {
	    /* If we think this is a sound effect, play it as such (note=-1) */
	    if((esvx->Vhdr.ctOctave==1)&&(esvx->Vhdr.samplesPerSec)
		&&(esvx->Vhdr.oneShotHiSamples)&&(!esvx->Vhdr.repeatHiSamples))
		{
		PlaySample(esvx,0,-1,64,0);
		}
	    /* Else play it like an instrument */
	    else
		{
	    	for(oct=0; oct < esvx->Vhdr.ctOctave; oct++)
		    {
	    	    PlaySample(esvx,oct,0,64,50);
	    	    PlaySample(esvx,oct,4,64,50);
	    	    PlaySample(esvx,oct,7,64,50);
		    }
		}
	    CloseAudio();
	    }
```c
        else printf("error opening audio device\n");
```
	}


```c
    else
    	printf("%s\n",IFFerr(error));

    cleanup();
    exit(RETURN_OK);
    }
```
void bye(UBYTE *s,int error)
   {
   if((*s)&&(!FromWb)) printf("%s\n",s);
   cleanup();
   exit(error);
   }


void cleanup()
   {
   if(esvx)
	{
	DD(bug("About to UnloadSample\n"));
	UnloadSample(esvx);

	DD(bug("About to FreeIFF\n"));
	if(esvx->ParseInfo.iff) 	FreeIFF(esvx->ParseInfo.iff);

	DD(bug("About to free EightSVXInfo\n"));
```c
        FreeMem(esvx,sizeof(struct EightSVXInfo));
```
	}

   if(IFFParseBase)  	CloseLibrary(IFFParseBase);
   }


/** ShowSample() **********************************************
 *
 * Show sample information after calling LoadSample()
 *
 *************************************************************************/
LONG ShowSample(struct EightSVXInfo *esvx)


```c
    {
    LONG error = 0L;
    BYTE *buf;
    Voice8Header *vhdr;

    if(!esvx)			return(CLIENT_ERROR);
    if(!(buf = esvx->sample))	return(CLIENT_ERROR);

    /* LoadSample copied VHDR and NAME (if any) to our esvx frame */
    vhdr = &esvx->Vhdr;
    if(esvx->name[0]) printf("\nNAME: %s",esvx->name);

    printf("\n\nVHDR Info:");
    printf("\noneShotHiSamples=%ld", vhdr->oneShotHiSamples);
    printf("\nrepeatHiSamples=%ld", vhdr->repeatHiSamples);
    printf("\nsamplesPerHiCycle=%ld", vhdr->samplesPerHiCycle);
    printf("\nsamplesPerSec=%ld", vhdr->samplesPerSec);
    printf("\nctOctave=%ld", vhdr->ctOctave);
    printf("\nsCompression=%ld", vhdr->sCompression);
    printf("\nvolume=0x%lx", vhdr->volume);
    printf("\nData = %3ld %3ld %3ld %3ld %3ld %3ld %3ld %3ld",
           buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
    printf("\n       %3ld %3ld %3ld %3ld %3ld %3ld %3ld %3ld ...\n",
           buf[8+0],buf[8+1],buf[8+2],buf[8+3],buf[8+4],buf[8+5],
           buf[8+6],buf[8+ 7]);

    return(error);
    }
```
/* OpenAudio
 *
 * Opens audio device for one audio channel, 2 IO requests
 * Returns 0 for success
 *
 * Based on code by Dan Baker
 */

UBYTE           whichannel[] = { 1,2,4,8 };

/* periods for scale starting at   65.40Hz (C) with 128 samples per cycle
 *                            or  130.81Hz (C) with  64 samples per cycle
 *                            or  261.63Hz (C) with  32 samples per cycle
 *                            or  523.25Hz (C) with  16 samples per cycle
 *                            or 1046.50Hz (C) with   8 samples per cycle
 *                            or 2093.00Hz (C) with   4 samples per cycle
 */

UWORD   per_ntsc[12]= { 428, 404, 380, 360,
			340, 320, 302, 286,
			270, 254, 240, 226 };

/* periods adjusted for system clock frequency */
UWORD   per[12];

/* Note - these values 3579545 NTSC, 3546895 PAL */
#define NTSC_CLOCK 3579545L
#define PAL_CLOCK  3546895L

#define AIOCNT 4
struct 	IOAudio *aio[AIOCNT] = {NULL}; 	  /* Ptrs to IO blocks for commands  */

struct 	MsgPort *port;   	/* Pointer to a port so the device can reply */
BOOL	devopened;
ULONG	clock = NTSC_CLOCK;     /* Will check for PAL and change if necessary */


LONG OpenAudio()
{
extern	struct ExecBase *SysBase;
LONG 	error=0L;
ULONG   period;
int	k;

if(devopened)	return(-1);

/*-------------------------------------------------------------------------*/
/* Ask the system if we are PAL or NTSC and set clock constant accordingly */
/*-------------------------------------------------------------------------*/
if(GfxBase=OpenLibrary("graphics.library",0L))
```c
    {
    if(((struct GfxBase *)GfxBase)->DisplayFlags & PAL)
```
		clock = PAL_CLOCK;
    else
		clock = NTSC_CLOCK;

```c
    CloseLibrary((struct Library *) GfxBase);
    }
```
printf("OpenAudio: For period calculations, clock=%ld\n", clock);

/* calculate period values for one octave based on system clock */
for(k=0; k<12; k++)
```c
    {
    period = ((per_ntsc[k] * clock) + (NTSC_CLOCK >> 1)) / NTSC_CLOCK;
    per[k] = period;
    D(bug("per[%ld]=%ld ",k,per[k]));
    }
```
D(bug("\n"));

/*-------------------------------------------------------------------*/
/* Create a reply port so the audio device can reply to our commands */
/*-------------------------------------------------------------------*/
if(!(port=CreatePort(0,0)))
	{ error = 1; goto bailout; }

/*--------------------------------------------------------------------------*/
/*  Create audio I/O blocks so we can send commands to the audio device     */
/*--------------------------------------------------------------------------*/
for(k=0; k<AIOCNT; k++)
```c
    {
    if(!(aio[k]=(struct IOAudio *)CreateExtIO(port,sizeof(struct IOAudio))))
```
	{ error = k+2; goto bailout; }

```c
    }
```
/*----------------------------------------------------------------------*/
/* Set up the audio I/O block for channel allocation:                   */
/* ioa_Request.io_Message.mn_ReplyPort is the address of a reply port.  */
/* ioa_Request.io_Message.mn_Node.ln_Pri sets the precedence (priority) */
/*   of our use of the audio device. Any tasks asking to use the audio  */
/*   device that have a higher precedence will steal the channel from us.*/
/* ioa_Request.io_Command is the command field for IO.                  */
/* ioa_Request.io_Flags is used for the IO flags.                       */
/* ioa_AllocKey will be filled in by the audio device if the allocation */
/*   succeeds. We must use the key it gives for all other commands sent.*/
/* ioa_Data is a pointer to the array listing the channels we want.     */
/* ioa_Length tells how long our list of channels is.                   */
/*----------------------------------------------------------------------*/
aio[0]->ioa_Request.io_Command               = ADCMD_ALLOCATE;
aio[0]->ioa_Request.io_Flags                 = ADIOF_NOWAIT;
aio[0]->ioa_AllocKey                         = 0;
aio[0]->ioa_Data                             = whichannel;
aio[0]->ioa_Length                           = sizeof(whichannel);

/*-----------------------------------------------*/
/* Open the audio device and allocate a channel  */
/*-----------------------------------------------*/
if(!(OpenDevice("audio.device",0L, (struct IORequest *) aio[0] ,0L)))
	devopened = TRUE;
else { error = 5; goto bailout; }

/* Clone the flags, channel allocation, etc. into other IOAudio requests */
for(k=1; k<AIOCNT; k++)	*aio[k] = *aio[0];

bailout:
if(error)
```c
    {
    printf("OpenAudio errored out at step %ld\n",error);
    CloseAudio();
    }
```
return(error);
}


/* CloseAudio
 *
 * Close audio device as opened by OpenAudio, null out pointers
 */
void CloseAudio()
{
int k;

D(bug("Closing audio device...\n"));

/* Note - we know we have no outstanding audio requests */
if(devopened)

```c
    {
    CloseDevice((struct IORequest *) aio[0]);
    devopened = FALSE;
    }
```
for(k=0; k<AIOCNT; k++)

```c
    {
    if(aio[k]) 	DeleteExtIO(aio[k]), aio[k] = NULL;
    }
```
if(port)   	DeletePort(port),  port = NULL;
}


/** PlaySample() **********************************************
 *
 * Play a note in octave for delay/50ths of a second
 * OR Play a sound effect (set octave and note to 0, -1)
 *
 * Requires successful OpenAudio() called previously
 *
 * When playing notes:
 * Expects note values between 0 (C) and 11 (B#)
 * Uses largest octave sample in 8SVX as octave 0, next smallest
 *   as octave 1, etc.
 *
 * Notes - this simple example routine does not do ATAK and RLSE)
 *       - use of Delay for timing is simplistic, synchronous, and does
 *		not take into account that the oneshot itself may be
 *		longer than the delay.
 *         Use timer.device for more accurate asynchronous delays
 *
 *************************************************************************/
/* Max playable sample in one IO request is 128K */
#define MAXSAMPLE 131072

LONG	PlaySample(struct EightSVXInfo *esvx,
			LONG octave, LONG note, UWORD volume, ULONG delay)
{
/* pointers to outstanding requests */
struct		IOAudio	*aout0=NULL, *aout1=NULL;
ULONG		period;
LONG		osize, rsize;
BYTE		*oneshot, *repeat;

if(!devopened)	return(-1);

if(note > 11) note=0;

if( note == -1 ) period = clock / esvx->Vhdr.samplesPerSec;
else 		 period = per[note]; /* table set up by OpenAudio */

if(octave > esvx->Vhdr.ctOctave) octave = 0;
if(volume > 64)	volume = 64;

oneshot = esvx->osamps[octave];
osize   = esvx->osizes[octave];
repeat  = esvx->rsamps[octave];
rsize   = esvx->rsizes[octave];

D(bug("oneshot $%lx size %ld, repeat $%lx size %ld\n",
	oneshot, osize, repeat, rsize));

/*------------------------------------------------------------*/
/* Set up audio I/O blocks to play a sample using CMD_WRITE.  */
/* Set up one request for the oneshot and one for repeat      */
/* (all ready for simple case, but we may not need both)      */
/* The io_Flags are set to ADIOF_PERVOL so we can set the     */
/*    period (speed) and volume with the our sample;          */
/* ioa_Data points to the sample; ioa_Length gives the length */
/* ioa_Cycles tells how many times to repeat the sample       */
/* If you want to play the sample at a given sampling rate,   */
/* set ioa_Period = clock/(given sampling rate)               */
/*------------------------------------------------------------*/
aio[0]->ioa_Request.io_Command             =CMD_WRITE;
aio[0]->ioa_Request.io_Flags               =ADIOF_PERVOL;
aio[0]->ioa_Data                           =oneshot;
aio[0]->ioa_Length                         =osize;
aio[0]->ioa_Period                         =period;
aio[0]->ioa_Volume                         =volume;
aio[0]->ioa_Cycles                         =1;

aio[2]->ioa_Request.io_Command             =CMD_WRITE;
aio[2]->ioa_Request.io_Flags               =ADIOF_PERVOL;
aio[2]->ioa_Data                           =repeat;
aio[2]->ioa_Length                         =rsize;
aio[2]->ioa_Period                         =period;
aio[2]->ioa_Volume                         =volume;
aio[2]->ioa_Cycles                         =0;	/* repeat until stopped */

/*---------------------------------------------------*/
/* Send the command to start a sound using BeginIO() */
/* Go to sleep and wait for the sound to finish with */
/* WaitIO() to wait and get the get the ReplyMsg     */
/*---------------------------------------------------*/
printf("Starting tone O len %ld for %0ld cyc, R len %ld for %0ld cyc, per=%ld...",
		osize, aio[0]->ioa_Cycles, rsize, aio[1]->ioa_Cycles, period);

if(osize)
```c
    {
    /* Simple case for oneshot sample <= 128K (ie. most samples) */
    if(osize <= MAXSAMPLE)	BeginIO((struct IORequest *)(aout0=aio[0]));

    /* Note - this else case code is for samples >128K */
    else
```
	{
	*aio[1] = *aio[0];
	aout0 = playbigsample(aio[0],aio[1],oneshot,osize,period,volume);
	}

```c
     }
```
if(rsize)
```c
    {
    /* Simple case for oneshot sample <= 128K (ie. most samples) */
    if(rsize <= MAXSAMPLE)	BeginIO((struct IORequest *)(aout1=aio[2]));

    /* Note - this else case code is for samples >128K */
    else
```
	{
	*aio[3] = *aio[2];
	aout1 = playbigsample(aio[2],aio[3],repeat,rsize,period,volume);
	}

```c
     }
```
if(delay)	Delay(delay);	/* crude timing for notes */

/* Wait for any requests we still have out */
if(aout0) WaitIO(aout0);

if(aout1)
   {
   if(note >= 0) AbortIO(aout1);	/* if a note, stop it now */
   WaitIO(aout1);
   }

printf("Done\n");
}


/** playbigsample() ********************************************************
 *
 *  called by playsample to deal with samples > 128K
 *
 *  wants pointers to two ready-to-use IOAudio iorequest blocks
 *
 *  returns pointer to the IOAudio request that is still out
 *   or NULL if none (error)
 *************************************************************************/

struct IOAudio *playbigsample(struct IOAudio *aio0, struct IOAudio* aio1,
			BYTE *samptr, LONG ssize, ULONG period, UWORD volume)
{
struct IOAudio *aio[2];
LONG   size;
int    req=0, reqn=1;	/* current and next IOAudio request indexes */

if((!aio0)||(!aio1)||(ssize < MAXSAMPLE))	return(NULL);

aio[req]  = aio0;
aio[reqn] = aio1;

/* start the first 128 K playing */
aio[req]->ioa_Request.io_Command             =CMD_WRITE;
aio[req]->ioa_Request.io_Flags               =ADIOF_PERVOL;
aio[req]->ioa_Data                           =samptr;
aio[req]->ioa_Length			     =MAXSAMPLE;
aio[req]->ioa_Period                         =period;
aio[req]->ioa_Volume                         =volume;
aio[req]->ioa_Cycles                         =1;
BeginIO((struct IORequest*)aio[req]);

for(samptr=samptr + MAXSAMPLE, size = ssize - MAXSAMPLE;
	size > 0;
		samptr += MAXSAMPLE)
```c
    {
    /* queue the next piece of sample */
    reqn = req ^ 1;	/* alternate IO blocks 0 and 1 */
    aio[reqn]->ioa_Request.io_Command             =CMD_WRITE;
    aio[reqn]->ioa_Request.io_Flags               =ADIOF_PERVOL;
    aio[reqn]->ioa_Data                           =samptr;
    aio[reqn]->ioa_Length = (size > MAXSAMPLE) ? MAXSAMPLE : size;
    aio[reqn]->ioa_Period                         =period;
    aio[reqn]->ioa_Volume                         =volume;
    aio[reqn]->ioa_Cycles                         =1;
    BeginIO((struct IORequest*)aio[reqn]);

    /* Wait for previous request to finish */
    WaitIO(aio[req]);
    /* decrement size */
    size = (size > MAXSAMPLE) ? size-MAXSAMPLE : 0;
    req = reqn;		/* switch between aio[0] and aio[1] */
    }
```
return(aio[reqn]);
}

/** LoadSample() **********************************************************
 *
 * Read 8SVX, given an initialized EightSVXInfo with not-in-use IFFHandle,
 *   and filename.  Leaves the IFFHandle open so you can FindProp()
 *   additional chunks or copychunks().  You must UnloadSample()
 *   when done.  UnloadSample will closeifile if the file is still
 *   open.
 *
 * Fills in esvx->Vhdr and Name, and allocates/loads esvx->sample,
 *   setting esvx->samplebytes to size for deallocation.
 *
 * Returns 0 for success of an IFFERR (libraries/iffparse.h)
 *************************************************************************/
LONG LoadSample(struct EightSVXInfo *esvx, UBYTE *filename)
```c
    {
    struct IFFHandle *iff;
    struct StoredProperty *sp;
    Voice8Header *vhdr;
    BYTE *oneshot, *repeat;
    ULONG osize, rsize, spcyc;
    int oct;
    LONG error = 0L;

    D(bug("LoadSample:\n"));

    if(!esvx)				return(CLIENT_ERROR);
    if(!(iff=esvx->ParseInfo.iff))	return(CLIENT_ERROR);

    if(!(error = openifile((struct ParseInfo *)esvx, filename, IFFF_READ)))
```
	{
	printf("Reading '%s'...\n",filename);
	error = parseifile((struct ParseInfo *)esvx,
			ID_FORM, ID_8SVX,
			esvx->ParseInfo.propchks,
			esvx->ParseInfo.collectchks,
			esvx->ParseInfo.stopchks);

	D(bug("LoadSample: after parseifile - error = %ld\n",error));

	if((!error)||(error == IFFERR_EOC)||(error == IFFERR_EOF))
	    {
	    if(contextis(iff,ID_8SVX,ID_FORM))
		{
		D(bug("LoadSample: context is 8SVX\n"));
		if(!(sp = FindProp(iff,ID_8SVX,ID_VHDR)))
		    {
		    message("No 8SVX.VHDR!");
		    error = IFFERR_SYNTAX;
		    }
		else
		    {
		    D(bug("LoadSample: Have VHDR\n"));
		    /* copy Voice8Header into frame */
		    vhdr = (Voice8Header *)(sp->sp_Data);
		    *(&esvx->Vhdr) = *vhdr;
		    /* copy name if any */
		    esvx->name[0]='\0';
		    if(sp = FindProp(iff,ID_8SVX,ID_NAME))
			{
			strncpy(esvx->name,sp->sp_Data,sp->sp_Size);
			esvx->name[MIN(sp->sp_Size,79)] = '\0';
			}
	    	    error = LoadSBody(esvx);
		    D(bug("LoadSample: After LoadSBody - error = %ld\n",error));
		    if(!error)
			{
			osize   = esvx->Vhdr.oneShotHiSamples;
			rsize   = esvx->Vhdr.repeatHiSamples;
			spcyc	= esvx->Vhdr.samplesPerHiCycle;
			if(!spcyc) spcyc = esvx->Vhdr.repeatHiSamples;
			if(!spcyc) spcyc = 8;

			oneshot = esvx->sample;

			for(oct = esvx->Vhdr.ctOctave-1; oct >= 0;
				 oct--, oneshot+=(osize+rsize),
					osize <<= 1, rsize <<=1, spcyc <<=1)
```c
    			    {
    			    repeat  = oneshot + osize;
```
			    esvx->osizes[oct] = osize;
			    if(osize) esvx->osamps[oct] = oneshot;
			    else      esvx->osamps[oct] = 0;
			    esvx->rsizes[oct] = rsize;
			    if(rsize) esvx->rsamps[oct] = repeat;
			    else      esvx->rsamps[oct] = 0;
			    esvx->spcycs[oct] = spcyc;

 			D(bug("oneshot $%lx size %ld, repeat $%lx size %ld\n",
				oneshot, osize, repeat, rsize));

			    }
		        }
		    }
		}
	    else
		{
		message("Not an 8SVX\n");
		error = NOFILE;
		}
	    }
	}

```c
    if(error)
```
	{
	closeifile((struct ParseInfo *)esvx);
	UnloadSample(esvx);
	}


```c
    return(error);
    }
```
/** UnloadSample() *******************************************************
 *
 * Frees and closes everything opened/alloc'd by LoadSample()
 *
 *************************************************************************/
void UnloadSample(struct EightSVXInfo *esvx)
```c
    {
    if(esvx)
```
	{
	UnloadSBody(esvx);
	closeifile((struct ParseInfo *)esvx);
	}


```c
    }
```
/** LoadSBody() ***********************************************************
 *
 * Read a 8SVX Sample BODY into RAM.
 *
 *************************************************************************/
LONG LoadSBody(struct EightSVXInfo *esvx)
```c
    {
    struct IFFHandle *iff;
    LONG sbytes, rlen, error = 0L;
    ULONG memtype;
    Voice8Header *vhdr = &esvx->Vhdr;
    BYTE *t;

    D(bug("LoadSBody:\n"));

    if(!(iff=esvx->ParseInfo.iff))	return(CLIENT_ERROR);
    if(!esvx)				return(CLIENT_ERROR);

    if(!(currentchunkis(iff,ID_8SVX,ID_BODY)))
```
	{
	message("LoadSBody: not at BODY!");
	return(IFFERR_READ);
	}

```c
    sbytes  = ChunkMoreBytes(CurrentChunk(iff));

    /* if we have to decompress, let's just load it into public mem */
    memtype = vhdr->sCompression ? MEMF_PUBLIC : MEMF_CHIP;

    D(bug("LoadSBody: samplebytes=%ld, compression=%ld\n",
```
			sbytes,vhdr->sCompression));

```c
    if(!(esvx->sample = (BYTE *)AllocMem(sbytes, memtype)))
```
	{
```c
        error = CLIENT_ERROR;
```
	}
    else
	{
	D(bug("LoadSBody: have load buffer\n"));
	esvx->samplebytes = sbytes;
```c
        if(rlen=ReadChunkBytes(iff,esvx->sample,sbytes) != sbytes)
```
	    error = IFFERR_READ;

	if(error)
	    {
	    D(bug("LoadSBody: ReadChunkBytes error = %ld, read %ld bytes\n",
			error));
	    UnloadSample(esvx);
	    }
	else if (vhdr->sCompression) /* Decompress, if needed. */
	    {
```c
            if(t = (BYTE *)AllocMem(sbytes<<1, MEMF_CHIP))
```
		{
		D(bug("LoadSBody: have decompression buffer\n"));
```c
            	DUnpack(esvx->sample, sbytes, t);
            	FreeMem(esvx->sample, sbytes);
            	esvx->sample = t;
            	esvx->samplebytes = sbytes << 1;
```
		}
	    else
		{
		UnloadSample(esvx);
		error = IFFERR_NOMEM;
		}
	    }
	}


```c
    return(error);
    }
```
/** UnloadSBody() ********************************************************
 *
 * Deallocates esvx->smaple
 *
 *************************************************************************/
void UnloadSBody(struct EightSVXInfo *esvx)
```c
    {
    if(esvx)
```
	{
	if(esvx->sample)
	    {
	    DD(bug("About to free SBody\n"));
	    FreeMem(esvx->sample,esvx->samplebytes);
	    esvx->sample = NULL;
	    }
	esvx->samplebytes = NULL;
	}


```c
    }
```
/* DUnpack.c --- Fibonacci Delta decompression by Steve Hayes */

/* Fibonacci delta encoding for sound data */
BYTE codeToDelta[16] = {-34,-21,-13,-8,-5,-3,-2,-1,0,1,2,3,5,8,13,21};

/* Unpack Fibonacci-delta encoded data from n byte source
 * buffer into 2*n byte dest buffer, given initial data
 * value x.  It returns the lats data value x so you can
 * call it several times to incrementally decompress the data.
 */

BYTE D1Unpack(BYTE source[], LONG n, BYTE dest[], BYTE x)
   {
   BYTE d;
   LONG i, lim;

   lim = n << 1;
   for (i=0; i < lim; ++i)
```c
      {
      /* Decode a data nibble, high nibble then low nibble */
      d = source[i >> 1];    /* get a pair of nibbles */
      if (i & 1)             /* select low or high nibble */
         d &= 0xf;           /* mask to get the low nibble */
      else
         d >>= 4;            /* shift to get the high nibble */
      x += codeToDelta[d];   /* add in the decoded delta */
      dest[i] = x;           /* store a 1 byte sample */
      }
```
   return(x);
   }

/* Unpack Fibonacci-delta encoded data from n byte
 * source buffer into 2*(n-2) byte dest buffer.
 * Source buffer has a pad byte, an 8-bit initial
 * value, followed by n-2 bytes comprising 2*(n-2)
 * 4-bit encoded samples.
 */

void DUnpack(source, n, dest)
BYTE source[], dest[];
LONG n;
   {
   D1Unpack(source+2, n-2, dest, source[1]);
   }

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)

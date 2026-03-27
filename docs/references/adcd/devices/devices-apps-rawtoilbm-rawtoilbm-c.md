---
title: Devices/apps/RawtoILBM/RawtoILBM.c
manual: devices
chapter: devices
section: devices-apps-rawtoilbm-rawtoilbm-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/apps/RawtoILBM/RawtoILBM.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* RawtoILBM
 * Converts raw file (from ILBMtoRaw) into an ILBM
 * Requires linkage with several iffparse modiules - See Makefile
 */

#include "iffp/ilbmapp.h"

#include <intuition/intuitionbase.h>
#include <workbench/workbench.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

char *vers = "\0$VER: RawtoILBM 37.5";
char *Copyright =
  "RawtoILBM v37.5 - converts raw file to ILBM - Freely Redistributable";
#define MINARGS 6
char *usage = "Usage: RawtoILBM rawname ilbmname width height depth\n";

void bye(UBYTE *s,int e);
void cleanup(void);

struct Library	*IntuitionBase = NULL;
struct Library	*GfxBase = NULL;
struct Library	*IFFParseBase = NULL;

struct ILBMInfo ilbm = {0};

USHORT	colortable[MAXAMCOLORREG];

BOOL fromWB;


void main(int argc, char **argv)
```c
    {
    LONG	error = 0L, rawfile, rlen;
    USHORT	width, height, depth, pwidth, pheight, pmode, extra;
    ULONG 	plsize;
    char        *rawname,*ilbmname;
    int 	k;

    fromWB = (argc==0) ? TRUE : FALSE;

    if(!(IntuitionBase = OpenLibrary("intuition.library", 0)))
      bye("Can't open intuition library.\n",RETURN_WARN);

    if(!(GfxBase = OpenLibrary("graphics.library",0)))
      bye("Can't open graphics library.\n",RETURN_WARN);

    if(!(IFFParseBase = OpenLibrary("iffparse.library",0)))
      bye("Can't open iffparse library.\n",RETURN_WARN);

    if(!(ilbm.ParseInfo.iff = AllocIFF()))
      bye(IFFerr(IFFERR_NOMEM),RETURN_WARN);

    if(argc==MINARGS)                 /* Passed filenames via command line  */
      	{
      	rawname  = argv[1];
      	ilbmname = argv[2];
```
	width  = atoi(argv[3]);
	height = atoi(argv[4]);
	depth  = atoi(argv[5]);

	/* Page width, height, and mode for saved ILBM */
	pwidth  = width  < 320 ? 320 : width;
	pheight = height < 200 ? 200 : height;
	pmode	= pwidth >= 640  ? HIRES : 0L;
	pmode  |= pheight >= 400 ? LACE  : 0L;

	plsize = RASSIZE(width,height);
	}
    else
	{
	printf("%s\n%s\n",Copyright,usage);
	bye("\n",RETURN_OK);
	}


```c
    if(!(rawfile = Open(rawname,MODE_OLDFILE)))
```
	{
	printf("Can't open raw file '%s'\n",rawname);
	bye(" ",RETURN_WARN);
	}

```c
    /*
     * Allocate Bitmap and planes
     */
     extra = depth > 8 ? depth - 8 : 0;
     if(ilbm.brbitmap = AllocMem(sizeof(struct BitMap) + (extra<<2),
```
				MEMF_CLEAR))
```c
        {
        InitBitMap(ilbm.brbitmap,depth,width,height);
        for(k=0, error=0, rlen=1; k<depth && (!error) && (rlen >0); k++)
            {
            if(!(ilbm.brbitmap->Planes[k] = AllocRaster(width,height)))
```
			error = IFFERR_NOMEM;
```c
            if(! error)
```
		{
```c
                BltClear(ilbm.brbitmap->Planes[k], RASSIZE(width,height),0);
```
		/* Read a plane */
		rlen = Read(rawfile,ilbm.brbitmap->Planes[k],plsize);
```c
                }
```
	    }

	/* get colortable */
	if((!error)&&(rlen > 0))
		rlen=Read(rawfile,colortable,(MIN(1<<depth,MAXAMCOLORREG)<<1));

```c
        if((error)||(rlen<=0))
            {
```
	    if(rlen <= 0)  	printf("Error loading raw file - check dimensions\n");
```c
    	    else 		printf("Error allocating planes\n");
```
	    }
	else
	    {
	    error = saveilbm(&ilbm, ilbm.brbitmap, pmode,
```c
                width,  height, pwidth, pheight,
                colortable, MIN(1<<depth,MAXAMCOLORREG), 4,    /* colors */
```
		mskNone, 0,		/* masking. transColor */
		NULL, NULL,		/* additional chunk lists */
		ilbmname);
	    }

```c
        for(k=0; k<depth; k++)
            {
            if(ilbm.brbitmap->Planes[k])
```
			FreeRaster(ilbm.brbitmap->Planes[k],width,height);
	    }
	FreeMem(ilbm.brbitmap, sizeof(struct BitMap) + (extra << 2));
	}

```c
    Close(rawfile);

    if(error)
```
	{
	printf("%s\n",IFFerr(error));
	bye(" ", RETURN_FAIL);
	}


```c
    else bye("",RETURN_OK);
    }
```
void bye(UBYTE *s,int e)

```c
    {
    if(s&&(*s)) printf("%s\n",s);
    if ((fromWB)&&(*s))    /* Wait so user can read messages */
        {
        printf("\nPRESS RETURN TO EXIT\n");
        while(getchar() != '\n');
        }
    cleanup();
    exit(e);
    }
```
void cleanup()

```c
    {
    if(ilbm.ParseInfo.iff)	FreeIFF(ilbm.ParseInfo.iff);

    if(GfxBase)		CloseLibrary(GfxBase);
    if(IntuitionBase)	CloseLibrary(IntuitionBase);
    if(IFFParseBase)	CloseLibrary(IFFParseBase);
    }
```

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)

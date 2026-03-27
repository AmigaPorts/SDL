---
title: Devices/apps/ILBMtoRaw/ILBMtoRaw.c
manual: devices
chapter: devices
section: devices-apps-ilbmtoraw-ilbmtoraw-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/apps/ILBMtoRaw/ILBMtoRaw.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*--------------------------------------------------------------*/
/*								*/
/* ILBMtoRaw: reads in ILBM, writes out raw file (raw planes, 	*/
/*  followed by colormap) 					*/
/*                                                              */
/* Based on ILBMRaw.c by Jerry Morrison and Steve Shaw,		*/
/* Electronic Arts.           					*/
/* Jan 31, 1986							*/
/*                                                              */
/* This software is in the public domain.                       */
/* This version for the Amiga computer.                         */
/*                                                              */
/*  Callable from CLI ONLY					*/
/*  modified 05-91 for use wuth iffparse modules		*/
/*  Requires linkage with several other modules - see Makefile  */
/*--------------------------------------------------------------*/

#include "iffp/ilbmapp.h"

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

char *vers = "\0$VER: ILBMtoRaw 37.5";
char *Copyright = "ILBMtoRaw v37.5 (Freely Redistributable)";

void bye(UBYTE *s, int e);
void cleanup(void);

LONG SaveBitMap(UBYTE *name, struct BitMap *bm, SHORT *cols, int ncols);

struct Library *IFFParseBase = NULL;
struct Library *GfxBase = NULL;

/* ILBM frame */
struct ILBMInfo ilbm = {0};


/* ILBM Property chunks to be grabbed - BMHD and CMAP needed for this app
 */
LONG	ilbmprops[] = {
		ID_ILBM, ID_BMHD,
		ID_ILBM, ID_CMAP,
		TAG_DONE
		};

/* ILBM Collection chunks (more than one in file) to be gathered */
LONG	*ilbmcollects = NULL;	/* none needed for this app */

/* ILBM Chunk to stop on */
LONG	ilbmstops[] = {
		ID_ILBM, ID_BODY,
		TAG_DONE
		};


/** main() ******************************************************************/

void main(int argc, char **argv)
```c
    {
    LONG error=NULL;
    UBYTE *ilbmname, fname[80], buf[24];

    if ((argc < 2)||(argv[argc-1][0]=='?'))
```
	bye("Usage from CLI: 'ILBMtoRaw filename'\n",RETURN_OK);

```c
    if(!(GfxBase = OpenLibrary("graphics.library",0)))
```
	bye("Can't open graphics.library",RETURN_FAIL);

```c
    if(!(IFFParseBase = OpenLibrary("iffparse.library",0)))
```
	bye("Can't open iffparse.library",RETURN_FAIL);

/*
 * Here we set up default ILBMInfo fields for our
 * application's frames.
 * Above we have defined the propery and collection chunks
 * we are interested in (some required like BMHD)
 */
```c
    ilbm.ParseInfo.propchks      = ilbmprops;
    ilbm.ParseInfo.collectchks   = ilbmcollects;
    ilbm.ParseInfo.stopchks      = ilbmstops;
    if(!(ilbm.ParseInfo.iff = AllocIFF()))
    	bye(IFFerr(IFFERR_NOMEM),RETURN_FAIL);	/* Alloc an IFFHandle */

    ilbmname = argv[1];

    /* Load as a brush since we don't need to display it */
    if (error = loadbrush(&ilbm,ilbmname))
        {
        printf("Can't load ilbm \"%s\", ifferr=%s\n",ilbmname,IFFerr(error));
        bye("",RETURN_WARN);
        }
    else /* Successfully loaded ILBM */
```
	{

```c
        strcpy(fname,argv[1]);
```
	if(ilbm.camg & HAM)	strcat(fname, ".ham");
	if(ilbm.camg & EXTRA_HALFBRITE)	strcat(fname, ".ehb");

	if(ilbm.camg & HIRES)	strcat(fname, ".hi");
	else strcat(fname, ".lo");

	if(ilbm.camg & LACE)	strcat(fname, ".lace");

	strcat(fname,".");
	sprintf(buf,"%d",ilbm.Bmhd.w);
	strcat(fname,buf);
	strcat(fname,"x");
	sprintf(buf,"%d",ilbm.Bmhd.h);
	strcat(fname,buf);
	strcat(fname,"x");
	sprintf(buf,"%d",ilbm.brbitmap->Depth);
	strcat(fname, buf);
	printf(" Creating file %s \n", fname);
	error=SaveBitMap(fname, ilbm.brbitmap, ilbm.colortable, ilbm.ncolors);

	unloadbrush(&ilbm);
	}



```c
    if(error)	bye(IFFerr(error),RETURN_WARN);
    else	bye("",RETURN_OK);
    }
```
/* SaveBitMap (as raw planes and colortable)
 *
 * Given filename, bitmap structure, and colortable pointer,
 * writes out raw bitplanes and colortable (not an ILBM)
 * Returns 0 for success
 */


LONG SaveBitMap(UBYTE *name, struct BitMap *bm, SHORT *cols, int ncols)
```c
    {
    SHORT i;
    LONG nb,plsize;

    LONG file = Open( name, MODE_NEWFILE);
    if( file == 0 )
```
	{
	printf(" couldn't open %s \n",name);
	return(CLIENT_ERROR);	/* couldnt open a load-file */
	}
```c
    plsize = bm->BytesPerRow*bm->Rows;
    for (i=0; i<bm->Depth; i++)
```
	{
	nb =  Write(file, bm->Planes[i], plsize);
	if (nb<plsize) break;
	}

```c
    if(nb>0)	nb=Write(file, cols, (1<<bm->Depth)*2);	/* save color map */
    Close(file);
    return(nb >= 0 ? 0L : IFFERR_WRITE);
    }
```
void bye(UBYTE *s, int e)

```c
    {
    if(s&&(*s))	printf("%s\n",s);
    cleanup();
    exit(e);
    }
```
void cleanup()

```c
    {
    if(ilbm.ParseInfo.iff)		FreeIFF(ilbm.ParseInfo.iff);

    if(IFFParseBase)	CloseLibrary(IFFParseBase);
    if(GfxBase)		CloseLibrary(GfxBase);
    }
```

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)

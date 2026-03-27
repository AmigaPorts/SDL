---
title: Devices/modules/ilbmr.c
manual: devices
chapter: devices
section: devices-modules-ilbmr-c
functions: []
libraries: []
---

# Devices/modules/ilbmr.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* ilbmr.c --- ILBM loading routines for use with iffparse */

/*----------------------------------------------------------------------*
 * ILBMR.C  Support routines for reading ILBM files.
 * (IFF is Interchange Format File.)
 *
 * Based on code by Jerry Morrison and Steve Shaw, Electronic Arts.
 * This software is in the public domain.
 * Modified for iffparse.library 05/90
 * This version for the Amiga computer.
 *----------------------------------------------------------------------*/

#include "iffp/ilbm.h"
#include "iffp/packer.h"
#include "iffp/ilbmapp.h"

#define movmem CopyMem

#define MaxSrcPlanes (25)

extern struct Library *GfxBase;

/*---------- loadbody ---------------------------------------------------*/

LONG loadbody(iff, bitmap, bmhd)
struct IFFHandle *iff;
struct BitMap *bitmap;
BitMapHeader *bmhd;
	{
	BYTE *buffer;
	ULONG bufsize;
	LONG error = 1;

	D(bug("In loadbody\n"));

	if(!(currentchunkis(iff,ID_ILBM,ID_BODY)))
	    {
	    message("ILBM has no BODY\n");	/* Maybe it's a palette */
	    return(IFF_OKAY);
	    }

	if((bitmap)&&(bmhd))
	    {
	    D(bug("Have bitmap and bmhd\n"));

	    bufsize = MaxPackedSize(RowBytes(bmhd->w)) << 4;
```c
            if(!(buffer = AllocMem(bufsize,0L)))
```
		{
		D(bug("Buffer alloc of %ld failed\n",bufsize));
		return(IFFERR_NOMEM);
		}
	    error = loadbody2(iff, bitmap, NULL, bmhd, buffer, bufsize);
	    D(bug("Returned from getbody, error = %ld\n",error));
	    }
	FreeMem(buffer,bufsize);
	return(error);
	}


/* like the old GetBODY */
LONG loadbody2(iff, bitmap, mask, bmhd, buffer, bufsize)
struct IFFHandle *iff;
struct BitMap *bitmap;
BYTE *mask;
BitMapHeader *bmhd;
BYTE *buffer;
ULONG bufsize;
   {
   UBYTE srcPlaneCnt = bmhd->nPlanes;   /* Haven't counted for mask plane yet*/
   WORD srcRowBytes = RowBytes(bmhd->w);
   WORD destRowBytes = bitmap->BytesPerRow;
   LONG bufRowBytes = MaxPackedSize(srcRowBytes);
   int nRows = bmhd->h;
   WORD compression = bmhd->compression;
   register int iPlane, iRow, nEmpty;
   register WORD nFilled;
   BYTE *buf, *nullDest, *nullBuf, **pDest;
   BYTE *planes[MaxSrcPlanes]; /* array of ptrs to planes & mask */
   struct ContextNode *cn;

   D(bug("srcRowBytes = %ld\n",srcRowBytes));

   cn = CurrentChunk(iff);

   if (compression > cmpByteRun1)

```c
      return(CLIENT_ERROR);
```
   D(bug("loadbody2: compression=%ld srcBytes=%ld bitmapBytes=%ld\n",
		compression, srcRowBytes, bitmap->BytesPerRow));
   D(bug("loadbody2: bufsize=%ld bufRowBytes=%ld, srcPlaneCnt=%ld\n",
			bufsize, bufRowBytes, srcPlaneCnt));

   /* Complain if client asked for a conversion GetBODY doesn't handle.*/
   if ( srcRowBytes  >  bitmap->BytesPerRow  ||

```c
         bufsize < bufRowBytes * 2  ||
         srcPlaneCnt > MaxSrcPlanes )
      return(CLIENT_ERROR);
```
   D(bug("loadbody2: past conversion checks\n"));

   if (nRows > bitmap->Rows)   nRows = bitmap->Rows;

   D(bug("loadbody2: srcRowBytes=%ld, srcRows=%ld, srcDepth=%ld, destDepth=%ld\n",
		srcRowBytes, nRows, bmhd->nPlanes, bitmap->Depth));

   /* Initialize array "planes" with bitmap ptrs; NULL in empty slots.*/
   for (iPlane = 0; iPlane < bitmap->Depth; iPlane++)
```c
      planes[iPlane] = (BYTE *)bitmap->Planes[iPlane];
```
   for ( ;  iPlane < MaxSrcPlanes;  iPlane++)

```c
      planes[iPlane] = NULL;
```
   /* Copy any mask plane ptr into corresponding "planes" slot.*/
   if (bmhd->masking == mskHasMask)
	{

```c
      	if (mask != NULL)
             planes[srcPlaneCnt] = mask;  /* If there are more srcPlanes than
               * dstPlanes, there will be NULL plane-pointers before this.*/
      	else
             planes[srcPlaneCnt] = NULL;  /* In case more dstPlanes than src.*/
      	srcPlaneCnt += 1;  /* Include mask plane in count.*/
      	}
```
   /* Setup a sink for dummy destination of rows from unwanted planes.*/
   nullDest = buffer;
   buffer  += srcRowBytes;
   bufsize -= srcRowBytes;

   /* Read the BODY contents into client's bitmap.

    * De-interleave planes and decompress rows.
    * MODIFIES: Last iteration modifies bufsize.*/
   buf = buffer + bufsize;  /* Buffer is currently empty.*/
   for (iRow = nRows; iRow > 0; iRow--)
	{
```c
      	for (iPlane = 0; iPlane < srcPlaneCnt; iPlane++)
```
	    {
 	    pDest = &planes[iPlane];

```c
            /* Establish a sink for any unwanted plane.*/
            if (*pDest == NULL)
```
		{
	    	nullBuf = nullDest;
```c
            	pDest   = &nullBuf;
            	}

            /* Read in at least enough bytes to uncompress next row.*/
            nEmpty  = buf - buffer;	  /* size of empty part of buffer.*/
            nFilled = bufsize - nEmpty;	  /* this part has data.*/
```
	    if (nFilled < bufRowBytes)
		{
	    	/* Need to read more.*/

	    	/* Move the existing data to the front of the buffer.*/
	    	/* Now covers range buffer[0]..buffer[nFilled-1].*/
```c
            	movmem(buf, buffer, nFilled);  /* Could be moving 0 bytes.*/

            	if(nEmpty > ChunkMoreBytes(cn))
```
		    {

```c
               	    /* There aren't enough bytes left to fill the buffer.*/
               	    nEmpty = ChunkMoreBytes(cn);
               	    bufsize = nFilled + nEmpty;  /* heh-heh */
               	    }
```
	    	/* Append new data to the existing data.*/
```c
            	if(ReadChunkBytes(iff, &buffer[nFilled], nEmpty) < nEmpty)
```
			return(CLIENT_ERROR);

```c
            	buf     = buffer;
```
	    	nFilled = bufsize;
	    	nEmpty  = 0;
	    	}

 	    /* Copy uncompressed row to destination plane.*/
```c
            if(compression == cmpNone)
```
		{
```c
            	if(nFilled < srcRowBytes)  return(IFFERR_MANGLED);
```
	    	movmem(buf, *pDest, srcRowBytes);
	    	buf    += srcRowBytes;
```c
            	*pDest += destRowBytes;
            	}
```
	    else
		{
```c
         	/* Decompress row to destination plane.*/
            	if ( unpackrow(&buf, pDest, nFilled,  srcRowBytes) )
                    /*  pSource, pDest, srcBytes, dstBytes  */
               		return(IFFERR_MANGLED);
```
	    	else *pDest += (destRowBytes - srcRowBytes);
		}
	    }
	}
   return(IFF_OKAY);
   }


/* ----------- getcolors ------------- */

/* getcolors - allocates a ilbm->colortable for at least MAXAMCOLORREG
 *      and loads CMAP colors into it, setting ilbm->ncolors to number
 *      of colors actually loaded.
 */
LONG getcolors(struct ILBMInfo *ilbm)
	{
	struct IFFHandle	*iff;
	int error = 1;

	if(!(iff=ilbm->ParseInfo.iff))	return(CLIENT_ERROR);

	if(!(error = alloccolortable(ilbm)))
	   error = loadcmap(iff, ilbm->colortable, &ilbm->ncolors);
	if(error) freecolors(ilbm);
	D(bug("getcolors: error = %ld\n",error));
	return(error);
	}


/* alloccolortable - allocates ilbm->colortable and sets ilbm->ncolors
 *	to the number of colors we have room for in the table.
 */

LONG alloccolortable(struct ILBMInfo *ilbm)
	{
	struct IFFHandle	*iff;
	struct	StoredProperty	*sp;

	LONG	error = CLIENT_ERROR;
	ULONG	ctabsize;
	USHORT	ncolors;

	if(!(iff=ilbm->ParseInfo.iff))	return(CLIENT_ERROR);

	if(sp = FindProp (iff, ID_ILBM, ID_CMAP))
		{
		/*
		 * Compute the size table we need
		 */
		ncolors = sp->sp_Size / 3;		/* how many in CMAP */
		ncolors = MAX(ncolors, MAXAMCOLORREG);

		ctabsize = ncolors * sizeof(Color4);
		if(ilbm->colortable =
		   (Color4 *)AllocMem(ctabsize,MEMF_CLEAR|MEMF_PUBLIC))
		    {
		    ilbm->ncolors = ncolors;
		    ilbm->ctabsize = ctabsize;
		    error = 0L;
		    }
		else error = IFFERR_NOMEM;
		}
	D(bug("alloccolortable for %ld colors: error = %ld\n",ncolors,error));
	return(error);
	}


void freecolors(struct ILBMInfo *ilbm)
	{
	if(ilbm->colortable)
		{
		FreeMem(ilbm->colortable, ilbm->ctabsize);
		}
	ilbm->colortable = NULL;
	ilbm->ctabsize = 0;
	}



/* Passed IFFHandle, pointer to colortable array, and pointer to
 * a USHORT containing number of colors caller has space to hold,
 * loads the colors and sets pNcolors to the number actually read.
 *
 * NOTE !!! - Old GetCMAP passed a pointer to a UBYTE for pNcolors
 *            This one is passed a pointer to a USHORT
 */
LONG loadcmap(struct IFFHandle *iff, WORD *colortable,USHORT *pNcolors)
	{
	register struct StoredProperty	*sp;
	register LONG			idx;
	register ULONG			ncolors;
	register UBYTE			*rgb;
	LONG				r, g, b;

	if(!(colortable))
		{
		message("No colortable allocated\n");
		return(1);
		}

	if(!(sp = FindProp (iff, ID_ILBM, ID_CMAP)))	return(1);

	rgb = sp->sp_Data;
	ncolors = sp->sp_Size / sizeofColorRegister;
	if(*pNcolors < ncolors)	ncolors = *pNcolors;
	*pNcolors = ncolors;

	idx = 0;

```c
        while (ncolors--)
                {
                r = (*rgb++ & 0xF0) << 4;
                g = *rgb++ & 0xF0;
                b = *rgb++ >> 4;
                colortable[idx] = r | g | b;
                idx++;
                }
        return(0);
        }
```
/*
 * Returns CAMG or computed mode for storage in ilbm->camg
 *
 * ilbm->Bmhd structure must be initialized prior to this call.
 */
ULONG getcamg(struct ILBMInfo *ilbm)
	{
	struct IFFHandle *iff;
	struct StoredProperty *sp;
	UWORD  wide,high,deep;
	ULONG modeid = 0L;


```c
    	if(!(iff=ilbm->ParseInfo.iff))	return(0L);
```
	wide = ilbm->Bmhd.pageWidth;
	high = ilbm->Bmhd.pageHeight;
	deep = ilbm->Bmhd.nPlanes;

	D(bug("Getting CAMG for w=%ld h=%ld d=%ld ILBM\n",wide,high,deep));

```c
        /*
         * Grab CAMG's idea of the viewmodes.
         */
        if (sp = FindProp (iff, ID_ILBM, ID_CAMG))
                {
                modeid = (* (ULONG *) sp->sp_Data);

                /* knock bad bits out of old-style 16-bit viewmode CAMGs
                 */
                if((!(modeid & MONITOR_ID_MASK))||
```
		  ((modeid & EXTENDED_MODE)&&(!(modeid & 0xFFFF0000))))
```c
                   modeid &=
```
		    (~(EXTENDED_MODE|SPRITES|GENLOCK_AUDIO|GENLOCK_VIDEO|VP_HIDE));

```c
                /* check for bogus CAMG like DPaintII brushes
                 * with junk in upper word and extended bit
                 * not set in lower word.
                 */
                if((modeid & 0xFFFF0000)&&(!(modeid & 0x00001000))) sp=NULL;
                }

        if(!sp) {
                /*
                 * No CAMG (or bad CAMG) present; use computed modes.
                 */
                if (wide >= 640)        modeid = HIRES;
                if (high >= 400)        modeid |= LACE;
                if (deep == 6)
                        {
                        modeid |= ilbm->EHB ? EXTRA_HALFBRITE : HAM;
                        }
```
		D(bug("No CAMG found - using mode $%08lx\n",modeid));

```c
                }
```
	D(bug("getcamg: modeid = $%08lx\n",modeid));
	return(modeid);
	}


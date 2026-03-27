---
title: Devices/modules/loadilbm.c
manual: devices
chapter: devices
section: devices-modules-loadilbm-c
functions: []
libraries: []
---

# Devices/modules/loadilbm.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* loadilbm.c 05/91  C. Scheppner CBM
 *
 * High-level ILBM load routines
 */

#include "iffp/ilbm.h"
#include "iffp/ilbmapp.h"

extern struct Library *GfxBase;

/* loadbrush
 *
 * Passed an initialized ILBMInfo with a not-in-use ParseInfo.iff
 *   IFFHandle and desired propchks, collectchks, and stopchks, and filename,
 *   will load an ILBM as a brush, setting up ilbm->Bmhd, ilbm->camg,
 *   ilbm->brbitmap, ilbm->colortable, and ilbm->ncolors
 *
 *   Note that ncolors may be more colors than you can LoadRGB4.
 *   Use MIN(ilbm->ncolors,MAXAMCOLORREG) for color count if you change
 *   the colors yourself using 1.3/2.0 functions.
 *
 * Returns 0 for success or an IFFERR (libraries/iffparse.h)
 */

LONG loadbrush(struct ILBMInfo *ilbm, UBYTE *filename)
{
LONG error = 0L;

```c
    if(!(ilbm->ParseInfo.iff))	return(CLIENT_ERROR);

    if(!(error = openifile((struct ParseInfo *)ilbm, filename, IFFF_READ)))
```
	{
	error = parseifile((struct ParseInfo *)ilbm,
				ID_FORM, ID_ILBM,
				ilbm->ParseInfo.propchks,
				ilbm->ParseInfo.collectchks,
				ilbm->ParseInfo.stopchks);
	if((!error)||(error == IFFERR_EOC)||(error == IFFERR_EOF))
	    {
	    if(contextis(ilbm->ParseInfo.iff,ID_ILBM,ID_FORM))
		{
	    	if(error = createbrush(ilbm))   deletebrush(ilbm);
		}
	    else
		{
		closeifile((struct ParseInfo *)ilbm);
		message("Not an ILBM\n");
		error = NOFILE;
		}
	    }
	}
```c
    return(error);
```
}


/* unloadbrush
 *
 * frees and close everything alloc'd/opened by loadbrush
 */
void unloadbrush(struct ILBMInfo *ilbm)
{
```c
    closeifile((struct ParseInfo *)ilbm);
    deletebrush(ilbm);
```
}


/* queryilbm
 *
 * Passed an initilized ILBMInfo with a not-in-use IFFHandle,
 *   and a filename,
 *   will open an ILBM, fill in ilbm->camg and ilbm->bmhd,
 *   and close the ILBM.
 *
 * This allows you to determine if the ILBM is a size and
 *   type you want to deal with.
 *
 * Returns 0 for success or an IFFERR (libraries/iffparse.h)
 */

/* query just wants these chunks */
LONG queryprops[] = { ID_ILBM, ID_BMHD,
		      ID_ILBM, ID_CAMG,

```c
                      TAG_DONE };
```
/* scan can stop when a CMAP or BODY is reached */
LONG querystops[] = { ID_ILBM, ID_CMAP,
		      ID_ILBM, ID_BODY,
		      TAG_DONE };

LONG queryilbm(struct ILBMInfo *ilbm, UBYTE *filename)
{
LONG error = 0L;
BitMapHeader *bmhd;

```c
    if(!(ilbm->ParseInfo.iff))	return(CLIENT_ERROR);

    if(!(error = openifile((struct ParseInfo *)ilbm, filename, IFFF_READ)))
```
	{
	D(bug("queryilbm: openifile successful\n"));

	error = parseifile((struct ParseInfo *)ilbm,
			ID_FORM, ID_ILBM,
			queryprops, NULL, querystops);

	D(bug("queryilbm: after parseifile, error = %ld\n",error));

	if((!error)||(error == IFFERR_EOC)||(error == IFFERR_EOF))
	    {
	    if(contextis(ilbm->ParseInfo.iff,ID_ILBM,ID_FORM))
		{
		if(bmhd = (BitMapHeader*)
			findpropdata(ilbm->ParseInfo.iff,ID_ILBM,ID_BMHD))
		    {
		    *(&ilbm->Bmhd) = *bmhd;
		    ilbm->camg = getcamg(ilbm);
		    }
		else error = NOFILE;
		}
	    else
		{
		message("Not an ILBM\n");
		error = NOFILE;
		}
	    }
	closeifile(ilbm);
	}
```c
    return(error);
```
}


/* loadilbm
 *
 * Passed a not-in-use IFFHandle, an initialized ILBMInfo, and filename,
 *   will load an ILBM into your already opened ilbm->scr, setting up
 *   ilbm->Bmhd, ilbm->camg, ilbm->colortable, and ilbm->ncolors
 *   and loading the colors into the screen's viewport
 *
 *   Note that ncolors may be more colors than you can LoadRGB4.
 *   Use MIN(ilbm->ncolors,MAXAMCOLORREG) for color count if you change
 *   the colors yourself using 1.3/2.0 functions.
 *
 * Returns 0 for success or an IFFERR (libraries/iffparse.h)
 *
 * NOTE - loadilbm() keeps the IFFHandle open so you can copy
 *   or examine other chunks.  You must call closeifile(iff,ilbm)
 *   to close the file and deallocate the parsed context
 *
 */

LONG loadilbm(struct ILBMInfo *ilbm, UBYTE *filename)
{
LONG error = 0L;


```c
    D(bug("loadilbm:\n"));

    if(!(ilbm->ParseInfo.iff))	return(CLIENT_ERROR);
    if(!ilbm->scr)		return(CLIENT_ERROR);

    if(!(error = openifile((struct ParseInfo *)ilbm, filename, IFFF_READ)))
```
	{
	D(bug("loadilbm: openifile successful\n"));

	error = parseifile((struct ParseInfo *)ilbm,
			ID_FORM, ID_ILBM,
			ilbm->ParseInfo.propchks,
			ilbm->ParseInfo.collectchks,
			ilbm->ParseInfo.stopchks);

	D(bug("loadilbm: after parseifile, error = %ld\n",error));

	if((!error)||(error == IFFERR_EOC)||(error == IFFERR_EOF))
	    {
	    if(contextis(ilbm->ParseInfo.iff,ID_ILBM,ID_FORM))
		{
	    	error = loadbody(ilbm->ParseInfo.iff,
					&ilbm->scr->BitMap, &ilbm->Bmhd);

		D(bug("loadilbm: after loadbody, error = %ld\n",error));

		if(!error)
		    {
		    if(!(getcolors(ilbm)))
				LoadRGB4(&ilbm->scr->ViewPort,ilbm->colortable,
					MIN(ilbm->ncolors,MAXAMCOLORREG));
		    }
		}
	    else
		{
		closeifile((struct ParseInfo *)ilbm);
		message("Not an ILBM\n");
		error = NOFILE;
		}
	    }
	}
```c
    return(error);
```
}


/* unloadilbm
 *
 * frees and closes everything allocated by loadilbm
 */
void unloadilbm(struct ILBMInfo *ilbm)
{
```c
    closeifile((struct ParseInfo *)ilbm);
    freecolors(ilbm);
```
}


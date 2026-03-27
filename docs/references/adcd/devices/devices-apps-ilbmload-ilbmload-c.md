---
title: Devices/apps/ILBMLoad/ILBMLoad.c
manual: devices
chapter: devices
section: devices-apps-ilbmload-ilbmload-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/apps/ILBMLoad/ILBMLoad.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* ILBMLoad.c 05/91  C. Scheppner CBM
 *
 * Example which
 *  - first queries an ILBM to determine size and mode
 *  - then opens an appropriate screen and window
 *  - then loads the ILBM into the already opened screen
 *
 * For clipboard, use filename -c[unit] (like -c, -c1, -c2, etc.)
 *
 * requires linkage with several IFF modules
 * see Makefile
 */

#include "iffp/ilbmapp.h"


#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void cleanup(void);
void bye(UBYTE *s,int error);

#define MINARGS 2
char *vers = "\0$VER: ILBMLoad 37.5";
char *Copyright = "ILBMLoad v37.5 (Freely Redistributable)";
char *usage = "Usage: ILBMLoad ilbmname (-c[unit] for clipboard";


struct Library *IntuitionBase  = NULL;
struct Library *GfxBase        = NULL;
struct Library *IFFParseBase   = NULL;

/* Note - these fields are also available in the ILBMInfo structure */
struct   Screen         *scr;         /* for ptr to screen structure */
struct   Window         *win;         /* for ptr to window structure */
struct   RastPort       *wrp;         /* for ptr to RastPort  */
struct   ViewPort       *vp;          /* for ptr to Viewport  */

struct   IntuiMessage   *msg;

struct   NewWindow      mynw = {
   0, 0,                                  /* LeftEdge and TopEdge */
   0, 0,                          	  /* Width and Height */
   -1, -1,                                /* DetailPen and BlockPen */
   VANILLAKEY|MOUSEBUTTONS,               /* IDCMP Flags with Flags below */
   BACKDROP|BORDERLESS|SMART_REFRESH|NOCAREREFRESH|ACTIVATE|RMBTRAP,
   NULL, NULL,                            /* Gadget and Image pointers */
   NULL,                                  /* Title string */
   NULL,                                  /* Screen ptr null till opened */
   NULL,                                  /* BitMap pointer */
   50, 20,                                /* MinWidth and MinHeight */
   0 , 0,                                 /* MaxWidth and MaxHeight */
   CUSTOMSCREEN                           /* Type of window */
   };


BOOL   FromWb;


/* ILBM Property chunks to be grabbed
 * List BMHD, CMAP and CAMG first so we can skip them when we write
 * the file back out (they will be written out with separate code)
 */
LONG	ilbmprops[] = {
		ID_ILBM, ID_BMHD,
		ID_ILBM, ID_CMAP,
		ID_ILBM, ID_CAMG,
		ID_ILBM, ID_CCRT,
		ID_ILBM, ID_AUTH,
		ID_ILBM, ID_Copyright,
		TAG_DONE
		};

/* ILBM Collection chunks (more than one in file) to be gathered */
LONG	ilbmcollects[] = {
		ID_ILBM, ID_CRNG,
		TAG_DONE
		};

/* ILBM Chunk to stop on */
LONG	ilbmstops[] = {
		ID_ILBM, ID_BODY,
		TAG_DONE
		};


UBYTE nomem[]  = "Not enough memory\n";
UBYTE noiffh[] = "Can't alloc iff\n";



/* For our allocated ILBM frame */
struct ILBMInfo  *ilbm;


/*
 * MAIN
 */
void main(int argc, char **argv)
   {
   UBYTE *ilbmname=NULL;
   LONG error = 0L;

   FromWb = argc ? FALSE : TRUE;

   if((argc<MINARGS)||(argv[argc-1][0]=='?'))
	{
	printf("%s\n%s\n",Copyright,usage);
```c
        bye("",RETURN_OK);
```
	}

   ilbmname = argv[1];

   /* Open Libraries */

   if(!(IntuitionBase = OpenLibrary("intuition.library", 0)))

```c
      bye("Can't open intuition library.\n",RETURN_WARN);
```
   if(!(GfxBase = OpenLibrary("graphics.library",0)))

```c
      bye("Can't open graphics library.\n",RETURN_WARN);
```
   if(!(IFFParseBase = OpenLibrary("iffparse.library",0)))



```c
      bye("Can't open iffparse library.\n",RETURN_WARN);
```
/*
 * Alloc one ILBMInfo struct
 */
```c
    if(!(ilbm = (struct ILBMInfo *)
```
	AllocMem(sizeof(struct ILBMInfo),MEMF_PUBLIC|MEMF_CLEAR)))
		bye(nomem,RETURN_FAIL);

/*
 * Here we set up our ILBMInfo fields for our
 * application.
 * Above we have defined the propery and collection chunks
 * we are interested in (some required like BMHD)
 */


```c
    ilbm->ParseInfo.propchks	= ilbmprops;
    ilbm->ParseInfo.collectchks	= ilbmcollects;
    ilbm->ParseInfo.stopchks	= ilbmstops;

    ilbm->windef	= &mynw;
```
/*
 * Alloc IFF handle for frame
 */

```c
    if(!(ilbm->ParseInfo.iff = AllocIFF())) bye(noiffh,RETURN_FAIL);
```
/* Normally you would use showilbm() to open an appropriate acreen
 * and display an ILBM in it.
 *
 * However, here we are demonstrating
 *  - first querying an ILBM to get its BMHD and CAMG (real or computed)
 *  - then opening our own display
 *  - then loading the ILBM into it
 */

```c
    if(!(error = queryilbm(ilbm,ilbmname)))
```
	{
	D(bug("ilbmload: after query, this ILBM is %ld x %ld x %ld, modeid=$%lx\n",
		ilbm->Bmhd.w, ilbm->Bmhd.h, ilbm->Bmhd.nPlanes, ilbm->camg));

	/* Note - you could use your own routines to open your
	 * display, but if so, you must initialize ilbm->scr,
	 * ilbm->win, ilbm->wrp, ilbm->srp, and ilbm->vp for your display.
	 * Here we will use opendisplay() which will initialize
	 * those fields.
	 */
	if(!(opendisplay(ilbm,
			MAX(ilbm->Bmhd.pageWidth, ilbm->Bmhd.w),
			MAX(ilbm->Bmhd.pageHeight,ilbm->Bmhd.h),
			MIN(ilbm->Bmhd.nPlanes,MAXAMDEPTH),
			ilbm->camg)))
	    {
	    printf("Failed to open display\n");
	    }
	else
	    {
	    D(bug("ilbmload: opendisplay successful\n"));

	    scr = ilbm->scr;
	    win = ilbm->win;

	    if(!(error = loadilbm(ilbm, ilbmname)))
		{
	    	D(bug("ilbmload: loadilbm successful\n"));

		/* Note - we don't need to examine or copy any
		 * chunks from the file, so we will close file now
		 */
		closeifile(ilbm);
		ScreenToFront(ilbm->scr);
		Wait(1<<win->UserPort->mp_SigBit);
		unloadilbm(ilbm);	/* deallocs colors, closeifile if needed */
		}
	    closedisplay(ilbm);
 	    }


```c
      	}

    if(error)	printf("%s\n",IFFerr(error));

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
   if(ilbm)
	{
	if(ilbm->ParseInfo.iff) 	FreeIFF(ilbm->ParseInfo.iff);
	FreeMem(ilbm,sizeof(struct ILBMInfo));
	}

   if(GfxBase) 	     	CloseLibrary(GfxBase);
   if(IntuitionBase) 	CloseLibrary(IntuitionBase);
   if(IFFParseBase)  	CloseLibrary(IFFParseBase);
   }

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)

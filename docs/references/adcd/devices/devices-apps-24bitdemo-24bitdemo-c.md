---
title: Devices/apps/24bitDemo/24bitDemo.c
manual: devices
chapter: devices
section: devices-apps-24bitdemo-24bitdemo-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/apps/24bitDemo/24bitDemo.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* 24bitDemo.c 05/91  C. Scheppner CBM
 *
 * Example which creates a 24-bit raster, saves it as a 24-bit ILBM,
 *   then loads it as a brush and shows it to you 4 planes at a time
 *   Optionally (if given a filename) just displays 4 planes at a time.
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

#define MINARGS 1
char *vers = "\0$VER: 24bitDemo 37.5";
char *Copyright = "24bitDemo v37.5 (Freely Redistributable)";
char *usage = "Usage: 24bitDemo [loadname] (saves/loads if no loadname given)";


struct Library *IntuitionBase  = NULL;
struct Library *GfxBase        = NULL;
struct Library *IFFParseBase   = NULL;

/* Note - these fields are also available in the ILBMInfo structure */
struct   Screen         *scr;         /* for ptr to screen structure */
struct   Window         *win;         /* for ptr to window structure */
struct   RastPort       *wrp;         /* for ptr to RastPort  */
struct   ViewPort       *vp;          /* for ptr to Viewport  */


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


/* For our allocated ILBM frames */
struct ILBMInfo  *ilbm[2];

#define SCRPLANES 4

USHORT colortable[32];
USHORT cstarts[]= { 0x000, 0x800, 0x000, 0x080, 0x000, 0x008 };
USHORT coffs[]	= { 0x100, 0x100, 0x010, 0x010, 0x001, 0x001 };

UBYTE *ilbmname = "RAM:24bit.ilbm";
UBYTE *rgbnames[]={"R0","R1","R2","R3","R4","R5","R6","R7",
		   "G0","G1","G2","G3","G4","G5","G6","G7",
		   "B0","B1","B2","B3","B4","B5","B6","B7" };

UBYTE *endtext1 = "Displayed 24 planes, 4 at a time.";
UBYTE *endtext2 = "Press mousebutton or key to exit.";

/*
 * MAIN
 */
void main(int argc, char **argv)
   {

```c
    struct RastPort *rp = NULL;
    struct BitMap dummy = {0};
    struct BitMap *bm = NULL, *xbm, *sbm;
    LONG	error = 0L;
    USHORT	width, height, depth, pwidth, pheight, pmode, extra, rgb;
    ULONG 	plsize;
    UBYTE	*tpp;
    BOOL	DoSave = TRUE;
    int 	k, p, s, n;
```
   FromWb = argc ? FALSE : TRUE;

   if((argc > 1)&&(argv[argc-1][0]=='?'))
	{
	printf("%s\n%s\n",Copyright,usage);
```c
        bye("",RETURN_OK);
```
	}

   if(argc==2)
	{
	ilbmname = argv[1];
	DoSave = FALSE;
	}

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
 * Alloc ILBMInfo structs
 */
```c
    if(!(ilbm[0] = (struct ILBMInfo *)
```
	AllocMem(sizeof(struct ILBMInfo),MEMF_PUBLIC|MEMF_CLEAR)))
		bye(nomem,RETURN_FAIL);
```c
    if(!(ilbm[1] = (struct ILBMInfo *)
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
    ilbm[0]->ParseInfo.propchks		= ilbmprops;
    ilbm[0]->ParseInfo.collectchks	= ilbmcollects;
    ilbm[0]->ParseInfo.stopchks		= ilbmstops;

    ilbm[0]->windef	= &mynw;

    *ilbm[1] = *ilbm[0];
```
/*
 * Alloc IFF handles for frame
 */


```c
    if(!(ilbm[0]->ParseInfo.iff = AllocIFF())) bye(noiffh,RETURN_FAIL);
    if(!(ilbm[1]->ParseInfo.iff = AllocIFF())) bye(noiffh,RETURN_FAIL);
```
/* for saving our demo 24-bit ILBM */

```c
    width  = 320;
    height = 200;
    depth  = 24;

    /* Page width, height, and mode for saved ILBM */
    pwidth  = width  < 320 ? 320 : width;
    pheight = height < 200 ? 200 : height;
    pmode   = pwidth >= 640  ? HIRES : 0L;
    pmode  |= pheight >= 400 ? LACE  : 0L;

    plsize = RASSIZE(width,height);

    if(!DoSave)	goto nosave;

    /*
     * Allocate Bitmap and planes
     */
    extra = depth > 8 ? depth - 8 : 0;
    if(ilbm[0]->brbitmap = AllocMem(sizeof(struct BitMap) + (extra<<2),
```
				MEMF_CLEAR))
	{
	bm = ilbm[0]->brbitmap;
```c
        InitBitMap(bm,depth,width,height);
        for(k=0, error=0; k<depth && (!error); k++)
            {
            if(!(bm->Planes[k] = AllocRaster(width,height)))
```
			error = IFFERR_NOMEM;
```c
            if(! error)
```
		{
```c
                BltClear(bm->Planes[k], RASSIZE(width,height),0);
                }
```
	    }

	if(!error)
	    {
	    if(!(rp = AllocMem(sizeof(struct RastPort),MEMF_CLEAR)))
		error = IFFERR_NOMEM;
	    else
		{
		InitRastPort(rp);
		rp->BitMap = bm;
		rp->Mask = 0x01;	/* we'll render 1 plane at a time */
		SetAPen(rp,1);
		SetDrMd(rp,JAM1);
		}
	    }

	if(!error)
	    {
	    /* Put something recognizable in the planes.
	     * Our bitmap is not part of a screen or viewport
	     * so we can fiddle with the pointers and depth
	     */
	    tpp = bm->Planes[0];	/* save first plane pointer */
	    bm->Depth = 1;
	    for(k=0; k<depth; k++)	/* swap in planeptrs 1 at a time */
		{
		bm->Planes[0] = bm->Planes[k];
		Move(rp,k * 10, (k * 8) + 8);	/* render rgb bitname text */
		Text(rp, rgbnames[k], 2);
		}
	    bm->Depth = depth;		/* restore depth */
	    bm->Planes[0] = tpp;	/* and first pointer */

	    /* Save the 24-bit ILBM */
	    printf("Saving %s\n",ilbmname);
	    error = saveilbm(ilbm[0], ilbm[0]->brbitmap, pmode,
                width,  height, pwidth, pheight,
                NULL, 0, 0,	/* colortable */
		mskNone, 0,	/* masking, transparent */
		NULL, NULL, 	/* chunklists */
		ilbmname);
	    }

	/* Free our bitmap */
```c
        for(k=0; k<depth; k++)
            {
            if(ilbm[0]->brbitmap->Planes[k])
```
			FreeRaster(ilbm[0]->brbitmap->Planes[k],width,height);
	    }
	FreeMem(ilbm[0]->brbitmap, sizeof(struct BitMap) + (extra << 2));
	ilbm[0]->brbitmap = NULL;
	if(rp)	FreeMem(rp, sizeof(struct RastPort));
	}

```c
    if(error)
```
	{
	printf("%s\n",IFFerr(error));
	bye(" ", RETURN_FAIL);
	}

nosave:

/* Normally you would use showilbm() to open an appropriate acreen
 * and display an ILBM in it.  However, this is a 24-bit ILBM
 * so we will load it as a brush (bitmap).
 * Here we are demonstrating
 *  - first querying an ILBM to get its BMHD and CAMG (real or computed)
 *  - then opening our own display
 *  - then loading the 24-bit ILBM as a brush (bitmap) and displaying
 *	it 4 planes at a time in our 4-plane screen.
 */

```c
    printf("Attempting to load %s as a bitmap and display 4 planes at a time\n",
```
		ilbmname);

```c
    if(!(error = queryilbm(ilbm[0],ilbmname)))
```
	{
	D(bug("24bitDemo: after query, this ILBM is %ld x %ld x %ld,modeid=$%lx\n",

```c
          ilbm[0]->Bmhd.w, ilbm[0]->Bmhd.h, ilbm[0]->Bmhd.nPlanes, ilbm[0]->camg));
```
	/* Note - you could use your own routines to open your
	 * display, but if so, you must initialize ilbm[0]->scr,
	 * ilbm[0]->win, ilbm[0]->wrp, ilbm[0]->srp, and ilbm[0]->vp for your
```c
         * display.  Here we will use opendisplay() which will initialize
```
	 * those fields.
	 */

	if(!(opendisplay(ilbm[0],
			MAX(ilbm[0]->Bmhd.pageWidth, ilbm[0]->Bmhd.w),
			MAX(ilbm[0]->Bmhd.pageHeight,ilbm[0]->Bmhd.h),
			MIN(ilbm[0]->Bmhd.nPlanes, SCRPLANES),
			ilbm[0]->camg)))
	    {
	    printf("Failed to open display\n");
	    }
	else
	    {
	    D(bug("24bitDemo: opendisplay (%ld planes) successful\n",SCRPLANES));

	    scr = ilbm[0]->scr;
	    win = ilbm[0]->win;
	    wrp = ilbm[0]->wrp;
	    vp  = ilbm[0]->vp;

	    if(!(error = loadbrush(ilbm[1], ilbmname)))
		{
	    	D(bug("24bitDemo: loadbrush successful\n"));

		/* Note - we don't need to examine or copy any
		 * chunks from the file, so we will close file now
		 */
		closeifile(ilbm[0]);
		ScreenToFront(ilbm[0]->scr);

		xbm = &dummy;		/* spare bitmap */
		sbm = &scr->BitMap;	/* screen's bitmap */
		bm = ilbm[1]->brbitmap;	/* the 24-plane bitmap */
		depth = bm->Depth;


```c
        	InitBitMap(xbm,SCRPLANES,scr->Width,scr->Height);
```
		/* Show the 24 planes */
		for(p=0; p<depth; p+=SCRPLANES)	/* 4 at a time */
		    {
		    SetRast(&scr->RastPort, 0);
		    for(s=0; s<SCRPLANES; s++)
			{
			if((p+s) < depth) xbm->Planes[s] = bm->Planes[p+s];
			else  		  xbm->Planes[s] = NULL, xbm->Depth--;
			}
		    /* Blit planes to the screen */
		    BltBitMap(xbm, 0, 0,
			      sbm, 0, 0,
			      scr->Width, scr->Height,
			      0xC0, 0x0F, NULL);

		    /* Emulate 8-bit color with 4-bit per gun colors
		     * by using each rgb value twice
		     */
		    for(n=0, rgb=cstarts[p /SCRPLANES]; n < 16; n++)
			{
			if(!n)	colortable[n] = 0xFFF;
			else	colortable[n] = rgb;
			/* bump gun for every 2 planes since
			 * we only have 8 bits per gun
			 */
			if(n & 1)  rgb += coffs[ p / SCRPLANES];
			}
		    LoadRGB4(vp, colortable, 16);
		    Delay(50);
		    }

		SetRast(&scr->RastPort, 0);

		SetAPen(wrp, 1);
		Move(wrp, 24, 80);
		Text(wrp, endtext1, strlen(endtext1));
		Move(wrp, 24, 120);
		Text(wrp, endtext2, strlen(endtext2));

		Wait(1<<win->UserPort->mp_SigBit);
		unloadbrush(ilbm[1]);	/* deallocs colors, closeifile if needed */
		}
	    closedisplay(ilbm[0]);
	    printf("Done\n");
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
   if(ilbm[0])
	{
	if(ilbm[0]->ParseInfo.iff) 	FreeIFF(ilbm[0]->ParseInfo.iff);
	FreeMem(ilbm[0],sizeof(struct ILBMInfo));
	}
   if(ilbm[1])
	{
	if(ilbm[1]->ParseInfo.iff) 	FreeIFF(ilbm[1]->ParseInfo.iff);
	FreeMem(ilbm[1],sizeof(struct ILBMInfo));
	}

   if(GfxBase) 	     	CloseLibrary(GfxBase);
   if(IntuitionBase) 	CloseLibrary(IntuitionBase);
   if(IFFParseBase)  	CloseLibrary(IFFParseBase);
   }

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)

---
title: Devices/apps/ILBMDemo/ILBMDemo.c
manual: devices
chapter: devices
section: devices-apps-ilbmdemo-ilbmdemo-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/apps/ILBMDemo/ILBMDemo.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* ILBMDemo.c  05/91   C. Scheppner CBM
 *
 * Demonstrates displaying an ILBM, loading a brush,
 *   saving an ILBM, and optionally printing a screen (CTRL-p)
 *   Use -c (or -c1, -c2, etc) as filename to read from or save to clipboard.
 *
 * requires linkage with several iffp modules - see Makefile
 */

#include "iffp/ilbmapp.h"


#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void chkmsg(void);
void cleanup(void);
void bye(UBYTE *s,int error);

#define SAVECHANGES

#define MINARGS 3
char *vers = "\0$VER: ILBMDemo 37.5";
char *Copyright = "ILBMDemo v37.5 (Freely Redistributable)";
char *usage =
"Usage: ILBMDemo sourceilbm destilbm [brushname]  (CTRL-p to print screen)\n"
"Displays source, optionally loads and blits brush, saves to dest\n"
"Use filename -c[unit] (ie. -c, -c1, -c2, etc.) for clipboard\n";

char *savename;

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


BOOL   FromWb, Done;


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


/* For test of adding new chunks to saved FORM */
struct Chunk newchunks[2] = {
	{
	&newchunks[1],
	ID_ILBM, ID_AUTH, IFFSIZE_UNKNOWN,
	"CAS_CBM"},
	{
	NULL,
	ID_ILBM, ID_NAME, IFFSIZE_UNKNOWN,
	"Untitled No. 27"},
	};


UBYTE nomem[]  = "Not enough memory\n";
UBYTE noiffh[] = "Can't alloc iff\n";

/* our indexes to reference our frames
 * DEFault, BRUsh, and SCReen
 */
#define DEF	0
#define BRU	1
#define SCR	2
#define UICOUNT 3

/* For our ILBM frames */
struct ILBMInfo  *ilbms[UICOUNT]  = { NULL };


/*
 * MAIN
 */
void main(int argc, char **argv)
   {
#ifdef SAVECHANGES
   struct Chunk *chunk;
   CamgChunk *camg;
   LONG saverror;
#endif
   UBYTE *ilbmname=NULL, *brushname=NULL, ans, c;
   BPTR lock;
   LONG error;

   FromWb = argc ? FALSE : TRUE;

   if((argc<MINARGS)||(argv[argc-1][0]=='?'))
	{
	printf("%s\n%s\n",Copyright,usage);
```c
        bye("",RETURN_OK);
```
	}

   switch(argc)

```c
      {
      case 4:
         brushname	= argv[3];
      case 3:
         savename	= argv[2];
         ilbmname	= argv[1];
         break;
      }
```
   /* if dest not clipboard, warn if dest file already exists */
   if(strcmp(savename,"-c"))
	{
	if(lock = Lock(savename,ACCESS_READ))
	    {
	    UnLock(lock);
	    printf("Dest file \"%s\" already exists.  Overwrite (y or n) ? ",
			savename);
	    ans = 0;
	    while((c = getchar()) != '\n') if(!ans)  ans = c | 0x20;
	    if(ans == 'n')   bye("Exiting.\n",RETURN_OK);
	    }
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
 * Alloc three ILBMInfo structs (one each for defaults, screen, brush)
 */
```c
    if(!(ilbms[0] = (struct ILBMInfo *)
```
	AllocMem(UICOUNT * sizeof(struct ILBMInfo),MEMF_PUBLIC|MEMF_CLEAR)))
		bye(nomem,RETURN_FAIL);
    else
	{
	ilbms[BRU] = ilbms[0] + 1;
	ilbms[SCR] = ilbms[0] + 2;
	}

/*
 * Here we set up default ILBMInfo fields for our
 * application's frames.
 * Above we have defined the propery and collection chunks
 * we are interested in (some required like BMHD)
 * Since all of our frames are for ILBM's, we'll initialize
 * one default frame and clone the others from it.
 */
```c
    ilbms[DEF]->ParseInfo.propchks	= ilbmprops;
    ilbms[DEF]->ParseInfo.collectchks	= ilbmcollects;
    ilbms[DEF]->ParseInfo.stopchks	= ilbmstops;

    ilbms[DEF]->windef	= &mynw;
```
/*
 * Initialize our working ILBM frames from our default one
 */

```c
    *ilbms[SCR] = *ilbms[DEF];	/* for our screen */
    *ilbms[BRU] = *ilbms[DEF];	/* for our brush  */
```
/*
 * Alloc two IFF handles (one for screen frame, one for brush frame)
 */

```c
    if(!(ilbms[SCR]->ParseInfo.iff = AllocIFF())) bye(noiffh,RETURN_FAIL);
    if(!(ilbms[BRU]->ParseInfo.iff = AllocIFF())) bye(noiffh,RETURN_FAIL);
```
/* Load and display an ILBM
 */
```c
    if(error = showilbm(ilbms[SCR],ilbmname))
```
	{
	printf("Can't load background \"%s\"\n",ilbmname);
	bye("",RETURN_WARN);
	}



```c
    /* These were set up by our successful showilbm() above */
    win = ilbms[SCR]->win;	/* our window */
    wrp = ilbms[SCR]->wrp;	/* our window's RastPort */
    scr = ilbms[SCR]->scr;	/* our screen */
    vp  = ilbms[SCR]->vp;		/* our screen's ViewPort */

    ScreenToFront(scr);
```
 /* Now let's load a brush and blit it into the window
  */
```c
    if(brushname)
```
	{
	if (error = loadbrush(ilbms[BRU],brushname))
	    {
	    printf("Can't load brush \"%s\"\n",brushname);
	    bye("",RETURN_WARN);
	    }
	else	/* Success */
	    {
	    D(bug("About to Blt bitmap $%lx to rp $%lx, w=%ld h=%ld\n",
		ilbms[BRU]->brbitmap,wrp,ilbms[BRU]->Bmhd.w,ilbms[BRU]->Bmhd.h));
```c
            BltBitMapRastPort(ilbms[BRU]->brbitmap,0,0,
                     		wrp,0,0,
                     		ilbms[BRU]->Bmhd.w, ilbms[BRU]->Bmhd.h,
                     		0xC0);
     	    }
```
	}

#ifdef SAVECHANGES

 /* This code is an example for Read/Modify/Write programs
  *
  * We copy off the parsed chunks we want to preserve,
  * close the IFF read file, reopen it for write,
  * and save a new ILBM which
  * will include the chunks we have preserved, but
  * with newly computed and set-up BMHD, CMAP, and CAMG.
  */

   if(!(ilbms[SCR]->ParseInfo.copiedchunks =
	copychunks(ilbms[SCR]->ParseInfo.iff,
		   ilbmprops, ilbmcollects,
		   MEMF_PUBLIC)))
		printf("error cloning chunks\n");
   else
	{
        /* we can close the file now */
   	closeifile(ilbms[SCR]);

   	printf("Test of copychunks and findchunk:\n");

   	/* Find copied CAMG chunk if any */
   	if(chunk = findchunk(ilbms[SCR]->ParseInfo.copiedchunks,ID_ILBM,ID_CAMG))
	    {
	    camg = (CamgChunk *)chunk->ch_Data;
	    printf("CAMG: $%08lx\n",camg->ViewModes);
	    }

```c
        else printf("No CAMG found\n");
```
   	/* Find copied CRNG chunks if any */
   	if(chunk = findchunk(ilbms[SCR]->ParseInfo.copiedchunks,ID_ILBM,ID_CRNG))
	    {
   	    while((chunk)&&(chunk->ch_ID == ID_CRNG))
		{
		printf("Found a CRNG chunk\n");
		chunk = chunk->ch_Next;
		}
	    }
   	else printf("No CRNG chunks found\n");
	}

```c
    printf("\nAbout to save screen as %s, adding NAME and AUTH chunks\n",
```
		savename);

```c
    if(saverror = screensave(ilbms[SCR], ilbms[SCR]->scr,
```
				ilbms[SCR]->ParseInfo.copiedchunks,
				newchunks,
				savename))
			printf("%s\n",IFFerr(saverror));

#endif

   Done = FALSE;
   while(!Done)


```c
      {
      Wait(1<<win->UserPort->mp_SigBit);
      chkmsg();
      }
```
   cleanup();
   exit(RETURN_OK);
   }


void chkmsg(void)
```c
    {
    LONG  error;
    ULONG class;
    UWORD code;
    WORD  mousex, mousey;

    while(msg = (struct IntuiMessage *)GetMsg(win->UserPort))
```
	{
	class = msg->Class;
```c
      	code  = msg->Code;
      	mousex = msg->MouseX;
      	mousey = msg->MouseY;

      	ReplyMsg(msg);
      	switch(class)
```
   	    {
	    case MOUSEBUTTONS:
	    switch(code)
		{
		/* emulate a close gadget */
		case SELECTDOWN:
		   if((mousex < 12)&&(mousey < 12))	Done = TRUE;
		   break;
		default:
		   break;
		}
```c
            case VANILLAKEY:
            switch(code)
               	{
```
		/* also quit on CTRL-C, CTRL-D, or q */
```c
               	case 'q': case 0x04: case 0x03:
                  Done = TRUE;
                  break;
```
		case 0x10:	/* CTRL-p means print */

		  /* Print the whole screen */
		  if(error=screendump(ilbms[SCR]->scr,
				0,0,
				ilbms[SCR]->scr->Width,
				ilbms[SCR]->scr->Height,
				0,0))
			printf("Screendump printer error=%ld\n",error);
		  break;

```c
               	default:
                  break;
```
		}


```c
            default:
            break;
            }
      	}
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
   if(ilbms[SCR])
	{
   	if(ilbms[SCR]->scr)		unshowilbm(ilbms[SCR]);
#ifdef SAVECHANGES
   	freechunklist(ilbms[SCR]->ParseInfo.copiedchunks);
#endif
   	if(ilbms[SCR]->ParseInfo.iff)	FreeIFF(ilbms[SCR]->ParseInfo.iff);
	}

   if(ilbms[BRU])
	{
   	if(ilbms[BRU]->brbitmap)	unloadbrush(ilbms[BRU]);
   	if(ilbms[BRU]->ParseInfo.iff) 	FreeIFF(ilbms[BRU]->ParseInfo.iff);
	}

   if(ilbms[0])
	{
	FreeMem(ilbms[0],UICOUNT * sizeof(struct ILBMInfo));
	}

   if(GfxBase) 	     CloseLibrary(GfxBase);
   if(IntuitionBase) CloseLibrary(IntuitionBase);
   if(IFFParseBase)  CloseLibrary(IFFParseBase);
   }

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)

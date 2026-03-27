---
title: devices/modules/screen.c
manual: libraries
chapter: libraries
section: devices-modules-screen-c
functions: [RethinkDisplay]
libraries: [intuition.library]
---

# devices/modules/screen.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* screen.c - 2.0 screen module for Display
 * based on scdemo, oscandemo, looki
 */

/*
Copyright (c) 1989-1999 Amiga, Inc.

Executables based on this information may be used in software
for Amiga computers. All other rights reserved.
This information is provided "as is"; no warranties are made.
All use is at your own risk, and no liability or responsibility
is assumed.
*/

#include "iffp/ilbmapp.h"

BOOL   VideoControlTags(struct ColorMap *,ULONG tags, ...);

extern struct Library *GfxBase;
extern struct Library *IntuitionBase;

struct TextAttr SafeFont = { (UBYTE *) "topaz.font", 8, 0, 0, };
UWORD  penarray[] = {~0};

/* default new window if none supplied in ilbm->nw */
struct   NewWindow      defnw = {
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


/* opendisplay - passed ILBMInfo, dimensions, modeID
 *
 *    Attempts to open correct 2.0 modeID screen and window,
 *    else an old 1.3 mode screen and window.
 *
 * Returns *window or NULL.
 */

struct Window *opendisplay(struct ILBMInfo *ilbm,
			   SHORT wide, SHORT high, SHORT deep,
			   ULONG mode)
```c
    {
    struct NewWindow newwin, *nw;

    closedisplay(ilbm);
    if(ilbm->scr = openidscreen(ilbm, wide, high, deep, mode))
```
	{
	nw = &newwin;
	if(ilbm->windef) *nw = *(ilbm->windef);
	else *nw = *(&defnw);
	nw->Screen	= ilbm->scr;

	D(bug("sizes: scr= %ld x %ld  passed= %ld x %ld\n",
		ilbm->scr->Width,ilbm->scr->Height,wide,high));

	nw->Width	= wide;
	nw->Height	= high;
	if (!(ilbm->win = OpenWindow(nw)))
	    {
	    closedisplay(ilbm);
	    D(bug("Failed to open window."));
	    }
	else
	    {
	    if(ilbm->win->Flags & BACKDROP)
		{
		ShowTitle(ilbm->scr, FALSE);
		ilbm->TBState = FALSE;
		}
	    }
	}

```c
    if(ilbm->scr)	/* nulled out by closedisplay if OpenWindow failed */
```
	{
	ilbm->vp  = &ilbm->scr->ViewPort;
	ilbm->srp = &ilbm->scr->RastPort;
	ilbm->wrp = ilbm->win->RPort;
	}


```c
    return(ilbm->win);
    }
```
void closedisplay(struct ILBMInfo *ilbm)
```c
    {
    if(ilbm)
```
	{
```c
    	if (ilbm->win)	CloseWindow(ilbm->win), ilbm->win = NULL;
    	if (ilbm->scr)	CloseScreen(ilbm->scr), ilbm->scr = NULL;
    	ilbm->vp  = NULL;
    	ilbm->srp = ilbm->wrp = NULL;
```
	}



```c
    }
```
/* openidscreen - ILBMInfo, dimensions, modeID
 *
 *    Attempts to open correct 2.0 modeID screen with centered
 *    overscan based on user's prefs,
 *    else old 1.3 mode screen.
 *
 * If ilbm->stype includes CUSTOMBITMAP, ilbm->brbitmap will be
 *   	used as the screen's bitmap.
 * If ilbm->stags is non-NULL, these tags will be added to the
 *	end of the taglist.
 *
 * Returns *screen or NULL.
 */

struct Screen *openidscreen(struct ILBMInfo *ilbm,
			    SHORT wide, SHORT high, SHORT deep,
			    ULONG mode)
```c
    {
    struct NewScreen ns;			/* for old style OpenScreen */
    struct Rectangle spos, dclip, txto, stdo, maxo, uclip;  /* display rectangles */
    struct Rectangle *uclipp;
    struct Screen   *scr = NULL;
    LONG   error, trynew;
    ULONG  bitmaptag, passedtags;
    BOOL   vctl;

    if (trynew = ((((struct Library *)GfxBase)->lib_Version >= 36)&&
          (((struct Library *)IntuitionBase)->lib_Version >= 36)))
```
	{
```c
    	/* if >= v36, see if mode is available */
```
	if(error = ModeNotAvailable(mode))
	    {
	    D(bug("Mode $%08lx not available, error=%ld:\n",mode,error));
	    /* if not available, try fall back mode */
	    mode = modefallback(mode,wide,high,deep);
	    error = ModeNotAvailable(mode);

	    D(bug("$%08lx ModeNotAvailable=%ld:\n",mode,error));
	    }

	if(error) trynew = FALSE;
	else trynew=((QueryOverscan(mode,&txto,OSCAN_TEXT))&&
			(QueryOverscan(mode,&stdo,OSCAN_STANDARD))&&
			    (QueryOverscan(mode,&maxo,OSCAN_MAX)));
	}

```c
    D(bug("\nILBM: w=%ld, h=%ld, d=%ld, mode=0x%08lx\n",
```
		wide,high,deep,mode));
```c
    D(bug("OPEN: %s.\n",
        trynew	? "Is >= 2.0 and mode available, trying OpenScreenTags"
```
		: "Not 2.0, doing old OpenScreen"));

```c
    if(trynew)
```
	{
	/* If user clip type specified and available, use it */
	if(ilbm->Video) ilbm->ucliptype = OSCAN_VIDEO;
	if((ilbm->ucliptype)&&(QueryOverscan(mode,&uclip,ilbm->ucliptype)))
		uclipp = &uclip;
	else uclipp = NULL;

	clipit(wide,high,&spos,&dclip,&txto,&stdo,&maxo,uclipp);

	D(bug("Using dclip  %ld,%ld  to  %ld,%ld... width=%ld height=%ld\n",
			dclip.MinX,dclip.MinY,dclip.MaxX,dclip.MaxY,
			dclip.MaxX-dclip.MinX+1,dclip.MaxY-dclip.MinY+1));
	D(bug("spos->minx = %ld, spos->miny = %ld\n",spos.MinX,spos.MinY));
	D(bug("DEBUG: About to attempt OpenScreenTags\n"));

	bitmaptag = ((ilbm->brbitmap)&&(ilbm->stype & CUSTOMBITMAP)) ?
		SA_BitMap : TAG_IGNORE;
	passedtags = ilbm->stags ? TAG_MORE : TAG_IGNORE;

	scr=(struct Screen *)OpenScreenTags((struct NewScreen *)NULL,
		SA_DisplayID,	mode,
		SA_Type,	ilbm->stype,
		SA_Behind,	TRUE,
		SA_Top,		spos.MinY,
		SA_Left,	spos.MinX,
		SA_Width,	wide,
		SA_Height,	high,
		SA_Depth,	deep,
		SA_DClip,	&dclip,
		SA_AutoScroll,	ilbm->Autoscroll ? TRUE : FALSE,
		SA_Title,	ilbm->stitle,
		SA_Font,	&SafeFont,
		SA_Pens,	penarray,
		SA_ErrorCode,	&error,
		bitmaptag,	ilbm->brbitmap,
		passedtags,	ilbm->stags,
		TAG_DONE
		);

	    D(bug("DEBUG: OpenScreenTags scr at 0x%lx\n",scr));

	    if(scr)
		{
		if(ilbm->Notransb)
		    {
		    vctl=VideoControlTags(scr->ViewPort.ColorMap,
				VTAG_BORDERNOTRANS_SET, TRUE,
				TAG_DONE);

	D(bug("VideoControl to set bordernotrans, error = %ld\n",vctl));

		    MakeScreen(scr);
		    RethinkDisplay();
		    }
		}
	    else modeErrorMsg(mode,error);
```c
        }

    if(!scr)
```
	{
	/* ns initialization for 1.3 old style OpenScreen only
         */
	ns.LeftEdge = ns.TopEdge = 0;
	ns.Width 	=	wide;
	ns.Height 	=	high;
	ns.Depth	=	deep;
	ns.ViewModes	= 	modefallback(mode,wide,high,deep);
	ns.DetailPen	=	0;
	ns.BlockPen	=	1;
	ns.Gadgets	=	NULL;
	ns.CustomBitMap	=	((ilbm->brbitmap)&&(ilbm->stype & CUSTOMBITMAP))
					? ilbm->brbitmap : NULL;
	ns.Font		=	&SafeFont;
	ns.DefaultTitle = 	ilbm->stitle;
	ns.Type		=	ilbm->stype & 0x01FF;  /* allow only 1.3 types */

	scr=(struct Screen *)OpenScreen(&ns);

	D(bug("DEBUG: ns.ViewModes=0x%lx, vp->Modes=0x%lx\n",
```c
                 ns.ViewModes,scr->ViewPort.Modes));
```
	D(bug("DEBUG: non-extended scr at 0x%lx (0=failure)\n",scr));
	}


```c
    return(scr);
    }
```
/*
 * modefallback - passed a mode id, attempts to provide a
 *                suitable old mode to use instead
 */

/* for old 1.3 screens */
#define MODE_ID_MASK (LACE|HIRES|HAM|EXTRA_HALFBRITE)

ULONG modefallback(ULONG mode, SHORT wide, SHORT high, SHORT deep)
{
ULONG newmode;

```c
    /* For now, simply masks out everything but old mode bits.
     * This is just a cheap way to get some kind of display open
     *   and may be totally invalid for future modes.
     * Should search the display database for a suitable mode
     * based on the specific needs of your application.
     */
    newmode = mode & MODE_ID_MASK;

    D(bug("Try 0x%08lx instead of 0x%08lx\n",newmode,mode));
    return(newmode);
```
}


/*
 * clipit - passed width and height of a display, and the text, std, and
 *          max overscan rectangles for the mode, clipit fills in the
 *          spos (screen pos) and dclip rectangles to use in centering.
 *          Centered around smallest containing user-editable oscan pref,
 *          with dclip confined to legal maxoscan limits.
 *          Screens which center such that their top is below text
 *          oscan top, will be moved up.
 *          If a non-null uclip is passed, that clip is used instead.
 */
void clipit(SHORT wide, SHORT high,
	    struct Rectangle *spos, struct Rectangle *dclip,
	    struct Rectangle *txto, struct Rectangle *stdo,
	    struct Rectangle *maxo, struct Rectangle *uclip)
{
struct  Rectangle *besto;
SHORT	minx, maxx, miny, maxy;
SHORT	txtw, txth, stdw, stdh, maxw, maxh, bestw, besth;

```c
    /* get the txt, std and max widths and heights */
    txtw = txto->MaxX - txto->MinX + 1;
    txth = txto->MaxY - txto->MinY + 1;
    stdw = stdo->MaxX - stdo->MinX + 1;
    stdh = stdo->MaxY - stdo->MinY + 1;
    maxw = maxo->MaxX - maxo->MinX + 1;
    maxh = maxo->MaxY - maxo->MinY + 1;

    if((wide <= txtw)&&(high <= txth))
```
	{
	besto = txto;
	bestw = txtw;
	besth = txth;

	D(bug("Best clip is txto\n"));
	}
    else
	{
	besto = stdo;
	bestw = stdw;
	besth = stdh;

	D(bug("Best clip is stdo\n"));
	}

```c
    D(bug("TXTO: mnx=%ld mny=%ld mxx=%ld mxy=%ld  stdw=%ld stdh=%ld\n",
```
		txto->MinX,txto->MinY,txto->MaxX,txto->MaxY,txtw,txth));
```c
    D(bug("STDO: mnx=%ld mny=%ld mxx=%ld mxy=%ld  stdw=%ld stdh=%ld\n",
```
		stdo->MinX,stdo->MinY,stdo->MaxX,stdo->MaxY,stdw,stdh));
```c
    D(bug("MAXO: mnx=%ld mny=%ld mxx=%ld mxy=%ld  maxw=%ld maxh=%ld\n",
```
		maxo->MinX,maxo->MinY,maxo->MaxX,maxo->MaxY,maxw,maxh));

```c
    if(uclip)
```
	{
	*dclip = *uclip;
```c
    	spos->MinX = uclip->MinX;
```
	spos->MinY = uclip->MinY;

	D(bug("UCLIP: mnx=%ld mny=%ld maxx=%ld maxy=%ld\n",
			dclip->MinX,dclip->MinY,dclip->MaxX,dclip->MaxY));
	}
    else
	{
	/* CENTER the screen based on best oscan prefs
 	* but confine dclip within max oscan limits
 	*
 	* FIX MinX first */
	spos->MinX = minx = besto->MinX - ((wide - bestw) >> 1);
	maxx = wide + minx - 1;
	if(maxx > maxo->MaxX)  maxx = maxo->MaxX;	/* too right */
	if(minx < maxo->MinX)  minx = maxo->MinX;	/* too left  */

	D(bug("DCLIP: minx adjust from %ld to %ld\n",spos->MinX,minx));

	/* FIX MinY */
	spos->MinY = miny = besto->MinY - ((high - besth) >> 1);
	/* if lower than top of txto, move up */
	spos->MinY = miny = MIN(spos->MinY,txto->MinY);
	maxy = high + miny - 1;
	if(maxy > maxo->MaxY)  maxy = maxo->MaxY;	/* too down  */
	if(miny < maxo->MinY)  miny = maxo->MinY;	/* too up    */

	D(bug("DCLIP: miny adjust from %ld to %ld\n",spos->MinY,miny));

	/* SET up dclip */
	dclip->MinX = minx;
	dclip->MinY = miny;
	dclip->MaxX = maxx;
	dclip->MaxY = maxy;

	D(bug("CENTER: mnx=%ld mny=%ld maxx=%ld maxy=%ld\n",
			dclip->MinX,dclip->MinY,dclip->MaxX,dclip->MaxY));
	}
}


void modeErrorMsg(ULONG mode, ULONG errorcode)
   {
   UBYTE *s=NULL;

	D(bug("DEBUG: Can't open mode ID 0x%08lx screen: ",mode));

```c
    	switch ( errorcode )
```
	{
	case OSERR_NOMEM:
	    s="Not enough memory.";
	    break;
	case OSERR_NOCHIPMEM:
	    s="Not enough chip memory.";
	    break;
#ifdef DEBUG
	case OSERR_NOMONITOR:
	    s="monitor not available.";
	    break;

	case OSERR_NOCHIPS:
	    s="new chipset not available.";
	    break;

	case OSERR_PUBNOTUNIQUE:
	    s="public screen already open.";
	    break;
	case OSERR_UNKNOWNMODE:
	    s="mode ID is unknown.";
	    break;
	default:
	    message("unknown mode error %ld\n",errorcode);
#endif
	}


```c
    if(s) message("%s\n",s);
    }
```
/*----------------------------------------------------------------------*/

BOOL VideoControlTags(struct ColorMap *cm, ULONG tags, ...)


```c
    {
    return (VideoControl(cm, (struct TagItem *)&tags));
    }
```
/*----------------------------------------------------------------------*/

---

## See Also

- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)

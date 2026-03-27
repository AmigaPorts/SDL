---
title: Devices/iffp/ilbmapp.h
manual: devices
chapter: devices
section: devices-iffp-ilbmapp-h
functions: []
libraries: []
---

# Devices/iffp/ilbmapp.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* ilbmapp.h
 * - definition of ILBMInfo structure
 * - inclusion of includes needed by modules and application
 * - application-specific definitions
 *
 * 07/03/91 - added ilbm->stags for screen.c
 */
#ifndef ILBMAPP_H
#define ILBMAPP_H

#include "iffp/ilbm.h"

struct ILBMInfo {
	/* general parse.c related */
	struct  ParseInfo ParseInfo;

	/* The following variables are for
	 * programs using the ILBM-related modules.
	 * They may be removed or replaced for
	 * programs parsing other forms.
	 */
	/* ILBM */
	BitMapHeader Bmhd;		/* filled in by load and save ops */
	ULONG	camg;			/* filled in by load and save ops */
	Color4	*colortable;		/* allocated by getcolors */
	ULONG	ctabsize;		/* size of colortable in bytes */
	USHORT	ncolors;		/* number of color registers loaded */
	USHORT  Reserved1;

	/* for getbitmap.c */
	struct BitMap *brbitmap;	/* for loaded brushes only */

	/* for screen.c */
	struct Screen *scr;		/* screen of loaded display   */
	struct Window *win;		/* window of loaded display   */
	struct ViewPort *vp;		/* viewport of loaded display */
	struct RastPort	*srp;		/* screen's rastport */
	struct RastPort *wrp;		/* window's rastport */
	BOOL TBState;			/* state of titlebar hiddenness */

	/* caller preferences */
	struct NewWindow *windef;	/* definition for window */
	UBYTE *stitle;		/* screen title */
	LONG stype;		/* additional screen types */
	WORD ucliptype;		/* overscan display clip type */
	BOOL EHB;		/* default to EHB for 6-plane/NoCAMG */
	BOOL Video;		/* Max Video Display Clip (non-adjustable) */
	BOOL Autoscroll;	/* Enable Autoscroll of screens */
	BOOL Notransb;		/* Borders not transparent to genlock */
	ULONG *stags;		/* Additional screen tags for 2.0 screens */

	ULONG Reserved[7];	/* must be 0 for now */

	/* Application-specific variables may go here */
	};

/* referenced by modules */

extern struct Library *IFFParseBase;

/* protos for application module(s) */

#endif


---
title: include/graphics/gfxnodes.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-graphics-gfxnodes-h
functions: []
libraries: []
---

# include/graphics/gfxnodes.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	GRAPHICS_GFXNODES_H
#define	GRAPHICS_GFXNODES_H
/*
**	$VER: gfxnodes.h 39.0 (21.8.1991)
**	Includes Release 44.1
**
**	graphics extended node definintions
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

struct	ExtendedNode	{
struct	Node	*xln_Succ;
struct	Node	*xln_Pred;
UBYTE	xln_Type;
BYTE	xln_Pri;
char	*xln_Name;
UBYTE	xln_Subsystem;
UBYTE	xln_Subtype;
LONG	xln_Library;
LONG	(*xln_Init)();
};

#define SS_GRAPHICS	0x02

#define	VIEW_EXTRA_TYPE		1
#define	VIEWPORT_EXTRA_TYPE	2
#define	SPECIAL_MONITOR_TYPE	3
#define	MONITOR_SPEC_TYPE	4

#endif	/* GRAPHICS_GFXNODES_H */


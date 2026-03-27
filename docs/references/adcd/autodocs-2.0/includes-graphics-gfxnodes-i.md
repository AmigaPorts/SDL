---
title: Includes/graphics/gfxnodes.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-graphics-gfxnodes-i
functions: []
libraries: []
---

# Includes/graphics/gfxnodes.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	GRAPHICS_GFXNODES_I
GRAPHICS_GFXNODES_I	EQU	1
**
**	$Filename: graphics/gfxnodes.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
**
**	graphics extended node definitions
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
**


    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC
	STRUCTURE	XLN,0
	APTR	XLN_SUCC
	APTR	XLN_PRED
	UBYTE	XLN_TYPE
	BYTE	XLN_PRI
	APTR	XLN_NAME
	UBYTE	XLN_SUBSYSTEM
	UBYTE	XLN_SUBTYPE
	LONG	XLN_LIBRARY
	LONG	XLN_INIT
	LABEL	XLN_SIZE

SS_GRAPHICS	EQU	$02

VIEW_EXTRA_TYPE		EQU	1
VIEWPORT_EXTRA_TYPE	EQU	2
SPECIAL_MONITOR_TYPE	EQU	3
MONITOR_SPEC_TYPE	EQU	4

	ENDC	; GRAPHICS_GFXNODES_I


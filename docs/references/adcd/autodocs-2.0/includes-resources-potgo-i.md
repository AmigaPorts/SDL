---
title: Includes/resources/potgo.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-resources-potgo-i
functions: []
libraries: []
---

# Includes/resources/potgo.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	RESOURCES_POTGO_I
RESOURCES_POTGO_I	EQU	1
**
**	$Filename: resources/potgo.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.0 $
**	$Date: 90/04/13 $
**
**	potgo resource name
**
**	(C) Copyright 1986-1999 Amiga, Inc.
**	    All Rights Reserved
**
POTGONAME MACRO
		dc.b	'potgo.resource',0
		ds.w	0
	ENDM

	ENDC	; RESOURCES_POTGO_I


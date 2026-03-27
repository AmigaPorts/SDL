---
title: Includes/resources/battmem.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-resources-battmem-i
functions: []
libraries: []
---

# Includes/resources/battmem.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	RESOURCES_BATTMEM_I
RESOURCES_BATTMEM_I	SET	1
**
**	$Filename: resources/battmem.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.3 $
**	$Date: 90/05/01 $
**
**	BattMem resource name strings.
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**		All Rights Reserved
**

BATTMEMNAME	MACRO
		dc.b	'battmem.resource',0
		ds.w	0
		ENDM

	ENDC	; RESOURCES_BATTMEM_I


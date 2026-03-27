---
title: Includes/graphics/sprite.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-graphics-sprite-i
functions: []
libraries: []
---

# Includes/graphics/sprite.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	GRAPHICS_SPRITE_I
GRAPHICS_SPRITE_I	SET	1
**
**	$Filename: graphics/sprite.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
**
**
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
**


    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC
   STRUCTURE   SimpleSprite,0
   APTR        ss_posctldata
   WORD        ss_height
   WORD        ss_x
   WORD        ss_y
   WORD        ss_num
   LABEL       ss_SIZEOF

	ENDC	; GRAPHICS_SPRITE_I


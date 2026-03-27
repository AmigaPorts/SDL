---
title: Includes/clib/macros.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-macros-h
functions: []
libraries: []
---

# Includes/clib/macros.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef CLIB_MACROS_H
#define CLIB_MACROS_H
/*
**	$Filename: clib/macros.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.0 $
**	$Date: 90/11/30 $
**
**	C prototypes
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)<(b)?(a):(b))
#define ABS(x)	    ((x<0)?(-(x)):(x))

#endif	/* CLIB_MACROS_H */


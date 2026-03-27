---
title: III-1/Ispy_stubs.asm
manual: amiga-mail
chapter: amiga-mail
section: iii-1-ispy-stubs-asm
functions: []
libraries: []
---

# III-1/Ispy_stubs.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**
**      ISpy stubs
**
**
** Copyright (c) 1991-1999 Amiga, Inc.
**
** This example is provided in electronic form by Amiga,
** Inc. for use with the Amiga Mail Volume II technical publication.
** Amiga Mail Volume II contains additional information on the correct
** usage of the techniques and operating system functions presented in
** these examples.  The source and executable code of these examples may
** only be distributed in free electronic form, via bulletin board or
** as part of a fully non-commercial and freely redistributable
** diskette.  Both the source and executable code (including comments)
** must be included, without modification, in any copy.  This example
** may not be published in printed form or distributed with any
** commercial product. However, the programming techniques and support
** routines set forth in these examples may be used in the development
** of original executable software products for Amiga
** computers.
**
** All other rights reserved.
**
** This example is provided "as-is" and is subject to change; no
** warranties are made.  All use is at your own risk. No liability or
** responsibility is assumed.
**
**
	INCLUDE "exec/types.i"

	SECTION CODE

	XREF	_SysBase

	XREF    _LVOForbid
	XREF    _LVOPermit

	XREF	_newOpenScreen
	XREF	_newOpenWindowTagList
	XREF	_newFreeMem
	XREF	_newSetFont

	XDEF	_OpenScreenStub
	XDEF	_OpenWindowTagListStub
	XDEF	_FreeMemStub
	XDEF	_SetFontStub


_OpenScreenStub:
	movem.l	a4,-(sp)
	lea		4(sp),a4
	jsr		_newOpenScreen
	movem.l	(sp)+,a4
	rts

_OpenWindowTagListStub:
	movem.l	a4,-(sp)
	lea		4(sp),a4
	jsr		_newOpenWindowTagList
	movem.l	(sp)+,a4
	rts

_FreeMemStub:
	movem.l	a4,-(sp)
	lea		4(sp),a4
	jsr		_newFreeMem
	movem.l	(sp)+,a4
	rts

_SetFontStub:
	movem.l	a4,-(sp)
	lea		4(sp),a4
	jsr		_newSetFont
	movem.l	(sp)+,a4
	rts

	END


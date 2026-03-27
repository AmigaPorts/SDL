---
title: Includes/dos/stdio.i
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-dos-stdio-i
functions: []
libraries: []
---

# Includes/dos/stdio.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND DOS_STDIO_I
DOS_STDIO_I	EQU	1
**
**	$Filename: dos/stdio.i $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.2 $
**	$Date: 91/11/01 $
**
**	ANSI-like stdio defines for dos buffered I/O
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	    All Rights Reserved
**


* types for SetVBuf()
BUF_LINE	EQU	0	; flush on \n, etc
BUF_FULL	EQU	1	; never flush except when needed
BUF_NONE	EQU	2	; no buffering

* EOF return value
ENDSTREAMCH	EQU	-1

	ENDC	; DOS_STDIO_I


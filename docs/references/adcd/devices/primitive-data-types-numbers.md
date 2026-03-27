---
title: Primitive Data Types / Numbers
manual: devices
chapter: devices
section: primitive-data-types-numbers
functions: []
libraries: []
---

# Primitive Data Types / Numbers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Numeric types supported are two's complement binary integers in the format
used by the MC68000 processor - high byte first, high word first - the
reverse of 8088 and 6502 format.

	UBYTE	 8 bits unsigned
	WORD	16 bits signed
	UWORD	16 bits unsigned
	LONG	32 bits signed

The actual type definitions depend on the CPU and the compiler.  In this
document, we'll express data type definitions in the C programming
language. [See C, A Reference Manual.]  In 68000 Lattice C:

	typedef unsigned char	UBYTE;	/*  8 bits unsigned	*/
	typedef short		WORD;	/* 16 bits signed	*/
	typedef unsigned short	UWORD;	/* 16 bits unsigned	*/
	typedef long		LONG;	/* 32 bits signed	*/


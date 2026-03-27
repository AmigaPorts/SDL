---
title: Includes/libraries/mathffp.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-libraries-mathffp-h
functions: [SPAbs, SPAdd, SPCeil, SPCmp, SPDiv, SPFix, SPFloor, SPFlt, SPMul, SPNeg, SPSub, SPTst]
libraries: [mathffp.library]
---

# Includes/libraries/mathffp.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	LIBRARIES_MATHFFP_H
#define	LIBRARIES_MATHFFP_H 1
/*
**	$Filename: libraries/mathffp.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.2 $
**	$Date: 90/05/01 $
**
**	general floating point declarations
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef PI
#define PI	  ((float) 3.141592653589793)
#endif
#define TWO_PI	  (((float) 2) * PI)
#define PI2	  (PI / ((float) 2))
#define PI4	  (PI / ((float) 4))
#ifndef E
#define E	  ((float) 2.718281828459045)
#endif
#define LOG10	  ((float) 2.302585092994046)

#define FPTEN	  ((float) 10.0)
#define FPONE	  ((float) 1.0)
#define FPHALF	  ((float) 0.5)
#define FPZERO	  ((float) 0.0)

#define trunc(x)  ((int) (x))
#define round(x)  ((int) ((x) + 0.5))
#define itof(i)   ((float) (i))

#define	fabs	SPAbs
#define floor	SPFloor
#define	ceil	SPCeil

#define	tan	SPTan
#define	atan	SPAtan
#define cos	SPCos
#define acos	SPAcos
#define sin	SPSin
#define asin	SPAsin
#define exp	SPExp
#define pow(a,b)	SPPow((b),(a))
#define log	SPLog
#define log10	SPLog10
#define sqrt	SPSqrt

#define	sinh	SPSinh
#define cosh	SPCosh
#define tanh	SPTanh


int	 SPFix();			  /* Basic math functions */
float	 SPFlt();
int	 SPCmp();
int	 SPTst();
float	 SPAbs();
float	 SPFloor();
float	 SPCeil();
#ifndef abs
float	 abs();
#endif
float	 SPNeg();
float	 SPAdd();
float	 SPSub();
float	 SPMul();
float	 SPDiv();

float	 SPAsin(),  SPAcos(),  SPAtan();  /* Transcendental math functions */
float	 SPSin(),   SPCos(),   SPTan(),   SPSincos();
float	 SPSinh(),  SPCosh(),  SPTanh();
float	 SPExp(),   SPLog(),   SPLog10(), SPPow();
float	 SPSqrt(),  SPFieee();

float	 afp(),    dbf();		  /* Math conversion functions */

#endif	/* LIBRARIES_MATHFFP_H */

---

## See Also

- [SPAbs — mathffp.library](../autodocs/mathffp.library.md#spabs)
- [SPAdd — mathffp.library](../autodocs/mathffp.library.md#spadd)
- [SPCeil — mathffp.library](../autodocs/mathffp.library.md#spceil)
- [SPCmp — mathffp.library](../autodocs/mathffp.library.md#spcmp)
- [SPDiv — mathffp.library](../autodocs/mathffp.library.md#spdiv)
- [SPFix — mathffp.library](../autodocs/mathffp.library.md#spfix)
- [SPFloor — mathffp.library](../autodocs/mathffp.library.md#spfloor)
- [SPFlt — mathffp.library](../autodocs/mathffp.library.md#spflt)
- [SPMul — mathffp.library](../autodocs/mathffp.library.md#spmul)
- [SPNeg — mathffp.library](../autodocs/mathffp.library.md#spneg)
- [SPSub — mathffp.library](../autodocs/mathffp.library.md#spsub)
- [SPTst — mathffp.library](../autodocs/mathffp.library.md#sptst)

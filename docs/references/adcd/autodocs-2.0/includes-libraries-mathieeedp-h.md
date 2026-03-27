---
title: Includes/libraries/mathieeedp.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-libraries-mathieeedp-h
functions: [IEEEDPAbs, IEEEDPAdd, IEEEDPCeil, IEEEDPCmp, IEEEDPDiv, IEEEDPFix, IEEEDPFloor, IEEEDPFlt, IEEEDPMul, IEEEDPNeg, IEEEDPSub, IEEEDPTst]
libraries: [mathieeedoubbas.library]
---

# Includes/libraries/mathieeedp.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	LIBRARIES_MATHIEEEDP_H
#define	LIBRARIES_MATHIEEEDP_H
/*
**	$Filename: libraries/mathieeedp.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.1 $
**	$Date: 90/07/13 $
**	Include file to use for <math.h>
**
**	(C) Copyright 1987-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef PI
#define PI	((double)	3.141592653589793))
#endif

#define TWO_PI	(((double)	2)	* PI)
#define PI2	(PI/((double)2))
#define PI4	(PI/((double)4))

#ifndef	E
#define	E	((double)	2.718281828459045)
#endif

#define LOG10	((double)	2.302585092994046)
#define FPTEN	((double)	10.0)
#define	FPONE	((double)	1.0)
#define FPHALF	((double)	0.5)
#define FPZERO	((double)	0.0)
#define trunc(x)	((int)	(x))
#define round(x)	((int)	((x) + 0.5))
#define itof(i)		((double) (i))

#define	fabs	IEEEDPAbs
#define floor	IEEEDPFloor
#define	ceil	IEEEDPCeil

#define	tan	IEEEDPTan
#define	atan	IEEEDPAtan
#define cos	IEEEDPCos
#define acos	IEEEDPAcos
#define sin	IEEEDPSin
#define asin	IEEEDPAsin
#define exp	IEEEDPExp
#define pow(a,b)	IEEEDPPow((b),(a))
#define log	IEEEDPLog
#define log10	IEEEDPLog10
#define sqrt	IEEEDPSqrt

#define	sinh	IEEEDPSinh
#define cosh	IEEEDPCosh
#define tanh	IEEEDPTanh


double	IEEEDPTan(),IEEEDPAtan();
double	IEEEDPCos(),IEEEDPACos();
double	IEEEDPSin(),IEEEDPASin();
double	IEEEDPExp(),IEEEDPLog();
double	IEEEDPSqrt();
double	IEEEDPLog10(),IEEEDPPow();
double	IEEEDPSincos();
double	IEEEDPSinh(),IEEEDPCosh(),IEEEDPTanh();
float	IEEEDPTieee();
double	IEEEDPFieee();

int	IEEEDPFix();
int	IEEEDPCmp(),IEEEDPTst();
double	IEEEDPFlt();
double	IEEEDPAbs();
double	IEEEDPNeg();
double	IEEEDPAdd();
double	IEEEDPSub();
double	IEEEDPMul();
double	IEEEDPDiv();
double	IEEEDPFloor();
double	IEEEDPCeil();

#endif	/* LIBRARIES_MATHIEEEDP_H */

---

## See Also

- [IEEEDPAbs — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpabs)
- [IEEEDPAdd — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpadd)
- [IEEEDPCeil — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpceil)
- [IEEEDPCmp — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpcmp)
- [IEEEDPDiv — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpdiv)
- [IEEEDPFix — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpfix)
- [IEEEDPFloor — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpfloor)
- [IEEEDPFlt — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpflt)
- [IEEEDPMul — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpmul)
- [IEEEDPNeg — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpneg)
- [IEEEDPSub — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpsub)
- [IEEEDPTst — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedptst)

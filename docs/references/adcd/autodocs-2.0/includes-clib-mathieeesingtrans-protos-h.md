---
title: Includes/clib/mathieeesingtrans_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-mathieeesingtrans-protos-h
functions: []
libraries: []
---

# Includes/clib/mathieeesingtrans_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_MATHIEEESINGTRANS_PROTOS_H
#define  CLIB_MATHIEEESINGTRANS_PROTOS_H
/*
**	$Filename: clib/mathieeesingtrans_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.3 $
**	$Date: 90/11/07 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
FLOAT IEEESPAtan( FLOAT parm );
FLOAT IEEESPSin( FLOAT parm );
FLOAT IEEESPCos( FLOAT parm );
FLOAT IEEESPTan( FLOAT parm );
FLOAT IEEESPSincos( FLOAT *cosptr, FLOAT parm );
FLOAT IEEESPSinh( FLOAT parm );
FLOAT IEEESPCosh( FLOAT parm );
FLOAT IEEESPTanh( FLOAT parm );
FLOAT IEEESPExp( FLOAT parm );
FLOAT IEEESPLog( FLOAT parm );
FLOAT IEEESPPow( FLOAT exp, FLOAT arg );
FLOAT IEEESPSqrt( FLOAT parm );
FLOAT IEEESPTieee( FLOAT parm );
FLOAT IEEESPFieee( FLOAT parm );
FLOAT IEEESPAsin( FLOAT parm );
FLOAT IEEESPAcos( FLOAT parm );
FLOAT IEEESPLog10( FLOAT parm );
#endif	 /* CLIB_MATHIEEESINGTRANS_PROTOS_H */


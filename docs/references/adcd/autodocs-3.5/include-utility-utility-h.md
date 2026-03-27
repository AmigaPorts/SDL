---
title: include/utility/utility.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-utility-utility-h
functions: []
libraries: []
---

# include/utility/utility.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef UTILITY_UTILITY_H
#define UTILITY_UTILITY_H
/*
**	$VER: utility.h 39.2 (18.9.1992)
**	Includes Release 44.1
**
**	utility.library include file
**
**	(C) Copyright 1992-1999 Amiga, Inc.
**	All Rights Reserved
*/

/*****************************************************************************/


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif


/*****************************************************************************/


#define UTILITYNAME "utility.library"


struct UtilityBase
{
```c
    struct Library ub_LibNode;
    UBYTE	   ub_Language;
    UBYTE	   ub_Reserved;
```
};


/*****************************************************************************/


#endif /* UTILITY_UTILITY_H */


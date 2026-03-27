---
title: include/utility/date.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-utility-date-h
functions: []
libraries: []
---

# include/utility/date.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef UTILITY_DATE_H
#define UTILITY_DATE_H
/*
**	$VER: date.h 39.1 (20.1.1992)
**	Includes Release 44.1
**
**	Date conversion routines ClockData definition.
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	All Rights Reserved
*/

/*****************************************************************************/


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif


/*****************************************************************************/


struct ClockData
{
```c
    UWORD sec;
    UWORD min;
    UWORD hour;
    UWORD mday;
    UWORD month;
    UWORD year;
    UWORD wday;
```
};


/*****************************************************************************/


#endif /* UTILITY_DATE_H */


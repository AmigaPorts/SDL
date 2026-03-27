---
title: Devices/modules/unpacker.c
manual: devices
chapter: devices
section: devices-modules-unpacker-c
functions: []
libraries: []
---

# Devices/modules/unpacker.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include "iffp/ilbm.h"
#include "iffp/packer.h"

/*----------------------------------------------------------------------*
 * unpacker.c Convert data from "cmpByteRun1" run compression. 11/15/85
 *
 * Based on code by Jerry Morrison and Steve Shaw, Electronic Arts.
 * This software is in the public domain.
 *
 *	control bytes:
 *	 [0..127]   : followed by n+1 bytes of data.
 *	 [-1..-127] : followed by byte to be repeated (-n)+1 times.
 *	 -128       : NOOP.
 *
 * This version for the Amiga computer.
 *----------------------------------------------------------------------*/

/*----------- UnPackRow ------------------------------------------------*/

#define UGetByte()	(*source++)
#define UPutByte(c)	(*dest++ = (c))

/* Given POINTERS to POINTER variables, unpacks one row, updating the source
 * and destination pointers until it produces dstBytes bytes.
 */

BOOL unpackrow(BYTE **pSource, BYTE **pDest, WORD srcBytes0, WORD dstBytes0)
```c
    {
    register BYTE *source = *pSource;
    register BYTE *dest   = *pDest;
    register WORD n;
    register BYTE c;
    register WORD srcBytes = srcBytes0, dstBytes = dstBytes0;
    BOOL error = TRUE;	/* assume error until we make it through the loop */
    WORD minus128 = -128;  /* get the compiler to generate a CMP.W */

    while( dstBytes > 0 )  {
```
	if ( (srcBytes -= 1) < 0 )  goto ErrorExit;
```c
    	n = UGetByte();

    	if (n >= 0) {
```
	    n += 1;
	    if ( (srcBytes -= n) < 0 )  goto ErrorExit;
	    if ( (dstBytes -= n) < 0 )  goto ErrorExit;
	    do {  UPutByte(UGetByte());  } while (--n > 0);
	    }

```c
    	else if (n != minus128) {
```
	    n = -n + 1;
	    if ( (srcBytes -= 1) < 0 )  goto ErrorExit;
	    if ( (dstBytes -= n) < 0 )  goto ErrorExit;
	    c = UGetByte();
	    do {  UPutByte(c);  } while (--n > 0);
	    }
	}

```c
    error = FALSE;	/* success! */
```
  ErrorExit:


```c
    *pSource = source;  *pDest = dest;
    return(error);
    }
```
/* end */


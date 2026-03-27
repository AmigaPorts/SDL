# include/graphics/graphint.h


#ifndef	GRAPHICS_GRAPHINT_H
#define	GRAPHICS_GRAPHINT_H
/*
**	$VER: graphint.h 39.0 (23.9.1991)
**	Includes Release 44.1
**
**
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

/* structure used by AddTOFTask */
struct Isrvstr
{
```c
    struct Node is_Node;
    struct Isrvstr *Iptr;   /* passed to srvr by os */
    LONG (*code)();
    LONG (*ccode) __CLIB_PROTOTYPE((APTR));
    APTR Carg;
```
};

#endif	/* GRAPHICS_GRAPHINT_H */


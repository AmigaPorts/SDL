---
title: 31 Commodities Exchange Library / Commodity Tool Types
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-commodity-tool-types
functions: []
libraries: []
---

# 31 Commodities Exchange Library / Commodity Tool Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A goal of Commodities Exchange is to improve user control over input
handlers.  One way in which it accomplishes this goal is through the use
of standard icon Tool Types.  The user will expect commodities to
recognize the set of standard Tool Types:


        CX_PRIORITY
        CX_POPUP
        CX_POPKEY
CX_PRIORITY lets the user set the priority of a commodity.  The string
"CX_PRIORITY=" is a number from -128 to 127.  The higher the number, the
higher the priority of the commodity, giving it access to input events
before lower priority commodities.  All commodities should recognize
CX_PRIORITY.

CX_POPUP and CX_POPKEY are only relevant to commodities with a window.
The string "CX_POPUP=" should be followed by a "yes" or "no", telling the
commodity if it should or shouldn't show its window when it is first
launched.  CX_POPKEY is followed by a string describing the key to use as
a hot key for making the commodity's window appear (pop up).  The
description string for CX_POPKEY describes an input event.  The specific
format of the string is discussed in the next section
("[Filter Objects and the Input Description String](libraries/31-commodities-exchange-filter-objects-and-input.md)").

Commodities Exchange's support library functions simplify parsing
arguments from either the Workbench or the Shell (CLI).  A Workbench
launched commodity gets its arguments directly from the Tool Types in the
commodity's icon.  Shell launched commodities get their arguments from the
command line, but these arguments look exactly like the Tool Types from
the commodity's icon.  For example, the following command line sets the
priority of a commodity called HotKey to 5:


```c
    HotKey "CX_PRIORITY=5"
```
Commodities Exchange has several support library functions used to parse
arguments:


```c
    tooltypearray = UBYTE **ArgArrayInit(LONG argc, UBYTE **argv);
                    void    ArgArrayDone(void);

    tooltypevalue = STRPTR  ArgString(UBYTE **tooltypearray,
                                      STRPTR tooltype,
                                      STRPTR defaultvalue);
    tooltypevalue = LONG  *ArgInt(UBYTE **tooltypearray,
                                  STRPTR tooltype,
                                  LONG defaultvalue);
```
[ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md) initializes a Tool Type array of strings which it creates
from the startup arguments, argc and argv.  It doesn't matter if these
startup arguments come from the Workbench or from a Shell, ArgArrayInit()
can extract arguments from either source.  Because ArgArrayInit() uses
some icon.library functions, a commodity is responsible for opening that
library before using the function.

[ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md) also uses some resources that must be returned to the
system when the commodity is done.  [ArgArrayDone()](autodocs-2.0/amiga-lib-argarraydone.md) performs this clean up.
Like ArgArrayInit(), ArgArrayDone() uses icon.library, so the library has
to remain open until ArgArrayDone() is finished.

The support library has two functions that use the Tool Type array set up
by [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md), [ArgString()](autodocs-2.0/amiga-lib-argstring.md) and [ArgInt()](autodocs-2.0/amiga-lib-argint.md).  ArgString() scans the Tool
Type array for a specific Tool Type.  If successful, it returns a pointer
to the value associated with that Tool Type.  If it doesn't find the Tool
Type, it returns the default value passed to it.  ArgInt() is similar to
ArgString().  It also scans the ArgArrayInit()'s Tool Type array, but it
returns a LONG rather than a string pointer.  ArgInt() extracts the
integer value associated with a Tool Type, or, if that Tool Type is not
present, it returns the default value.

Of course, these Tool Type parsing functions are not restricted to the
standard Commodities Exchange Tool Types.  A commodity that requires any
arguments should use these functions along with custom Tool Types to
obtain these values.  Because the Commodities Exchange standard arguments
are processed as Tool Types, the user will expect to enter other arguments
as Tool Types too.


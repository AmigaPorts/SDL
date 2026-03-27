---
title: Tool Types
manual: amiga-mail
chapter: amiga-mail
section: tool-types
functions: []
libraries: []
---

# Tool Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A goal of Commodities Exchange is to improve user control over input
handlers.  One way in which it accomplishes this is through the use of
standard ToolTypes.  The user will expect commodities to recognize the
set of standard tool types:


    CX_PRIORITY
    CX_POPUP
    CX_POPKEY
CX_PRIORITY lets the user set the priority of a commodity.  The string
"CX_PRIORITY=" is a number from -128 to 127.  The higher the number,
the higher the priority of the commodity, giving it access to input
events before lower priority commodities.  All commodities should
recognize CX_PRIORITY.

CX_POPUP and CX_POPKEY are only relevant to commodities with a window.
The string "CX_POPUP=" should be followed by a "yes" or "no", telling
the commodity if it should or shouldn't show its window when it is
first launched.  CX_POPKEY is followed by a st ring describing the key
to use as a hot key for "popping up" the commodity's window.  The
description string for CX_POPKEY describes an input event.  The
specific format of the string is discussed later in this article.

Commodities Exchange's support library functions simplify parsing
arguments from either the Workbench or a CLI.  A Workbench launched
commodity gets its arguments directly from the tool types in the
commodity's icon.  CLI launched commodities get their ar guments from
the command line, but these arguments look exactly like the tool types
from the commodity's icon.  For example, the following command line
sets the priority of a commodity called HotKey to 5:


```c
    HotKey "CX_PRIORITY=5"
```
Commodities Exchange has several support library functions used to
parse arguments:


```c
    tooltypearray = char **ArgArrayInit(int argc, char **argv);
    void ArgArrayDone(void);
    tooltypevalue = char *ArgString(char **tooltypearray,
                                char *tooltype, char *defaultvalue);
    tooltypevalue = LONG *ArgInt(char **tooltypearray,
                                char *tooltype, LONG defaultvalue);
```
ArgArrayInit() initializes a tool type array of strings which it
creates from the startup arguments, argc and argv.  It doesn't matter
if these startup arguments come from the Workbench or from a CLI,
ArgArrayInit() can extract arguments from either source.  Because
ArgArrayInit() uses some icon.library functions, a commodity is
responsible for opening that library before using the function.

ArgArrayInit() also uses some resources that must be returned to the
system when the commodity is done.  ArgArrayDone() performs this clean
up.  Like ArgArrayInit(), ArgArrayDone() uses icon.library, so the
library has to remain open until ArgArrayDone() is finished.

The support library has two functions that use the tool type array
set up by ArgArrayInit(), ArgString() and ArgInt().  ArgString()
scans the tool type array for a specific tool type.  If successful,
it returns a pointer to the value associated with that tool type.  If
it doesn't find the tool type, it returns the default value passed to
it. ArgInt() is similar to ArgString().  It also scans the
ArgArrayInit()'s tool type array, but it returns a LONG rather than a
string pointer.  ArgInt() extracts the i nteger value associated with
a tool type, or, if that tool type is not present, it returns the
default value.

Of course, these tool type parsing functions are not restricted to the
standard Commodities Exchange tool types.  A commodity that requires
any arguments should use these functions along with custom tool types
to obtain these values.  Because the Commodit ies Exchange standard
arguments are processed as tool types, the user will expect to enter
other arguments as tool types.


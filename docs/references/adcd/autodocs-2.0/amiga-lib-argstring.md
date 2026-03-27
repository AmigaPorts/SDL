---
title: amiga.lib/ArgString
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-argstring
functions: []
libraries: []
---

# amiga.lib/ArgString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ArgString -- return a string pointer from a ToolTypes array. (V36)
```
SYNOPSIS

```c
    string = ArgString(tt,entry,defaultstring)

    STRPTR ArgString(UBYTE **,STRPTR,STRPTR);
```
FUNCTION

```c
    This function looks in the ToolTypes array 'tt' returned
    by [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md) for 'entry' and returns the value associated
    with it. 'tt' is in standard ToolTypes format such as:

            ENTRY=Value

    This function returns a pointer to the Value string.

    If 'entry' is not found, 'defaultstring' is returned.
```
INPUTS

```c
    tt - a ToolTypes array as returned by [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md)
    entry - the entry in the ToolTypes array to search for
    defaultstring - the value to return in case 'entry' is not found within
                    the ToolTypes array
```
RESULTS

    value - the value associated with 'entry', or defaultstring if 'entry'
            is not in the ToolTypes array
SEE ALSO

```c
    [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md)
```

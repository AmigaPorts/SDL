---
title: amiga.lib/ArgInt
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-argint
functions: []
libraries: []
---

# amiga.lib/ArgInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ArgInt -- return an integer value from a ToolTypes array. (V36)
```
SYNOPSIS

```c
    value = ArgInt(tt,entry,defaultval)

    LONG ArgInt(UBYTE **,STRPTR,LONG);
```
FUNCTION

```c
    This function looks in the ToolTypes array 'tt' returned
    by [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md) for 'entry' and returns the value associated
    with it. 'tt' is in standard ToolTypes format such as:

            ENTRY=Value

    The Value string is passed to atoi() and the result is returned by
    this function.

    If 'entry' is not found, the integer 'defaultval' is returned.
```
INPUTS

```c
    tt - a ToolTypes array as returned by [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md)
    entry - the entry in the ToolTypes array to search for
    defaultval - the value to return in case 'entry' is not found within
                 the ToolTypes array
```
RESULTS

    value - the value associated with 'entry', or defaultval if 'entry'
            is not in the ToolTypes array
NOTES

    This function requires that dos.library V36 or higher be opened.
SEE ALSO

```c
    [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md)
```

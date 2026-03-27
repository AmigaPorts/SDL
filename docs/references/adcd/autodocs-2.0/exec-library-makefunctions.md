---
title: exec.library/MakeFunctions
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-makefunctions
functions: []
libraries: []
---

# exec.library/MakeFunctions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MakeFunctions -- construct a function jump table
SYNOPSIS

```c
    tableSize = MakeFunctions(target, functionArray, funcDispBase)
    D0                        A0      A1             A2

    ULONG MakeFunctions(APTR,APTR,APTR);
```
FUNCTION

```c
    A low level function used by [MakeLibrary](autodocs-2.0/exec-library-makelibrary.md) to build jump tables of
    the type used by libraries, devices and resources.  It allows the
    table to be built anywhere in memory, and can be used both for
    initialization and replacement. This function also supports function
    pointer compression by expanding relative displacements into absolute
    pointers.

    The processor instruction cache is cleared after the table building.
```
INPUT

```c
    destination - the target address for the high memory end of the
            function jump table.  Typically this will be the library
            base pointer.

    functionArray - pointer to an array of function pointers or
            function displacements.  If funcDispBase is zero, the array
            is assumed to contain absolute pointers to functions. If
            funcDispBase is not zero, then the array is assumed to
            contain word displacements to functions.  In both cases,
            the array is terminated by a -1 (of the same size as the
            actual entry.

    funcDispBase - pointer to the base about which all function
            displacements are relative.  If zero, then the function
            array contains absolute pointers.
```
RESULT

```c
    tableSize - size of the new table in bytes (for LIB_NEGSIZE).
```
SEE ALSO

```c
    [exec/MakeLibrary](autodocs-2.0/exec-library-makelibrary.md)
```

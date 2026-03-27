---
title: dos.library/FindVar
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-findvar
functions: [DeleteVar, GetVar, SetVar]
libraries: [dos.library]
---

# dos.library/FindVar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FindVar -- Finds a local variable (V36)
```
SYNOPSIS

```c
    var = FindVar( name, type )
    D0              D1    D2

    struct [LocalVar](autodocs-2.0/includes-dos-var-h.md) * FindVar(STRPTR, ULONG )
```
FUNCTION

    Finds a local variable structure.
INPUTS

```c
    name - pointer to an variable name.  Note variable names follow
           filesystem syntax and semantics.

    type - type of variable to be found (see [<dos/var.h>](autodocs-2.0/includes-dos-var-h.md))
```
RESULT


```c
    var  - pointer to a [LocalVar](autodocs-2.0/includes-dos-var-h.md) structure or NULL
```
SEE ALSO

```c
    [GetVar()](autodocs-2.0/dos-library-getvar.md), [SetVar()](autodocs-2.0/dos-library-setvar.md), [DeleteVar()](autodocs-2.0/dos-library-deletevar.md), [<dos/var.h>](autodocs-2.0/includes-dos-var-h.md)
```

---

## See Also

- [DeleteVar — dos.library](../autodocs/dos.library.md#deletevar)
- [GetVar — dos.library](../autodocs/dos.library.md#getvar)
- [SetVar — dos.library](../autodocs/dos.library.md#setvar)

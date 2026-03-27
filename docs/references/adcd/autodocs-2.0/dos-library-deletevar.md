---
title: dos.library/DeleteVar
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-deletevar
functions: [FindVar, GetVar, SetVar]
libraries: [dos.library]
---

# dos.library/DeleteVar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteVar -- Deletes a local or environment variable (V36)
```
SYNOPSIS

```c
    success = DeleteVar( name, flags )
    D0                    D1    D2

    BOOL DeleteVar(STRPTR, ULONG )
```
FUNCTION

    Deletes a local or environment variable.
INPUTS

```c
    name   - pointer to an variable name.  Note variable names follow
             filesystem syntax and semantics.
    flags  - combination of type of var to delete (low 8 bits), and
             flags to control the behavior of this routine.  Currently
             defined flags include:

             GVF_LOCAL_ONLY  - delete a local (to your process) variable.
             GVF_GLOBAL_ONLY - delete a global environment variable.

             The default is to delete a local variable if found, otherwise
             a global environment variable if found (only for LV_VAR).
```
RESULT

    success - If non-zero, the variable was sucessfully deleted, FALSE
              indicates failure.
BUGS

    LV_VAR is the only type that can be global
SEE ALSO

```c
    [GetVar()](autodocs-2.0/dos-library-getvar.md), [SetVar()](autodocs-2.0/dos-library-setvar.md), [FindVar()](autodocs-2.0/dos-library-findvar.md), [DeleteFile()](autodocs-2.0/dos-library-deletefile.md), [<dos/var.h>](autodocs-2.0/includes-dos-var-h.md)
```

---

## See Also

- [FindVar — dos.library](../autodocs/dos.library.md#findvar)
- [GetVar — dos.library](../autodocs/dos.library.md#getvar)
- [SetVar — dos.library](../autodocs/dos.library.md#setvar)

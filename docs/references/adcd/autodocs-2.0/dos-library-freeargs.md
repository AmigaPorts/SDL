---
title: dos.library/FreeArgs
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-freeargs
functions: [FindArg, ReadArgs]
libraries: [dos.library]
---

# dos.library/FreeArgs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeArgs - Free allocated memory after [ReadArgs()](autodocs-2.0/dos-library-readargs.md) (V36)
```
SYNOPSIS

```c
    FreeArgs(rdargs)
               D1

    void FreeArgs(struct [RDArgs](autodocs-2.0/includes-dos-rdargs-h.md) *)
```
FUNCTION

```c
    Frees memory allocated to return arguments in from [ReadArgs()](autodocs-2.0/dos-library-readargs.md).  If
    [ReadArgs](autodocs-2.0/dos-library-readargs.md) allocated the [RDArgs](autodocs-2.0/includes-dos-rdargs-h.md) structure it will be freed.
```
INPUTS

```c
    rdargs - structure returned from [ReadArgs()](autodocs-2.0/dos-library-readargs.md)
```
SEE ALSO

```c
    [ReadArgs()](autodocs-2.0/dos-library-readargs.md), [ReadItem()](autodocs-2.0/dos-library-readitem.md), [FindArg()](autodocs-2.0/dos-library-findarg.md)
```

---

## See Also

- [FindArg — dos.library](../autodocs/dos.library.md#findarg)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)

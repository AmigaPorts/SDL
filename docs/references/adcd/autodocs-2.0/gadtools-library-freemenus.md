---
title: gadtools.library/FreeMenus
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-freemenus
functions: [CreateMenusA]
libraries: [gadtools.library]
---

# gadtools.library/FreeMenus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeMenus -- Frees memory allocated by [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md). (V36)
```
SYNOPSIS

```c
    FreeMenus(menu)
              A0

    VOID FreeMenus(struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) *);
```
FUNCTION

```c
    Frees the menus allocated by [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md).  It is safe to
    call this function with a NULL parameter.
```
INPUTS

```c
    menu - Pointer to menu structure (or first MenuItem) obtained
    from [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md).
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md)
```

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)

---
title: iffparse.library/LocalItemData
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-localitemdata
functions: [AllocLocalItem, FreeLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/LocalItemData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LocalItemData -- Get pointer to user data for local context item.
SYNOPSIS

```c
    data = LocalItemData (lci)
     d0                   a0

    UBYTE                   *data;
    struct [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md)   *lci;
```
FUNCTION

```c
    Returns pointer to the user data associated with the given local
    context item.  The size of the data area depends on the "usize"
    argument used when allocating this item.  If the pointer to the item
    given (lci) is NULL, the function also returns NULL.
```
INPUTS

    lci     - pointer to local context item or NULL.
RESULT

    data    - pointer to user data area or NULL if lci is NULL.
EXAMPLE

NOTES

BUGS

```c
    Currently, there is no way to determine the size of the user data
    area; you have to 'know'.
```
SEE ALSO

```c
    [AllocLocalItem()](autodocs-2.0/iffparse-library-alloclocalitem.md), [FreeLocalItem()](autodocs-2.0/iffparse-library-freelocalitem.md)
```

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [FreeLocalItem — iffparse.library](../autodocs/iffparse.library.md#freelocalitem)

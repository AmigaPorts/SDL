---
title: gadtools.library/FreeGadgets
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-freegadgets
functions: [CreateGadgetA]
libraries: [gadtools.library]
---

# gadtools.library/FreeGadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeGadgets -- Free a linked list of gadgets. (V36)
```
SYNOPSIS

```c
    FreeGadgets(glist)
                A0

    VOID FreeGadgets(struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *glist);
                     A0
```
FUNCTION

```c
    Frees any GadTools gadgets found on the linked list of gadgets
    beginning with the specified one.  Frees all the memory that was
    allocated by [CreateGadgetA()](autodocs-2.0/gadtools-library-creategadgeta.md).  This function will return safely
    with no action if it receives a NULL parameter.
```
INPUTS

    glist - pointer to first gadget in list to be freed.
RESULT

    none
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CreateGadgetA()](autodocs-2.0/gadtools-library-creategadgeta.md)
```

---

## See Also

- [CreateGadgetA — gadtools.library](../autodocs/gadtools.library.md#creategadgeta)

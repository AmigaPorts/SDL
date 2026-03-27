---
title: intuition.library/ClearPointer
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-clearpointer
functions: [ClearPointer, SetPointer]
libraries: [intuition.library]
---

# intuition.library/ClearPointer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ClearPointer -- Clear the mouse pointer definition from a window.
SYNOPSIS

```c
    ClearPointer( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                  A0

    VOID ClearPointer( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Clears the window of its own definition of the Intuition mouse pointer.
    After calling ClearPointer(), every time this window is the active
    one the default Intuition pointer will be the pointer displayed
    to the user.  If your window is the active one when this routine
    is called, the change will take place immediately.

    [Custom](autodocs-2.0/includes-hardware-custom-h.md) definitions of the mouse pointer which this function clears
    are installed by a call to [SetPointer()](autodocs-2.0/intuition-library-setpointer.md).
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window to be cleared of its pointer definition
```
RESULT

    None
BUGS

SEE ALSO

```c
    [SetPointer()](autodocs-2.0/intuition-library-setpointer.md)
```

---

## See Also

- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)

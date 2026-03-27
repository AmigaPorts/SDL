---
title: layout_gc/LAYOUT_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: layout-gc-layout-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# layout_gc/LAYOUT_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME

      LAYOUT_GetClass -- Gets the pointer to the layout class.
  SYNOPSIS

```c
      layout_class = LAYOUT_GetClass();
      D0

      Class * LAYOUT_GetClass(VOID);
```
  FUNCTION

```c
      Obtains the pointer to the layout gadget class for use with
      [NewObject()](autodocs-3.5/intuition-library-newobject-2.md).  This function always returns a valid pointer so
      you do not need to check it.  The reason is that if the library
      opens fine, then the pointer returned is already setup.  (Of
      course this implies that if opening the library fails, you
      shouldn't be calling this.)

      Note that this function does not create the class, that is done
      when the class library is opened.
```
  INPUTS

      Nothing.
  RESULT

      LayoutClass - Pointer to the layout gadget class.

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)

---
title: getscreenmode.gadget/GETSCREENMODE_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: getscreenmode-gadget-getscreenmode-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# getscreenmode.gadget/GETSCREENMODE_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GETSCREENMODE_GetClass -- Gets the pointer to the screenmode
                                 requester class
   SYNOPSIS

```c
       getscreenmode_class = GETSCREENMODE_GetClass();
       D0

       Class * GETSCREENMODE_GetClass( void );
```
   FUNCTION

```c
       Obtains the pointer to the getscreenmode gadget class for use with
       [NewObject()](autodocs-3.5/intuition-library-newobject-2.md).  This function always returns a valid pointer so
       you do not need to check it.  The reason is that if the library
       opens fine, then the pointer returned is already setup.  (Of course
       this implies that if opening the library fails, you shouldn't be
       calling this.)

       Note that this function does not create the class, that is done
       when the class library is opened.
```
   INPUTS

   RESULT

       getscreenmode_class - Pointer to the getscreenmode gadget class.
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)

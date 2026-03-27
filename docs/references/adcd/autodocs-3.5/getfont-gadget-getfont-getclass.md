---
title: getfont.gadget/GETFONT_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: getfont-gadget-getfont-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# getfont.gadget/GETFONT_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GETFONT_GetClass -- Gets the pointer to the font requester class
   SYNOPSIS

```c
       getfont_class = GETFONT_GetClass();
       D0

       Class * GETFONT_GetClass( void );
```
   FUNCTION

```c
       Obtains the pointer to the getfont gadget class for use with
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

       getfont_class - Pointer to the getfont gadget class.
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)

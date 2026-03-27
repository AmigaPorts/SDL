---
title: getfile.gadget/GETFILE_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: getfile-gadget-getfile-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# getfile.gadget/GETFILE_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GETFILE_GetClass -- Gets the pointer to the file requester class
   SYNOPSIS

```c
       getfile_class = GETFILE_GetClass();
       D0

       Class * GETFILE_GetClass( void );
```
   FUNCTION

```c
       Obtains the pointer to the getfile gadget class for use with
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

       getfile_class - Pointer to the getfile gadget class.
   EXAMPLE

   NOTES

```c
       The GFILE_REQUEST method will return 0 if no file is selected and
       the GETFILE_DrawersOnly tag is not used, even is the user selected
       the positive response in the requester. If a file is selected (the
       file gadget in the file requester is not empty), it will return 1.
```
   BUGS

   SEE ALSO

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)

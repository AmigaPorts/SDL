---
title: 37 Utility Library / International String Functions
manual: libraries
chapter: libraries
section: 37-utility-library-international-string-functions
functions: [Stricmp, Strnicmp, ToLower, ToUpper]
libraries: [utility.library]
---

# 37 Utility Library / International String Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The international string functions in utility library are a way to make
use of a future localization library which Amiga, Inc. will provide.
When the localization library is opened, the functions will be replaced by
ones which will take the locale as defined by the user into account. This
means that the compare order may change according to the locale, so care
should be taken not to rely on obtaining specific compare sequences.

Currently implemented are:

  _______________________________________________________________
 |                                                               |
 |  [Stricmp()](autodocs-2.0/utility-library-stricmp.md)  Compare string case-insensitive.                  |
 | [Strnicmp()](autodocs-2.0/utility-library-strnicmp.md)  Compare string case-insensitive, with a specified |
 |             length.                                           |
 |  [ToLower()](autodocs-2.0/utility-library-tolower.md)  Convert a character to lower case.                |
 |  [ToUpper()](autodocs-2.0/utility-library-toupper.md)  Convert a character to upper case.                |
 |_______________________________________________________________|



    Table 37-4: Utility Library International String Functions
These functions operate in the same manner as their ANSI C equivalents,
for the most part.  For more information, see the "[Utility Library](autodocs-2.0/utility-doc.md)"
Autodocs in the Amiga ROM Kernel Reference Manual: Includes and Autodocs.
Here is a simple example of the usage of the international string
functions.


```c
     [istr.c](libraries/lib-examples-istr-c.md) 
```

---

## See Also

- [Stricmp — utility.library](../autodocs/utility.library.md#stricmp)
- [Strnicmp — utility.library](../autodocs/utility.library.md#strnicmp)
- [ToLower — utility.library](../autodocs/utility.library.md#tolower)
- [ToUpper — utility.library](../autodocs/utility.library.md#toupper)

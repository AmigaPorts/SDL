---
title: 1 / / Design Decisions / Conditional Code
manual: libraries
chapter: libraries
section: 1-design-decisions-conditional-code
functions: [OpenLibrary]
libraries: [exec.library]
---

# 1 / / Design Decisions / Conditional Code

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Conditional code provides a second way to take advantage of [Release 2](libraries/1-operating-system-versions-about-release-2.md)
enhancements in a 1.3-compatible application.  The basic idea is to add
low overhead conditional code, based on library version, to make use of
selected Release 2 features if they are available.  There are some
powerful and beneficial Release 2 features which are definitely worth
conditional code.

The control flow for such conditional code is always based on whether a
particular version of a library is available.  Failure of [OpenLibrary()](libraries/1-programming-in-the-amiga-environment-libraries-of.md)
(i.e., return value of NULL) means that the library version requested is
not available.  The version number of a library that successfully opened
can be checked by testing LibBase->lib_Version.  Always check for a
version greater or equal to the version you need.



```c
    Examples of conditional library checking code:

    /* Checking for presence of a new Release 2 library */
    if( AslBase = OpenLibrary("asl.library", 37L) )
            { /* OK to use the ASL requester */ }
    else
            { /* Must use a different method */ }

    /* Check version of an existing library with new Release 2 features */
    if(GfxBase->lib_Version >= 37)   { /* then allow new genlock modes */}
```

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)

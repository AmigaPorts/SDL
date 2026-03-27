---
title: 18 / What is a Library? / Minimum Subset of Library Vectors
manual: libraries
chapter: libraries
section: 18-what-is-a-library-minimum-subset-of-library-vectors
functions: [CloseLibrary, OpenLibrary]
libraries: [exec.library]
---

# 18 / What is a Library? / Minimum Subset of Library Vectors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The first four code vectors of a library must be the following entries:

OPEN

```c
    is the entry point called by the function [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md).  In most
    libraries, OPEN increments the library variable [lib_OpenCnt](libraries/18-exec-libraries-what-is-a-library.md). This
    variable is also used by CLOSE and EXPUNGE.
```
CLOSE

```c
    is the entry point called by the function [CloseLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md). It
    decrements the library variable [lib_OpenCnt](libraries/18-exec-libraries-what-is-a-library.md) and may do a delayed
    EXPUNGE.
```
EXPUNGE

    prepares the library for removal from the system. This often includes
    deallocating memory resources that were reserved during
    initialization. EXPUNGE not only frees the memory allocated for data
    structures, but also the areas reserved for the library node itself.
RESERVED

    is a fourth function vector reserved for future use. It must always
    return zero.

---

## See Also

- [CloseLibrary — exec.library](../autodocs/exec.library.md#closelibrary)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)

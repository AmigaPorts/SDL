---
title: exec.library/OldOpenLibrary
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-oldopenlibrary
functions: []
libraries: []
---

# exec.library/OldOpenLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    OldOpenLibrary -- obsolete [OpenLibrary](autodocs-2.0/exec-library-openlibrary.md)
```
SYNOPSIS

```c
    library = OldOpenLibrary(libName)
    D0                       A1

    struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *OldOpenLibrary(APTR);
```
FUNCTION

```c
    The 1.0 release of the Amiga system had an incorrect version of
    [OpenLibrary](autodocs-2.0/exec-library-openlibrary.md) that did not check the version number during the
    library open.  This obsolete function is provided so that object
    code compiled using a 1.0 system will still run.

    This exactly the same as "OpenLibrary(libName,0L);"
```
INPUTS

    libName - the name of the library to open
RESULTS

    library - a library pointer for a successful open, else zero
SEE ALSO

```c
    [CloseLibrary](autodocs-2.0/exec-library-closelibrary.md)
```

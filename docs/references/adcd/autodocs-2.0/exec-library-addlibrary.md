---
title: exec.library/AddLibrary
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addlibrary
functions: []
libraries: []
---

# exec.library/AddLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddLibrary -- add a library to the system
SYNOPSIS

```c
    AddLibrary(library)
               A1

    void AddLibrary(struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *);
```
FUNCTION

    This function adds a new library to the system, making it available
    to other programs.  The library should be ready to be opened at
    this time.  It will be added to the system library name list, and
    the checksum on the library entries will be calculated.
INPUTS

    library - pointer to a properly initialized library structure
SEE ALSO

```c
    [RemLibrary](autodocs-2.0/exec-library-remlibrary.md), [CloseLibrary](autodocs-2.0/exec-library-closelibrary.md), [OpenLibrary](autodocs-2.0/exec-library-openlibrary.md), [MakeLibrary](autodocs-2.0/exec-library-makelibrary.md)
```

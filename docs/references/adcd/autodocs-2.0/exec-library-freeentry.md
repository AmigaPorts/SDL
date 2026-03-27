---
title: exec.library/FreeEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-freeentry
functions: []
libraries: []
---

# exec.library/FreeEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeEntry -- free many regions of memory
SYNOPSIS

```c
    FreeEntry(memList)
              A0
    void FreeEntry(struct [MemList](autodocs-2.0/includes-exec-memory-h.md) *);
```
FUNCTION

```c
    This function takes a memList structure (as returned by AllocEntry)
    and frees all the entries.
```
INPUTS

```c
    memList -- pointer to structure filled in with [MemEntry](autodocs-2.0/includes-exec-memory-h.md)
               structures
```
SEE ALSO

```c
    [AllocEntry](autodocs-2.0/exec-library-allocentry.md)
```

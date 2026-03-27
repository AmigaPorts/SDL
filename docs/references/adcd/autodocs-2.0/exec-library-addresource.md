---
title: exec.library/AddResource
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addresource
functions: []
libraries: []
---

# exec.library/AddResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddResource -- add a resource to the system
SYNOPSIS

```c
    AddResource(resource)
                A1

    void AddResource(APTR);
```
FUNCTION

```c
    This function adds a new resource to the system and makes it
    available to other users.  The resource must be ready to be called
    at this time.

    Resources currently have no system-imposed structure, however they
    must start with a standard named node (LN_SIZE), and should with
    a standard [Library](autodocs-2.0/includes-exec-libraries-h.md) node (LIB_SIZE).
```
INPUTS

    resource - pointer an initialized resource node
SEE ALSO

```c
    [RemResource](autodocs-2.0/exec-library-remresource.md), [OpenResource](autodocs-2.0/exec-library-openresource.md), [MakeLibrary](autodocs-2.0/exec-library-makelibrary.md)
```

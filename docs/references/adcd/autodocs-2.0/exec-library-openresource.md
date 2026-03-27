---
title: exec.library/OpenResource
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-openresource
functions: []
libraries: []
---

# exec.library/OpenResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OpenResource -- gain access to a resource
SYNOPSIS

```c
    resource = OpenResource(resName)
    D0                      A1

    APTR OpenResource(STRPTR);
```
FUNCTION

```c
    This function returns a pointer to a resource that was previously
    installed into the system.

    There is no CloseResource() function.
```
INPUTS
   resName - the name of the resource requested.

RESULTS

    resource - if successful, a resource pointer, else NULL

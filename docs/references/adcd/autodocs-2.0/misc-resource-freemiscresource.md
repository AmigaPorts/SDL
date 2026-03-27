---
title: misc.resource/FreeMiscResource
manual: autodocs-2.0
chapter: autodocs-2.0
section: misc-resource-freemiscresource
functions: []
libraries: []
---

# misc.resource/FreeMiscResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeMiscResource - make a resource available for reallocation
SYNOPSIS

```c
    FreeMiscResource( unitNum )
                      D0

    void FreeMiscResource(ULONG);
```
FUNCTION

```c
    This routine frees one of the resources allocated
    by [AllocMiscResource](autodocs-2.0/misc-resource-allocmiscresource.md).  The resource is made available
    for reuse.

    FreeMiscResource must be called from the same task that
    called [AllocMiscResource](autodocs-2.0/misc-resource-allocmiscresource.md).  This function may not be called from
    interrupt code.
```
INPUTS

    unitNum - the number of the miscellaneous resource to be freed.
RESULTS

    Frees the appropriate resource.
BUGS

SEE ALSO

```c
    resources/misc.i, [AllocMiscResource()](autodocs-2.0/misc-resource-allocmiscresource.md)
```

---
title: intuition.library/EndRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-endrequest
functions: [Request]
libraries: [intuition.library]
---

# intuition.library/EndRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    EndRequest -- Remove a currently active requester.
SYNOPSIS

```c
    EndRequest( [Requester](autodocs-2.0/includes-intuition-intuition-h.md), [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                A0         A1

    VOID EndRequest( struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

    Ends the request by erasing the requester and decoupling it from
    the window.

    Note that this doesn't necessarily clear all requesters from the
    window, only the specified one.  If the window labors under other
    requesters, they will remain in the window.
INPUTS

```c
    [Requester](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the requester to be removed
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure with which this requester
       is associated
```
RESULT

    None
BUGS

SEE ALSO

```c
    [Request()](autodocs-2.0/intuition-library-request.md)
```

---

## See Also

- [Request — intuition.library](../autodocs/intuition.library.md#request)

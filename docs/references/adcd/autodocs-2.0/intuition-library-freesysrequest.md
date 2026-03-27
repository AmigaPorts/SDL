---
title: intuition.library/FreeSysRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-freesysrequest
functions: [AutoRequest, BuildSysRequest, CloseWindow]
libraries: [intuition.library]
---

# intuition.library/FreeSysRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeSysRequest -- Free resources gotten by a call to [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md).
```
SYNOPSIS

```c
    FreeSysRequest( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                    A0

    VOID FreeSysRequest( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    This routine frees up all memory allocated by a successful call to
    the [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md) procedure.  If [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md) returned a
    pointer to a window, then you are able to wait on the message port
    of that window to detect an event which satisfies the requester.
    When you want to remove the requester, you call this procedure.  It
    ends the requester and deallocates any memory used in the creation
    of the requester.  It also closes the special window that was opened
    for your system requester.

    For V36: It's OK if you pass a NULL or a TRUE (1) value to
    this function.  Also, this function properly disposes of
    requesters gotten using BuildEasyRequest().
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = value of the window pointer returned by a successful call to
       the [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md) procedure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md), [AutoRequest()](autodocs-2.0/intuition-library-autorequest.md), [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
```

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)

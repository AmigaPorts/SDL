---
title: intuition.library/ActivateWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-activatewindow
functions: [OpenWindow]
libraries: [intuition.library]
---

# intuition.library/ActivateWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ActivateWindow -- Activate an Intuition window.
SYNOPSIS

```c
    [success =] ActivateWindow( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
    [D0]                        A0

    [LONG] ActivateWindow( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
    /* returns LONG in V36 and higher */
```
FUNCTION

    Activates an Intuition window.

    Note that this call may have its action deferred: you cannot assume
    that when this call is made the selected window has become active.
    This action will be postponed while the user plays with gadgets and
    menus, or sizes and drags windows.  You may detect when the window
    actually has become active by the IDCMP_ACTIVEWINDOW IDCMP message.

    This call is intended to provide flexibility but not to confuse the
    user.  Please call this function synchronously with some action
    by the user.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = a pointer to a [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure
```
RESULT

    V35 and before: None.
    V36 and later: returns zero if no problem queuing up
        the request for deferred action
BUGS

    Calling this function in a tight loop can blow out Intuition's deferred
    action queue.
SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md), and the WFLG_ACTIVATE window flag
```

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)

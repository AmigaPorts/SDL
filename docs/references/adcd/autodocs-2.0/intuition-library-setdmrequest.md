---
title: intuition.library/SetDMRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setdmrequest
functions: [ClearDMRequest, Request, SetDMRequest]
libraries: [intuition.library]
---

# intuition.library/SetDMRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetDMRequest -- Set the DMRequest of a window.
SYNOPSIS

```c
    success = SetDMRequest( [Window](autodocs-2.0/includes-intuition-intuition-h.md), DMRequest )
    D0                      A0      A1

    BOOL SetDMRequest( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Attempts to set the DMRequest into the specified window.
    The DMRequest is the special requester that you attach to
    the double-click of the menu button which the user can then
    bring up on demand.  This routine WILL NOT change the DMRequest
    if it's already set and is currently active (in use by the user).
    After having called SetDMRequest(), if you want to change the
    DMRequest, the correct way to start is by calling [ClearDMRequest()](autodocs-2.0/intuition-library-cleardmrequest.md)
    until it returns a value of TRUE; then you can call SetDMRequest()
    with the new DMRequest.

    If the POINTREL flag is set in the DMRequest, the DMR will open as
    close to the pointer as possible.  The RelLeft/Top fields are
    for fine-tuning the position.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window from which the DMRequest is to be set
    DMRequest = a pointer to a requester
```
RESULT

    If the current DMRequest was not in use, sets the DMRequest
        pointer into the window and returns TRUE.
    If the DMRequest was currently in use, doesn't change the pointer
        and returns FALSE
BUGS

SEE ALSO

```c
    [ClearDMRequest()](autodocs-2.0/intuition-library-cleardmrequest.md), [Request()](autodocs-2.0/intuition-library-request.md)
```

---

## See Also

- [ClearDMRequest — intuition.library](../autodocs/intuition.library.md#cleardmrequest)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
- [SetDMRequest — intuition.library](../autodocs/intuition.library.md#setdmrequest)

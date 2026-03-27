---
title: intuition.library/ModifyIDCMP
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-modifyidcmp
functions: [CloseWindow, ModifyIDCMP, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/ModifyIDCMP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ModifyIDCMP -- Modify the state of a window's IDCMPFlags.
SYNOPSIS

```c
    [Success =] ModifyIDCMP( [Window](autodocs-2.0/includes-intuition-intuition-h.md), IDCMPFlags )
    [D0]                     A0      D0

    [BOOL] ModifyIDCMP( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, ULONG );
    /* returns BOOL in V37 and greater */
```
FUNCTION

```c
    This routine modifies the state of your window's IDCMP (Intuition
    Direct Communication [Message](autodocs-2.0/includes-exec-ports-h.md) Port).  The state is modified to reflect
    your desires as described by the flag bits in the value IDCMPFlags.

    The four actions that might be taken are:
```
   - if there is currently no IDCMP in the given window, and IDCMPFlags
     is zero, nothing happens
   - if there is currently no IDCMP in the given window, and any of the
```c
     IDCMPFlags is selected (set), then the IDCMP of the window is
     created, including allocating and initializing the message ports
     and allocating a signal bit for your port.  See the "Input and
     Output Methods" chapter of the Intuition Reference Manual for full
      details
```
   - if the IDCMP for the given window exists, and the
```c
     IDCMPFlags argument is zero, this says that you want
     Intuition to close the ports, free the buffers and free
     your signal bit.  You MUST be the same task that was active
     when this signal bit was allocated (either by ModifyIDCMP()
      or [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) ).
```
   - if the IDCMP for the given window is opened, and the IDCMPFlags


```c
     argument is not zero, this means that you want to change the
     state of which events will be broadcast to you through the IDCMP

    NOTE:  You can set up the Window->UserPort to any port of your own
    before you call ModifyIDCMP().  If IDCMPFlags is non-null but
    your UserPort is already initialized, Intuition will assume that
    it's a valid port with task and signal data preset and Intuition
    won't disturb your set-up at all, Intuition will just allocate
    the Intuition message port half of it.  The converse is true
    as well:  if UserPort is NULL when you call here with
    IDCMPFlags == NULL, Intuition will deallocate only the Intuition
    side of the port.

    This allows you to use a port that you already have allocated:
    - [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) with IDCMPFlags equal to NULL (open no ports)
    - set the UserPort variable of your window to any valid port of your
      own choosing
    - call ModifyIDCMP with IDCMPFlags set to what you want
    - then, to clean up later, set UserPort equal to NULL before calling
      [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md) (leave IDCMPFlags alone)  BUT FIRST: you must make
      sure that no messages sent your window are queued at the port,
      since they will be returned to the memory free pool.

    For an example of how to close a window with a shared IDCMP,
    see the description for [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md).
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure containing the IDCMP ports
    IDCMPFlags = the flag bits describing the new desired state of the
                 IDCMP
```
RESULT

```c
    Starting in V37, this function returns NULL if it was unable
    to create the necessary message ports.  (The possibility of
    failure exists in earlier releases, but no return code was offered).
    Do not check the return code under V36 or earlier.
```
BUGS

SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md), [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
```

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)

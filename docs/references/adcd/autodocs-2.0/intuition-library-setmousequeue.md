---
title: intuition.library/SetMouseQueue
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setmousequeue
functions: [OpenWindow]
libraries: [intuition.library]
---

# intuition.library/SetMouseQueue

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetMouseQueue -- Change limit on pending mouse messages. (V36)
```
SYNOPSIS

```c
    oldQueueLength = SetMouseQueue( [Window](autodocs-2.0/includes-intuition-intuition-h.md), QueueLength )
    D0                              A0      D0

    LONG SetMouseQueue( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, UWORD );
```
FUNCTION

    Changes the number of mouse messages that Intuition will allow
    to be outstanding for your window.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = your window
    QueueLength = the new value of outstanding mouse movement messages
      you wish to allow.
```
RESULT

    -1 if 'Window' is not known
    Otherwise the previous value of the queue limit.
    The corresponding function for changing the repeat key
    queue limit is not yet implemented.
BUGS

SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)
```

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)

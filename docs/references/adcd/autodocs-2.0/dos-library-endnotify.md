---
title: dos.library/EndNotify
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-endnotify
functions: [StartNotify]
libraries: [dos.library]
---

# dos.library/EndNotify

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    EndNotify -- Ends a notification request (V36)
```
SYNOPSIS

```c
    EndNotify(notifystructure)
                    D1

    VOID EndNotify(struct [NotifyRequest](autodocs-2.0/includes-dos-notify-h.md) *)
```
FUNCTION

```c
    Removes a notification request.  Safe to call even if [StartNotify()](autodocs-2.0/dos-library-startnotify.md)
    failed.  For NRF_SEND_MESSAGE, it searches your port for any messages
    about the object in question and removes and replies them before
    returning.
```
INPUTS

```c
    notifystructure - a structure passed to [StartNotify()](autodocs-2.0/dos-library-startnotify.md)
```
SEE ALSO

```c
    [StartNotify()](autodocs-2.0/dos-library-startnotify.md), [<dos/notify.h>](autodocs-2.0/includes-dos-notify-h.md)
```

---

## See Also

- [StartNotify — dos.library](../autodocs/dos.library.md#startnotify)

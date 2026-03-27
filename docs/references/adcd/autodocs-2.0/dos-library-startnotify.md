---
title: dos.library/StartNotify
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-startnotify
functions: [EndNotify]
libraries: [dos.library]
---

# dos.library/StartNotify

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    StartNotify -- Starts notification on a file or directory (V36)
```
SYNOPSIS

```c
    success = StartNotify(notifystructure)
    D0                          D1

    BOOL StartNotify(struct [NotifyRequest](autodocs-2.0/includes-dos-notify-h.md) *)
```
FUNCTION

    Posts a notification request.  Do not modify the notify structure while
    it is active.  You will be notified when the file or directory changes.
    For files, you will be notified after the file is closed.  Not all
    filesystems will support this: applications should NOT require it.  In
    particular, most network filesystems won't support it.
INPUTS

```c
    notifystructure - A filled-in [NotifyRequest](autodocs-2.0/includes-dos-notify-h.md) structure
```
RESULT

    success - Success/failure of request
BUGS

```c
    The V36 floppy/HD filesystem doesn't actually send notifications.  The
    V36 ram handler (ram:) does.  This has been fixed for V37.
```
SEE ALSO

```c
    [EndNotify()](autodocs-2.0/dos-library-endnotify.md), [<dos/notify.h>](autodocs-2.0/includes-dos-notify-h.md)
```

---

## See Also

- [EndNotify — dos.library](../autodocs/dos.library.md#endnotify)

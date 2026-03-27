---
title: dos.library/GetFileSysTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-getfilesystask
functions: [Open]
libraries: [dos.library]
---

# dos.library/GetFileSysTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetFileSysTask -- Returns the default filesystem for the process (V36)
```
SYNOPSIS

```c
    port = GetFileSysTask()
    D0

    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *GetFileSysTask(void)
```
FUNCTION

```c
    Returns the default filesystem task's port (pr_FileSystemTask) for the
    current process.
```
RESULT

    port - The pr_MsgPort of the filesystem, or NULL.
SEE ALSO

```c
    [SetFileSysTask()](autodocs-2.0/dos-library-setfilesystask.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)

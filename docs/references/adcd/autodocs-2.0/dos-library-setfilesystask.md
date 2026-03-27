---
title: dos.library/SetFileSysTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setfilesystask
functions: [Open]
libraries: [dos.library]
---

# dos.library/SetFileSysTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetFileSysTask -- Sets the default filesystem for the process (V36)
```
SYNOPSIS

```c
    oldport = SetFileSysTask(port)
    D0                        D1

    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *SetFileSysTask(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *)
```
FUNCTION

```c
    Sets the default filesystem task's port (pr_FileSystemTask) for the
    current process.
```
INPUTS

    port - The pr_MsgPort of the default filesystem for the process
RESULT

    oldport - The previous FileSysTask value
SEE ALSO

```c
    [GetFileSysTask()](autodocs-2.0/dos-library-getfilesystask.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)

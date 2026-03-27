---
title: dos.library/GetConsoleTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-getconsoletask
functions: [Open]
libraries: [dos.library]
---

# dos.library/GetConsoleTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetConsoleTask -- Returns the default console for the process (V36)
```
SYNOPSIS

```c
    port = GetConsoleTask()
    D0

    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *GetConsoleTask(void)
```
FUNCTION

```c
    Returns the default console task's port (pr_ConsoleTask) for the
    current process.
```
RESULT

    port - The pr_MsgPort of the console handler, or NULL.
SEE ALSO

```c
    [SetConsoleTask()](autodocs-2.0/dos-library-setconsoletask.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)

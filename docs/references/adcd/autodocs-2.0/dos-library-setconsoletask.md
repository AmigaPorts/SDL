---
title: dos.library/SetConsoleTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setconsoletask
functions: [Open]
libraries: [dos.library]
---

# dos.library/SetConsoleTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetConsoleTask -- Sets the default console for the process (V36)
```
SYNOPSIS

```c
    oldport = SetConsoleTask(port)
    D0                        D1

    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *SetConsoleTask(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *)
```
FUNCTION

```c
    Sets the default console task's port (pr_ConsoleTask) for the
    current process.
```
INPUTS

    port - The pr_MsgPort of the default console handler for the process
RESULT

    oldport - The previous ConsoleTask value.
SEE ALSO

```c
    [GetConsoleTask()](autodocs-2.0/dos-library-getconsoletask.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)

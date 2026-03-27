---
title: dos.library/FindCliProc
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-findcliproc
functions: [Cli, Forbid, MaxCli]
libraries: [dos.library, exec.library]
---

# dos.library/FindCliProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FindCliProc -- returns a pointer to the requested CLI process (V36)
```
SYNOPSIS

```c
    proc = FindCliProc(num)
    D0             D1

    struct [Process](autodocs-2.0/includes-dos-dosextens-h.md) *FindCliProc(LONG)
```
FUNCTION

```c
    This routine returns a pointer to the CLI process associated with the
    given CLI number.  If the process isn't an active CLI process, NULL is
    returned.  NOTE: should normally be called inside a [Forbid()](autodocs-2.0/exec-library-forbid.md), if you
    must use this function at all.
```
INPUTS

```c
    num  - [Task](autodocs-2.0/includes-exec-tasks-h.md) number of CLI process
```
RESULT

    proc - Pointer to given CLI process
SEE ALSO

```c
    [Cli()](autodocs-2.0/dos-library-cli.md), [Forbid()](autodocs-2.0/exec-library-forbid.md), [MaxCli()](autodocs-2.0/dos-library-maxcli.md)
```

---

## See Also

- [Cli — dos.library](../autodocs/dos.library.md#cli)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [MaxCli — dos.library](../autodocs/dos.library.md#maxcli)

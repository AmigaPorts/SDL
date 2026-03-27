---
title: dos.library/MaxCli
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-maxcli
functions: [Cli, FindCliProc, MaxCli]
libraries: [dos.library]
---

# dos.library/MaxCli

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MaxCli -- returns the highest CLI process number possibly in use (V36)
```
SYNOPSIS

```c
    number = MaxCli()
    D0

    LONG MaxCli(void)
```
FUNCTION

```c
    Returns the highest CLI number that may be in use.  CLI numbers are
    reused, and are usually as small as possible.  To find all CLIs, scan
    using [FindCliProc()](autodocs-2.0/dos-library-findcliproc.md) from 1 to MaxCLI().  The number returned by
    MaxCli() may change as processes are created and destroyed.
```
RESULT

    number - The highest CLI number that _may_ be in use.
SEE ALSO

```c
    [FindCliProc()](autodocs-2.0/dos-library-findcliproc.md), [Cli()](autodocs-2.0/dos-library-cli.md)
```

---

## See Also

- [Cli — dos.library](../autodocs/dos.library.md#cli)
- [FindCliProc — dos.library](../autodocs/dos.library.md#findcliproc)
- [MaxCli — dos.library](../autodocs/dos.library.md#maxcli)

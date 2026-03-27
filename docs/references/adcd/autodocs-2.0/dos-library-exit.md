---
title: dos.library/Exit
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-exit
functions: [CreateNewProc]
libraries: [dos.library]
---

# dos.library/Exit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Exit -- Exit from a program
SYNOPSIS

```c
    Exit( returnCode )
          D1

    void Exit(LONG)
```
FUNCTION

```c
    Exit() is currently for use with programs written as if they
    were BCPL programs.  This function is not normally useful for
    other purposes.

    In general, therefore, please DO NOT CALL THIS FUNCTION!

    In order to exit, C programs should use the C language exit()
    function (note the lower case letter "e").  Assembly programs should
    place a return code in D0, and execute an RTS instruction with
    their original stack ptr.
```
IMPLEMENTATION

```c
    The action of Exit() depends on whether the program which called it
    is running as a command under a CLI or not. If the program is
    running under the CLI the command finishes and control reverts to
    the CLI. In this case, returnCode is interpreted as the return code
    from the program.

    If the program is running as a distinct process, Exit() deletes the
    process and release the space associated with the stack, segment
    list and process structure.
```
INPUTS

    returnCode - integer
SEE ALSO

```c
    [CreateProc()](autodocs-2.0/dos-library-createproc.md), [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md)
```

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)

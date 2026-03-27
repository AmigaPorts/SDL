---
title: dos.library/SystemTagList
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-systemtaglist
functions: [CreateNewProc, Input, Output, SystemTagList]
libraries: [dos.library]
---

# dos.library/SystemTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SystemTagList -- Have a shell execute a command line (V36)
```
SYNOPSIS

```c
    error = SystemTagList(command, tags)
    D0                      D1      D2

    LONG SystemTagList(STRPTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *)

    error = System(command, tags)
    D0               D1      D2

    LONG System(STRPTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *)

    error = SystemTags(command, Tag1, ...)

    LONG SystemTags(STRPTR, ULONG, ...)
```
FUNCTION

```c
    Similar to [Execute()](autodocs-2.0/dos-library-execute.md), but does not read commands from the input
    filehandle.  Spawns a Shell process to execute the command, and
    returns the returncode the command produced, or -1 if the command
    could not be run for any reason.  The input and output filehandles
    will not be closed by System, you must close them (if needed) after
    System returns, if you specified them via SYS_INPUT or SYS_OUTPUT.

    By default the new process will use your current [Input()](autodocs-2.0/dos-library-input.md) and [Output()](autodocs-2.0/dos-library-output.md)
    filehandles.  Normal Shell command-line parsing will be done
    including redirection on 'command'.  The current directory and path
    will be inherited from your process.  Your path will be used to find
    the command (if no path is specified).

    If used with the SYS_Asynch flag, it WILL close both it's input and
    output filehandles after running the command (even if these were
    your [Input()](autodocs-2.0/dos-library-input.md) and Output()!)

    Normally uses the boot (ROM) shell, but other shells can be specified
    via SYS_UserShell and SYS_CustomShell.  Normally, you should send
    things written by the user to the UserShell.  The UserShell defaults
    to the same shell as the boot shell.

    The tags are passed through to [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md) (tags that conflict
    with SystemTagList() will be filtered out).  This allows setting
    things like priority, etc for the new process.
```
INPUTS

```c
    command - Program and arguments
    tags    - see [<dos/dostags.h>](autodocs-2.0/includes-dos-dostags-h.md).  Note that both SystemTagList()-
              specific tags and tags from [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md) may be passed.
```
RESULT

    error   - 0 for success, result from command, or -1.  Note that on
              error, the caller is responsible for any filehandles or other
              things passed in via tags.
SEE ALSO

```c
    [Execute()](autodocs-2.0/dos-library-execute.md), [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md), [<dos/dostags.h>](autodocs-2.0/includes-dos-dostags-h.md), [Input()](autodocs-2.0/dos-library-input.md), [Output()](autodocs-2.0/dos-library-output.md)
```

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SystemTagList — dos.library](../autodocs/dos.library.md#systemtaglist)

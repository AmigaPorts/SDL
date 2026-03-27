---
title: dos.library/CliInitRun
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-cliinitrun
functions: [CliInitNewcli, IoErr, ReplyPkt, WaitPkt]
libraries: [dos.library]
---

# dos.library/CliInitRun

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CliInitRun -- Set up a process to be a shell from initial packet
SYNOPSIS

```c
    flags = CliInitRun( packet )
    D0                    A0

    LONG CliInitRun( struct [DosPacket](autodocs-2.0/includes-dos-dosextens-h.md) * )
```
FUNCTION

```c
    This function initializes a process and CLI structure for a new
    shell, from parameters in an initial packet passed by the system
    (Run, System(), Execute()).  The format of the data in the packet
    is purposely not defined.  The setup includes all the normal fields
    in the structures that are required for proper operation (current
    directory, paths, input streams, etc).

    It returns a set of flags containing information about what type
    of shell invocation this is.

    Definitions for the values of fn:
            Bit 31     Set to indicate flags are valid
            Bit  3     Set to indicate asynch system call
            Bit  2     Set if this is a System() call
            Bit  1     Set if user provided input stream
            Bit  0     Set if RUN provided output stream

    If Bit 31 is 0, then you must check [IoErr()](autodocs-2.0/dos-library-ioerr.md) to determine if an error
    occurred.  If [IoErr()](autodocs-2.0/dos-library-ioerr.md) returns a pointer to your process, there has
    been an error, and you should clean up and exit.  The packet will
    have already been returned by [CliInitNewcli()](autodocs-2.0/dos-library-cliinitnewcli.md).  If it isn't a pointer
    to your process and Bit 31 is 0, you should wait before replying
    the packet until after you've loaded the first command (or when you
    exit).  This helps avoid disk "gronking" with the Run command.
    (Note: this is different from what you do for CliInitNewcli().)

    If Bit 31 is 1, then if Bit 3 is one, [ReplyPkt()](autodocs-2.0/dos-library-replypkt.md) the packet
    immediately (Asynch System()), otherwise wait until your shell exits
    (Sync System(), [Execute()](autodocs-2.0/dos-library-execute.md)).
    (Note: this is different from what you do for CliInitNewcli().)

    This function is very similar to [CliInitNewcli()](autodocs-2.0/dos-library-cliinitnewcli.md).
```
INPUTS

```c
    packet - the initial packet sent to your process [MsgPort](autodocs-2.0/includes-exec-ports-h.md)
```
RESULT

    fn - flags or a pointer
SEE ALSO

```c
    [CliInitNewcli()](autodocs-2.0/dos-library-cliinitnewcli.md), [ReplyPkt()](autodocs-2.0/dos-library-replypkt.md), [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md), System(), [Execute()](autodocs-2.0/dos-library-execute.md), [IoErr()](autodocs-2.0/dos-library-ioerr.md)
```

---

## See Also

- [CliInitNewcli — dos.library](../autodocs/dos.library.md#cliinitnewcli)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [ReplyPkt — dos.library](../autodocs/dos.library.md#replypkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)

---
title: dos.library/CliInitNewcli
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-cliinitnewcli
functions: [CliInitNewcli, CliInitRun, IoErr, ReplyPkt, WaitPkt]
libraries: [dos.library]
---

# dos.library/CliInitNewcli

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CliInitNewcli -- Set up a process to be a shell from initial packet
SYNOPSIS

```c
    flags = CliInitNewcli( packet )
    D0                       A0

    LONG CliInitNewcli( struct [DosPacket](autodocs-2.0/includes-dos-dosextens-h.md) * )
```
FUNCTION

```c
    This function initializes a process and CLI structure for a new
    shell, from parameters in an initial packet passed by the system
    (NewShell or NewCLI, etc).  The format of the data in the packet
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
    have already been returned by CliInitNewcli().  If it isn't a pointer
    to your process and Bit 31 is 0, reply the packet immediately.
    (Note: this is different from what you do for CliInitRun().)

    This function is very similar to [CliInitRun()](autodocs-2.0/dos-library-cliinitrun.md).
```
INPUTS

```c
    packet - the initial packet sent to your process [MsgPort](autodocs-2.0/includes-exec-ports-h.md)
```
RESULT

    fn - flags or a pointer
SEE ALSO

```c
    [CliInitRun()](autodocs-2.0/dos-library-cliinitrun.md), [ReplyPkt()](autodocs-2.0/dos-library-replypkt.md), [WaitPkt()](autodocs-2.0/dos-library-waitpkt.md), [IoErr()](autodocs-2.0/dos-library-ioerr.md)
```

---

## See Also

- [CliInitNewcli — dos.library](../autodocs/dos.library.md#cliinitnewcli)
- [CliInitRun — dos.library](../autodocs/dos.library.md#cliinitrun)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [ReplyPkt — dos.library](../autodocs/dos.library.md#replypkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)

---
title: Initialization
manual: amiga-mail
chapter: amiga-mail
section: initialization
functions: [IoErr, ReplyPkt, WaitPkt]
libraries: [dos.library]
---

# Initialization

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The entity that starts the shell calls the shell code in C style (RTS to
exit). This entity also sends a startup packet to your process port.  You
must retrieve this packet before doing any DOS I/O (much like WBMessages).
You can use WaitPkt() for this.  The entity will take care of attaching a
CommandLineInterface structure to your process, which will be freed on
exit from the UserShell by the system.

In your process structure, check the SegArray pointed to by pr_Seglist
(note that it's a BPTR).  If SegArray[4] is NULL, you must move the value
from SegArray[3] to SegArray[4], and NULL out SegArray[3].  This is
because SegArray[3] will be used to store the seglist pointer for each
program you run.

The startup packet contains some information that tells the UserShell what
kind of shell to be.  At present, the two sets of sources can launch the
UserShell:


```c
    The Run command, Execute(), or System()
    The NewShell or NewCLI resident commands
```
The size of the stack that the system gives the UserShell depends on how
the user started the shell.  If it was started from Execute() or System(),
the stack is 3200 bytes.  If the UserShell was started from Run, NewShell,
or NewCLI, the stack is 4000.

The type of shell required is specified by the combination of the packet's
dp_Res1 and dp_Res2 fields.   Here's a piece of code for turning them into
a value from 0 to 3:


```c
    init_type = (parm_pkt->dp_Res1 == 0 ? 0:2)|(parm_pkt->dp_Res2 == 0 ? 0:1);
```
Currently, only types 0 and 2 are implemented.  For 1 and 3 you should
exit with an error (returning the packet).  Type 0 is for Run, Execute()
and System(), type 2 is for NewShell and NewCLI.  After setting up your
SegArray as above, for type 0 call CliInitRun(pkt), and for type 2 call
CliInitNewcli(pkt). These both return a value we'll call ``fn''.  Keep fn
around, it has useful state information that you'll need later.  Note that
these CliInitXxxx functions don't follow the normal DOS convention of Dn
for arguments (they use A0 for pkt!).

The CliInitXxxx functions do many magic things to get all the streams and
structures properly set up, etc.  You shouldn't need to know anything
about this or what the values in the packet are, other than dp_Res1 and
dp_Res2 (see the Appendix for more information on these functions).


```c
       Definitions for the values of fn:

    Bit 31    Set to indicate flags are valid
    Bit  3     Set to indicate an asynchronous System() call
    Bit  2     Set if this is a System() call
    Bit  1     Set if user provided input stream
    Bit  0     Set if RUN provided output stream
```
If fn bit 31 is 0 (fn >= 0), then you must check IoErr() to find out what
to do.  If IoErr() is a pointer to your process, there has been an error
in the initialization of the CLI structure and processing the packet.  In
this case you should clean up and exit.  You don't have to return the
packet because the CliInitXxxx functions take care of this for you if
there is an error.  If IoErr() isn't a pointer to your process, then if
this is a NewCLI or NewShell command (init_type of 2), reply the packet
immediately.

If the init_type is 0, you have to look at fn to determine when to send
back the startup packet.  If the shell was called from an asynchronous
System() function ((fn & 0x8000000C) == 0x8000000C), return the packet
immediately.  If this is a synchronous System() call ((fn & 0x8000000C) ==
0x80000004) or the fn flags are valid but this is not a System() call ((fn
& 0x8000000C) == 0x80000000) (Execute() does this), you return the packet
just before exiting from your shell (see the Cleanup section below).  If
the fn flags are invalid (bit 31 == 0), but there is something other than
your task pointer in IoErr(), then this shell was called by the Run
command.  Here you can either return the packet immediately, or return it
after having loaded the first command (or failed to find/load it).  This
delay in reply helps avoid the disk thrashing caused by two commands
loading at the same instant.

When you do a ReplyPkt(), use ReplyPkt(pkt, pkt->dp_Res1, pkt->dp_Res2) to
avoid losing error codes set up by CliInitXxxx.

Initialize pr_HomeDir to NULL, set up any local shell variables, etc.

We're all set up now, so you can now enter your main loop and start taking
commands.

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [ReplyPkt — dos.library](../autodocs/dos.library.md#replypkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)

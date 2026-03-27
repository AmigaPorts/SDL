---
title: Finding a Program
manual: amiga-mail
chapter: amiga-mail
section: finding-a-program
functions: [DupLock, Forbid, LoadSeg, Lock, ParentDir, Permit]
libraries: [dos.library, exec.library]
---

# Finding a Program

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several possible places a shell can look for commands passed to
it. The resident list is an important place to look as it contains many
commands that the user finds important enough to keep loaded into memory
at all times. Some shells have commands built directly into them.  Of
course, if the shell cannot find a command in the resident list or in its
collection of internal commands, the shell has to scan the path looking
for the command.  If a shell supports the script bit, when it finds a
command on disk with the script bit set, it should read commands from the
script file.

Here's how you deal with commands on the resident list: After finding the
command (under Forbid()!), if the Segment structure's seg_UC is >= 0,
increment it; if less than 0, don't modify it.  If seg_UC is less than
CMD_DISABLED, the corresponding resident command is currently disabled and
you should not execute it.  The same is true if seg_UC is equal to
CMD_SYSTEM.  After incrementing seg_UC, you can Permit().  After using a
resident command, decrement the seg_UC count if it's greater than 0 (under
Forbid() again).

When identifying scripts, I advise that you use something unique to
identify your scripts, and pass all other scripts to the Boot Shell via
System() for execution.  A good method (which was worked out on BIX long
ago) is to include within the first 256 characters or so, the string
"#!<your shell name, ala csh>!#".  BootShells could, for example, start
with "; #!c:execute!#.  The idea is the string inside the #!...!# should
be the interpreter to run on the script.  If none is specified, give it to
the BootShell.  If you want, you could extend this to include handling of
the sequence for all interpreters. The programs should be invoked as
"<interpreter> <filename> <args>" as if the user had typed that.

Don't forget to set pr_HomeDir for programs loaded from disk.  The Lock in
pr_HomeDir should be a DupLock() of the directory the program was loaded
from. For programs from the resident list, leave it NULL.

Please support multi-assigned C: directories.  The important thing here is
to not lock C:.  Instead, prepend ``C:'' onto the filename you wish to
Lock()/LoadSeg().  Also, if a command is loaded from C:, get its
pr_HomeDir by Lock()ing the file (with C: prepended), and then using
ParentDir() to get its home directory.

The Path is attached to cli_CommandDir.  It is a BPTR to a NULL
terminated, singly-linked list (connected via BPTRs) of directory Locks:


```c
    struct pathBPTRlistentry {
        BPTR   pathBPTRlistentry *next;
        struct Lock              directorylock
    }
```
Please don't modify the list; use the Path command instead.  This will
make it far easier for us to improve this in the future.

Make sure you clear the SIGBREAK_CTRL_x signals before starting a program.
In order to prevent the user from hitting a break key somewhere between
where you check for the break and where you clear the signals (thus losing
the break signal), you may wish check for a break and clear the signals at
the same time. The safest way is to use:


```c
    oldsigs = SetSignal(0L, SIGBREAK_CTRL_C |
                            SIGBREAK_CTRL_D |
                            SIGBREAK_CTRL_E |
                            SIGBREAK_CTRL_F);
```
Then you can check oldsigs for any signals that you care about.

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentDir — dos.library](../autodocs/dos.library.md#parentdir)
- [Permit — exec.library](../autodocs/exec.library.md#permit)

---
title: 14 / Workbench and the Startup Code Module / Shell Startup
manual: libraries
chapter: libraries
section: 14-workbench-and-the-startup-code-module-shell-startup
functions: [Forbid, GetMsg]
libraries: [exec.library]
---

# 14 / Workbench and the Startup Code Module / Shell Startup

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a program is started from the Shell (or a Shell script), standard
startup modules will parse the command line (received in A0, with length
in D0) into an array of pointers to individual argument strings placing
them in argv, and an argument count in argc.

If a program is started from the Shell, argc will always equal at least
one and the first element in argv will always be a pointer to the command
name.  Other command line arguments are stored in turn. For example, if
the command line was:


```c
     df0:myprogram   "my file1"   file2    ;this is a comment
```
then argc will be 3, argv[0] will be "df0:myprogram", argv[1] will be "my
file1", and argv[2] will be "file2".  Correct startup code will strip
spaces between arguments and trailing spaces from the last argument and
will also properly deal with quoted arguments with embedded spaces.

As with Workbench, standard startup code for the Shell sets up [SysBase](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md),
the pointer to the Exec master library, and opens the DOS library setting
up [DOSBase](libraries/17-libraries-and-devices-calling-a-library-function.md).  C applications that are linked with standard startup code can
call an Exec or AmigaDOS functions without opening the library first.

The startup code also fills in the stdio file handles (_stdin, _stdout,
etc.) for the application.  Finally argv and argc, are pushed onto the
stack and the application is called via a JSR.  When the application
returns or exits back to the startup code, the startup code closes and
frees all opens and allocations it has made for the application, and then
returns to the system with the whatever value the program exited with.

Link your applications only with standard, tested startup code of some
type such as the module supplied with your compiler.  Startup code
provides your programs with correct, consistent handling of Shell command
line and Workbench arguments and will perform some initializations and
cleanups which would otherwise need to be handled by your own code.  Very
small startups can be used for programs that do not require command line
arguments.

A few words of warning for those of you who do not use standard startup
code:

  * If you are started as a Workbench process, you must [GetMsg()](libraries/24-messages-getting-a-message.md) the

```c
    [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message before using any functions in the DOS library.
```
  * You must turn off task switching (with [Forbid()](libraries/21-exec-tasks-function-reference.md)) before replying the

```c
    [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message from Workbench.  This will prevent Workbench from
    unloading your code before you can exit properly.
```
  * If you do your own command line parsing, you must provide the user

    with consistent and correct handling of command line arguments.

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)

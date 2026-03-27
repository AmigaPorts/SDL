---
title: The System() Function
manual: amiga-mail
chapter: amiga-mail
section: the-system-function
functions: [Input, Output]
libraries: [dos.library]
---

# The System() Function

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The System() function is intended to replace the Execute() function of
release 1.3.  System() spawns a shell process to execute the command
line which is passed to System() as an argument.  The shell parses the
command-line normally, just like command-lines typed directly into the
shell's console.  If it can, System() will pass the current path and
directory to the programs it launches.

The System() function can execute external commands either
synchronously or asynchronously.  When System() is used synchronously,
control returns to the calling program after the external program has
completed.  In this case, System() returns the external program's
return code, or a -1 if the command could not be found or run.  On the
other hand, when System() initiates a program asynchronously, the
program is no longer a concern for the caller.  The operating system
will take care of the cleanup.  This is extremely useful for an
application that must start up multiple programs on user demand, such
as a hot key commodity.  By default, System() starts programs
synchronously.  To launch a program asynchronously, use the SYS_Asynch
tag with the data field set to TRUE.

With the System() call, it is easy to provide programs with specific
input and output handles.  The tags SYS_Input and SYS_Output (defined
in dos/dostags.h) are used to supply the input and output file
handles.  A program can pass its own input and output handles to a
synchronously launched program by passing the results of Input() and
Output(), respectively.  Note that with a synchronous System() call,
the OS will not close these handles when the spawned process exits.
In the case of an asynchronously launched program, the launching
program normally must provide new IO handles since the system
automatically closes these handles when the asynchronous process ends.
Because AmigaDOS wants separate handles for input and output, System()
will automatically create an output handle if it's passed a handle for
SYS_Input and NULL for SYS_Output.  This allows a program to open a
CON: window for input and use it for both input and output, as
System() will test to see if input is interactive and, if so, will
attempt to open ``*'' for output to that console.  If the input file
handle is not interactive, System() opens ``*'' on the current console
task.

Programs launched using System() are not restricted to the built-in,
or Boot, shell.  In the near future, System() will be able to take
advantage of specially designed shells (the design requirements of
these special shells have not yet been documented).  Two tags,
SYS_UserShell and SYS_CustomShell, specify which shell System() should
use to execute the command-line.  By using the SYS_UserShell tag with
a tag value of TRUE, an application tells System() to send a command
to the user's preferred shell rather that the boot shell (Note that
the default user shell is the boot shell).  If an application opens a
shell for the user or executes the user's command-lines, it should
tell System() to use the user shell.  If an application requires
consistent shell behavior, it must not use the user shell because the
user can change the user shell.  Another shell tag, SYS_CustomShell,
allows an application to choose other shells besides the boot and user
shells.  This tag's data field should contain the custom shell's name
as it appears in the system resident list.

Although it does offer many features, System() does have some
limitations.  First, because command paths currently only exist in the
CLI structure, Workbench (non-CLI) processes have no paths.
Consequently, when a Workbench process calls a program using System(),
the shell has no path to search for that program (aside from the
system default search path of C: and the current directory).  A second
limitation of the System() function involves CTRL-C/D/E/F handling.
When a task opens a CON: window to provide a handle for a
System()-launched command, that task is the owner of the handle.  This
has two effects.  A System()-launched command running in that CON:
window will only be able to receive CTRL-C/D/E/F signals while it is
doing input or output to the window (i.e. when it has a pending read
or write).  If the task that owns the handle is still around, it
receives CTRL-C/D/E/F signals whenever those keys are pressed in the
CON: window.

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)

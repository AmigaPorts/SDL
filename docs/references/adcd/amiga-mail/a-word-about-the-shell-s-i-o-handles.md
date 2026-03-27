---
title: A Word About the Shell's I/O Handles
manual: amiga-mail
chapter: amiga-mail
section: a-word-about-the-shell-s-i-o-handles
functions: [Input, Output, ReadArgs, RunCommand, SelectInput, SelectOutput]
libraries: [dos.library]
---

# A Word About the Shell's I/O Handles

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are three pairs of I/O handles in a shell process.  The shell's
Process structure contains the pr_CIS (current input stream) and pr_COS
(current output stream) file handles.  That Process's CommandLineInterface
structure contains the other two pairs of I/O handles:
cli_StandardInput/cli_StandardOutput and
cli_CurrentInput/cli_CurrentOutput.  Each has different uses within a
normal shell.

Routines that operate on Input() or Output(), such as ReadArgs() or
ReadItem(), use the pr_CIS and pr_COS I/O handles (which they acquire by
calling the dos.library routines Input() and Output(), not by directly
looking at the Process structure).  Shell-launched application programs
the run on the shell's process also use these I/O handles as their normal
input and output channels. This is where functions like scanf() and
printf() get and send their input and output.  The shell changes these
file handles (using SelectInput()/SelectOutput()) according to the shell
defaults and according to any I/O redirection.

The cli_StandardInput and cli_StandardOutput I/O handles are the default
input and output channels for the shell.  They usually refer to the user's
console window and will not change while the shell is running.  The shell
should use these values as the default values for pr_CIS and pr_COS (via
SelectInput() and SelectOutput()) when it runs a command from a command
line.

The cli_CurrentInput handle is the current source of command lines.  This
normally is the same as cli_StandardInput.  The cli_CurrentInput handle
will differ from cli_StandardInput when the shell is executing a script or
when handling an Execute() or System() call.  In these cases, it points to
a file handle from which the shell is reading commands.  This handle
refers to one of three files: the script file you called with the execute
command, a temporary file created by the execute command, or a pseudo file
created by Execute() or System().

When a shell runs the execute command, If cli_CurrentInput differs from
cli_StandardInput, The execute command will close cli_CurrentInput and
replace it with a new one, so don't cache the value of cli_CurrentInput as
it will be invalid.  In this case, cli_CurrentInput must not be the same
as pr_CIS when you call RunCommand() if the executable could possible be
the execute commands (or anything else that tries to close
cli_CurrentInput).

The cli_CurrentOutput file handle is currently unused by the system.  It's
initialized to the same as cli_StandardOutput.

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
- [SelectOutput — dos.library](../autodocs/dos.library.md#selectoutput)

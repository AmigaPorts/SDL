---
title: The Main Shell Loop
manual: amiga-mail
chapter: amiga-mail
section: the-main-shell-loop
functions: [SelectInput, SelectOutput]
libraries: [dos.library]
---

# The Main Shell Loop

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Note: some things in this section assume your UserShell will act similarly
to the Boot Shell in 2.0.  If not, modify to see fit, but pay close
attention to things external programs will notice (such as the setup of
the process and CLI structures).  In particular, the article assumes that
you handle scripts by redirecting cli_CurrentInput to a file with the
script in it, as the execute command does.  Note that the execute command
will attempt to do this if you run it--be careful.

Before reading a command line, you need to SelectInput() on the I/O handle
in the current cli_CurrentInput, and SelectOutput() on cli_StandardOutput.
This makes sure the shell is reading from its command line source and
writing to the the default output handle.

If this shell is executing a script, you should check if the user hit the
break key for scripts (Ctrl-D is what the BootShell uses).  If you do
detect a script break, you can print an error message to the current
output stream by calling PrintFault(304, "<your shell name>").  304 is the
error number (ERROR_BREAK) and the string gets prepended to the error
message (which is currently " :***Break").  This allows the OS to print
the error message using the standard error message which can be
internationalized in future versions of the OS.

Next, determine if you should print a prompt.  The nasty statement below
sets up the Interactive flag for you, by setting it if the following are
true:


```c
    This shell is not a background shell
    input has not been redirected to an Execute/script
    file this is not a System() call
```
You don't have to handle it precisely this way, but this works (Note:
0x80000004 is a test for whether this is a System() call, see the ``fn''
bit definitions above).


#define SYSTEM     ((((LONG)fn) & 0x80000004) == 0x80000004)
#define NOTSCRIPT  (clip->cli_CurrentInput == clip->cli_StandardInput)

  clip->cli_Interactive = (!clip->cli_Background && NOTSCRIPT && !SYSTEM) ?


```c
                   DOSTRUE : FALSE;
```
The BootShell prints a prompt if cli_Interactive is DOSTRUE.

Do all your mucking with the input line, alias and local variable
expansion, etc.

---

## See Also

- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
- [SelectOutput — dos.library](../autodocs/dos.library.md#selectoutput)

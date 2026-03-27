---
title: Running a Program
manual: amiga-mail
chapter: amiga-mail
section: running-a-program
functions: [Close, FGetC, Input, IoErr, ReadArgs, RunCommand, SelectInput, SelectOutput]
libraries: [dos.library]
---

# Running a Program

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To actually invoke a program on your process, use RunCommand()--it does
special compatibility magic that keeps certain third-party applications
working properly.   If RunCommand() fails due to lack of memory, it
returns -1 (normally success!).  In this case, check IoErr().  If it is
equal to ERROR_NO_FREE_STORE, then RunCommand() really ran out of memory.
Note that RunCommand() stuffs a copy of your arguments into the buffer of
the input handle for use by ReadArgs(), and un-stuffs them when the
program exits.  Also note that RunCommand() takes stack size in bytes, and
cli_DefaultStack is the size of the stack in LONGs.

After the program has completed, free the Lock in pr_HomeDir and set it to
NULL.  Re-setup your I/O handles with SelectInput() on cli_CurrentInput
and SelectOutput() on cli_StandardOutput.  It's a good idea to NULL
cli_Module here as well, as it can make your exit/cleanup logic easier.

You must eat any unused buffered input.  Here's some tricky code that does
that (read the Autodocs to figure it out if you wish):


```c
    ch = UnGetC(Input(),-1) ? 0 : '\n';
    while ((ch != '\n') && (ch != END_STREAM_CH)) ch = FGetC(Input());
```
Note: ENDSTREAMCH is EOF (-1).  Newer include files #define this in
<dos/stdio.h> and <dos/stdio.i>.

To finish the main input loop, use the code below or something like it.
This keeps compatibility with certain hacks people had figured out about
1.3 (See SYSTEM and NOTSCRIPT #defines above).


```c
        /* for compatibility */
        /* system exit special case - taken only if they have played */
        /* around with the input stream */
        if (SYSTEM && NOTSCRIPT) break;
    } while (ch != ENDSTREAMCH);
```
EndCLI sets fh_End = 0, which causes FGetC() to call replenish(), which
returns ENDSTREAMCH on fh_End == 0.  EndCLI also sets cli_Background!
This neatly avoids a prompt after EndCLI.

After you've gotten an EOF (falling out of the while(ch != ENDSTREAMCH)
statement above), you need to check if the shell was executing a script
file. For Execute-type scripts, if (cli_CurrentInput != cli_StandardInput)
is true, the shell was executing a script.  If this is the case, you'll
need to Close() the cli_CurrentInput, and DeleteFile() the temporary file
cli_CommandFile, if there is a file name there.  Next, set
cli_CurrentInput to cli_StandardInput, and restore the fail level.  Then
you go back to your normal input loop and accept commands again.  Note:
this is based on handling scripts in the same manner as the BootShell--you
may handle them in different ways.

On EOF, you also need to check if this is a System() call.  The check for
a System() call is ((fn & 0x80000004) == 0x80000004).  If you had been
handling a System() call, or if the shell was not executing a script, you
should go to your cleanup code to exit.

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [Input — dos.library](../autodocs/dos.library.md#input)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
- [SelectOutput — dos.library](../autodocs/dos.library.md#selectoutput)

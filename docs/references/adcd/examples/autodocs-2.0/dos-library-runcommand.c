/* Source: ADCD 2.1
 * Section: dos-library-runcommand
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-runcommand.md
 */

    Runs a command on your process/cli.  Seglist may be any language,
    including BCPL programs.  Stacksize is in bytes.  argptr is a null-
    terminated string, argsize is its length.  Returns the returncode the
    program exited with in d0. Returns -1 if the stack couldn't be
    allocated.

    NOTE: the argument string MUST be terminated with a newline to work
    properly with [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html) and other argument parsers.

    RunCommand also takes care of setting up the current input filehandle
    in such a way that [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html) can be used in the program, and restores
    the state of the buffering before returning.  It also sets the value
    returned by [GetArgStr()](../Includes_and_Autodocs_2._guide/node02B4.html), and restores it before returning.  NOTE:
    the setting of the argument string in the filehandle was added in V37.

    It's usually appropriate to set the command name (via
    [SetProgramName()](../Includes_and_Autodocs_2._guide/node02FB.html)) before calling RunCommand().  RunCommand() sets
    the value returned by [GetArgStr()](../Includes_and_Autodocs_2._guide/node02B4.html) while the command is running.

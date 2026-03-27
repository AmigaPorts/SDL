/* Source: ADCD 2.1
 * Section: dos-library-systemtaglist
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-systemtaglist.md
 */

    Similar to [Execute()](../Includes_and_Autodocs_2._guide/node029E.html), but does not read commands from the input
    filehandle.  Spawns a Shell process to execute the command, and
    returns the returncode the command produced, or -1 if the command
    could not be run for any reason.  The input and output filehandles
    will not be closed by System, you must close them (if needed) after
    System returns, if you specified them via SYS_INPUT or SYS_OUTPUT.

    By default the new process will use your current [Input()](../Includes_and_Autodocs_2._guide/node02BF.html) and [Output()](../Includes_and_Autodocs_2._guide/node02D8.html)
    filehandles.  Normal Shell command-line parsing will be done
    including redirection on 'command'.  The current directory and path
    will be inherited from your process.  Your path will be used to find
    the command (if no path is specified).

    If used with the SYS_Asynch flag, it WILL close both it's input and
    output filehandles after running the command (even if these were
    your [Input()](../Includes_and_Autodocs_2._guide/node02BF.html) and Output()!)

    Normally uses the boot (ROM) shell, but other shells can be specified
    via SYS_UserShell and SYS_CustomShell.  Normally, you should send
    things written by the user to the UserShell.  The UserShell defaults
    to the same shell as the boot shell.

    The tags are passed through to [CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html) (tags that conflict
    with SystemTagList() will be filtered out).  This allows setting
    things like priority, etc for the new process.

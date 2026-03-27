# dos.library/SystemTagList



NAME

```c
    SystemTagList -- Have a shell execute a command line (V36)
```
SYNOPSIS

```c
    error = SystemTagList(command, tags)
    D0                      D1      D2

    LONG SystemTagList(STRPTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *)

    error = System(command, tags)
    D0               D1      D2

    LONG System(STRPTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *)

    error = SystemTags(command, Tag1, ...)

    LONG SystemTags(STRPTR, ULONG, ...)
```
FUNCTION

```c
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
```
INPUTS

```c
    command - Program and arguments
    tags    - see [<dos/dostags.h>](../Includes_and_Autodocs_2._guide/node006D.html).  Note that both SystemTagList()-
              specific tags and tags from [CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html) may be passed.
```
RESULT

    error   - 0 for success, result from command, or -1.  Note that on
              error, the caller is responsible for any filehandles or other
              things passed in via tags.
SEE ALSO

```c
    [Execute()](../Includes_and_Autodocs_2._guide/node029E.html), [CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html), [<dos/dostags.h>](../Includes_and_Autodocs_2._guide/node006D.html), [Input()](../Includes_and_Autodocs_2._guide/node02BF.html), [Output()](../Includes_and_Autodocs_2._guide/node02D8.html)
```

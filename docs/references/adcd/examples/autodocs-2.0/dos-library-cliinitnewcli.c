/* Source: ADCD 2.1
 * Section: dos-library-cliinitnewcli
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-cliinitnewcli.md
 */

    This function initializes a process and CLI structure for a new
    shell, from parameters in an initial packet passed by the system
    (NewShell or NewCLI, etc).  The format of the data in the packet
    is purposely not defined.  The setup includes all the normal fields
    in the structures that are required for proper operation (current
    directory, paths, input streams, etc).

    It returns a set of flags containing information about what type
    of shell invocation this is.

    Definitions for the values of fn:
            Bit 31     Set to indicate flags are valid
            Bit  3     Set to indicate asynch system call
            Bit  2     Set if this is a System() call
            Bit  1     Set if user provided input stream
            Bit  0     Set if RUN provided output stream

    If Bit 31 is 0, then you must check [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) to determine if an error
    occurred.  If [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) returns a pointer to your process, there has
    been an error, and you should clean up and exit.  The packet will
    have already been returned by CliInitNewcli().  If it isn't a pointer
    to your process and Bit 31 is 0, reply the packet immediately.
    (Note: this is different from what you do for CliInitRun().)

    This function is very similar to [CliInitRun()](../Includes_and_Autodocs_2._guide/node0289.html).

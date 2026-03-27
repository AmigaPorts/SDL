/* Source: ADCD 2.1
 * Section: dos-library-exit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-exit.md
 */

    The action of Exit() depends on whether the program which called it
    is running as a command under a CLI or not. If the program is
    running under the CLI the command finishes and control reverts to
    the CLI. In this case, returnCode is interpreted as the return code
    from the program.

    If the program is running as a distinct process, Exit() deletes the
    process and release the space associated with the stack, segment
    list and process structure.

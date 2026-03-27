/* Source: ADCD 2.1
 * Section: dos-library-createnewproc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-createnewproc.md
 */

    This creates a new process according to the tags passed in.  See
    [dos/dostags.h](../Includes_and_Autodocs_2._guide/node006D.html) for the tags.

    You must specify one of NP_Seglist or NP_Entry.  NP_Seglist takes a
    seglist (as returned by LoadSeg()).  NP_Entry takes a function
    pointer for the routine to call.

    There are many options, as you can see by examining [dos/dostags.h](../Includes_and_Autodocs_2._guide/node006D.html).
    The defaults are for a non-CLI process, with copies of your
    [CurrentDir](../Includes_and_Autodocs_2._guide/node028F.html), HomeDir (used for PROGDIR:), priority, consoletask,
    windowptr, and variables.  The input and output filehandles default
    to opens of NIL:, stack to 4000, and others as shown in dostags.h.
    This is a fairly reasonable default setting for creating threads,
    though you may wish to modify it (for example, to give a descriptive
    name to the process.)

    CreateNewProc() is callable from a task, though any actions that
    require doing Dos I/O (DupLock() of currentdir, for example) will not
    occur.

    NOTE: if you call CreateNewProc() with both NP_Arguments, you must
    not specify an NP_Input of NULL.  When NP_Arguments is specified, it
    needs to modify the input filehandle to make [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html) work properly.

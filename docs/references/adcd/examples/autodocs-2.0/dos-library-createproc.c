/* Source: ADCD 2.1
 * Section: dos-library-createproc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-createproc.md
 */

    CreateProc() creates a new AmigaDOS process of name 'name'.  AmigaDOS
    processes are a superset of exec tasks.

    A seglist, as returned by [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html), is passed as 'seglist'.
    This represents a section of code which is to be run as a new
    process. The code is entered at the first hunk in the segment list,
    which should contain suitable initialization code or a jump to
    such.  A process control structure is allocated from memory and
    initialized.  If you wish to fake a seglist (that will never
    have DOS [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html) called on it), use this code:

                DS.L    0   ;Align to longword
                DC.L    16  ;Segment "length" (faked)
                DC.L    0   ;Pointer to next segment
                ...start of code...

    The size of the root stack upon activation is passed as
    'stackSize'.  'pri' specifies the required priority of the new
    process.  The result will be the process msgport address of the new
    process, or zero if the routine failed.  The argument 'name'
    specifies the new process name.  A zero return code indicates
    error.

    The seglist passed to CreateProc() is not freed when it exits; it
    is up to the parent process to free it, or for the code to unload
    itself.

    Under V36 and later, you probably should use [CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html) instead.

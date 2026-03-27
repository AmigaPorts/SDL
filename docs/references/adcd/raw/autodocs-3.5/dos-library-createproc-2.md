# dos.library/CreateProc




    NAME
	CreateProc -- Create a new process

    SYNOPSIS
	process = CreateProc( name, pri, seglist, stackSize )
	D0		      D1    D2	 D3	  D4

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *CreateProc(STRPTR, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129), LONG)

    FUNCTION
	CreateProc() creates a new AmigaDOS process of name 'name'.  AmigaDOS
	processes are a superset of exec tasks.

	A seglist, as returned by [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html), is passed as 'seglist'.
	This represents a section of code which is to be run as a new
	process. The code is entered at the first hunk in the segment list,
	which should contain suitable initialization code or a jump to
	such.  A process control structure is allocated from memory and
	initialized.  If you wish to fake a seglist (that will never
	have DOS [UnLoadSeg()](../Includes_and_Autodocs_3._guide/node01C7.html) called on it), use this code:

		    DS.L    0	;Align to longword
		    DC.L    16	;Segment "length" (faked)
		    DC.L    0	;Pointer to next segment
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

	Under V36 and later, you probably should use [CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html) instead.

    INPUTS
	name      - pointer to a null-terminated string
	pri       - signed long (range -128 to +127)
	seglist   - BCPL pointer to a seglist
	stackSize - integer (must be a multiple of 4 bytes)

    RESULTS
	process   - pointer to new process msgport

    SEE ALSO
	[CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html), [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html), [UnLoadSeg()](../Includes_and_Autodocs_3._guide/node01C7.html)


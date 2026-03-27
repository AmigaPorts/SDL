# dos.library/SetProgramDir



   NAME
	SetProgramDir -- Sets the directory returned by [GetProgramDir](../Includes_and_Autodocs_3._guide/node0179.html) (V36)

   SYNOPSIS
	oldlock = SetProgramDir(lock)
	D0		         D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) SetProgramDir(BPTR)

   FUNCTION
	Sets a shared lock on the directory the program was loaded from.
	This can be used for a program to find data files, etc, that are
	stored with the program, or to find the program file itself.  NULL
	is a valid input.  This can be accessed via [GetProgramDir()](../Includes_and_Autodocs_3._guide/node0179.html) or
	by using paths relative to PROGDIR:.

   INPUTS
	lock - A lock on the directory the current program was loaded from

   RESULT
	oldlock - The previous ProgramDir.

   SEE ALSO
	[GetProgramDir()](../Includes_and_Autodocs_3._guide/node0179.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html)


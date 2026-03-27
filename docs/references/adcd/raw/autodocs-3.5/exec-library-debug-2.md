# exec.library/Debug



   NAME
	Debug -- run the system debugger

   SYNOPSIS
	Debug(flags)
	      D0

	void Debug(ULONG);

   FUNCTION
	This function calls the system debugger.  By default this debugger
	is "SAD" in >= V39 and "ROM-WACK" in < V39.  Other debuggers are
	encouraged to take over this entry point (via [SetFunction()](../Includes_and_Autodocs_3._guide/node0238.html)) so
	that when an application calls Debug(), the alternative debugger
	will get control.  Currently a zero is passed to allow future
	expansion.

   NOTE
	The Debug() call may be made when the system is in a questionable
	state; if you have a [SetFunction()](../Includes_and_Autodocs_3._guide/node0238.html) patch, make few assumptions, be
	prepared for [Supervisor](../Includes_and_Autodocs_3._guide/node0242.html) mode, and be aware of differences in the
	Motorola stack frames on the 68000,'10,'20,'30,'40 (etc.)

   BUGS
	In ROMWack, calling this function in SUPERVISOR state would have
	caused the a5 register to be trashed and the user stack pointer to
	be trashed.  As of V39 (and the instroduction of SAD) this is no
	longer the case.  However, calling this function in [Supervisor](../Includes_and_Autodocs_3._guide/node0242.html)
	state is a bit "tricky" at best...

	Note that due to a bug, pre-V40 SAD had the command
	codes wrong.  See the SAD autodoc for more details.

   SEE ALSO
	[SetFunction()](../Includes_and_Autodocs_3._guide/node0238.html)
	your favorite debugger's manual...
	the SAD autodocs...
	the ROM-WACK chapter of the ROM Kernel Manual... (pre-V39)


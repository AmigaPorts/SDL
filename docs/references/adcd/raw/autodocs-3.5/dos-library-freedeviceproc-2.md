# dos.library/FreeDeviceProc



   NAME
	FreeDeviceProc -- Releases port returned by [GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html) (V36)

   SYNOPSIS
	FreeDeviceProc(devproc)
			 D1

	void FreeDeviceProc(struct [DevProc](../Includes_and_Autodocs_3._guide/node05D9.html#line420) *)

   FUNCTION
	Frees up the structure created by [GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html), and any associated
	temporary locks.

	Decrements the counter incremented by [GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html).  The counter
	is in an extension to the 1.3 process structure.  After calling
	FreeDeviceProc(), do not use the port or lock again!  It is safe to
	call FreeDeviceProc(NULL).

   INPUTS
	devproc - A value returned by [GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html)

   BUGS
	Counter not currently active in 2.0.

   SEE ALSO
	[GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html), [DeviceProc()](../Includes_and_Autodocs_3._guide/node0154.html), [AssignLock()](../Includes_and_Autodocs_3._guide/node0141.html), [AssignLate()](../Includes_and_Autodocs_3._guide/node0140.html),
	[AssignPath()](../Includes_and_Autodocs_3._guide/node0142.html)


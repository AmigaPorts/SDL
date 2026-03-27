# dos.library/DeviceProc



    NAME
	DeviceProc -- Return the process [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) of specific I/O handler

    SYNOPSIS
	process = DeviceProc( name )
	D0		      D1

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *DeviceProc (STRPTR)

    FUNCTION
	DeviceProc() returns the process identifier of the process which
	handles the device associated with the specified name. If no
	process handler can be found then the result is zero. If the name
	refers to an assign then a directory lock is returned in [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).
	This lock should not be UnLock()ed or Examine()ed (if you wish to do
	so, [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html) it first).

    BUGS
	In V36, if you try to DeviceProc() something relative to an assign
	made with [AssignPath()](../Includes_and_Autodocs_3._guide/node0142.html), it will fail.  This is because there's no
	way to know when to unlock the lock.  If you're writing code for
	V36 or later, it is highly advised you use [GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html) instead,
	or make your code conditional on V36 to use GetDeviceProc()/
	[FreeDeviceProc()](../Includes_and_Autodocs_3._guide/node0170.html).

    SEE ALSO
	[GetDeviceProc()](../Includes_and_Autodocs_3._guide/node0177.html), [FreeDeviceProc()](../Includes_and_Autodocs_3._guide/node0170.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html)


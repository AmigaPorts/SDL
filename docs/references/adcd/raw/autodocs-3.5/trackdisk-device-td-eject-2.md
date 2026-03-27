# trackdisk.device/TD_EJECT



   NAME

```c
       TD_EJECT -- eject (or load) the disk in the drive, if possible.
```
   FUNCTION
	This command causes the drive to attempt to eject the disk in
	it, if any.  Note that the current trackdisk.device does not
	implement this command, but it might in the future, and other
	trackdisk-compatible drivers may implement this command.  Some
	devices may be able to load disks on command also.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_EJECT
	io_Flags	0 or IOF_QUICK
	io_Length	0 (load, if supported) or 1 (eject)

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)

   BUGS
	The pre-V40 autodoc didn't mention io_Length.  Because of this, for
	devices that can never support load, a driver might want to eject if
	io_Length is 0.


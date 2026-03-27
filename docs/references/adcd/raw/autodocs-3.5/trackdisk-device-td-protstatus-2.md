# trackdisk.device/TD_PROTSTATUS



   NAME
	TD_PROTSTATUS -- return whether the current disk is write-protected.

   FUNCTION
	This command is used to determine whether the current disk is
	write-protected.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_PROTSTATUS
	io_Flags	0 or IOF_QUICK

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)
	io_Actual - if io_Error is 0, this tells you whether the disk in the
		    drive is write-protected. 0 means the disk is NOT write-
		    protected, while any other value indicates it is.


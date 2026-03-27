# trackdisk.device/TD_MOTOR



   NAME
	TD_MOTOR/ETD_MOTOR -- control the on/off state of a drive motor.

   FUNCTION
	This command gives control over the disk motor. The motor may be
	turned on or off. When it is on, the drive light automatically turns
	on as well.

	If the motor is just being turned on, the device will delay the
	proper amount of time to allow the drive to come up to speed. Normally,
	turning the drive on is not necessary, the device does this
	automatically if it receives a request when the motor is off. However,
	turning the motor off is the programmer's responsibility.

	In addition, the standard instructions to the user are that it is safe
	to remove a disk from a drive if and only if the motor is off (that is,
	if the disk light is off).

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	TD_MOTOR or ETD_MOTOR
	io_Flags	0 or IOF_QUICK
	io_Length	the requested state of the motor, 0 to turn the motor
			off, and 1 to turn the motor on.
	iotd_Count	(ETD_MOTOR only) maximum allowable change counter
			value.

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](../Includes_and_Autodocs_3._guide/node0604.html)
	io_Actual - if io_Error is 0 this contains the previous state of the
		    drive motor.


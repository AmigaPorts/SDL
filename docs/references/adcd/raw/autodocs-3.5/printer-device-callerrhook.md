# printer.device/CallErrHook



   NAME
	CallErrHook -- internal call of error hook

   SYNOPSIS
	result = (*PrinterData->pd_CallErrHook)(hook, iorequest, msg);
	D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CallErrHook(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *, struct [PrtErrMsg](../Includes_and_Autodocs_3._guide/node0605.html#line383) *);

   FUNCTION
	An application can set an error hook that is called in case of
	errors to display an formated and localized error message to the
	user. The driver can set an error hook to format and localize
	custom error messages and to call the application's error hook. This
	is done by calling PD->pd_CallErrHook() from the printer.device.
	CallErrHook will do additional formating like setting a title of
	the error message if no is set by the driver and then calls the
	application's error hook.

   RESULT
	The return value of the hook is returned from CallErrHook.


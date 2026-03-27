# printer.device/PRD_SETERRHOOK



   NAME
	PRD_SETERRHOOK -- set a hook for error messages (V44)

   FUNCTION
	This command sets a hook that will be called if the printer.device
	returns with an error from any other I/O command. This allows
	printer drivers to use private error messages.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	PRD_SETERRORHOOK
	io_Hook		a pointer to a hook that will be called

	Two standard hook values a defined:

	PDHOOK_NONE	no error hook is to be used
	PDHOOK_STD	EasyRequest() is used to display the error message

	The hook gets a pointer to the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) that caused the error as
	the object and a pointer to the following structure as message:

struct [PrtErrMsg](../Includes_and_Autodocs_3._guide/node0605.html#line383) {
	ULONG pe_Version;
	ULONG pe_ErrorLevel;
	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *pe_Window; /* window for EasyRequest() */
	struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) *pe_ES;
	ULONG *pe_IDCMP;
	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) pe_ArgList;
};
	pe_Version	the message version number PDHOOK_VERSION
	pe_ErrorLevel	one of RETURN_WARN, RETURN_ERROR, RETURN_FAIL
	pe_Window	a window pointer (for EasyRequest()) or NULL
	pe_ES		a pointer to the error message structure
	pe_IDCMP	a pointer to IDCMP Flags for EasyRequest()
	pe_ArgList	a pointer to an array of arguments

	The simplest case is to use that structure to call EasyRequest()
	or to [printf()](../Includes_and_Autodocs_3._guide/node0048.html) a message to a console (use the error message from
	pe_ES and the pe_ArgList).


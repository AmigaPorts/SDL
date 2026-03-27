# lowlevel.library/SetJoyPortAttrsA



   NAME
	SetJoyPortAttrsA -- change the attributes of a port.  (V40.27)
	SetJoyPortAttrs -- varargs stub for SetJoyPortAttrsA().  (V40.27)

   SYNOPSIS
	success = SetJoyPortAttrsA(portNumber, tagList);
	D0                         D0          A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetJoyPortAttrsA(ULONG, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	Success = SetJoyPortAttrs(portNumber, firstTag, ...);

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetJoyPortAttrs(Tag, ...);


   FUNCTION
	This function allows modification of several attributes held by
	[ReadJoyPort()](../Includes_and_Autodocs_3._guide/node0468.html) about both it's operation and the type of controller
	currently plugged into the port.

	ReadJoyPort()'s default behavior is to attempt to automatically
	sense the type of controller plugged into any given port, when
	asked to read that port. This behavior is beneficial, to allow
	simple detection of the type of controller plugged into the port.
	Unfortunately, rare cases are possible where extremely fine
	mouse movements appear to be real joystick movements. Also, this
	ability to auto-sense the controller type causes most reads to
	take longer than if there were no auto-sensing.

	SetJoyPortAttrs() is intended to provide for both of these cases.
	It allows the programmer to notify [ReadJoyPort()](../Includes_and_Autodocs_3._guide/node0468.html) to stop spending
	time attempting to sense which type of controller is in use -- and,
	optionally, to force [ReadJoyPort()](../Includes_and_Autodocs_3._guide/node0468.html) into utilizing a certain
	controller type.

   INPUTS
	portNumber - the joyport in question (0-3).
	tagList - a pointer to an array of tags providing parameters
	          to SetJoyPortAttrs(); if NULL, the function
	          will return TRUE, but do nothing.

   TAGS
	SJA_Type (ULONG) - Sets the current controller type to the mouse,
			joystick, or game controller. Supply one of
			SJA_TYPE_GAMECTLR, SJA_TYPE_MOUSE, SJA_TYPE_JOYSTK,
			or SJA_TYPE_AUTOSENSE. If SJA_TYPE_AUTOSENSE is used,
			[ReadJoyPort()](../Includes_and_Autodocs_3._guide/node0468.html) will attempt to determine the type of
			controller plugged into the given port automatically.
			If one of the other types is used, [ReadJoyPort()](../Includes_and_Autodocs_3._guide/node0468.html) will
			make no attempt to read the given controller as
			anything other than the type specified. The default
			type is SJA_AUTOSENSE.

	             	Note -- if you set the type to anything other than
	             	auto-sense, it's your responsibility to return it
	             	to auto-sense mode before exiting.

	SJA_Reinitialize (VOID) - Return a given port to it's initial state,
		     	forcing a port to deallocate any allocated resources;
	             	return the implied type to SJA_TYPE_AUTOSENSE.

   RESULT
	success - TRUE if everything went according to plan, or FALSE upon
		  failure

   SEE ALSO
	[ReadJoyPort()](../Includes_and_Autodocs_3._guide/node0468.html), [<libraries/lowlevel.h>](../Includes_and_Autodocs_3._guide/node0624.html)


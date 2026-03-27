# commodities.library/InvertKeyMap



   NAME
	InvertKeyMap -- generate an input event from an ANSI code. (V36)

   SYNOPSIS
	success = InvertKeyMap(ansiCode,event,km)
	D0	 	       D0       A0    A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) InvertKeyMap(ULONG,struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *,struct [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) *);

   FUNCTION
	This function uses the system call [MapANSI()](../Includes_and_Autodocs_3._guide/node0411.html) to figure out what
	[InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) translates to an ANSI character code 'ansiCode'. The
	[InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) pointed to by 'event' is filled in with that information.
	The [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) 'km' is used for the translation, unless it is NULL, in
	which case the current system default keymap is used.

   INPUTS
	ansiCode - the ANSI code to convert to an input event
	event - the [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) to fill-in
	km - the keymap to use for the translation, or NULL to use the
	     current system default keymap.

   RESULTS
	success - TRUE if the translation worked, FALSE otherwise.

   BUGS
	This function currently handles one-deep dead keys (such as
	<alt f>o ). It does not look up the high key map (keystrokes
	with scan codes greater than 0x40).

	Prior to V40, this function was not initializing the ie_SubClass
	and ie_TimeStamp fields of the [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) structure. A simple work
	around to the problem is to clear these values to 0 before making
	a call to this function:

		struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) ie;

		    ie.ie_SubClass           = 0;
		    ie.ie_TimeStamp.tv_secs  = 0;
		    ie.ie_TimeStamp.tv_micro = 0;
		    if (InvertKeyMap(ansiCode,&ie,NULL))
		    ...

   SEE ALSO
	[cx_lib/InvertString()](../Includes_and_Autodocs_3._guide/node0042.html)


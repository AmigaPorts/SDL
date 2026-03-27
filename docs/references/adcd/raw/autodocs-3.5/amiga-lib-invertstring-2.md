# amiga.lib/InvertString



   NAME
	InvertString -- produce input events that would generate the
			given string. (V36)

   SYNOPSIS
	events = InvertString(str,km)

	struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *InvertString(STRPTR,struct [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) *);

   FUNCTION
	This function returns a linked list of input events which would
	translate into the string using the supplied keymap (or the system
	default keymap if 'km' is NULL).

	'str' is null-terminated and may contain:
	   - ANSI character codes
	   - backslash escaped characters:
		n   -   CR
		r   -   CR
		t   -   TAB
		0   -   illegal, do not use!
		\   -   backslash
	   - a text description of an input event as used by [ParseIX()](../Includes_and_Autodocs_3._guide/node00F3.html),
	     enclosed in angle brackets.

	An example is:

          abc<alt f1>nhi there.
   INPUTS
	str - null-terminated string to convert to input events
	km - keymap to use for the conversion, or NULL to use the default
	     keymap.

   RESULTS
	events - a chain of input events, or NULL if there was a problem. The
		 most likely cause of failure is an illegal description
		 enclosed in angled brackets.

		 This chain should eventually be freed using [FreeIEvents()](../Includes_and_Autodocs_3._guide/node003E.html).

   SEE ALSO
	[commodities.library/ParseIX()](../Includes_and_Autodocs_3._guide/node00F3.html), [FreeIEvents()](../Includes_and_Autodocs_3._guide/node003E.html)


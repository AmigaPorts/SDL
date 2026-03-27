# lowlevel.library/GetLanguageSelection



   NAME
	GetLanguageSelection -- returns the current language selection. (V40)

   SYNOPSIS
	language = GetLanguageSelection();
	D0

	ULONG GetLanguageSelection (VOID);

   FUNCTION
	Determine what the user has specified as a language.

   RESULT
	language - user specified language, or zero if none has yet been
		   specified. See [<libraries/lowlevel.h>](../Includes_and_Autodocs_3._guide/node0624.html) for a definition
		   of the currently supported language.

   SEE ALSO
	[<libraries/lowlevel.h>](../Includes_and_Autodocs_3._guide/node0624.html), locale.doc


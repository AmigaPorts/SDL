# intuition.library/GetDefPrefs



    NAME
	GetDefPrefs -- Get a copy of the the Intuition default [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57).

    SYNOPSIS
	Prefs = GetDefPrefs( PrefBuffer, Size )
	D0		     A0          D0

	struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) *GetDefPrefs( struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) *, WORD );

    FUNCTION
	Gets a copy of the Intuition default preferences data.  Writes the
	data into the buffer you specify.  The number of bytes you want
	copied is specified by the size argument.

	The default preferences are those that Intuition uses when it
	is first opened.  If no preferences file is found, these are
	the preferences that are used.  These would also be the startup
	preferences in an AmigaDOS-less environment.

	It is legal to take a partial copy of the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) structure.
	The more pertinent preferences variables have been grouped near
	the top of the structure to facilitate the memory conservation
	that can be had by taking a copy of only some of the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57)
	structure.

    INPUTS
	PrefBuffer = pointer to the memory buffer to receive your copy of the
```c
                Intuition [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) structure
```
	Size = the number of bytes in your PrefBuffer, the number of bytes
          you want copied from the system's internal Preference settings

    RESULT
	Returns your parameter PrefBuffer.

    BUGS

    SEE ALSO
	[GetPrefs()](../Includes_and_Autodocs_3._guide/node03B8.html)


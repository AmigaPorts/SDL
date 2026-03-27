# intuition.library/SetPrefs



    NAME
	SetPrefs -- Set Intuition preferences data.

    SYNOPSIS
	Prefs = SetPrefs( PrefBuffer, Size, Inform )
	D0		  A0          D0    D1

	struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) *SetPrefs( struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) );

    FUNCTION
	Sets new preferences values.  Copies the first 'Size' bytes
	from your preferences buffer to the system preferences table,
	and puts them into effect.

	The 'Inform' parameter, if TRUE, indicates that an IDCMP_NEWPREFS
	message is to be sent to all windows that have the IDCMP_NEWPREFS
	IDCMPFlag set.

	It is legal to set a partial copy of the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) structure.
	The most frequently changed values are grouped at the beginning
	of the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) structure.

	New for V36:  A new and more extensible method for supplying
	[Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) has been introduced in V36, and relies on file
	system notification.  The Intuition preferences items rely
	also on the IPrefs program.  Certain elements of the
	[Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) structure have been superseded by this new method.
	(Elements are generally superseded as new hardware or software
	features demand more information than fits in struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57).
	Parts of struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) must be ignored so that applications
	calling [GetPrefs()](../Includes_and_Autodocs_3._guide/node03B8.html), modifying some other part of struct [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57),
	then calling SetPrefs(), don't end up truncating the extended
	data).

	Pointer Preferences:  Starting with V36, pointer changes
	submitted through SetPrefs() are only heeded until the first
	time IPrefs informs Intuition of a V36-style pointer preferences
	file.  In V39 and higher, only the pointer from the initial
	SetPrefs() (i.e. devs:system-configuration) is heeded.

	Palette Preferences:  Starting with V39, color changes submitted
	through SetPrefs() are ignored after the first time IPrefs sends
	Intuition new style palette preferences.

	FontHeight and LaceWB:  These are only respected from
	devs:system-configuration.

	[View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) centering and size:  Changes to ViewX/YOffset and
	Row/ColumnSizeChange only apply to the default monitor
	(NTSC or PAL), and not to other monitors such as Productivity.

	Other fields may be superseded in the future.

    INPUTS
	PrefBuffer = pointer to the memory buffer which contains your
	    desired settings for Intuition preferences
	Size = the number of bytes in your PrefBuffer, the number of bytes
           you want copied to the system's internal preference settings
	Inform = whether you want the information of a new preferences
	    setting propagated to all windows.

    NOTES
	Unless you are responding to a user's explicit request to
	change [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) (for example, you are writing a [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57)
	editor), you should probably avoid using this function.
	The user's [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) should be respected, not overridden.

    RESULT
	Returns your parameter PrefBuffer.

    BUGS

    SEE ALSO
	[GetDefPrefs()](../Includes_and_Autodocs_3._guide/node03B7.html), [GetPrefs()](../Includes_and_Autodocs_3._guide/node03B8.html)


# intuition.library/OpenScreenTagList



   NAME	
	OpenScreenTagList -- [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html) with [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) extension array. (V36)
	OpenScreenTags -- Varargs stub for OpenScreenTagList. (V36)

   SYNOPSIS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = OpenScreenTagList( [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476), TagItems )
	D0	  		    A0         A1

	struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *OpenScreenTagList( struct [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476) *,
		struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = OpenScreenTags( [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476), Tag1, ... )

	struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *OpenScreenTags( struct [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476) *,
		ULONG, ... );

   FUNCTION
	Provides an extension to the parameters passed to [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html).
	This extensions is in the form of (a pointer to) an array of
	[TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) structures, which have to fields: ti_Tag, an ID identifying
	the meaning of the other field, ti_Data.  See [<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html).

	The tag items can supplement or override the values in [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476).
	In fact, you can pass a NULL value of the [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476) pointer.
	For that matter, if you pass NULL in both arguments, you'll get
	a screen with defaults in all fields, including display mode,
	depth, colors, dimension, title, and so on.  We ask that
	you at least supply a title when you open a screen.

	See [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html) documentation for parameter specifications.

   INPUTS
 	[NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476)     - (optional) pointer to a [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476) structure.
 	TagItems      - (optional) pointer to (an array of) [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31)
			structures, terminated by the value TAG_END.

   RESULT
 	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132)	- an open Intuition screen.  See [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html) for
		extended error codes when [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) is returned NULL.

   EXAMPLE
	The version using a variable number of arguments must be
	created for each particular compiler, and may not have
	an analogue in all versions.  For vanilla, 32-bit C
	parameter passing conventions, this works (and will
	appear in amiga.lib):

	struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132)	*
	OpenScreenTags( ns, tag1 )
	struct [NewScreen](../Includes_and_Autodocs_3._guide/node0602.html#line476)	*ns;
	ULONG			tag1;
	{
	    struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132)	*OpenScreenTagList();

	    return ( OpenScreenTagList( ns, (struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *) &tag1 ) );
	}

   NOTES
	We recommend this extension to [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html) over using the
	field ExtNewScreen.Extension.  However, the ExtNewScreen.Extension
	is a convenient way to supply a few tags to V36 Intuition which
	will be ignored by V34 Intuition.  See [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html) documentation
	for lots of details.

	A VERY IMPORTANT NOTE about the Screen->BitMap.  In the future,
	bitmaps will need to grow.  The embedded instance of a bitmap
	in the screen will no longer be large enough to hold the whole
	description of the bitmap.

	YOU ARE STRONGLY URGED to use Screen->RastPort.BitMap in place of
	&Screen->BitMap whenever and whereever possible.

   BUGS


   SEE ALSO
	[OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html)


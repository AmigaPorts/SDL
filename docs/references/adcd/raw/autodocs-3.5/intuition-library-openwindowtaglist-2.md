# intuition.library/OpenWindowTagList



   NAME	
	OpenWindowTagList -- [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) with [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) extension. (V36)
	OpenWindowTags -- Varargs stub for OpenWindowTagList (V36)

   SYNOPSIS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = OpenWindowTagList( [NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086), TagItems )
	D0	  		    A0         A1

	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *OpenWindowTagList( struct [NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086) *,
		struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = OpenWindowTags( [NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086), Tag1, ... )

	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *OpenWindowTags( struct [NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086) *, ULONG, ... );

   FUNCTION
	A variation of [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) that allow direct specification of
	a [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) array of extension data.  Recommended over using the
	ExtNewWindow.Extension field.

	If you omit the [NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086) (pass NULL), a set of defaults
	are used, and overridden by the tag items.  Even without
	any tag items at all, a reasonable window opens on the Workbench
	or default public screen.

	See [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) for all the details.

   INPUTS
 	[NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086) - (optional) pointer to a [NewWindow](../Includes_and_Autodocs_3._guide/node05E0.html#line1086) structure.
	TagItems - (optional) pointer to [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) array, with tag
		values as described under the description for
		[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html).

   RESULT
 	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) - newly created window, per your specifications.

   EXAMPLE
	See [OpenScreenTagList()](../Includes_and_Autodocs_3._guide/node03D4.html) for an example of how to create
	a "varargs" version of this function for convenient C
	language programming.

   NOTES


   BUGS


   SEE ALSO
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html)


# gadtools.library/GetVisualInfoA



   NAME
	GetVisualInfoA -- get information GadTools needs for visuals. (V36)
	GetVisualInfo -- varargs stub for GetVisualInfoA(). (V36)

   SYNOPSIS
	vi = GetVisualInfoA(screen, tagList)
	D0                  A0      A1

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) vi = GetVisualInfoA(struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	vi = GetVisualInfo(screen, firsttag, ...)

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) vi = GetVisualInfo(struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

   FUNCTION
	Get a pointer to a (private) block of data containing various bits
	of information that GadTools needs to ensure the best quality
	visuals.  Use the result in the [NewGadget](../Includes_and_Autodocs_3._guide/node062A.html#line82) structure of any gadget
	you create, or as a parameter to the various menu calls.  Once the
	gadgets/menus are no longer needed (after the last CloseWindow),
	call [FreeVisualInfo()](../Includes_and_Autodocs_3._guide/node027A.html).

   INPUTS
	screen - pointer to the screen you will be opening on. This parameter
		 may be NULL, in which case this function fails.
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	There are currently no tags defined for this function.

   RESULT
	vi - pointer to private data, or NULL for failure

   SEE ALSO
	[FreeVisualInfo()](../Includes_and_Autodocs_3._guide/node027A.html), [intuition/LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html),
	[intuition/UnlockPubScreen()](../Includes_and_Autodocs_3._guide/node03FE.html)


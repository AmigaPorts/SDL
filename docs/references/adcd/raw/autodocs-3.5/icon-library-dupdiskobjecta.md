# icon.library/DupDiskObjectA



   NAME
	DupDiskObjectA -- Duplicate an icon (V44)

   SYNOPSIS
	icon = DupDiskObjectA(icon,tags);
	D0                    A0   A1

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) * DupDiskObjectA(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon,
	                                   struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	icon = DupDiskObject(icon,tag1,...);

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) * DupDiskObject(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon,
	                                  [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1,...);

   FUNCTION
	This function is used to create a duplicate of a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64)
	in memory. It can also be used to create an extended
	("native") [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) data structure from an existing,
	traditional format [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) data structure.

   INPUTS
	icon -- Pointer to the icon to be duplicated.
	tags -- Control options.

   TAGS
	ICONDUPA_DuplicateDrawerData (BOOL) -- Duplicate the [DrawerData](../Includes_and_Autodocs_3._guide/node05D6.html#line41),
	    if available.

	    This tag defaults to TRUE.

	ICONDUPA_DuplicateImages (BOOL) -- Duplicate the icon images;
	    note that this DOES NOT include the associated image
	    data. To get the image data duplicated, too, also use
	    the ICONDUPA_DuplicateImageData tag.

	    This tag defaults to TRUE.

	ICONDUPA_DuplicateImageData (BOOL) -- Duplicate the icon image
	    data; this tag works together with the ICONDUPA_DuplicateImages
	    tag. If ICONDUPA_DuplicateImageData is set to TRUE, you must
	    also set ICONDUPA_DuplicateImages to TRUE.

	    This tag defaults to TRUE.

	ICONDUPA_DuplicateDefaultTool (BOOL) -- Duplicate the icon default
	    tool, if available.

	    This tag defaults to TRUE.

	ICONDUPA_DuplicateToolTypes (BOOL) -- Duplicate the icon tool
	    types, if available.

	    This tag defaults to TRUE.

	ICONDUPA_DuplicateToolWindow (BOOL) -- Duplicate the icon tool
	    window if available.

	    This tag defaults to TRUE.

	ICONDUPA_ActivateImageData (BOOL) -- If the source icon contains
	    palette mapped image data that was never put to use (this
	    happens if it is retrieved with the [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html) call rather
	    than the new [GetIconTagList()](../Includes_and_Autodocs_3._guide/node0350.html) call), this tag will cause the
	    image data to be analyzed and an attempt to be made to use that
	    image data in the duplicate. The resulting icon will be remapped
	    for display on the default screen, such as the Workbench screen.

	    This tag defaults to FALSE.

	ICONA_ErrorCode (LONG *) -- Pointer to a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) word variable to
	    store error codes in. Note that this variable will be
	    initialized regardless of whether an error occured or not.
	    Thus, you can check for an error condition by comparing the
	    variable contents against 0; 0 indicates success, all other
	    values are error codes as defined by dos.library.

   RESULT
	icon -- Pointer to a struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) or NULL in case of error.
	    You can use [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to retrieve the error code or use the
	    ICONA_ErrorCode tag instead.

   NOTES
	Any data you chose not to have duplicated will be set to NULL.
	For example, if you specified "ICONDUPA_DuplicateImages,FALSE",
	then the resulting icon's do_Gadget.GadgetRender and
	do_Gadget.SelectRender will both be NULL.

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[workbench/icon.h](../Includes_and_Autodocs_3._guide/node0618.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)


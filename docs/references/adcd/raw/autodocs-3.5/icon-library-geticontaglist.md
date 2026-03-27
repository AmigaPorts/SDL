# icon.library/GetIconTagList



   NAME
	GetIconTagList -- Retrieve an icon (V44)

   SYNOPSIS
	icon = GetIconTagList(name,tags);
	D0                    A0   A1

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) * GetIconTagList(STRPTR name,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	icon = GetIconTags(name,tag1,...);

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) * GetIconTags(STRPTR name,[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1,...);

   FUNCTION

	This function is used to retrieve an icon; the icon can
	belong to a file/drawer/volume or it can be a default icon.

   INPUTS
	name -- Name of the object an icon is to be retrieved for,
	    or NULL if a default icon is to be retrieved.
	tags -- Retrieval options.

   TAGS
	ICONGETA_GetDefaultType (LONG) -- Type of the default icon
	    to retrieve; must be one of WBDISK, WBDRAWER, WBTOOL,
	    WBPROJECT, WBGARBAGE, WBDEVICE or WBKICK.

	    If this tag is used, the "name" parameter will be ignored.

	ICONGETA_GetDefaultName (STRPTR) -- Name of the default object
	    type to retrieve a default icon for. If the named default
	    icon cannot be found, NULL will be returned. To avoid
	    this, also specify ICONGETA_GetDefaultType: this will provide
	    a fall-back and return a "default" default icon instead.

	    If this tag is used, the "name" parameter will be ignored.

	ICONGETA_FailIfUnavailable (BOOL) -- If there is no icon for
	    the specified object, this tag will control how to
	    proceed: if ICONGETA_FailIfUnavailable is set to TRUE,
	    NULL and an error code will be returned; if set to FALSE,
	    icon.library will first invoke the global identification
	    hook (see icon.library/IconControlA) and then, if necessary,
	    provide a default icon for the object in question.

	    This tag defaults to TRUE.

	ICONGETA_GetPaletteMappedIcon (BOOL) -- By default, icon.library
	    will try to retrieve the palette mapped version of an icon. To
	    change this, set the ICONGETA_GetPaletteMappedIcon tag to FALSE.

	    This tag defaults to TRUE.

	ICONGETA_RemapIcon (BOOL) -- Palette mapped icons will usually
	    be automatically remapped for display on the screen
	    selected using [IconControlA()](../Includes_and_Autodocs_3._guide/node0351.html). If you do not want this to
	    happen because, for example, you want to use LayoutIcon()
	    instead, you can set the ICONGETA_RemapIcon tag to FALSE.
	    Take care when doing this as the icon returned to you
	    will have NULL pointers in the do_Gadget.GadgetRender
	    and do_Gadget.SelectRender members.

	    This tag defaults to TRUE.

	ICONGETA_IsDefaultIcon (LONG *) -- When retrieving an icon with
	    the ICONGETA_FailIfUnavailable tag set to FALSE, you may
	    receive a default icon because there is no on-disk icon
	    file for the object you wanted to retrieve it for. This
	    type of default icon is also known as a "fake" icon.
	    To find out whether you have received a fake icon, use the
	    ICONGETA_IsDefaultIcon tag.

	ICONGETA_GenerateImageMasks (BOOL) -- When loading icons with
	    transparent colours or backfill imagery, bit plane masks
	    will be generated for later use with [DrawIconStateA()](../Includes_and_Autodocs_3._guide/node0347.html).
	    If you do not need these masks, set this tag to FALSE.

	    This tag defaults to TRUE.

	ICONGETA_Screen (struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *) -- Pointer to the screen
	    to remap the icon to; if set to NULL, this keeps the
	    icon from getting remapped in the first place (see
	    ICONGETA_RemapIcon for the consequences).

	    This tag defaults to the default screen to remap to, as
	    preset by [IconControlA()](../Includes_and_Autodocs_3._guide/node0351.html).

	ICONGETA_Label (STRPTR) -- The label text to be printed below
	    the icon when it is put to use lateron. This parameter
	    can be useful to figure out the type of the icon to
	    be retrieved by the identification hook. For example,
	    Workbench may label unreadable disk icons as "DF0:????".
	    The identification hook could key on this and supply an
	    appropriate icon for the disk.

	    This tag defaults to NULL.

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

   EXAMPLE

	/* Retrieve the default drawer icon. */
	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon;
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) errorCode;

	icon = GetIconTags(NULL,
	    ICONGETA_GetDefaultType,WBDRAWER,
	    ICONA_ErrorCode,&errorCode,
	TAG_DONE);

	if(icon == NULL)
	{
	    Printf("could not retrieve default drawer icon;n");
	    PrintFault(errorCode,NULL);
	}

	/* Retrieve the default "picture" icon. */
	icon = GetIconTags(NULL,
	    ICONGETA_GetDefaultName,"picture",
	TAG_DONE);

	/* Retrieve the default "picture" icon; if there is no
	 * such default icon, retrieve the default project
	 * icon instead.
	 */
	icon = GetIconTags(NULL,
	    ICONGETA_GetDefaultName,"picture",
	    ICONGETA_GetDefaultType,WBPROJECT,
	TAG_DONE);

	/* Retrieve the regular, non-palette-mapped version of
	 * an icon.
	 */
	icon = GetIconTags("file",
	    ICONGETA_GetPaletteMappedIcon,FALSE,
	TAG_DONE);

	/* Retrieve the icon for a file; if there is no icon associated
	 * with it, retrieve a default icon that matches the file.
	 * Also, remember whether we got a real icon or a fake one.
	 */
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) isFakeIcon;

	icon = GetIconTags("file",
	    ICONGETA_FailIfUnavailable,FALSE,
	    ICONGETA_IsDefaultIcon,&isFakeIcon,
	TAG_DONE);

	if(icon != NULL)
	{
	    Printf("got an icon at 0x%08lx, and it is a %s icon.n",
	        icon,isFakeIcon ? "fake" : "real");
	}

   NOTES
	This function is a superset of [GetDefDiskObject()](../Includes_and_Autodocs_3._guide/node034C.html), [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html)
	and [GetDiskObjectNew()](../Includes_and_Autodocs_3._guide/node034E.html).

	If a palette-mapped icon is set to allocate its colours from the
	default screen, such as the Workbench screen, icon.library may
	resort to remap its colours in the course of Workbench screen
	close/reopen transitions. This means that you cannot depend upon
	the icon's image bitmaps to stay the same size, shape or colour.
	If this is what you need, you should either create your own images
	from the palette mapped data or make copies of the icon image
	bitmaps and the associated colour table.

	If during Workbench close/open transitions the global remap
	screen becomes NULL, GetIconTagList() may refuse to return a
	remapped icon and return with an error (ERROR_REQUIRED_ARG_MISSING)
	instead.

   SEE ALSO
	[workbench/icon.h](../Includes_and_Autodocs_3._guide/node0618.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)
	[icon.library/GetDiskObject](../Includes_and_Autodocs_3._guide/node034D.html)
	[icon.library/GetDiskObjectNew](../Includes_and_Autodocs_3._guide/node034E.html)
	[icon.library/GetDefDiskObject](../Includes_and_Autodocs_3._guide/node034C.html)
	[icon.library/IconControlA](../Includes_and_Autodocs_3._guide/node0351.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)


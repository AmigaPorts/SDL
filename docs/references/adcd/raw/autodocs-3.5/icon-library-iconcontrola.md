# icon.library/IconControlA



   NAME
	IconControlA -- Set and get icon and icon.library options (V44)

   SYNOPSIS
	processed = IconControlA(icon,tags);
	D0                       A0   A1

	ULONG IconControlA(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	processed = IconControl(icon,tag1,...);

	ULONG IconControl(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *,[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1,...);

   FUNCTION

	This function is used to modify and query icon and icon.library
	options.

   INPUTS
	icon -- Pointer to a struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64), or NULL if global
		options are to be modified/queried.
	tags -- Options to modify/query.

   TAGS
	ICONCTRLA_SetGlobalScreen (struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *) -- Pointer to the
	    screen to remap palette mapped icons to. This is commonly
	    used by workbench.library after it has initialized itself
	    and before/after screen open/close transitions. If the
	    screen is set to NULL, the icon colour remapping strategy is
	    changed: colours are no longer allocated from a screen
	    and the colours to map to will come from a default colour
	    colour table with four palette entries. Please note that
	    once you select a screen to remap to, you cannot tell
	    icon.library to use a different screen; you first need to
	    tell icon.library to "let go" of the previously selected
	    screen by passing a NULL ICONCTRLA_SetGlobalScreen parameter.
	    You can set a different screen only after this is done.

	ICONCTRLA_GetGlobalScreen (struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) **) -- Pointer to the
	    screen to remap palette mapped icons to.

	ICONCTRLA_SetGlobalPrecision (LONG) -- Set the global colour
	    allocation precision used when remapping icons for
	    display. Default is PRECISION_ICON.

	OBP_Precision (LONG) -- Can be used as an alias for the
	    ICONCTRLA_SetGlobalPrecision tag.

	ICONCTRLA_GetGlobalPrecision (LONG *) -- Get the global colour
	    allocation precision used when remapping icons for
	    display.

	ICONCTRLA_SetGlobalEmbossRect (struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) *) -- Set the
	    frame sizes used for drawing icons. The [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26)
	    must be initialized as follows:

	        Rectangle->MinX  Width of left edge border (negative),
	                         must be in the range [-255..-1]
	        Rectangle->MinY  Height of top edge border (negative),
	                         must be in the range [-255..-1]
	        Rectangle->MaxX  Width of right edge border (positive),
	                         must be in the range [1..255]
	        Rectangle->MaxY  Height of bottom edge border (positive),
	                         must be in the range [1..255]

	ICONCTRLA_GetGlobalEmbossRect (struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) *) -- Get the
	    frame sizes used for drawing icons.

	ICONCTRLA_SetGlobalFrameless (BOOL) -- Select whether icons
	    should always be drawn without a surrounding frame.
	    This option defaults to FALSE.

	ICONCTRLA_GetGlobalFrameless (LONG *) -- Query whether icons
	    are always drawn without a surrounding frame.

	ICONCTRLA_SetGlobalIdentifyHook (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *) -- Set the
	    hook that is invoked when trying to find an icon
	    for a file/drawer/volume that does not have an
	    icon associated with it. If set to NULL, no hook
	    will be called. The hook will be called with the
	    following parameters:

	    hookFunc(hook,reserved,iim)
	              A0     A2    A1

	    VOID hookFunc(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook,[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) reserved,
	                  struct [IconIdentifyMsg](../Includes_and_Autodocs_3._guide/node0618.html#line255) *iim);

	    The reserved parameter will be set to NULL (V44).

	    The icon identification message contents are as follows:

	        iim_SysBase
	        iim_DOSBase
	        iim_UtilityBase
	        iim_IconBase
	            [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) base pointers set up for your use.

	        iim_FileLock
	            A lock on the object to return an icon for.
	            This lock is guaranteed to be non-NULL.

	        iim_ParentLock
	            A lock on the object's parent directory. This
	            may be NULL if iim_FileLock points to a volume's
	            root directory. In such a case you should return
	            a WBDISK type icon instead of a WBDRAWER icon.

	        iim_FIB
	            An initialized [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) structure; prior
	            to passing iim_FIB to you, Examine(iim_FileLock,iim_FIB)
	            was called. Unlike the other members of this data
	            structure, you may modify the contents of iim_FIB.

	        iim_FileHandle
	            If the object to return an icon for is a file,
	            this member will contain a file handle that can
	            be used to [Read()](../Includes_and_Autodocs_3._guide/node01A0.html) its contents. The file read
	            position will be set to the beginning of
	            the file. Note that this member can be NULL.

	        iim_Tags
	            A copy of the tag item list passed to GetIconTagList();
	            if you are going to call [GetIconTagList()](../Includes_and_Autodocs_3._guide/node0350.html) in your
	            hook, be sure to include this list as part of the
	            tag list you pass to it.

	            NOTE: This list does not include the tag
	                  ICONA_FailIfUnavailable. Keep in mind that
	                  the use of this tag can trigger a recursion
	                  if the icon you tried to retrieve via
	                  [GetIconTagList()](../Includes_and_Autodocs_3._guide/node0350.html) does not exist: your hook
	                  code will be invoked again.

	    With the exception of iim_FIB, all members of the
	    [IconIdentifyMsg](../Includes_and_Autodocs_3._guide/node0618.html#line255) are read-only; you may pass them to
	    functions like [Read()](../Includes_and_Autodocs_3._guide/node01A0.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), etc. but you
	    may not [Close()](../Includes_and_Autodocs_3._guide/node0149.html) files, [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html) locks or perform
	    other functions that may result in the data structures
	    getting deallocated or trashed.

	    When you manage to find the right icon type for the object
	    to be examined, you should return a pointer to a
	    struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) that can be freed using [FreeDiskObject()](../Includes_and_Autodocs_3._guide/node034A.html)
	    lateron. Note that you cannot just return a pointer to a
	    statically initialized data structure in your code, you
	    must return a pointer to a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) allocated by icon.library
	    itself, such as through [GetIconTagList()](../Includes_and_Autodocs_3._guide/node0350.html), [DupDiskObjectA()](../Includes_and_Autodocs_3._guide/node0348.html)
	    or [NewDiskObject()](../Includes_and_Autodocs_3._guide/node0354.html).

	    The icon you return will be checked to make sure that its
	    type matches the corresponding object. For example, returning
	    a WBDRAWER icon for a volume root directory will cause that
	    icon to be released and to be ignored.

	ICONCTRLA_GetGlobalIdentifyHook (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) **) -- Get the
	    hook that is invoked when trying to find an icon
	    for a file/drawer/volume that does not have an
	    icon associated with it.

	ICONCTRLA_SetGlobalMaxNameLength (LONG) -- icon.library has
	    a built-in file name length limit that affects whether
	    icon files are read and written. Currently, the default
	    for this value is 25 characters. This is sufficient for
	    an icon file name acceptable with the ROM filing system.
	    This limit has two effects: if an icon file is to be
	    written whose name would be longer than the limit,
	    icon.library will silently abort the write attempt and
	    pretend that the icon file has been written; this is done
	    in order to avoid overwriting the original data file with
	    the icon file. If an icon file was read that turns out to
	    contain invalid icon data, another test is done in order to
	    find out whether the file name was longer than the limit. If
	    this is the case, it is assumed that the data was read from
	    the original file rather than from the icon file. The library
	    then pretends that the icon file was not found.

	    This tag can be used to set this length limit. The limit
	    must be in the range [8..255].

	ICONCTRLA_GetGlobalMaxNameLength (LONG *) -- Retrieve the
	    file name length limit used by icon.library.

	ICONCTRLA_SetGlobalNewIconsSupport (BOOL) -- Select whether
	    icon.libray should read and return coloured icon images stored
	    in NewIcons format.
	    This option defaults to TRUE.

	ICONCTRLA_GetGlobalNewIconsSupport (LONG *) -- Query whether
	    icon.library will read and return coloured icon images
	    stored in NewIcons format.

	ICONCTRLA_SetGlobalColorIconSupport (BOOL) -- Select whether
	    icon.libray should read and return coloured icon images.
	    This option defaults to TRUE.

	ICONCTRLA_GetGlobalColorIconSupport (LONG *) -- Query whether
	    icon.library will read and return coloured icon images.

	ICONA_ErrorCode (LONG *) -- Pointer to a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) word variable to
	    store error codes in. Note that this variable will be
	    initialized regardless of whether an error occured or not.
	    Thus, you can check for an error condition by comparing the
	    variable contents against 0; 0 indicates success, all other
	    values are error codes as defined by dos.library.

	ICONA_ErrorTagItem (struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) **) -- When an error occurs
	    whilst processing the tag item list passed to IconControl(),
	    you can have a pointer to the item that caused the error
	    passed back via the ICONA_ErrorTagItem tag. Note that for
	    [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) lists allocated from the stack the address passed
	    back to you may no longer be valid when control returns from
	    IconControl().

	The following tags need a valid icon parameter to operate on.
	If the parameter is missing or invalid, it will be registered
	as an error.

	ICONCTRLA_GetImageMask1 (PLANEPTR *) -- Pointer to the mask plane
	    for the regular icon image (icon->do_Gadget.GadgetRender).
	    Note that this may be NULL.

	ICONCTRLA_GetImageMask2 (PLANEPTR *) -- Pointer to the mask plane
	    for the alternate icon image (icon->do_Gadget.SelectRender).
	    Note that this may be NULL.

	ICONCTRLA_SetTransparentColor1 (LONG) -- Set the transparent
	    colour for a palette mapped icon image, in this case the
	    regular icon image (icon->do_Gadget.GadgetRender). The
	    colour must be among the valid palette entries, e.g. for
	    a 16 colour image, the transparent colour may not be
	    larger than 15. To make the icon image opaque, set its
	    transparent colour to -1.

	ICONCTRLA_GetTransparentColor1 (LONG *) -- Get the transparent
	    colour for a palette mapped icon image, in this case the
	    regular icon image (icon->do_Gadget.GadgetRender). If
	    the image is opaque, its "transparent colour" will be
	    returned as -1. Note that this data is valid only for
	    palette mapped icons; for other types, you may not
	    receive any meaningful result.

	ICONCTRLA_SetTransparentColor2 (LONG) -- Set the transparent
	    colour for a palette mapped icon image, in this case the
	    alternate icon image (icon->do_Gadget.SelectRender). The
	    colour must be among the valid palette entries, e.g. for
	    a 16 colour image, the transparent colour may not be
	    larger than 15. To make the icon image opaque, set its
	    transparent colour to -1. Please note that you can set
	    the alternate image transparent colour only if there is
	    an alternate image.

	ICONCTRLA_GetTransparentColor2 (LONG *) -- Get the transparent
	    colour for a palette mapped icon image, in this case the
	    alternate icon image (icon->do_Gadget.SelectRender). If
	    the image is opaque, its "transparent colour" will be
	    returned as -1. Note that this data is valid only for
	    palette mapped icons; for other types, you may not
	    receive any meaningful result. Likewise, if there is
	    no alternate image, no information may be available.

	ICONCTRLA_SetPalette1 (struct [ColorRegister](../Includes_and_Autodocs_3._guide/node05DD.html#line223) *) -- Set the colour
	    palette for a palette mapped icon image, in this case the
	    regular icon image (icon->do_Gadget.GadgetRender).

	ICONCTRLA_GetPalette1 (struct [ColorRegister](../Includes_and_Autodocs_3._guide/node05DD.html#line223) **) -- Get the colour
	    palette for a palette mapped icon image, in this case the
	    regular icon image (icon->do_Gadget.GadgetRender). Note
	    that this data is valid only for palette mapped icons; for
	    other types, you may not receive any meaningful result.
	    Note that the number of palette entries in this table
	    matches the number of colours in use when the icon
	    was first created.

	ICONCTRLA_SetPalette2 (struct [ColorRegister](../Includes_and_Autodocs_3._guide/node05DD.html#line223) *) -- Set the colour
	    palette for a palette mapped icon image, in this case the
	    alternate icon image (icon->do_Gadget.SelectRender).

	ICONCTRLA_GetPalette2 (struct [ColorRegister](../Includes_and_Autodocs_3._guide/node05DD.html#line223) **) -- Get the colour
	    palette for a palette mapped icon image, in this case the
	    alternate icon image (icon->do_Gadget.SelectRender). Note
	    that this data is valid only for palette mapped icons; for
	    other types, you may not receive any meaningful result.
	    If there is no alternate image, no information may be
	    available.
	    Note that the number of palette entries in this table
	    matches the number of colours in use when the icon
	    was first created.

	ICONCTRLA_SetPaletteSize1 (ULONG) -- Set the size of the colour
	    palette to be used for a palette mapped icon image, in
	    this case the regular icon image (icon->do_Gadget.GadgetRender).
	    This value must be in the range [1..256].

	ICONCTRLA_GetPaletteSize1 (ULONG *) -- Get the size of the colour
	    palette to be used for a palette mapped icon image, in
	    this case the regular icon image (icon->do_Gadget.GadgetRender).
	    Note that this data is valid only for palette mapped icons; for
	    other types, you may not receive any meaningful result.

	ICONCTRLA_SetPaletteSize2 (ULONG) -- Set the size of the colour
	    palette to be used for a palette mapped icon image, in
	    this case the alternate icon image (icon->do_Gadget.SelectRender).
	    This value must be in the range [1..256].

	ICONCTRLA_GetPaletteSize2 (ULONG *) -- Get the size of the colour
	    palette to be used for a palette mapped icon image, in
	    this case the alternate icon image (icon->do_Gadget.SelectRender).
	    Note that this data is valid only for palette mapped icons; for
	    other types, you may not receive any meaningful result.
	    If there is no alternate image, no information may be
	    available.

	ICONCTRLA_SetImageData1 (UBYTE *) -- Set the image data to be used for
	    a palette mapped icon image, in this case the regular icon
	    image (icon->do_Gadget.GadgetRender). There must be exactly
	    as many bytes of image data as the image width multiplied
	    by its height requires.

	    To drop the palette mapped image data associated with an icon,
	    use "ICONCTRLA_SetImageData1,NULL,".

	ICONCTRLA_GetImageData1 (UBYTE **) -- Get the image data to be used for
	    a palette mapped icon image, in this case the regular icon
	    image (icon->do_Gadget.GadgetRender). Note that this data is
	    valid only for palette mapped icons; for other types, you may
	    not receive any meaningful result.

	ICONCTRLA_SetImageData2 (UBYTE *) -- Set the image data to be used for
	    a palette mapped icon image, in this case the alternate icon
	    image (icon->do_Gadget.SelectRender). There must be exactly
	    as many bytes of image data as the image width multiplied
	    by its height requires.

	    To drop the palette mapped image data associated with the alternate
	    image of an icon, use "ICONCTRLA_SetImageData2,NULL,".

	ICONCTRLA_GetImageData2 (UBYTE **) -- Get the image data to be used for
	    a palette mapped icon image, in this case the alternate icon
	    image (icon->do_Gadget.SelectRender). Note that this data is
	    valid only for palette mapped icons; for other types, you may
	    not receive any meaningful result. If there is no alternate
	    image, no information may be available.

	ICONCTRLA_SetFrameless (BOOL) -- Select whether the icon should be
	    drawn without a frame. This option defaults to FALSE.

	ICONCTRLA_GetFrameless (LONG *) -- Query whether the icon should be
	    drawn without a frame.

	ICONCTRLA_SetNewIconsSupport (BOOL) -- Select whether palette mapped
	    icon images that were originally stored in NewIcons format
	    should be written back in the same format. This option
	    defaults to TRUE.

	ICONCTRLA_GetNewIconsSupport (LONG *) -- Query whether palette mapped
	    icon images that were originally stored in NewIcons format
	    should be written back in the same format.

	ICONCTRLA_SetAspectRatio (UBYTE) -- Set the icon aspect ratio; this
	    consists of a numerator and a denominator packed into a
	    single byte (the PACK_ICON_ASPECT_RATIO() macro can be used
	    for encoding this parameter). If the icon aspect ratio is
	    unknown, ICON_ASPECT_RATIO_UNKNOWN should be used.

	ICONCTRLA_GetAspectRatio (UBYTE *) -- Get the icon aspect ratio; this
	    consists of a numerator and a denominator packed into a
	    single byte (the UNPACK_ICON_ASPECT_RATIO() macro can be used
	    for decoding this value). If the icon aspect ratio is unknown,
	    ICON_ASPECT_RATIO_UNKNOWN will be returned.

	ICONCTRLA_SetWidth (ULONG) -- Select the palette mapped icon image
	    width. This value must be in the range [1..256].

	ICONCTRLA_GetWidth (ULONG *) -- Query the palette mapped icon image
	    width. Note that this data is valid only for palette mapped icons;
	    for other types, you may not receive any meaningful result.

	ICONCTRLA_SetHeight (ULONG) -- Select the palette mapped icon image
	    height. This value must be in the range [1..256].

	ICONCTRLA_GetHeight (ULONG *) -- Query the palette mapped icon image
	    height. Note that this data is valid only for palette mapped icons;
	    for other types, you may not receive any meaningful result.

	ICONCTRLA_IsPaletteMapped (LONG *) -- Query whether the icon is using
	    palette mapped icon images.

	ICONCTRLA_IsNewIcon (LONG *) -- Query whether the icon is of the
	    NewIcon type.

	ICONCTRLA_IsNativeIcon (LONG *) -- There is an important difference
	    between struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) icons allocated by icon.library itself
	    (these are the so-called "native" icons) and statically initialized
	    icons which consist solely of a simple struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) which may
	    be part of a program's static data area. For example, you can
	    attach a palette mapped icon image to a "native" icon, which is
	    something you cannot do with a statically allocated icon. To help
	    you tell the two types apart, you can use the ICONCTRLA_IsNativeIcon
	    query tag.

	ICONGETA_IsDefaultIcon (LONG *) -- Query whether this icon is associated
	    with a file/drawer/volume or is a "fake" icon that was constructed
	    for an object that has no icon associated with it.

	ICONCTRLA_GetScreen (struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) **) -- Get the screen this icon
	    has been remapped to and whose colour map it uses. Note that this
	    data is valid only for palette mapped icons; for other types, you
	    may not receive any meaningful result.

	    This tag may return NULL if the icon is not currently associated
	    with a screen.

	ICONCTRLA_HasRealImage2 (LONG *) -- icon.library may generate an
	    alternate image for palette mapped icons if there is no image
	    data stored for this image. To find out whether an icon
	    was generated or is part of the original icon image, use the
	    ICONCTRLA_HasRealImage2 tag.

   RESULT
	processed -- Number of tags that were processed correctly, i.e.
	    the number of tags whose parameters are in order, for which
	    information could be returned, etc. If processing stops because of
	    an error, the number returned by this function will be smaller
	    than the number of tag items passed in. The same happens if
	    the information you wanted to obtain is unavailable. In any
	    case, check the error code this routine can set up for you.

   EXAMPLE
	/* Check if the icon is palette mapped. */
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) isPaletteMapped;
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) errorCode;
	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon;

	if(IconControl(icon,
	    ICONCTRLA_IsPaletteMapped,&isPaletteMapped,
	    ICONA_ErrorCode,&errorCode,
	TAG_DONE) == 1)
	{
	    Printf("the icon %s palette mappedn",
	        isPaletteMapped ? "is" : "is not");
	}
	else
	{
	    Printf("could not query icon information;n");
	    PrintFault(errorCode,NULL);
	}

	/* Set the icon colour remapping precision. */
	IconControl(NULL,
	    ICONCTRLA_SetGlobalPrecision,PRECISION_EXACT,
	TAG_DONE);

	/* Query the embossing rectangle dimensions and
	 * the identification hook.
	 */
	struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) rect;
	struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook;

	if(IconControl(NULL,
	    ICONCTRLA_GetGlobalEmbossRect,&rect,
	    ICONCTRLA_GetGlobalIdentifyHook,&hook,
	TAG_DONE) == 2)
	{
	    Printf("embossing rect: %ld,%ld,%ld,%ldn",
	        rect.MinX,rect.MaxX,rect.MinY,rect.MaxY);
	    Printf("identification hook: 0x%08lxn",
	        hook);
	}

   NOTES
	Changing an icon's palette or image data does not automatically
	produce a different icon image you can use. To do this, you
	must re-layout it using LayoutIcon().

	When querying parameters, make sure to always pass in a pointer
	to a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) word variable to store the result in.

	Some get/set operations may cause additional memory to be
	allocated. This may fail; be prepared.

	IconControl() processes the tag item list in sequential order.
	This has consequences for several tags, such as the palette size
	and the transparent colour. For example, if you want to make
	colour #14 of an icon image transparent, make sure to have the
	palette size set to at least 15 colours before you try to change
	the transparent colour. Otherwise, IconControl() may refuse to
	set the transparent colour to #14 since it won't know that there
	should be more than 14 colours in that image at the time you try
	to set it. Therefore, if you wanted to change the palette size and
	the transparent colour in the same tag item list, make sure that the
	palette size change tag appears before the transparent colour change
	tag.

	As described above, some of the operations on icons are not
	supported for DiskObjects not allocated through icon.library. In
	such cases you will receive an error code ERROR_ACTION_NOT_KNOWN.

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/DupDiskObjectA](../Includes_and_Autodocs_3._guide/node0348.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	icon.library/LayoutIcon
	[icon.library/NewDiskObject](../Includes_and_Autodocs_3._guide/node0354.html)
	[graphics.library/BltMaskBitMapRastPort](../Includes_and_Autodocs_3._guide/node02B5.html)
	[graphics.library/ObtainBestPenA](../Includes_and_Autodocs_3._guide/node0306.html)
	[utility.library/CallHookPkt](../Includes_and_Autodocs_3._guide/node0599.html)
	[graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
	[workbench/icon.h](../Includes_and_Autodocs_3._guide/node0618.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)


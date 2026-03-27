---
title: icon.library/GetIconTagList
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-geticontaglist
functions: [GetDefDiskObject, GetDiskObject, GetDiskObjectNew, IoErr]
libraries: [dos.library, icon.library]
---

# icon.library/GetIconTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetIconTagList -- Retrieve an icon (V44)

   SYNOPSIS
	icon = GetIconTagList(name,tags);
	D0                    A0   A1

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) * GetIconTagList(STRPTR name,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	icon = GetIconTags(name,tag1,...);

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) * GetIconTags(STRPTR name,[Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1,...);

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
	    selected using [IconControlA()](autodocs-3.5/icon-library-iconcontrola.md). If you do not want this to
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
	    will be generated for later use with [DrawIconStateA()](autodocs-3.5/icon-library-drawiconstatea.md).
	    If you do not need these masks, set this tag to FALSE.

	    This tag defaults to TRUE.

	ICONGETA_Screen (struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *) -- Pointer to the screen
	    to remap the icon to; if set to NULL, this keeps the
	    icon from getting remapped in the first place (see
	    ICONGETA_RemapIcon for the consequences).

	    This tag defaults to the default screen to remap to, as
	    preset by [IconControlA()](autodocs-3.5/icon-library-iconcontrola.md).

	ICONGETA_Label (STRPTR) -- The label text to be printed below
	    the icon when it is put to use lateron. This parameter
	    can be useful to figure out the type of the icon to
	    be retrieved by the identification hook. For example,
	    Workbench may label unreadable disk icons as "DF0:????".
	    The identification hook could key on this and supply an
	    appropriate icon for the disk.

	    This tag defaults to NULL.

	ICONA_ErrorCode (LONG *) -- Pointer to a [LONG](autodocs-3.5/include-exec-types-h.md) word variable to
	    store error codes in. Note that this variable will be
	    initialized regardless of whether an error occured or not.
	    Thus, you can check for an error condition by comparing the
	    variable contents against 0; 0 indicates success, all other
	    values are error codes as defined by dos.library.

   RESULT
	icon -- Pointer to a struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) or NULL in case of error.
	    You can use [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to retrieve the error code or use the
	    ICONA_ErrorCode tag instead.

   EXAMPLE

	/* Retrieve the default drawer icon. */
	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon;
	[LONG](autodocs-3.5/include-exec-types-h.md) errorCode;

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
	[LONG](autodocs-3.5/include-exec-types-h.md) isFakeIcon;

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
	This function is a superset of [GetDefDiskObject()](autodocs-3.5/icon-library-getdefdiskobject-2.md), [GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md)
	and [GetDiskObjectNew()](autodocs-3.5/icon-library-getdiskobjectnew-2.md).

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
	[workbench/icon.h](autodocs-3.5/include-workbench-icon-h.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)
	[icon.library/GetDiskObject](autodocs-3.5/icon-library-getdiskobject-2.md)
	[icon.library/GetDiskObjectNew](autodocs-3.5/icon-library-getdiskobjectnew-2.md)
	[icon.library/GetDefDiskObject](autodocs-3.5/icon-library-getdefdiskobject-2.md)
	[icon.library/IconControlA](autodocs-3.5/icon-library-iconcontrola.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)

---

## See Also

- [GetDefDiskObject — icon.library](../autodocs/icon.library.md#getdefdiskobject)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [GetDiskObjectNew — icon.library](../autodocs/icon.library.md#getdiskobjectnew)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

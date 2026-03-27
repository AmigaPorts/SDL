---
title: icon.library/DupDiskObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-dupdiskobjecta
functions: [GetDiskObject, IoErr]
libraries: [dos.library, icon.library]
---

# icon.library/DupDiskObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DupDiskObjectA -- Duplicate an icon (V44)

   SYNOPSIS
	icon = DupDiskObjectA(icon,tags);
	D0                    A0   A1

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) * DupDiskObjectA(struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                                   struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	icon = DupDiskObject(icon,tag1,...);

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) * DupDiskObject(struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                                  [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1,...);

   FUNCTION
	This function is used to create a duplicate of a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md)
	in memory. It can also be used to create an extended
	("native") [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) data structure from an existing,
	traditional format [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) data structure.

   INPUTS
	icon -- Pointer to the icon to be duplicated.
	tags -- Control options.

   TAGS
	ICONDUPA_DuplicateDrawerData (BOOL) -- Duplicate the [DrawerData](autodocs-3.5/include-workbench-workbench-h.md),
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
	    happens if it is retrieved with the [GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md) call rather
	    than the new [GetIconTagList()](autodocs-3.5/icon-library-geticontaglist.md) call), this tag will cause the
	    image data to be analyzed and an attempt to be made to use that
	    image data in the duplicate. The resulting icon will be remapped
	    for display on the default screen, such as the Workbench screen.

	    This tag defaults to FALSE.

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

   NOTES
	Any data you chose not to have duplicated will be set to NULL.
	For example, if you specified "ICONDUPA_DuplicateImages,FALSE",
	then the resulting icon's do_Gadget.GadgetRender and
	do_Gadget.SelectRender will both be NULL.

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[workbench/icon.h](autodocs-3.5/include-workbench-icon-h.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)

---

## See Also

- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)

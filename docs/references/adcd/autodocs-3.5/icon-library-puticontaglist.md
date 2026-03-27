---
title: icon.library/PutIconTagList
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-puticontaglist
functions: [IoErr, PutDefDiskObject, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/PutIconTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PutIconTagList -- Store an icon (V44)

   SYNOPSIS
	success = PutIconTagList(name,icon,tags);
	D0                       A0   A1   A2

	[BOOL](autodocs-3.5/include-exec-types-h.md) PutIconTagList(STRPTR name,struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                    struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = PutIconTags(name,icon,tag1,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) PutIconTags(STRPTR name,struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,

```c
                        [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1,...);
```
   FUNCTION
	This function is used to store an icon; the icon can
	belong to a file/drawer/volume or it can be a default icon.

   INPUTS
	name -- Name of the object the icon is to be stored for,
	    or NULL if a default icon is to be stored.
	icon -- The icon to be stored.
	tags -- Storage options.

   TAGS
	ICONPUTA_NotifyWorkbench (BOOL) -- Set this to TRUE to notify
	    Workbench of the fact that an icon was changed.

	    This tag defaults to FALSE.

	ICONPUTA_PutDefaultType (LONG) -- Type of the default icon
	    this icon is to replace; must be one of WBDISK, WBDRAWER,
	    WBTOOL, WBPROJECT, WBGARBAGE, WBDEVICE or WBKICK.

	    If this tag is used, the "name" parameter will be ignored.

	ICONPUTA_PutDefaultName (STRPTR) -- Name of the default object
	    type this icon is to be stored as.

	    If this tag is used, the "name" parameter will be ignored.

	ICONPUTA_DropPlanarIconImage (BOOL) -- If you decide that the
	    palette mapped icon imagery is sufficient to represent
	    an icon, you can tell icon.library not to store the original,
	    planar icon image data with the icon file. To do this,
	    set this tag to TRUE. Instead of the planar icon images,
	    a single default image will be stored. This can result
	    in space savings but may not look too pretty.

	    This tag defaults to FALSE.

	ICONPUTA_DropChunkyIconImage (BOOL) -- This tag can be used to
	    keep the chunky icon image data from getting written
	    to disk.

	    This tag defaults to FALSE.

	ICONPUTA_DropNewIconToolTypes (BOOL) -- This tag controls whether
	    any NewIcon tool types will be omitted when writing the
	    icon to disk. TRUE will omit the data.

	    This tag defaults to FALSE.

	ICONPUTA_OptimizeImageSpace (BOOL) -- A palette mapped icon
	    image might not use the entire icon palette. By default,
	    icon.library does not bother about this, it expects the
	    creator of the icon to choose its palette efficiently.
	    But just in case, you can tell icon.library to attempt
	    to identify how many colours are really in use and to
	    optimize its image compressor for them. This may take
	    extra time and is not recommended for daily use.

	    This tag defaults to FALSE.

	ICONPUTA_OnlyUpdatePosition (BOOL) -- This tag can be used to
	    reduce the overhead in updating icon information on disk
	    if the only information changed is the icon position.
	    For this case, you can set this tag to TRUE. The icon
	    to be modified will have only its do_CurrentX/do_CurrentY
	    member values changed, the remainer will stay unmodified.
	    Please note that this tag only takes effect if the
	    ICONPUTA_PutDefaultType and ICONPUTA_PutDefaultName tags
	    are omitted.

	    This tag defaults to FALSE.

	ICONPUTA_PreserveOldIconImages (BOOL) -- Before writing a
	    palette mapped icon back to disk, icon.library will make
	    sure that the original planar image data is stored in the
	    file. If you don't want that to happen, set this option to
	    FALSE. This tag will allow you to change the planar icon
	    image data written back to disk.

	    This tag defaults to TRUE.

	ICONA_ErrorCode (LONG *) -- Pointer to a [LONG](autodocs-3.5/include-exec-types-h.md) word variable to
	    store error codes in. Note that this variable will be
	    initialized regardless of whether an error occured or not.
	    Thus, you can check for an error condition by comparing the
	    variable contents against 0; 0 indicates success, all other
	    values are error codes as defined by dos.library.

   RESULT
	success -- TRUE if the icon file could be stored, FALSE otherwise.
	    You can use [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to retrieve the error code or use the
	    ICONA_ErrorCode tag instead.

   EXAMPLE
	/* Store an icon as the default "picture" icon. */
	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon;
	[LONG](autodocs-3.5/include-exec-types-h.md) errorCode;
	[BOOL](autodocs-3.5/include-exec-types-h.md) success;

	success = PutIconTags(NULL,icon,
	    ICONPUTA_PutDefaultName,"picture",
	    ICONA_ErrorCode,&errorCode,
	TAG_DONE);

	if(success == FALSE)
	{
	    Printf("could not store default picture icon;n");
	    PrintFault(errorCode,NULL);
	}

   NOTES
	This function is a superset of [PutDefDiskObject()](autodocs-3.5/icon-library-putdefdiskobject-2.md) and [PutDiskObject()](autodocs-3.5/icon-library-putdiskobject-2.md).

	If the name of the icon file to be stored would be too long to fit
	(as set with IconControl(..., ICONCTRLA_SetGlobalMaxNameLength, ...))
	then PutIconTagList() will silently pretend that the icon file has
	been written to disk. However, it will not store the icon file on the
	disk since there would a risk of accidentally overwriting the file the
	icon belongs to. If you want to know whether the icon you wrote was
	in fact written to disk, provide an error code pointer with the
	ICONA_ErrorCode tag. If the name of the file was too long,
	PutIconTagList() will still pretend that the icon file was written
	successfully, but the error code ERROR_TOO_MANY_LEVELS will be stored
	in the variable you passed in with the ICONA_ErrorCode tag.

   SEE ALSO
	[workbench/icon.h](autodocs-3.5/include-workbench-icon-h.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/PutDefDiskObject](autodocs-3.5/icon-library-putdefdiskobject-2.md)
	[icon.library/PutDiskObject](autodocs-3.5/icon-library-putdiskobject-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutDefDiskObject — icon.library](../autodocs/icon.library.md#putdefdiskobject)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)

---
title: icon.library/LayoutIconA
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-layouticona
functions: [FreeDiskObject]
libraries: [icon.library]
---

# icon.library/LayoutIconA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LayoutIconA -- Adapt a palette-mapped icon for display (V44)

   SYNOPSIS
	success = LayoutIconA(icon,screen,tags);
	D0                    A0   A1     A2

	[BOOL](autodocs-3.5/include-exec-types-h.md) LayoutIconA(struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *screen,
	                 struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = LayoutIcon(icon,screen,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) LayoutIcon(struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *screen,...);

   FUNCTION
	This function will prepare an icon for display, either on a
	specific screen or using a default colour palette. It is
	useful only for palette mapped icons.

   INPUTS
	icon -- The icon to be remapped. This must be a palette mapped
	    icon.
	screen -- Pointer to a screen to remap the icon for or NULL
	    to remap the icon to use the system default colour palette
	    or something very similar to it (this means: four colours
	    only).
	tags -- Additional rendering options.

   TAGS
	OBP_Precision (LONG) -- Pen colour allocation precision.
	    Default is the same precision as set in the global
	    icon.library settings (see [IconControlA()](autodocs-3.5/icon-library-iconcontrola.md)).

   OUTPUTS
	success -- TRUE if the icon could be remapped, FALSE if
	    the remapping failed for some reason. In case of
	    of failure, icon.library will try its best to keep
	    the icon in a presentable state, but this may fail.
	    In case of failure, the error code can be retrieved
	    using [dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md).

   NOTES
	You must make sure that the screen you remap to does not
	go away while there is an icon to use its colours. For
	a public screen, the easiest way to guarantee this is
	to keep it locked (see intuition.library/LockPubScreen).
	For custom screens, just don't close them! If you have to close
	the screen or need to keep your icon around until after a screen
	is closed, you should call LayoutIcon() with a NULL screen
	parameter. This will release all pens the icon has allocated
	and remap the icon to a default set of colours. Alternatively,
	you can dispose of the icon via [FreeDiskObject()](autodocs-3.5/icon-library-freediskobject-2.md) which
	will also release all pens the icon has allocated, including
	the icon itself, of course.

	Icons remapped to the global default screen (normally, that
	would be the Workbench screen) may get changed and remapped
	again during Workbench close/open transitions. To prevent
	this from taking place, just make sure that the Workbench
	screen does not close (e.g. via LockPubScreen("Workbench")).

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[graphics.library/ObtainBestPenA](autodocs-3.5/graphics-library-obtainbestpena.md)
	[graphics.library/ReleasePen](autodocs-3.5/graphics-library-releasepen.md)
	[icon.library/FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	icon.library/IconControl
	[intuition.library/LockPubScreen](autodocs-3.5/intuition-library-lockpubscreen-2.md)
	[intuition.library/UnlockPubScreen](autodocs-3.5/intuition-library-unlockpubscreen-2.md)
	[graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [FreeDiskObject — icon.library](../autodocs/icon.library.md#freediskobject)

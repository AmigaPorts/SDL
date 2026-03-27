# icon.library/LayoutIconA



   NAME
	LayoutIconA -- Adapt a palette-mapped icon for display (V44)

   SYNOPSIS
	success = LayoutIconA(icon,screen,tags);
	D0                    A0   A1     A2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LayoutIconA(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon,struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *screen,
	                 struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	success = LayoutIcon(icon,screen,...);

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LayoutIcon(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon,struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *screen,...);

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
	    icon.library settings (see [IconControlA()](../Includes_and_Autodocs_3._guide/node0351.html)).

   OUTPUTS
	success -- TRUE if the icon could be remapped, FALSE if
	    the remapping failed for some reason. In case of
	    of failure, icon.library will try its best to keep
	    the icon in a presentable state, but this may fail.
	    In case of failure, the error code can be retrieved
	    using [dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html).

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
	you can dispose of the icon via [FreeDiskObject()](../Includes_and_Autodocs_3._guide/node034A.html) which
	will also release all pens the icon has allocated, including
	the icon itself, of course.

	Icons remapped to the global default screen (normally, that
	would be the Workbench screen) may get changed and remapped
	again during Workbench close/open transitions. To prevent
	this from taking place, just make sure that the Workbench
	screen does not close (e.g. via LockPubScreen("Workbench")).

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[graphics.library/ObtainBestPenA](../Includes_and_Autodocs_3._guide/node0306.html)
	[graphics.library/ReleasePen](../Includes_and_Autodocs_3._guide/node0314.html)
	[icon.library/FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	icon.library/IconControl
	[intuition.library/LockPubScreen](../Includes_and_Autodocs_3._guide/node03C1.html)
	[intuition.library/UnlockPubScreen](../Includes_and_Autodocs_3._guide/node03FE.html)
	[graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)


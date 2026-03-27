# intuition.library/AllocScreenBuffer



    NAME
	AllocScreenBuffer -- Get a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) for double-buffering. (V39)

    SYNOPSIS
	sbuffer = AllocScreenBuffer( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45), flags )
	D0                           A0      A1      D0

	struct [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) *AllocScreenBuffer( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *,
	    struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *, ULONG );

    FUNCTION
	Allocates a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure and usually a [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  This
	structure can be used for double (or multiple) buffering in
	Intuition screens.  You may use this call to obtain a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644)
	structure for the screen's initial [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45), or for other BitMaps
	you intend to swap in.

	AllocScreenBuffer() also allocates a graphics.library [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278)
	structure.  The [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure this call returns contains
	a pointer to that [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) structure, which is free for your use.
	See [graphics.library/AllocDBufInfo()](../Includes_and_Autodocs_3._guide/node02A1.html) for full details on using
	this structure to achieve notification of when it is safe to
	render into an old buffer and when it is right to switch again.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to the screen to double-buffer
	[BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) = For CUSTOMBITMAP screens, you may pre-allocate
		a [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) matching the screen's BitMap's properties, and
		pass that in, to get a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) referring to that
		[BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  Set this parameter to NULL if you'd prefer
		that Intuition allocate the alternate buffer.  This parameter
		must be NULL for non-CUSTOMBITMAP screens.
	Flags = Set a combination of these flags:
	    For non-CUSTOMBITMAP screens, set SB_SCREEN_BITMAP in order to
		get a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) referring to the screen's actual [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).
		(For CUSTOMBITMAP screens, just set the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) parameter
		to the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) you passed to [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html)).
	    Set SB_COPY_BITMAP if you would like the screen's [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45)
		copied into this ScreenBuffer's [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  This is required
		to get any menu-bar or gadget imagery into each
		ScreenBuffer's [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  If the screen has no Intuition
		rendering, you may omit this flag.  Also, when allocating
		a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) for the screen's initial [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45), this flag
		should not be set.

    RESULT
	Pointer to a valid [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure, or NULL if failure.
	You may render into the resulting [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) as appropriate.
	You may use the sb_DBufInfo field to access graphics.library
	ViewPort-buffering features such as learning when it is safe
	to reuse the previous [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  If not, you risk writing into
	the on-screen [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45), which can damage menu or gadget rendering!


    NOTES
	The role of SB_SCREEN_BITMAP is to wrap a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) around
	the actual current [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) used by the non-CUSTOMBITMAP screen.
	The words actual or current are used instead of initial, since
	an application could do some double-buffering, leave the
	non-initial buffer installed into the screen, free up the
	others, then re-allocate [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structures to do more
	double-buffering.  In that case, the actual screen [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) is
	not necessarily the initial one.

	The role of SB_COPY_BITMAP is to say "please put whatever
	imagery is currently on-screen into this new [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) too".
	That's how the screen titlebar and other imagery get copied
	over into each buffer.

    BUGS

    SEE ALSO
	[FreeScreenBuffer()](../Includes_and_Autodocs_3._guide/node03B1.html), [ChangeScreenBuffer()](../Includes_and_Autodocs_3._guide/node039A.html),
	[graphics.library/AllocDBufInfo()](../Includes_and_Autodocs_3._guide/node02A1.html), [graphics.library/ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)


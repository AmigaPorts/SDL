---
title: graphics.library/VideoControl
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-videocontrol-2
functions: [ChangeVPBitMap, FreeColorMap, GetColorMap, GetVPModeID, LoadRGB4, MakeVPort, ScrollVPort, SetRGB4, VideoControl]
libraries: [graphics.library]
---

# graphics.library/VideoControl

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	VideoControl -- Modify the operation of a ViewPort's [ColorMap](autodocs-3.5/include-graphics-view-h.md) (V36)
	VideoControlTags -- varargs stub for VideoControl (V36)
   SYNOPSIS
	error = VideoControl( cm , tags )
	d0                    a0   a1

	ULONG VideoControl( struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	error= VideoControlTags(cm, tags,...);


   FUNCTION
	[Process](autodocs-3.5/include-dos-dosextens-h.md) the commands in the VideoControl command [TagItem](autodocs-3.5/include-utility-tagitem-h.md) buffer
	using cm as the target, with respect to its "attached" [ViewPort](autodocs-3.5/include-graphics-view-h.md).

	viewport commands:

	VTAG_ATTACH_CM     [_SET        | _GET] -- set/get attached viewport
	VTAG_VIEWPORTEXTRA [_SET        | _GET] -- set/get attached vp_extra
	VTAG_NORMAL_DISP   [_SET        | _GET] -- set/get [DisplayInfoHandle](autodocs-3.5/include-graphics-displayinfo-h.md)
	                                           (natural mode)
	VTAG_COERCE_DISP   [_SET        | _GET] -- set/get [DisplayInfoHandle](autodocs-3.5/include-graphics-displayinfo-h.md)
	                                           (coerced mode)
	VTAG_PF1_BASE      [_SET        | _GET] -- set/get color base for
	                                           first playfield. (V39)
	VTAG_PF2_BASE      [_SET        | _GET] -- set/get color base for
	                                           second playfield. (V39)
	VTAG_SPODD_BASE    [_SET        | _GET] -- set/get color base for odd
	                                           sprites. (V39)
	VTAG_SPEVEN_BASE   [_SET        | _GET] -- set/get color base for even
	                                           sprites. (V39)
	VTAG_BORDERSPRITE  [_SET        | _GET] -- on/off/inquire sprites in
	                                           borders. (V39)
	VTAG_SPRITERESN    [_SET        | _GET] -- set/get sprite resolution
	              (legal values are SPRITERESN_ECS/_140NS/_70NS/_35NS.
	               see [graphics/view.h)](autodocs-3.5/include-graphics-view-h.md) (V39)
	VTAG_PF1_TO_SPRITEPRI [_SET     | _GET] -- set/get playfield1 priority
```c
                                                  with respect to sprites (V3
```
9)
	VTAG_PF2_TO_SPRITEPRI [_SET     | _GET] -- set/get playfield2 priority
```c
                                                  with respect to sprites (V3
```
9)
	(These two require that the [ColorMap](autodocs-3.5/include-graphics-view-h.md) is attached to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) to be
	 effective).

	genlock commands:

	VTAG_BORDERBLANK   [_SET | _CLR | _GET] -- on/off/inquire blanking
	VTAG_BORDERNOTRANS [_SET | _CLR | _GET] -- on/off/inquire notransparency
	VTAG_CHROMAKEY     [_SET | _CLR | _GET] -- on/off/inquire chroma mode
	VTAG_BITPLANEKEY   [_SET | _CLR | _GET] -- on/off/inquire bitplane mode
	VTAG_CHROMA_PEN    [_SET | _CLR | _GET] -- set/clr/get chromakey pen #
	VTAG_CHROMA_PLANE  [_SET |      | _GET] -- set/get bitplanekey plane #

	control commands:

	VTAG_IMMEDIATE	- normally, VideoControl changes do not occur until the
	        next [MakeVPort](autodocs-3.5/graphics-library-makevport-2.md). Using this tag, some changes can be made to
	        happen immediately. The tag data is a pointer to a longword
	        flag variable which will be cleared if all changes happened
	        immediately. See the example. (V39)

	VTAG_FULLPALETTE   [_SET | _CLR | _GET] -- enable/disable loading of all
	        colors in the copper list.
	        Normally, graphics will only load the color which are necessary
	        for the viewport, based upon the screen depth and mode. In order
	        to use the color palette banking features, you may need to use
	        this tag to tell graphics to load ALL colors, regardless of
	        screen depth. (V39)

	VC_IntermediateCLUpdate
	VC_IntermediateCLUpdate_Query
	         When set, graphics will update the intermediate copper
		 lists on colour changes. When FALSE, graphics won't update
	         the intermediate copperlists, so [ScrollVPort()](autodocs-3.5/graphics-library-scrollvport-2.md),
	         [ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md) and colour loading functions will be faster.
	         This value is TRUE by default. (V40)

	VC_NoColorPaletteLoad
	VC_NoColorPaletteLoad_Query
	         When set, only colour 0 will be loaded for this [ViewPort](autodocs-3.5/include-graphics-view-h.md),
	         hence the inter-ViewPort gap will be smaller. The colours for
	         this [ViewPort](autodocs-3.5/include-graphics-view-h.md) are inherited from the next higher [ViewPort](autodocs-3.5/include-graphics-view-h.md). The
		 results are undefined if this is the first or only [ViewPort](autodocs-3.5/include-graphics-view-h.md) in
	         the display, and undefined when used in conjunction with
	         VTAG_FULLPALETTE (!?!).
	         This value is FALSE by default. (V40)

	VC_DUALPF_Disable
	VC_DUALPF_Disable_Query
		When set, disables the setting of the dual-playfield
		bit in bplcon0. When used with a dual-playfield mode
		screen, this allows using separate scroll and bitmaps
		for the odd and even bitplanes, without going through
		the normal dual-playfield priority and palette selection.
		With appropriate palette setup, this can be used for
		transparency effects, etc.

	copper commands

	VTAG_USERCLIP      [_SET | _CLR | _GET] -- on/off/inquire clipping of
	                                           UserCopperList at bottom
	                                           edge of ColorMap->cm_vp
	                                           (defaults to off)

	buffer commands:

	VTAG_NEXTBUF_CM                         -- link to more VTAG commands
	VTAG_END_CM                             -- terminate command buffer

	batch mode commands:

	(if you want your videocontrol taglist to be processed in "batch"
	 mode, that is, at the next [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) for the ColorMap->cm_vp;
	 you may install a static list of videocontrol TagItems into the
	 [ColorMap](autodocs-3.5/include-graphics-view-h.md) with the BATCH_ITEMS_SET command; and then enable/disable
	 batch mode processing of those items via the BATCH_CM control
	 command)

	VTAG_BATCH_CM      [_SET | _CLR | _GET] -- on/off/inquire batch mode
	VTAG_BATCH_ITEMS   [_SET | _ADD | _GET] -- set/add/get batched TagLists

	private commands (used internally by intuition -- do not call):

	VTAG_VPMODEID      [_SET | _CLR | _GET] -- force [GetVPModeID()](autodocs-3.5/graphics-library-getvpmodeid-2.md) return


   INPUTS
	cm   = pointer to struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) obtained via [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md).
	tags = pointer to a table of videocontrol tagitems.

   RESULT
	error = NULL if no error occurred in the control operation.
	(non-NULL if bad colormap pointer, no tagitems or bad tag)

	The operating characteristics of the [ColorMap](autodocs-3.5/include-graphics-view-h.md) and its attached
	[ViewPort](autodocs-3.5/include-graphics-view-h.md) are modified. The result will be incorporated into the
	[ViewPort](autodocs-3.5/include-graphics-view-h.md) when its copper lists are reassembled via [MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md).

	Note that you must NOT change colors in the viewport (via [SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md),
	[LoadRGB4()](autodocs-3.5/graphics-library-loadrgb4-2.md), [SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md), etc.) after changing any of the color palette
	offsets (VTAG_PF1_BASE, etc), without first remaking the [ViewPort](autodocs-3.5/include-graphics-view-h.md).

   NOTES
	Sprite resolutions is controlled by two sets of tags, SPRITERESN
	and DEFSPRITERESN. If you don't set the sprite resolution, it will
	follow the intuition-controlled "default" sprite resolution. Setting
	the sprite resolution to one of the SPRITERESN_ values will allow the
	application to override intuition's control of it.

	This function will modify the contents of the TagList you pass to it by
	changing _GET tags to the corresponding _SET or _CLR tag. The
	exceptions to this rule are documented as such above (such as
	VTAG_IMMEDIATE).

	The new tags added for V40 have the prefix VC_ instead of VTAG_. These
	tags work in the same manner as all other tags in the system, and will
	not be modified by VideoControl().

   EXAMPLE
	must_remake=-1;
	error=VideoControl(myvp->ColorMap,VTAG_BORDERBLANK_SET,-1,
	                   (GFXBase->lib_Version>=39)?VTAG_IMMEDIATE:TAG_IGNORE,
						&must_remake);
	if (must_remake) { MakeVPort(myview,myvp); MrgCop(myview); }

   EXAMPLE
	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) VCTags[] =
	{
	    {VTAG_BORDERBLANK_GET, NULL},
	    {VTAG_SPRITERESN_SET, SPRITERESN_35NS},
	    {TAG_DONE, NULL},
	};
	[BOOL](autodocs-3.5/include-exec-types-h.md) bblank = FALSE;

	if (VideoControl(cm, VCTags) == NULL)
	{
	    bblank = (VCTags[0].ti_Tag == VTAG_BORDERBLANK_SET);
	}

   EXAMPLE
	struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) VCTags[] =
	{
	    {VC_NoColorPaletteLoad_Query, NULL},
	    {TAG_DONE},
	};
	ULONG query;

	VCTags[0].ti_Data = (ULONG)&query;
	if (VideoControl(cm, VCTags) == NULL)
	{
	    printf("Palette loading is %sn", (query ? "off" : "on"));
	}

   BUGS

   SEE ALSO
	[graphics/videocontrol.h](autodocs-3.5/include-graphics-videocontrol-h.md), [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md), [FreeColorMap()](autodocs-3.5/graphics-library-freecolormap-2.md)

---

## See Also

- [ChangeVPBitMap — graphics.library](../autodocs/graphics.library.md#changevpbitmap)
- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [ScrollVPort — graphics.library](../autodocs/graphics.library.md#scrollvport)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)

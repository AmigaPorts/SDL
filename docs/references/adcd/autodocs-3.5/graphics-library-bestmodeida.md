---
title: graphics.library/BestModeIDA
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-bestmodeida
functions: [BestModeIDA]
libraries: [graphics.library]
---

# graphics.library/BestModeIDA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	BestModeIDA -- calculate the best ModeID with given parameters (V39)
	BestModeID  -- varargs stub for BestModeIDA()

   SYNOPSIS
	ID = BestModeIDA(TagItems)
	d0               a0

	ULONG BestModeIDA(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	ID = BestModeID(Tag1, ...)

	ULONG BestModeID(ULONG, ...);

   FUNCTION
	To determine the best ModeID to fit the parameters set in the TagList.

   INPUTS
	TagItems - A pointer to an array of TagItems.

   TAGS
	BIDTAG_DIPFMustHave (ULONG) - Mask of DIPF_ flags
	       (from DisplayInfo->PropertyFlags) that the returned ModeID
	       must have.
	       Default - NULL

	BIDTAG_DIPFMustNotHave (ULONG) - Mask of DIPF_ flags that the
	       returned ModeID must not have.
	       Default - SPECIAL_FLAGS

	BIDTAG_ViewPort (struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *) - [ViewPort](autodocs-3.5/include-graphics-view-h.md) for which a best-fit
	       ModeID is sought.
	       Default - NULL

	BIDTAG_NominalWidth (UWORD),
	BIDTAG_NominalHeight (UWORD) - together make the aspect ratio.
	       These values override the vp->DWidth and vp->DHeight values
	       in the given [ViewPort](autodocs-3.5/include-graphics-view-h.md).
	       Default - SourceID NominalDimensionInfo if BIDTAG_SourceID is
	       passed, or vp->DWidth and vp->DHeight if BIDTAG_ViewPort is
	       passed, or 640 x 200.

	BIDTAG_DesiredWidth (UWORD),
	BIDTAG_DesiredHeight (UWORD) - Used to distinguish between two
	       mode IDs with identical aspect ratios.
	       Default - same values as NominalWidth and NominalHeight.

	BIDTAG_Depth (UBYTE) - minimum the returned ModeID must support.
	       Default - vp->RasInfo->BitMap->Depth if BIDTAG_ViewPort is
	       passed, else 1.

	BIDTAG_MonitorID (ULONG) - returned ModeID must use this monitor.
	       Default - will not restrict the search to any particular monitor

	BIDTAG_SourceID (ULONG) - Use this ModeID instead of a [ViewPort](autodocs-3.5/include-graphics-view-h.md).
	       If specified, the DIPFMustHave mask is made up of the
	       ((DisplayInfo->PropertyFlags of this ID & SPECIAL_FLAGS) |
	        DIPFMustHave flags).
	       Default - VPModeID(vp) if BIDTAG_ViewPort was passed, else the
	       DIPFMustHave and DIPFMustNotHave masks are left unchanged.

	BIDTAG_RedBits (UBYTE),
	BIDTAG_BlueBits (UBYTE),
	BIDTAG_Greenits (UBYTE) - Minimum bits per gun the resultant
	       ModeID must support.
	       Default - 4 bits per gun.

   RESULTS
	ID      - ID of the best mode to use, or INVALID_ID if a match could
	          not be found.

   NOTES
	This function takes into account the Compatability of the Monitor
	being matched to, and the source [ViewPort](autodocs-3.5/include-graphics-view-h.md) or ModeID.
	Incompatibilitys will cause a result of INVALID_ID.

	BIDTAG_NominalWidth, BIDTAG_NominalHeight,
	BIDTAG_DesiredWidth, BIDTAG_DesiredHeight, must all be non-0.

	The comparisons are made against the DimensionInfo->Nominal values.
	ie, this will not return a best fit against overscan dimensions.

   EXAMPLE
	IFF Display Program with a HAM image, to be displayed in the same
	monitor type as the Workbench [ViewPort](autodocs-3.5/include-graphics-view-h.md).

	ID = BestModeID(BIDTAG_NominalWidth, IFFImage->Width,
	                BIDTAG_NominalHeight, IFFImage->Height,
	                BIDTAG_Depth, IFFImage->Depth,
	                BIDTAG_DIPFMustHave, DIPF_IS_HAM,
	                BIDTAG_MonitorID, (GetVPModeID(WbVP) & MONITOR_ID_MASK),
	                TAG_END);

	To make an interlace version of a ViewPort:

	ID = BestModeID(BIDTAG_ViewPort, ThisViewPort,
	                BIDTAG_MustHave, DIFP_IS_LACE,
	                TAG_END);

   SEE ALSO
	[<graphics/modeid.h>](autodocs-3.5/include-graphics-modeid-h.md) [<graphics/displayinfo.h>](autodocs-3.5/include-graphics-displayinfo-h.md)

---

## See Also

- [BestModeIDA — graphics.library](../autodocs/graphics.library.md#bestmodeida)

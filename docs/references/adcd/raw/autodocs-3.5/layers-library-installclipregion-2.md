# layers.library/InstallClipRegion



    NAME
	InstallClipRegion -- Install clip region in layer

    SYNOPSIS
	oldclipregion = InstallClipRegion( l,  region )
	d0                                 a0  a1

	struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *InstallClipRegion( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *, struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *);

    FUNCTION
	Installs a transparent Clip region in the layer. All
	subsequent graphics calls will be clipped to this region.
	You MUST remember to call InstallClipRegion(l,NULL) before
	calling DeleteLayer(l) or the Intuition function [CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)
 	if you have installed a non-NULL ClipRegion in l.

    INPUTS
	l - pointer to a layer
	region - pointer to a region

    RESULTS
	oldclipregion - The pointer to the previous ClipRegion that
	    was installed. Returns NULL if no previous ClipRegion installed.

	    Note: If the system runs out of memory while computing the
	        resulting ClipRects the LAYERS_CLIPRECTS_LOST bit will
	        be set in l->Flags.

    BUGS
	If the system runs out of memory during normal layer operations,
	the [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) list may get swept away and not restored.
	As soon as there is enough memory and the layer library
	gets called again the [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) list will be rebuilt.

    SEE ALSO
	[BeginUpdate()](../Includes_and_Autodocs_3._guide/node0418.html) [EndUpdate()](../Includes_and_Autodocs_3._guide/node0421.html),
	[graphics/layers.h](../Includes_and_Autodocs_3._guide/node0625.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html), [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)


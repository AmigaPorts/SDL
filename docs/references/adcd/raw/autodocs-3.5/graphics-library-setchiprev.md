# graphics.library/SetChipRev



   NAME
	SetChipRev -- turns on the features of a Chip Set  (V39)

   SYNOPSIS
	chiprevbits = SetChipRev(ChipRev)
	                           d0

	ULONG SetChipRev(ULONG);

   FUNCTION
	Enables the features of the requested Chip Set if available,
	and updates the graphics database accordingly.

   INPUTS
	ChipRev - Chip Rev that you would like to be enabled.

   RESULT
	chiprevbits - Actual bits set in GfxBase->ChipRevBits0.

   NOTES
	This routine should only be called once. It will be called by the system
	in the startup-sequence, but is included in the autodocs for authors
	of bootblock-games that wish to take advantage of post-ECS features.

   SEE ALSO
	[<graphics/gfxbase.h>](../Includes_and_Autodocs_3._guide/node0612.html)


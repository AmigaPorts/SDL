# card.resource/GetCardMap



   NAME
	GetCardMap -- Obtain pointer to [CardMemoryMap](../Includes_and_Autodocs_3._guide/node05E2.html#line44) structure

   SYNOPSIS
	pointer=GetCardMap()
	d0

	struct [CardMemoryMap](../Includes_and_Autodocs_3._guide/node05E2.html#line44) *GetCardMap( void );

   FUNCTION
	Obtain pointer to a [CardMemoryMap](../Includes_and_Autodocs_3._guide/node05E2.html#line44) structure.  The structure
	is READ only.

	Devices should never assume credit-card memory appears
	at any particular place in memory.  By using this function
	to obtain pointers to the base memory locations of the various
	credit-card memory types, your device will continue to work
	properly should credit cards appear in different memory
	locations in future hardware.

   RETURNS
	Pointer to [CardMemoryMap](../Includes_and_Autodocs_3._guide/node05E2.html#line44) structure -

		struct [CardMemoryMap](../Includes_and_Autodocs_3._guide/node05E2.html#line44) {
		[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*cmm_CommonMemory;
		[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*cmm_AttributeMemory;
		[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*cmm_IOMemory;
		};

	As of card.resource V39, this structure has been extended to
	include the size of these memory regions.  See card.h/card.i
	for the new fields.  If card.resource V39, use the constants
	in the [CardMemoryMap](../Includes_and_Autodocs_3._guide/node05E2.html#line44) structure rather than hard coded constants
	for memory region size.

   NOTES
	If any pointer in the structure is NULL, it means this type
	of credit-card memory is not being made available.

   SEE ALSO
	[resources/card.h](../Includes_and_Autodocs_3._guide/node05E2.html), resources/card.i


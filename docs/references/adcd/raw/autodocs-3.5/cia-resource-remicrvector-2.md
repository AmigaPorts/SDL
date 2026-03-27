# cia.resource/RemICRVector



   NAME
	RemICRVector -- Detach an interrupt handler from a [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) bit.

   SYNOPSIS
	RemICRVector( Resource, iCRBit, interrupt )
	              A6        D0      A1

	void RemICRVector( struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *, WORD, struct [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) *);

   FUNCTION
	Disconnect interrupt processing code for a particular
	interrupt bit of the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) ICR.

	This function will also disable the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) interrupt for the
	given ICR bit.

   INPUTS
	iCRBit          Bit number to set (0..4).
	interrupt       Pointer to interrupt structure.

   RESULT

   NOTE
	The [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resources are special in that there is more than one
	of them in the system. Because of this, the C language stubs
	in amiga.lib for the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resources require an extra parameter
	to specify which [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resource to use. The synopsis for the
	amiga.lib stubs is as follows:

	RemICRVector( Resource, iCRBit, interrupt )
	              A6        D0      A1

	void RemICRVector( struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *, WORD, struct [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) *);

   SEE ALSO
	[cia.resource/AddICRVector()](../Includes_and_Autodocs_3._guide/node00C9.html)


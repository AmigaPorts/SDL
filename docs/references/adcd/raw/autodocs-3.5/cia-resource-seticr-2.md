# cia.resource/SetICR



   NAME
	SetICR -- [Cause](../Includes_and_Autodocs_3._guide/node01F4.html), clear, and sample ICR interrupts.

   SYNOPSIS
	oldMask = SetICR( Resource, mask )
	D0                A6        D0

	WORD SetICR( struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *, WORD );

   FUNCTION
	This function provides a means of reseting, causing, and
	sampling 8520 [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) interrupt control registers.

   INPUTS
	mask            A bit mask indicating which interrupts to be
	                    effected. If bit 7 is clear the mask
	                    indicates interrupts to be reset.  If bit
	                    7 is set, the mask indicates interrupts to
	                    be caused. Bit positions are identical to
	                    those in 8520 ICR.

   RESULTS
	oldMask         The previous interrupt register status before
	                    making the requested changes.  To sample
	                    current status without making changes,
	                    call the function with a null parameter.

   EXAMPLES
	Get the interrupt mask:
	    mask = SetICR(0)
	Clear serial port interrupt:
	    SetICR(0x08)

   NOTE
	The [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resources are special in that there is more than one
	of them in the system. Because of this, the C language stubs
	in amiga.lib for the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resources require an extra parameter
	to specify which [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resource to use. The synopsis for the
	amiga.lib stubs is as follows:

	oldMask = SetICR( Resource, mask )
	D0                A6        D0

	WORD SetICR( struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *, WORD );

	***WARNING***

	Never read the contents of the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) interrupt control registers
	directly.  Reading the contents of one of the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) interrupt
	control registers clears the register.  This can result in
	interrupts being missed by critical operating system code, and
	other applications.

   EXCEPTIONS
	Setting an interrupt bit for an enabled interrupt will cause
	an immediate interrupt.

   SEE ALSO
	[cia.resource/AbleICR()](../Includes_and_Autodocs_3._guide/node00C8.html)


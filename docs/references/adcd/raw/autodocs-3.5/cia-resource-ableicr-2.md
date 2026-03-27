# cia.resource/AbleICR



   NAME
	AbleICR -- Enable/disable ICR interrupts.

   SYNOPSIS
	oldMask = AbleICR( Resource, mask )
	D0                 A6        D0

	WORD AbleICR( struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *, WORD );

   FUNCTION
	This function provides a means of enabling and disabling 8520
	[CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) interrupt control registers. In addition it returns the
	previous enable mask.

   INPUTS
	mask            A bit mask indicating which interrupts to be
	                    modified. If bit 7 is clear the mask
	                    indicates interrupts to be disabled. If
	                    bit 7 is set, the mask indicates
	                    interrupts to be enabled. Bit positions
	                    are identical to those in 8520 ICR.

   RESULTS
	oldMask         The previous enable mask before the requested
	                    changes. To get the current mask without
	                    making changes, call the function with a
	                    null parameter.

   EXAMPLES
	Get the current mask:
	    mask = AbleICR(0)
	[Enable](../Includes_and_Autodocs_3._guide/node0205.html) both timer interrupts:
	    AbleICR(0x83)
	[Disable](../Includes_and_Autodocs_3._guide/node0203.html) serial port interrupt:
	    AbleICR(0x08)

   EXCEPTIONS
	Enabling the mask for a pending interrupt will cause an
	immediate processor interrupt (that is if everything else is
	enabled). You may want to clear the pending interrupts with
	[SetICR()](../Includes_and_Autodocs_3._guide/node00CB.html) prior to enabling them.

   NOTE
	The [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resources are special in that there is more than one
	of them in the system. Because of this, the C language stubs
	in amiga.lib for the [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resources require an extra parameter
	to specify which [CIA](../Includes_and_Autodocs_3._guide/node05E5.html#line28) resource to use. The synopsis for the
	amiga.lib stubs is as follows:

	oldMask = AbleICR( Resource, mask )
	D0                 A6        D0

	WORD AbleICR( struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *, WORD );

   SEE ALSO
	[cia.resource/SetICR()](../Includes_and_Autodocs_3._guide/node00CB.html)


# card.resource/CardMiscControl



   NAME
	CardMiscControl -- Set/Clear miscellaneous control bits

   SYNOPSIS
	control_bits=CardMiscControl( handle, control_bits );
	d0			 	a1      	d1

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) CardMiscControl( struct [CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

   FUNCTION
	Used to set/clear miscellaneous control bits (generally for
	use with I/O cards).

   INPUTS
	handle - Same handle as that used when [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) was called.

	control_bits - A mask value of control bits to be turned on/off.

	The bit values which might be usable are defined in card.h/i.

	For example, to enable digital audio, and disable hardware
	write-protect (if supported), you would call this function with these
	values --

	CARDF_DISABLE_WP|CARDF_ENABLE_DIGAUDIO

	Then to turn off digital audio, but leave write-protect
	disable, you would use a value of --

	CARDF_DISABLE_WP

	Finally too reenable write protect, call this function with
	a mask value of 0.

   RETURNS
	control_bits - The same mask value you called this function
	with if successful.  If one, or more bits has been cleared
	in the return mask, this would indicate that the control bit
	is not being supported, or that the card has been removed
	by the user.

	For example, if you called this function with a mask value
	of --

	CARDF_DISABLE_WP|CARDF_ENABLE_DIGAUDIO

	And this function returned a value of --

	CARDF_DISABLE_WP

	This would indicate that it is not possible to enable digital
	audio (most likely because this feature has not been implemented).

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

	!!!IMPORTANT!!!

	You should ALWAYS try to enable digital audio for I/O cards
	as this will also configure the card socket for the I/O
	interface (if supported).

	Not all cards will connect the write-enable line (e.g.,
	some I/O cards).  On some machines (e.g., the A600) it will
	not be possible to write to such cards unless you disable
	write-protection by using this function.

	!!!NEW!!!

	For card.resource V39 (check resource base for VERSION before
	using), new bits have been defined which let you enable/disable
	particular status change interrupts.  See [CardInterface()](../Includes_and_Autodocs_3._guide/node0093.html) for
	defaults.  These new bits are backwards compatable with V37
	for which only the CARDB_DISABLE_WP, and CARDB_ENABLE_DIGAUDIO
	bits were defined.  These new bits allow you to enable, or
	disable specific status change interrupts including BVD1/SC,
	BVD2/DA, and BSY/IRQ.  The defaults for these status change
	interrupts are unchanged from V37, and WR (Write-protect) status
	change interrupts are always enabled as they use to be.

	An example of use:

	CARD_INTF_SETCLR!CARD_INTF_BVD1

	Would enable BVD1/SC status change interrupts, and not change
	the enable/disable state for BVD2/DA or BSY/IRQ status change
	interrupts.  If the change was made successfully, the
	CARD_INTB_BVD1 bit would be set in register D0 when this function
	returns.

   SEE ALSO
	[CardInterface()](../Includes_and_Autodocs_3._guide/node0093.html), [resources/card.h](../Includes_and_Autodocs_3._guide/node05E2.html), resources/card.i


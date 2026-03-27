# card.resource/CardResetRemove



   NAME
	CardResetRemove -- Set/Clear reset on card removal.

   SYNOPSIS
	success=CardResetRemove( handle, flag );
				 a1      d0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CardResetRemove( struct [CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) *, ULONG );

   FUNCTION
	Used to set/clear HARDWARE [RESET](../Includes_and_Autodocs_3._guide/node0253.html) on card change detect.

	This function should generally not be used by devices
	which support HOT-REMOVAL.  HARDWARE [RESET](../Includes_and_Autodocs_3._guide/node0253.html) on removal
	is generally intended for execute-in-place software, or
	ram cards whose memory has been added as system ram.

   INPUTS
	handle - Same handle as that used when [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) was called.

	flag - TRUE if you want to SET HARDWARE [RESET](../Includes_and_Autodocs_3._guide/node0253.html) on credit
	       card removal.  FALSE if you want to CLEAR HARDWARE
	       [RESET](../Includes_and_Autodocs_3._guide/node0253.html).

   RETURNS
	1  - Success.

	0  - Function failed (most likely because the card was removed
	     by the user, and you are no longer the owner of the card).

	-1 - This function is not being made available.

   NOTES
	This function should only be called from a task.

   SEE ALSO
	[OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html)


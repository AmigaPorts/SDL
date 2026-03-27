# potgo.resource/FreePotBits



   NAME
	FreePotBits -- Free allocated bits in the potgo register.

   SYNOPSIS
	FreePotBits(allocated)
	            D0

	void FreePotBits( [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

   FUNCTION
	The FreePotBits routine frees previously allocated bits in the
	hardware potgo register that the application had allocated via
	[AllocPotBits](../Includes_and_Autodocs_3._guide/node04FF.html) and no longer wishes to use.  It accepts the
	return value from [AllocPotBits](../Includes_and_Autodocs_3._guide/node04FF.html) as its argument.


# potgo.resource/WritePotgo



   NAME
	WritePotgo -- [Write](../Includes_and_Autodocs_3._guide/node01D1.html) to the hardware potgo register.

   SYNOPSIS
	WritePotgo(word, mask)
	           D0    D1

	void WritePotgo( [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

   FUNCTION
	The WritePotgo routine sets and clears bits in the hardware
	potgo register.  Only those bits specified by the mask are
	affected -- it is improper to set bits in the mask that you
	have not successfully allocated.  The bits in the high byte
	are saved to be maintained when other users write to the
	potgo register.  The START bit is not saved, it is written
	only explicitly as the result of a call to this routine with
	the START bit set: other users will not restart it.

   INPUTS
	word - the data to write to the hardware potgo register and
	    save for further use, except the START bit, which is
	    not saved.
	mask - those bits in word that are to be written.  Other
	    bits may have been provided by previous calls to
	    this routine, and default to zero.


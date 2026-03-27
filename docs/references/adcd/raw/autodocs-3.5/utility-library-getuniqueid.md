# utility.library/GetUniqueID



   NAME
	GetUniqueID -- return a relatively unique number. (V39)

   SYNOPSIS
	id = GetUniqueID();
	D0

	ULONG GetUniqueID(VOID);

   FUNCTION
	Returns a unique value each time it is called. This is useful for
	things that need unique ID such as the GadgetHelp ID, etc.
	Note that this is only unique for 4,294,967,295 calls to this
	function. Under normal use this is not a problem.
	This function is safe in interrupts.

   RESULT
	id - a 32-bit value that is unique.


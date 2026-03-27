# dos.library/CheckSignal



   NAME
	CheckSignal -- Checks for break signals (V36)

   SYNOPSIS
	signals = CheckSignal(mask)
	D0		      D1

	ULONG CheckSignal(ULONG)

   FUNCTION
	This function checks to see if any signals specified in the mask have
	been set and if so, returns them.  Otherwise it returns FALSE.
	All signals specified in mask will be cleared.

   INPUTS
	mask    - Signals to check for.

   RESULT
	signals - Signals specified in mask that were set.

   SEE ALSO


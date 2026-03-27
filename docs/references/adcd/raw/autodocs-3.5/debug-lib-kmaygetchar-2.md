# debug.lib/KMayGetChar



   NAME
	KMayGetChar - return a character if present, but don't wait
		      (defaults to the serial port at 9600 baud)

   SYNOPSIS
	flagChar = KMayGetChar()
	D0

   FUNCTION
	return either a -1, saying that there is no character present, or
	whatever character was waiting.  KMayGetChar is the assembly
	interface,  _KMayGetChar is the C interface.


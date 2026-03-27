# debug.lib/KCmpStr



   NAME
	KCmpStr - compare two null terminated strings

   SYNOPSIS
	mismatch = KCmpStr(string1, string2)
	D0         A0        A1

   FUNCTION
	string1 is compared to string2 using the ASCII collating
	sequence.  0 indicates the strings are identical.


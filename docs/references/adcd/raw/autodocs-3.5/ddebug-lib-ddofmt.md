# ddebug.lib/DDoFmt



   NAME
	DDoFmt -- format data into a character stream.

   SYNOPSIS
	DDoFmt(FormatString, DataStream, PutChProc, PutChData);
	      A0	    A1		A2	   A3

   FUNCTION
	perform "C"-language-like formatting of a data stream,
	outputting the result a character at a time

   INPUTS
	[FormatString](../Includes_and_Autodocs_3._guide/node0457.html) - a "C"-language-like null terminated format
		string, with the following supported % types:
	DataStream - a stream of data that is interpreted according to
		the format string.
	PutChProc - the procedure to call with each character to be
		output, called as:
	    PutChProc(Char,  PutChData);
		      D0-0:8 A3
		the procedure is called with a null Char at the end of
		the format string.
	PutChData - an address register that passes thru to PutChProc.


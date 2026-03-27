# graphics.library/QBlit



   NAME

	QBlit -- Queue up a request for blitter usage

   SYNOPSIS
	QBlit( bp )
	       a1

	void QBlit( struct [bltnode](../Includes_and_Autodocs_3._guide/node05DF.html#line87) * );

   FUNCTION
	Link a request for the use of the blitter to the end of the

       current blitter queue.  The pointer bp points to a blit structure
       containing, among other things, the link information, and the
       address of your routine which is to be called when the blitter
       queue finally gets around to this specific request.  When your
       routine is called, you are in control of the blitter ... it is
       not busy with anyone else's requests.  This means that you can
       directly specify the register contents and start the blitter.
       See the description of the blit structure and the uses of QBlit
       in the section titled Graphics Support in the OS Kernel Manual.
       Your code must be written to run either in supervisor or user
       mode on the 68000.
   INPUTS
	bp - pointer to a blit structure

   RESULT
	Your routine is called when the blitter is ready for you.
	In general requests for blitter usage through this channel are
	put in front of those who use the blitter via [OwnBlitter](../Includes_and_Autodocs_3._guide/node030C.html) and
	[DisownBlitter](../Includes_and_Autodocs_3._guide/node02CA.html). However for small blits there is more overhead
	using the queuer than Own/Disown Blitter.

   NOTES
	Code which uses QBlit(), or [QBSBlit()](../Includes_and_Autodocs_3._guide/node030F.html) should make use of
	the pointer to a cleanup routine in the [bltnode](../Includes_and_Autodocs_3._guide/node05DF.html#line87) structure.
	The cleanup routine may be called on the context of an
	interrupt, therefore the routine may set a flag, and signal
	a task, but it may not call [FreeMem()](../Includes_and_Autodocs_3._guide/node020E.html) directly.  Use of
	the cleanup routine is the only safe way to signal that
	your [bltnode](../Includes_and_Autodocs_3._guide/node05DF.html#line87) has completed.

   BUGS
	QBlit(), and [QBSBlit()](../Includes_and_Autodocs_3._guide/node030F.html) have been rewritten for V39 due to
	various long standing bugs in earlier versions of this code.

   SEE ALSO
	[QBSBlit()](../Includes_and_Autodocs_3._guide/node030F.html) [hardware/blit.h](../Includes_and_Autodocs_3._guide/node05DF.html)


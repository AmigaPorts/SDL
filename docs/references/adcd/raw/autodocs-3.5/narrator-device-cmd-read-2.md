# narrator.device/CMD_READ



   NAME
	CMD_READ - Query the narrator device for mouth shape or other
		   synchronization events.


   SYNOPSIS
	Standard device command.


   FUNCTION
	Currently, there are three events which the user can inquire
	about from the narrator device.  These are: mouth shape changes,
	start of word, and start of syllable.  Each read request returns
	information about any or all of these events as determined by
	the bits set in the sync field of the read [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block.  In
	the case of mouth shape changes, each shape returned is guaranteed
	to be different from the previously returned shape to allow
	updating to be done only when necessary.  Each read request is
	associated with a write request	by information contained in the
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block used to open the device.  Since the first field
	in the read [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block is a write [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) structure, this
	association is easily made by copying the write [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block
	(after the [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) call) into the voice field of the read
	[IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block.  If there is no write in progress or in the
	device input queue with the same pseudo unit number as the read
	request, the read will be returned to the user with an error.  This
	is also how the user knows that the write request has finished and
	that s/he should not issue any more reads.  Note that in this case
	the mouth shapes may not be different from previously returned values.


   INPUTS
	[mouth_rb](../Includes_and_Autodocs_3._guide/node0630.html#line128) [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block with the voice field (a [narrator_rb](../Includes_and_Autodocs_3._guide/node0630.html#line93)
	structure) copied from the associated write request with the
	following fields modified:

	   io_Message - Pointer to message port for read request
	   io_Command - CMD_READ
	   io_Error   - Clear before issuing first read
	   width      - 0
	   height     - 0


   RESULTS
	As long as the speech is in progress, each read returns the
	following information in the [mouth_rb](../Includes_and_Autodocs_3._guide/node0630.html#line128) [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) block.

	If mouth shape changes are requested the following fields are
	modified:
	   width  - Contains mouth width value in arbitrary units
	   height - Contains mouth height value in arbitrary units
	   shape  - Compressed form of mouth shapes (internal use only)


	******	NEW FOR V37 NARRATOR

	If word synchronization is requested:
	   sync   - Bit NDB_WORDSYNC is set

	If syllable synchronization is requested:
	   sync   - Bit NDB_SYLSYNC is set

	Note that any or all of the above fields can be set and it is
	the user's responsibility to check for all possibilities.


   SEE ALSO
	[CMD_WRITE](../Includes_and_Autodocs_3._guide/node04D8.html)
	Exec input/output documentation.


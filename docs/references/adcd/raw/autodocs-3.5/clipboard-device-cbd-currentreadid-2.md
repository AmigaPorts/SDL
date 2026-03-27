# clipboard.device/CBD_CURRENTREADID



   NAME
	CBD_CURRENTREADID - Determine the current read identifier.

   FUNCTION
	CBD_CURRENTREADID fills the io_ClipID with a clip identifier that
	can be compared with that of a post command: if greater than
	the post identifier then the post data held privately by an
	application is not valid for its own pasting.

   IO REQUEST
	io_Message	mn_ReplyPort set up
	io_Device	preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CBD_CURRENTREADID

   RESULTS
	io_ClipID	the ClipID of the current write is set


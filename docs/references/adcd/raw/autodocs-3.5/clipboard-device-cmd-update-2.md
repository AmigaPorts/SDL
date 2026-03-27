# clipboard.device/CMD_UPDATE



   NAME
	CMD_UPDATE -- Terminate the writing of a clip to the clipboard.

   FUNCTION
	Indicate to the clipboard that the previous write commands are
	complete and can be used for any pending pastes (reads).  This
	command cannot be issued while any of the write commands are
	pending.

   IO REQUEST
	io_Message	mn_ReplyPort set up
	io_Device	preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CMD_UPDATE
	io_ClipID	the ClipID of the write

   RESULTS
	io_Error	non-zero if an error occurred


# keyboard.device/KBD_REMRESETHANDLER



   NAME
	KBD_REMRESETHANDLER -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) a keyboard reset handler.

   FUNCTION
	[Remove](../Includes_and_Autodocs_3._guide/node022F.html) a function previously added to the list of reset
	handler functions with [KBD_ADDRESETHANDLER](../Includes_and_Autodocs_3._guide/node040A.html).

   IO REQUEST
	io_Message	mn_ReplyPort set
	io_Device	preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	KBD_REMRESETHANDLER
	io_Data		a pointer to the handler interrupt structure.


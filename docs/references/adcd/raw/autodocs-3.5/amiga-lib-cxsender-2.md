# amiga.lib/CxSender



   NAME
	CxSender -- create a commodity sender object. (V36)

   SYNOPSIS
	senderObj = CxSender(port,id)

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxSender(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *,LONG);

   FUNCTION
	This function creates a Commodities sender object. The action
	of this object on receiving a Commodities message is to copy the
	Commodities message into a standard Exec [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46), to put the value
	'id' in the message as well, and to send the message off to the
	message port 'port'.

	The value 'id' is used so that an application can monitor
	messages from several senders at a single port. It can be retrieved
	from the Exec message by using the function [CxMsgID()](../Includes_and_Autodocs_3._guide/node00E7.html). The value can
	be a simple integer ID, or a pointer to some application data
	structure.

	Note that Exec messages sent by sender objects arrive
	asynchronously at the destination port. Do not assume anything about
	the status of the Commodities message which was copied into the Exec
	message you received.

	All Exec messages sent to your ports must be replied. Messages may be
	replied after the sender object has been deleted.

	This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), defined
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

   INPUTS
	port - the port for the sender to send messages to
	id - the id of the messages sent by the sender

   RESULTS
	senderObj - a pointer to the sender object, or NULL if it could
		    not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), [commodities.library/CxMsgID()](../Includes_and_Autodocs_3._guide/node00E7.html),
	[exec.library/PutMsg()](../Includes_and_Autodocs_3._guide/node0226.html), [exec.library/ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html)


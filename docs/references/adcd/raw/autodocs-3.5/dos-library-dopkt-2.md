# dos.library/DoPkt



   NAME
	DoPkt -- Send a dos packet and wait for reply (V36)

   SYNOPSIS
	result1 = DoPkt(port,action,arg1,arg2,arg3,arg4,arg5)
	D0               D1    D2    D3   D4   D5   D6   D7

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) DoPkt(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),LONG)

   FUNCTION
	Sends a packet to a handler and waits for it to return.  Any secondary
	return will be available in D1 AND from [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).  DoPkt() will work
	even if the caller is an exec task and not a process; however it will
	be slower, and may fail for some additional reasons, such as being
	unable to allocate a signal.  DoPkt() uses your pr_MsgPort for the
	reply, and will call pr_PktWait.  (See BUGS regarding tasks, though).

	Only allows 5 arguments to be specified.  For more arguments (packets
	support a maximum of 7) create a packet and use [SendPkt()/WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html).

   INPUTS
	port    - pr_MsgPort of the handler process to send to.
	action  - the action requested of the filesystem/handler
	arg1, arg2, arg3, arg4,arg5 - arguments, depend on the action, may not
		   be required.

   RESULT
	result1 - the value returned in dp_Res1, or FALSE if there was some
		  problem in sending the packet or recieving it.
	result2 - Available from [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) AND in register D1.

   BUGS
	Using DoPkt() from tasks doesn't work in V36. Use [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html),
	[PutMsg()](../Includes_and_Autodocs_3._guide/node0226.html), and [WaitPort()/GetMsg()](../Includes_and_Autodocs_3._guide/node0214.html) for a workaround, or you can call
	[CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html) to start a process to do Dos I/O for you.  In V37,
	DoPkt() will allocate, use, and free the [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) required.

   NOTES
	Callable from a task (under V37 and above).

   SEE ALSO
	[AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html), [FreeDosObject()](../Includes_and_Autodocs_3._guide/node0172.html), [SendPkt()](../Includes_and_Autodocs_3._guide/node01B0.html), [WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html),
	[CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html), [AbortPkt()](../Includes_and_Autodocs_3._guide/node0139.html)


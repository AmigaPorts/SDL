# dos.library/CliInitRun



   NAME
	CliInitRun -- Set up a process to be a shell from initial packet

   SYNOPSIS
	flags = CliInitRun( packet )
	D0		      A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CliInitRun( struct [DosPacket](../Includes_and_Autodocs_3._guide/node05D9.html#line107) * )

   FUNCTION
	This function initializes a process and CLI structure for a new
	shell, from parameters in an initial packet passed by the system
	(Run, System(), Execute()).  The format of the data in the packet
	is purposely not defined.  The setup includes all the normal fields
	in the structures that are required for proper operation (current
	directory, paths, input streams, etc).

	It returns a set of flags containing information about what type
	of shell invocation this is.

	Definitions for the values of fn:
		Bit 31     Set to indicate flags are valid
		Bit  3     Set to indicate asynch system call
		Bit  2     Set if this is a System() call
		Bit  1     Set if user provided input stream
		Bit  0     Set if RUN provided output stream

	If Bit 31 is 0, then you must check [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to determine if an error
	occurred.  If [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) returns a pointer to your process, there has
	been an error, and you should clean up and exit.  The packet will
	have already been returned by [CliInitNewcli()](../Includes_and_Autodocs_3._guide/node0147.html).  If it isn't a pointer
	to your process and Bit 31 is 0, you should wait before replying
	the packet until after you've loaded the first command (or when you
	exit).  This helps avoid disk "gronking" with the Run command.
	(Note: this is different from what you do for CliInitNewcli().)

	If Bit 31 is 1, then if Bit 3 is one, [ReplyPkt()](../Includes_and_Autodocs_3._guide/node01A9.html) the packet
	immediately (Asynch System()), otherwise wait until your shell exits
	(Sync System(), [Execute()](../Includes_and_Autodocs_3._guide/node015E.html)).
	(Note: this is different from what you do for CliInitNewcli().)

	This function is very similar to [CliInitNewcli()](../Includes_and_Autodocs_3._guide/node0147.html).

   INPUTS
	packet - the initial packet sent to your process [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27)

   RESULT
	fn - flags or a pointer

   SEE ALSO
	[CliInitNewcli()](../Includes_and_Autodocs_3._guide/node0147.html), [ReplyPkt()](../Includes_and_Autodocs_3._guide/node01A9.html), [WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html), System(), [Execute()](../Includes_and_Autodocs_3._guide/node015E.html), [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html)


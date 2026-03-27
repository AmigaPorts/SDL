# utility.library/CallHookPkt



   NAME
	CallHookPkt -- invoke a [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) function callback. (V36)

   SYNOPSIS
	return = CallHookPkt(hook,object,message);
	D0		     A0   A2	 A1

	ULONG CallHookPkt(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *,[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37),APTR);

   FUNCTION
	Performs the callback standard defined by a [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure.
	This function is really very simple; it effectively performs
	a JMP to Hook->h_Entry.

	It is probably just as well to do this operation in an
	assembly language function linked in to your program, possibly
	from a compiler supplied library or a builtin function.

	It is anticipated that C programs will often call a 'varargs'
	variant of this function which will be named [CallHook](../Includes_and_Autodocs_3._guide/node0024.html). This
	function must be provided in a compiler specific library, but
	an example of use would be:

	result = CallHook(hook,dataobject,COMMAND_ID,param1,param2);

	The function [CallHook()](../Includes_and_Autodocs_3._guide/node0024.html) can be implemented in many C compilers
	like this:

	ULONG CallHook(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) object, ULONG command, ... )
	{
	    return(CallHookPkt(hook,object,(APTR)&command));
	}

   INPUTS
	hook - pointer to an initialized [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure as defined in
	       [<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html)
	object - useful data structure in the particular context the hook is
		 being used for.
	message - pointer to a message to be passed to the hook. This is not
		  an Exec [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) structure, but is a message in the OOP sense.

   RESULTS
	return - the value returned by the hook function.

   WARNING
	The functions called through this function should follow normal
	register conventions unless EXPLICITLY documented otherwise (and
	they have a good reason too).

   SEE ALSO
	[<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html)


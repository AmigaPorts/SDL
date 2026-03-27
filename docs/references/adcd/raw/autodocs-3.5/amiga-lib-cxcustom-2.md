# amiga.lib/CxCustom



   NAME
	CxCustom -- create a custom commodity object. (V36)

   SYNOPSIS
	customObj = CxCustom(action,id);

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxCustom(LONG(*)(),LONG);

   FUNCTION
	This function creates a custom commodity object. The action
	of this object on receiving a commodity message is to call a
	function of the application programmer's choice.

	The function provided ('action') will be passed a pointer to
	the actual commodities message (in commodities private data
	space), and will actually execute as part of the input handler
	system task. Among other things, the value of 'id' can be
	recovered from the message by using the function [CxMsgID()](../Includes_and_Autodocs_3._guide/node00E7.html).

	The purpose of this function is two-fold. First, it allows
	programmers to create Commodities Exchange objects with
	functionality that was not imagined or chosen for inclusion
	by the designers. Secondly, this is the only way to act
	synchronously with Commodities.

	This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), defined
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

   INPUTS
	action - a function to call whenever a message reaches the object
	id - a message id to assign to the object

   RESULTS
	customObj - a pointer to the new custom object, or NULL if it could
		    not be created.

  SEE ALSO
	[commodities.library/CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), [commodities.library/CxMsgID()](../Includes_and_Autodocs_3._guide/node00E7.html)


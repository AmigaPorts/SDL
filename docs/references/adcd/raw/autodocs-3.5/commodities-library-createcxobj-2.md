# commodities.library/CreateCxObj



   NAME
	CreateCxObj -- create a new commodity object. (V36)

   SYNOPSIS
	co = CreateCxObj(type,arg1,arg2);
	D0		 D0   A0   A1

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CreateCxObj(ULONG,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),LONG);

   FUNCTION
	This function creates a commodity object of type 'type'. It is not
	proper to call this function directly. Each object creation routine
	except [CxBroker()](../Includes_and_Autodocs_3._guide/node00E5.html) is defined as a macro in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html)
	These are independently documented.

	All functions which operate on a commodity object are made with
	a reference to the thirty-two bit value returned by this function
	(or by [CxBroker()](../Includes_and_Autodocs_3._guide/node00E5.html)).

   INPUTS
	type - the type of object to create as defined in
	       [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html)
	arg1 - first argument, meaning depends on 'type'
	arg2 - second argument, meaning depends on 'type'

   RESULTS
	co - a pointer to the new object or NULL if it could not be created.
	     A NULL return indicates typically a lack of system memory. Minor
	     problems in creating an object, such as providing a bad filter
	     description to [cx_lib/CxFilter()](../Includes_and_Autodocs_3._guide/node002F.html), typically don't cause failure,
	     but are recorded in an internal error field in the new object
	     which can be accessed via [CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html).

   SEE ALSO
	[CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html), [cx_lib/CxFilter()](../Includes_and_Autodocs_3._guide/node002F.html), [cx_lib/CxSender()](../Includes_and_Autodocs_3._guide/node0030.html),
	[cx_lib/CxSignal()](../Includes_and_Autodocs_3._guide/node0031.html), [cx_lib/CxTranslate()](../Includes_and_Autodocs_3._guide/node0032.html), [cx_lib/CxDebug()](../Includes_and_Autodocs_3._guide/node002E.html),
	[cx_lib/CxCustom()](../Includes_and_Autodocs_3._guide/node002D.html), [CxBroker()](../Includes_and_Autodocs_3._guide/node00E5.html)


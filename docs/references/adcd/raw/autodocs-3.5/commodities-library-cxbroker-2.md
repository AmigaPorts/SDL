# commodities.library/CxBroker



   NAME
	CxBroker -- create a commodity broker. (V36)

   SYNOPSIS
	broker = CxBroker(nb,error);
	D0		  A0 D0

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxBroker(struct [NewBroker](../Includes_and_Autodocs_3._guide/node0632.html#line39) *,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *);

   FUNCTION
	This function creates a broker from the specification found in the
	[NewBroker](../Includes_and_Autodocs_3._guide/node0632.html#line39) structure pointed to by 'nb'. The purpose and meaning of the
	fields of the [NewBroker](../Includes_and_Autodocs_3._guide/node0632.html#line39) structure are described below. Also see
	[<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html) for more info.

	struct [NewBroker](../Includes_and_Autodocs_3._guide/node0632.html#line39)
	{
	    [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48)            nb_Version;
	    [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57)          nb_Name;
	    [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57)          nb_Title;
	    [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57)          nb_Descr;
	    WORD            nb_Unique;
	    WORD	    nb_Flags;
	    [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48)            nb_Pri;
	    struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *nb_Port;
	    WORD            nb_ReservedChannel;
	};

	nb_Version
	This is the way that future versions of commodities can identify
	which version of the [NewBroker](../Includes_and_Autodocs_3._guide/node0632.html#line39) structure you are using. This should be
	set to NB_VERSION as defined in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html)

	nb_Name
	This is the name of the broker. This name is used to find the broker
	in commodities' object list and is the name shown in the listview
	gadget of the Exchange program. The name string is copied in the
	broker object upon creation so it can be discarded right after
	CxBroker() returns. The maximum length of the name string is defined
	by a constant in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

	nb_Title, nb_Descr
	These are two strings which appear to the user in the Exchange
	program and describe the application the broker is representing.
	Note that these strings are copied into the broker object so they
	can be discarded right after CxBroker() returns. The maximum length
	of these strings that will be recognized are defined by constants in
	[<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

	nb_Unique
	This field indicates what should happen if a broker of the same name
	(nb_Name) already exists in commodities' object list. Constants
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html) allow the caller to specify whether
	another broker is to be created, and whether any existing broker of
	the same name should be notified that an attempt at creating a
	duplicate has been made.

	nb_Pri
	This specifies with what priority the new broker is to be inserted
	within commodities' object list. Higher priority nodes appear
	earlier in a list. It is strongly recommended that the ToolTypes
	environment of an application be used to allow the end-user to set
	the priority of the broker.

   INPUTS
	nb - an initialized [NewBroker](../Includes_and_Autodocs_3._guide/node0632.html#line39) structure
	error - a pointer to a longword where to store a failure code (may be
		NULL)

   RESULTS
	broker - a pointer to the broker object or NULL upon failure. If the
		 'error' pointer is not NULL, a further diagnostic code is
		 placed at that address. Error codes are defined in
		 [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html) and include:

			CBERR_OK
			No problems; broker created OK.

 			CBERR_SYSERR
			System problems, not your fault, sign of low memory.

			CBERR_DUP
			The nb_Unique field specified that only one broker of
			'nb_Name' should be allowed, and one already exists.

			CBERR_VERSION
			The version specified in 'nb_Version' is unknown to the
			library.

   SEE ALSO
	[SetCxObjPri()](../Includes_and_Autodocs_3._guide/node00F6.html), [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html)


# datatypes.library/GetDTTriggerMethods



    NAME
	GetDTTriggerMethods - Obtain trigger methods supported by an object
```c
                                                               (V39)

    SYNOPSIS
```
	methods = GetDTTriggerMethods (object);
	d0				a0

	struct DTMethods *GetDTTriggerMethods (Object *);

    FUNCTION
	This function is used to obtain a list of trigger methods that an
	object supports.  This is so that an application can provide
	the appropriate controls for an object.  For example, an AmigaGuide
	object needs controls for "Contents", "Index", "Retrace", "Browse <",
	and "Browse >",

    INPUTS
	object - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

    RETURNS
	Returns a pointer to a NULL terminated [DTMethod](../Includes_and_Autodocs_3._guide/node0606.html#line272) list.  This list is
	only valid until the object is disposed off.

    EXAMPLE
	To call the method:

	    [DoMethod](../Includes_and_Autodocs_3._guide/node0038.html) (object, DTM_TRIGGER, dtm[button]->dtm_Method);

    SEE ALSO
	[GetDTMethods()](../Includes_and_Autodocs_3._guide/node010E.html)


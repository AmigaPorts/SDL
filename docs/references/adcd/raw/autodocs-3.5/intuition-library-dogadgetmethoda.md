# intuition.library/DoGadgetMethodA



    NAME
	DoGadgetMethodA -- Invoke method on a boopsi gadget. (V39)
	DoGadgetMethod -- Varargs stub for DoGadgetMethodA(). (V39)

    SYNOPSIS
	result = DoGadgetMethodA( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) )
	D0		          A0      A1      A2         A3

	ULONG DoGadgetMethodA( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, [Msg](../Includes_and_Autodocs_3._guide/node0636.html#line28) );

	result = DoGadgetMethod( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), MethodID, ...)

	ULONG DoGadgetMethod( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, ULONG, ... );

    FUNCTION
	Same as the [DoMethod()](../Includes_and_Autodocs_3._guide/node0038.html) function of amiga.lib, but provides context
	information and arbitration for classes which implement custom
	Intuition gadgets.

	You should use this function for boopsi gadget objects,
	or for "models" which propagate information to gadgets.

	Unlike [DoMethod()](../Includes_and_Autodocs_3._guide/node0038.html), this function provides a [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) pointer
	(if possible) when invoking the method.  Some classes may
	require or benefit from this.

    INPUTS
	[Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) = abstract pointer to a boopsi gadget
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = window gadget has been added to using [AddGList()](../Includes_and_Autodocs_3._guide/node0393.html) or [AddGadget()](../Includes_and_Autodocs_3._guide/node0392.html)
	[Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = for REQGADGETs, requester containing the gadget
	[Msg](../Includes_and_Autodocs_3._guide/node0636.html#line28) = the boopsi message to send

    RESULT
	The object does whatever it wants with the message you sent,
	which might include updating its gadget visuals.

	The return value is defined per-method.

    NOTES
	This function invokes the specified method with a [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24)
	derived from the 'Window' and 'Requester' pointers.  The [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24)
	is passed as the second parameter of the message, except for
	OM_NEW, OM_SET, OM_NOTIFY, and OM_UPDATE, where the [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24)
	is passed as the third parameter.

	Implementers of new gadget methods should ensure that the
	[GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) is the second long-word of their message!

    SEE ALSO
	[NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html), [DisposeObject()](../Includes_and_Autodocs_3._guide/node03A5.html), [GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html), [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.


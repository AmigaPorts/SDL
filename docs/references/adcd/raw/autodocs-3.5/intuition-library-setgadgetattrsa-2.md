# intuition.library/SetGadgetAttrsA



    NAME
	SetGadgetAttrsA -- Specify attribute values for a boopsi gadget. (V36)
	SetGadgetAttrs -- Varargs stub for SetGadgetAttrsA(). (V36)

    SYNOPSIS
	result = SetGadgetAttrsA( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), TagList )
	D0		          A0      A1      A2         A3

	ULONG SetGadgetAttrsA( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	result = SetGadgetAttrs( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), Tag1, ...)

	ULONG SetGadgetAttrs( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, ULONG, ... );

    FUNCTION
	Same as SetAttrs(), but provides context information and
	arbitration for classes which implement custom Intuition gadgets.

	You should use this function for boopsi gadget objects which have
	already been added to a requester or a window, or for "models" which
	propagate information to gadget already added.

	Typically, the gadgets will refresh their visuals to reflect
	changes to visible attributes, such as the value of a slider,
	the text in a string-type gadget, the selected state of a button.

	You can use this as a replacement for SetAttrs(), too, if you
	specify NULL for the 'Window' and 'Requester' parameters.

    INPUTS
	[Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) = abstract pointer to a boopsi gadget
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = window gadget has been added to using [AddGList()](../Includes_and_Autodocs_3._guide/node0393.html) or [AddGadget()](../Includes_and_Autodocs_3._guide/node0392.html)
	[Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = for REQGADGETs, requester containing the gadget
	TagList = array of [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) structures with attribute/value pairs.

    RESULT
	The object does whatever it wants with the attributes you provide,
	which might include updating its gadget visuals.

	The return value tends to be non-zero if the changes would require
	refreshing gadget imagery, if the object is a gadget.

    NOTES
	This function invokes the OM_SET method with a [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24)
	derived from the 'Window' and 'Requester' pointers.

    BUGS
	Prior to V39, this function ran with inadequate locking against
	the calls that Intuition's input task makes to the gadgets.
	To run properly prior to V39, this function, input processing,
	and and the gadget's dispatcher must be mutually re-entrant.

    SEE ALSO
	[NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html), [DisposeObject()](../Includes_and_Autodocs_3._guide/node03A5.html), [GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html), [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.


# amiga.lib/CxTranslate



   NAME
	CxTranslate -- create a commodity translator object. (V36)

   SYNOPSIS
	translatorObj = CxTranslate(ie);

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxTranslate(struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *);

   FUNCTION
	This function creates a Commodities 'translator' object.
	The action of this object on receiving a Commodities message is to
	replace that message in the commodities network with a chain of
	Commodities input messages.

	There is one new Commodities input message generated for each input
	event in the linked list starting at 'ie' (and NULL terminated). The
	routing information of the new input messages is copied from the input
	message they replace.

	The linked list of input events associated with a translator object
	can be changed using the [SetTranslate()](../Includes_and_Autodocs_3._guide/node00F9.html) function.

	If 'ie' is NULL, the null translation occurs: that is, the original
	commodities input message is disposed, and no others are created to
	take its place.

	This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), defined
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

   INPUTS
	ie - the input event list used as replacement by the translator

   RESULTS
	translatorObj - a pointer to the translator object, or NULL if it could
		        not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), [commodities.library/SetTranslate()](../Includes_and_Autodocs_3._guide/node00F9.html)


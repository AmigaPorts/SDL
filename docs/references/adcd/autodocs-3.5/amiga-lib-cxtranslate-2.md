---
title: amiga.lib/CxTranslate
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-cxtranslate-2
functions: [CreateCxObj, SetTranslate]
libraries: [commodities.library]
---

# amiga.lib/CxTranslate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxTranslate -- create a commodity translator object. (V36)

   SYNOPSIS
	translatorObj = CxTranslate(ie);

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxTranslate(struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *);

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
	can be changed using the [SetTranslate()](autodocs-3.5/commodities-library-settranslate-2.md) function.

	If 'ie' is NULL, the null translation occurs: that is, the original
	commodities input message is disposed, and no others are created to
	take its place.

	This function is a C-language macro for [CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), defined
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

   INPUTS
	ie - the input event list used as replacement by the translator

   RESULTS
	translatorObj - a pointer to the translator object, or NULL if it could
		        not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), [commodities.library/SetTranslate()](autodocs-3.5/commodities-library-settranslate-2.md)

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [SetTranslate — commodities.library](../autodocs/commodities.library.md#settranslate)

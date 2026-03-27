---
title: resource.library/RL_SetResourceScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-setresourcescreen
functions: []
libraries: []
---

# resource.library/RL_SetResourceScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_SetResourceScreen - sets or clears the screen (V44)

   SYNOPSIS
	success = RL_SetResourceScreen(resource, screen)
	 D0                             A0        A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) RL_SetResourceScreen(RESOURCEFILE, struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *);

   FUNCTION
	This routine sets or clears the screen of the resource. You must clear
	the screen before you close or unlock it. You must set a valid screen
	before you call NewObjectA or NewGroupA.

	Setting a new screen does not mean that the allocated objects are
	automatically adapt to the new screen. This function only controls
	the internal housekeeping of the screen (and related structures). If
	you cannot adapt the allocated objects to a new screen (like setting
	an attribute with the new screen value) you must dispose and
	recreate them.

	If you set the same screen pointer as was before this function does
	nothing but returns TRUE.

   INPUTS
	resource -- a pointer to a resource
	screen --  a pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md) or NULL

   RESULTS
	success -- TRUE if the screen is successfully set or cleared.

   SEE ALSO
	[resource.library/RL_OpenResource](autodocs-3.5/resource-library-rl-openresource.md)


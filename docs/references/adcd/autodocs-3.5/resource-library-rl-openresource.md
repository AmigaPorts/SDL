---
title: resource.library/RL_OpenResource
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-openresource
functions: []
libraries: []
---

# resource.library/RL_OpenResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_OpenResource - open a resource (V44)

   SYNOPSIS
	resource = RL_OpenResource(resobject, screen, catalog)
	 D0                         A0         A1      A2

	[RESOURCEFILE](autodocs-3.5/include-libraries-resource-h.md) RL_OpenResource(APTR, struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, struct [Catalog](autodocs-3.5/include-libraries-locale-h.md) *);

   FUNCTION
	This routine opens a resource object.

	If you give a NULL for the parameter screen do not call [RL_NewObjectA](autodocs-3.5/resource-library-rl-newobjecta.md)
	or [RL_NewGroupA](autodocs-3.5/resource-library-rl-newgroupa.md). You must first set a screen with
	[RL_SetResourceScreen](autodocs-3.5/resource-library-rl-setresourcescreen.md).

   INPUTS
	resobject -- a pointer to a resource object
	screen -- a pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md). This may be NULL
	catalog -- a pointer to a [Catalog](autodocs-3.5/include-libraries-locale-h.md). This may be NULL

   RESULTS
	resource -- a pointer to a resource or NULL

   EXAMPLE

	extern char RCTResource[];
	struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *screen;

	screen = LockPubScreen(NULL);
	[RESOURCEFILE](autodocs-3.5/include-libraries-resource-h.md) resource = RL_OpenResource(RCTResource, screen, NULL);
	if (resource)
	{
		/* create your objects here */
	}
	RL_CloseResource(resource);
	UnlockPubScreen(NULL,screen);

   SEE ALSO
	[intuition.library/LockPubScreen](autodocs-3.5/intuition-library-lockpubscreen-2.md)
	[intuition.library/OpenScreenTagList](autodocs-3.5/intuition-library-openscreentaglist-2.md)
	locale.library/OpenCatalogA
	[resource.library/RL_CloseResource](autodocs-3.5/resource-library-rl-closeresource.md)
	[resource.library/RL_SetResourceScreen](autodocs-3.5/resource-library-rl-setresourcescreen.md)


---
title: resource.library/--background--
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-background
functions: []
libraries: []
---

# resource.library/--background--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	resource.library -- resource handling for BOOPSI classes

   DESCRIPTION
	The resource.library offers an API to handle resource objects
	(an object file created from ReActor or similar BOOPSI creator
	tools). One can create BOOPSI objects and groups of BOOPSI
	objects and resource tracking is completly done by
	resource.library.

	A resource object ist an AmigaDOS hunk object file that contains
	data structures with all necessary informations for creating BOOPSI
	objects. Special class informations allows to handle intuition
	BOOPSI objects.

	Strings are automatically localized if needed. The resource
	objects contains references to labels (for the locale string IDs)
	and strings (for the default strings) which has to be linked with
	symbol definitions from the application (a new catcomp version is
	available to create assembler source files for those definitions).

	The default label for the resource object is _RCTResource (defined
	by ReActor). Use a statement like

		extern char RCTResource[];

	to access the resource object. The variable RCTResource has to be
	used as the first argument to [RL_OpenResource](autodocs-3.5/resource-library-rl-openresource.md).


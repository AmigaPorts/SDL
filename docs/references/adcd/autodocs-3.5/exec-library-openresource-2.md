---
title: exec.library/OpenResource
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-openresource-2
functions: []
libraries: []
---

# exec.library/OpenResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenResource -- gain access to a resource

   SYNOPSIS
	resource = OpenResource(resName)
	D0			A1

	[APTR](autodocs-3.5/include-exec-types-h.md) OpenResource(STRPTR);

   FUNCTION
	This function returns a pointer to a resource that was previously
	installed into the system.

	There is no CloseResource() function.

   INPUTS

       resName - the name of the resource requested.
   RESULTS
	resource - if successful, a resource pointer, else NULL


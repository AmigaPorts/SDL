---
title: expansion.library/ObtainConfigBinding
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-obtainconfigbinding-2
functions: []
libraries: []
---

# expansion.library/ObtainConfigBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ObtainConfigBinding - try to get permission to bind drivers

   SYNOPSIS
	ObtainConfigBinding()


   FUNCTION
	ObtainConfigBinding gives permission to bind drivers to
	[ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structures.  It exists so two drivers at once
	do not try and own the same [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structure.  This
	call will block until it is safe proceed.

	It is crucially important that people lock out others
	before loading new drivers.  Much of the data that is used
	to configure things is statically kept, and others need
	to be kept from using it.

	This call is built directly on Exec [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) code
	(e.g. ObtainSemaphore).

   INPUTS

   RESULTS

   EXCEPTIONS

   SEE ALSO
	[ReleaseConfigBinding()](autodocs-3.5/expansion-library-releaseconfigbinding-2.md)

   BUGS


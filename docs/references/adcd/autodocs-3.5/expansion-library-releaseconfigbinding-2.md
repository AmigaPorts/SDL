---
title: expansion.library/ReleaseConfigBinding
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-releaseconfigbinding-2
functions: []
libraries: []
---

# expansion.library/ReleaseConfigBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReleaseConfigBinding - allow others to bind to drivers

   SYNOPSIS
	ReleaseConfigBinding()


   FUNCTION
	This call should be used when you are done binding drivers
	to [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) entries.  It releases the SignalSemaphore; this
	allows others to bind their drivers to [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structures.

   SEE ALSO
	[ObtainConfigBinding()](autodocs-3.5/expansion-library-obtainconfigbinding-2.md)


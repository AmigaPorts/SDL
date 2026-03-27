---
title: The Global Drawing Attribute Chunks / PPRF
manual: devices
chapter: devices
section: the-global-drawing-attribute-chunks-pprf
functions: []
libraries: []
---

# The Global Drawing Attribute Chunks / PPRF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

PPRF (0x50505249)   	/* Page preferences */

The PPRF chunk contains preference settings for ProVector.  Although this
chunk is not required, its use is encouraged because it contains some
important environment information.

	struct PPRFstruct {
	    ULONG	ID;
	    ULONG	Size;
	    char	Prefs[Size];
	};

DR2D stores preferences as a concatenation of several null-terminated
strings, in the Prefs[] array.  The strings can appear in any order. The
currently supported strings are:

		Units=<unit-type>
		Portrait=<boolean>
		PageType=<page-type>
		GridSize=<number>

where:
		<unit-type> 	is either Inch, Cm, or Pica
		<boolean>   	is either True or False
		<page-type> 	is either Standard, Legal, B4, B5, A3,
				  A4, A5, or Custom
		<number>    	is a floating-point number

The DR2D FORM does not require this chunk to explicitly state all the
possible preferences.  In the absence of any particular preference string,
a DR2D reader should fall back on the default value.  The defaults are:

		Units=Inch
		Portrait=True
		PageType=Standard
		GridSize=1.0


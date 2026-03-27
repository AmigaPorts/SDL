---
title: icon.library/MatchToolValue
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-matchtoolvalue-2
functions: []
libraries: []
---

# icon.library/MatchToolValue

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MatchToolValue - check a tool type variable for a particular value.

   SYNOPSIS
	result = MatchToolValue(typeString, value)
	  D0                        A0        A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) MatchToolValue(STRPTR, STRPTR);

   FUNCTION
	MatchToolValue is useful for parsing a tool type value for
	a known value.  It knows how to parse the syntax for a tool
	type value (in particular, it knows that '|' separates
	alternate values).  Note that the parsing is case insensitive.

   INPUTS
	typeString -- a ToolType value (as returned by FindToolType)
	value -- you are interested if value appears in typeString

   RESULTS
	result -- TRUE if the value was in typeString else FALSE.

   EXAMPLE
	Assume there are two type strings:
	    type1 = "text"
	    type2 = "a|b|c"

	MatchToolValue( type1, "text" ) returns TRUE
	MatchToolValue( type1, "TEXT" ) returns TRUE
	MatchToolValue( type1, "data" ) returns FALSE
	MatchToolValue( type2, "a" )    returns TRUE
	MatchToolValue( type2, "b" )    returns TRUE
	MatchToolValue( type2, "d" )    returns FALSE
	MatchToolValue( type2, "a|b" )  returns FALSE

   NOTES
	icon.library V44 skips blank spaces surrounding the typeString
	options and the value string. Older icon.library versions did
	not support this.

   SEE ALSO
	[icon.library/FindToolType](autodocs-3.5/icon-library-findtooltype-2.md)
	[utility.library/Stricmp](autodocs-3.5/utility-library-stricmp-2.md)


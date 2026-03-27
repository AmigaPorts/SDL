---
title: icon.library/FindToolType
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-findtooltype-2
functions: []
libraries: []
---

# icon.library/FindToolType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindToolType - find the value of a ToolType variable.

   SYNOPSIS
	value = FindToolType(toolTypeArray, typeName)
	  D0                      A0           A1

	[STRPTR](autodocs-3.5/include-exec-types-h.md) FindToolType(STRPTR *, STRPTR);

   FUNCTION
	This function searches a tool type array for a given entry,
	and returns a pointer to that entry.  This is useful for
	finding standard tool type variables.  The returned
	value is not a new copy of the string but is only
	a pointer to the part of the string after typeName.

   INPUTS
	toolTypeArray -- an array of strings (STRPTR *).
	typeName -- the name of the tooltype entry (STRPTR).

   RESULTS
	value -- a pointer to a string that is the value bound to typeName,
	        or NULL if typeName is not in the toolTypeArray.

   EXAMPLE
	Assume the tool type array has two strings in it:
	    "FILETYPE=text"
	    "TEMPDIR=:t"

	FindToolType( toolTypeArray, "FILETYPE" ) returns "text"
	FindToolType( toolTypeArray, "filetype" ) returns "text"
	FindToolType( toolTypeArray, "TEMPDIR" )  returns ":t"
	FindToolType( toolTypeArray, "MAXSIZE" )  returns NULL
	FindToolType( toolTypeArray, "text" )     returns NULL
	FindToolType( toolTypeArray, ":t" )       returns NULL

   NOTES
	icon.library V44 tolerates tool type strings with additional
	blanks around the '=' character, such as in "FILETYPE = text".
	Older icon.library versions did not support this.

   SEE ALSO
	[icon.library/MatchToolValue](autodocs-3.5/icon-library-matchtoolvalue-2.md)


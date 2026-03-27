# icon.library/MatchToolValue



   NAME
	MatchToolValue - check a tool type variable for a particular value.

   SYNOPSIS
	result = MatchToolValue(typeString, value)
	  D0                        A0        A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) MatchToolValue(STRPTR, STRPTR);

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
	[icon.library/FindToolType](../Includes_and_Autodocs_3._guide/node0349.html)
	[utility.library/Stricmp](../Includes_and_Autodocs_3._guide/node05B0.html)


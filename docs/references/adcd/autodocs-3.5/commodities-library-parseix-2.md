---
title: commodities.library/ParseIX
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-parseix-2
functions: [MatchIX]
libraries: [commodities.library]
---

# commodities.library/ParseIX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ParseIX -- initialize an input expression given a description string.
		   (V36)

   SYNOPSIS
	failureCode = ParseIX(description,ix);
	D0		      A0          A1

	[LONG](autodocs-3.5/include-exec-types-h.md) ParseIX(STRPTR,IX *);

   FUNCTION
	Given an input description string and an allocated input
	expression, sets the fields of the input expression to
	correspond to the description string.

   INPUTS
	description - the string to parse
	ix - the input expression to hold the result of the parse

   RESULTS
	failureCode -  0 if all went well,
		      -1 if tokens after end (code spec)
	              -2 if 'description' was NULL

   SEE ALSO
	[<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md), [MatchIX()](autodocs-3.5/commodities-library-matchix.md)

---

## See Also

- [MatchIX — commodities.library](../autodocs/commodities.library.md#matchix)

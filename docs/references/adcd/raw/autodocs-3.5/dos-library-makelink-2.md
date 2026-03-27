# dos.library/MakeLink



   NAME
	MakeLink -- Creates a filesystem link (V36)

   SYNOPSIS
	success = MakeLink( name, dest, soft )
	D0		     D1    D2    D3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) MakeLink( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) )

   FUNCTION
	Create a filesystem link from 'name' to dest.  For "soft-links",
	dest is a pointer to a null-terminated path string.  For "hard-
	links", dest is a lock (BPTR).  'soft' is FALSE for hard-links,
	non-zero otherwise.

	Soft-links are resolved at access time by a combination of the
	filesystem (by returning ERROR_IS_SOFT_LINK to dos), and by
	Dos (using [ReadLink()](../Includes_and_Autodocs_3._guide/node01A3.html) to resolve any links that are hit).

	Hard-links are resolved by the filesystem in question.  A series
	of hard-links to a file are all equivalent to the file itself.
	If one of the links (or the original entry for the file) is
	deleted, the data remains until there are no links left.

   INPUTS
	name - Name of the link to create
	dest - [CPTR](../Includes_and_Autodocs_3._guide/node0654.html#line67) to path string, or [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) lock
	soft - FALSE for hard-links, non-zero for soft-links

   RESULT
	Success - boolean

   BUGS
	In V36, soft-links didn't work in the ROM filesystem.  This was
	fixed for V37.

   SEE ALSO
	[ReadLink()](../Includes_and_Autodocs_3._guide/node01A3.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html), [Lock()](../Includes_and_Autodocs_3._guide/node0186.html)


# dos.library/NewLoadSeg



   NAME
	NewLoadSeg -- Improved version of [LoadSeg](../Includes_and_Autodocs_3._guide/node0185.html) for stacksizes (V36)

   SYNOPSIS
	seglist = NewLoadSeg(file, tags)
	D0		      D1    D2

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) NewLoadSeg(STRPTR, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

	seglist = NewLoadSegTagList(file, tags)
	D0			     D1    D2

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) NewLoadSegTagList(STRPTR, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

	seglist = NewLoadSegTags(file, ...)

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) NewLoadSegTags(STRPTR, ...)

   FUNCTION
	Does a [LoadSeg](../Includes_and_Autodocs_3._guide/node0185.html) on a file, and takes additional actions based on the
	tags supplied.

	Clears unused portions of Code and Data hunks (as well as BSS hunks).
	(This also applies to [InternalLoadSeg()](../Includes_and_Autodocs_3._guide/node0180.html) and [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html)).

	NOTE to overlay users: NewLoadSeg() does NOT return seglist in
	both D0 and D1, as [LoadSeg](../Includes_and_Autodocs_3._guide/node0185.html) does.  The current ovs.asm uses [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html),
	and assumes returns are in D1.  We will support this for [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html)
	ONLY.

   INPUTS
	file - Filename of file to load
	tags - pointer to tagitem array

   RESULT
	seglist - Seglist loaded, or NULL

   BUGS
	No tags are currently defined.

   SEE ALSO
	[LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html), [UnLoadSeg()](../Includes_and_Autodocs_3._guide/node01C7.html), [InternalLoadSeg()](../Includes_and_Autodocs_3._guide/node0180.html), [InternalUnLoadSeg()](../Includes_and_Autodocs_3._guide/node0181.html)


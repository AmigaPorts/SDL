# utility.library/NextTagItem



   NAME
	NextTagItem -- iterate through a tag list. (V36)

   SYNOPSIS
	tag = NextTagItem(tagItemPtr);
	D0		  A0

	struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *NextTagItem(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) **);

   FUNCTION
	Iterates through a tag list, skipping and chaining as dictated by
	system tags. TAG_SKIP will cause it to skip the entry and a number
	of following tags as specified in ti_Data. TAG_IGNORE ignores that
	single entry, and TAG_MORE has a pointer to another array of tags (and
	terminates the current array!). TAG_DONE also terminates the current
	array. Each call returns either the next tagitem you should examine,
	or NULL when the end of the list has been reached.

   INPUTS
	tagItemPtr - doubly-indirect reference to a [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) structure.
		     The pointer will be changed to keep track of the
		     iteration.

   RESULTS
	nextTag	- each [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) in the array or chain of arrays that should be
		  processed according to system tag values defined in
		  [<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html)) is returned in turn with successive
		  calls.

   EXAMPLE
	Iterate(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);
	{
	struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tstate;
	struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tag;

	    tstate = tags;
	    while (tag = NextTagItem(&tstate))
	    {
		switch (tag->ti_Tag)
		{
 		    case TAG1: ...
			       break;

 		    case TAG2: ...
			       break;

		    ...
		}
	    }
   	}

   WARNING
	Do NOT use the value of *tagItemPtr, but rather use the pointer
	returned by NextTagItem().

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [GetTagData()](../Includes_and_Autodocs_3._guide/node05A3.html), [PackBoolTags()](../Includes_and_Autodocs_3._guide/node05A8.html), [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html)


# utility.library/CloneTagItems



   NAME
	CloneTagItems -- copy a tag list. (V36)

   SYNOPSIS
	clone = CloneTagItems(original);
	D0		      A0

	struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *CloneTagItems(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	Copies the essential contents of a tag list into a new tag list.

	The cloning is such that calling [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html) with a given tag on
	the original or cloned tag lists will always return the same
	tag value. That is, the ordering of the tags is maintained.

   INPUTS
	original - tag list to clone. May be NULL, in which case an
		   empty tag list is returned.

   RESULTS
	clone - copy of the original tag list, or NULL if there was not enough
		memory. This tag list must eventually by freed by calling
		[FreeTagItems()](../Includes_and_Autodocs_3._guide/node05A2.html).

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [AllocateTagItems()](../Includes_and_Autodocs_3._guide/node0594.html), [FreeTagItems()](../Includes_and_Autodocs_3._guide/node05A2.html),
	[RefreshTagItemClones()](../Includes_and_Autodocs_3._guide/node05AA.html)


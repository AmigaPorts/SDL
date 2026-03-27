# utility.library/RefreshTagItemClones



   NAME
	RefreshTagItemClones -- rejuvenate a clone from the original. (V36)

   SYNOPSIS
	RefreshTagItemClones(clone,original)
			     A0	   A1

	VOID RefreshTagItemClones(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	If (and only if) the tag list 'clone' was created from 'original' by
	[CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html), and if 'original' has not been changed in any way,
	you can reset the clone list to its original state by using this
	function.

   INPUTS
	clone - return value from CloneTagItems(original)
	original - a tag list that hasn't changed since [CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html)

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [CloneTagItems()](../Includes_and_Autodocs_3._guide/node059B.html), [AllocateTagItems()](../Includes_and_Autodocs_3._guide/node0594.html),
	[FreeTagItems()](../Includes_and_Autodocs_3._guide/node05A2.html), [ApplyTagChanges()](../Includes_and_Autodocs_3._guide/node0597.html)


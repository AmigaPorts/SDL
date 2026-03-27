# utility.library/ApplyTagChanges



   NAME
	ApplyTagChanges -- change a tag list based on a second tag list. (V39)

   SYNOPSIS
	ApplyTagChanges(list,changeList);
			A0   A1

	VOID ApplyTagChanges(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	For any tag that appears in both 'list' and 'changeList', this
	function will change the ti_Data field of the tag in 'list' to
	match the ti_Data field of the tag in 'changeList'. In effect,
	'changeList' contains a series of new values for tags already in
	'list'. Any tag in 'changeList' that is not in 'list' is ignored.

   INPUTS
	list - a list of existing tags (may be NULL)
	changeList - a list of tags to modify 'list' with (may be NULL)

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [FilterTagChanges()](../Includes_and_Autodocs_3._guide/node059D.html)


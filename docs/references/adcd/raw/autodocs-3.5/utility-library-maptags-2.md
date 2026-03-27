# utility.library/MapTags



   NAME
	MapTags	-- convert ti_Tag values in a list via map pairing. (V36)

   SYNOPSIS
	MapTags(tagList,mapList,mapType);
		A0	A1      D0

	VOID MapTags(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *,ULONG);

   FUNCTION
	Apply a "mapping list" mapList to tagList.

	If the ti_Tag field of an item in tagList appears as ti_Tag in some
	item in mapList, overwrite ti_Tag with the corresponding ti_Data
	from the map list.

	The mapType parameter specifies how the mapping operation is to
	proceed, with the following available types:

		MAP_REMOVE_NOT_FOUND
		If a tag in tagList does not appear in the mapList, remove
		it from tagList.

		MAP_KEEP_NOT_FOUND
		To have items which do not appear in the mapList survive the
		mapping process as-is.

	MapTags() is central to BOOPSI gadget interconnections where you want
	to convert the tag values from one space (the sender) to another (the
	receiver).

	The procedure will change the values of the input tag list
	tagList (but not mapList).

	You can "filter" a list by passing MAP_REMOVE_NOT_FOUND as mapType,
	and having the data items in mapList equal the corresponding tags.

	You can perform the inverse filter ("everything but") by passing
	a mapType of MAP_KEEP_NOT_FOUND, and creating a map item for every tag
	you want to filter out, pairing it with a mapped data value of
	TAG_IGNORE.

	For safety and "order independence" of tag item arrays, if you
	attempt to map some tag to the value TAG_DONE, the value TAG_IGNORE
	will be substituted instead.

   INPUTS
	tagList	- input list of tag items which is to be mapped to tag values
		  as specified in mapList.
	mapList - a "mapping list" tag list which pairs tag values expected to
		  appear in tagList with new values to be substituted in the
		  ti_Tag fields of tagList (may be NULL)
	mapType - one of the available mapping types as defined in
		  [<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html)

   EXAMPLE
	/* Consider this source list: */
	    struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) list[] =
	    {
		{MY_SIZE, 	71},
		{MY_WEIGHT, 	200},
		{TAG_DONE,	}

```c
           };
```
	/* And the mapping list: */
	    struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) map[] =
	    {
		{MY_SIZE, 	HIS_TALL},
		{TAG_DONE,	}
	    };

	/* Then after MapTags(list,map,MAP_REMOVE_NOT_FOUND), 'list' will
	   become: */
		{HIS_TALL,71},
		{TAG_IGNORE,},
		{TAG_DONE,}

	/* Or after MapTags(list,map,MAP_KEEP_NOT_FOUND), 'list' will
	   become: */
		{HIS_TALL,  71},
		{MY_WEIGHT, 200},
		{TAG_DONE,  }

   BUGS
	Prior to V39, the mapType parameter did not work. The function
	always behaved as if the parameter was set to MAP_KEEP_NOT_FOUND.

   SEE ALSO
	[<utility/tagitem.h>](../Includes_and_Autodocs_3._guide/node064C.html), [ApplyTagChanges()](../Includes_and_Autodocs_3._guide/node0597.html), [FilterTagChanges()](../Includes_and_Autodocs_3._guide/node059D.html)


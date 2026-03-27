# utility.library/UnpackStructureTags



   NAME
	UnpackStructureTags -- unpack a structure to values in taglist. (V39)

   SYNOPSIS
	num = UnpackStructureTags(pack,packTable,tagList);
	D0                        A0   A1        A2

	ULONG UnpackStructureTags(APTR,ULONG *,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	For each table entry, a [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html) will be done and if the
	matching tag is found in the taglist, the data in the structure
	will be placed into the memory pointed to by the tag's ti_Data.
	ti_Data *must* point to a LONGWORD.

   INPUTS
	pack - a pointer to the data area to be unpacked
	packTable - a pointer to the packing information table.
		    See [<utility/pack.h>](../Includes_and_Autodocs_3._guide/node066A.html) for definition and macros
	tagList - a pointer to the taglist to unpack into

   RESULTS
	num - the number of tag items unpacked

   SEE ALSO
	[<utility/pack.h>](../Includes_and_Autodocs_3._guide/node066A.html), [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html), [PackStructureTags()](../Includes_and_Autodocs_3._guide/node05A9.html)


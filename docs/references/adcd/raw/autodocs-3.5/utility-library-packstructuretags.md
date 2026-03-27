# utility.library/PackStructureTags



   NAME
	PackStructureTags -- pack a structure with values from taglist. (V39)

   SYNOPSIS
	num = PackStructureTags(pack,packTable,tagList);
	D0                      A0   A1        A2

	ULONG PackStructureTags(APTR,ULONG *,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	For each table entry, a [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html) will be done and if the
	matching tag is found in the taglist, the data field will be
	packed into the given structure based on the packtable
	definition.

   INPUTS
	pack - a pointer to the data area to fill in.
	packTable - a pointer to the packing information table.
		    See [<utility/pack.h>](../Includes_and_Autodocs_3._guide/node066A.html) for definition and macros.
	tagList - a pointer to the taglist to pack into the structure

   RESULTS
	num - the number of tag items packed

   SEE ALSO
	[<utility/pack.h>](../Includes_and_Autodocs_3._guide/node066A.html), [FindTagItem()](../Includes_and_Autodocs_3._guide/node05A0.html), [UnpackStructureTags()](../Includes_and_Autodocs_3._guide/node05B8.html)


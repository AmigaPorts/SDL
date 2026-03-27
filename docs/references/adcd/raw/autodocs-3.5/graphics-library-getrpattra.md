# graphics.library/GetRPAttrA



   NAME
       GetRPAttrA -- examine rastport settings via a tag list
	GetRPAttrs  -- varargs stub for GetRPAttrA

   SYNOPSIS

```c
       GetRPAttrA(rp,tags)
                  a0   a1
```
	void GetRPAttrA(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	GetRPAttrs(rp,attr1,&result1,...);

   FUNCTION
```c
       [Read](../Includes_and_Autodocs_3._guide/node01A0.html) the settings of a rastport into variables. The
```
	ti_Tag field of the [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) specifies which attribute
	should be read, and the ti_Data field points at the
	location where the result hsould be stored. All current
	tags store the return data as LONGs (32 bits).

	currently available tags are:

		RPTAG_Font		Font for [Text()](../Includes_and_Autodocs_3._guide/node0332.html)
		RPTAG_SoftStyle		style for text (see [graphics/text.h)](../Includes_and_Autodocs_3._guide/node05EC.html)
		RPTAG_APen		Primary rendering pen
		RPTAG_BPen		Secondary rendering pen
		RPTAG_DrMd 		Drawing mode (see [graphics/rastport.h)](../Includes_and_Autodocs_3._guide/node05D7.html)
		RPTAG_OutLinePen 	Area Outline pen
		RPTAG_WriteMask 	Bit Mask for writing.
		RPTAG_MaxPen 		Maximum pen to render (see [SetMaxPen()](../Includes_and_Autodocs_3._guide/node0324.html))
		RPTAG_DrawBounds	Determine the area that will be rendered
					into by rendering commands. Can be used
					to optimize window refresh. Pass a pointer
					to a rectangle in the tag data. On return,
					the rectangle's MinX will be greater than
					its MaxX if there are no active cliprects.

   INPUTS
	rp - pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to examine.
	tags - a standard tag list specifying the attributes to be read,
		and where to store their values.

   RESULT

   BUGS

   SEE ALSO
	[GetAPen()](../Includes_and_Autodocs_3._guide/node02E0.html) [GetBPen()](../Includes_and_Autodocs_3._guide/node02E2.html) [GetDrMd()](../Includes_and_Autodocs_3._guide/node02E5.html) GetOutLinePen()
	[SetRPAttrA()](../Includes_and_Autodocs_3._guide/node032C.html) [graphics/rpattr.h](../Includes_and_Autodocs_3._guide/node0663.html)


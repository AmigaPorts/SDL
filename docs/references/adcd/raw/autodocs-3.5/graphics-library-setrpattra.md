# graphics.library/SetRPAttrA



   NAME
       SetRPAttrA -- modify rastport settings via a tag list
	SetRPAttrs  -- varargs stub for SetRPAttrA

   SYNOPSIS

```c
       SetRPAttrA(rp,tags)
                  a0   a1
```
	void SetRPAttrA(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	SetRPAttrs(rp,tag,...);

   FUNCTION
       Modify settings of a rastport, based on the taglist passed.
	currently available tags are:

		RPTAG_Font		Font for [Text()](../Includes_and_Autodocs_3._guide/node0332.html)
		RPTAG_SoftStyle		style for text (see [graphics/text.h)](../Includes_and_Autodocs_3._guide/node05EC.html)
		RPTAG_APen		Primary rendering pen
		RPTAG_BPen		Secondary rendering pen
		RPTAG_DrMd 		Drawing mode (see [graphics/rastport.h)](../Includes_and_Autodocs_3._guide/node05D7.html)
		RPTAG_OutLinePen 	Area Outline pen
		RPTAG_WriteMask 	Bit Mask for writing.
		RPTAG_MaxPen 		Maximum pen to render (see [SetMaxPen()](../Includes_and_Autodocs_3._guide/node0324.html))

   INPUTS
	rp - pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to modify.
	tags - a standard tag list

   RESULT

   BUGS

   SEE ALSO
	[SetFont()](../Includes_and_Autodocs_3._guide/node0323.html) [SetSoftStyle()](../Includes_and_Autodocs_3._guide/node032D.html) [SetAPen()](../Includes_and_Autodocs_3._guide/node031E.html) [SetBPen()](../Includes_and_Autodocs_3._guide/node031F.html) [SetDrMd()](../Includes_and_Autodocs_3._guide/node0322.html) SetOutLinePen()
	[SetWriteMask()](../Includes_and_Autodocs_3._guide/node032E.html) [SetMaxPen()](../Includes_and_Autodocs_3._guide/node0324.html) [GetRPAttrA()](../Includes_and_Autodocs_3._guide/node02EB.html) [graphics/rpattr.h](../Includes_and_Autodocs_3._guide/node0663.html)


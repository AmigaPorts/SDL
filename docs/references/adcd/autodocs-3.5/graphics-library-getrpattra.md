---
title: graphics.library/GetRPAttrA
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getrpattra
functions: [GetAPen, GetBPen, GetDrMd, SetMaxPen, Text]
libraries: [graphics.library]
---

# graphics.library/GetRPAttrA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
       GetRPAttrA -- examine rastport settings via a tag list
	GetRPAttrs  -- varargs stub for GetRPAttrA

   SYNOPSIS

```c
       GetRPAttrA(rp,tags)
                  a0   a1
```
	void GetRPAttrA(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	GetRPAttrs(rp,attr1,&result1,...);

   FUNCTION
```c
       [Read](autodocs-3.5/dos-library-read-2.md) the settings of a rastport into variables. The
```
	ti_Tag field of the [TagItem](autodocs-3.5/include-utility-tagitem-h.md) specifies which attribute
	should be read, and the ti_Data field points at the
	location where the result hsould be stored. All current
	tags store the return data as LONGs (32 bits).

	currently available tags are:

		RPTAG_Font		Font for [Text()](autodocs-3.5/graphics-library-text-2.md)
		RPTAG_SoftStyle		style for text (see [graphics/text.h)](autodocs-3.5/include-graphics-text-h.md)
		RPTAG_APen		Primary rendering pen
		RPTAG_BPen		Secondary rendering pen
		RPTAG_DrMd 		Drawing mode (see [graphics/rastport.h)](autodocs-3.5/include-graphics-rastport-h.md)
		RPTAG_OutLinePen 	Area Outline pen
		RPTAG_WriteMask 	Bit Mask for writing.
		RPTAG_MaxPen 		Maximum pen to render (see [SetMaxPen()](autodocs-3.5/graphics-library-setmaxpen.md))
		RPTAG_DrawBounds	Determine the area that will be rendered
					into by rendering commands. Can be used
					to optimize window refresh. Pass a pointer
					to a rectangle in the tag data. On return,
					the rectangle's MinX will be greater than
					its MaxX if there are no active cliprects.

   INPUTS
	rp - pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to examine.
	tags - a standard tag list specifying the attributes to be read,
		and where to store their values.

   RESULT

   BUGS

   SEE ALSO
	[GetAPen()](autodocs-3.5/graphics-library-getapen.md) [GetBPen()](autodocs-3.5/graphics-library-getbpen.md) [GetDrMd()](autodocs-3.5/graphics-library-getdrmd.md) GetOutLinePen()
	[SetRPAttrA()](autodocs-3.5/graphics-library-setrpattra.md) [graphics/rpattr.h](autodocs-3.5/include-graphics-rpattr-h.md)

---

## See Also

- [GetAPen — graphics.library](../autodocs/graphics.library.md#getapen)
- [GetBPen — graphics.library](../autodocs/graphics.library.md#getbpen)
- [GetDrMd — graphics.library](../autodocs/graphics.library.md#getdrmd)
- [SetMaxPen — graphics.library](../autodocs/graphics.library.md#setmaxpen)
- [Text — graphics.library](../autodocs/graphics.library.md#text)

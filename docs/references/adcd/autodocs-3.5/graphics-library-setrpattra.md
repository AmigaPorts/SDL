---
title: graphics.library/SetRPAttrA
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setrpattra
functions: [SetAPen, SetBPen, SetDrMd, SetFont, SetMaxPen, SetSoftStyle, SetWriteMask, Text]
libraries: [graphics.library]
---

# graphics.library/SetRPAttrA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
       SetRPAttrA -- modify rastport settings via a tag list
	SetRPAttrs  -- varargs stub for SetRPAttrA

   SYNOPSIS

```c
       SetRPAttrA(rp,tags)
                  a0   a1
```
	void SetRPAttrA(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	SetRPAttrs(rp,tag,...);

   FUNCTION
       Modify settings of a rastport, based on the taglist passed.
	currently available tags are:

		RPTAG_Font		Font for [Text()](autodocs-3.5/graphics-library-text-2.md)
		RPTAG_SoftStyle		style for text (see [graphics/text.h)](autodocs-3.5/include-graphics-text-h.md)
		RPTAG_APen		Primary rendering pen
		RPTAG_BPen		Secondary rendering pen
		RPTAG_DrMd 		Drawing mode (see [graphics/rastport.h)](autodocs-3.5/include-graphics-rastport-h.md)
		RPTAG_OutLinePen 	Area Outline pen
		RPTAG_WriteMask 	Bit Mask for writing.
		RPTAG_MaxPen 		Maximum pen to render (see [SetMaxPen()](autodocs-3.5/graphics-library-setmaxpen.md))

   INPUTS
	rp - pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to modify.
	tags - a standard tag list

   RESULT

   BUGS

   SEE ALSO
	[SetFont()](autodocs-3.5/graphics-library-setfont-2.md) [SetSoftStyle()](autodocs-3.5/graphics-library-setsoftstyle-2.md) [SetAPen()](autodocs-3.5/graphics-library-setapen-2.md) [SetBPen()](autodocs-3.5/graphics-library-setbpen-2.md) [SetDrMd()](autodocs-3.5/graphics-library-setdrmd-2.md) SetOutLinePen()
	[SetWriteMask()](autodocs-3.5/graphics-library-setwritemask.md) [SetMaxPen()](autodocs-3.5/graphics-library-setmaxpen.md) [GetRPAttrA()](autodocs-3.5/graphics-library-getrpattra.md) [graphics/rpattr.h](autodocs-3.5/include-graphics-rpattr-h.md)

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
- [SetDrMd — graphics.library](../autodocs/graphics.library.md#setdrmd)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [SetMaxPen — graphics.library](../autodocs/graphics.library.md#setmaxpen)
- [SetSoftStyle — graphics.library](../autodocs/graphics.library.md#setsoftstyle)
- [SetWriteMask — graphics.library](../autodocs/graphics.library.md#setwritemask)
- [Text — graphics.library](../autodocs/graphics.library.md#text)

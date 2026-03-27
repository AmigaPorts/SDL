---
title: 16 / Creating a Font Requester / Specifying Options with TagItems
manual: libraries
chapter: libraries
section: 16-creating-a-font-requester-specifying-options-with
functions: []
libraries: []
---

# 16 / Creating a Font Requester / Specifying Options with TagItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As with a file requester, the font requester is specified with a [TagItem](libraries/37-tags-tag-functions-and-structures.md)
list.  There are several tags that are specific to the font requester:


  Font Requester
  Tag Name        Used For
  --------------  --------
  ASL_FontName    Default font ([fo_Attr](libraries/16-asl-library-creating-a-font-requester.md).ta_Name)
  ASL_FontHeight  Default font size ([fo_Attr](libraries/16-asl-library-creating-a-font-requester.md).ta_YSize)
  ASL_FontStyles  Default font style ([fo_Attr](libraries/16-asl-library-creating-a-font-requester.md).ta_Style)
  ASL_FontFlags   Default font flags ([fo_Attr](libraries/16-asl-library-creating-a-font-requester.md).ta_Flags)
  ASL_FrontPen    Default font color ([fo_FrontPen](libraries/16-asl-library-creating-a-font-requester.md))
  ASL_BackPen     Default font background color ([fo_BackPen](libraries/16-asl-library-creating-a-font-requester.md))
  ASL_ModeList    Alternate strings for the drawing mode gadget (see below)
  ASL_MinHeight   Minimum font height the requester will display
  ASL_MaxHeight   Maximum font height the requester will display


Note that the last two tags only limit the range of font sizes that the
font requester displays, the user is free to type in any value.

Font requesters have additional special options that are controlled
through the ASL_FuncFlags tag.  This tag works the same way as it does
with file requesters but with different options available.  Recall that
the data for this tag is divided into bit fields, each of which controls a
requester option.  The flags used with the ASL_FuncFlags tag in a font
requester are defined in <libraries/[asl.h](autodocs-2.0/includes-libraries-asl-h.md)>:


  Font Requester Flags  Used For
  --------------------  --------
  FONF_FRONTCOLOR       Enables font color selection gadgets
  FONF_BACKCOLOR        Enables font background color selection gadget
  FONF_STYLES           Enables font style selection gadget
  FONF_FIXEDWIDTH       Limits display to fixed width fonts only
  FONF_DRAWMODE         Enables font draw mode gadget


A simple font requester (one without any of the above FONF_ flags set)
only lets the user choose a font and a Y size.  Setting the flags above
adds options to the font requester.  FONF_FRONTCOLOR and FONF_BACKCOLOR
add color selection gadgets to the requester, one for choosing a font's
foreground color (labeled "Text") and the other for choosing the
background color (labeled "Field").  The font requester records the user's
setting in the [FontRequester](libraries/16-asl-library-creating-a-font-requester.md)'s fo_FrontPen and fo_BackPen fields.

FONF_STYLES sets up several gadgets to choose the style of the font (bold,
italics, underline).  The font requester saves these settings in the
[fo_Attr](libraries/16-asl-library-creating-a-font-requester.md).ta_Style bit field according to the style flags defined in
<graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>.  FONF_FIXEDWIDTH limits the font name display to fixed
width (non-proportional) fonts (note that this does not prevent the user
from typing in a proportional font name).

FONF_DRAWMODE adds a cycle gadget to the font requester so the user can
choose the draw mode.  The draw mode is saved in the requester's
[fo_DrawMode](libraries/16-asl-library-creating-a-font-requester.md) field.  The number stored there corresponds to the draw mode's
position in the gadget's cycle.

The draw mode cycle gadget initially is labeled "Mode" and has three
elements in its cycle: "JAM1", "JAM2", and "Complement".  These yield a
result of 0, 1, and 2, respectively.  It is possible to change the names
and number of draw modes with the ASL_ModeList tag.  This tag accepts a
pointer to an array of strings.  The first string replaces "Mode" as the
label for the draw mode cycle gadget.  The strings that follow replace the
elements of the cycle gadget.  The last entry in the array has to be NULL
to tell the requester where the list of entries ends.


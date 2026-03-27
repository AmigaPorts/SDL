---
title: The Font Requester
manual: amiga-mail
chapter: amiga-mail
section: the-font-requester
functions: [AllocAslRequest]
libraries: [asl.library]
---

# The Font Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The ASL library also contains a font requester.  The default font
requester consists of two scrolling lists, one containing font names, the
other containing font sizes.  Each scrolling list is accompanied by a
string gadget which lets the user type in the name and size of the font
they want.

   [Figure 2 - The FontReq.c font requester](amiga-mail/i-7-fontreq-ilbm.md) 

The font size string gadget (actually, an integer gadget) is especially
useful because it allows the user to type in a font size that doesn't
appear in the font size scrolling list.  If the font size the user
requests does not already exist in the system, the Amiga can generate the
font size the user requests either through bitmap scaling, or, if scalable
outline fonts are available, by scaling an outline font.

Using the font requester is similar to using the file requester.  First,
allocate a requester structure.  A font requester requires the
FontRequester structure:


struct FontRequester    {


```c
        APTR    fo_Reserved1[2];
        struct TextAttr fo_Attr;       /* Returned TextAttr            */
        UBYTE   fo_FrontPen;           /* Returned pens, if selected   */
        UBYTE   fo_BackPen;
        UBYTE   fo_DrawMode;
        APTR    fo_UserData;
        };
```
To allocate this structure, use AllocAslRequest() or AllocAslRequestTags()
with the first argument set to ASL_FontRequest.

There are several tags that are specific to the font requester:


    ASL_FontName
    ASL_FontHeight
    ASL_FontStyles
    ASL_FontFlags
    ASL_FrontPen
    ASL_BackPen
    ASL_MinHeight
    ASL_MaxHeight
    ASL_ModeList
The first six tags are used to place initial values into the FontRequester
structure.  They correspond respectively to the FontRequester's
fo_Attr.ta_Name, fo_Attr.ta_YSize, fo_Attr.ta_Style, fo_Attr.ta_Flags,
fo_FrontPen, and fo_BackPen fields.  ASL_MinHeight specifies the minimum Y
height that the font requester should list.  ASL_MaxHeight specifies the
maximum Y height that the font requester should list.  Note that these
tags only limit the range of font sizes that the font requester displays,
the user is free to type in any value.  The ASL_ModeList tag specifies the
strings used for the font requester's drawing mode gadget.  This is
discussed later in the chapter.

The are several options available to the font requester that are toggled
by setting flags with the ASL_FuncFlags tag.  These flags are:


    FONF_FRONTCOLOR
    FONF_BACKCOLOR
    FONF_STYLES
    FONF_FIXEDWIDTH
    FONF_DRAWMODE
A simple font requester (one without any of the above FONF_ flags set)
only lets the user choose a font and a Y size.  Setting the flags above
adds options to the font requester.  FONF_FRONTCOLOR and FONF_BACKCOLOR
add color selection gadgets to the requester, one for choosing a font's
foreground color (labeled ``Text'' on the requester) and the other for
choosing the backround color (labeled ``Field'').  The font requester
records the user's setting in the FontRequester's fo_FrontPen and
fo_BackPen fields.  FONF_STYLES sets up several gadgets to choose the
style of the font (bold, italics, underline).  The font requester saves
these setting in the fo_Attr.ta_Style bit field according to the style
flags defined in <graphics/text.h>.  FONF_FIXEDWIDTH limits the font name
display to fixed width (non-proportional) fonts (note that this does not
prevent the user from typing in a proportional font name).  FONF_DRAWMODE
adds a cycle gadget to the font requester so the user can choose the draw
mode.  The draw mode is saved in the requester's fo_DrawMode field.  The
number stored there corresponds to the draw mode's position in the
gadget's cycle.

The draw mode cycle gadget initially is labeled ``Mode'' and has three
elements in its cycle: ``JAM1'', ``JAM2'', and ``Complement''.  These
yield a result of 0, 1, and 2, respectively.  It is possible to change the
names and number of draw modes with the ASL_ModeList tag.  This tag
accepts a pointer to an array of strings.  The first string replaces
``Mode'' as the label for the draw mode cycle gadget.  The strings that
follow replace the elements of the cycle gadget.  The last entry in the
array has to be NULL to tell the requester where the list of entries ends.

The [FontReq.c](amiga-mail/i-7-fontreq-c.md) example illustrates how to use a font requester.

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)

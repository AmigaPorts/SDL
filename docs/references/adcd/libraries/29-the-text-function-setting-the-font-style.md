---
title: 29 / The Text Function / Setting the Font Style
manual: libraries
chapter: libraries
section: 29-the-text-function-setting-the-font-style
functions: [AskSoftStyle, OpenDiskFont, OpenFont, SetSoftStyle]
libraries: [diskfont.library, graphics.library]
---

# 29 / The Text Function / Setting the Font Style

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [OpenFont()](libraries/29-the-text-function-choosing-the-font.md) and [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) functions both search through the fonts
available to them, looking for the font that most closely matches the
[TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure.  If these functions can't find a font that matches
exactly, they will open the one with the same name that most closely
matches the TextAttr structure's [ta_YSize](libraries/29-the-text-function-choosing-the-font.md), [ta_Style](libraries/29-the-text-function-choosing-the-font.md), and [ta_Flags](libraries/29-the-text-function-choosing-the-font.md) fields
(in that order of preference).

If the font doesn't match your style choice exactly, it is possible to ask
the system to alter how it renders the font so it matches the style you
need.  The rastport contains some flags that tell the system's text
rendering functions to algorithmically add styles to characters as they
are rendered.  Currently, the system can add up to three styles to a font:
italics, bold, and underline.  The system cannot alter the style of a font
if the style is already intrinsic to the font.  For example, it is not
possible to add (or remove) the bold styling to a font if the font was
designed to be bolded.  There are two graphics.library functions that deal
with software font style setting:


```c
    ULONG AskSoftStyle( struct RastPort *rp );
    ULONG SetSoftStyle( struct RastPort *rp, ULONG newstyle,
                        ULONG enable );
```
The [AskSoftStyle()](autodocs-2.0/graphics-library-asksoftstyle.md) function returns a bitmask of the style bits available
to the rastport's current font.  The style bits are the same ones used by
the [TextAttr](libraries/29-the-text-function-choosing-the-font.md)'s [ta_Style](libraries/29-the-text-function-choosing-the-font.md) field (from <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>).  [SetSoftStyle()](autodocs-2.0/graphics-library-setsoftstyle.md)
changes the rastport's current software style setting according to the
style bits set in the newstyle field (from the function prototype above).

[SetSoftStyle()](autodocs-2.0/graphics-library-setsoftstyle.md) pays attention only to the bits of newstyle that have the
corresponding bit in the enable field set as well.  This function returns
the style, which is the combined result of previous soft style selection,
the effect of this function, and the style inherent in the set font.  The
following code fragment turns on the algorithmic font attributes for the
rastport (myrastport) based on those style attributes that were requested
in the [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) call (mytextattr.[ta_Style](libraries/29-the-text-function-choosing-the-font.md)) and not inherent in the
font.


```c
    /* Set the font and add software styling to the text if I asked for
       a style in OpenFont() and didn't get it.  Because most Amiga fonts
       do not have styling built into them (with the exception of the CG
       outline fonts), if the user selected some kind of styling for the
       text, it will have to be added algorithmically by calling
       SetSoftStyle().
    */
    if (myfont = OpenDiskFont(mytextattr))
    {
            SetFont(myrastport, myfont);
            SetSoftStyle(myrastport,
                         mytextattr.ta_Style ^ myfont->tf_Style,
                         (FSF_BOLD | FSF_UNDERLINED | FSF_ITALIC));
    ...
    ...
            CloseFont(myfont);
    }
```

---

## See Also

- [AskSoftStyle — graphics.library](../autodocs/graphics.library.md#asksoftstyle)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [SetSoftStyle — graphics.library](../autodocs/graphics.library.md#setsoftstyle)

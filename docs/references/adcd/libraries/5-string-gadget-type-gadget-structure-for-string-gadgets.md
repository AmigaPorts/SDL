---
title: 5 / String Gadget Type / Gadget Structure For String Gadgets
manual: libraries
chapter: libraries
section: 5-string-gadget-type-gadget-structure-for-string-gadgets
functions: [FontExtent]
libraries: [graphics.library]
---

# 5 / String Gadget Type / Gadget Structure For String Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To an application, a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget consists of a standard [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure
along with an entry buffer, an undo buffer and a number of extensions.

For a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget, set the [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure to
[GTYP_STRGADGET](libraries/5-intuition-gadgets-gadget-structure.md).  Set the [SpecialInfo](libraries/5-intuition-gadgets-gadget-structure.md) field to point to an instance of a
[StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) structure, which must be initialized by the application.

The [container](libraries/5-proportional-gadget-components-the-container.md) for a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget is its select box.  The application
specifies the size of the container.  As the user types into the string
gadget, the characters appear in the gadget's container.

[String](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets may hold more characters than are displayable in the
[container](libraries/5-proportional-gadget-components-the-container.md).  To use this feature, the application simply provides a buffer
that is larger than the number of characters that will fit in the
container.  This allows the user to enter and edit strings that are much
longer than the visible portion of the buffer.  Intuition maintains the
cursor position and scrolls the text in the container as needed.

The application may specify the justification of the string in the
[container](libraries/5-proportional-gadget-components-the-container.md).  The default is [GACT_STRINGLEFT](libraries/5-gadget-structure-gadget-activation-flags.md), or left justification.  If the
flag [GACT_STRINGCENTER](libraries/5-gadget-structure-gadget-activation-flags.md) is set, the text is center justified; if
[GACT_STRINGRIGHT](libraries/5-gadget-structure-gadget-activation-flags.md) is set, the text is right justified.

When the gadget is activated, the select box contents are redrawn,
including the background area.  If [GFLG_STRINGEXTEND](libraries/5-gadget-structure-gadget-flags.md) is set for the gadget
or the gadget is using a proportional font by default, then the entire
select box will be cleared regardless of the font size or
[StringInfo.MaxChars](libraries/5-string-gadget-type-stringinfo-structure.md) value.  For compatibility reasons, if the [string](libraries/5-intuition-gadgets-string-gadget-type.md)
gadget is not extended then the following conditions apply (see the
section on "[Extending String Gadgets](libraries/5-string-gadget-type-extended-string-gadgets.md)" for more information).

  * If the font is monospace (not proportional), the width of the gadget

    will be rounded down to an even multiple of the font width.
  * If the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget is left justified ([GACT_STRINGLEFT](libraries/5-gadget-structure-gadget-activation-flags.md)), a maximum

```c
    of [StringInfo.MaxChars](libraries/5-string-gadget-type-stringinfo-structure.md) times the font width pixels of space will be
    cleared.  Thus, if MaxChars is 3 (two characters plus the trailing
    NULL) and the font width is 8, then a maximum of 3 * 8 = 24 pixels
    will be cleared.  If the font defaults to a proportional font, then
    the width returned by [FontExtent()](libraries/29-graphics-library-and-text-does-the-text-fit.md) will be used as the character
    width.
```
No facilities are provided to place imagery within the select box of a
[string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget.

 [String Gadget Imagery and Highlighting](libraries/5-gadget-structure-for-string-gadgets-imagery-and.md) 

---

## See Also

- [FontExtent — graphics.library](../autodocs/graphics.library.md#fontextent)

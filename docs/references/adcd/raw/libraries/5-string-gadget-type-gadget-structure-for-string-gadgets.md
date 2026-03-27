# 5 / String Gadget Type / Gadget Structure For String Gadgets


To an application, a [string](../Libraries_Manual_guide/node0164.html) gadget consists of a standard [Gadget](../Libraries_Manual_guide/node0149.html) structure
along with an entry buffer, an undo buffer and a number of extensions.

For a [string](../Libraries_Manual_guide/node0164.html) gadget, set the [GadgetType](../Libraries_Manual_guide/node0149.html#line58) field in the [Gadget](../Libraries_Manual_guide/node0149.html) structure to
[GTYP_STRGADGET](../Libraries_Manual_guide/node0149.html#line66).  Set the [SpecialInfo](../Libraries_Manual_guide/node0149.html#line125) field to point to an instance of a
[StringInfo](../Libraries_Manual_guide/node016B.html) structure, which must be initialized by the application.

The [container](../Libraries_Manual_guide/node0159.html) for a [string](../Libraries_Manual_guide/node0164.html) gadget is its select box.  The application
specifies the size of the container.  As the user types into the string
gadget, the characters appear in the gadget's container.

[String](../Libraries_Manual_guide/node0164.html) gadgets may hold more characters than are displayable in the
[container](../Libraries_Manual_guide/node0159.html).  To use this feature, the application simply provides a buffer
that is larger than the number of characters that will fit in the
container.  This allows the user to enter and edit strings that are much
longer than the visible portion of the buffer.  Intuition maintains the
cursor position and scrolls the text in the container as needed.

The application may specify the justification of the string in the
[container](../Libraries_Manual_guide/node0159.html).  The default is [GACT_STRINGLEFT](../Libraries_Manual_guide/node014B.html#line87), or left justification.  If the
flag [GACT_STRINGCENTER](../Libraries_Manual_guide/node014B.html#line79) is set, the text is center justified; if
[GACT_STRINGRIGHT](../Libraries_Manual_guide/node014B.html#line83) is set, the text is right justified.

When the gadget is activated, the select box contents are redrawn,
including the background area.  If [GFLG_STRINGEXTEND](../Libraries_Manual_guide/node014A.html#line81) is set for the gadget
or the gadget is using a proportional font by default, then the entire
select box will be cleared regardless of the font size or
[StringInfo.MaxChars](../Libraries_Manual_guide/node016B.html#line49) value.  For compatibility reasons, if the [string](../Libraries_Manual_guide/node0164.html)
gadget is not extended then the following conditions apply (see the
section on "[Extending String Gadgets](../Libraries_Manual_guide/node016D.html)" for more information).

  * If the font is monospace (not proportional), the width of the gadget

    will be rounded down to an even multiple of the font width.
  * If the [string](../Libraries_Manual_guide/node0164.html) gadget is left justified ([GACT_STRINGLEFT](../Libraries_Manual_guide/node014B.html#line87)), a maximum

```c
    of [StringInfo.MaxChars](../Libraries_Manual_guide/node016B.html#line49) times the font width pixels of space will be
    cleared.  Thus, if MaxChars is 3 (two characters plus the trailing
    NULL) and the font width is 8, then a maximum of 3 * 8 = 24 pixels
    will be cleared.  If the font defaults to a proportional font, then
    the width returned by [FontExtent()](../Libraries_Manual_guide/node03DA.html#line15) will be used as the character
    width.
```
No facilities are provided to place imagery within the select box of a
[string](../Libraries_Manual_guide/node0164.html) gadget.

 [String Gadget Imagery and Highlighting](../Libraries_Manual_guide/node016A.html) 


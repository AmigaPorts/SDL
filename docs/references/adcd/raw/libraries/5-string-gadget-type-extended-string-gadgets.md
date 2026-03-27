# 5 / String Gadget Type / Extended String Gadgets


The [StringInfo](../Libraries_Manual_guide/node016B.html) structure may be extended by setting the [GFLG_STRINGEXTEND](../Libraries_Manual_guide/node014A.html#line81)
gadget flag and placing a pointer to a [StringExtend](../Includes_and_Autodocs_2._guide/node00E5.html#line18) structure in the
StringInfo [Extension](../Libraries_Manual_guide/node016B.html#line76) variable.  GFLG_STRINGEXTEND is available beginning
with V37, under V36 the application must use [GACT_STRINGEXTEND](../Libraries_Manual_guide/node014B.html#line108) to get the
same functionality.  Note that GACT_STRINGEXTEND is not ignored prior to
V36 and should only be set in V36 or later systems.  GFLG_STRINGEXTEND is
ignored prior to V37.


```c
    struct StringExtend
        {
        struct TextFont *Font;
        UBYTE       Pens[2];
        UBYTE       ActivePens[2];
        ULONG       InitialModes;
        struct Hook *EditHook;
        UBYTE       *WorkBuffer;
        ULONG       Reserved[4];
        };
```
Font

```c
    If a font is specified in the StringExtend structure, that font will
    be used by the gadget.  By default, the [string](../Libraries_Manual_guide/node0164.html) gadget inherits the
    font of the screen on which it appears.  Note that this is a pointer
    to an open font and not a pointer to a [TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure.

    Proportional fonts are supported in [string](../Libraries_Manual_guide/node0164.html) gadgets starting with
    Release 2. If the select box of the gadget is not tall enough to
    render the font, Intuition will fall back to topaz 8.
```
Pens

```c
    Pens specify the pens used to render the text while the gadget is
    inactive.  Pens[0] is the foreground (text) pen, Pens[1] is the
    background pen.
```
ActivePens

```c
    ActivePens specify the pens used to render the text while the gadget
    is active. ActivePens[0] is the foreground (text) pen, ActivePens[1]
    is the background pen.
```
InitialModes

```c
    These modes may be used in StringExtend structure InitialModes field.

    SGM_REPLACE
        If this flag is set, the [string](../Libraries_Manual_guide/node0164.html) gadget will be in replace or
        overwrite mode.  If this flag is cleared, the string gadget will
        be in insert mode.  In replace mode, characters entered
        overwrite the existing characters.  In insert mode, characters
        entered are inserted into the buffer and the following
        characters are advanced by one position until the buffer is
        full.  If the buffer is full in insert mode then characters may
        not be entered until some are deleted.

        When using this flag, always initialize [StringInfo](../Libraries_Manual_guide/node016B.html) with an
        in-range value of [BufferPos](../Libraries_Manual_guide/node016B.html#line54).  While most changes to gadgets
        require the application to first remove the gadget before
        modifying the gadget, this flag may be toggled without removing
        the gadget from the gadget list.  The change will take effect on
        the next character typed by the user.

    SGM_NOFILTER
        Don't filter control chars, enter them into the gadget as typed.
        In this mode the control character command keys for [string](../Libraries_Manual_guide/node0164.html)
        gadgets are not active.  If the user disables control character
        filtering from the IControl Preferences editor, there is no way
        for the application to turn it on for an individual string
        gadget.  In filter mode, control characters may be entered into
        the string by holding the left Amiga key while the character is
        entered.

        While most changes to gadgets require the application to first
        remove the gadget before modifying the gadget, this flag may be
        toggled without removing the gadget from the gadget list.  The
        change will take effect on the next character typed by the user.

    SGM_FIXEDFIELD
        Fixed length buffer used for editing, the user cannot shorten or
        lengthen the string through edit operations.  The field length
        is taken from the length of the character string in the buffer
        when the gadget is added to the system.  Fixed field mode
        modifies the meanings of many of the string editing keys, as
        explained in the tables above.  Always set SGM_REPLACE when
        using a fixed length buffer.

    SGM_EXITHELP
        Allows the help key to be heard by the application from within
        [string](../Libraries_Manual_guide/node0164.html) gadgets.  The gadget will exit immediately when the help
        key is pressed with the [IntuiMessage.Code](../Libraries_Manual_guide/node01D9.html#line33) set to 0x5F (new for
        V37).
```
EditHook and WorkBuffer

```c
    EditHook and WorkBuffer are used for custom string editing, which is
    [discussed below](../Libraries_Manual_guide/node016E.html).
```

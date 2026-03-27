# diskfont.library/OpenDiskFont



NAME

    OpenDiskFont - load and get a pointer to a disk font.
SYNOPSIS

```c
    font = OpenDiskFont(textAttr)
    D0                  A0
```
FUNCTION

```c
    This function finds the font with the specified textAttr on
    disk, loads it into memory, and returns a pointer to the font
    that can be used in subsequent [SetFont](../Includes_and_Autodocs_2._guide/node0479.html) and [CloseFont](../Includes_and_Autodocs_2._guide/node042E.html) calls.
    It is important to match this call with a corresponding
    [CloseFont](../Includes_and_Autodocs_2._guide/node042E.html) call for effective management of font memory.

    If the font is already in memory, the copy in memory is used.
    The disk copy is not reloaded.
```
INPUTS

```c
    textAttr - a [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) structure that describes the text font
            attributes desired.
```
RESULTS

    D0 is zero if the desired font cannot be found.
NOTES

```c
    As of V36, OpenDiskFont() will automatically attempt to
    construct a font for you if:

            You have requested a font size which does not exist
            as a designed font, and

            You have not set the DESIGNED bit in the ta_Flags
            field of the [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66), or [TTextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line73) struct.

    Constructed fonts are created by scaling a designed font.
    A designed font is one which typically resides on disk,
    or in ROM (e.g., a font which has been designed by hand
    using a drawing tool).  Designed fonts generally look better
    than fonts constructed by the font scaler, but designed
    fonts also require disk space for each font size.

    Always set the DESIGNED bit if you do not want constructed fonts,
    or use [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) to find out which font sizes already exist.
```
BUGS

```c
    This routine will not work well with font names whose file
    name components are longer than the maximum allowed
    (30 characters).
```

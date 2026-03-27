# graphics.library/SetFont



NAME

```c
    SetFont -- Set the text font and attributes in a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    SetFont(rp, font)
            A1   A0

    void SetFont(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *);
```
FUNCTION

```c
    This function sets the font in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to that described
    by font, and updates the text attributes to reflect that
    change.  This function clears the effect of any previous
    soft styles.
```
INPUTS

```c
    rp   - the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) in which the text attributes are to be changed
    font - pointer to a [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) structure returned from [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)
           or [OpenDiskFont()](../Includes_and_Autodocs_2._guide/node01F7.html)
```
RESULT

NOTES

```c
    This function had previously been documented that it would
    accept a null font.  This practice is discouraged.
    o   Use of a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) with a null font with text routines has
        always been incorrect and risked the guru.
    o   Keeping an obsolete font pointer in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) is no more
        dangerous than keeping a zero one there.
    o   SetFont(rp, 0) causes spurious low memory accesses under
        some system software releases.

    As of V36, the following Amiga font variants are no longer
    directly supported:
        fonts with NULL tf_CharSpace and non-NULL tf_CharKern.
        fonts with non-NULL tf_CharSpace and NULL tf_CharKern.
        fonts with NULL tf_CharSpace and NULL tf_CharKern with
            a tf_CharLoc size component greater than tf_XSize.
    Attempts to SetFont these one of these font variants will
    cause the system to modify your font to make it acceptable.
```
BUGS

```c
    Calling SetFont() on in-code TextFonts (ie fonts not
    OpenFont()ed) will result in a loss of 24 bytes from
    the system as of V36.
    This can be resolved by calling [StripFont()](../Includes_and_Autodocs_2._guide/node0480.html).
```
SEE ALSO

```c
    [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)  [StripFont()](../Includes_and_Autodocs_2._guide/node0480.html)
    [diskfont.library/OpenDiskFont()](../Includes_and_Autodocs_2._guide/node01F7.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```

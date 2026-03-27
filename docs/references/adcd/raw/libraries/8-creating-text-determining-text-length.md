# 8 / Creating Text / Determining Text Length


To determine the pixel length of a given [IntuiText](../Libraries_Manual_guide/node01C7.html) string, call the
[IntuiTextLength()](../Includes_and_Autodocs_2._guide/node0222.html) function.


```c
    LONG IntuiTextLength( struct IntuiText *iText );
```
Set the iText argument to point to the [IntuiText](../Libraries_Manual_guide/node01C7.html) structure whose length is
to be found.  This function will return the length of the iText text
string in pixels.  Note that if the [ITextFont](../Libraries_Manual_guide/node01C7.html#line59) field of the given IntuiText
is set to NULL, or Intuition cannot access the specified font, then
[GfxBase->DefaultFont](../Includes_and_Autodocs_2._guide/node00AE.html#line24) will be used in determining the length of the text.
This may not be the same as the [RastPort](../Libraries_Manual_guide/node034A.html) font with which the text would be
printed.


# 8 / Creating Text / Fonts


The application may choose to specify the font used in rendering the
[IntuiText](../Libraries_Manual_guide/node01C7.html), or it may choose to use the default font for the system.

To use the default font, set the [ITextFont](../Libraries_Manual_guide/node01C7.html#line59) field to NULL.  Some care must
be taken when using the default font.  When an [IntuiText](../Libraries_Manual_guide/node01C7.html) object is
rendered and no font is specified, the text will be rendered in the font
set in the [RastPort](../Libraries_Manual_guide/node034A.html).

If the [RastPort](../Libraries_Manual_guide/node034A.html) font is NULL, the text will be rendered using
[GfxBase->DefaultFont](../Includes_and_Autodocs_2._guide/node00AE.html#line24).  Also, [IntuiTextLength()](../Libraries_Manual_guide/node01C9.html) always uses
GfxBase->DefaultFont when [ITextFont](../Libraries_Manual_guide/node01C7.html#line59) is NULL.  The application must have
open the graphics library in order to check the default font in GfxBase.
(See the [graphics library](../Libraries_Manual_guide/node03D2.html) chapter for more information.)

To use a specific font for this text, place a pointer to an initialized
[TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure in the [ITextFont](../Libraries_Manual_guide/node01C7.html#line59) field.  Intuition will only use the
specified font if it is available through a call to the [OpenFont()](../Libraries_Manual_guide/node03D6.html#line5)
routine.  To use a font from disk, the application must first open the
font using the [OpenDiskFont()](../Libraries_Manual_guide/node03D6.html#line5) function.  For more information about using
fonts, see the "[Graphics Library and Text](../Libraries_Manual_guide/node03D6.html)" chapter in this manual.


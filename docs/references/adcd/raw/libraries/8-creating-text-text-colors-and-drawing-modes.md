# 8 / Creating Text / Text Colors and Drawing Modes


[IntuiText](../Libraries_Manual_guide/node01C7.html) gets its colors from the values set in the color registers for
the screen in which they are rendered.  The available number of colors and
palette settings are screen attributes and cannot be changed through
IntuiText rendering.

Text characters in general are made up of two areas: the character image
itself and the background area surrounding the character image.  The color
used in each area is determined by the draw mode which can be set to [JAM1](../Libraries_Manual_guide/node01C7.html#line26),
[JAM2](../Libraries_Manual_guide/node01C7.html#line29) or [COMPLEMENT](../Libraries_Manual_guide/node01C7.html#line33).  The flag [INVERSVID](../Libraries_Manual_guide/node01C7.html#line37) may also be specified.

[JAM1](../Libraries_Manual_guide/node01C7.html#line26) draw mode renders each character with [FrontPen](../Libraries_Manual_guide/node01C7.html#line16) and leaves the
background area unaffected.  Because the background of a character is not
drawn, the pixels of the destination memory  around the character image
are not disturbed.  Graphics beneath the text will be visible in the
background area of each character cell.

[JAM2](../Libraries_Manual_guide/node01C7.html#line29) draw mode renders each character with [FrontPen](../Libraries_Manual_guide/node01C7.html#line16) and renders each
character background with [BackPen](../Libraries_Manual_guide/node01C7.html#line19).  Using this mode, any graphics that
previously appeared beneath the character cells will be totally
overwritten.

[COMPLEMENT](../Libraries_Manual_guide/node01C7.html#line33) draw mode renders the pixels of each character as the binary
complement of the color that is currently at the destination pixel.  The
destination is the display memory where the text is drawn.  As with [JAM1](../Libraries_Manual_guide/node01C7.html#line26),
nothing is drawn into the background.  [FrontPen](../Libraries_Manual_guide/node01C7.html#line16) and [BackPen](../Libraries_Manual_guide/node01C7.html#line19) are not used
in COMPLEMENT mode.  To determine the complement color, invert all the
bits in the binary representation of the color register number.  The
resulting number specifies the color register to use for that pixel.  In a
three bitplane display, for example, color 6 (110 in binary) is the
complement of color 1 (001 in binary).

The [INVERSVID](../Libraries_Manual_guide/node01C7.html#line37) flag inverses the video for each of the drawing modes.  For
[JAM1](../Libraries_Manual_guide/node01C7.html#line26), nothing is drawn into the character area and the background is drawn
in [FrontPen](../Libraries_Manual_guide/node01C7.html#line16).  For [JAM2](../Libraries_Manual_guide/node01C7.html#line29), the character area is drawn in [BackPen](../Libraries_Manual_guide/node01C7.html#line19) and the
background is drawn in FrontPen.  For [COMPLEMENT](../Libraries_Manual_guide/node01C7.html#line33) mode, nothing is drawn
into the character area and the background is complemented.


# 8 / Creating Text / Directly Drawing the IntuiText


Use the [PrintIText()](../Includes_and_Autodocs_2._guide/node023D.html) call to directly draw the text into the target
[RastPort](../Libraries_Manual_guide/node034A.html) of a window or screen.


```c
    void PrintIText( struct RastPort *rp, struct IntuiText *iText,
                     long left, long top );
```
The rp argument is a pointer to the [RastPort](../Libraries_Manual_guide/node034A.html) into which the text should be
drawn.  This RastPort can come from a [Window](../Libraries_Manual_guide/node0121.html) or [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure.

The iText argument is a pointer to a list of [IntuiText](../Libraries_Manual_guide/node01C7.html) structures which
are to be rendered.  The list may contain a single IntuiText structure.
If the font is not specified in the IntuiText structure, Intuition will
render the text using the [RastPort](../Libraries_Manual_guide/node034A.html)'s font.

The left and top arguments give the external component, or base position
for this list of [IntuiText](../Libraries_Manual_guide/node01C7.html) structures.  The [LeftEdge](../Libraries_Manual_guide/node01C7.html#line42) and [TopEdge](../Libraries_Manual_guide/node01C7.html#line42) values in
each IntuiText structure are added to these to determine the final
position of the text.

[IntuiText](../Libraries_Manual_guide/node01C7.html) objects may also be drawn indirectly by attaching them to
gadgets, menus or requesters.


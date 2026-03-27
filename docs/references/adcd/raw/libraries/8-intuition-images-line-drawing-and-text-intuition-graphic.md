# 8 Intuition Images, Line Drawing and Text / Intuition Graphic Objects


Intuition graphic objects are easy to create and economical to use.  There
are just three basic types of graphic objects you can use yet these three
types cover most rendering needs:

[Image](../Libraries_Manual_guide/node01BA.html)

    Images are graphic objects that can contain any imagery.  They
    consist of a rectangular bitmap that can be any size and describes
    each individual pixel to be displayed.
[Border](../Libraries_Manual_guide/node01C1.html)

    Borders are connected lines of any length and number, drawn between
    an arbitrary series of points.  They consist of a series of two
    dimensional coordinates that describe the points between which lines
    will be drawn.
[IntuiText](../Libraries_Manual_guide/node01C7.html)

    IntuiText strings are text strings of any length drawn in any font.
    They consist of a text string and font specification that describes
    the text to be rendered.
Each of these three objects may be chained together with other members of
the same type.  For instance, many lines of text may be rendered as a
single object by linking many instances of [IntuiText](../Libraries_Manual_guide/node01C7.html) objects together.
Only objects of the same type may be linked.

Any of these types can be rendered into any of the Intuition display
elements (window, requester, menu, etc.).  In fact, the application can
often display the same structure in more than one position or more than
one of the elements at the same time.

 [Displaying Images, Borders and IntuiText](../Libraries_Manual_guide/node01B7.html) 
 [Positioning Graphic Objects](../Libraries_Manual_guide/node01B8.html) 


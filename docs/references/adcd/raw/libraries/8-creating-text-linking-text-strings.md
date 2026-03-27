# 8 / Creating Text / Linking Text Strings


The [NextText](../Libraries_Manual_guide/node01C7.html#line66) field can point to another instance of an [IntuiText](../Libraries_Manual_guide/node01C7.html)
structure.  This allows the application to create a complex object which
has several distinct groups of characters, each with its own color, font,
location, and drawing mode.  This can be used to create multiple lines of
text, to position characters in the text very accurately and to change the
color or font of the text.  Each list of IntuiText objects may be drawn
with one call to [PrintIText()](../Libraries_Manual_guide/node01C8.html), or attached to a gadget, menu or requester
as a single object.


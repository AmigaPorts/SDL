# 8 / Graphic Objects / Displaying Images, Borders and IntuiText


Images, Borders and IntuiText objects may be directly or indirectly
rendered into the display by the application.  The application can draw
these objects directly into windows or screens by using one of the
functions [DrawImage()](../Libraries_Manual_guide/node01BB.html), [DrawBorder()](../Libraries_Manual_guide/node01C2.html) or [PrintIText()](../Libraries_Manual_guide/node01C8.html).  The application
supplies the appropriate pointer to a [Border](../Libraries_Manual_guide/node01C1.html), [Image](../Libraries_Manual_guide/node01BA.html) or [IntuiText](../Libraries_Manual_guide/node01C7.html) structure
as an argument to the function, as well as position information and a
pointer to the correct [RastPort](../Libraries_Manual_guide/node034A.html).  These rendering functions are discussed
in more detail below.

The application can also draw these objects indirectly by attaching them
to a menu, gadget or requester.  As Intuition places these elements on the
display, it also renders the associated graphics.  The [Requester](../Libraries_Manual_guide/node01AB.html#line72), [Gadget](../Libraries_Manual_guide/node0149.html#line91),
and [MenuItem](../Libraries_Manual_guide/node019A.html#line47) structures contain one or more fields reserved for rendering
information.  See the specific chapters on these items for information on
attaching graphical objects to them.


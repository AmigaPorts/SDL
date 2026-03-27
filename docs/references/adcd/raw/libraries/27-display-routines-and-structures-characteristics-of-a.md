# 27 / Display Routines and Structures / Characteristics of a Viewport


To describe a [ViewPort](../Libraries_Manual_guide/node032B.html#line59) fully, you need to set the following parameters:
height, width, depth and display mode.

In addition to these parameters, you must tell the system the location in
memory from which the data for the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) display should be retrieved
(by associating with it a [BitMap](../Libraries_Manual_guide/node032B.html#line74) structure) and how to position the final
ViewPort display on the screen. The ViewPort will take on the user's
default Workbench colors unless otherwise instructed with a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4).  See
the section called "[Preparing the ColorMap Structure](../Libraries_Manual_guide/node0331.html)" for more information.


# 27 Graphics Primitives / Drawing Routines


Most of the graphics drawing routines require information about how the
drawing is to take place.  For this reason, most graphics drawing routines
use a data structure called a [RastPort](../Libraries_Manual_guide/node034A.html), that contains pointers to the
drawing area and drawing variables such as the current pen color and font
to use.  In general, you pass a pointer to your RastPort structure as an
argument whenever you call a drawing function.

 [The RastPort Structure](../Libraries_Manual_guide/node034A.html) 
 [Using the Graphics Drawing Routines](../Libraries_Manual_guide/node0355.html) 
 [Performing Data Move Operations](../Libraries_Manual_guide/node0360.html) 


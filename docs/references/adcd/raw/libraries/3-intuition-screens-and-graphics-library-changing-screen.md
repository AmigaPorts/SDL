# 3 / Intuition Screens and Graphics Library / Changing Screen Colors


Screen colors are set at the time the screen is opened with the [SA_Colors](../Libraries_Manual_guide/node00E5.html#line111)
tag.  If the colors need to be changed after the screen is opened, the
graphics library function, LoadRGB4() should be used.  To change a single
entry in the color table, use SetRGB4() and SetRGB4CM().  See the
"[Graphics Primitives](../Libraries_Manual_guide/node0331.html)" chapter for more information on these functions.


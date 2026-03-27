# 4 / Window Structures and Functions / Graphics and Text in Windows


Applications can call functions in both the graphics library and the
Intuition library to render images, lines, text and other graphic elements
in windows.  The graphics library provides primitive operations such as
area fill, line drawing, text and animation.

The number of colors and the palette available in a window are defined by
the screen in which the window opens.  Applications should never change
the palette of a screen unless the screen is a custom screen created by
the application.

Graphics rendered into the window should respect the drawing pens defined
for the screen.  See the section on "[DrawInfo and the 3D Look](../Libraries_Manual_guide/node00EC.html)" in the
"Intuition Screens" chapter for more information.

Default window fonts come from one of two places, depending on the screen
on which the window opens.  The window title font is always taken from the
screen font.  If the screen is opened with a font specified, either by
specifying the tag [SA_Font](../Libraries_Manual_guide/node00E5.html#line125) or the variable [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Font, then
[Window.RPort](../Libraries_Manual_guide/node0121.html#line66)->Font is taken from the screen's font.  Otherwise, the
window's rastport's font is taken from [GfxBase->DefaultFont](../Includes_and_Autodocs_2._guide/node00AE.html#line24). This
information is available to the application if it opened the screen.

If the application did not open the screen, it has no way of knowing which
font has been used for the window.  Applications that require to know the
window's font before the window is open must explicitly set the font
(using [SetFont()](../Libraries_Manual_guide/node03D6.html)) for that window after opening it.  In this case, the
application may use any font it desires.  It is recommended that
applications use the screen's font if they support proportional fonts, and
[GfxBase->DefaultFont](../Includes_and_Autodocs_2._guide/node00AE.html#line24) otherwise, as these fonts are generally the user's
preference.

Intuition also provides a minimal high level interface to some of the
functions in the Graphics library.  This includes calls to draw lines,
text and images.  See the chapter entitled
"[Intuition Images, Line Drawing and Text](../Libraries_Manual_guide/node01B5.html)," for more information about
using Intuition to render graphics.


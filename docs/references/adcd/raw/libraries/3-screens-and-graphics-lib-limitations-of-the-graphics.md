# 3 / Screens and Graphics Lib / Limitations of the Graphics Subsystem


If each of the visible screens does not have the same physical attributes,
it may not be possible to display the data in its proper screen mode.
Screen coercion is the technique that allows multiple screens with
differing physical attributes to be displayed simultaneously.  When a
coerced screen is visible, its aspect ratio and colors may appear
significantly changed.  This is normal and the screen will be displayed
correctly when it is the frontmost screen.

Hardware restrictions prevent certain types of displays.  For instance,
screens always use the full width of the display, regardless of the width
of the overscan rectangle.  This prevents any changes in display mode
within a video line.  Other modes, such as the VGA modes, require specific
revisions of the custom chips and may not be available on all machines.
See the "[Graphics Primitives](../Libraries_Manual_guide/node0321.html)" chapter and the Amiga [Hardware](../Hardware_Manual_guide/node006F.html) Reference
Manual for more information on Amiga display organization and limitations.


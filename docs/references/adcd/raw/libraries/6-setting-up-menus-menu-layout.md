# 6 / Setting Up Menus / Menu Layout


The Amiga allows great flexibility in the specification of fonts for the
display.  Default fonts are chosen by the user to suit their particular
requirements and display resolution.  The application should, where
possible, use one of the preferred fonts.

If the application did not open its own screen and completely specify the
font for that screen, it must perform dynamic menu layout.  This is
because the [Menu](../Libraries_Manual_guide/node0199.html) structure does not specify font.  The menu header always
uses the screen font and the program should update the size and position
of these items at runtime to reflect the font.

The font for menu items may be specified in the [MenuItem](../Libraries_Manual_guide/node019A.html) structure,
allowing the programmer to hard code values for the font, size and
position of these items.  This is not recommended.  A specific font, while
ideal on one system, may be less than ideal on another display type.  Use
the preferred font wherever possible.

If the application does its own menu layout, it must use great care to
handle the font in the menu strip and the font in each item or sub-item.
The code should also keep items from running off the edges of the screen.

See the description of [ItemFill](../Libraries_Manual_guide/node019A.html#line47) in the section "[MenuItem Structure](../Libraries_Manual_guide/node019A.html)" below
for information on the positioning of multiple [IntuiText](../Libraries_Manual_guide/node01C7.html) or [Image](../Libraries_Manual_guide/node01BA.html)
structures within the menu item.

Applications should use the GadTools library menu layout routines whenever
possible, rather than performing their own layout.  See the chapter on the
"[GadTools Library](../Libraries_Manual_guide/node024E.html)" for more details.


---
title: 6 / Setting Up Menus / Menu Layout
manual: libraries
chapter: libraries
section: 6-setting-up-menus-menu-layout
functions: []
libraries: []
---

# 6 / Setting Up Menus / Menu Layout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga allows great flexibility in the specification of fonts for the
display.  Default fonts are chosen by the user to suit their particular
requirements and display resolution.  The application should, where
possible, use one of the preferred fonts.

If the application did not open its own screen and completely specify the
font for that screen, it must perform dynamic menu layout.  This is
because the [Menu](libraries/6-menu-data-structures-menu-structure.md) structure does not specify font.  The menu header always
uses the screen font and the program should update the size and position
of these items at runtime to reflect the font.

The font for menu items may be specified in the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure,
allowing the programmer to hard code values for the font, size and
position of these items.  This is not recommended.  A specific font, while
ideal on one system, may be less than ideal on another display type.  Use
the preferred font wherever possible.

If the application does its own menu layout, it must use great care to
handle the font in the menu strip and the font in each item or sub-item.
The code should also keep items from running off the edges of the screen.

See the description of [ItemFill](libraries/6-menu-data-structures-menuitem-structure.md) in the section "[MenuItem Structure](libraries/6-menu-data-structures-menuitem-structure.md)" below
for information on the positioning of multiple [IntuiText](libraries/8-creating-text-intuitext-structure.md) or [Image](libraries/8-creating-images-image-structure.md)
structures within the menu item.

Applications should use the GadTools library menu layout routines whenever
possible, rather than performing their own layout.  See the chapter on the
"[GadTools Library](libraries/15-gadtools-library-gadtools-menus.md)" for more details.


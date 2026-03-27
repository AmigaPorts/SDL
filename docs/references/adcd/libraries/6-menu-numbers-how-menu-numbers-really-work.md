---
title: 6 / / Menu Numbers / How Menu Numbers Really Work
manual: libraries
chapter: libraries
section: 6-menu-numbers-how-menu-numbers-really-work
functions: []
libraries: []
---

# 6 / / Menu Numbers / How Menu Numbers Really Work

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following is a description of how menu numbers really work.  It should
clarify why there are some restrictions on the number of menu components
Intuition allows.  Programs should not rely on the information given here
to access menu number information directly though.  Always use the
Intuition menu macros to handle menu numbers.

For convenience you should use the menus supplied.  For example, to
extract the item number from the menu number, call the macro
[ITEMNUM](libraries/6-setting-up-menus-menu-numbers.md)(menu_number); to construct a menu number, call the macro
[FULLMENUNUM](libraries/6-intuition-menus-other-menu-macros.md)(menu, item, sub).  See the section at the end of this chapter
for a more complete description of the [menu number macros](libraries/6-intuition-menus-other-menu-macros.md).

Menu numbers are 16-bit numbers with 5 bits used for the menu number, 6
bits used for the menu item number, and 5 bits used for the sub-item
number.  The three numbers only have meaning when used together to
determine the position of the item or sub-item selected.


bit 15 (MSB)                                                 bit 0 (LSB)
    _______________________________________________________________
   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   |                   |                       |                   |
   |These bits are for |   These bits are for  |  These bits are   |
   |the Sub-items with-|     the Menu Items    |   for the Menu    |
   |in the Menu Items  |     within the Menu   |       number      |
   |                   |                       |                   |
   |___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|


The value "all bits on" means that no selection of this particular
component was made.  [MENUNULL](libraries/6-setting-up-menus-menu-numbers.md) actually equals "no selection of any of the
components was made" so MENUNULL always equals "all bits of all components
on."

For example, suppose that the program gets back the menu number (in
hexadecimal) 0x0CA0.  In binary that equals:



bit 15 (MSB)                                                 bit 0 (LSB)
    _______________________________________________________________
   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   |                   |                       |                   |
   |                   |                       |                   |
   | 0   0   0   0   1 | 1   0   0   1   0   1 | 0   0   0   0   0 |
   |                   |                       |                   |
   |                   |                       |                   |
   |___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|



```c
     Sub_Item number=1    Menu Item number=37      Menu number=0
```
Again, the application should not examine these numbers directly. Use the
macros described above to ensure proper menu handling.


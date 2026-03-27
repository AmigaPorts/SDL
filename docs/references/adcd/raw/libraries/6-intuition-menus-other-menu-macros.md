# 6 Intuition Menus / Other Menu Macros


The [MENUNEM()](../Libraries_Manual_guide/node0188.html#line7), [ITEMNUM()](../Libraries_Manual_guide/node0188.html#line7) and [SUBNUM()](../Libraries_Manual_guide/node0188.html#line7) macros let an application break a
menu number down into its component parts--the specific menu number, the
item number and the sub-item number.  (See the section on "[Menu Numbers](../Libraries_Manual_guide/node0188.html)"
earlier in this chapter for details.)  Intuition also supplies macros that
allow an application to construct a menu number given its components:

SHIFTMENU(n)

    Create a properly masked and shifted specific menu number.
SHIFTITEM(n)

    Create a properly masked and shifted item number.
SHIFTSUB(n)

    Create a properly masked and shifted sub-item number.
FULLMENUNUM( menu, item, sub )

    Create a complete composite menu number from its components.

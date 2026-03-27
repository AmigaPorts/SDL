# 6 / Setting Up Menus / Help Key Processing in Menus


If the window is opened with the [WA_MenuHelp](../Libraries_Manual_guide/node0125.html#line142) tag, then user selection of
the help key while menus are displayed will be detected.  This tag is only
available under V37 and later.

When the user presses the Help key while using the menu system, the menu
selection is terminated and an [IDCMP_MENUHELP](../Libraries_Manual_guide/node01DE.html#line21) event is sent.  The
IDCMP_MENUHELP event is sent in place of the [IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) event, not in
addition to it.  IDCMP_MENUHELP never come as multi-select items, and the
event terminates the menu processing session.

The routine that handles the [IDCMP_MENUHELP](../Libraries_Manual_guide/node01DE.html#line21) events must be very
careful--it can receive menu information that is impossible under
[IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html).  IDCMP_MENUHELP events may be sent for any menu, item or
sub-item in the menu strip, regardless of its state or position in the
list.  The program may receive events for items that are disabled or
ghosted.  IDCMP_MENUHELP events may send the menu header number alone, or
the menu and item numbers, or all three components regardless of the items
linked to the selected menu or item.  This is done because it is
reasonable for a user to request help in a disabled item or a menu header.
If the user requests menu help on a disabled menu item or sub-item, try to
explain to the user why that item is disabled and what steps are necessary
to enable it.  For instance, pressing help while a menu header is
highlighted will trigger an IDCMP_MENUHELP event with a code that has a
valid number for the menu, then [NOITEM](../Libraries_Manual_guide/node0188.html#line20) and [NOSUB](../Libraries_Manual_guide/node0188.html#line20) (IDCMP_MENUPICK would
receive [MENUNULL](../Libraries_Manual_guide/node0188.html#line20) in this case.)

The application should not take the action indicated by the [IDCMP_MENUHELP](../Libraries_Manual_guide/node01DE.html#line21)
event, it should provide the user with a description of the use or status
of that menu.  The application should never step through the [NextSelect](../Libraries_Manual_guide/node019A.html#line93)
chain when it receives a IDCMP_MENUHELP event.


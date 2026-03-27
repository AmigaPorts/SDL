# Iconifying


Although the zoom gadget provides a pseudo-iconifying feature, the
Workbench's AppIcon and AppMenuItem features provide true iconification.
To iconify a window, create the AppIcon or AppMenuItem that will replace
the window.  Next, store the state of the window (like its current
position or the state of its gadgets), so the application can restore the
window to its original state when the application reopens it.  Now close
the window. Because it is possible for the AddAppIcon() or
AddAppMenuItem() function to fail, It is important to create the AppIcon
or AppMenuItem before closing the window.  If an application closes the
window first and Workbench can't create the AppIcon or AppMenuItem, there
will be no AppIcon or AppMenuItem for the user to select to uniconify the
window.

An application can set up a gadget or menu item so the user can tell the
application to iconify the window.  If the application uses a gadget to
iconify, it should not put the gadget in the window border because there
is no standard "look" to what an iconify gadget should look like.

The last example, [hide.c](../AmigaMail_Vol2_guide/node01B8.html), shows how to use AppIcons and AppMenuItems to
iconify a window.

   [hide.h](../AmigaMail_Vol2_guide/node01B9.html) 


# AppMenuItems


Using the workbench.library's AddAppMenuItem() call, an application can
add an AppMenuItem to the Workbench's "Tools" menu.  This AppAdd function
has one parameter unique to it, menutext (from the prototype above).  It
points to the string that appears in the "Tools" menu.

An AppMenuItem performs the same functions as an AppIcon or AppWindow, but
it does not require the overhead of a DiskObject or a window.  It also
does not require the user to drop icons on an object.  In some cases, the
user might prefer to use an AppMenuItem over an AppIcon or AppWindow
because the user doesn't have to shuffle around the Workbench windows to
get to the "Tools" menu.  Note that in older versions of release 2.0,
Workbench did not supply a list of WBArgs when the user selected an
AppMenuItem.

The C source code example [AppMenu.c](../AmigaMail_Vol2_guide/node01B5.html) at the end of this article is a simple
example of how to create an AppMenuItem.


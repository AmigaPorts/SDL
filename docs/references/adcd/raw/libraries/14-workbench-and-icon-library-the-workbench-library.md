# 14 Workbench and Icon Library / The Workbench Library


Workbench arguments are sent to an application when it is started. There
are also special facilities in Release 2 of Workbench that allow an
application that is already running to get additional arguments.  These
special facilities are known as AppWindow, AppIcon and AppMenuItem.

An [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line142) is a special kind of window that allows the user to drag
icons into it.  Applications that set up an AppWindow will receive a
message from Workbench whenever the user moves an icon into the AppWindow.
The message contains the name of the file or directory that the icon
represents.

An [AppIcon](../Includes_and_Autodocs_2._guide/node0135.html#line142) is similar to an AppWindow.  It is a special type of icon that
allows the user to drag other icons on top of it.  Like AppWindows, an
application that sets up an AppIcon will receive a message from Workbench
whenever the user moves another icon on top of the AppIcon.  The message
contains the name of the file or directory that the moved icon represents.

An [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line142) allows an application to add a custom menu item to the
usual set of menu choices supported by Workbench.  An application that
sets up an AppMenuItem will receive a message from Workbench whenever the
user picks that item from the Workbench menus.

When an application receives the messages described above, the message
will include struct [WBArg](../Libraries_Manual_guide/node023E.html#line40) *am_ArgList containing the names ([wa_Name](../Libraries_Manual_guide/node023E.html#line49)) and
directory locks ([wa_Lock](../Libraries_Manual_guide/node023E.html#line49)) of all selected icons that were passed as
arguments by the user.  This am_ArgList has the same format as the
[sm_ArgList](../Libraries_Manual_guide/node023E.html#line36) of a [WBStartup](../Libraries_Manual_guide/node023E.html) message.

 [Workbench Library Functions](../Libraries_Manual_guide/node0246.html)    [An AppMenuItem Example](../Libraries_Manual_guide/node05C1.html) 
 [An AppIcon Example](../Libraries_Manual_guide/node05C0.html)             [An AppWindow Example](../Libraries_Manual_guide/node05C2.html) 


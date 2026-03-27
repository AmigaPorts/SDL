---
title: 14 Workbench and Icon Library / The Workbench Library
manual: libraries
chapter: libraries
section: 14-workbench-and-icon-library-the-workbench-library
functions: []
libraries: []
---

# 14 Workbench and Icon Library / The Workbench Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Workbench arguments are sent to an application when it is started. There
are also special facilities in Release 2 of Workbench that allow an
application that is already running to get additional arguments.  These
special facilities are known as AppWindow, AppIcon and AppMenuItem.

An [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) is a special kind of window that allows the user to drag
icons into it.  Applications that set up an AppWindow will receive a
message from Workbench whenever the user moves an icon into the AppWindow.
The message contains the name of the file or directory that the icon
represents.

An [AppIcon](autodocs-2.0/includes-workbench-workbench-h.md) is similar to an AppWindow.  It is a special type of icon that
allows the user to drag other icons on top of it.  Like AppWindows, an
application that sets up an AppIcon will receive a message from Workbench
whenever the user moves another icon on top of the AppIcon.  The message
contains the name of the file or directory that the moved icon represents.

An [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) allows an application to add a custom menu item to the
usual set of menu choices supported by Workbench.  An application that
sets up an AppMenuItem will receive a message from Workbench whenever the
user picks that item from the Workbench menus.

When an application receives the messages described above, the message
will include struct [WBArg](libraries/14-workbench-environment-wbstartup-message.md) *am_ArgList containing the names ([wa_Name](libraries/14-workbench-environment-wbstartup-message.md)) and
directory locks ([wa_Lock](libraries/14-workbench-environment-wbstartup-message.md)) of all selected icons that were passed as
arguments by the user.  This am_ArgList has the same format as the
[sm_ArgList](libraries/14-workbench-environment-wbstartup-message.md) of a [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message.

 [Workbench Library Functions](libraries/14-the-workbench-library-workbench-library-functions.md)    [An AppMenuItem Example](libraries/lib-examples-appmenuitem-c.md) 
 [An AppIcon Example](libraries/lib-examples-appicon-c.md)             [An AppWindow Example](libraries/lib-examples-appwindow-c.md) 


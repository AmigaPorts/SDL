---
title: IV-59: AppWindows, AppIcons, and AppMenuItems
manual: amiga-mail
chapter: amiga-mail
section: iv-59-appwindows-appicons-and-appmenuitems
functions: []
libraries: []
---

# IV-59: AppWindows, AppIcons, and AppMenuItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By Fred Mitchell and John Orr


Since its inception, the Workbenchä has had a limitation.  Although it is
a fairly powerful user interface, that power is not accessible to
application programs.   The power is limited to an interface that only
launches other programs.  After Workbench launches a program, the program
no longer has any ties to the Workbench GUI.  If an application needs an
iconic interface, it has to create its own, independent of Workbench.

Workbench 2.0 is different.  Through the workbench.library, applications
can utilize the iconic interface of Workbench 2.0.  There are three
elements to this interface: AppWindows, AppIcons, and AppMenuItems.  In
this article, they are referred to as AppObjects.

When the user drops a Workbench icon onto a special kind of application
window called an AppWindow, Workbench sends a message to the application
that created the AppWindow.  This message contains a complete list of the
icons that the user dropped on the window.  This is useful for an
application like an editor.  The editor can open an Intuition window on
the Workbench screen and make it into an AppWindow so that when the user
drops an icon on the AppWindow, the editor will load the icon's
corresponding file.  The IconEdit utility that comes on the 2.0 release
disks does this.

An application can also create its own icons for the Workbench window.
These icons are called AppIcons.  They are similar to AppWindows in that
Workbench will tell an application what icons the user dropped on its
AppIcon.  In addition, Workbench will notify the application if the user
double-clicks the AppIcon.  This makes AppIcons useful not only as a
"drop box" (like an AppWindow), but they can also be used as some sort
of activator for an application.  For example, a word processor that opens
a window on the Workbench can use an AppIcon to "iconify" its window.
When the user wants to get rid of a cumbersome window, he iconifies it,
which gets rid of the window and leaves an AppIcon on the Workbench window
in its place.  When the user wants the window back, he double-clicks the
AppIcon and the window reappears.

The release 2.0 Workbench has a special menu called "Tools".  It is
special because unlike the other Workbench menus, any application can add
its own menu items to this menu.  These menu items are called
AppMenuItems.  Like the AppIcon, the AppMenu can be used both as an
activator and as a "drop box". When the user selects one of these menu
items, Workbench sends a message to the application that created the
AppMenuItem.  If there were any icons selected when the user selected the
AppMenuItem, the application will also get a list of those icons.

 [The AppMessage Structure](amiga-mail/the-appmessage-structure.md)      [AppWindows](amiga-mail/appwindows.md)      [AppMenuItems](amiga-mail/appmenuitems.md) 
 [Adding AppObjects](amiga-mail/adding-appobjects.md)             [AppIcons](amiga-mail/appicons.md)        [adc.c](amiga-mail/iv-59-adc-c.md) 


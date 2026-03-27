# 6 / Setting Up Menus / Sharing Menu Strips


A single menu strip may be attached to multiple windows in an application
by calling [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) for each window.  All of the windows must be on
the same screen for this to work.  Since menus are always associated with
the active window on a given screen, and since only one window may be
active on a screen at a time, only one window may display the shared menu
strip at any given time.

When multiple windows share a single menu strip, they will all "see" the
same state of the menus, that is, changes made to the menu strip from one
window will still exist when a new window is activated.  If the
application wishes to share menu strips but to have a different flag and
enabled status for each window, the program may watch [IDCMP_ACTIVEWINDOW](../Libraries_Manual_guide/node01E0.html#line36)
for the windows and modify the menu strip to match the active window's
requirements at that point.  In addition, the application must also set
[IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) to insure that the user can't access the menus of a newly
activated window before the application can process the IDCMP_ACTIVEWINDOW
message.

[ResetMenuStrip()](../Libraries_Manual_guide/node0184.html#line9) may also be used to set the menus for the multiple
windows as long as [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) is used first to attach the menu strip
to any one window and no major changes are made to the menu strip before
the calls to ResetMenuStrip() on subsequent windows.


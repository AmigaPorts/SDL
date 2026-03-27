# 6 / / Intercepting Menu Operations / Shortcuts and IDCMP_MENUVERIFY


The idea behind [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) is to synchronize the program with
Intuition's menu handling sessions.  The motive was to allow a program to
arbitrate access to a custom screen's bitmap, so that Intuition would not
render menus before the application was prepared for them.

Some programs use [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) to permit them to intercept the right
mouse button for their own purposes.  Other programs use it to delay menu
operations while they recover from unusual events such as illegible colors
of the screen or double buffering and related [ViewPort](../Libraries_Manual_guide/node00F1.html#line4) operations.

Menu shortcut keystrokes, for compatibility, also respect
[IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6).  They are always paired with an [IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) message
so that the program knows the menu operation is over.  This is true even
if the menu event is cancelled.


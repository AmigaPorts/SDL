# 4 / Other Window Functions / Menus and the Active Window


Menus for the active window will be displayed when the user presses the
menu button on the mouse.  Menus may be disabled for the window by not
providing a menu strip, or by clearing the menus with [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11).
Similarly, if the active window has [WFLG_RMBTRAP](../Libraries_Manual_guide/node0125.html#line95) set, the menu button will
not bring up the menus.

Two other functions, [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) and [ResetMenuStrip()](../Libraries_Manual_guide/node0184.html#line9), are used to
attach or update the menu strip for a window.


```c
    void ClearMenuStrip( struct Window *window );
    BOOL SetMenuStrip( struct Window *window, struct Menu *menu );
    BOOL ResetMenuStrip( struct Window *window, struct Menu *menu );
```
If [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) has been called for a window, [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11) must be
called before closing the window.  After ClearMenuStrip() has been called,
the user can no longer access menus for this window.  See the chapter
"[Intuition Menus](../Libraries_Manual_guide/node0180.html)," for complete information about setting up menus.


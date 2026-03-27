# 6 / Setting Up Menus / Changing Menu Strips


Direct changes to a menu strip attached to a window may be made only after
the menu strip has been removed from the window.  Use the [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11)
function to remove the menu strip.  It may be added back to the window
after the changes are complete.

Major changes include such things as adding or removing menus, items and
sub-items; changing text or image data; and changing the placement of the
data.  These changes require the system to completely re-layout the menus.

An additional function, [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html), is available to let the
application make small changes to the menus without the overhead of
[SetMenuStrip()](../Libraries_Manual_guide/node0181.html).  Only two things in the menu strip may be changed before a
call to ResetMenuStrip(), they are: changing the [CHECKED](../Libraries_Manual_guide/node019B.html#line7) flag to turn
checkmarks on or off, and changing the [ITEMENABLED](../Libraries_Manual_guide/node019B.html#line30) flag to enable/disable
menus, items or sub-items.


```c
    BOOL ResetMenuStrip( struct Window *window, struct Menu *menu );
```
[ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html) is called in place of [SetMenuStrip()](../Libraries_Manual_guide/node0181.html), and may only be
called on menus that were previously initialized with a call to
SetMenuStrip().  As with SetMenuStrip(), the menu strip must be removed
from the window before calling ResetMenuStrip().  Note that the window
used in the ResetMenuStrip() call does not have to be the same window to
which the menu was previously attached.  The window, however, must be on a
screen of the same mode to prevent the need for recalculating the layout
of the menu.

If the application wishes to attach a different menu strip to a window
that already has an existing menu strip, the application must call
[ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11) before calling [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) with the new menu strip.

The flow of events for menu operations should be:


```c
     1. [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html).

     2. [SetMenuStrip()](../Libraries_Manual_guide/node0181.html).

     3. Zero or more iterations of [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11) and
        [SetMenuStrip()](../Libraries_Manual_guide/node0181.html)/[ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html).

     4. [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11).

     5. [CloseWindow()](../Libraries_Manual_guide/node0105.html).
```

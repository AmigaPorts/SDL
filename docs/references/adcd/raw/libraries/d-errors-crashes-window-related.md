# D / Errors / Crashes--Window Related


Be careful not to [CloseWindow()](../Libraries_Manual_guide/node0105.html) a window during a while(msg=GetMsg(...))
loop on that window's port (next [GetMsg()](../Libraries_Manual_guide/node02F2.html) would be on freed pointer).
Also, use [ModifyIDCMP](../Libraries_Manual_guide/node01E3.html#line5)(NULL) with care, especially if using one port with
multiple windows.  Be sure to [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11) any menus before closing a
window, and do not free items such as dynamically allocated gadgets and
menus while they are attached to a window.  Do not reference an
[IntuiMessage](../Libraries_Manual_guide/node01D9.html)'s [IAddress](../Libraries_Manual_guide/node01D9.html#line73) field as a structure pointer of any kind before
determining it is a structure pointer (this depends on the [Class](../Libraries_Manual_guide/node01D9.html#line28) of the
IntuiMessage).  If a crash or problem only occurs when opening a window
after extended use of your program, check to make sure that your program
is properly freeing up signals allocated indirectly by [CreatePort()](../Libraries_Manual_guide/node02EC.html),
[OpenWindow()](../Libraries_Manual_guide/node0103.html) or ModifyIDCMP().


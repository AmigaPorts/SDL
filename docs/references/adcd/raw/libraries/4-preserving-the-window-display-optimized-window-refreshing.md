# 4 / Preserving the Window Display / Optimized Window Refreshing


Bracketing the display updating in the [BeginRefresh()](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) pair
automatically restricts all rendering to the "damaged" areas.


```c
    void BeginRefresh( struct Window *window );
    void EndRefresh  ( struct Window *window, long complete );
```
These functions makes sure that refreshing is done in the most efficient
way, only redrawing those portions of the window that really need to be
redrawn.  The rest of the rendering commands are discarded.

Operations performed between the [BeginRefresh()](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) pair should
be restricted to simple rendering.  All of the rendering functions in
Intuition library and Graphics library are safe.  Calls to
[RefreshGadgets()](../Libraries_Manual_guide/node0177.html#line5) are not permitted.  Avoid calls that may lock the
[LayerInfo](../Includes_and_Autodocs_2._guide/node00C4.html#line33), or get complicated in Intuition, since BeginRefresh() leaves
the window's layer or layers locked.  Avoid [AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21), and therefore
all direct or indirect disk related DOS calls.  See the
"[Intuition Gadgets](../Libraries_Manual_guide/node0143.html#line10)" chapter for more information on gadget restrictions
with BeginRefresh()/EndRefresh().

Certain applications do not need to receive refresh events, and can avoid
having to call [BeginRefresh()](../Libraries_Manual_guide/node011E.html) and [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) by setting the
WFLG_NOCAREREFRESH flag or the [WA_NoCareRefresh](../Libraries_Manual_guide/node0125.html#line62) tag in the
[OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.

The [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) function takes a boolean value as an argument (complete
in the prototype above).  This value determines whether refreshing is
completely finished.  When set to FALSE, further refreshing may be
performed between subsequent [BeginRefresh()](../Libraries_Manual_guide/node011E.html)/ EndRefresh() pairs.  Set the
boolean to TRUE for the last call to EndRefresh().

It is critical that applications performing multiple
[BeginRefresh()](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) pairs using EndRefresh(win,FALSE) hold layers
locked through the entire process.  The layer lock may only be released
after the final call to EndRefresh(win,TRUE). See the "[Layers Library](../Libraries_Manual_guide/node03EC.html)" for
more details.

The procedures outlined in this section take care of refreshing what is
inside the window.  Another function named [RefreshWindowFrame()](../Includes_and_Autodocs_2._guide/node0242.html) refreshes
window borders, including the title region and gadgets:


```c
    void RefreshWindowFrame( struct Window *window );
```
Applications can use this function to update window borders after
overwriting them with graphics.


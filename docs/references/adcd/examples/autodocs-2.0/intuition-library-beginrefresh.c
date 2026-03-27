/* Source: ADCD 2.1
 * Section: intuition-library-beginrefresh
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-beginrefresh.md
 */

    This routine sets up your window for optimized refreshing.

    Its role is to provide Intuition integrated access to the Layers
    library function [BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html).  Its additional contribution is
    to be sure that locking protocols for layers are followed, by
    locking both layers of a WFLG_GIMMEZEROZERO window only after the
    parent [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) has been locked.  Also, the WFLG_WINDOWREFRESH
    flag is set in your window, for your information.

    The purpose of [BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html), and hence BeginRefresh(), is to
    restrict rendering in a window (layer) to the region that needs
    refreshing after an operation such as window sizing or uncovering.
    This restriction to the "damage region" persists until you call
    [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html).

    For instance, if you have a WFLG_SIMPLE_REFRESH window which is
    partially concealed and the user brings it to the front, you can
    receive an IDCMP_REFRESHWINDOW message asking you to refresh your
    display.  If you call BeginRefresh() before doing any of the
    rendering, then the layer that underlies your window will be arranged
    so that the only rendering that will actually take place will be that
    which goes to the newly-revealed areas.  This is very performance-
    efficient, and visually attractive.

    After you have performed your refresh of the display, you should call
    [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html) to reset the state of the layer and the window.  Then you
    may proceed with rendering to the entire window as usual.

    You learn that your window needs refreshing by receiving either a
    message of class IDCMP_REFRESHWINDOW through the IDCMP, or an input
    event of class IECLASS_REFRESHWINDOW through the Console device.
    Whenever you are told that your window needs refreshing, you should
    call BeginRefresh() and [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html) to clear the refresh-needed
    state, even if you don't plan on doing any rendering.  You may relieve
    yourself of even this burden by setting the WFLG_NOCAREREFRESH flag
    when opening your window.

    WARNING: You should only perform graphics refreshing operations
    during the period between calling BeginRefresh() and [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html).
    In particular, do not call [RefreshGadgets()](../Includes_and_Autodocs_2._guide/node0240.html) or [RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html), since
    the locking protocol internal to Intuition runs the risk of creating
    a deadlock.  Note that Intuition refreshes the gadgets (through
    the damage region) before it sends the IDCMP_REFRESHWINDOW message.

    ANOTHER WARNING: The concept of multiple refresh passes using
    EndRefresh( w, FALSE ) is not completely sound without further
    protection.  The reason is that between two sessions, more
    damage can occur to your window.  Your final EndRefresh( w, TRUE )
    will dispose of all damage, including the new, and your
    initial refreshing pass will never get the chance to refresh
    the new damage.

    To avoid this, you must protect your session using [LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html)
    which will prevent Intuition from performing window operations
    or anything else which might cause further damage from occurring.
    Again, while holding the LayerInfo lock make no Intuition
    function calls dealing with gadgets; just render.

    You can, however, call [InstallClipRegion()](../Includes_and_Autodocs_2._guide/node0399.html) for the different
    refresh passes, if you have two clip regions.

    SIMILAR WARNING: Your program and Intuition "share" your window
    layer's DamageList.  BeginRefresh() helps arbitrate this
    sharing, but the lower-level function [layers.library/BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html)
    does not.  It isn't really supported to use [BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html) on
    a window's layer, but if you do--for whatever reason--it is
    critical that you first acquire the LayerInfo lock as in
    the above example: even if you only have one pass of refresh
    rendering to do.  Otherwise, the refreshing of your window's
    borders and gadgets can be incomplete, and the problem might
    occur only under certain conditions of task priority and
    system load.

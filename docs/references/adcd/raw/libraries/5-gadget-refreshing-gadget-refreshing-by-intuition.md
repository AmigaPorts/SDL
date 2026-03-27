# 5 / Gadget Refreshing / Gadget Refreshing by Intuition


Intuition will refresh a gadget whenever an operation has damaged the
layer of the window or requester to which it is attached.  Because of
this, the typical application does not need to call [RefreshGList()](../Libraries_Manual_guide/node0146.html) as a
part of its [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) event handling.

Intuition's refreshing of the gadgets of a damaged layer is done through
the layer's damage list.  This means that rendering is clipped or limited
to the layer's damage region--that part of the window or requester that
needs refreshing.

Intuition directly calls the [Layers library](../Libraries_Manual_guide/node03E3.html#line22) functions [BeginUpdate()](../Libraries_Manual_guide/node03EF.html#line32) and
[EndUpdate()](../Libraries_Manual_guide/node03EF.html#line32), so that rendering is restricted to the proper area.
Applications should not directly call these functions under Intuition,
instead, use the [BeginRefresh()](../Libraries_Manual_guide/node011E.html) and [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) calls.  Calls to
[RefreshGList()](../Libraries_Manual_guide/node0146.html) or [RefreshGadgets()](../Libraries_Manual_guide/node0177.html#line5) between BeginRefresh() and EndRefresh()
are not permitted.  Never add or remove gadgets between the BeginRefresh()
and EndRefresh() calls.

For more information on [BeginRefresh()](../Includes_and_Autodocs_2._guide/node0200.html) and [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html), see the
"[Intuition Windows](../Libraries_Manual_guide/node011E.html)" chapter and the Amiga ROM Kernel Reference Manual:
Includes and Autodocs.

Gadgets which are positioned using [GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29) or [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38), or
sized using [GFLG_RELWIDTH](../Libraries_Manual_guide/node014A.html#line47) or [GFLG_RELHEIGHT](../Libraries_Manual_guide/node014A.html#line55) pose a problem for this
scheme.  When the window is sized, the images for these gadgets must
change, even though they are not necessarily in the damage region.
Therefore, Intuition must add the original and new visual regions for such
relative gadgets to the damage region before refreshing the gadgets.  The
result of this is that applications should ensure that any gadgets with
relative position or size do not have [Border](../Libraries_Manual_guide/node01C1.html), [Image](../Libraries_Manual_guide/node01BA.html) or [IntuiText](../Libraries_Manual_guide/node01C7.html) imagery
that extends beyond their select boxes.


# 7 / True Requesters / Rendering Requesters


The application may choose to use Intuition's rendering facilities to
display the requester, or it may define its own custom bitmap.  The
[Requester](../Libraries_Manual_guide/node01AB.html) structure is initialized differently according to the rendering
method chosen.

To use Intuition's rendering facilities, you supply a list of one or more
display objects with the [Requester](../Libraries_Manual_guide/node01AB.html) structure and submit the Requester  to
Intuition, allowing it to draw the objects.  These objects can include
independent lists of [Border](../Libraries_Manual_guide/node01C1.html)s, [IntuiText](../Libraries_Manual_guide/node01C7.html), [Image](../Libraries_Manual_guide/node01BA.html)s and [Gadget](../Libraries_Manual_guide/node0149.html)s.  Note that
the abilty to provide a list of Image structures is new in V36, and the
[USEREQIMAGE](../Libraries_Manual_guide/node01AB.html#line147) flag must be set for them to be rendered.  For more about
Intuition rendering see the chapter on
"[Intuition Images, Line Drawing and Text](../Libraries_Manual_guide/node01B5.html)".

The gadgets in a requester also have their own borders, images and text to
add to the display imagery.  Intuition will allocate the buffers,
construct a bitmap that lasts for the duration of the display, and render
the requester into the window.  This rendering is all done over a solid
color, filled background specified by the [BackFill](../Libraries_Manual_guide/node01AB.html#line171) pen in the [Requester](../Libraries_Manual_guide/node01AB.html)
structure.  The backfill may be disabled by setting the [NOREQBACKFILL](../Libraries_Manual_guide/node01AB.html#line151) flag
(this also a new feature of V36).

On the other hand, a custom requester may be designed with pre-defined,
bitmap imagery for the entire object.  The image bitmap is submitted to
Intuition through the [ImageBMap](../Libraries_Manual_guide/node01AB.html#line181) field of the [Requester](../Libraries_Manual_guide/node01AB.html) structure.  The
bitmap should be designed to reduce user confusion; gadgets should line up
with their images, and the designer should attempt to use glyphs (symbols)
familiar to the user.

To provide imagery for the requester, applications should always try to
use data structures attached to the [Requester](../Libraries_Manual_guide/node01AB.html) structure as described
above.  Although, rendering directly into the requester layer's [RastPort](../Libraries_Manual_guide/node034A.html)
is tolerated, it must be done with great care.

First, a requester is allowed to have gadgets that automatically close the
requester when they are selected ([GACT_ENDGADGET](../Libraries_Manual_guide/node014B.html#line31)).  If such a gadget is
selected, the requester, its layer, and its layer's [RastPort](../Libraries_Manual_guide/node034A.html) will be
deleted asynchronously to your application.  If your application is trying
to render directly into the requester at that time, the results are
unpredictable.  Therefore, do not put GACT_ENDGADGET gadgets into a
requester if you plan on rendering directly into its RastPort.

Second, recall that requesters are clipped to the inside of the window
(not including the borders).  If the window can be sized smaller such that
the requester would be entirely clipped, the requester's layer may be
deleted by Intuition.  If your window's minimum size and the requester
size and position are such that the requester can be completely clipped,
then reading [Requester.ReqLayer](../Libraries_Manual_guide/node01AB.html#line177) is unsafe without additional protection.
It would be correct to [LockLayerInfo()](../Libraries_Manual_guide/node03EC.html#line11) the screen's [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33), then check
for the existence of the requester's ReqLayer, then render, then unlock.

For reasons such as these, direct rendering is discouraged.


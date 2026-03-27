# 5 / Gadget Refreshing / Gadget Refreshing by the Program


The [AddGList()](../Libraries_Manual_guide/node0133.html#line7) function adds gadgets to Intuition's internal lists but do
not display their imagery.  Subsequently calls to [RefreshGList()](../Libraries_Manual_guide/node0146.html) must be
made to draw the gadgets into the window or requester.

Programs may use [RefreshGList()](../Libraries_Manual_guide/node0146.html) to update the display after making changes
to their gadgets.  The supported changes include (not an exhaustive list):
changing the [GFLG_SELECTED](../Libraries_Manual_guide/node014A.html#line63) flag for [boolean](../Libraries_Manual_guide/node014C.html) gadgets to implement mutually
exclusive gadgets, changing the [GadgetText](../Libraries_Manual_guide/node0149.html#line111) of a gadget to change its
label, changing the [GFLG_DISABLED](../Libraries_Manual_guide/node014A.html#line73) flag, and changing the contents of the
[StringInfo](../Libraries_Manual_guide/node016B.html) structure [Buffer](../Libraries_Manual_guide/node016B.html#line19) of a [string](../Libraries_Manual_guide/node0164.html) gadget.  When making changes to a
gadget, be sure to remove the gadget from the system with [RemoveGList()](../Libraries_Manual_guide/node0133.html#line27)
before altering it.  Remember to add the gadget back and refresh its
imagery.

[Boolean](../Libraries_Manual_guide/node014C.html) gadgets rendered with borders, instead of images, or highlighted
with surrounding boxes ([GFLG_GADGHBOX](../Libraries_Manual_guide/node014A.html#line12)) are handled very simply by
Intuition, and complicated transitions done by the program can get the
rendering out of phase.  Applications should avoid modifying the imagery
and refreshing gadgets that may be highlighted due to selection by the
user.  Such operations may leave pixels highlighted when the gadget is no
longer selected.  The problems with such transitions can often be avoided
by providing imagery, either image or border, that covers all pixels in
the select box.  For [GFLG_GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16) gadgets, the select imagery should
cover all pixels covered in the normal imagery.

 [Updating a Gadget's Imagery](../Libraries_Manual_guide/node0145.html)    [gadget Refresh Function](../Libraries_Manual_guide/node0146.html) 


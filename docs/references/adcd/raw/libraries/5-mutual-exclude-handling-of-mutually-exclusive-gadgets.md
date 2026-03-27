# 5 / / Mutual Exclude / Handling of Mutually Exclusive Gadgets


Use [RemoveGList()](../Libraries_Manual_guide/node0133.html#line27) to remove the [boolean](../Libraries_Manual_guide/node014C.html) gadget from the window or
requester.  Set or clear the [GFLG_SELECTED](../Libraries_Manual_guide/node014A.html#line63) flag to reflect the displayed
state of the gadget.  Replace the gadget using [AddGList()](../Libraries_Manual_guide/node0133.html#line7) and refresh its
imagery with [RefreshGList()](../Libraries_Manual_guide/node0146.html).  Of course, several gadgets may be processed
with a single call to each of these functions.


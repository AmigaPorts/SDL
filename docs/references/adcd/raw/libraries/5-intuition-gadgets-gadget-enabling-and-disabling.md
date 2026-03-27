# 5 Intuition Gadgets / Gadget Enabling and Disabling


A gadget may be disabled so that it cannot be chosen by the user.  When a
gadget is disabled, its image is ghosted.  A ghosted gadget is overlaid
with a pattern of dots, thereby making the imagery less distinct.  The
dots are drawn into the select box of the gadget and any imagery that
extends outside of the select box is not affected by the ghosting.

The application may initialize whether a gadget is disabled by setting the
[GFLG_DISABLED](../Libraries_Manual_guide/node014A.html#line73) flag in the [Gadget](../Libraries_Manual_guide/node0149.html) structure's [Flags](../Libraries_Manual_guide/node0149.html#line48) field before a gadget
is submitted to Intuition.  Clear this flag to create an enabled gadget.

After a gadget is submitted to Intuition for display, its current enable
state may be changed by calling [OnGadget()](../Includes_and_Autodocs_2._guide/node0235.html) or [OffGadget()](../Includes_and_Autodocs_2._guide/node0233.html).  If the gadget
is in a requester, the requester must currently be displayed when calling
these functions.


```c
    void OnGadget ( struct Gadget *gadget, struct Window *window,
                    struct Requester *requester );
    void OffGadget( struct Gadget *gadget, struct Window *window,
                    struct Requester *requester );
```
Depending on what sort of imagery you choose for your gadget, [OnGadget()](../Includes_and_Autodocs_2._guide/node0235.html)
may not be smart enough to correct the gadget's displayed imagery.  See
the section on "[Updating a Gadget's Imagery](../Libraries_Manual_guide/node0145.html)" for more details.

Multiple gadgets may be enabled or disabled by calling [OnGadget()](../Includes_and_Autodocs_2._guide/node0235.html) or
[OffGadget()](../Includes_and_Autodocs_2._guide/node0233.html) for each gadget, or by removing the gadgets with
[RemoveGList()](../Libraries_Manual_guide/node0133.html#line27), setting or clearing the [GFLG_DISABLED](../Libraries_Manual_guide/node014A.html#line73) flag on each,
replacing the gadgets with [AddGList()](../Libraries_Manual_guide/node0133.html#line7), and refreshing with [RefreshGList()](../Libraries_Manual_guide/node0146.html).


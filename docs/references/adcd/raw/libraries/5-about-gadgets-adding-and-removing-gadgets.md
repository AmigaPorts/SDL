# 5 / About Gadgets / Adding and Removing Gadgets


Gadgets may be added to a window or requester when the window or requester
is opened, or they may be added later.  To add the gadgets when a window
is opened, use the [WA_Gadgets](../Libraries_Manual_guide/node0124.html#line52) tag with the [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.  This
technique is demonstrated in the example above.  For a requester, set the
[ReqGadget](../Libraries_Manual_guide/node01AB.html#line72) field in the [Requester](../Libraries_Manual_guide/node01AB.html) structure to point to the first gadget in
the list.

To add or remove gadgets in a window or requester that is already open,
use [AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html) or [RemoveGList()](../Includes_and_Autodocs_2._guide/node0247.html).  These functions operate on gadgets
arranged in a list.  A gadget list is linked together by the [NextGadget](../Libraries_Manual_guide/node0149.html#line21)
field of the Gadget structure (see the description of the [Gadget structure](../Libraries_Manual_guide/node0149.html)
later in this chapter).

[AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html) adds a gadget list that you specify to the existing gadget list
of a window or requester:


```c
    UWORD AddGList( struct Window *window, struct Gadget *agadget,
                    unsigned long position, long numGad,
                    struct Requester *requester );
```
Up to numGad gadgets will be added from the gadget list you specify
beginning with agadget.  The position argument determines where your
gadgets will be placed in the existing list of gadgets for the window or
requester.  Use (~0) to add your gadget list to the end of the window or
requester's gadget list.  This function returns the actual position where
your gadgets are added in the existing list.

To remove gadgets from a window or requester use [RemoveGList()](../Includes_and_Autodocs_2._guide/node0247.html):


```c
    UWORD RemoveGList( struct Window *remPtr, struct Gadget *agadget,
                       long numGad );
```
This function removes up to numGad gadgets from a window or requester,
beginning with the specified one.  Starting with V37, if one of the
gadgets that is being removed is the active gadget, this routine will wait
for the user to release the mouse button before deactivating and removing
the gadget.  This function returns the former position of the removed
gadget or -1 if the specified gadget was not found.

The [Gadget](../Libraries_Manual_guide/node0149.html) structure should never be directly modified after it has been
added to a window or requester.  To modify a gadget, first remove it with
[RemoveGList()](../Includes_and_Autodocs_2._guide/node0247.html), modify the structure as needed, and then add the gadget
back to the system with [AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html).  Finally, refresh the gadget imagery
with [RefreshGList()](../Libraries_Manual_guide/node0146.html). (See the section on "[Gadget Refreshing](../Libraries_Manual_guide/node0142.html)" below for
more information.)

Some attributes of a gadget may be modified through special Intuition
functions that perform the modification.  When using such functions it is
not necessary to remove, add or refresh the gadget.  These functions, such
as [NewModifyProp()](../Libraries_Manual_guide/node0163.html), [OnGadget()](../Libraries_Manual_guide/node0147.html#line10) and [OffGadget()](../Libraries_Manual_guide/node0147.html#line10), are described later in
this chapter.


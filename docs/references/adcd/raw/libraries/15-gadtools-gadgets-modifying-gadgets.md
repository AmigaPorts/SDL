# 15 / GadTools Gadgets / Modifying Gadgets


The attributes of a gadget are set up when the gadget is created.  Some of
these attributes can be changed later by using the [GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html)
function:


```c
    void GT_SetGadgetAttrs (struct Gadget *gad, struct Window *win,
                            struct Requester *req, Tag tag1, ... )
    void GT_SetGadgetAttrsA(struct Gadget *gad, struct Window *win,
                            struct Requester *req, struct TagItem *taglist)
```
The gad argument specifies the gadget to be changed while the win argument
specifies the window the gadget is in.  Currently, the req argument is
unused and must be set to NULL.

The gadget attributes are changed by passing tag arguments to these
functions.  The tag arguments can be either a set of [TagItem](../Libraries_Manual_guide/node0497.html)s on the stack
for [GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html), or a pointer to an array of TagItems for
[GT_SetGadgetAttrsA()](../Includes_and_Autodocs_2._guide/node03F6.html).  The tag items specify the attributes that are to be
changed for the gadget.  Keep in mind though that not every gadget
attribute can be modified this way.

For example, in the slider gadget presented earlier, the level-formatting
string may not be changed after the gadget is created.  However, the
slider's level may be changed to 5 as follows:


```c
    GT_SetGadgetAttrs(slidergad, win, req,
        GTSL_Level, 5,
        TAG_END);
```
Here are some other example uses of [GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html) to change gadget
attributes after it is created.


```c
    /* Disable a button gadget */
    GT_SetGadgetAttrs(buttongad, win, NULL,
                            GA_Disabled, TRUE,
                            TAG_END);

    /* Change a slider's range to be 1 to 100, currently at 50 */
    GT_SetGadgetAttrs(slidergad, win, NULL,
                            GTSL_Min, 1,
                            GTSL_Max, 100,
                            GTSL_Level, 50,
                            TAG_END);

    /* Add a node to the head of listview's list, and make it */
    /* the selected one */
    GT_SetGadgetAttrs(listviewgad, win, NULL,
                            /* detach list before modifying */
                            GTLV_Labels, ~0,
                            TAG_END);
    AddHead(&lvlabels, &newnode);
    GT_SetGadgetAttrs(listviewgad, win, NULL,
                            /* re-attach list */
                            GTLV_Labels, &lvlabels,
                            GTLV_Selected, 0,
                            TAG_END);
```
When changing a gadget using these functions, the gadget will
automatically update its visuals.  No refresh is required, nor should any
refresh call be performed.


```c
    Warning:
    --------
    The [GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html) functions may not be called inside of a
    [GT_BeginRefresh()/GT_EndRefresh()](../Libraries_Manual_guide/node026F.html#line19) pair.  This is true of Intuition
    gadget functions generally, including those discussed in the
    "[Intuition Gadgets](../Libraries_Manual_guide/node0143.html)" chapter.
```
In the sections that follow all the possible attributes for each kind of
gadget are discussed.  The tags are also described in the Autodocs for
[GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html) in the Amiga ROM Kernel Reference Manual: Includes and
Autodocs.


```c
    Important:
    ----------
    Tags that can only be sent to [CreateGadget()](../Libraries_Manual_guide/node025A.html) and not to
    [GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html) will be marked as create only in the
    discussion that follows.  Those that are valid parameters to both
    functions will be marked as create and set.
```

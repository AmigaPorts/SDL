# 15 / / / GetVisualInfo() and FreeVisualInfo()


In order to ensure their best appearance, GadTools gadgets and menus need
information about the screen on which they will appear.  Before creating
any GadTools gadgets or menus, the program must get this information using
the [GetVisualInfo()](../Includes_and_Autodocs_2._guide/node03EE.html) call.


```c
    APTR GetVisualInfoA( struct Screen *screen, struct TagItem *taglist );
    APTR GetVisualInfo( struct Screen *screen, Tag tag1, ... );
```
Set the screen argument to a pointer to the screen you are using.  The tag
arguments, tag1 or taglist, are reserved for future extensions.  Currently
none are recognized, so only TAG_END should be used.

The function returns an abstract handle called the VisualInfo.  For
GadTools gadgets, the [ng_VisualInfo](../Libraries_Manual_guide/node0259.html#line49) field of the [NewGadget](../Libraries_Manual_guide/node0259.html) structure must
be set to this handle before the gadget can be added to the window.
GadTools menu layout and creation functions also require the VisualInfo
handle as an argument.

There are several ways to get the pointer to the screen on which the
window will be opened.  If the application has its own custom screen, this
pointer is known from the call to [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) or [OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6).  If
the application already has its window opened on the Workbench or some
other public screen, the screen pointer can be found in [Window.WScreen](../Libraries_Manual_guide/node0121.html#line62).
Often the program will create its gadgets and menus before opening the
window.  In this case, use [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34) to get a pointer to the desired
public screen, which also provides a lock on the screen to prevent it from
closing.  See the chapters "[Intuition Screens](../Libraries_Manual_guide/node00E6.html)" and "[Intuition Windows](../Libraries_Manual_guide/node0106.html)" for
more about public screens.

The VisualInfo data must be freed after all the gadgets and menus have
been freed but before releasing the screen.  Custom screens are released
by calling [CloseScreen()](../Libraries_Manual_guide/node00E4.html), public screens are released by calling
[CloseWindow()](../Libraries_Manual_guide/node0105.html) or [UnlockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34), depending on the technique used.  Use
[FreeVisualInfo()](../Includes_and_Autodocs_2._guide/node03ED.html) to free the visual info data.


```c
    void FreeVisualInfo( APTR vi );
```
This function takes just one argument, the VisualInfo handle as returned
by [GetVisualInfo()](../Includes_and_Autodocs_2._guide/node03EE.html).  The sequence of events for using the VisualInfo
handle could look like this:


```c
    init()
    {
    myscreen = LockPubScreen(NULL);
    if (!myscreen)
        {
        cleanup("Failed to lock default public screen");
        }
    vi = GetVisualInfo(myscreen);
    if (!vi)
        {
        cleanup("Failed to GetVisualInfo");
        }
    /* Create gadgets here */
    ng.ng_VisualInfo = vi;
    ...
    }

    void cleanup(STRPTR errorstr)
    {
    /* These functions may be safely called with a NULL parameter: */
    FreeGadgets(glist);
    FreeVisualInfo(vi);

    if (myscreen)
        UnlockPubScreen(NULL, myscreen);

    printf(errorstr);
    }
```

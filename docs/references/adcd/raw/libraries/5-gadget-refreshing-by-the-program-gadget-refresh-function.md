# 5 / / Gadget Refreshing by the Program / Gadget Refresh Function


Use the [RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html) function to refresh one or more gadgets in a window
or requester.


```c
    void RefreshGList( struct Gadget *gadgets, struct Window *window,
                       struct Requester *requester, long numGad );
```
This function redraws no more than numGad gadgets, starting with the
specified gadget, in a window or requester.  The application should
refresh any gadgets after adding them.  The function should also be used
after the application has modified the imagery of the gadgets to display
the new imagery.


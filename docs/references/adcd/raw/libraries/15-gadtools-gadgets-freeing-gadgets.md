# 15 / GadTools Gadgets / Freeing Gadgets


After closing the window, the gadgets allocated using [CreateGadget()](../Libraries_Manual_guide/node025A.html) must
be released.  [FreeGadgets()](../Includes_and_Autodocs_2._guide/node03EB.html) is a simple call that will free all the
GadTools gadgets that it finds, beginning with the gadget whose pointer is
passed as an argument.


```c
    void FreeGadgets( struct Gadget *gad );
```
The gad argument is a pointer to the first gadget to be freed.  It is safe
to call [FreeGadgets()](../Includes_and_Autodocs_2._guide/node03EB.html) with a NULL gadget pointer, the function will then
return immediately.  Before calling FreeGadgets(), the application must
first either remove the gadgets or close the window.

When the gadget passed to [FreeGadgets()](../Includes_and_Autodocs_2._guide/node03EB.html) is the first gadget in a linked
list, the function frees all the GadTools gadgets on the list without
patching pointers or trying to maintain the integrity of the list.  Any
non-GadTools gadgets found on the list will not be freed, hence the result
will not necessarily form a nice list since any intervening GadTools
gadgets will be gone.

See the section on "[Creating Gadget Lists](../Libraries_Manual_guide/node026E.html)" for more information on using
linked lists of gadgets.


# 15 / / Setting Up GadTools Menus and Gadgets / CreateContext()


Use of GadTools gadgets requires some per-window context information.
[CreateContext()](../Includes_and_Autodocs_2._guide/node03E7.html) establishes a place for that information to go. This
function must be called before any GadTools gadgets are created.


```c
    struct Gadget *CreateContext( struct Gadget **glistptr );
```
The glistptr argument is a double-pointer to a [Gadget](../Libraries_Manual_guide/node0149.html) structure.  More
specifically, this is a pointer to a NULL-initialized pointer to a Gadget
structure.

The return value of [CreateContext()](../Includes_and_Autodocs_2._guide/node03E7.html) is a pointer to this gadget, which
should be fed to the program's first call to [CreateGadget()](../Libraries_Manual_guide/node025A.html).  This pointer
to the [Gadget](../Libraries_Manual_guide/node0149.html) structure returned by CreateContext(), may then serve as a
handle to the list of gadgets as they are created.  The [code fragment](../Libraries_Manual_guide/node026E.html#line5)
listed in the next section shows how to use CreateContext() together with
CreateGadget() to make a linked list of GadTools gadgets.


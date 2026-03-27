# B / rootclass / New Methods: OM_SET


This method tells an object to set one or more of its attributes.
Applications should not call this method directly.  Instead, use the
intuition.library functions [SetAttrs()](../Libraries_Manual_guide/node0205.html) and [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5) to call this
method.  The return value for this method is not explicitly defined.

The return value for this method is not explicitly defined.  However, in
general, when implementing the OM_SET method, if setting an object
attribute causes some sort of visual state change, the OM_SET method
should return a value greater than zero.  If changing an attribute does
not affect the visual state, OM_SET should return zero.

This method uses a custom message (defined in <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line76)>):


```c
    struct opSet {
        ULONG             MethodID;      /* OM_SET */
        struct TagItem    *ops_AttrList; /* tag list of attributes to set*/
        struct GadgetInfo *ops_GInfo;
    };
```
The ops_AttrList field contains a pointer to a tag list of attribute/value
pairs.  These pairs contain the IDs and the new values of the attributes
to set.  The dispatcher has to look through this list (see docs for the
utility.library [NextTagItem()](../Libraries_Manual_guide/node0497.html#line35) function) for attributes its class
recognizes and set the attribute's value accordingly.  The dispatcher
should let its superclass handle any attributes it does not recognize.

If the object is a gadget, the ops_GInfo field contains a pointer to a
[GadgetInfo](../Libraries_Manual_guide/node0219.html#line23) structure.  Otherwise, the value in ops_GInfo is undefined.
Intuition use the GadgetInfo structure to pass display information to
gadgets.  See the [gadgetclass](../Libraries_Manual_guide/node04F2.html) methods for more details.


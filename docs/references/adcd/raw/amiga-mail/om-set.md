# OM_SET


This method is used to set an object's attributes.  The Intuition function
SetAttr() calls this method.  It receives the following arguments:


```c
    struct opSet
    {
        ULONG MethodID;
        struct TagItem *ops_AttrList;
        struct GadgetInfo *ops_GInfo;
    };
```
For the OM_SET method, the new class's dispatcher should process the
attributes your class recognizes and have the superclass process any
unrecognized attributes.  Note that a subclass dispatcher can directly
process attributes it inherits from a superclass, rather than passing the
message on to the superclass.

Note that mytextlabelclass treats the OM_UPDATE method exactly like the
OM_SET method.  This is OK because these two methods are functionally
equivalent for imageclass classes.


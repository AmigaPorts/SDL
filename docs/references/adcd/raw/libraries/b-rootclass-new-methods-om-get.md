# B / rootclass / New Methods: OM_GET


Tells an object to report an attribute's value.  Applications should not
call this method directly.  Instead, use the intuition.library function
[GetAttr()](../Libraries_Manual_guide/node0206.html).  The return value for this method is not explicitly defined.

This method uses a custom message (defined in <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line106)>):


```c
    struct opGet {
        ULONG MethodID;     /* OM_GET */
        ULONG opg_AttrID;   /* ID of attribute to get */
        ULONG *opg_Storage; /* place to put attribute value */
    };
```
If the object's dispatcher recognizes opg_AttrID as one of the attributes
defined by this class, the dispatcher should copy the value of that
attribute to where opg_Storage points:


```c
    struct opGet *myopget;
    ...
    *(myopget->opg_Storage) = my_attribute_value;
    ...
```
If the dispatcher does not recognize opg_AttrID, it should pass the
message on to the superclass.


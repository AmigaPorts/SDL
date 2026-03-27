# B / rootclass / New Methods: OM_ADDTAIL


This method tells an object to add itself to the end of a specified Exec
list.  Boopsi objects contain a [MinNode](../Libraries_Manual_guide/node02D9.html) structure used for this purpose.
The return value for this method is not explicitly defined.

The method uses a custom message (defined in <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line115)>):


```c
    struct opAddTail {
        ULONG       MethodID;   /* OM_ADDTAIL */
        struct List *opat_List; /* The exec list to add the object to */
    };
```
The opat_List can be any Exec list.  Use the Intuition function
[NextObject()](../Includes_and_Autodocs_2._guide/node0230.html) to step through this list.


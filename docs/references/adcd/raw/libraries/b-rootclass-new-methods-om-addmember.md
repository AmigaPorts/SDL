# B / rootclass / New Methods: OM_ADDMEMBER


Tells an object to add another object to its personal Exec list.  What the
list is for depends on the class.  The return value for this method is not
explicitly defined.

One class that uses this method is [modelclass](../Libraries_Manual_guide/node04CC.html).  A modelclass object
maintains a broadcast list.  When a modelclass object gets an [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html)
message, it broadcasts an [OM_UPDATE](../Libraries_Manual_guide/node04D0.html) message about the OM_NOTIFY to every
object in its broadcast list.

This method uses a custom message (defined in <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line121)>):


```c
    #define  opAddMember opMember
    struct opMember {
        ULONG  MethodID;     /* OM_ADDMEMBER (or OM_REMMEMBER) */
        Object *opam_Object; /* add (or remove) this object    */
    };                       /* to (from) personal list.       */
```
opam_Object is the object to add to the list.  A dispatcher typically
implements OM_ADDMEMBER by sending the [OM_ADDTAIL](../Libraries_Manual_guide/node04BE.html) message to the
opam_Object object.


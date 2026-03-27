# B / rootclass / New Methods: OM_REMMEMBER


Tells an object to remove a member object from its personal list.  The
member object should have already been added with [OM_ADDMEMBER](../Libraries_Manual_guide/node04C0.html).  This
method uses the same custom message as OM_ADDMEMBER.  Normally a
dispatcher implements OM_REMMEMBER by sending the [OM_REMOVE](../Libraries_Manual_guide/node04BF.html) message to the
opam_Object object.  The return value for this method is not explicitly
defined.


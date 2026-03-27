# 23 / List Functions / MinList/MinNode Operations


All of the above functions and macros will work with long or short format
node structures.  A [MinNode](../Libraries_Manual_guide/node02D9.html#line7) structure contains only linkage information.
A full [Node](../Libraries_Manual_guide/node02D9.html#line19) structure contains linkage information, as well as type,
priority and name fields.  The smaller MinNode is used where space and
memory alignment issues are important.  The larger Node is used for queues
or lists that require a name tag for each node.


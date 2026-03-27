# 23 / List Functions / Insertion and Removal


The [Insert()](../Includes_and_Autodocs_2._guide/node035F.html) function is used for inserting a new node into any position
in a list.  It always inserts the node following a specified node that is
already part of the list.  For example, Insert([header](../Libraries_Manual_guide/node02DD.html#line21),[node](../Libraries_Manual_guide/node02DD.html#line21),pred) inserts
the node node after the node pred in the specified list.  If the pred node
points to the list header or is NULL, the new node will be inserted at the
head of the list.  Similarly, if the pred node points to the [lh_Tail](../Libraries_Manual_guide/node02DB.html#line17) of
the list, the new node will be inserted at the tail of the list.  However,
both of these actions can be better accomplished with the functions
mentioned in the "[Special Case Insertion](../Libraries_Manual_guide/node02DF.html)" section below.

The [Remove()](../Includes_and_Autodocs_2._guide/node0373.html) function is used to remove a specified node from a list.  For
example, Remove([node](../Libraries_Manual_guide/node02DD.html#line21)) will remove the specified node from whatever list it
is in.  To be removed, a node must actually be in a list. If you attempt
to remove a node that is not in a list, you will cause serious system
problems.


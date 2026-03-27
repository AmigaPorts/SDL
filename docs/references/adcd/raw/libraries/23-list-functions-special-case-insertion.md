# 23 / List Functions / Special Case Insertion


Although the [Insert()](../Libraries_Manual_guide/node02DE.html) function allows new nodes to be inserted at the head
and the tail of a list, the [AddHead()](../Includes_and_Autodocs_2._guide/node0325.html) and [AddTail()](../Includes_and_Autodocs_2._guide/node032C.html) functions will do so
with higher efficiency.  Adding to the head or tail of a list is common
practice in first-in-first-out ([FIFO](../Libraries_Manual_guide/node02E0.html)) or last-in-first-out ([LIFO](../Libraries_Manual_guide/node02E0.html) or stack)
operations.  For example, AddHead([header](../Libraries_Manual_guide/node02DD.html#line21),[node](../Libraries_Manual_guide/node02DD.html#line21)) would insert the node at
the head of the specified list.


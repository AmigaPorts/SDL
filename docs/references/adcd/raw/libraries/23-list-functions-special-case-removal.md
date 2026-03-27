# 23 / List Functions / Special Case Removal


The two functions [RemHead()](../Includes_and_Autodocs_2._guide/node0370.html) and [RemTail()](../Includes_and_Autodocs_2._guide/node0377.html) are used in combination with
[AddHead()](../Libraries_Manual_guide/node02DF.html) and [AddTail()](../Libraries_Manual_guide/node02DF.html) to create special list ordering.  When you combine
AddTail() and RemHead(), you produce a first-in-first-out (FIFO) list.
When you combine AddHead() and RemHead() a last-in-first-out (LIFO or
stack) list is produced.  RemTail() exists for symmetry. Other
combinations of these functions can also be used productively.

Both [RemHead()](../Includes_and_Autodocs_2._guide/node0370.html) and [RemTail()](../Includes_and_Autodocs_2._guide/node0377.html) remove a [node](../Libraries_Manual_guide/node02DD.html#line21) from the list, and return a
pointer to the removed node. If the list is empty, the function return a
NULL result.


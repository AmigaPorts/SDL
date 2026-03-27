# 23 Exec Lists and Queues / Function Reference


The following charts give a brief description of the Exec list and queue
functions and assembler macros.  See the Amiga ROM Kernel Reference
Manual: Includes and Autodocs for details about each call.


             Table 23-1: Exec List and Queue Functions
  _________________________________________________________________
 |                                                                 |
 |  Exec Function  Description                                     |
 |=================================================================|
 |    [AddHead()](../Includes_and_Autodocs_2._guide/node0325.html)  Insert a node at the head of a list.              |
 |    [AddTail()](../Includes_and_Autodocs_2._guide/node032C.html)  Append a node to the tail of a list.              |
 |    [Enqueue()](../Includes_and_Autodocs_2._guide/node034D.html)  Insert or append a node to a system queue.        |
 |   [FindName()](../Includes_and_Autodocs_2._guide/node034E.html)  Find a node with a given name in a system list.   |
 |     [Insert()](../Includes_and_Autodocs_2._guide/node035F.html)  Insert a node into a list.                        |
 |  IsListEmpty  Test if list is empty                             |
 |    [NewList()](../Includes_and_Autodocs_2._guide/node0161.html)  Initialize a list structure for use.              |
 |    [RemHead()](../Includes_and_Autodocs_2._guide/node0370.html)  Remove the head node from a list.                 |
 |     [Remove()](../Includes_and_Autodocs_2._guide/node0373.html)  Remove a node from a list.                        |
 |    [RemTail()](../Includes_and_Autodocs_2._guide/node0377.html)  Remove the tail node from a list.                 |
 |_________________________________________________________________|


          Table 23-2: Exec List and Queue Assembler Macros
  _________________________________________________________________
 |                                                                 |
 |  Exec Function  Description                                     |
 |=================================================================|
 |      [NEWLIST](../Includes_and_Autodocs_2._guide/node0081.html#line44)  Initialize a list header for use.                 |
 |      [TSTLIST](../Includes_and_Autodocs_2._guide/node0081.html#line52)  Test if list is empty (list address in register). |
 |               No arbitration needed.                            |
 |      [TSTLST2](../Includes_and_Autodocs_2._guide/node0081.html#line66)  Test is list is empty (from effective address of  |
 |               list).  Arbitration needed.                       |
 |         [SUCC](../Includes_and_Autodocs_2._guide/node0081.html#line73)  Get next node in a list.                          |
 |         [PRED](../Includes_and_Autodocs_2._guide/node0081.html#line78)  Get previous node in a list.                      |
 |      [IFEMPTY](../Includes_and_Autodocs_2._guide/node0081.html#line83)  Branch if list is empty.                          |
 |   [IFNOTEMPTY](../Includes_and_Autodocs_2._guide/node0081.html#line89)  Branch if list is not empty.                      |
 |      [TSTNODE](../Includes_and_Autodocs_2._guide/node0081.html#line95)  Get next node, test if at end of list.            |
 |     [NEXTNODE](../Includes_and_Autodocs_2._guide/node0081.html#line101)  Get next node, go to exit label if at end.        |
 |      [ADDHEAD](../Includes_and_Autodocs_2._guide/node0081.html#line113)  Add node to head of list.                         |
 |      [ADDTAIL](../Includes_and_Autodocs_2._guide/node0081.html#line122)  Add node to tail of list.                         |
 |       [REMOVE](../Includes_and_Autodocs_2._guide/node0081.html#line133)  Remove node from a list.                          |
 |      [REMHEAD](../Includes_and_Autodocs_2._guide/node0081.html#line141)  Remove node from head of list.                    |
 |     [REMHEADQ](../Includes_and_Autodocs_2._guide/node0081.html#line152)  Remove node from head of list quickly.            |
 |      [REMTAIL](../Includes_and_Autodocs_2._guide/node0081.html#line162)  Remove node from tail of list.                    |
 |_________________________________________________________________|


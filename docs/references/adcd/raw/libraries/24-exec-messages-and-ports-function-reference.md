# 24 Exec Messages and Ports / Function Reference


The following chart gives a brief description of the Exec functions that
control inter-task communication with messages and ports.  See the Amiga
ROM Kernel Reference Manual: Includes and Autodocs for details about each
call.

               Table 24-1: Exec Message and Port Functions
  _____________________________________________________________________
 |                                                                     |
 |       Function                   Description                        |
 |=====================================================================|
 |        [AddPort()](../Includes_and_Autodocs_2._guide/node0329.html)  Add a public message port to the system list.     |
 |  [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html)  Allocate and initialize a new message port (V37). |
 |  [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html)  Free a message port, created with CreateMsgPort() |
 |                   (V37).                                            |
 |       [FindPort()](../Includes_and_Autodocs_2._guide/node034F.html)  Find a public message port in the system list.    |
 |         [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html)  Get next message from the message port.           |
 |         [PutMsg()](../Includes_and_Autodocs_2._guide/node036B.html)  Put a message to a message port.                  |
 |        [RemPort()](../Includes_and_Autodocs_2._guide/node0374.html)  Remove a message port from the system list.       |
 |       [ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html)  Reply to a message on its reply port.             |
 |_____________________________________________________________________|


               Table 24-2: Amiga.lib Exec Support Functions
  _____________________________________________________________________
 |                                                                     |
 |       Function                   Description                        |
 |=====================================================================|
 |     [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)  Allocate and initialize a new message port, make  |
 |                   public if named                                   |
 |     [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)  Delete a message port, created with CreatePort(). |
 |_____________________________________________________________________|


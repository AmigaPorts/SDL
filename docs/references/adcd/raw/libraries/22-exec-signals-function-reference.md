# 22 Exec Signals / Function Reference


The following chart gives a brief description of the Exec functions that
control task signalling.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for details about each call.


                    Table 22-1: Exec Signal Functions
  _______________________________________________________________________
 |                                                                       |
 |   Exec Signal                                                         |
 |    Function                         Description                       |
 |=======================================================================|
 |  [AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html)  Allocate a signal bit.                                |
 |   [FreeSignal()](../Includes_and_Autodocs_2._guide/node0356.html)  Free a signal bit allocated with AllocSignal().       |
 |    [SetSignal()](../Includes_and_Autodocs_2._guide/node037E.html)  Query or set the state of the signals for the current |
 |                 task.                                                 |
 |       [Signal()](../Includes_and_Autodocs_2._guide/node0381.html)  Signal a task by setting signal bits in its [Task](../Libraries_Manual_guide/node02BB.html)      |
 |                 structure.                                            |
 |         [Wait()](../Includes_and_Autodocs_2._guide/node038A.html)  Wait for one or more signals from other tasks or      |
 |                 interrupts.                                           |
 |_______________________________________________________________________|


# 21 Exec Tasks / Function Reference


The following chart gives a brief description of the Exec functions that
control tasks.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details about each call.


     Table 21-3: Exec Task, Processor and Cache Control Functions
  ___________________________________________________________________
 |                                                                   |
 |      Exec Task                                                    |
 |      Function          Description                                |
 |===================================================================|
 |       [AddTask()](../Includes_and_Autodocs_2._guide/node032D.html)  Add a task to the system.                        |
 |     [AllocTrap()](../Includes_and_Autodocs_2._guide/node0334.html)  Allocate a processor trap vector.                |
 |       [Disable()](../Includes_and_Autodocs_2._guide/node034A.html)  Disable interrupt processing.                    |
 |        [Enable()](../Includes_and_Autodocs_2._guide/node034C.html)  Enable interrupt processing.                     |
 |      [FindTask()](../Includes_and_Autodocs_2._guide/node0352.html)  Find a specific task.                            |
 |        [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html)  Forbid task rescheduling.                        |
 |      [FreeTrap()](../Includes_and_Autodocs_2._guide/node0357.html)  Release a process trap.                          |
 |        [Permit()](../Includes_and_Autodocs_2._guide/node0369.html)  Permit task rescheduling.                        |
 |    [SetTaskPri()](../Includes_and_Autodocs_2._guide/node0380.html)  Set the priority of a task.                      |
 |       [RemTask()](../Includes_and_Autodocs_2._guide/node0378.html)  Remove a task from the system.                   |
 |-------------------------------------------------------------------|
 |   [CacheClearE()](../Includes_and_Autodocs_2._guide/node0338.html)  Flush CPU instruction and/or data caches (V37).  |
 |   [CacheClearU()](../Includes_and_Autodocs_2._guide/node0339.html)  Flush CPU instruction and data caches (V37).     |
 |  [CacheControl()](../Includes_and_Autodocs_2._guide/node033A.html)  Global cache control (V37).                      |
 |  [CachePostDMA()](../Includes_and_Autodocs_2._guide/node033B.html)  Perform actions prior to hardware DMA (V37).     |
 |   [CachePreDMA()](../Includes_and_Autodocs_2._guide/node033C.html)  Perform actions after hardware DMA (V37).        |
 |         [GetCC()](../Includes_and_Autodocs_2._guide/node0359.html)  Get processor [condition codes](../Libraries_Manual_guide/node02CC.html).                   |
 |         [SetSR()](../Includes_and_Autodocs_2._guide/node037F.html)  Get/set processor [status register](../Libraries_Manual_guide/node02CB.html).               |
 |    [SuperState()](../Includes_and_Autodocs_2._guide/node0385.html)  Set [supervisor mode](../Libraries_Manual_guide/node02CA.html) with user stack.             |
 |    [Supervisor()](../Includes_and_Autodocs_2._guide/node0386.html)  Execute a short supervisor mode function.        |
 |     [UserState()](../Includes_and_Autodocs_2._guide/node0388.html)  Return to user mode with user stack.             |
 |-------------------------------------------------------------------|
 |    [CreateTask()](../Includes_and_Autodocs_2._guide/node014A.html)  Amiga.lib function to setup and add a new task.  |
 |    [DeleteTask()](../Includes_and_Autodocs_2._guide/node0155.html)  Amiga.lib function to delete a task created with |
 |                  CreateTask().                                    |
 |___________________________________________________________________|


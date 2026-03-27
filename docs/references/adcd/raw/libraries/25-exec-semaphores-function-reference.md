# 25 Exec Semaphores / Function Reference


The following charts give a brief description of the Exec semaphore
functions.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details about each call.


                   Table 25-1: Exec Semaphore Functions
  ________________________________________________________________________
 |                                                                        |
 |  Exec Semaphore Function                 Description                   |
 |========================================================================|
 |           [AddSemaphore()](../Includes_and_Autodocs_2._guide/node032B.html)  Initialize and add a signal semaphore to the |
 |                           system.                                      |
 |       [AttemptSemaphore()](../Includes_and_Autodocs_2._guide/node0336.html)  Try to get an exclusive lock on a signal     |
 |                           semaphore without blocking.                  |
 |          [FindSemaphore()](../Includes_and_Autodocs_2._guide/node0351.html)  Find a given system signal semaphore.        |
 |          [InitSemaphore()](../Includes_and_Autodocs_2._guide/node035D.html)  Initialize a signal semaphore.               |
 |        [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html)  Try to get exclusive access to a signal      |
 |                           semaphore.                                   |
 |    [ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html)  Try to get exclusive access to a list of     |
 |                           signal semaphores.                           |
 |  [ObtainSemaphoreShared()](../Includes_and_Autodocs_2._guide/node0364.html)  Try to get shared access to a signal         |
 |                           semaphore (V36).                             |
 |       [ReleaseSemaphore()](../Includes_and_Autodocs_2._guide/node036D.html)  Release the lock on a signal semaphore.      |
 |   [ReleaseSemaphoreList()](../Includes_and_Autodocs_2._guide/node036E.html)  Release the locks on a list of signal        |
 |                           semaphores.                                  |
 |           [RemSemaphore()](../Includes_and_Autodocs_2._guide/node0376.html)  Remove a signal semaphore from the system.   |
 |________________________________________________________________________|


# 25 / / The Signal Semaphore / Releasing a SignalSemaphore


Once you have obtained the semaphore and completed any operations on the
semaphore protected object, you should release the semaphore.  The
[ReleaseSemaphore()](../Includes_and_Autodocs_2._guide/node036D.html) function does this.  For each successful
[ObtainSemaphore()](../Libraries_Manual_guide/node02FA.html), [ObtainSemaphoreShared()](../Libraries_Manual_guide/node02FB.html) and [AttemptSemaphore()](../Libraries_Manual_guide/node02FC.html) call you
make, you must have a matching ReleaseSemaphore() call.


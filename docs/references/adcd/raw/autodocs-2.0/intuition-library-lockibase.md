# intuition.library/LockIBase



NAME

```c
    LockIBase -- Invoke semaphore arbitration of [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line67).
```
SYNOPSIS

```c
    Lock = LockIBase( LockNumber )
    D0                D0

    ULONG LockIBase( ULONG );
```
FUNCTION

```c
    Grabs Intuition internal semaphore so that caller may examine
    [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line67) safely.  This function is not a magic "fix all my
    race conditions" panacea.

    The idea here is that you can get the locks Intuition needs before
    such [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line67) fields as ActiveWindow and FirstScreen are
    changed, or linked lists of windows and screens are changed.

    Do Not Get Tricky with this entry point, and do not hold these locks
    for long, as all Intuition input processing will wait for you to
    surrender the lock by a call to [UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html).

    NOTE WELL: A call to this function MUST be paired with a subsequent
    call to [UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html), and soon, please.

    NOTE WELL: Do not call any Intuition functions (nor any graphics,
    layers, dos, or other high-level system function) while
    holding this lock.
```
INPUTS

    A long unsigned integer, LockNumber, specifies which of Intuition's
    internal locks you want to get.  This parameter should be zero for all
    forseeable uses of this function, which will let you examine active
    fields and linked lists of screens and windows with safety.
RESULT

```c
    Returns another ULONG which should be passed to [UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html) to
    surrender the lock gotten by this call.
```
BUGS

    This function must not be called while holding any other system locks
    such as layer or LayerInfo locks.
SEE ALSO

```c
    [UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html), [layers.library/LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html),
    [exec.library/ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html)
```

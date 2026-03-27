# 11 Intuition Special Functions / Locking IntuitionBase


It is sometimes necessary to examine the [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line59) structure.  Items
such as the address of the active screen and window, current mouse
coordinates and more can be found there.  It is never a good idea to
simply read these fields, as they are prone to sudden change.  The
IntuitionBase structure must always be locked before looking at its fields.

It is necessary to inform Intuition that an application is about to
examine [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line59) so that Intuition will not change any variables and
IntuitionBase will remain static during the access.  The call [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html)
will lock the state of IntuitionBase so that it may be examined.  During
the time that the application has IntuitionBase locked, all Intuition
input processing is frozen.  Make every effort to examine IntuitionBase
and release the lock as quickly as possible.  The values in IntuitionBase
are read-only.  Applications should never write values to IntuitionBase.


```c
    ULONG LockIBase( unsigned long dontknow );
```
[LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html) is passed a ULONG (dontknow in the prototype above) indicating
the Intuition lock desired.  For all foreseeable uses of the call this
value should be 0.  LockIBase() returns a ULONG, that must be passed to
[UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html) later to allow [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line59) to change once again.

Every call to [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html) must be matched by a subsequent call to
[UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html):


```c
    void UnlockIBase( unsigned long ibLock );
```
Set the ibLock argument to the value returned by the previous call to
[LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html).


```c
    About LockIBase().
    ------------------
    This function should not be called while holding any other system
    locks such as [Layer](../Libraries_Manual_guide/node03E4.html) and [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) locks.  Between calls to
    [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html) and [UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html), you may not call any Intuition
    or other high-level system functions so it is best to copy the
    information you need and release the lock as quickly as possible.

    About IntuitionBase.
    --------------------
    Never, ever, modify any of the fields in [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line59) directly.
    Also, there are fields in IntuitionBase that are considered system
    private that should not be accessed, even for reading.  (Refer to the
    <intuition/[intuitionbase](../Includes_and_Autodocs_2._guide/node00DC.html)> include file.) Application programs
    cannot depend on (and should not use) the contents of these fields;
    their usage is subject to change in future revisions of Intuition.
```

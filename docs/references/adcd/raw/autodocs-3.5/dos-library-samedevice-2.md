# dos.library/SameDevice



   NAME
	SameDevice -- Are two locks are on partitions of the device? (V37)

   SYNOPSIS
	same = SameDevice(lock1, lock2)
	D0		   D1     D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SameDevice( [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129), [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) )

   FUNCTION
	SameDevice() returns whether two locks refer to partitions that
	are on the same physical device (if it can figure it out).  This
	may be useful in writing copy routines to take advantage of
	asynchronous multi-device copies.

	Entry existed in V36 and always returned 0.

   INPUTS
	lock1,lock2 - locks

   RESULT
	same - whether they're on the same device as far as Dos can determine.


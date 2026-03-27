# lowlevel.library/ElapsedTime



   NAME
	ElapsedTime -- returns the time elapsed since it was last called. (V40)

   SYNOPSIS
	fractionalSeconds = ElapsedTime(context);
	D0                              A0

	ULONG ElapsedTime(struct [EClockVal](../Includes_and_Autodocs_3._guide/node0607.html#line34) *);

   FUNCTION
	This function utilizes the [timer.device/ReadEClock()](../Includes_and_Autodocs_3._guide/node0578.html) function to get
	an accurate elapsed time value. Since the context needs to be
	established the first call to this routine will return a nonsense
	value.

	The return value for this function only allows for sixteen bits
	worth for the integer number of seconds and sixteen bits for the
	factional number of seconds.

	With sixteen bits worth of integer seconds this function can be
	used to timer an interval up to about 16 hours. If the actual time
	interval is larger this function will return this maximum value.

	The sixteen bits for fractional seconds gives a resolution of
	approximately 20 microseconds. However, it is not recomended
	to expect this function to be accurate for a time interval of
	less than 200 microseconds.

   INPUTS
	context - pointer to an [EClockVal](../Includes_and_Autodocs_3._guide/node0607.html#line34) structure. The first time you
		  call this function, you should initialize the structure
		  to 0s. You should then reuse the same structure for
		  subsequent calls to this function, as this is how the
		  elapsed time is calculated.

   RESULT
	fractionalSeconds - The elapsed time as a fixed point 32-bit
	                    number with the point fixed in the middle.
	                    That is, the upper order sixteen bits represent
	                    the number of seconds elapsed. The low order
	                    sixteen bit represent the fractional number of
	                    seconds elapsed. This value is limited to about
	                    sixteen hours. Although this value is precise
	                    to nearly 20 microseconds it is only accurate to
	                    within 200 microseconds.

   WARNING
	The first call to this function will return a non-sense value. Only
	rely on its result starting with the second call.

   SEE ALSO
	[timer.device/ReadEClock()](../Includes_and_Autodocs_3._guide/node0578.html)


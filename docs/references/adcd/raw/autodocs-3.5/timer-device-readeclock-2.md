# timer.device/ReadEClock



   NAME
	ReadEClock -- Get the current value of the E-Clock. (V36)

   SYNOPSIS
	E_Freq = ReadEClock( Dest )
	D0                   A0

	ULONG ReadEClock ( struct [EClockVal](../Includes_and_Autodocs_3._guide/node0607.html#line34) * );

   FUNCTION
	This routine calculates the current 64 bit value of the E-Clock
	and stores it in the destination [EClockVal](../Includes_and_Autodocs_3._guide/node0607.html#line34) structure. The count
	rate of the E-Clock is also returned.

	A0 will be left unchanged

	This is a low overhead function designed so that very short
	intervals may be timed.

   INPUTS
	Dest -- pointer to an [EClockVal](../Includes_and_Autodocs_3._guide/node0607.html#line34) structure.

   RETURNS
	Dest -- the [EClockVal](../Includes_and_Autodocs_3._guide/node0607.html#line34) structure will contain the E-Clock time
	E_Freq -- The count rate of the E-Clock (tics/sec).

   NOTES
	This function may be called from interrupts.

   SEE ALSO

   BUGS


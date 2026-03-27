# battclock.resource/ReadBattClock



   NAME
	ReadBattClock -- [Read](../Includes_and_Autodocs_3._guide/node01A0.html) time from clock chip.  (V36)

   SYNOPSIS
	AmigaTime = ReadBattClock( )

	ULONG ReadBattClock( void );
	D0

   FUNCTION
	This routine reads the time from the clock chip and returns it
	as the number of seconds from 01-jan-1978.

   INPUTS

   RESULTS
	AmigaTime       The number of seconds from 01-Jan-1978 that
	                    the clock chip thinks it is.

   NOTES
	If the clock chip returns an invalid date, the clock chip is
	reset and 0 is returned.

   SEE ALSO

   BUGS


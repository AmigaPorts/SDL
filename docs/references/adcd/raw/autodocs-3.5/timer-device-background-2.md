# timer.device/--background--



   TIMER REQUEST
	A time request is a non standard IO [Request](../Includes_and_Autodocs_3._guide/node03E5.html).  It has an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17)
	followed by a [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure or an eclockval structure.

   TIMEVAL
	A [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) structure consists of two longwords.  The first is
	the number of seconds, the latter is the fractional number
	of microseconds.  The microseconds must always be "normalized"
	e.g. the longword must be between 0 and one million.

   ECLOCKVAL
	A eclockval structure consists of two longwords.  The first is
	the high order 32 bits of a 64 bit number and the second is the
	the low order 32 bits.  The 64 bit number is a count of "E" clock
	ticks.  The "E" clock frequency is related to the master clock
	frequency of the machine and can be determined by calling the
	[ReadEClock()](../Includes_and_Autodocs_3._guide/node0578.html) library like call.

   UNITS
	The timer contains five units -- two designed to accuratly measure
	short intervals, one that has little system overhead and is very
	stable over time, and two that work like an alarm clock.

   UNIT_MICROHZ
	This unit uses the programmable timers in the 8520s to keep track
	of its time.  It has precision down to about 2 microseconds, but
	will drift as system load increases.  The accuracy of this unit
	is the same as that of the master clock of the machine.  This unit
	uses a [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) in its [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39).

   UNIT_VBLANK
	This unit uses a strobe from the power supply to keep track of its
	time or the "E" clock on machines without power supply strobes.
	It is very stable over time, but only has a resolution of that of
	the vertical blank interrupt.  This unit is very cheap to use, and
	should be used by those who are waiting for long periods of time
	(typically 1/2 second or more).  This unit uses a [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) in its
	[timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39).

   UNIT_ECLOCK
	This unit is exacly the same as UNIT_MICROHZ except that it uses
	an eclockval instead of a [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) in its [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39).

   UNIT_WAITUNTIL
	This unit waits until the systime is greater than or equal to the
	time in the [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) in the [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39).  This unit has the same
	resolution and accuracy as that of UNIT_VBLANK.

   UNIT_WAITECLOCK
	This unit waits until the E-Clock value as returned by [ReadEClock()](../Includes_and_Autodocs_3._guide/node0578.html)
	is greater than or equal to the eclockval in the [timerequest](../Includes_and_Autodocs_3._guide/node0607.html#line39). This
	unit has the same resolution and accuracy as that of UNIT_ECLOCK.

   LIBRARY
	In addition to the normal device calls, the timer also supports
	several direct, library like calls.

   BUGS
	In the V1.2/V1.3 release, the timer device has problems with
	very short time requests.  When one of these is made, other
	timer requests may be finished inaccurately.  A side effect
	is that AmigaDOS requests such as "Delay(0);" or
	"WaitForChar(x,0);" are unreliable.


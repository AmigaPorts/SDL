# F / / Interface Signals / RES - reset input


A low on the RES pin resets all internal registers.  The port pins are set
as inputs and port registers to zero (although a read of the ports will
return all highs because of passive pull-ups). The timer control registers
are set to zero and the timer latches to all ones.  All other registers
are reset to zero.


# F / Register Functional Description / Input Modes


Control bits (CRA5, CRB5-6) allow selection of the clock used to decrement
the timer.  [Timer A](../Hardware_Manual_guide/node0133.html)  can count 02 clock pulses or external pulses applied
to the CNT pin.   [Timer B](../Hardware_Manual_guide/node0133.html)  can count 02 pulses, external CNT pulses,
 [timer A](../Hardware_Manual_guide/node0133.html)  underflow pulses, or  [timer A](../Hardware_Manual_guide/node0133.html)  underflow pulses while the CNT
pin is held high.

The timer latch is loaded into the timer on any timer underflow, on a
force load, or following a write to the high byte of the pre- scalar while
the timer is stopped.  If the timer is running, a write to the high byte
will load the timer latch but not the counter.


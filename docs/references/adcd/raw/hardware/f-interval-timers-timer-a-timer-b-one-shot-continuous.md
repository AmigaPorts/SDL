# F / / Interval Timers (Timer A, Timer B) / One-shot/continuous


A control bit (CRx3) selects either timer mode.  In one-shot mode, the
timer will count down from the latched value to zero, generate an
interrupt, reload the latched value, then stop. In continuous mode, the
timer will count down from the latched value to zero, generate an
interrupt, reload the latched value, and repeat the procedure continuously.

In one-shot mode, a write to timer-high (register 5 for timer A, register
7 for Timer B) will transfer the timer latch to the counter and initiate
counting regardless of the start bit.


# F 8520 Complex Interface Adapters / Time of Day Clock


TOD consists of a 24-bit binary counter.  Positive edge transitions on
this pin cause the binary counter to increment.  The TOD pin has a passive
pull-up on it.

A programmable alarm is provided for generating an interrupt at a desired
time. The alarm registers are located at the same addresses as the
corresponding TOD registers.  Access to the alarm is governed by a
 [control register](../Hardware_Manual_guide/node0145.html)  bit (CRB7).  The alarm is write-only; any read of a TOD
address will read time regardless of the state of the ALARM access bit.

A specific sequence of events must be followed for proper setting and
reading of TOD.  TOD is automatically stopped whenever a write to the
register occurs.  The clock will not start again until after a write to
the  [LSB event](../Hardware_Manual_guide/node012F.html#line4)  register.  This assures that TOD will always start at the
desired time.

Since a carry from one stage to the next can occur at any time with
respect to a read operation, a latching function is included to keep all
TOD information constant during a read sequence. All TOD registers latch
on a read of  [MSB event](../Hardware_Manual_guide/node012F.html#line4)  and remain latched until after a read of
 [LSB event](../Hardware_Manual_guide/node012F.html#line4) . The TOD clock continues to count when the output registers
are latched. If only one register is to be read, there is no carry problem
and the register can be read "on the fly" provided that any read of
 [MSB event](../Hardware_Manual_guide/node012F.html#line4)  is followed by a read of  [LSB Event](../Hardware_Manual_guide/node012F.html#line4)  to disable the latching.

 [Bit Names for Write Time/Alarm or Read Time](../Hardware_Manual_guide/node013D.html) 


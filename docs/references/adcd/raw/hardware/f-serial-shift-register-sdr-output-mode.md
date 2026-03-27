# F / Serial Shift Register (SDR) / Output Mode


In the output mode,  [Timer A](../Hardware_Manual_guide/node0133.html)  is used as the baud rate generator. Data is
shifted out on the SP pin at 1/2 the underflow rate of  [Timer A](../Hardware_Manual_guide/node0133.html) .  The
maximum baud rate possible is 02 divided by 4, but the maximum usable baud
rate will be determined by line loading and the speed at which the
receiver responds to input data.

To begin transmission, you must first set up  [Timer A](../Hardware_Manual_guide/node0133.html)  in continuous mode,
and start the timer.  Transmission will start following a write to the
serial data register.  The clock signal derived from  [Timer A](../Hardware_Manual_guide/node0133.html)  appears as
an output on the CNT pin.  The data in the serial data register will be
loaded into the shift register, then shifted out to the SP pin when a CNT
pulse occurs.  Data shifted out becomes valid on the next falling edge of
CNT and remains valid until the next falling edge.

After eight CNT pulses, an interrupt is generated to indicate that more
data can be sent.  If the serial data register was reloaded with new
information prior to this interrupt, the new data will automatically be
loaded into the shift register and transmission will continue.

If no further data is to be transmitted after the eighth CNT pulse, CNT
will return high and SP will remain at the level of the last data bit
transmitted.

SDR data is shifted out MSB first.  Serial input data should appear in
this same format.


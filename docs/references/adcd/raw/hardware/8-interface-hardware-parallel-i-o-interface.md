# 8 Interface Hardware / Parallel I/O Interface


The general-purpose bi-directional  [parallel interface](../Hardware_Manual_guide/node0101.html)  is a 25-pin
connector on the back panel of the computer. This connector is generally
used for a parallel printer.

For each data byte written to the parallel port register, the hardware
automatically generates a pulse on the data ready pin.  The acknowledge
pulse from the parallel device is hooked up to an interrupt. For pin
connections and timing, see  [Appendix E](../Hardware_Manual_guide/node00F3.html)  and  [Appendix F](../Hardware_Manual_guide/node012E.html) .


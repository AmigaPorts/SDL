# E / / Serial Interface Specification / Timing


Maximum operating frequency is 19.2 KHz.  Refer to EIA standard RS-232-C
for operating and installation specifications.  A rate of 31.25 KHz will
be supported through the use of a MIDI adapter.

Modem control signals ( [CTS, RTS, DTR, DSR, CD](../Hardware_Manual_guide/node0106.html) ) are completely under
software control.  The modem control lines have no hardware affect on and
are completely asynchronous to  [TXD and RXD](../Hardware_Manual_guide/node0106.html) .


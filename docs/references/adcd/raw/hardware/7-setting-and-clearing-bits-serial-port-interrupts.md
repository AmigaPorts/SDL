# 7 / / Setting and Clearing Bits / Serial Port Interrupts


The following serial interrupts are associated with the specified bits of
the  [interrupt registers](../Hardware_Manual_guide/node0164.html) .

Bit 11, RBF (for receive buffer full), specifies that the input buffer of
the UART has data that is ready to read. This bit generates a
 [level 5 interrupt](../Hardware_Manual_guide/node016F.html) .

Bit 0, TBE (for "transmit buffer empty"), specifies that the output
buffer of the UART needs more data and data can now be written into this
buffer. This bit generates a  [level 1 interrupt](../Hardware_Manual_guide/node016F.html) .


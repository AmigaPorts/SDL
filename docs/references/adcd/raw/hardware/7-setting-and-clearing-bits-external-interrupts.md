# 7 / / Setting and Clearing Bits / External Interrupts


Bits 13 and 3 of the  [interrupt registers](../Hardware_Manual_guide/node0164.html)  are reserved for external
interrupts.

Bit 13, EXTER, becomes a 1 when the system line called INT6* becomes a
logic 0. Bit 13 generates a  [level 6 interrupt](../Hardware_Manual_guide/node016F.html) .

Bit 3, PORTS, becomes a 1 when the system line called INT2* becomes a
logic 0. Bit 3 causes a  [level 2 interrupt](../Hardware_Manual_guide/node016F.html) .


# 8 / Serial I/O Interface / Specifying The Register Contents


The data to be transmitted is placed in the output register ( [SERDAT](../Hardware_Manual_guide/node01A4.html) ).
Above the data bits, 1 bits must be added as stop bits. Normally, either
one or two stop bits are sent.

The transmission of the start bit is independent of the contents of this
register. One start bit is automatically generated before the first data
bit (bit 0) is sent.

Writing this register starts the data transmission. If this register is
written with all zeros, no data transmission is initiated.


# 8 / Serial I/O Interface / How Output Data Is Transmitted


You send data out on the transmit lines by writing into the serial data
output register (SERDAT).  This register is write-only.

Data will be sent out at the same rate as you have established for the
read.  Immediately after you write the data into this register, the system
will begin the transmission at the baud rate you selected.

At the start of the operation, this data is transferred from SERDAT into
an internal serial  [shift register](../Hardware_Manual_guide/node013E.html) .  When the transfer to the serial
 [shift register](../Hardware_Manual_guide/node013E.html)  has been completed, SERDAT can accept new data; the TBE
interrupt signals this fact.

Data will be moved out of the  [shift register](../Hardware_Manual_guide/node013E.html) , one bit during each time
interval, starting with the least significant bit. The shifting continues
until all 1 bits have been shifted out. Any number or combination of data
and stop bits may be specified this way.

SERDAT is a 16-bit register that allows you to control the format
(appearance) of the transmitted data. To form a typical data sequence,
such as one start bit, eight data bits, and one stop bit, you write into
SERDAT the contents shown in Figures 8-12 and 8-13.




       15        9 8 7             0
     _________________________________
                                                         |     |
       0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 - - - - - - - - - ->|  1  |
     _________________________________                   |     |

                                                         one bit

                                 All zeros from last shift -


    Figure 8-12: Starting Appearance of SERDAT and Shift Register




                   15        9 8 7                 0
                 __________________________________
                                 |                 |
                   0 0 0 0 0 0 1 |<- 8 bits data ->|
                 ________________|_________________|

                                - - - - - - - - - ->

                     Data gets shfted out this way.


           Figure 8-13: Ending Appearance of Shift Register
The register stops shifting and signals "shift register empty" (TSRE) when
there is a 1 bit present in the bit-shifted-out position and the rest of
the contents of the  [shift register](../Hardware_Manual_guide/node013E.html)  are 0s. When new nonzero contents are
loaded into this register, shifting begins again.


# 8 / Serial I/O Interface / Contents Of The Receive Data Register


The serial input data-receive register is 16 bits wide.  It contains the 8
or 9 bit input data and status bits.

The data is received, one bit at a time, into an internal
serial-to-parallel  [shift register](../Hardware_Manual_guide/node013E.html) .  When the proper number of bit times
have elapsed, the contents of this register are transferred to the serial
data read register (SERDATR) shown in Table 8-10, and you are signaled
that there is data ready for you.

Immediately after the transfer of data takes place, the
 [receive shift register](../Hardware_Manual_guide/node013F.html)  again becomes ready to accept new data. After
receiving the receiver-full interrupt, you will have up to one full
character-receive time (8 to 10 bit times) to accept the data and clear
the interrupt. If the interrupt is not cleared in time, the OVERRUN bit is
set.

Table 8-9 shows the definitions of the various bit positions within
SERDATR.


```c
               Table 8-9: SERDATR /  [ADKCON](../Hardware_Manual_guide/node0194.html)  Registers
```
   SERDATR
   -------

   Bit
   Number  Name    Function
   ------  ----    --------
   15      OVRUN    OVERRUN

```c
                    (Mirror -- also appears in the interrupt request
                    register.) Indicates that another byte of data was
                    received before the previous byte was picked up by the
                    processor.  To prevent this condition, it is necessary
                    to reset INTF_RBF (bit 11, receive-buffer-full) in
                     [INTREQ](../Hardware_Manual_guide/node0037.html) .
```
   14      RBF      READ BUFFER FULL

```c
                    (Mirror -- also appears in the interrupt request
                    register.) When this bit is 1, there is data ready to
                    be picked up by the processor.  After reading the
                    contents of this data register, you must reset the
                    INTF_RBF bit in  [INTREQ](../Hardware_Manual_guide/node0037.html)  to prevent an overrun.
```
   13      TBE      TRANSMIT BUFFER EMPTY

```c
                    (Not a mirror -- interrupt occurs when the buffer
                    becomes empty.)  When bit 14 is a 1, the data in the
                    output data register ( [SERDAT](../Hardware_Manual_guide/node01A4.html) ) has been transferred to
                    the  [serial output shift register](../Hardware_Manual_guide/node0140.html) , so  [SERDAT](../Hardware_Manual_guide/node01A4.html)  is ready
                    to accept another output word.  This is also true when
                    the buffer is empty.

                    This bit is normally used for full-duplex operation.
```
   12      TSRE     TRANSMIT SHIFT REGISTER EMPTY

```c
                    When this bit is a 1, the  [output shift register](../Hardware_Manual_guide/node0140.html)  has
                    completed its task, all data has been transmitted, and
                    the register is now idle.  If you stop writing data
                    into the output register ( [SERDAT](../Hardware_Manual_guide/node01A4.html) ), then this bit will
                    become a 1 after both the word currently in the
                     [shift register](../Hardware_Manual_guide/node013E.html)  and the word placed into  [SERDAT](../Hardware_Manual_guide/node01A4.html)  have
                    been transmitted.

                    This bit is normally used for half-duplex operation.
```
   11      RXD      Direct read of  [RXD pin](../Hardware_Manual_guide/node023D.html)  on Paula chip.

   10               Not used at this time.

   9       STP      Stop bit if 9 data bits are specified for receive.

   8       STP      Stop bit if 8 data bits are specified for receive.

                            OR
           DB8      9th data bit if 9 bits are specified for receive.
   7-0     DB7-DB0  Low 8 data bits of received data.  Data is TRUE (data
```c
                    you read is the same polarity as the data expected).

    [ADKCON](../Hardware_Manual_guide/node0194.html) 
```
   --------

   Bit
   Number  Name     Function
   ------  ----     --------
   15      SET/CLR  Allows setting or clearing individual bits.


                    If bit 15 is a 1 specified bits are set.
                    If bit 15 is a 0 specified bits are cleared.
   11      UARTBRK  Force the transmit pin to zero.


---
title: 8 / Serial I/O Interface / Contents Of The Receive Data Register
manual: hardware
chapter: hardware
section: 8-serial-i-o-interface-contents-of-the-receive-data-register
functions: []
libraries: []
---

# 8 / Serial I/O Interface / Contents Of The Receive Data Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The serial input data-receive register is 16 bits wide.  It contains the 8
or 9 bit input data and status bits.

The data is received, one bit at a time, into an internal
serial-to-parallel  [shift register](hardware/f-8520-complex-interface-adapters-serial-shift-register-sdr.md) .  When the proper number of bit times
have elapsed, the contents of this register are transferred to the serial
data read register (SERDATR) shown in Table 8-10, and you are signaled
that there is data ready for you.

Immediately after the transfer of data takes place, the
 [receive shift register](hardware/f-serial-shift-register-sdr-input-mode.md)  again becomes ready to accept new data. After
receiving the receiver-full interrupt, you will have up to one full
character-receive time (8 to 10 bit times) to accept the data and clear
the interrupt. If the interrupt is not cleared in time, the OVERRUN bit is
set.

Table 8-9 shows the definitions of the various bit positions within
SERDATR.


```c
               Table 8-9: SERDATR /  [ADKCON](hardware/8-timing-adkcon-and-adkconr-audio-and-disk-control-register.md)  Registers
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
                     [INTREQ](hardware/a-register-summary-intreq-intreqr.md) .
```
   14      RBF      READ BUFFER FULL

```c
                    (Mirror -- also appears in the interrupt request
                    register.) When this bit is 1, there is data ready to
                    be picked up by the processor.  After reading the
                    contents of this data register, you must reset the
                    INTF_RBF bit in  [INTREQ](hardware/a-register-summary-intreq-intreqr.md)  to prevent an overrun.
```
   13      TBE      TRANSMIT BUFFER EMPTY

```c
                    (Not a mirror -- interrupt occurs when the buffer
                    becomes empty.)  When bit 14 is a 1, the data in the
                    output data register ( [SERDAT](hardware/8-serial-i-o-interface-how-output-data-is-transmitted.md) ) has been transferred to
                    the  [serial output shift register](hardware/f-serial-shift-register-sdr-output-mode.md) , so  [SERDAT](hardware/8-serial-i-o-interface-how-output-data-is-transmitted.md)  is ready
                    to accept another output word.  This is also true when
                    the buffer is empty.

                    This bit is normally used for full-duplex operation.
```
   12      TSRE     TRANSMIT SHIFT REGISTER EMPTY

```c
                    When this bit is a 1, the  [output shift register](hardware/f-serial-shift-register-sdr-output-mode.md)  has
                    completed its task, all data has been transmitted, and
                    the register is now idle.  If you stop writing data
                    into the output register ( [SERDAT](hardware/8-serial-i-o-interface-how-output-data-is-transmitted.md) ), then this bit will
                    become a 1 after both the word currently in the
                     [shift register](hardware/f-8520-complex-interface-adapters-serial-shift-register-sdr.md)  and the word placed into  [SERDAT](hardware/8-serial-i-o-interface-how-output-data-is-transmitted.md)  have
                    been transmitted.

                    This bit is normally used for half-duplex operation.
```
   11      RXD      Direct read of  [RXD pin](hardware/j-custom-chip-pin-allocation-list-paula-pin-assignment.md)  on Paula chip.

   10               Not used at this time.

   9       STP      Stop bit if 9 data bits are specified for receive.

   8       STP      Stop bit if 8 data bits are specified for receive.

                            OR
           DB8      9th data bit if 9 bits are specified for receive.
   7-0     DB7-DB0  Low 8 data bits of received data.  Data is TRUE (data
```c
                    you read is the same polarity as the data expected).

    [ADKCON](hardware/8-timing-adkcon-and-adkconr-audio-and-disk-control-register.md) 
```
   --------

   Bit
   Number  Name     Function
   ------  ----     --------
   15      SET/CLR  Allows setting or clearing individual bits.


                    If bit 15 is a 1 specified bits are set.
                    If bit 15 is a 0 specified bits are cleared.
   11      UARTBRK  Force the transmit pin to zero.


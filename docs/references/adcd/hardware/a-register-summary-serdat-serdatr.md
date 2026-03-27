---
title: A Register Summary / SERDAT, SERDATR
manual: hardware
chapter: hardware
section: a-register-summary-serdat-serdatr
functions: []
libraries: []
---

# A Register Summary / SERDAT, SERDATR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
SERDAT     030      W       P      Serial port data and stop bits write

```c
                                       (transmit data buffer)

                 This address writes data to a transmit data buffer.
                 Data from this buffer is moved into a serial shift
                 register for output transmission whenever it is
                 empty.  This sets the interrupt request TBE
                 (transmit buffer empty). A stop bit must be
                 provided as part of the data word. The length of
                 the data word is set by the position of the stop
                 bit.

                 BIT# 15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                      -----------------------------------------------
                 USE   0  0  0  0  0  0  S D8 D7 D6 D5 D4 D3 D2 D1 D0

                 Note:  S = stop bit = 1, D = data bits.
```
SERDATR    018      R       P      Serial port data and status read

```c
                                       (receive data buffer)

                 This address reads data from a receive data buffer.
                 Data in this buffer is loaded from a receiving
                 shift register whenever it is full.  Several
                 interrupt request bits are also read at this
                 address, along with the data, as shown below.

                 BIT#  SYM          FUNCTION
                 ----  ----         -----------------------
                 15    OVRUN        Serial port receiver overrun.
                                    Reset by resetting bit 11 of
                                     [INTREQ](hardware/a-register-summary-intreq-intreqr.md) .
                 14    RBF          Serial port receive buffer full
                                    (mirror).
                 13    TBE          Serial port transmit buffer
                                    empty (mirror).
                 12    TSRE         Serial port transmit shift
                                    register empty.
                                    Reset by loading into buffer.
                 11    RXD          RXD pin receives UART serial
                                    data for direct bit test by
                                    the microprocessor.
                 10     0           Not used
                 09    STP          Stop bit
                 08  STP-DB8        Stop bit if LONG, data bit if
                                    not.
                 07    DB7          Data bit
                 06    DB6          Data bit
                 05    DB5          Data bit
                 04    DB4          Data bit
                 03    DB3          Data bit
                 02    DB2          Data bit
                 01    DB1          Data bit
                 00    DB0          Data bit
```

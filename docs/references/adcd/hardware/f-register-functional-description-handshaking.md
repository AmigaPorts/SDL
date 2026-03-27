---
title: F / Register Functional Description / Handshaking
manual: hardware
chapter: hardware
section: f-register-functional-description-handshaking
functions: []
libraries: []
---

# F / Register Functional Description / Handshaking

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Handshaking occurs on data transfers using the PC output pin and the FLAG
input pin.  PC will go low on the third cycle after a  [port B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md)  access.
This signal can be used to indicate "data ready" at  [port B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md)  or "data
accepted" from  [port B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) . Handshaking on 16-bit data transfers (using both
 [ports A and B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) ) is possible by always reading or writing  [port A](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md)  first.
FLAG is a negative edge-sensitive input that can be used for receiving the
PC output from another 8520 or as a general- purpose interrupt input.  Any
negative transition on FLAG will set the FLAG interrupt bit.


        REG  NAME   D7   D6   D5   D4   D3   D2   D1   D0
        ---  ----   ---- ---- ---- ---- ---- ---- ---- ----
         0   PRA    PA7  PA6  PA5  PA4  PA3  PA2  PA1  PA0
         1   PRB    PB7  PB6  PB5  PB4  PB3  PB2  PB1  PB0
         2   DDRA   DPA7 DPA6 DPA5 DPA4 DPA3 DPA2 DPA1 DPA0
         3   DDRB   DPB7 DPB6 DPB5 DPB4 DPB3 DPB2 DPB1 DPB0

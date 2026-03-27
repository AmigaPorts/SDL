---
title: F / Serial Shift Register (SDR) / Input Mode
manual: hardware
chapter: hardware
section: f-serial-shift-register-sdr-input-mode
functions: []
libraries: []
---

# F / Serial Shift Register (SDR) / Input Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In input mode, data on the SP pin is shifted into the shift register on
the rising edge of the signal applied to the CNT pin. After eight CNT
pulses, the data in the shift register is dumped into the serial data
register and an interrupt is generated.


---
title: 8 / Serial I/O Interface / Specifying The Register Contents
manual: hardware
chapter: hardware
section: 8-serial-i-o-interface-specifying-the-register-contents
functions: []
libraries: []
---

# 8 / Serial I/O Interface / Specifying The Register Contents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The data to be transmitted is placed in the output register ( [SERDAT](hardware/8-serial-i-o-interface-how-output-data-is-transmitted.md) ).
Above the data bits, 1 bits must be added as stop bits. Normally, either
one or two stop bits are sent.

The transmission of the start bit is independent of the contents of this
register. One start bit is automatically generated before the first data
bit (bit 0) is sent.

Writing this register starts the data transmission. If this register is
written with all zeros, no data transmission is initiated.


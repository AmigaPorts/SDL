---
title: F 8520 Complex Interface Adapters / Hardware Connection Details
manual: hardware
chapter: hardware
section: f-8520-complex-interface-adapters-hardware-connection
functions: []
libraries: []
---

# F 8520 Complex Interface Adapters / Hardware Connection Details

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system hardware selects the CIAs when the upper three address bits are
101.  Furthermore, CIAA is selected when A12 is low, A13 high; CIAB is
selected when A12 is high, A13 low.  CIAA communicates on data bits 7-0,
CIAB communicates on data bits 15-8.

Address bits A11, A10, A9, and A8 are used to specify which of the 16
internal registers you want to access.  This is indicated by "r" in the
address.  All other bits are don't cares.  So, CIAA is selected by the
following binary address:  101x xxxx xx01 rrrr xxxx xxx0. CIAB address:
101x xxxx xx10 rrrr xxxx xxx1

With future expansion in mind, we have decided on the following addresses:
CIAA = BFEr01; CIAB = BFDr00.  Software must use byte accesses to these
address, and no other.

 [Interface Signals](hardware/f-hardware-connection-details-interface-signals.md) 


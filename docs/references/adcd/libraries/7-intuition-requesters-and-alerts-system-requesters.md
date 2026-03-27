---
title: 7 Intuition Requesters and Alerts / System Requesters
manual: libraries
chapter: libraries
section: 7-intuition-requesters-and-alerts-system-requesters
functions: [ModifyIDCMP]
libraries: [intuition.library]
---

# 7 Intuition Requesters and Alerts / System Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

System requesters, such as DOS requests to "Insert volume foo in any
drive,"  are created by the system using [EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md).  Unless otherwise
specified, these requests appear on the default public screen.

System requests may appear at any time the system requires a resource that
is not available.  The user may be in the middle of an action, the program
may be in any state.

Use the function [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) to turn off all verify messages before
calling any function that might generate a system requester.  Neglecting
to do so can cause situations where Intuition is waiting for the return of
a message which the application program is unable to receive because its
input is shut off while the requester is up.  If Intuition finds itself in
a deadlock state, the verify function will timeout and be automatically
replied.

 [Redirecting System Requesters](libraries/7-system-requesters-redirecting-system-requesters.md) 

---

## See Also

- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)

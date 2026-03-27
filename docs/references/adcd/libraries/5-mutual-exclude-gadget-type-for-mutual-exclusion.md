---
title: 5 / / Mutual Exclude / Gadget Type for Mutual Exclusion
manual: libraries
chapter: libraries
section: 5-mutual-exclude-gadget-type-for-mutual-exclusion
functions: []
libraries: []
---

# 5 / / Mutual Exclude / Gadget Type for Mutual Exclusion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To implement mutual exclusion, gadgets must be hit-select (not
[GACT_TOGGLESELECT](libraries/5-gadget-structure-gadget-activation-flags.md)) [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets, with the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) activation
type (never [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md)).  All state changes must be executed upon
receiving the [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) message for the gadgets.  Failure to do
this could introduce subtle out-of-phase imagery problems.


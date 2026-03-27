---
title: 5 / Boolean Gadget Type / Mutual Exclude
manual: libraries
chapter: libraries
section: 5-boolean-gadget-type-mutual-exclude
functions: []
libraries: []
---

# 5 / Boolean Gadget Type / Mutual Exclude

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Mutual exclusion of [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets (sometimes referred to as "radio
buttons") is not directly supported by Intuition.  This section describes
the method an application should use to implement this feature.  It is up
to the application to handle the manipulation of excluded gadgets in an
Intuition compatible way.  The program must proceed with caution so as to
maintain the synchronization of the gadget and its imagery.  The rules
provided in this section for the implementation of mutual exclude gadgets
minimize the risk and complexity of the application.  Other techniques may
seem to work with simple input, but may fail in subtle ways when stressed.

 [Gadget Type for Mutual Exclusion](libraries/5-mutual-exclude-gadget-type-for-mutual-exclusion.md) 
 [Gadget Highlighting for Mutual Exclusion](libraries/5-mutual-exclude-gadget-highlighting-for-mutual-exclusion.md) 
 [Handling of Mutually Exclusive Gadgets](libraries/5-mutual-exclude-handling-of-mutually-exclusive-gadgets.md) 


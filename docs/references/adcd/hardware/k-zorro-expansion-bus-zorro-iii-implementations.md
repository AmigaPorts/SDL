---
title: K Zorro Expansion Bus / Zorro III Implementations
manual: hardware
chapter: hardware
section: k-zorro-expansion-bus-zorro-iii-implementations
functions: []
libraries: []
---

# K Zorro Expansion Bus / Zorro III Implementations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Functionally, there are two possible implementation levels in existance
for the Zorro III bus.  All of the features described in this chapter are
required for a full compliance Zorro III bus.  However, the original Amiga
3000 computers were shipped with a bus controller that supported only a
subset of the Zorro III specification published here.  This is, however,
upgradable.

The A3000 implementation of the Zorro III bus is driven by a custom
controller chip called Fat Buster.  The specification of this chip and the
A3000 hardware are fully capable of supporting the complete Zorro III bus,
but the initial silicon on Fat Buster, called the Level 1 Fat Buster,
omits some features.  Missing are: support of  [Multiple Transfer Cycles](hardware/k-zorro-iii-bus-architecture-multiple-transfer-cycles.md) ;
support for Zorro III style bus arbitration; support for
 [Quick Interrupts](hardware/k-zorro-iii-bus-architecture-quick-interrupts.md) .

The Level 2 version of Fat Buster has been in testing for some time at
Commodore in West Chester, PA. Any developers who immediately intend to
design PICs supporting these features are urged to contact Amiga, Inc.
 [Technical Support](hardware/1-introduction-applications-technical-support-cats.md) /Amiga Developer Support for more information on
obtaining samples of this part for use in A3000 systems. These parts are
likely to be introduced into production, and available as part of an A3000
upgrade, very soon.  All Buster chip revisions "13G" and earlier support
the Level 1 features.  Buster chip revisions "13H" and later support Level
2 features and improved Level 1 features as well.


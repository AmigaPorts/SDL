---
title: 28 / / Specifying Animation Components / Position of an AnimComp
manual: libraries
chapter: libraries
section: 28-specifying-animation-components-position-of-an-animcomp
functions: []
libraries: []
---

# 28 / / Specifying Animation Components / Position of an AnimComp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To specify the placement of each [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) relative to its controlling
[AnimOb](libraries/28-animation-with-gels-animation-data-structures.md), you set the AnimComp members [XTrans](autodocs-2.0/includes-graphics-gels-h.md) and [YTrans](autodocs-2.0/includes-graphics-gels-h.md).  These values can
be positive or negative.

The system is designed so that only one of the [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)s in any given
sequence is "active" (being displayed) at a given point in time.  It is
the only image in the sequence that is (or is about to be) linked into the
[GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list. The [Timer](libraries/28-animation-components-specifying-time-for-each-image.md) determines how long each Component in the
sequence remains active, as described below.


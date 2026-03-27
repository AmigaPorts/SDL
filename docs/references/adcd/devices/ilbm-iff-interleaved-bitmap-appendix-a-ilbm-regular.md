---
title: ILBM IFF Interleaved Bitmap / Appendix A. ILBM Regular Expression
manual: devices
chapter: devices
section: ilbm-iff-interleaved-bitmap-appendix-a-ilbm-regular
functions: []
libraries: []
---

# ILBM IFF Interleaved Bitmap / Appendix A. ILBM Regular Expression

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a regular expression summary of the FORM ILBM syntax.  This could
be an IFF file or a part of one.


```c
    ILBM ::= "FORM" #{    "ILBM" BMHD [CMAP] [GRAB] [DEST] [SPRT] [CAMG]
                            CRNG* CCRT* [BODY]    }

    BMHD ::= "BMHD" #{    BitMapHeader    }
    CMAP ::= "CMAP" #{    (red green blue)*    } [0]
    GRAB ::= "GRAB" #{    Point2D    }
    DEST ::= "DEST" #{    DestMerge    }
    SPRT ::= "SPRT" #{    SpritePrecedence    }
    CAMG ::= "CAMG" #{    LONG    }

    CRNG ::= "CRNG" #{    CRange    }
    CCRT ::= "CCRT" #{    CycleInfo    }
    BODY ::= "BODY" #{    UBYTE*    } [0]
```
The token "#" represents a ckSize LONG count of the following {braced}
data bytes.  E.g., a [BMHD](devices/standard-properties-bmhd.md)'s "#" should equal sizeof(BitMapHeader).
Literal strings are shown in "quotes", [square bracket items] are
optional, and "*" means 0 or more repetitions.  A sometimes-needed pad
byte is shown as "[0]".

The property chunks [BMHD](devices/standard-properties-bmhd.md), [CMAP](devices/standard-properties-cmap.md), [GRAB](devices/standard-properties-grab.md), [DEST](devices/standard-properties-dest.md), [SPRT](devices/standard-properties-sprt.md), [CAMG](devices/standard-properties-camg.md) and any CRNG and
CCRT data chunks may actually be in any order but all must appear before
the [BODY](devices/standard-body-data-chunk-body.md) chunk since ILBM readers usually stop as soon as they read the
BODY.  If any of the 6 property chunks are missing, default values are
inherited from any shared properties (if the ILBM appears inside an IFF
[LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) with [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)s) or from the reader program's defaults.  If any property
appears more than once, the last occurrence before the BODY is the one
that counts since that's the one that modifies the BODY.


# ILBM IFF Interleaved Bitmap / Appendix A. ILBM Regular Expression


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
data bytes.  E.g., a [BMHD](../Devices_Manual_guide/node01AF.html)'s "#" should equal sizeof(BitMapHeader).
Literal strings are shown in "quotes", [square bracket items] are
optional, and "*" means 0 or more repetitions.  A sometimes-needed pad
byte is shown as "[0]".

The property chunks [BMHD](../Devices_Manual_guide/node01AF.html), [CMAP](../Devices_Manual_guide/node01B0.html), [GRAB](../Devices_Manual_guide/node01B1.html), [DEST](../Devices_Manual_guide/node01B2.html), [SPRT](../Devices_Manual_guide/node01B3.html), [CAMG](../Devices_Manual_guide/node01B4.html) and any CRNG and
CCRT data chunks may actually be in any order but all must appear before
the [BODY](../Devices_Manual_guide/node01B7.html) chunk since ILBM readers usually stop as soon as they read the
BODY.  If any of the 6 property chunks are missing, default values are
inherited from any shared properties (if the ILBM appears inside an IFF
[LIST](../Devices_Manual_guide/node01CA.html#line49) with [PROP](../Devices_Manual_guide/node01CA.html#line49)s) or from the reader program's defaults.  If any property
appears more than once, the last occurrence before the BODY is the one
that counts since that's the one that modifies the BODY.


---
title: Appendix A. Quick Reference / 8SVX Regular Expression
manual: devices
chapter: devices
section: appendix-a-quick-reference-8svx-regular-expression
functions: []
libraries: []
---

# Appendix A. Quick Reference / 8SVX Regular Expression

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a regular expression summary of the [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) syntax.  This could
be an IFF file or part of one.


```c
    8SVX     ::= "FORM" #{  "8SVX" VHDR [NAME] [Copyright] [AUTH] ANNO*
                            [ATAK] [RLSE] BODY }

    VHDR     ::= "VHDR" #{ Voice8Header     }
    NAME     ::= "NAME" #{ CHAR*    } [0]
    Copyright::= "(c) " #{ CHAR*    } [0]
    AUTH     ::= "AUTH" #{ CHAR*    } [0]
    ANNO     ::= "ANNO" #{ CHAR*    } [0]

    ATAK     ::= "ATAK" #{ EGPoint* }
    RLSE     ::= "RLSE" #{ EGPoint* }
    BODY     ::= "FORM" #{ BYTE*    } [0]
```
The token "#" represents a ckSize LONG count of the following {braced}
data bytes.  E.g., a [VHDR](devices/standard-data-and-property-chunks-required-property-vhdr.md)'s "#" should equal sizeof(Voice8Header).
Literal items are shown in "quotes", [square bracket items] are optional,
and "*" means 0 or more replications.  A sometimes-needed pad byte is
shown as "[0]".

Actually, the order of chunks in a [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) is not as strict as this
regular expression indicates.  The property chunks [VHDR](devices/standard-data-and-property-chunks-required-property-vhdr.md), NAME, Copyright,
and AUTH may actually appear in any order as long as they all precede the
[BODY](devices/standard-data-and-property-chunks-data-chunk-body.md) chunk.  The optional data chunks ANNO, [ATAK](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md), and [RLSE](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md) don't have to
precede the BODY chunk.  And of course, new kinds of chunks may appear
inside a [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) in the future.


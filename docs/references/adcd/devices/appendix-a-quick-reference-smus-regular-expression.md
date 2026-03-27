---
title: Appendix A. Quick Reference / SMUS Regular Expression
manual: devices
chapter: devices
section: appendix-a-quick-reference-smus-regular-expression
functions: []
libraries: []
---

# Appendix A. Quick Reference / SMUS Regular Expression

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a regular expression summary of the FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) syntax.  This could
be an IFF file or part of one.


```c
    SMUS      ::= "FORM" #{ "SMUS" SHDR [NAME] [Copyright] [AUTH] [IRev]
                            ANNO* INS1*  TRAK*  InstrForm* }

    SHDR      ::= "SHDR" #{ SScoreHeader    }
    NAME      ::= "NAME" #{ CHAR*   } [0]
    Copyright ::= "(c) " #{ CHAR*   } [0]
    AUTH      ::= "AUTH" #{ CHAR*   } [0]
    IRev      ::= "IRev" #{ ...     }

    ANNO      ::= "ANNO" #{ CHAR*   } [0]
    INS1      ::= "INS1" #{ RefInstrument   } [0]

    TRAK      ::= "TRAK" #{ SEvent* }
    InstrForm ::= "FORM" #{ ...     }
```
The token "#" represents a ckSize LONG count of the following {braced}
data bytes.  Literal items are shown in "quotes", [square bracket items]
are optional, and "*" means 0 or more replications.  A sometimes-needed
pad byte is shown as "[0]".

Actually, the order of chunks in a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) is not as strict as this
regular expression indicates.  The [SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md), [NAME](devices/standard-data-and-property-chunks-optional-text-chunks-2.md), [Copyright](devices/standard-data-and-property-chunks-optional-text-chunks-2.md), [AUTH](devices/standard-data-and-property-chunks-optional-text-chunks-2.md), [IRev](devices/standard-data-and-property-chunks-optional-text-chunks-2.md),
[ANNO](devices/standard-data-and-property-chunks-optional-text-chunks-2.md), and [INS1](devices/standard-data-and-property-chunks-optional-property-ins1.md) chunks may appear in any order, as long as they precede the
[TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) chunks.

The chunk "InstrForm" represents any kind of instrument data [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) embedded
in the FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  For example, see the document "8SVX" IFF 8-Bit Sampled
Voice. Of course, a recipient program will ignore an instrument FORM if it
doesn't recognize that FORM type.


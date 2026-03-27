# Appendix A. Quick Reference / SMUS Regular Expression


Here's a regular expression summary of the FORM [SMUS](../Devices_Manual_guide/node02AB.html) syntax.  This could
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

Actually, the order of chunks in a FORM [SMUS](../Devices_Manual_guide/node02AB.html) is not as strict as this
regular expression indicates.  The [SHDR](../Devices_Manual_guide/node02B3.html), [NAME](../Devices_Manual_guide/node02B4.html), [Copyright](../Devices_Manual_guide/node02B4.html), [AUTH](../Devices_Manual_guide/node02B4.html), [IRev](../Devices_Manual_guide/node02B4.html),
[ANNO](../Devices_Manual_guide/node02B4.html), and [INS1](../Devices_Manual_guide/node02B5.html) chunks may appear in any order, as long as they precede the
[TRAK](../Devices_Manual_guide/node02B7.html) chunks.

The chunk "InstrForm" represents any kind of instrument data [FORM](../Devices_Manual_guide/node01C7.html#line51) embedded
in the FORM [SMUS](../Devices_Manual_guide/node02AB.html).  For example, see the document "8SVX" IFF 8-Bit Sampled
Voice. Of course, a recipient program will ignore an instrument FORM if it
doesn't recognize that FORM type.


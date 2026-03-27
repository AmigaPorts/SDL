# Appendix A. Quick Reference / 8SVX Regular Expression


Here's a regular expression summary of the [FORM 8SVX](../Devices_Manual_guide/node02C9.html) syntax.  This could
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
data bytes.  E.g., a [VHDR](../Devices_Manual_guide/node02CD.html)'s "#" should equal sizeof(Voice8Header).
Literal items are shown in "quotes", [square bracket items] are optional,
and "*" means 0 or more replications.  A sometimes-needed pad byte is
shown as "[0]".

Actually, the order of chunks in a [FORM 8SVX](../Devices_Manual_guide/node02C9.html) is not as strict as this
regular expression indicates.  The property chunks [VHDR](../Devices_Manual_guide/node02CD.html), NAME, Copyright,
and AUTH may actually appear in any order as long as they all precede the
[BODY](../Devices_Manual_guide/node02D0.html) chunk.  The optional data chunks ANNO, [ATAK](../Devices_Manual_guide/node02CF.html), and [RLSE](../Devices_Manual_guide/node02CF.html) don't have to
precede the BODY chunk.  And of course, new kinds of chunks may appear
inside a [FORM 8SVX](../Devices_Manual_guide/node02C9.html) in the future.


---
title: MTRX.doc / Chunks
manual: devices
chapter: devices
section: mtrx-doc-chunks
functions: []
libraries: []
---

# MTRX.doc / Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The MTRX FORM is composed of the definition of the structure, followed by
the BODY which contains the data which is defined.  Usually, there is only
one set of data, but a smarter IFF read could use the definition as a
PROPerty, with identically formatted data sets (BODYs) in a LIST.

  FORM MTRX

```c
    definition (ARRY | STRU | DTYP)
    BODY
```
ARRY: The array chunk defines a counted list of similar items. The first
(required) chunk in an ARRY is ELEM, which gives the number of elements in
the array.  Optionally, there may be limits given, (LOWR and UPPR), which
could be used in scaling during sampling of the data. Lastly is the
definition of an element of the array, which may be a nested definition
like everything else.

  ARRY ::= "ARRY" #{ ELEM [LOWR] [UPPR] [PACK] ARRY|STRU|DTYP }

STRU: The structure chunk defines a counted list of dissimilar things. The
first (required) chunk in a STRU is FLDS, which gives the number of fields
in the structure.  Lastly are definitions of each field in the structure.
Again, each field may have a nested definition like everything else.

 STRU ::= "STRU" #{ FLDS ([PACK] ARRY|STRU|DTYP)* }

VALU: The value contains a datatype, and then a constant of that type. The
datatype contains the size of the constant, so this chunk has variable
size.  VALU is used in the ARRY chunk to give the scaling limits of the
array.

BODY: This is the actual data we went to so much effort to describe. It is
stored in "row-first" format, that is, items at the bottom of the nested
description are stored next to each other.  In most cases, it should be
sufficient to simply block-read the whole chunk from disk, unless the
reader needs to adjust byte-ordering or store in a more time-efficient
format in memory.  Data is assumed to be byte-aligned.

PACK: The PACK chunk is necessary when the bit length of the data is not a
multiple of 8, that is, not byte-aligned, and the user wishes to conserve
space by packing data items together.  PACK is simply a number - the
number of items to bit-pack before aligning on a byte. A PACK is in effect
for the remainder of its nested scope, or until overridden by a new
specification.  A STRU or ARRY is assumed to have a PACK of 1 by default -
it is not affected by PACKs in definitions above. A PACK of 0 means to
byte-align before processing the next definition. The PACK specifier
should be normalized.  For example, when packing a large array of 3-bit
numbers, PACK should be 8 since 3*8 = 24. In this case 8 is the smallest
PACK number which aligns on a byte naturally.

DTYP: The DataType is the most interesting chunk, as it attempts to define
every conceivable type of numeric data with 32 bits.  The 32 bits are
broken down into three fields, 1) the size in bits, 2) the Class, and 3)
SubClass. The Class makes the most major distinction, separating integers
from floating point numbers from Binary Coded Decimal and etc.  Within
each class is a SubClass, which gives the specific encoding used.
Finally, the Size tells what how much room the data occupies.  The basic
division of datatypes is given in the tree structure below.


```c
    Class             SubClass     Size  Final Specific Type
    =====             ========     ====  ===================
     |
    Binary Unsigned - 0 ------------ 8   UByte
     |                              16   UWord
     |                              32   ULong
     |
    Binary Signed --- 0 ------------  8  Byte
     |                               16  Word
     |                               32  ULong
     |
    Real ------------Ieee38 -------- 32  Ieee Single Precision
     |                |
     |               Ieee308 ------- 64  Double Precision
     |                |              32  Truncated Double Precision
     |                |
     |               FFP ----------- 32  Motorola Fast Floating Point
     |
    Text ----------- Text0 --------- ??  Null-terminated text
     |                |
     |               CText --------- ??  Number of characters in first byte
     |                |
     |               FText --------- ??  Fixed length, space padded
     |
    BCD ------------ Nibble -------- ??
                      |
                     Character ----- ??
```
A design goal was to create a classification system which other people can
easily plug into.  Many data types are simply size variations on existing
data types.  For example, a 4-bit integer can be specified by giving the
size as four bits in the Signed Binary class.  Be aware that not all MTRX
readers may support your new type, but there will not be any type clashes
or ambiguities by following these rules.  If you have a truly unique Class
or SubClass, you will need to register it with Commodore to prevent
clashes.

A second design goal was to create a format which is easily decoded by
software.  By aligning fields on bytes, you have the option of redefining
the datatype as a structure, so as to avoid shifting when accessing the
fields.  Since the numbers are sequentially assigned, they are suitable as
array indicies, and may be optimized in a C switch statement.

A third design goal was allowing for naive and sophisticated readers. In
checking for a certain datatype, a naive reader can simply compare the
whole datatype with a small set of known types, which assumes that each
different Size defines a unique datatype.  Sophisticated readers will
consider the Class, SubClass and Size separately, so as to support
arbitrary size integers, and truncated Floating Point numbers, for example.

 *
 * MTRX ::= "FORM" #{ "MTRX" ARRY|STRU|DTYP BODY       } Matrix
 * ARRY ::= "ARRY" #{ ELEM [LOWR] [UPPR] [PACK] ARRY|STRU|DTYP } Array
 * STRU ::= "STRU" #{ FLDS ([PACK] ARRY|STRU|DTYP)*    } Structure
 * ELEM ::= "ELEM" #{ elements                         } Array elements
 * LOWR ::= "LOWR"  { VALU                             } Minimum limit
 * UPPR ::= "UPPR"  { VALU                             } Maximum limit
 * VALU ::=        #{ dtyp value                       } Value (in union)
 * dtyp ::=         { size, subclass, class            } Data Type (scalar)
 * DTYP ::= "DTYP" #{ dtyp                             }
 * FLDS ::= "FLDS" #{ number of fields                 } Number of Fields
 * PACK ::= "PACK" #{ units packed b4 byte alignment   } Packing
 * BODY ::= "BODY" #{ inner-first binary dump          } Data
 *
 *   [] means optional
 *   #  means the size of the unit following
 *   *  means one or more of
 *


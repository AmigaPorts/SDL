# Data Sections / Group FORM


A data section is a [chunk](../Devices_Manual_guide/node01DD.html) with ckID "[FORM](../Devices_Manual_guide/node01C7.html#line52)" and this arrangement:


```c
    FORM       ::= "FORM" #{ FormType (LocalChunk | FORM | LIST | CAT)* }
    FormType   ::= ID
    LocalChunk ::= Property | Chunk
```
The ID "[FORM](../Devices_Manual_guide/node01C7.html#line52)" is a syntactic keyword like "struct" in C.  Think of a
"struct [ILBM](../Devices_Manual_guide/node01AC.html)" containing a field "[CMAP](../Devices_Manual_guide/node01B0.html)".  If you see "FORM" you will know
to expect a FORM type ID (the structure name, "[ILBM](../Devices_Manual_guide/node01AC.html)" in this example) and
a particular contents arrangement or "syntax" (local [chunk](../Devices_Manual_guide/node01DD.html), FORMs, [LIST](../Devices_Manual_guide/node01CA.html#line49)s,
and [CAT](../Devices_Manual_guide/node01CA.html#line2) ).  A "FORM ILBM", in particular, might contain a local chunk
"CMAP", an "ILBM.CMAP" (to use a qualified name).

So the [chunk](../Devices_Manual_guide/node01DD.html) ID "[FORM](../Devices_Manual_guide/node01C7.html#line52)" indicates a data section.  It implies that the
[chunk](../Devices_Manual_guide/node01DD.html) contains an ID and some number of nested chunks.  In reading a FORM,
like any other chunk, programs must respect its ckSize as a virtual
end-of-file for reading its contents, even if they're truncated.

The [FORM](../Devices_Manual_guide/node01C7.html#line52) type is a restricted ID that may not contain lower case letters
or punctuation characters.  (Cf. Type IDs.  Cf. Single Purpose Files.)

The type-specific information in a [FORM](../Devices_Manual_guide/node01C7.html#line52) is composed of its "local [chunk](../Devices_Manual_guide/node01DD.html)s":
data properties and other [chunk](../Devices_Manual_guide/node01DD.html)s.  Each FORM type is a local name space
for local [chunk](../Devices_Manual_guide/node01DD.html) IDs.  So "[CMAP](../Devices_Manual_guide/node01B0.html)" local [chunk](../Devices_Manual_guide/node01DD.html)s in other FORM types may be
unrelated to "ILBM.CMA"".  More than that, each FORM type defines semantic
scope.  If you know what a FORM [ILBM](../Devices_Manual_guide/node01AC.html) is, you will know what an ILBM.[CMAP](../Devices_Manual_guide/node01B0.html)
is.

Local [chunk](../Devices_Manual_guide/node01DD.html)s defined when the [FORM](../Devices_Manual_guide/node01C7.html#line52) type is designed (and therefore known
to all clients of this type) are called "standard" while specialized ones
added later are "nonstandard".

Among the local [chunk](../Devices_Manual_guide/node01DD.html)s, property chunks give settings for various details
like text font while the other chunks supply the essential information.
This distinction is not clear cut.  A property setting can be cancelled by
a later setting of the same property.  E.g., in the sequence:

	prop1 = x  (Data A)  prop1 = z  prop1 = y (Data B)

prop1 is = x for Data A, and y for Data B.  The setting prop1 = z has no
effect.

For clarity, the universally reserved [chunk](../Devices_Manual_guide/node01DD.html) IDs "[LIST](../Devices_Manual_guide/node01CA.html#line49)", "[FORM](../Devices_Manual_guide/node01C7.html#line52)", "[PROP](../Devices_Manual_guide/node01CA.html#line49)",
"[CAT](../Devices_Manual_guide/node01CA.html#line2) ", "    ", "LIS1" through "LIS9", "FOR1" through "FOR9", and "CAT1"
through "CAT9" may not be FORM type IDs.

Part 5, below, talks about grouping [FORM](../Devices_Manual_guide/node01C7.html#line52)s into [LIST](../Devices_Manual_guide/node01CA.html#line49)s and [CAT](../Devices_Manual_guide/node01CA.html#line2) s.  They let
you group a bunch of FORMs but don't impose any particular meaning or
constraints on the grouping.  Read on.


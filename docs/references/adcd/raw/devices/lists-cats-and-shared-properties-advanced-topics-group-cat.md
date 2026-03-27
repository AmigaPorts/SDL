# LISTs, CATs, and Shared Properties (Advanced topics) / Group CAT


A [CAT](../Devices_Manual_guide/node01CA.html#line2)  is just an untyped group of data objects.

Structurally, a [CAT](../Devices_Manual_guide/node01CA.html#line2)  is a [chunk](../Devices_Manual_guide/node01DD.html) with [chunk](../Devices_Manual_guide/node01DD.html) ID "CAT " containing a "contents
type" ID followed by the nested objects.  The ckSize of each contained
chunk is essentially a relative pointer to the next one.

	CAT		::= "CAT " #{ ContentsType (FORM | LIST | CAT)* }
	ContentsType    ::= ID	- a hint or an "abstract data type" ID

In reading a [CAT](../Devices_Manual_guide/node01CA.html#line2) , like any other [chunk](../Devices_Manual_guide/node01DD.html), programs must respect its ckSize
as a virtual end-of-file for reading the nested objects even if they're
malformed or truncated.

The "contents type" following the [CAT](../Devices_Manual_guide/node01CA.html#line2) 's ckSize indicates what kind of
[FORM](../Devices_Manual_guide/node01C7.html#line52)s are inside.  So a CAT of [ILBM](../Devices_Manual_guide/node01AC.html)s would store "ILBM" there.  It's just
a hint. It may be used to store an "abstract data type".  A CAT could just
have blank contents ID ("    ") if it contains more than one kind of [FORM](../Devices_Manual_guide/node01C7.html#line52).

[CAT](../Devices_Manual_guide/node01CA.html#line2)  defines only the format of the group.  The group's meaning is open to
interpretation.  This is like a list in LISP: the structure of cells is
predefined but the meaning of the contents as, say, an association list
depends on use.  If you need a group with an enforced meaning (an
"abstract datatype" or Smalltalk "subclass"), some consistency
constraints, or additional data [chunk](../Devices_Manual_guide/node01DD.html)s, use a composite [FORM](../Devices_Manual_guide/node01C7.html#line52) instead (Cf.
Composite FORMs).

Since a [CAT](../Devices_Manual_guide/node01CA.html#line2)  just means a concatenation of objects, CATs are rarely nested.
Programs should really merge CATs rather than nest them.


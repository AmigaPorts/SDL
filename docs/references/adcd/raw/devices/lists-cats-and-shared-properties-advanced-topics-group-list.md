# LISTs, CATs, and Shared Properties (Advanced topics) / Group LIST


A [LIST](../Devices_Manual_guide/node01CA.html#line49) defines a group very much like [CAT](../Devices_Manual_guide/node01CA.html#line2)  but it also gives a scope for
[PROP](../Devices_Manual_guide/node01CA.html#line49)s (see below).  And unlike CATs, LISTs should not be merged without
understanding their contents.

Structurally, a [LIST](../Devices_Manual_guide/node01CA.html#line49) is a [chunk](../Devices_Manual_guide/node01DD.html) with ckID "LIST" containing a "contents
type" ID, optional shared properties, and the nested contents ([FORM](../Devices_Manual_guide/node01C7.html#line52)s,
LISTs, and [CAT](../Devices_Manual_guide/node01CA.html#line2) s), in that order.  The ckSize of each contained [chunk](../Devices_Manual_guide/node01DD.html) is a
relative pointer to the next one.  A LIST is not an arbitrary linked
list - the cells are simply concatenated.


```c
    LIST         ::= "LIST" #{ ContentsType PROP* (FORM | LIST | CAT)* }
    ContentsType ::= ID
```

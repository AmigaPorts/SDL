# 33 / / Storing LCIs / StoreLocalItem()


The [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html) function is called as follows:


```c
    error = StoreLocalItem (iff, lci, position);
```
The position argument determines where the [LCI](../Libraries_Manual_guide/node044A.html) is stored.  The possible
values are IFFSLI_ROOT, IFFSLI_TOP, and IFFSLI_PROP.

IFFSLI_ROOT causes [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html) to store your [LCI](../Libraries_Manual_guide/node044A.html) in the default
[ContextNode](../Libraries_Manual_guide/node0446.html).

IFFSLI_TOP gets your [LCI](../Libraries_Manual_guide/node044A.html) stored in the top (current) [ContextNode](../Libraries_Manual_guide/node0446.html).


```c
    The LCI Ends When the Current Context Ends.
    -------------------------------------------
    When the current context expires, your [LCI](../Libraries_Manual_guide/node044A.html) will be deleted by
    the parser.
```
IFFSLI_PROP causes your [LCI](../Libraries_Manual_guide/node044A.html) to be stored in the topmost context from which
a property would apply.  This is usually the topmost [FORM](../Libraries_Manual_guide/node042A.html#line7) or [LIST](../Libraries_Manual_guide/node042A.html#line7) chunk.
For example, suppose you had a deeply nested [ILBM FORM](../Libraries_Manual_guide/node045D.html#line8), and you wanted to
store the [BMHD](../Libraries_Manual_guide/node0461.html#line3) property in its correct context such that, when the current
FORM context expired, the BMHD property would be deleted.  IFFSLI_PROP
will cause [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html) to locate the proper context for such scoping,
and store the LCI there.  See the section on "[Finding the Prop Context](../Libraries_Manual_guide/node045B.html)"
for additional information on the scope of properties.


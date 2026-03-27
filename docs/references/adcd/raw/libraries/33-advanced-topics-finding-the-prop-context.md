# 33 / Advanced Topics / Finding The PROP Context


Earlier it was mentioned that supplying a position value of [IFFSLI_PROP](../Libraries_Manual_guide/node044E.html#line17) to
[StoreLocalItem()](../Libraries_Manual_guide/node044E.html) would store it in the topmost property scope.
[FindPropContext()](../Includes_and_Autodocs_2._guide/node01C4.html) is the routine that finds that topmost context.

Property chunks (such as the [BMHD](../Libraries_Manual_guide/node0461.html#line3), [CMAP](../Libraries_Manual_guide/node0461.html#line16), and others) have dominion over
the [FORM](../Libraries_Manual_guide/node042A.html#line7) that contains them; they are said to be "in scope" and their
definition persists until the FORM's context ends.  Thus, a property chunk
has a scoping level equal to the FORM that contains it; when the FORM
ends, the property dies with it.

Consider a more complicated example.  Suppose you have a [LIST](../Libraries_Manual_guide/node042A.html#line7) with a [PROP](../Libraries_Manual_guide/node042A.html#line7)
in it.  PROPs are the global variables of LISTs; thus a property chunk
declared in a PROP will persist until the LIST's context ends.

This is what [FindPropContext()](../Includes_and_Autodocs_2._guide/node01C4.html) is looking for; a context level in which a
property chunk may be installed.

[FindPropContext()](../Includes_and_Autodocs_2._guide/node01C4.html) starts at the parent of the current context (second from
the top of the context stack) and starts searching downward, looking for
the first [FORM](../Libraries_Manual_guide/node042A.html#line7) or [LIST](../Libraries_Manual_guide/node042A.html#line7) context it finds.  If it finds one, it returns a
pointer to that [ContextNode](../Libraries_Manual_guide/node0446.html).  If it can't find a suitable context level,
it returns NULL.

[FindPropContext()](../Includes_and_Autodocs_2._guide/node01C4.html) is called as follows:


```c
    struct ContextNode *cn;

    cn = FindPropContext (iff);
```

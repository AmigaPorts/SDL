# 33 / / Storing LCIs / FindLocalItem()


After you've stored your [LCI](../Libraries_Manual_guide/node044A.html) in a [ContextNode](../Libraries_Manual_guide/node0446.html), you will no doubt want to
be able to find it again later.  You do this with the function
[FindLocalItem()](../Includes_and_Autodocs_2._guide/node01C2.html), which is called as follows:


```c
    lci = FindLocalItem (iff, type, id, ident);
```
[FindLocalItem()](../Includes_and_Autodocs_2._guide/node01C2.html) attempts to locate an [LCI](../Libraries_Manual_guide/node044A.html) having the specified type, ID,
and identification values.  The search proceeds as follows (refer to
[Figure 33-3](../Libraries_Manual_guide/node044A.html#line6) to understand this better).

[FindLocalItem()](../Includes_and_Autodocs_2._guide/node01C2.html) starts at the top (current) [ContextNode](../Libraries_Manual_guide/node0446.html) and searches all
[LCI](../Libraries_Manual_guide/node044A.html)s in that context.  If no matching LCIs are found, it proceeds down the
context stack to the next ContextNode and searches all its LCIs.  The
process repeats until it finds the desired LCI (whereupon it returns a
pointer to it), or reaches the end without finding anything (where it
returns NULL).


```c
    Context Stack Position.
    -----------------------
    [LCI](../Libraries_Manual_guide/node044A.html)s higher in the stack will "override" lower LCIs with the
    same type, ID, and identification field.  This is how property
    scoping is handled.  As [ContextNode](../Libraries_Manual_guide/node0446.html)s are popped off the context
    stack, all its LCIs are deleted as well.  See the section on
    "[Freeing LCIs](../Libraries_Manual_guide/node045C.html)" below for additional information on deleting LCIs.
```

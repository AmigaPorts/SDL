# 33 IFFParse Library / Context Functions


Internally, IFFParse maintains [IFF](../Libraries_Manual_guide/node0428.html) nesting and scoping context via a
context stack.  The [PushChunk()](../Libraries_Manual_guide/node0441.html) and [PopChunk()](../Libraries_Manual_guide/node0442.html) functions get their names
from this basic idea of the iffparse.library.  Direct access to this stack
is not allowed.  However, many functions are provided to assist in
examining and manipulating the context stack.


    About the Context Stack.
    ------------------------
    It is probably easier to think of a stack of blocks on a table in
    front of you when reading this discussion.
As the nesting level increases (as would happen when parsing a nested [LIST](../Libraries_Manual_guide/node042A.html#line7)
or [FORM](../Libraries_Manual_guide/node042A.html#line7)), the depth of the context stack increases; new elements are added
to the top.  When these contexts expire, the [ContextNode](../Libraries_Manual_guide/node0446.html)s are deleted and
the stack shrinks.

 [Context Nodes](../Libraries_Manual_guide/node0446.html) 
 [The Default Context](../Libraries_Manual_guide/node0449.html) 
 [Context-Specific Data: LocalContextItems](../Libraries_Manual_guide/node044A.html) 
 [Storing LCIs](../Libraries_Manual_guide/node044D.html) 
 [Some Interesting Internal Details](../Libraries_Manual_guide/node0451.html) 


# reaction.lib/GetAttrs



   NAME

       GetAttrsA -- Get multiple object attributes
       GetAttrs -- Varargs stub to GetAttrsA
   SYNOPSIS

```c
       count = GetAttrsA( object, taglist )

       count = GetAttrs( object, tag, address, ... )

       ULONG GetAttrsA( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * )

       ULONG GetAttrs( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ... )
```
   FUNCTION

```c
       Gets multiple attributes of an object iin a single call.
       [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) that while the function returns the number of
       attributes that were getable, it can not inform WHICH
       attributes, if any, were not. Thus, you shouldn't use this
       function when you are not sure that an attribute is getable.
```
   INPUTS

       object - pointer to the object that should be queried
       taglist - a list of tag and ULONG address pairs to fill
   RESULTS

       The number of attributes that succeeded.

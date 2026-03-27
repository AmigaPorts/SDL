# 33 / / Controlling Parsing / PropChunk()/FindProp()


In the case of a [FORM ILBM](../Libraries_Manual_guide/node045D.html#line8), certain chunks are defined as being able to
appear in any order.  Among these are the [BMHD](../Libraries_Manual_guide/node0461.html#line3), [CMAP](../Libraries_Manual_guide/node0461.html#line16), and [CAMG](../Libraries_Manual_guide/node0461.html#line7). Typically,
BMHD appears first, followed by CMAP and CAMG, but you can't make this
assumption.  The [IFF](../Libraries_Manual_guide/node0428.html) and ILBM standards require you to assume these chunks
will appear in any order.  So ideally, what you'd like to do is collect
them as they arrive, but not do anything with them until you actually need
them.

This is where [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html) comes in.  The syntax for PropChunk() is
identical to [StopChunk()](../Libraries_Manual_guide/node0433.html):


```c
    error = PropChunk (iff, ID_ILBM, ID_BMHD);
```
When you call [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html), the parser will look for chunks declared with
[PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html).  When it sees them, the parser will internally copy the
contents of the chunk into memory for you before continuing its parsing.

When you're ready to examine the contents of the chunk, you use the
function [FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html):


```c
    StoredProperty = FindProp (iff, ID_ILBM, ID_BMHD);
```
[FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html) returns a pointer to a struct [StoredProperty](../Includes_and_Autodocs_2._guide/node010B.html#line90), which contains
the chunk size and data.  If the chunk was never encountered, NULL is
returned.  This permits you to process the property chunks in any order
you wish, regardless of how they appeared in the file.  This provides much
better control of data interpretation and also reduces headaches.  The
following fragment shows how [ILBM BitMapHeader](../Libraries_Manual_guide/node045F.html) data could be accessed
after using [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) with [PropChunk](../Includes_and_Autodocs_2._guide/node01D3.html)(iff, ID_ILBM, ID_BMHD):


```c
    struct StoredProperty *sp;      /* defined in iffparse.h */
    struct BitMapHeader *bmhd;      /* defined in IFF spec   */

    if (sp = FindProp(iff, ID_ILBM, ID_BMHD))
            {
            /* If property is BMHD, sp->sp_Data is ptr to data in BMHD */
            bmhd = (struct BitMapHeader *)sp->sp_Data;
            printf("BMHD: PageWidth      = %ld\n",bmhd->PageWidth);
            }
```

# reaction.lib/LBRemNode



   NAME

```c
       LBRemNode -- V41 listbrowser.gadget [LBM_REMNODE](../Includes_and_Autodocs_3._guide/node0443.html) method stub
```
   SYNOPSIS

```c
       node = LBRemNode( gadget, window, requester, node )

       ULONG LBRemNode( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
           struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) * );
```
   FUNCTION

```c
       A function stub for calling [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html) to remove and
       free a node from a listbrowser list. This function mostly
       exists for completeness's sake.
```
   INPUTS

```c
       gadget = listbrowser object
       window = the window in which the gadget is, or NULL
       requester = the requester of the window, or NULL
       node = the node to free
```
   RESULT

       Nonzero on success.
   NOTES

```c
       This function uses the [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html) function also
       defined in this link library.
```
   SEE ALSO

```c
       [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html)
```

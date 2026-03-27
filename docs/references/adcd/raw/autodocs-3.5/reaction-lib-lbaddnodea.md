# reaction.lib/LBAddNodeA



   NAME

```c
       LBAddNodeA -- V41 listbrowser.gadget [LBM_ADDNODE](../Includes_and_Autodocs_3._guide/node0441.html) method stub
       LBAddNode -- Varargs version of LBAddNodeA
```
   SYNOPSIS

```c
       node = LBAddNodeA( gadget, window, requester, node, tags )

       struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *LBAddNodeA( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
           struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

       node = LBAddNode( gadget, window, requester, node, tag, ... )

       struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *LBAddNode( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, sruct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
           struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, ULONG, ... );
```
   FUNCTION

```c
       A function stub for calling [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html) to allocate
       and add a new node to a listbrowser list. The main advantage
       of this function is to let you inline the vararg LBNA taglist.
```
   INPUTS

```c
       gadget = listbrowser object
       window = the window in which the gadget is, or NULL
       requester = the requester of the window, or NULL
       node = the node before which to add the new node. NULL for
           beginning of the list
       tags = the LBNA node allocation taglist
```
   RESULT

       A pointer to the newly allocated node, or NULL on failure.
   NOTES

```c
       This function uses the [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html) function also
       defined in this link library.
```
   SEE ALSO

```c
       [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html)
```

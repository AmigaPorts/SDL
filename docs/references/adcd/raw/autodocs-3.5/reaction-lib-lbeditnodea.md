# reaction.lib/LBEditNodeA



   NAME

```c
       LBEditNodeA -- V41 listbrowser.gadget [LBM_EDITNODE](../Includes_and_Autodocs_3._guide/node0442.html) method stub
       LBEditNode -- Varargs version of LBEditNodeA
```
   SYNOPSIS

```c
       success = LBEditNodeA( gadget, window, requester, node, tags )

       ULONG LBEditNodeA( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
           struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

       success = LBEditNode( gadget, window, requester, node, tag, ... )

       ULONG LBEditNode( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, sruct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
           struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, ULONG, ... );
```
   FUNCTION

```c
       A function stub for calling [LibDoGadgetMethodA()](../Includes_and_Autodocs_3._guide/node052F.html) to modify an
       existing node on a listbrowser list. The main advantage
       of this function is to let you inline the vararg LBNA taglist.
```
   INPUTS

```c
       gadget = listbrowser object
       window = the window in which the gadget is, or NULL
       requester = the requester of the window, or NULL
       node = the node to modify
       tags = the LBNA node modification taglist
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

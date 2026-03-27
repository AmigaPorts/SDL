# page_gc/SetPageGadgetAttrsA



   NAME

       SetPageGadgetAttrsA -- Set gadget attributes in a paged layout
       SetPageGadgetAttrs -- Varargs stub for SetPageGadgetAttrsA
   SYNOPSIS

```c
       value = SetPageGadgetAttrsA(gad, page, win, req, tags)
       D0                            A0     A1       A2   A3   A4

       ULONG SetPageGadgetAttrsA(struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *,
               struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

       ULONG SetPageGadgetAttrs(struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *,
               struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, ULONG, ...)
```
   FUNCTION

       Like SetGadgetAttrs, but passes a NULL window and requester pointer
       if the gadget is not on the currently visible page.

# page_gc/RefreshPageGadget



   NAME

       RefreshPageGadget -- Refresh gadget in a paged layout
   SYNOPSIS

```c
       RefreshPageGadget(gad, page, win, req)
                         A0     A1       A2   A3

       void RefreshPageGadget(struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *,
               struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *)
```
   FUNCTION

```c
       Like RefreshGList(gad,win,req,1), but passes a NULL window and
       requester pointer if the gadget is not on the currently visible
       page.
```

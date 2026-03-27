# reaction.lib/OpenLayoutWindowTagList



   NAME

```c
       OpenLayoutWindowTagList -- [Open](../Includes_and_Autodocs_3._guide/node0196.html) a window at a suitable size for layout
       OpenLayoutWindowTags -- Varags stub for OpenLayoutWindowTagList
```
   SYNOPSIS

```c
       window = OpenLayoutWindowTagList( layout, screen, taglist )

       struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *OpenLayoutWindowTagList( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *,
               struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, struct TagList * )

       window = OpenLayoutWindowTags( layout, screen, tag, ... )

       struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *OpenLayoutWindowTags( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *,
               struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ... )
```
   FUNCTION

```c
       Determines the minimum size that will fit a layout and opens the window
       at that size. The sizing limits of the window will be set according to
       the layout's limits, and the layout will be added to the window,
       making it relative to window size. The layout will fit the whole inner
       size of the window. It will not be rendered, so you must call
       [RefreshGadgets()](../Includes_and_Autodocs_3._guide/node03DC.html), possibly after adding your border gadgets.

       This function will set InnerWidth, InnerHeight, and the screen for the
       window. Other tags you have to pass yourself.
```
   INPUTS

       layout -- the layout hierarcy for the window
       screen -- pointer to the screen the window will be opened on
       taglist -- the additional tags for the window.
   RESULTS

       A pointer to the opened window or NULL if the open failed.

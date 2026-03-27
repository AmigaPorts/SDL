# layout_gc/LayoutLimits



  NAME

      LayoutLimits -- easy way to find out max and min size of layout
  SYNOPSIS

```c
      LayoutLimits( layout, limits, font, screen );
                    a0      a1      a2    a3

      void LayoutLimits( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct LayoutLimits *,
                              struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *, struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) * )
```
  FUNCTION

```c
      This function is an easy way of getting the minimum and maximum
      limit of the layout group. Effectively it create a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) and
      execute the GM_DOMAIN method for both minimum and maximum size
      of the object filling in the LayoutLimits structure with the size
      values. The font passed to this call will most likely affect the
      results, so use the font you will use with the window. If you
      pass a NULL for the font, the system default font (monospaced)
      will be used. If you pass the optional screen pointer, the
      gadget will be provided a [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65). This will let the gadget
      adjust to the aspect ratio of the screen.

      If you use the resulting size for [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) or [WindowLimits()](../Includes_and_Autodocs_3._guide/node0404.html),
      remember that the results do not include window borders.
```
  INPUTS

```c
      layout = the layout object to get the size on.
      limits = a pointer to the struct LayoutLimits to fill.
      font = the [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) to use on the domain requests. May be NULL
              for system default font.
      screen = optional pointer to the screen on which the layout
              will be used on, or NULL.
```
  NOTES

```c
      This function will invoke the object's GM_DOMAIN method twice,
      with a NULL [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24). If you call it providing a screen
      pointer, the taglist of the message will contain that screen's
      [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) (GA_DrawInfo) for aspect information.
```
  SEE ALSO

      gadgetclass/GM_DOMAIN

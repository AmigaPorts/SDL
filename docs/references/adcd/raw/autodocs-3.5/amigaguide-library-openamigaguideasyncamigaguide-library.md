# amigaguide.library/OpenAmigaGuideAsyncAmigaguide.library/OpenAmigaGuideAsyncA



   NAME

```c
        OpenAmigaGuideAsyncA - [Open](../Includes_and_Autodocs_3._guide/node0196.html) an AmigaGuide database async (V34)
```
   SYNOPSIS

```c
        handle = OpenAmigaGuideAsyncA (nag, attrs);
        d0                              a0   d0

        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) OpenAmigaGuideAsyncA (struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) *,
                                                struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

        handle = OpenAmigaGuideAsync (nag, tag1, ...);

        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) OpenAmigaGuideAsyncA (struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) *,
                                                [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1, ...);
```
   FUNCTION

```c
        Opens an AmigaGuide database for ansynchronous use.

        The [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) structure, and its pointers, must stay valid until
        an ActiveToolID or ToolStatusID message is received by the calling
        process.

        This function actually spawns OpenAmigaGuide() as another process,
        so, for further documentation, refer to the OpenAmigaGuide()
        function.
```
   INPUTS

```c
        nag -- Pointer to a valid [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) structure.
            (see OpenAmigaGuide() for documentation on its useage).

        attrs -- Additional attributes.  See [OpenAmigaGuideA()](../Includes_and_Autodocs_3._guide/node000E.html).
```
   RETURNS

        handle -- Handle to an AmigaGuide system.
   SEE ALSO

```c
        [OpenAmigaGuideA()](../Includes_and_Autodocs_3._guide/node000E.html), [CloseAmigaGuide()](../Includes_and_Autodocs_3._guide/node0009.html)
```

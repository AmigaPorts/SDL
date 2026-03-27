# amigaguide.library/ReplyAmigaGuideMsg



   NAME

```c
        ReplyAmigaGuideMsg - Reply to an AmigaGuide message.    (V34)
```
   SYNOPSIS

```c
        ReplyAmigaGuideMsg ( msg );
                             a0

        VOID ReplyAmigaGuideMsg (struct [AmigaGuideMsg](../Includes_and_Autodocs_3._guide/node05D2.html#line88) *msg);
```
   FUNCTION

        This function is used to reply to an AmigaGuide SIPC message.
   INPUTS

```c
        msg - Pointer to a SIPC message returned by a previous call to
            [GetAmigaGuideMsg()](../Includes_and_Autodocs_3._guide/node000B.html).
```
   SEE ALSO

```c
        [OpenAmigaGuideAsyncA()](../Includes_and_Autodocs_3._guide/node000F.html), [AmigaGuideSignal()](../Includes_and_Autodocs_3._guide/node0008.html), [GetAmigaGuideMsg()](../Includes_and_Autodocs_3._guide/node000B.html)
```

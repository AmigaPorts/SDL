# amigaguide.library/AmigaGuideSignal



   NAME

```c
        AmigaGuideSignal - Obtain aysnc AmigaGuide signal.      (V34)
```
   SYNOPSIS

```c
        signal = AmigaGuideSignal ( handle );
        d0                           a0

        ULONG AmigaGuideSignal (AMIGAGUIDECONTEXT);
```
   FUNCTION

```c
        This function returns the signal bit to [Wait](../Includes_and_Autodocs_3._guide/node0246.html) on for AmigaGuideMsg's
        for a particular AmigaGuide database.
```
   INPUTS

        handle -- Handle to a AmigaGuide system.
   EXAMPLE

```c
        ULONG sigw, sigh;
        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) handle;

        /* get the signal bit to wait on for a AmigaGuide message */
        sigh = AmigaGuideSignal(handle);

        /* add the signal bit into the total signals to wait on */
        sigw |= sigh;
```
   RETURNS

```c
        signal -- [Signal](../Includes_and_Autodocs_3._guide/node023D.html) bit to [Wait](../Includes_and_Autodocs_3._guide/node0246.html) on.
```
   SEE ALSO

```c
        [OpenAmigaGuideAsyncA()](../Includes_and_Autodocs_3._guide/node000F.html), [GetAmigaGuideMsg()](../Includes_and_Autodocs_3._guide/node000B.html), [ReplyAmigaGuideMsg()](../Includes_and_Autodocs_3._guide/node0011.html)
```

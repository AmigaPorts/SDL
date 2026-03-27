# 16 / Calling Functions / Parameters Passed to Custom Hook Functions


A requester always passes three parameters to your custom hook function:


```c
    ULONG MyHookFunc(ULONG type, CPTR object, CPTR AslRequester)
```
If MyHookFunc() is called from a file requester doing [_DOWILDFUNC](../Libraries_Manual_guide/node0283.html#line8), the
three parameters are:




```c
    type = [FILF_DOWILDFUNC](../Libraries_Manual_guide/node0283.html#line8)

    object = pointer to an AnchorPath structure (from <dos/[dosasl.h](../Includes_and_Autodocs_2._guide/node0070.html#line52)>)

    AslRequester = pointer to the [FileRequester](../Libraries_Manual_guide/node027B.html#line15) that called the hook
                   function (Return a zero to display this file)
```
The [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line52) structure is a dos.library structure used in pattern
matching.  Refer to the AmigaDOS Manual, 3rd Edition by Bantam Books for
more information.

If MyHookFunc() is called from a font requester doing [_DOWILDFUNC](../Libraries_Manual_guide/node0283.html#line8), the
three parameters are:




```c
    type = [FONF_DOWILDFUNC](../Libraries_Manual_guide/node0283.html#line8)

    object = pointer to a [TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure (from <graphics/[text.h](../Includes_and_Autodocs_2._guide/node00A8.html#line65)>)

    AslRequester = pointer to the [FontRequester](../Libraries_Manual_guide/node0281.html) that called the hook
                   function (Return non-zero to display this particular
                   font size)
```
If MyHookFunc() is called from a file or font requester doing [_DOMSGFUNC](../Libraries_Manual_guide/node0283.html#line8),
the three parameters are:




```c
    type = [FILF_DOMSGFUNC](../Libraries_Manual_guide/node0283.html#line8) (file requester) or [FONF_DOMSGFUNC](../Libraries_Manual_guide/node0283.html#line8) (font
           requester)

    object = pointer to the [IntuiMessage](../Libraries_Manual_guide/node01D9.html) for the function to process

    AslRequester = pointer to the [FileRequester](../Libraries_Manual_guide/node027B.html#line15) or [FontRequester](../Libraries_Manual_guide/node0281.html) that
                   called the hook function (Return a pointer to the
                   [IntuiMessage](../Libraries_Manual_guide/node01D9.html))
```
Notice that it is possible for a requester to use both [_DOWILDFUNC](../Libraries_Manual_guide/node0283.html#line8) and
[_DOMSGFUNC](../Libraries_Manual_guide/node0283.html#line8) at the same time.  Your hook function has to differentiate
between the two cases by testing the type passed to it.  It is not
possible for a font and file requester to share a hook function for a
_DOWILDFUNC, because FILF_DOWILDFUNC is defined to be the same value as
FONF_DOWILDFUNC, so the hook function cannot tell if the object (from the
prototype above) is a pointer to an [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line52) structure or a pointer to a
[TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure.  It is possible for font and file requesters to share
one hook function for _DOMSGFUNC (even though FILF_DOMSGFUNC and
FONF_DOMSGFUNC are equal) because, in this case, font and file requesters
both call your hook function in the same manner.


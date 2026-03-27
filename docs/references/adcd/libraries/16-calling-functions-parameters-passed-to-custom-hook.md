---
title: 16 / Calling Functions / Parameters Passed to Custom Hook Functions
manual: libraries
chapter: libraries
section: 16-calling-functions-parameters-passed-to-custom-hook
functions: []
libraries: []
---

# 16 / Calling Functions / Parameters Passed to Custom Hook Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A requester always passes three parameters to your custom hook function:


```c
    ULONG MyHookFunc(ULONG type, CPTR object, CPTR AslRequester)
```
If MyHookFunc() is called from a file requester doing [_DOWILDFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md), the
three parameters are:




```c
    type = [FILF_DOWILDFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md)

    object = pointer to an AnchorPath structure (from <dos/[dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md)>)

    AslRequester = pointer to the [FileRequester](libraries/16-asl-library-creating-a-file-requester.md) that called the hook
                   function (Return a zero to display this file)
```
The [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) structure is a dos.library structure used in pattern
matching.  Refer to the AmigaDOS Manual, 3rd Edition by Bantam Books for
more information.

If MyHookFunc() is called from a font requester doing [_DOWILDFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md), the
three parameters are:




```c
    type = [FONF_DOWILDFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md)

    object = pointer to a [TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure (from <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>)

    AslRequester = pointer to the [FontRequester](libraries/16-asl-library-creating-a-font-requester.md) that called the hook
                   function (Return non-zero to display this particular
                   font size)
```
If MyHookFunc() is called from a file or font requester doing [_DOMSGFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md),
the three parameters are:




```c
    type = [FILF_DOMSGFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md) (file requester) or [FONF_DOMSGFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md) (font
           requester)

    object = pointer to the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) for the function to process

    AslRequester = pointer to the [FileRequester](libraries/16-asl-library-creating-a-file-requester.md) or [FontRequester](libraries/16-asl-library-creating-a-font-requester.md) that
                   called the hook function (Return a pointer to the
                   [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md))
```
Notice that it is possible for a requester to use both [_DOWILDFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md) and
[_DOMSGFUNC](libraries/16-asl-library-calling-custom-functions-from-a-requester.md) at the same time.  Your hook function has to differentiate
between the two cases by testing the type passed to it.  It is not
possible for a font and file requester to share a hook function for a
_DOWILDFUNC, because FILF_DOWILDFUNC is defined to be the same value as
FONF_DOWILDFUNC, so the hook function cannot tell if the object (from the
prototype above) is a pointer to an [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) structure or a pointer to a
[TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure.  It is possible for font and file requesters to share
one hook function for _DOMSGFUNC (even though FILF_DOMSGFUNC and
FONF_DOMSGFUNC are equal) because, in this case, font and file requesters
both call your hook function in the same manner.


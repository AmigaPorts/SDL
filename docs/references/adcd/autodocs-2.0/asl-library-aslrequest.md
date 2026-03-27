---
title: asl.library/AslRequest
manual: autodocs-2.0
chapter: autodocs-2.0
section: asl-library-aslrequest
functions: [AllocAslRequest, FreeAslRequest]
libraries: [asl.library]
---

# asl.library/AslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AslRequest -- get input from user for an ASL requester (V36)
```
SYNOPSIS

```c
    BOOL result = AslRequest( request, ptags );
    D0                        A0       A1

    BOOL    result;
    APTR    request;
    struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md)       *ptags;
```
FUNCTION

    Prompts the user for input, based on the specific type of
    requester and modifying tagitems.  The actions and results
    are specific to the type but in general the action is to open
    a requesting window prompting the user for a specific input.
    If the user cancels or the system aborts the request, NULL
    is returned, otherwise the request data structure readable
    data reflects the user input.
    Note that tag values stay in effect for each use of the
    requester until they are cleared or modified by passing the
    same tag with a new value.
INPUTS

```c
    request = requester structure allocated with [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md).
    ptags = pointer to an array of TagItems which may be used to
        modify the requester.

    AslRequestTags( type, tags... ) which accepts your tags
    on the stack, is available in amiga.lib.

    Example Usage: AslRequestTags( ASL_FileRequest,
                                   ASL_Hail, "My Title Bar",
                                   TAG_DONE );
```
TAGS


```c
    ( REMEMBER - ALL DATA STRUCTURES ARE READ-ONLY EXCEPT BY USING
      TAGITEMS !!! )

    ASL_Hail (STRPTR) - Hailing text to prompt user, typically
        displayed in window title bar.
    ASL_Window (struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *) - Parent window for the request
        function, which is used to select the screen on which the
        requesting window will be displayed and also is used for
        a shared IDCMP port.

    ASL_LeftEdge (WORD) - Preferred display position for left edge where
        request window should open.
    ASL_TopEdge (WORD) - Preferred top edge of request window.
    ASL_Width (WORD)   - Preferred width of request window.
    ASL_Height (WORD)  - Preferred height of request window.

    ASL_HookFunc (APTR) - Pointer to callback function, specific to
        each AslRequest type.

    ASL_File (STRPTR) - [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) initial filename string.
    ASL_Dir (STRPTR) - [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) initial directory path string.

    ASL_FontName (STRPTR) - [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) initial fontname string.
    ASL_FontHeight (UWORD) - [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) initial height (ta_YSize).
    ASL_FontStyles (UBYTE) - [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) initial styles (ta_Style).
    ASL_FontFlags (UBYTE) - [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) initial flags (ta_Flags).
    ASL_FrontPen (BYTE) - [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) front pen color (fo_FrontPen).
    ASL_BackPen (BYTE) - [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) back pen color (fo_BackPen).
    ASL_MinHeight (UWORD) - Minimum height for [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) display
        of font sizes.  (Application must check return value).
    ASL_MaxHeight (UWORD) - Maximum height for [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) display
        of font sizes. (Application must check ta_YSize returned).

    ASL_OKText (STRPTR) - Replacement for default "OK" gadget text.
        ( Limited to approx. six characters ).
    ASL_CancelText (STRPTR) - Replacement for default "CANCEL"
        gadget text. ( Limited to approx. six characters ).

    ASL_FuncFlags (ULONG) - Function flags, depends on requester
        type.  Example: FILF_SAVE for [FileRequester](autodocs-2.0/includes-libraries-asl-h.md).
    ASL_ExtFlags1 (ULONG) - Extended flags (to pass FILF1_ bitdefs)
               Example: FIL1F_NOFILES for file requester
```
RESULT

    If NULL, typically the user cancelled the requester or a system
    failure prevented the requester from being opened.  If non-zero,
    values will be set depending on the particular type of request,
    in the requesting data structure.  See "libraries/asl.h" for
    information on the READ-ONLY fields in each specific type of
    requester.
NOTES


```c
    Asl provides a way for applications to interact with requester
    operation via a callback (hook) function.  For the ASL file and
    font requesters, there are two ASL_FuncFlags to specify that you
    want a callback:

         for FileRequester: FILF_DOWILDFUNC and FILF_DOMSGFUNC
         for FontRequester: FONF_DOWILDFUNC and FONF_DOMSGFUNC

    The DOWILDFUNC allows you to perform the pattern matching.
    The DOMSGFUNC allows you to handle IDCMP messages received
    for windows that are sharing a UserPort with the requester.

    If you set one or both of these flags via the ASL_FuncFlags
    tagitem, you must provide a pointer to your hook function
    using the ASL_HookFunc tagitem.  Your function will be called
    as follows:

     ULONG rf_Function(ULONG Mask, CPTR Object, CPTR AslRequester)

    The Mask value is a copy of the specific ASL_FuncFlag value
    the callback is for.  Object is a pointer to a data object
    specific to the reason for the callback (defined by Mask).
    AslRequester is a pointer to the requester structure.

    Note that you can only define one HookFunc per requester.
    Your hook function must examine the Mask passed to it to
    determine what the callback is for and what the Object is.

    The following table will explain what is passed to, and
    expected to be returned by a hook functions for various masks:

    [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) DOWILDFUNC
    Purpose: to accept or reject individual files for display list
    Inputs: Mask            = FILF_DOWILDFUNC
            Object          = struct [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) *
            AslRequester    = struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) *
    Result: You return zero to accept file for display in list


    [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) DOWILDFUNC
    Purpose: to accept or reject individual fonts for display list
    Inputs: Mask            = FONF_DOWILDFUNC
            Object          = struct [TextAttr](autodocs-2.0/includes-graphics-text-h.md) *
            AslRequester    = struct [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) *
    Result: You return non-zero to accept font for display in list


    [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) (or FontRequester) DOMSGFUNC
    Purpose: to handle IDCMP msgs for other windows sharing port
    Inputs: Mask            = FILF_DOMSGFUNC (FONF_DOMSGFUNC)
            Object          = struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *
            AslRequester    = struct [FileRequester](autodocs-2.0/includes-libraries-asl-h.md) (FontRequester) *
    Result: You must return the Object pointer (asl will Reply the Object)
```
SEE ALSO

```c
    [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md), [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md)
```

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)

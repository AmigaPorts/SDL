/* Source: ADCD 2.1
 * Section: asl-library-aslrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/asl-library-aslrequest.md
 */

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

    [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) DOWILDFUNC
    Purpose: to accept or reject individual files for display list
    Inputs: Mask            = FILF_DOWILDFUNC
            Object          = struct [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) *
            AslRequester    = struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) *
    Result: You return zero to accept file for display in list


    [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) DOWILDFUNC
    Purpose: to accept or reject individual fonts for display list
    Inputs: Mask            = FONF_DOWILDFUNC
            Object          = struct [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) *
            AslRequester    = struct [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) *
    Result: You return non-zero to accept font for display in list


    [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) (or FontRequester) DOMSGFUNC
    Purpose: to handle IDCMP msgs for other windows sharing port
    Inputs: Mask            = FILF_DOMSGFUNC (FONF_DOMSGFUNC)
            Object          = struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *
            AslRequester    = struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) (FontRequester) *
    Result: You must return the Object pointer (asl will Reply the Object)

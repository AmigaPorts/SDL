/* Source: ADCD 2.1
 * Section: utility-library-callhookpkt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-callhookpkt.md
 */

    Performs the callback standard defined by a [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) structure.
    This function is really very simple; it effectively performs
    a JMP to Hook->h_Entry.

    It is probably just as well to do this operation in an
    assembly language function linked in to your program, possibly
    from a compiler supplied library or a builtin function.

    It is anticipated that C programs will often call a 'varargs'
    variant of this function which will be named [CallHook](../Includes_and_Autodocs_2._guide/node0142.html).  This
    function must be provided in a compiler specific library, but
    an example of use would be:

    returnval = CallHook( hook, dataobject, COMMAND_ID, param1, param2 );

    This function [CallHook](../Includes_and_Autodocs_2._guide/node0142.html) can be implemented in many C compilers
    like this:
    CallHook( hook, object, command, ... )
    struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23)    *hook;
    VOID            *object;
    ULONG           command;
    {
            return ( CallHookPkt( hook, object, (VOID *) &command ) );
    }

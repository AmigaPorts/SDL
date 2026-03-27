/* Source: ADCD 2.1
 * Section: cia-resource-addicrvector
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/cia-resource-addicrvector.md
 */

    A processor interrupt may be generated immediatly if this call
    is successful.

    In general, it is probably best to only call this function
    while DISABLED so that the resource to which the interrupt
    handler is being attached may be set to a known state before
    the handler is called. You MUST NOT change the state of the
    resource before attaching your handler to it.

    The [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources require an extra parameter
    to specify which [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    interrupt = AddICRVector( Resource, iCRBit, interrupt )
    D0                        A6        D0      A1

    struct [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) *AddICRVector( struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *, WORD,
            struct [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) *);

    ***WARNING***

    Never assume that any of the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) hardware is free for use.
    Always use the AddICRVector() function to obtain ownership
    of the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) hardware registers your code will use.

    Note that there are two (2) interval timers per [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30).  If
    your application needs one of the interval timers, you
    can try to obtain any one of the four (4) until AddICRVector()
    succeeds.  If all four interval timers are in-use, your
    application should exit cleanly.

    If you just want ownership of a [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) hardware timer, or register,
    but do not want interrupts generated, use the AddICRVector()
    function to obtain ownership, and use the [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html) function
    to turn off (or on) interrupts as needed.

    Note that CIA-B generates level 6 interrupts (which can degrade
    system performance by blocking lower priority interrupts).  As
    usual, interrupt handling code should be optimized for speed.

    Always call [RemICRVector()](../Includes_and_Autodocs_2._guide/node0538.html) when your code exits to release
    ownership of any [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) hardware obtained with AddICRVector().

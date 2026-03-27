/* Source: ADCD 2.1
 * Section: cia-resource-seticr
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/cia-resource-seticr.md
 */

    The [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources require an extra parameter
    to specify which [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    oldMask = SetICR( Resource, mask )
    D0                A6        D0

    WORD SetICR( struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *, WORD );

    ***WARNING***

    Never read the contents of the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) interrupt control registers
    directly.  Reading the contents of one of the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) interrupt
    control registers clears the register.  This can result in
    interrupts being missed by critical operating system code, and
    other applications.

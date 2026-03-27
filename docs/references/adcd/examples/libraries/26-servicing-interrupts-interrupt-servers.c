/* Source: ADCD 2.1
 * Section: 26-servicing-interrupts-interrupt-servers
 * Library: libraries
 * ADCD reference: libraries/26-servicing-interrupts-interrupt-servers.md
 */

    Use The Z Flag.
    ---------------
    [VERTB](../Libraries_Manual_guide/node0303.html#line81) (vertical blank) servers should always return with the Z (zero)
    flag set.  The processor Z flag is used rather than the normal
    function convention of returning a result in D0 because it may be
    tested more quickly by Exec upon the server's return.

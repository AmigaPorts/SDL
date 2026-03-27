/* Source: ADCD 2.1
 * Section: exec-library-addintserver
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-addintserver.md
 */

    This function adds a new interrupt server to a given server chain.
    The node is located on the chain in a priority dependent position.
    If this is the first server on a particular chain, interrupts will
    be enabled for that chain.

    Each link in the chain will be called in priority order until the
    chain ends or one of the servers returns with the 68000's Z condition
    code clear (indicating non-zero).  Servers on the chain should return
    with the Z flag clear if the interrupt was specifically for that
    server, and no one else.  VERTB servers should always return Z set.
    (Take care with High Level Language servers, the language may not
    have a mechanism for reliably setting the Z flag on exit).

    Servers are called with the following register conventions:

        D0 - scratch
        D1 - scratch

        A0 - scratch
        A1 - server is_Data pointer (scratch)

        A5 - jump vector register (scratch)
        A6 - scratch

        all other registers must be preserved

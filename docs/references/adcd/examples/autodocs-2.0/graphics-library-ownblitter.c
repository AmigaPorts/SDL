/* Source: ADCD 2.1
 * Section: graphics-library-ownblitter
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-ownblitter.md
 */

    If blitter is available return immediately with the blitter
    locked for your exclusive use. If the blitter is not available
    put task to sleep. It will be awakened as soon as the blitter
    is available. When the task first owns the blitter the blitter
    may still be finishing up a blit for the previous owner. You
    must do a [WaitBlit](../Includes_and_Autodocs_2._guide/node0489.html) before actually using the blitter registers.

    Calls to OwnBlitter() do not nest. If a task that owns the
    blitter calls OwnBlitter() again, a lockup will result.
    (Same situation if the task calls a system function
    that tries to own the blitter).

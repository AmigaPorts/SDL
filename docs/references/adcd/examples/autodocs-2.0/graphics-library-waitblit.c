/* Source: ADCD 2.1
 * Section: graphics-library-waitblit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-waitblit.md
 */

    When examining bits with the CPU right after a blit, or when freeeing
    temorary memory used by the blitter, a WaitBlit() may be required.

    Note that many graphics calls fire up the blitter, and let it run.
    The CPU does not need to wait for the blitter to finish before
    returning.

    Because of a bug in agnus (prior to all revisions of fat agnus)
    this code may return too soon when the blitter has, in fact, not
    started the blit yet, even though BltSize has been written.

    This most often occurs in a heavily loaded systen with extended memory,
    HIRES, and 4 bitplanes.

    WaitBlit currently tries to avoid this agnus problem by testing
    the BUSY bit multiple times to make sure the blitter has started.
    If the blitter is BUSY at first check, this function busy waits.

    This initial hardware bug was fixed as of the first "Fat Agnus" chip,
    as used in all A500 and A2000 computers.

    Because of a different bug in agnus (currently all revisions thru ECS)
    this code may return too soon when the blitter has, in fact, not
    stopped the blit yet, even though blitter busy has been cleared.

    This most often occurs in a heavily loaded systen with extended memory,
    in PRODUCTIVITY mode, and 2 bitplanes.

    WaitBlit currently tries to avoid this agnus problem by testing
    the BUSY bit multiple times to make sure the blitter has really
    written its final word of desination data.

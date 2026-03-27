/* Source: ADCD 2.1
 * Section: 27-performing-data-move-operations-accessing-blitter
 * Library: libraries
 * ADCD reference: libraries/27-performing-data-move-operations-accessing-blitter.md
 */

    struct bltnode
    {
        struct  bltnode *n;
        int     (*function)();
        char    stat;
        short   blitsize;
        short   beamsync;
        int     (*cleanup)();
    };

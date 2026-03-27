/* Source: ADCD 2.1
 * Section: include-hardware-blit-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-hardware-blit-h.md
 */

    struct  bltnode *n;
    int     (*function)();
    char    stat;
    short   blitsize;
    short   beamsync;
    int     (*cleanup)();

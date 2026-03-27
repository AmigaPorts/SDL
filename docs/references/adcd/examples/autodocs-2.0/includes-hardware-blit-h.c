/* Source: ADCD 2.1
 * Section: includes-hardware-blit-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-hardware-blit-h.md
 */

    struct  bltnode *n;
    int     (*function)();
    char    stat;
    short   blitsize;
    short   beamsync;
    int     (*cleanup)();

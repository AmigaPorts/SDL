/* Source: ADCD 2.1
 * Section: ii-65-restoreshell-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-65-restoreshell-c.md
 */

    struct Segment
        *bootshell_seg,
        *shell_seg;

    Forbid();
    shell_seg = FindSegment("shell", NULL, CMD_SYSTEM);
    bootshell_seg = FindSegment("bootshell", NULL, CMD_SYSTEM);
    if (bootshell_seg)

/* Source: ADCD 2.1
 * Section: vii-17-ecs-display-modes-and-ilbm-camg
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-ecs-display-modes-and-ilbm-camg.md
 */

    *  fails to mask out SPRITES|VP_HIDE|GENLOCK_AUDIO|GENLOCK_VIDEO.

    *  saves a 2.0 extended view mode as 16 bits rather than saving the
       32-bit modeID returned by GetVPModeID().

    *  saves garbage in the upper word of the
       CAMG value.

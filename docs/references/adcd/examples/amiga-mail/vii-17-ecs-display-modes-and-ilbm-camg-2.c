/* Source: ADCD 2.1
 * Section: vii-17-ecs-display-modes-and-ilbm-camg
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-ecs-display-modes-and-ilbm-camg.md
 */

    {
    /* Bad CAMG, so ignore CAMG and determine a mode based on
     * based on pagesize or aspect
     */
     modeid = NULL;
     if(wide >= 640)    modeid |= HIRES;
     if(high >= 400)    modeid |= LACE;
     }

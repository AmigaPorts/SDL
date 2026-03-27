/* Source: ADCD 2.1
 * Section: standard-properties-camg
 * Library: devices
 * ADCD reference: devices/standard-properties-camg.md
 */

    {
    /* Bad CAMG, so ignore CAMG and determine a mode based on
     * based on pagesize or aspect
     */
     modeid = NULL;
     if(wide >= 640) modeid |= HIRES;
     if(high >= 400) modeid |= LACE;
     }

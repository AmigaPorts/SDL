/* Source: ADCD 2.1
 * Section: devices-modules-ilbmr-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmr-c.md
 */

        /*
         * Grab CAMG's idea of the viewmodes.
         */
        if (sp = FindProp (iff, ID_ILBM, ID_CAMG))
                {
                modeid = (* (ULONG *) sp->sp_Data);

                /* knock bad bits out of old-style 16-bit viewmode CAMGs
                 */
                if((!(modeid & MONITOR_ID_MASK))||

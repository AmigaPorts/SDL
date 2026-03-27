/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-dospecial-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-dospecial-c.md
 */

        if (PED->ped_PrintMode) { /* if data has been printed */
                (*(PD->pd_PWrite))("\014",1); /* eject page */
                (*(PD->pd_PBothReady))(); /* wait for it to finish */
                PED->ped_PrintMode = 0; /* no data to print */
        }
        return(0);

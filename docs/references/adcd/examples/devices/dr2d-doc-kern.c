/* Source: ADCD 2.1
 * Section: dr2d-doc-kern
 * Library: devices
 * ADCD reference: devices/dr2d-doc-kern.md
 */

    struct KERNstruct {
        short   Ch1, Ch2;   /* The pair to kern (allows for 16 bits...) */
        IEEE    XDisplace,  /* Amount to displace -left +right */
                YDisplace;  /* Amount to displace -down +up */
    };

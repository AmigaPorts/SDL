/* Source: ADCD 2.1
 * Section: kern-0x4b45524c-kerning-pair
 * Library: amiga-mail
 * ADCD reference: amiga-mail/kern-0x4b45524c-kerning-pair.md
 */

    struct KERNstruct {
        short   Ch1, Ch2;  /* The pair to kern (allows for 16 bits...) */
        IEEE    XDisplace, /* Amount to displace -left +right */
                YDisplace; /* Amount to displace -down +up */
    };

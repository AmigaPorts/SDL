/* Source: ADCD 2.1
 * Section: devices-iffp-smus-h
 * Library: devices
 * ADCD reference: devices/devices-iffp-smus-h.md
 */

    UBYTE iRegister;	/* set this instrument register number */
    UBYTE type;		/* instrument reference type (see above) */
    UBYTE data1, data2;	/* depends on the "type" field */
    char name[60];	/* instrument name */
    } RefInstrument;

/* Source: ADCD 2.1
 * Section: 32-expansion-board-drivers-disk-based-drivers
 * Library: libraries
 * ADCD reference: libraries/32-expansion-board-drivers-disk-based-drivers.md
 */

    /* this structure is used by GetCurrentBinding() */
    /* and SetCurrentBinding()                       */
    struct CurrentBinding {
        struct ConfigDev *cb_ConfigDev;    /* first configdev in chain */
        UBYTE *          cb_FileName;      /* file name of driver */
        UBYTE *          cb_ProductString; /* product # string */
        UBYTE **         cb_ToolTypes;     /* tooltypes from disk object */
    };

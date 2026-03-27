/* Source: ADCD 2.1
 * Section: includes-exec-io-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-exec-io-h.md
 */

    struct  Message io_Message;
    struct  Device  *io_Device;     /* device node pointer  */
    struct  Unit    *io_Unit;	    /* unit (driver private)*/
    UWORD   io_Command;	    /* device command */
    UBYTE   io_Flags;
    BYTE    io_Error;		    /* error or warning num */

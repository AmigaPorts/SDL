/* Source: ADCD 2.1
 * Section: includes-devices-printer-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-printer-h.md
 */

    struct  Message io_Message;
    struct  Device  *io_Device;     /* device node pointer  */
    struct  Unit    *io_Unit;	    /* unit (driver private)*/
    UWORD   io_Command;	    /* device command */
    UBYTE   io_Flags;
    BYTE    io_Error;		    /* error or warning num */
    UWORD   io_PrtCommand;	    /* printer command */
    UBYTE   io_Parm0;		    /* first command parameter */
    UBYTE   io_Parm1;		    /* second command parameter */
    UBYTE   io_Parm2;		    /* third command parameter */
    UBYTE   io_Parm3;		    /* fourth command parameter */

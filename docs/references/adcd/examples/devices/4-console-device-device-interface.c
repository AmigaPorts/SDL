/* Source: ADCD 2.1
 * Section: 4-console-device-device-interface
 * Library: devices
 * ADCD reference: devices/4-console-device-device-interface.md
 */

       struct  Message io_Message;
       struct  Device  *io_Device;/* device node pointer  */
       struct  Unit    *io_Unit;  /* unit (driver private)*/
       UWORD   io_Command;        /* device command */
       UBYTE   io_Flags;
       BYTE    io_Error;          /* error or warning num */
       ULONG   io_Actual;         /* actual number of bytes transferred */
       ULONG   io_Length;         /* requested number bytes transferred*/
       APTR    io_Data;           /* points to data area */
       ULONG   io_Offset;         /* offset for block structured devices */

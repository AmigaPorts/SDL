/* Source: ADCD 2.1
 * Section: 3-clipboard-device-device-interface
 * Library: devices
 * ADCD reference: devices/3-clipboard-device-device-interface.md
 */

      struct  Message io_Message;
      struct  Device  *io_Device;     /* device node pointer  */
      struct  Unit    *io_Unit;       /* unit (driver private)*/
      UWORD   io_Command;             /* device command */
      UBYTE   io_Flags;               /* including QUICK and SATISFY */
      BYTE    io_Error;               /* error or warning num */
      ULONG   io_Actual;              /* number of bytes transferred */
      ULONG   io_Length;              /* number of bytes requested */
      STRPTR  io_Data;                /* either clip stream or post port */
      ULONG   io_Offset;              /* offset in clip stream */
      LONG    io_ClipID;              /* ordinal clip identifier */

/* Source: ADCD 2.1
 * Section: 10-device-interface-opening-the-printer-device
 * Library: devices
 * ADCD reference: devices/10-device-interface-opening-the-printer-device.md
 */

    union printerIO
    {
        struct IOStdReq    ios;
        struct IODRPReq    iodrp;
        struct IOPrtCmdReq iopc;
    };

    struct MsgPort  *PrintMP;         /* Message port pointer */
    union printerIO *PrintIO;         /* I/O request pointer */

    if (PrintMP=CreateMsgPort() )
      if (PrintIO=(union printerIO *)
                   CreateExtIO(PrintMP,sizeof(union printerIO)) )
         if (OpenDevice("printer.device",0L,(struct IORequest *)PrintIO,0))
              printf("printer.device did not open\n");

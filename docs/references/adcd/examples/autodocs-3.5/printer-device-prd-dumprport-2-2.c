/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/printer-device-prd-dumprport-2.md
 */

     struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *ioreq;
     struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *port;
     [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) signal;

     port = ioreq->io_Message.mn_ReplyPort;
     signal = port->mp_SigBit;

     SendIO(ioreq);  send request
     Wait(signal);  wait for completion (go to sleep)
     while ((Msg = GetMsg(port)) != NULL) {  get ALL messages
     }

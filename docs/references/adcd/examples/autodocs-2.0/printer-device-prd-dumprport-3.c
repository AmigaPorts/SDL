/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/printer-device-prd-dumprport.md
 */

     struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *ioreq;
     struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *port;
     UBYTE signal;

     port = ioreq->io_Message.mn_ReplyPort;
     signal = port->mp_SigBit;

     SendIO(ioreq);  send request
     Wait(signal);  wait for completion (go to sleep)
     while ((Msg = GetMsg(port)) != NULL) {  get ALL messages
     }

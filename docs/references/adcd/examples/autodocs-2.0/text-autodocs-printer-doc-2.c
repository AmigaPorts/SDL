/* Source: ADCD 2.1
 * Section: text-autodocs-printer-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-printer-doc.md
 */

     struct IORequest *ioreq;
     struct MsgPort *port;
     UBYTE signal;

     port = ioreq->io_Message.mn_ReplyPort;
     signal = port->mp_SigBit;

     SendIO(ioreq);  send request
     Wait(signal);  wait for completion (go to sleep)
     while ((Msg = GetMsg(port)) != NULL) {  get ALL messages
     }

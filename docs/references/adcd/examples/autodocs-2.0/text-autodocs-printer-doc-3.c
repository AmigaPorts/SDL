/* Source: ADCD 2.1
 * Section: text-autodocs-printer-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-printer-doc.md
 */

     struct IORequest *ioreq;

     AbortIO(ioreq);  abort request
     WaitIO(ioreq);  wait for reply

     at this point you can re-use 'ioreq'.

     Note that in the above examples 'ioreq' could be any one of...
     a) struct IOStdReq    a standard i/o request
     b) struct IODRPReq    a dumprport i/o request
     c) struct IOPrtCmdReq a printer command i/o request

     It is recommend that you do asynchronous i/o in your programs
     and give the user a way of aborting all requests.

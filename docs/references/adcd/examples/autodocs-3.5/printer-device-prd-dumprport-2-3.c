/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/printer-device-prd-dumprport-2.md
 */

     struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *ioreq;

     AbortIO(ioreq);  abort request
     WaitIO(ioreq);  wait for reply

     at this point you can re-use 'ioreq'.

     Note that in the above examples 'ioreq' could be any one of...
     a) struct [IOStdReq](../Includes_and_Autodocs_3._guide/node0621.html#line26)    a standard i/o request
     b) struct [IODRPReq](../Includes_and_Autodocs_3._guide/node0605.html#line173)    a dumprport i/o request
     c) struct [IOPrtCmdReq](../Includes_and_Autodocs_3._guide/node0605.html#line155) a printer command i/o request

     It is recommend that you do asynchronous i/o in your programs
     and give the user a way of aborting all requests.

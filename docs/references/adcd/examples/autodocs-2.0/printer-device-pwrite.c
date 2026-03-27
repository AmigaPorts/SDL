/* Source: ADCD 2.1
 * Section: printer-device-pwrite
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/printer-device-pwrite.md
 */

    PWrite writes 'length' bytes directly to the printer.  This
    function is generally called by printer drivers to send
    their buffer(s) to the printer.

    This function is accessed by referencing off the [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line64) (PD)
    structure.  Below is a code fragment to show how to do get access
    to a pointer to the [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line64) (PD) structure.

    #include [<exec/types.h>](../Includes_and_Autodocs_2._guide/node0096.html)
    #include [<devices/printer.h>](../Includes_and_Autodocs_2._guide/node0052.html)
    #include [<devices/prtbase.h>](../Includes_and_Autodocs_2._guide/node005A.html)

    struct [IODRPReq](../Includes_and_Autodocs_2._guide/node0052.html#line155) PReq;
    struct [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line64) *PD;
    struct [PrinterExtendedData](../Includes_and_Autodocs_2._guide/node005A.html#line134) *PED;

    /* open the printer device (any version); if it opened... */
    if (OpenDevice("printer.device", 0, &PReq, 0) == NULL) {

        /* get pointer to printer data structure */
        PD = (struct [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line64) *)PReq.io_Device;

        /* write something directly to the printer */
        (*PD->pd_PWrite)("Hello worldn", 12);

        CloseDevice(&PReq); /* close the printer device */
    }

/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/printer-device-prd-dumprport.md
 */

    #include [<exec/types.h>](../Includes_and_Autodocs_2._guide/node0096.html)
    #include [<devices/printer.h>](../Includes_and_Autodocs_2._guide/node0052.html)
    #include [<devices/prtbase.h>](../Includes_and_Autodocs_2._guide/node005A.html)
    #include [<devices/prtgfx.h>](../Includes_and_Autodocs_2._guide/node003B.html)

    struct [IODRPReq](../Includes_and_Autodocs_2._guide/node0052.html#line155) PReq;
    struct [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line64) *PD;
    struct [PrinterExtendedData](../Includes_and_Autodocs_2._guide/node005A.html#line134) *PED;

    open the printer device / if it opened...
    if (OpenDevice("printer.device", 0, &PReq, 0) == NULL) {
       get pointer to printer data
       PD = (struct [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line64) *)PReq.io_Device;
       get pointer to printer extended data
       PED = &PD->pd_SegmentData->ps_PED;
       let's see what's there
       printf("PrinterName = '%s', Version=%u, Revision=%un",
           PED->ped_PrinterName, PD->pd_SegmentData->ps_Version,
           PD->pd_SegmentData->ps_Revision,);
       printf("PrinterClass=%u, ColorClass=%un",
           PED->ped_PrinterClass, PED->ped_ColorClass);
       printf("MaxColumns=%u, NumCharSets=%u, NumRows=%un",
           PED->ped_MaxColumns, PED->ped_NumCharSets, PED->ped_NumRows);
       printf("MaxXDots=%lu, MaxYDots=%lu, XDotsInch=%u, YDotsInch=%un",
           PED->ped_MaxXDots, PED->ped_MaxYDots,
           PED->ped_XDotsInch, PED->ped_YDotsInch);
       CloseDevice(&PReq);
    }

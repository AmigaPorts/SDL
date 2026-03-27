/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/printer-device-prd-dumprport-2.md
 */

       get pointer to printer data
       PD = (struct [PrinterData](../Includes_and_Autodocs_3._guide/node05FC.html#line103) *)PReq.io_Device;
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

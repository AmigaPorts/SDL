/* Source: ADCD 2.1
 * Section: text-autodocs-printer-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-printer-doc.md
 */

       get pointer to printer data
       PD = (struct PrinterData *)PReq.io_Device;
       get pointer to printer extended data
       PED = &PD->pd_SegmentData->ps_PED;
       let's see what's there
       printf("PrinterName = '%s', Version=%u, Revision=%u\n",
           PED->ped_PrinterName, PD->pd_SegmentData->ps_Version,
           PD->pd_SegmentData->ps_Revision,);
       printf("PrinterClass=%u, ColorClass=%u\n",
           PED->ped_PrinterClass, PED->ped_ColorClass);
       printf("MaxColumns=%u, NumCharSets=%u, NumRows=%u\n",
           PED->ped_MaxColumns, PED->ped_NumCharSets, PED->ped_NumRows);
       printf("MaxXDots=%lu, MaxYDots=%lu, XDotsInch=%u, YDotsInch=%u\n",
           PED->ped_MaxXDots, PED->ped_MaxYDots,
           PED->ped_XDotsInch, PED->ped_YDotsInch);
       CloseDevice(&PReq);

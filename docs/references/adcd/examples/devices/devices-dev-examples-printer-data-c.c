/* Source: ADCD 2.1
 * Section: devices-dev-examples-printer-data-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-printer-data-c.md
 */

    {
    /* Allocate printerIO union */
    if (PIO = (union printerIO *)CreateExtIO(PrinterMP, sizeof(union printerIO)))
        {
        /* Open the printer.device */
        if (!(OpenDevice("printer.device",0,(struct IORequest *)PIO,0)))
            {

            /* Now that we've got the device opened, let's see what we've got.
             * First, get a pointer to the printer data.
             */
            PD = (struct PrinterData *)PIO->iodrp.io_Device;
            /* And a pointer to the extended data */
            PED = (struct PrinterExtendedData *)&PD->pd_SegmentData->ps_PED;

            /* See the <devices/prtbase.h> include file for more details on
             * the PrinterData and PrinterExtendedData structures.
             */
            printf("Printername: '%s', Version: %ld, Revision: %ld\n",
            PED->ped_PrinterName, PD->pd_SegmentData->ps_Version,
            PD->pd_SegmentData->ps_Revision);

            printf("PrinterClass: 0x%lx, ColorClass: 0x%lx\n",
            PED->ped_PrinterClass, PED->ped_ColorClass);

            printf("MaxColumns: %ld, NumCharSets: %ld, NumRows: %ld\n",
                PED->ped_MaxColumns, PED->ped_NumCharSets,PED->ped_NumRows);

            printf("MaxXDots: %ld, MaxYDots: %ld, XDotsInch: %ld, YDotsInch: %ld\n",
                PED->ped_MaxXDots, PED->ped_MaxYDots, PED->ped_XDotsInch, PED->ped_YDotsInch);

            CloseDevice((struct IORequest *)PIO);
            }
         else
             printf("Can't open printer.device\n");
        DeleteExtIO((struct IORequest *)PIO);
        }
    else
        printf("Can't CreateExtIO\n");
    DeletePort((struct MsgPort *)PrinterMP);
    }

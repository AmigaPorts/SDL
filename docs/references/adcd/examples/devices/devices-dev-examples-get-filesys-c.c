/* Source: ADCD 2.1
 * Section: devices-dev-examples-get-filesys-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-get-filesys-c.md
 */

       {
       for ( fse = (struct FileSysEntry *)FileSysResBase->fsr_FileSysEntries.lh_Head;
             fse->fse_Node.ln_Succ;
             fse = (struct FileSysEntry *)fse->fse_Node.ln_Succ)
            {
            printf("Found filesystem creator: %s\n",fse->fse_Node.ln_Name);

            printf("                 DosType: ");
            for (x=24; x>=8; x-=8)
                 putchar((fse->fse_DosType >> x) & 0xFF);

            putchar((fse->fse_DosType & 0xFF) + 0x30);

            printf("\n                 Version: %d",(fse->fse_Version >> 16));
            printf(".%ld\n\n",(fse->fse_Version & 0xFFFF));
            }
        }

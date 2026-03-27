/* Source: ADCD 2.1
 * Section: devices-dev-examples-scsi-direct-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-scsi-direct-c.md
 */

    {
    printf("\nBlock descriptor header\n");
    printf("=======================\n");
    printf("Mode Sense data length  = %d\n",(short)buffer[0]);
    printf("Block descriptor length = %d\n",(short)buffer[3]);
    tbuf = &buffer[4];
    printf("Density code            = %d\n",(short)tbuf[0]);
    tval = (tbuf[1]<<16) + (tbuf[2]<<8) + tbuf[3];
    printf("Number of blocks        = %ld\n",tval);
    tval = (tbuf[5]<<16) + (tbuf[6]<<8) + tbuf[7];
    printf("Block size              = %ld\n",tval);

    tbuf += buffer[3];          /* move to page descriptors */

    while ((tbuf - buffer) < buffer[0])
           {

           switch (tbuf[0] & 0x7f)
                   {
                   case 1:
                          printf("\nError Recovery Parameters\n");
                          printf("=========================\n");
                          printf("Page length             = %d\n",(short)tbuf[1]);
                          printf("DISABLE CORRECTION      = %d\n",(short)tbuf[2]&1);
                          printf("DISABLE XFER ON ERROR   = %d\n",(short)(tbuf[2]>>1)&1);
                          printf("POST ERROR              = %d\n",(short)(tbuf[2]>>2)&1);
                          printf("ENABLE EARLY CORRECTION = %d\n",(short)(tbuf[2]>>3)&1);
                          printf("READ CONTINUOUS         = %d\n",(short)(tbuf[2]>>4)&1);
                          printf("TRANSFER BLOCK          = %d\n",(short)(tbuf[2]>>5)&1);
                          printf("AUTO READ REALLOCATION  = %d\n",(short)(tbuf[2]>>6)&1);
                          printf("AUTO WRITE REALLOCATION = %d\n",(short)(tbuf[2]>>7)&1);
                          printf("Retry count             = %d\n",(short)tbuf[3]);
                          printf("Correction span         = %d\n",(short)tbuf[4]);
                          printf("Head offset count       = %d\n",(short)tbuf[5]);
                          printf("Data strobe offset count= %d\n",(short)tbuf[6]);
                          printf("Recovery time limit     = %d\n",(short)tbuf[7]);

                          tbuf += tbuf[1]+2;
                          break;

                   case 2:
                          printf("\nDisconnect/Reconnect Control\n");
                          printf("============================\n");
                          printf("Page length             = %d\n",(short)tbuf[1]);
                          printf("Buffer full ratio       = %d\n",(short)tbuf[2]);
                          printf("Buffer empty ratio      = %d\n",(short)tbuf[3]);
                          tval = (tbuf[4]<<8)+tbuf[5];
                          printf("Bus inactivity limit    = %d\n",tval);
                          tval = (tbuf[6]<<8)+tbuf[7];
                          printf("Disconnect time limit   = %d\n",tval);
                          tval = (tbuf[8]<<8)+tbuf[9];
                          printf("Connect time limit      = %d\n",tval);
                          tval = (tbuf[10]<<8)+tbuf[11];
                          printf("Maximum burst size      = %d\n",tval);
                          printf("Disable disconnection   = %d\n",(short)tbuf[12]&1);

                          tbuf += tbuf[1]+2;
                          break;

                   case 3:
                          printf("\nDevice Format Parameters\n");
                          printf("========================\n");
                          printf("Page length             = %d\n",(short)tbuf[1]);
                          tval = (tbuf[2]<<8)+tbuf[3];
                          printf("Tracks per zone         = %d\n",tval);
                          tval = (tbuf[4]<<8)+tbuf[5];
                          printf("Alternate sectors/zone  = %d\n",tval);
                          tval = (tbuf[6]<<8)+tbuf[7];
                          printf("Alternate tracks/zone   = %d\n",tval);
                          tval = (tbuf[8]<<8)+tbuf[9];
                          printf("Alternate tracks/volume = %d\n",tval);
                          tval = (tbuf[10]<<8)+tbuf[11];
                          printf("Sectors per track       = %d\n",tval);
                          tval = (tbuf[12]<<8)+tbuf[13];
                          printf("Bytes per sector        = %d\n",tval);
                          tval = (tbuf[14]<<8)+tbuf[15];
                          printf("Interleave              = %d\n",tval);
                          tval = (tbuf[16]<<8)+tbuf[17];
                          printf("Track skew factor       = %d\n",tval);
                          tval = (tbuf[18]<<8)+tbuf[19];
                          printf("Cylinder skew factor    = %d\n",tval);

                          tbuf += tbuf[1]+2;
                          break;

                   case 4:
                          printf("\nDrive Geometry Parameters\n");
                          printf("=========================\n");
                          printf("Page length             = %d\n",(short)tbuf[1]);
                          tval = (tbuf[2]<<16)+(tbuf[3]<<8)+tbuf[4];
                          printf("Number of cylinders     = %ld\n",tval);
                          printf("Number of heads         = %d\n",(short)tbuf[5]);
                          tval = (tbuf[6]<<16)+(tbuf[6]<<8)+tbuf[8];
                          printf("Start write precomp     = %ld\n",tval);
                          tval = (tbuf[9]<<16)+(tbuf[10]<<8)+tbuf[11];
                          printf("Start reduced write     = %ld\n",tval);
                          tval = (tbuf[12]<<8)+tbuf[13];
                          printf("Drive step rate         = %d\n",tval);
                          tval = (tbuf[14]<<16)+(tbuf[15]<<8)+tbuf[16];
                          printf("Landing zone cylinder   = %ld\n",tval);

                          tbuf += tbuf[1]+2;
                          break;

                   default:
                           printf("\nVendor Unique Page Code %2x\n",(short)tbuf[0]);
                           printf("==========================\n");
                           for (i=0; i<=tbuf[1]+1; i++ )
                                printf("%x ",(short)tbuf[i]);

                           printf("\n");
                           tbuf += tbuf[1]+2;
                   }
           }
    }

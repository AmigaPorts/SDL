/* Source: ADCD 2.1
 * Section: devices-modules-ilbmw-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmw-c.md
 */

      	    cmapReg.red    = ( *tabw >> 4 ) & 0xf0;
      	    cmapReg.red   |= (cmapReg.red >> 4);

      	    cmapReg.green  = ( *tabw      ) & 0xf0;
      	    cmapReg.green |= (cmapReg.green >> 4);

      	    cmapReg.blue   = ( *tabw << 4 ) & 0xf0;
      	    cmapReg.blue  |= (cmapReg.blue >> 4);

      	    if((WriteChunkBytes(iff, (BYTE *)&cmapReg, sizeofColorRegister))
                != sizeofColorRegister)
                        return(IFFERR_WRITE);
      	    ++tabw;
      	    }

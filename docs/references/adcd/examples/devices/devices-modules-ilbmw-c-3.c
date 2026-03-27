/* Source: ADCD 2.1
 * Section: devices-modules-ilbmw-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmw-c.md
 */

            planes[iPlane] += rowBytes;
            }

         /* Compress and write next row.*/
         else {
            buf = buffer;
            packedRowBytes = packrow(&planes[iPlane], &buf, rowBytes);

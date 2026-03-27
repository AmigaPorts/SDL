/* Source: ADCD 2.1
 * Section: devices-modules-parse-c
 * Library: devices
 * ADCD reference: devices/devices-modules-parse-c.md
 */

       if (cn = (CurrentChunk (iff)))
           {
           if (cn = (ParentChunk(cn)))
               {
               if((cn->cn_Type == type)&&(cn->cn_ID == id)) result = 1;
               }

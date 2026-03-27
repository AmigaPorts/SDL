/* Source: ADCD 2.1
 * Section: devices-dev-examples-full-narrator-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-full-narrator-c.md
 */

     {
     if (isspace((int)(c = *EngPtr++)))
         *(EngPtr-1) = ' ';
     if ((c == '.') || (c == '?'))
         {
         *EngPtr = '\0';
         EngStart[NumEngStarts++] = ++EngPtr;
         }
     }

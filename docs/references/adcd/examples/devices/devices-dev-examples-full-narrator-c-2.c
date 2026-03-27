/* Source: ADCD 2.1
 * Section: devices-dev-examples-full-narrator-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-full-narrator-c.md
 */

     {
     if (isspace((int)(c = *PhonPtr++)))
         *(PhonPtr-1) = ' ';
     if ((c == '.') || (c == '?'))
         {
         *PhonPtr = '\0';
         PhonStart[NumPhonStarts++] = ++PhonPtr;
         }
     }

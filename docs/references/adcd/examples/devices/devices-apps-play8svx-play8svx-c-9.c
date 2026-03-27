/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

      {
      /* Decode a data nibble, high nibble then low nibble */
      d = source[i >> 1];    /* get a pair of nibbles */
      if (i & 1)             /* select low or high nibble */
         d &= 0xf;           /* mask to get the low nibble */
      else
         d >>= 4;            /* shift to get the high nibble */
      x += codeToDelta[d];   /* add in the decoded delta */
      dest[i] = x;           /* store a 1 byte sample */
      }

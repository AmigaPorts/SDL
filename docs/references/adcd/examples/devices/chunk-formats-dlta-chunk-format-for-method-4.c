/* Source: ADCD 2.1
 * Section: chunk-formats-dlta-chunk-format-for-method-4
 * Library: devices
 * ADCD reference: devices/chunk-formats-dlta-chunk-format-for-method-4.md
 */

      int i;
      LONG *deltadata;
      WORD *ptr,*planeptr;
      register int s,size,nw;
      register WORD *data,*dest;

      deltadata = (LONG *)deltaword;
      nw = bm->BytesPerRow >>1;

      for (i=0;i<bm->Depth;i++) {
         planeptr = (WORD *)(bm->Planes[i]);
         data = deltaword + deltadata[i];
         ptr  = deltaword + deltadata[i+8];
         while (*ptr != 0xFFFF) {
            dest = planeptr + *ptr++;
            size = *ptr++;
            if (size < 0) {
               for (s=size;s<0;s++) {
                  *dest = *data;
                  dest += nw;
               }
               data++;
            }
            else {
               for (s=0;s<size;s++) {
                  *dest = *data++;
                  dest += nw;
               }
            }
         }
      }
      return(0);

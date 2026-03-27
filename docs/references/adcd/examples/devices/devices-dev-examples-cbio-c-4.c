/* Source: ADCD 2.1
 * Section: devices-dev-examples-cbio-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cbio-c.md
 */

      {
      looking = FALSE;

      if (ReadLong(ior,&chunk))
          {
          /* Is CHRS chunk ? */
          if (chunk == ID_CHRS)
              {
              /* Get size of chunk, and copy data */
              if (ReadLong(ior,&size))
                  {
                  if (size)
                      buf=FillCBData(ior,size);
                  }
              }

            /* If not, skip to next chunk */
          else
              {
              if (ReadLong(ior,&size))
                  {
                   looking = TRUE;
                   if (size & 1)
                       size++;    /* if odd size, add pad byte */

                    ior->io_Offset += size;
                  }
              }
          }
      }

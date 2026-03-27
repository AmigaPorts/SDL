/* Source: ADCD 2.1
 * Section: devices-other-cycvb-c
 * Library: devices
 * ADCD reference: devices/devices-other-cycvb-c.md
 */

      anyChange = NO;
      for (i=0; i<MAXNCYCS; i++)  {
         cyc = &cycles[i];
         if ( (cyc->low == cyc->high) ||
              ((cyc->flags&RNG_ACTIVE) == 0) ||
              (cyc->rate == RNG_NORATE) )
                 continue;

         cyc->count += cyc->rate;
         if (cyc->count >= OnePerTick)  {
            anyChange = YES;
            cyc->count -= OnePerTick;

            if (cyc->flags&RNG_REVERSE)  {
               temp = cycols[cyc->low];
               for (j=cyc->low; j < cyc->high; j++)
                  cycols[j] = cycols[j+1];
               cycols[cyc->low] = temp;
               }
            else  {
               temp = cycols[cyc->high];
               for (j=cyc->high; j > cyc->low; j--)
                  cycols[j] = cycols[j-1];
               cycols[cyc->low] = temp;
               }
            }
         }
      if (anyChange) LoadRGB4(vport,cycols,nColors);
      }

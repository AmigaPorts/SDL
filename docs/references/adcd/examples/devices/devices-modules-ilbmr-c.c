/* Source: ADCD 2.1
 * Section: devices-modules-ilbmr-c
 * Library: devices
 * ADCD reference: devices/devices-modules-ilbmr-c.md
 */

      	if (mask != NULL)
             planes[srcPlaneCnt] = mask;  /* If there are more srcPlanes than
               * dstPlanes, there will be NULL plane-pointers before this.*/
      	else
             planes[srcPlaneCnt] = NULL;  /* In case more dstPlanes than src.*/
      	srcPlaneCnt += 1;  /* Include mask plane in count.*/
      	}

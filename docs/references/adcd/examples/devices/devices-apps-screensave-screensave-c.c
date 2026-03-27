/* Source: ADCD 2.1
 * Section: devices-apps-screensave-screensave-c
 * Library: devices
 * ADCD reference: devices/devices-apps-screensave-screensave-c.md
 */

      {
      printf("%s\n%s\n",Copyright,usage);
      printf("Enter filename for save: ");
      l = mygets(&nbuf[0]);

      if(l==0)                /* No filename - Exit */
         {
         bye("\nScreen not saved, filename required\n",RETURN_FAIL);
         }
      else
         {
         filename = &nbuf[0];
         }
      }

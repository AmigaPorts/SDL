/* Source: ADCD 2.1
 * Section: devices-dev-examples-read-potinp-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-read-potinp-c.md
 */

      /* until CTRL-C is pressed */
      {
      /* Read word at $DFF016 */
        value = custom.potinp;

      /* Show what was read (restricted to our allocated bits) */
      printf("POTINP = $%lx\n",value & potbits);
      }

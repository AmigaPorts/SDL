/* Source: ADCD 2.1
 * Section: devices-dev-examples-read-potinp-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-read-potinp-c.md
 */

    {
    printf("Pot bits are already allocated! %lx\n",potbits);
    FreePotBits(potbits);
    return;
    }

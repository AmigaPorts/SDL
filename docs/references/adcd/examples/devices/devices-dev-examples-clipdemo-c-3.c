/* Source: ADCD 2.1
 * Section: devices-dev-examples-clipdemo-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-clipdemo-c.md
 */

    {
    if (!(CBWriteFTXT(ior,string)))
        {
        printf("Error writing to clipboard: io_Error = %ld\n",ior->io_Error);
        }
    CBClose(ior);
    }

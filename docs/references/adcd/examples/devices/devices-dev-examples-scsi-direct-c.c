/* Source: ADCD 2.1
 * Section: devices-dev-examples-scsi-direct-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-scsi-direct-c.md
 */

    {
    printf("Couldn't open unit %ld on %s\n",unit,dname);
    FreeMem( buffer,BUFSIZE );
    exit(100);
    }

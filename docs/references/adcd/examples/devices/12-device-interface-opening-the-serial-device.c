/* Source: ADCD 2.1
 * Section: 12-device-interface-opening-the-serial-device
 * Library: devices
 * ADCD reference: devices/12-device-interface-opening-the-serial-device.md
 */

       if (SerialIO=(struct IOExtSer *)
              CreateExtIO(SerialMP,sizeof(struct IOExtSer)) )
           SerialIO->io_SerFlags=SERF_SHARED;  /* Turn on SHARED mode */
           if (OpenDevice(SERIALNAME,0L,(struct IORequest *)SerialIO,0) )
               printf("%s did not open\n",SERIALNAME);

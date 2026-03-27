/* Source: ADCD 2.1
 * Section: 8-narrator-device-reading-from-the-narrator-device
 * Library: devices
 * ADCD reference: devices/8-narrator-device-reading-from-the-narrator-device.md
 */

    for (DoIO(MouthIO);MouthIO->voice.message.io_Error
                             != ND_NoWrite;DoIO(MouthIO))
          {
          if (MouthIO->sync & 0x01)  DoMouthShape();
          if (MouthIO->sync & 0x02)  DoWordSync();
          if (MouthIO->sync & 0x04)  DoSyllableSync();
          }

/* Source: ADCD 2.1
 * Section: 1-introduction-to-amiga-system-devices-devices-with
 * Library: devices
 * ADCD reference: devices/1-introduction-to-amiga-system-devices-devices-with.md
 */

      {
          /* Create the I/O request */
      if (TimerIO = (struct timerequest *)
          {           CreateExtIO(TimerMP,sizeof(struct timerequest)))
              /* Open the timer device */
          if (!(OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0)))
              {
              /* Set up pointer for timer functions */
              TimerBase = (struct Library *)TimerIO->tr_node.io_Device;

              ... use functions ...

              /* Close the timer device */
              CloseDevice(TimerIO);
              }

          /* Delete the I/O request */
          DeleteExtIO(TimerIO);
          }

      /* Delete the message port */
      DeletePort(TimerMP);
      }

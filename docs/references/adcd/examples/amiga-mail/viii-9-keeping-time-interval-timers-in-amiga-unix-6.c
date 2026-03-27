/* Source: ADCD 2.1
 * Section: viii-9-keeping-time-interval-timers-in-amiga-unix
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-9-keeping-time-interval-timers-in-amiga-unix.md
 */

          oldtime will hold the state of the timer; and newtime will be
          used to set the new timer parameters.

     11   Establish trap() as the current signal handler for the alarm
          signal.  The previous handler is saved in oldsig.

     12   Fetch the current settings of the timer.

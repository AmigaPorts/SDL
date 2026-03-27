/* Source: ADCD 2.1
 * Section: viii-9-keeping-time-interval-timers-in-amiga-unix
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-9-keeping-time-interval-timers-in-amiga-unix.md
 */

      1   The file signal.h defines the parameters for the signal(2)
          function.

    2-4   trap() is the simple signal handler that just sets a flag that
          another piece of code will examine.

      5   Define the sleep() function.

    6-8   oldsig is a variable that will be used to save the previous
          state of the signal handler; oldtime will be used to save the
          state of the alarm clock.

      9   Establish trap() as the current signal handler for the alarm
          signal.  The previous handler is saved in oldsig.

     10   Clear the alarm clock, saving the current state.

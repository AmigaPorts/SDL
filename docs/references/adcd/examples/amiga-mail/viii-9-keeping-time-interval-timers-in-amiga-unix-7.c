/* Source: ADCD 2.1
 * Section: viii-9-keeping-time-interval-timers-in-amiga-unix
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-9-keeping-time-interval-timers-in-amiga-unix.md
 */

     1  # include       <sys/time.h>
     2  ...
     3          {
     4                  struct itimerval        newtime;
     5                  newtime.it_value.tv_sec = 60;
     6                  newtime.it_value.tv_usec = 0;
     7                  newtime.it_interval.tv_sec = 5;
     8                  newtime.it_interval.tv_usec = 500000;
     9                  setitimer(ITIMER_REAL, &newtime, 0);
    10          }
    11  ...

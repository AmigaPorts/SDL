/* Source: ADCD 2.1
 * Section: viii-9-keeping-time-interval-timers-in-amiga-unix
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-9-keeping-time-interval-timers-in-amiga-unix.md
 */

     1  # include       <signal.h>
     2  # include       <sys/time.h>
     3  static void trap ()
     4  {
     5  }
     6  unsigned mysleep ( unsigned duration )
     7  {
     8         void                    (*oldsig)();
     9         struct itimerval        oldtime;
    10         struct itimerval        newtime;
    11         oldsig = signal(SIGALRM, trap);
    12         getitimer(ITIMER_REAL, &oldtime);
    13         if (oldtime.it_value.tv_sec == 0
                        && oldtime.it_value.tv_usec == 0
                        || oldtime.it_value.tv_sec >= duration)
    14         {
    15                 newtime.it_interval.tv_sec = 0;
    16                 newtime.it_interval.tv_usec = 0;
    17                 newtime.it_value.tv_sec = duration;
    18                 newtime.it_value.tv_usec = 0;
    19                 setitimer(ITIMER_REAL, &newtime, NULL);
    20         }
    21         pause();
    22         signal(SIGALRM, oldsig);
    23         if (oldtime.it_value.tv_sec > duration)
    24         {
    25                 oldtime.it_value.tv_sec -= duration;
    26                 setitimer(ITIMER_REAL, &newtime, NULL);
    27         }
    28         if (oldtime && oldtime < n)
    29                 return(n - oldtime);
    30         else
    31                 return 0;
    32  }

/* Source: ADCD 2.1
 * Section: viii-9-keeping-time-interval-timers-in-amiga-unix
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-9-keeping-time-interval-timers-in-amiga-unix.md
 */

     1  # include       <signal.h>
     2  static void trap ()
     3  {
     4  }
     5  unsigned sleep ( unsigned duration )
     6  {
     7          void            (*oldsig)();
     8          unsigned        oldtime;
     9          oldsig = signal(SIGALRM, trap);
    10          oldtime = alarm(0);
    11          if (oldtime && oldtime < duration)
    12                  alarm(oldtime);
    13          else
    14                  alarm(duration);
    15          pause();
    16          signal(SIGALRM, oldsig);
    17          if (oldtime > duration)
    18                  alarm(oldtime - duration);
    19          if (oldtime && oldtime < duration)
    20                  return(duration - oldtime);
    21          else
    22                  return 0;
    23  }

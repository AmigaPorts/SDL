---
title: Listening for Network and Amiga Events
manual: amiga-mail
chapter: amiga-mail
section: listening-for-network-and-amiga-events
functions: [Wait]
libraries: [exec.library]
---

# Listening for Network and Amiga Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once back in the main() routine, the application is almost ready to
start processing network events.  The only thing remaining is to decide
what kind of events the server needs to hear about.  Most applications
will need to be aware of both network and local Amiga events, which
means separate masks need to be set up for both types of events.  On
the network side, the mask needs to contain information on which
sockets need responses.


```c
    /* First, prepare the various masks for signal processing */
    fd_set sockmask;

    FD_ZERO( &sockmask );
    FD_SET( socket, &sockmask );
```
The sockmask variable will be used as a template to indicate what
network events the application notices.  Since sockmask came off the
stack and contains garbage, the FD_ZERO() call clears all its network
signal bits.  The FD_SET() call sets the mask to listen for events
relating to the socket that the server created earlier.  Everything is
prepared, so the next step is entering the event loop itself.




```c
    long umask;
    fd_set mask;

    while(1)
    {
        /*
        ** Reset the mask values for another pass
        */

        mask = sockmask;
        umask = SIGBREAKF_CTRL_C;

        /*
        ** selectwait is a combo network and Amiga Wait() rolled into
        ** a single call.  It allows the app to respond to both Amiga
        ** signals (CTRL-C in this case) and to network events.
        **
        ** Here, if the selectwait event is the SIGBREAK signal, we
        ** bail and AppPanic() but otherwise its a network event.
        */

        if (selectwait( 2, &mask, NULL, NULL, NULL, &umask ) == -1 )
        {
            AppPanic("CTRL-C:\nProgram terminating!",0);
        }
```
Before an event occurs, the mask variable tells selectwait() which
network events the server wants to receive.  After an event occurs, the
mask variable indicates which socket triggered the network event.  The
sockmask variable is used to reset mask back to its original mask value
at the top of each pass through the event loop.

In addition to waiting on network events, selectwait() also waits on
Exec signals for the current task.  For this example, the only Amiga
event the server cares about is a Ctrl-C break (SIGBREAKF_CTRL_C).  The
selectwait() function has a simple purpose, but due to the wide scope
of network events, the function has a myriad of parameters and
configurations. This example uses the bare minimum of what's possible
using selectwait(), and many network-friendly applications will be able
to get by using only a small subset of selectwait()'s potential.  In
this case, the network event set is passed in mask, and the Amiga event
mask is passed in umask.

If selectwait() returns with a value of -1, it means the Amiga event
mask was the trigger.  Otherwise, a network event caused the function
to return.  This example is simple enough that a Ctrl-C interrupt can
be handled rather easily.

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)

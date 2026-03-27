---
title: The ShowNote Server Application
manual: amiga-mail
chapter: amiga-mail
section: the-shownote-server-application
functions: []
libraries: []
---

# The ShowNote Server Application

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Although the Amiga's Shared Socket Library is meant to be compatible
with the Unix socket implementation, there are a couple of
Amiga-specific quirks that an Amiga networked application has to take
care of.  First, an Amiga application has to open the Shared Socket
Library (socket.library).  Before calling any other functions in
socket.library, the program has to call the socket.library function,
setup_sockets().  [ShowNote.c](amiga-mail/viii-31-shownote-c.md) code has almost all of the network
intialization material in the SS_Init() function.




```c
    /*
    ** Attempt to open socket library and initialize socket environment.
    ** If this fails, bail out to the non-returning AppPanic() routine.
    */

    if (SockBase = OpenLibrary("inet:libs/socket.library",0L))
    {
        setup_sockets( 3, &errno );
    }
    else
    {
        AppPanic("Can't open socket.library!",0);
    }
```
Unlike most libraries, socket.library does not go in LIBS:.  Instead,
it goes with the network-specific support files, in INET:, in a LIBS
directory.  This location needs to be hardcoded into the application.

Next, create a socket:




```c
    /*
    ** Open the initial socket on which incoming messages will queue for
    ** handling.  While the server is iterative, I do it this way so that
    ** SIGBREAKF_CTRL_C will continue to function.
    */

    int snum;

    if ((snum = socket( AF_INET, SOCK_STREAM, 0 )) == -1)
    {
        AppPanic("Socket Creation:",errno);
    }
```
and figure out what the well-known port number of the server is.  For
testing purposes, SendNote and ShowNote use a hard-coded port number
(8769).  If the application was installed on a network, each machine
that ran the server would need an entry for the "note" service in the
inet:db/services file.  In that case, both the server and the client
would have to use getservbyname() to find the port number of the
"note" service.

The server then needs to build a sockaddr_in structure describing
itself.  The sockaddr_in contains all the information needed to map an
initialized socket to a specific transport address on the Internet
(thus the _in suffix, other network protocols have different suffixes).
Before the socket can be assigned an Internet transport address, it
needs to be initialized:




```c
    struct sockaddr_in sockaddr;

    memset( &sockaddr, 0, len ); /* clear sockaddr */
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = 8769;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
```
Next, bind the socket to the well-known address in sockaddr.




```c
    if ( bind( snum, (struct sockaddr *)&sockaddr, len ) < 0 )
    {
        AppPanic("Socket Binding:",errno);
    }

    /*
    ** Okay, the socket is as ready as it gets.  Now all we need to do is to
    ** tell the system that the socket is open for business.
    */

    listen( snum, 5 );
```
The call to bind() takes the socket identifier and sockaddr_in
structure and assigns a unique network identity (a transport address)
to the socket, making it visible to the network.  The listen() call
tells socket.library the socket is ready to receive incoming messages.
The '5' in the listen() call tells the system the size of the
connection request queue.

A connection request that a client sends to the server's socket goes
into this queue and waits for the server to process it.  If requests
arrive at the server's socket faster than the server can process them,
the queue fills to capacity.  While the queue is full, the system
rejects any other incoming connection requests.  ShowNote uses 5
because that is the maximum allowed by Berkeley Sockets.


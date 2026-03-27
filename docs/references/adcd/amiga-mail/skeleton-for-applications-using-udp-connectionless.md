---
title: Skeleton for Applications Using UDP (connectionless)
manual: amiga-mail
chapter: amiga-mail
section: skeleton-for-applications-using-udp-connectionless
functions: []
libraries: []
---

# Skeleton for Applications Using UDP (connectionless)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The basic outline of most client/server model applications written with
UDP look something like this:

Server gets a socket with socket(), gets a port number with
getservbyname(), builds a sockaddr_in structure describing the server, and
gives that structure to bind() in order to attach a specific address to
the socket.  It then loops, waiting to recvfrom() any incoming datagrams
and responding to any requests in those datagrams.


```c
    int recvfrom(int socket, char *buf, int buflength, int flags,
                 struct sockaddr *clientname, int namelength)
```
The recvfrom() function is similar to the recv() function except it has
two extra parameters.  clientname is a buffer for a sockaddr_in structure.
When recvfrom() receives a datagram from some application on the network,
it fills in clientname with the transport address of that application.
The size of the structure is namelength.

The client gets a server hostname from the user, gets a socket(), gets the
server's port number with getservbyname(), builds a sockaddr_in structure
describing the server, and sendto()s a datagram to the server's well-known
address:

int sendto(int socket, char *buf, int buflength, int flags, struct
sockaddr *servername, int namelength) The client either waits for the
server to send back a datagram to the client's socket, or give up because
the server took too much time to reply.  The client does this by calling
select().  This function puts the client to sleep until either a
particular set of sockets is ready for reading, writing, or exception
processing, or after a timeout period has passed without any activity.


```c
    int select(int numsocks, fd_set *readsocks, fd_set *writesocks,
               fd_set *exceptsocks, struct timeval *timeout)
```
The numsocks parameter is 1 plus the number of sockets select() is waiting
on. The readsocks, writesocks, and exceptsocks parameters are each a
bitmask which tells select() which socket (or sockets) to wait for
activity on.  The fd_set structure (defined in <sys/types.h>), is
basically a handle to one of these bitmasks.  Programs cannot directly
manipulate the bits in these masks. Instead, there are functions to do
this:


```c
    FD_ZERO(struct fd_set *mymask)                /* clear all bits in
                                                     mymask */
    FD_SET(int mysocket, struct fd_set *mymask)   /* turn on the bit for
                                                     mysocket in mymask */
    FD_CLR(int mysocket, struct fd_set *mymask)   /* turn off the bit for
                                                     mysocket in mymask */
    FD_ISSET(int mysocket, struct fd_set *mymask) /* test if mysocket's bit
                                                     in mymask is set */
```
For the purposes of this article, the only relevant mask is readsocks,
because the client is only waiting to read from a socket.  Since the
client isn't interested in the other masks, it makes writesocks and
exceptsocks NULL.

The last parameter, timeout, sets the maximum amount of time that select()
should wait for activity on the sockets it is watching.

When select() returns, its return value is either -1 if it failed, 0 if
there was a timeout, or a positive number, which is the number of sockets
that became ready.  When select returns, it sets the bits in the bitmasks
according to which socket (or sockets) became ready.

When select() returns, if a socket became ready, the client calls
recvfrom() to get the datagram the server sent back.  On timeout, the
client might try to re-send the datagram since it may have been lost or
corrupted.  Datagrams can be also be received in an order different from
that in which they were sent and can be received in duplicate.


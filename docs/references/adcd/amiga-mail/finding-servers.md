---
title: Finding Servers
manual: amiga-mail
chapter: amiga-mail
section: finding-servers
functions: []
libraries: []
---

# Finding Servers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A client "finds" its server by the server's transport address.  As was
mentioned eariler, the transport address consists of a protocol, a host
address, and a port number.  For the TCP/IP protocol stack, the protocol
is either TCP or UDP.

The next thing the client needs to build after the transport address is an
internet address for the server's machine.  Normally the client obtains
that address from the user.  The address can be in one of two forms, an
internet address (in dotted decimal notation), or a host name which is an
ASCII string that corresponds to the host's internet address.  If the
client gets a host name, it asks the socket.library what internet address
corresponds to the host name.

When a server starts, it opens a socket and bind()s that socket using the
server's well-known port number.  There are two ways for the server's
well-known port to become well-known:

  1) A server's well-known port number can be hard-coded into both the

```c
     client and server.  This is recommended for prototyping new programs,
     but is a Very Bad Thing for programs which will be distributed.  The
     port number is arbitrary, but must not be one of the reserved ports
     (see the next section) and must not conflict with a port number
     already in use.
```
  2) Port numbers can be configurable.  All distributed network

```c
     applications should use configurable port numbers.  In programs
     written for AS225, you should use the inet:db/services file to
     configure a port number.  The function getservbyname() accepts a
     protocol (UDP or TCP) and the name of a well-known server and returns
     the port number of that service.  This requires you to configure your
     application by adding an entry to the inet:db/services file on every
     machine which will use the application.  Many standard Internet
     applications and Unix remote services are already in the
     inet:db/services file that comes with AS225.  If your application
     isn't already included, your installation scripts should add the
     entry for your application to inet:db/services.  Offer a default
     value, but let your user actually pick the number since your port
     number must not conflict with another (pre-existing) port number.
```

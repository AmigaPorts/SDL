---
title: Protocol Layers and the Berkeley Sockets Interface
manual: amiga-mail
chapter: amiga-mail
section: protocol-layers-and-the-berkeley-sockets-interface
functions: []
libraries: []
---

# Protocol Layers and the Berkeley Sockets Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Network applications should always be written to the Application
Programmer's Interface (API) of a particular protocol, not to the network
hardware.  Network standards usually include several protocols layered one
on top of another. These groups are often referred to as protocol stacks.
At the lowest level, one of the protocols must interface to some network
hardware.  Each layer adds some abstraction to using the network on a
lower level.  This serves to make it easier to program network software as
the developer doesn't have to deal with networking details that are well
below the level of the software under development.

The International Standards Organization (ISO) has created a reference
model on which to base new network layerings.  The ISO 7-Layer Reference
Model of Open Systems Interconnection looks like this:




```c
                 ------------------------------------
                | 7  Application                     |
                |------------------------------------|
                | 6  Presentation                    |
                |------------------------------------|
                | 5  Session                         |
                |------------------------------------|
                | 4  Transport                       |
                |------------------------------------|
                | 3  Network                         |
                |------------------------------------|
                | 2  Data Link (Hardware Interface)  |
                |------------------------------------|
                | 1  Physical Hardware Connection    |
                 ------------------------------------

                     ISO-7 Layer Reference Model
```
The only protocol stack for the Amiga which is currently available from
Commodore is TCP/IP.  Our AS225 software package includes the standard
TCP/IP protocols and several standard Internet applications.  It has the
same API as most Unix machines running TCP/IP using the Berkeley Sockets
interface.

Unix was designed to have a common method of accessing both files and
devices. Before a Unix application can perform any I/O operations on a
file, it has to open() it.  The Unix open call returns an integer called a
file descriptor that corresponds to the open file.  The application uses
this file descriptor to manipulate the file.

This method of I/O is not quite general enough for networking.  Instead,
there is the Berkeley Sockets interface.  A socket is an entity used to
send and receive data across a network.  A socket can be "plugged in" or
bound directly to the socket of some other application on another machine
somewhere on the network.  Like the Unix file system, applications access
their sockets using a file descriptor, although it is typically referred
to as a socket descriptor.

Thousands of network applications have been written to the socket
interface. AS225 has been shipping since December, 1990, and everything
needed to write network applications for AS225 is included on the 1991
DevCon disks and on the Network Developer's Disk.

On the Amiga, layers 1 and 2 should always be the network hardware and
SANA-II Network Device Driver (SANA-II defines the lowest level software
interface to networking hardware).  In AS225, layer 3 is the IP and ICMP
protocols of the TCP/IP protocol stack.  These protocols aren't used
directly by application developers.  Essentially, they handle machine to
machine communication.  The transport layer uses the network layer (and
the layers below it) to provide communication between individual processes
on different machines.  Most current network applications use transport
protocols.  The transport protocols in TCP/IP are TCP and UDP.

The TCP transport protocol is a connection-oriented, stream protocol.
Basically, the socket of one application connects to the socket of another
application and they communicate across the network in data streams.  The
two applications can be running on arbitrary machines on a network.  The
big plus of using TCP is that it is a reliable protocol.  If the data is
put in one end of a TCP stream, it either gets to the other end intact, or
not at all (which causes an error at the sender's end).  This makes it
easier to program applications because the application programmer does not
have to worry about packet corruption.

UDP is a connectionless, datagram protocol.  An application using UDP
sends datagrams to some other application on the network.  A datagram is a
fixed-length message.  Because the sockets of UDP applications are not
connected, a datagram sent from a socket can be sent to an arbitrary UDP
socket.  Unlike TCP, UDP is not a reliable protocol, so an application
that uses UDP has to account for errors that can occur during transmission.

The details of all the various protocols and how they behave are quite
complex and are beyond the scope of this article.  This article deals with
the difference between connection-oriented stream protocols (sockets which
are obtained as type SOCK_STREAM) and connectionless datagram protocols
(type SOCK_DGRAM).

The Amiga Shared Socket Library (socket.library) is Commodore's
implementation of the standard functions for manipulating, sending data
to, and receiving data from sockets.  Other network APIs for TCP/IP have
been written for other platforms (most notably TLI on Unix SVR4 systems).
Programs written using sockets on one machine can communicate just fine
with programs written using another API (i.e., TLI) on another machine.
Sockets are not specific to TCP/IP.  They can be used with different
"domains".  TCP/IP is one domain, another network protocol is another
domain and local Inter-Process Communication (IPC) is yet another.  Our
socket library currently supports only TCP/IP.

Layers 5 and 6 of the OSI model, the presentation and session layers, do
not exist in TCP/IP, or most other protocol stacks.  So with TCP/IP on the
Amiga, the protocol stack looks like this:




```c
                 -------------------------------------------
                | Application                               |
                |-------------------------------------------|
                | Transport (TCP, UDP)                      |
                |-------------------------------------------|
                | Network   (IP, ICMP)                      |
                |-------------------------------------------|
                | Data Link (SANA-II Network Device Driver) |
                |-------------------------------------------|
                | Hardware  (ethernet, arcnet, ...)         |
                 -------------------------------------------

                           TCP/IP Protocol Stack
```
In spite of the fact that protocols come in a stack, your application will
only come into direct contact with a protocol at the top of the stack.  In
the case of TCP/IP, this is the transport layer.  In theory, you are not
required to know protocols below the one used for your application.  In
practice, higher-level protocols are often described in terms of additions
to lower-level protocols.


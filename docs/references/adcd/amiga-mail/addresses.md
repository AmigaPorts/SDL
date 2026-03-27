---
title: Addresses
manual: amiga-mail
chapter: amiga-mail
section: addresses
functions: []
libraries: []
---

# Addresses

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All data on the network is sent to and from network addresses.  There are
many different types of network addresses, at least one type for each
layer of the protocol stack.  For example, the Network layer of the TCP/IP
protocol stack uses the IP and ICMP protocols which use 32-bit internet
addresses (which are usually represented in "dotted decimal notation"
e.g., 192.9.210.4) to talk to a specific machine at a specific
internet-style address.  When applications communicate with each other,
they usually use a transport layer protocol, therefore the data is sent
from one transport address to another.  A transport address generally
corresponds to a specific program running on a specific machine somewhere
on a network.

A transport address consists of three parts: a protocol, a host address,
and a process association.  In AS225, the protocol in a transport address
is either TCP or UDP.  The host address is dependent upon the protocol,
but in AS225, the host address is always the internet address of the host.
The process association is also protocol dependent, and in AS225, the
process association is a port number.  TCP/IP port numbers are 16-bit
integers that are used by the transport protocols on each host to direct
network traffic to a specific process running on the machine at that
internet address.

The set of port numbers is unique to each protocol.  For example, port
number 42 for UDP might belong to a different process than that which
belongs to port number 42 for TCP.  Without port numbers, multiple network
programs could not run simultaneously.

Transport protocols are analogous in some ways to Amiga Exec devices.  In
such an analogy, there is a TCP device and a UDP device.  Each device has
about 65,000 units and none of the units can be opened in shared mode.

Once a socket is created, it has to be bound to a transport address.  An
application binds an address to a socket in one of two ways.  The binding
can be made explicitly by the program to a specific transport address
(using the bind() call).  Servers normally use this type of binding.  In
this case, the server uses a preset, "well-known" port number in its
transport address.  The port number is well-known because all of the
server's possible clients know what that particular server's port number
is.   Because these clients know the server's port number, the clients can
construct a transport address for that particular service on any machine
that runs that server.  For example, the default, well-known port number
for ftp is 21.  If a client wants to use ftp to transfer files from a
machine at the internet address 192.9.210.4, it can use ftp's port number,
the machine's internet address, and the protocol (ftp uses TCP) to find
the ftp server at 192.9.210.4.  As long as there is an ftp server running
at 192.9.210.4, the client should have no problem finding the server. This
type of socket is analogous to a public message port.

The other way to bind a socket to a transport address is to let the socket
library arbitrarily choose a port number for the application.  Normally
client applications bind this way because a client does not need a
well-known address. The client supplies the server with its transport
address when it sets up communication with the server.  This type of
socket is analogous to a private Exec message port.


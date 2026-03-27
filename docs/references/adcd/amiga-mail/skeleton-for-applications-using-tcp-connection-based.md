---
title: Skeleton for Applications Using TCP (connection-based)
manual: amiga-mail
chapter: amiga-mail
section: skeleton-for-applications-using-tcp-connection-based
functions: []
libraries: []
---

# Skeleton for Applications Using TCP (connection-based)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Aside from the special quirks of the socket.library (which is discussed in
the "[Shared Socket Library](amiga-mail/the-shared-socket-library.md)" section below), the basic outline of the core
of most client/server model applications written with TCP starts with the
server:

Create a socket:


```c
    int socket(int family, int type, int protocol)
```
Where family specifies the protocol family (which for the TCP/IP protocol
stack is AF_INET from <sys/socket.h>), type specifies the abstract type of
communication (either SOCK_STREAM for TCP or SOCK_DGRAM for UDP), and
protocol is not generally used in the TCP/IP protocol stack and should be
set to zero. If socket() fails, it returns a -1, otherwise it returns a
socket descriptor.

Next, get the well-known port number of the server's service:


```c
    struct servent *getservbyname(char *family, char *service)
```
where family is one of two strings, "tcp" or "udp".  The service argument
is the name of the service that this server provides.  The function
returns a NULL if there was an error.  Otherwise, it returns pointer to a
servent structure (from <netdb.h>):


```c
    struct  servent {
        char   *s_name;      /* official service name */
        char   **s_aliases;     /* alias list */
        int    s_port;       /* port # */
        char   *s_proto;     /* protocol to use */
    };
```
Next, build a sockaddr_in (from <netinet/in.h>) structure using the port
number from the s_port field of the servent structure returned by
getservbyname():


```c
    struct in_addr {
        u_long s_addr;
    };

    struct sockaddr_in {
        short     sin_family;        /* address family.  Make this
                                        AF_INET for TCP/IP */
        u_short   sin_port;          /* the port number (the value from
                                        servent.s_port)    */
        struct    in_addr sin_addr;  /* internet address. For TCP/IP, make
                                        sin_addr.s_addr INADDR_ANY.  Bind
                                        will know what to do with this. */
        char      sin_zero[8];       /* unused by TCP/IP */
    };
```
The sockaddr_in structure is a TCP/IP specific version of the sockaddr
structure.

Now give the sockaddr_in to bind() in order to attach a specific address
to the socket:


```c
    int bind(int servsocket, struct sockaddr *name, int namelength)
```
where, servsocket is the socket descriptor of the socket that needs a
specific address, name is a pointer to the sockaddr structure (or, for
TCP/IP purposes, a sockaddr_in structure) that describes the address, and
namelength is the length of the sockaddr structure.

Once the socket is bound to an address, the server calls listen() to
indicate that it is waiting to receive connections.

The server is ready to start its main processing loop.  The accept()
function waits for and accepts a new connection at a socket:


```c
    int accept(int servsocket, struct sockaddr *name, int namelength)
```
where, servsocket is the socket (descriptor) on which the server is
waiting for connections, name points to a buffer where accept() copies a
sockaddr structure describing the client that is trying to connect to the
server, and namelength is the length of the name buffer.

If accept() fails, it returns a negative value, otherwise accept() returns
a socket descriptor of a new socket that is connected to the client's
socket.

The server can communicate with the client using the new socket while it
continues to listen to its original socket for new connections.  The
server may serve one client at a time (an iterative server), or give the
new socket (the one returned by accept()) to a new process so it can
handle talking to the client (a concurrent server).

Setting up the client is similar to setting up the server.  You have to
create a socket, find the service's well-known port number, and initialize
a sockaddr_in structure that refers to the server.  Creating the socket
and finding the service's port number are identical to the method
described above.

To initialize the sockaddr_in structure, fill in the sin_family (AF_INET)
and sin_port (service's well-known port number) fields as in the server.
To fill in the sin_addr field, the client needs to find the internet
address of the server's machine.  The client has to find this from either
from an ASCII string of the IP address or the host name (either of which
the client will probably get from the user).  The inet_addr() function
accepts an ASCII string of a numeric IP address and returns the internet
address to put in the sockaddr_in's sin_addr.s_addr field.  If the client
only has the host name, it has to call gethostbyname() to find out the
server's machine address:


```c
    struct hostent *gethostbyname(char *hostname)
```
The parameter hostname is an ASCII string naming the host.  This function
figures out the address of the host (usually by looking it up in the
inet:db/hosts file).  This function returns a pointer to a hostent
structure:


```c
    struct  hostent {
        char   *h_name;       /* official name of host */
        char   **h_aliases;   /* alias list */
        int    h_addrtype;    /* host address type */
        int    h_length;      /* length of address */
        char   **h_addr_list; /* list of addresses from name server */
    #define  h_addr  h_addr_list[0]  /* address, for backward
                                        compatibility */
    };
```
The #defined field, h_addr, contains a pointer to an in_addr structure,
which contains the actual host address.  Copy this value into the
sockaddr_in.sin_addr.s_addr field.

Now the client needs to establish a connection between itself and the
server. It does this with the connect() function():


```c
    int connect(int clientsocket, struct sockaddr *servname,
                int namelength)
```
where, clientsocket is the socket the client created earlier, servname
points to the sockaddr_in structure the client just built, and namelength
is the length of that sockaddr_in structure.

The server and client communicate using the send() and recv() functions:


```c
    int send(int socket, char *buf, int buflength, int flags)
    int recv(int socket, char *buf, int buflength, int flags)
```
where, socket is the socket to send to/receive from, buf is a buffer that
contains the data to transmit/is a place for recv() to put the data it
receives, buflength is the length of buf, and flags is beyond the scope of
this article.  For the moment, you can set it to zero.

The data is a continuous stream, with any meaning assigned by the
application protocol (not to be confused with the network protocol).  The
data is always received either intact or not at all.  The data almost
always gets there unless there is a serious network or host machine
problem.  When the communications are finished, both sides s_close() the
sockets which were connected.


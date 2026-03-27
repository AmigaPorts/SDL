---
title: Identifying Network Events and Talking to the Client
manual: amiga-mail
chapter: amiga-mail
section: identifying-network-events-and-talking-to-the-client
functions: [DisplayBeep]
libraries: [intuition.library]
---

# Identifying Network Events and Talking to the Client

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If selectwait() returned as a result of a network event, then a bit
more detective work is needed to determine which socket caused the
event.  The example only has to watch a single socket, so if that
socket wasn't the cause, an error occurred.  In more complex servers,
the server might have to check each of several sockets using the
FD_ISSET() macro to determine which one caused the event.  There is
also the possibility that more than a single event came in at the same
time, so an application with many active sockets needs to take into
account the possibility of multiple true results from FD_ISSET().


```c
    if (FD_ISSET( socket, &mask ))
    {
        HandleMsg( socket );
    }
    else
    {
        AppPanic("Network Signal Error!",0);
    }
```
The FD_ISSET() macro checks if there was activity on a socket by
checking if the socket's bit is set in the socket mask passed to
selectwait().  In this code, there is only a single active socket, so
if that socket isn't the trigger then there was an error.

When a client tries to talk with a server, it first attempts to get a
connection between itself and the server.  In this example, the server
application returns from its selectwait() with that socket identified
in the mask variable.  The server has to accept the connection:


```c
    sockadd_in saddr;
    int len;

    if (!(nsock = accept( sock, (struct sockaddr *)&saddr, &len )))
    {
        AppPanic("Accept:",errno);
    }
```
When the server calls accept(), the function attempts to form a
connection with the client.  If it can do so, it returns a new socket
identifier.  The new socket identifier corresponds to a new socket
where the all future communication between the client and server will
occur.  This allows concurrent servers to use an existing socket to
establish new connections while carrying on other private client-server
conversations.

The accept() function also passes back a sockaddr_in structure
describing the client.  In this example, the server uses this address
to figure out the client's host name:



```c
    struct hostname *hent;
    struct in_addr sad;
    char *dd_addr, *hname, rname[80];


    /*
    ** Get the internet address out of the sockaddr_in structure and then
    ** create a dotted-decimal format string from it.
    */

    sad = saddr.sin_addr;
    dd_addr = inet_ntoa(sad.s_addr);

    /*
    ** Use the internet address to find out the machine's name
    */

    if ( !( hent = gethostbyaddr( (char *) &sad.s_addr,
                                  sizeof(struct in_addr),
                                  AF_INET )))
    {
        AppPanic("Client resolution:\nAddress not in hosts db!", 0 );
    }
    hname = hent->h_name;
```
Right now, if the server cannot identify the client's machine, it
terminates with an error.  While this may seem a bit drastic, it does
prevent anonymous messages from being sent across the system.  Coding a
secure client and server requires more complex protocols and involves
many other issues which are beyond the scope of this article.

After doing a little formatting of the address and name information,
the HandleMsg() function begins the actual process of communicating
with the client.




```c
    int nsock;
    struct NetNote in;

    /*
    ** Okay, now the waiting packet needs to be removed from the connected
    ** socket that accept() gave back to us.  Verify its of type NN_MSG and
    ** if not, set return type to NN_ERR.  If it is, then display it and
    ** return an NN_ACK message.
    */

    recv( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    if (in.nn_Code == NN_MSG)
    {
        DisplayBeep(NULL);  /* DisplayBeep() to get the user's attention */
        DisplayBeep(NULL);
        retv = DoER( rname, (char *)&in.nn_Text, (char *)&in.nn_Button );
        in.nn_Code = NN_ACK;
        in.nn_Retval = retv;
    }
    else
    {
        in.nn_Code = NN_ERR;
    }
```
The recv() function removes a struct NetNote sized amount of data from
the socket nsock and places that information in a buffer.  Once the
message packet is in the buffer, the server verifies it is a proper
packet by checking the nn_Code.  The checking isn't really necessary
since the example uses a reliable protocol (TCP) and there is only one
type of packet the server can receive.  After checking the packet, the
server prepared the nn_Code field for the return trip to the client.
If there was something wrong with the packet, the server sets nn_Code
to NN_ERR, otherwise the server sets nn_Code to NN_ACK. If there was no
error, the server extracts the message and button text from the NetNote
packet.  The server passes them plus name and address information for
the client to the DoER() routine.  The DoER() routine creates a system
EasyRequest, displays it, and returns a value which corresponds to the
button which was pressed.  The return information on which button was
pressed is encoded into the nn_Retval field of the NetNote packet,
which is then ready to be sent back to the client.

The prepared packet is sent back to the client using the send()
function:



```c
    /*
    ** Having dealt with the message one way or the other, send the message
    ** back at the remote, then disconnect from the remote and return.
    */

    send( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    s_close( nsock );
```
The HandleMsg() function then closes nsock using s_close(). The packet
protocol between the client and server in this application is defined
so there are no cases where the client would send another message, so
it can close the socket and break the connection.  The
acknowledgement/error packet will arrive at the client regardless of
whether the connection is still active or not, at least under TCP/IP.
HandleMsg() returns to the main() routine and event loop.

Once back in the main event loop, the server will continue connecting
and responding to client messages until it receives a Ctrl-C interrupt
or an error condition occurs.

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)

---
title: Locating the Server Port and Connecting to It
manual: amiga-mail
chapter: amiga-mail
section: locating-the-server-port-and-connecting-to-it
functions: [ReadArgs]
libraries: [dos.library]
---

# Locating the Server Port and Connecting to It

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The next step is to find the server's port number.  In the case of this
example, the port name is hardcoded into the server and client.  A real
networked application should have an entry for the "note" service in
the inet:db/services file.  The code below finds the port number in the
client machine's inet:db/services file.




```c
    struct servent *servptr;
    char servnam[] = "note";

    if ((servptr = getservbyname( servnam, "tcp" )) == NULL)
    {
        printf("%s not in inet:db/services list!",servnam);
        FinalExit( RETURN_ERROR );
    }
    serv.sin_port = servptr->s_port;


    /*
    ** This tells the system the socket in question is an Internet socket
    */

    serv.sin_family = AF_INET;
```
Since the client and server are running on top of an IP (Internet
Protocol) system, the client needs to specify AF_INET in its call to
socket() just as the server did.



```c
    /*
    ** Initialize the socket
    */

    if ( (sock = socket( AF_INET, SOCK_STREAM, 0 )) < 0 )
    {
        printf("socket gen: %s\n", strerror(errno));
        FinalExit( RETURN_ERROR );
    }
```
The client socket is initialized and ready.  Because the client knows
the IP address of the server's machine and the service number of the
"note" service, the client knows the well-known transport address so
it can attempt to establish a connection with the server:



```c
    /*
    ** Connect the socket to the remote socket, which belongs to the
    ** server, and which will "wake up" the server.
    */

    if ( connect( sock,
                  (struct sockaddr *) &serv,
                  sizeof(struct sockaddr) ) < 0 )
    {
        printf("connect: %s\n", strerror(errno));
        s_close( sock );
        FinalExit( RETURN_ERROR );
    }
```
The connect() call contacts the server across the network and attempts
to form a connection.  There are many things which can go wrong at this
point, and any return less than zero indicates an error condition.  If
an error does occur, the socket.library function strerror() converts
the error number in errno into a readable error message, which is then
displayed by the client.  In case of an error, the client already has a
socket open, so it then must close the socket and terminate using the
application's error handler, FinalExit().

Once the connection is established, the client needs to prepare the
note request packet.  Since the call to ReadArgs() has already parsed
everything, the client only has to copy the strings into a NetNote
structure:


```c
    struct NetNote out;

    out.nn_Code = NN_MSG;
    strcpy( (char *)&out.nn_Text, text );
    strcpy( (char *)&out.nn_Button, button );
```
The client has filled in all the relevant fields of the NetNote
structure, so it is ready to send.  The server will fill in the
nn_Retval field before passing it back to the client, so the client
doesn't need to fill it in for the client-to-server leg of the trip.
All that remains is to transfer the packet across the network:



```c
    send( sock, (char *)&out, sizeof(struct NetNote), 0 );

    printf("\nMessage sent to %s...waiting for answer...\n", hostnam );

    /*
    ** Wait for either acknowlegde or error.
    */

    recv( sock, (char *)&out, sizeof(struct NetNote), 0 );
```
Now the client has to wait for the server to respond.  This is one of
the few points where the client can hang forever.  If the server
receives the message, and never replies back, the client will never
stop waiting for a reply.  A real application would time-out if the
server didn't respond within a certain time interval.  One way to do
this is using a selectwait() which breaks when triggered by a
timer.device event.  We'll leave that as an exercise.

The call to recv() waits until the server sends back a reply.  Once the
client receives the reply, the client has to check the NetNote
structure's nn_Code field.  If it's NN_ERR, an error occurred, and the
client terminates through the FinalExit() handler.  If an NN_ACK packet
comes back from the server, the nn_Retval field contains the number of
the button the user pressed on the ShowNote requester.

The server gets the button number directly from the EasyRequest()
function that the server uses to pop up the requester.  The buttons on
the requester are numbered from 1, increasing left to right, except for
the rightmost button, which is button zero.  If there is only one
button, that button will return a zero (it's the furthest right).

After the client gets the packet back from the server, the client's
task is complete.  It only has to clean up after itself.

---

## See Also

- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)

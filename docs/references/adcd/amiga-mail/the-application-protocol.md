---
title: The Application Protocol
manual: amiga-mail
chapter: amiga-mail
section: the-application-protocol
functions: []
libraries: []
---

# The Application Protocol

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The note program now needs an application protocol for sending
information between the client and server.  When the client sends a
request message to the server, it needs to send the note string.  It
also would be nice to supply the text for the buttons that will pop up
in the requester.  On the return trip from ShowNote to the SendNote
client, the protocol only needs to define some return codes so the
client can tell if the request worked and which button on the requester
the remote user clicked.  Because the application needs to send
different types of packets (one type containing a message request, the
other type containing the response from the server), the protocol needs
to have a way to specify a packet type.

The following structure is the packet that ShowNote and SendNote send
back and forth to each other:


```c
    struct NetNote
    {
        int nn_Code;
        int nn_Retval;
        char    nn_Text[200],
                nn_Button[40];
    };
```
On the trip from client to server, the nn_Code field is the message
request packet type (NN_MSG), nn_Text is the note for the remote user,
and nn_button is the text for the EasyRequest buttons.  On the return
trip, nn_Code is either NN_ACK, if there was no error, or NN_ERR, if
there was an error.  If there was no error, nn_Retval contains the
number of the EasyRequest button that the user selected.

In this application, the same packet is passed back and forth for both
legs of the trip (client to server and vice versa).  If the application
required sending large chunks of data in one direction and small chunks
of data in the other direction, it would be a good idea to use packets
of different sizes.  Otherwise, if the application used only one packet
size, the size of the packet would be huge compared to the size of the
small chunk of data, which would unnecessarily loading the network.


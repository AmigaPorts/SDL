---
title: VIII-31: A Shared Socket Library Server and Client
manual: amiga-mail
chapter: amiga-mail
section: viii-31-a-shared-socket-library-server-and-client
functions: []
libraries: []
---

# VIII-31: A Shared Socket Library Server and Client

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by John Wiederhirn and John Orr


Wednesday is gyro day in CATS, so we have to go out to lunch and eat
gyros.  Because David the Engineer used to work in CATS, we are morally
obligated to bring him along.  Like the rest of the engineers, David is
usually working very hard and doesn't notice what time it is, so we
have to remind him that it's time to leave for lunch.  Unfortunately,
David can't hear us yelling to him in the Engineering department, so we
needed an alternate way to tell David that is was time for lunch.  The
only logical conclusion was to write a program that uses the Shared
Socket Library to make a requester pop up on David's Workbench screen
telling him it is lunch time.

To write a network application for the Shared Socket Library you will
need two things:

```c
    1) An understand the material in the article
       "[Developing Network Applications for the Amiga](amiga-mail/viii-17-developing-network-applications-for-the-amiga.md)" from the
       January/February 1992 issue of Amiga Mail.

    2) The Shared Socket Library include files and Autodocs
       (which are on the Network Developer's Disk and the
       Denver/Milano 1991 Devcon disks)
```
@rem link used to go to "cats_cd:devcon_disks/devcon_91/contents_91.2/Network!Socket"
This application has to be broken into two pieces, a client and a
server.  The client program will send out the notes.  On Amiga A, the
user runs the client (SendNote), passing it a note string (like
"David, it's time to eat") and a machine address for Amiga B.  The
client then sends a note request off to the note server (ShowNote) on
Amiga B.  When the note server gets the note request, it pops up an
EasyRequest containing the note on Amiga B.  The server waits for the
user to click an "OK" gadget, then sends back an acknowledgement to
the client.

There are a couple of decisions to make about the application before
coding anything.  First, there are two transport protocols to choose
from: TCP and UDP.  To make things easier, this application uses TCP
because it is a reliable protocol, so the application doesn't have to
worry about making sure data makes it across the network.  The
application uses a client/server model, but there are two of those
models to choose from: iterative and concurrent.  Because this
application does not need to handle more than one request at the same
time, the iterative server is a better choice.  This also makes coding
easier.

 [The Application Protocol](amiga-mail/the-application-protocol.md) 
 [The ShowNote Server Application](amiga-mail/the-shownote-server-application.md) 
 [Listening for Network and Amiga Events](amiga-mail/listening-for-network-and-amiga-events.md) 
 [Identifying Network Events and Talking to the Client](amiga-mail/identifying-network-events-and-talking-to-the-client.md) 
 [Starting the ShowNote Server](amiga-mail/starting-the-shownote-server.md) 
 [The SendNote Client Application](amiga-mail/the-sendnote-client-application.md) 
 [Resolving the Target (Host) Address](amiga-mail/resolving-the-target-host-address.md) 
 [Locating the Server Port and Connecting to It](amiga-mail/locating-the-server-port-and-connecting-to-it.md) 
 [Starting the SendNote Client](amiga-mail/starting-the-sendnote-client.md) 

 [Note.h](amiga-mail/viii-31-note-h.md)      [SendNote.c](amiga-mail/viii-31-sendnote-c.md)      [ShowNote.c](amiga-mail/viii-31-shownote-c.md) 


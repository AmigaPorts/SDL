# VIII-31: A Shared Socket Library Server and Client


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
       "[Developing Network Applications for the Amiga](../AmigaMail_Vol2_guide/node0102.html)" from the
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

 [The Application Protocol](../AmigaMail_Vol2_guide/node0110.html) 
 [The ShowNote Server Application](../AmigaMail_Vol2_guide/node0111.html) 
 [Listening for Network and Amiga Events](../AmigaMail_Vol2_guide/node0112.html) 
 [Identifying Network Events and Talking to the Client](../AmigaMail_Vol2_guide/node0113.html) 
 [Starting the ShowNote Server](../AmigaMail_Vol2_guide/node0114.html) 
 [The SendNote Client Application](../AmigaMail_Vol2_guide/node0115.html) 
 [Resolving the Target (Host) Address](../AmigaMail_Vol2_guide/node0116.html) 
 [Locating the Server Port and Connecting to It](../AmigaMail_Vol2_guide/node0117.html) 
 [Starting the SendNote Client](../AmigaMail_Vol2_guide/node0118.html) 

 [Note.h](../AmigaMail_Vol2_guide/node01DB.html)      [SendNote.c](../AmigaMail_Vol2_guide/node01DC.html)      [ShowNote.c](../AmigaMail_Vol2_guide/node01DD.html) 


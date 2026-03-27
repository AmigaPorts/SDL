---
title: The SendNote Client Application
manual: amiga-mail
chapter: amiga-mail
section: the-sendnote-client-application
functions: [ReadArgs]
libraries: [dos.library]
---

# The SendNote Client Application

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The client application, SendNote, sends a message for a server to pop
up on its display.  While the server is an Intuition program in that it
uses a requester to display the messages and get responses, the client
(SendNote) is strictly a CLI-based application.  SendNote parses its
command line using the AmigaDOS 2.0 ReadArgs() call.  For more
information on ReadArgs(), see the AmigaDOS Manual, 3rd Edition from
Bantam, the article "[Standard Command Line Parsing](amiga-mail/ii-27-standard-command-line-parsing.md)" from the May/June
1991 issue of Amiga Mail, or the DOS library includes and Autodocs.
There is very little difference in the application-wide setup of
sockets between the client and server.  Both must open socket.library
and call setup_sockets() to initialize the socket environment.  One
minor difference is the number of sockets the client initializes.  The
client only needs a single socket to establish a connection to the
server, where the server requires at least two (one for receiving
connection requests and one for talking to a client).

The FinalExit() routine is both the client's error handler and its
shutdown routine.  Since the client doesn't need to maintain so much
operating information, the shutdown routine is rather simple, and can
be used for both errors and normal termination.

---

## See Also

- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)

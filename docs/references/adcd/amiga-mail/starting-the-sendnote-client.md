---
title: Starting the SendNote Client
manual: amiga-mail
chapter: amiga-mail
section: starting-the-sendnote-client
functions: [ReadArgs]
libraries: [dos.library]
---

# Starting the SendNote Client

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The SendNote command has the following template, and uses the AmigaDOS
2.0 ReadArgs() call to parse the CLI command line:


    SENDNOTE HOST/A,TEXT,BUTTON
The HOST argument is the address of the server machine.  It is either a
dotted-decimal notation address or its ASCII  host name from the
inet:db/hosts file.  The TEXT argument is the string the server will
pop up in its requester.  The BUTTON argument is the ASCII string that
will appear in the requester button.  For example:


    sendnote 123.123.123.1 "I've fallen and I can't get up!" "Help me!"
displays a requester on the machine whose address is 123.123.123.1,
with the text of the requester saying "I've fallen and I can't get up!"
and a button labeled "Help me!".  If that machine is not running the
server, then SendNote just displays an error message and terminates.
If the inet:db/hosts file on the machine running SendNote has an entry
that gives 123.123.123.1 the name "foo", then


    sendnote foo "I've fallen and I can't get up!" "Help me!"
will have the exact same effect as the previous form of the command.
There are also default values for both the TEXT and BUTTON arguments.
If the user doesn't provide an argument for BUTTON, then ShowNote
defaults to "OK".  If both TEXT and BUTTON are missing, the TEXT
argument defaults to "==PING!==".  To give the user on the server
machine several buttons to choose from, put several strings in the
BUTTON argument delimited by `|` characters, like this:


    sendnote foo "Is it time yet?" "yes|no|maybe"
That's all there is to the client application.  Because the
socket.library routines take care of so much of the network "nitty
gritty", the application code can deal with networks in a
straight-forward and simple manner.  Two applications (client and
server), each around 8K bytes in size, are able to implement a complete
and working intranetwork communication system (albeit a very simplistic
one).  If you are interested in doing more serious development using
the AS225 software (and thus IP and TCP/UDP), you should take a look at
more advanced texts.  A good start is Unix Network Programming by W. R.
Stevens (Prentice-Hall, ISBN 0-13-949876-1).  It covers many aspects of
network protocol and application design, as well as explaining quite a
bit about "Berkeley Sockets" which socket.library implements.

---

## See Also

- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)

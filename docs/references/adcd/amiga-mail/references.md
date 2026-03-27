---
title: References
manual: amiga-mail
chapter: amiga-mail
section: references
functions: []
libraries: []
---

# References

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Comer, D.E. (1991a), Internetworking with TCP/IP, Volume I, 2d:
Principles, Protocols, and Architecture. Prentice-Hall, ISBN 0-13-468505-9


```c
    If you want more detail on how the protocols work (especially how
    they support internetworking), this is the place to look.  Little
    programming information is in this volume.
```
Comer, D.E. and Stevens, D.L. (1991b), Internetworking with TCP/IP, Volume
II: Design, Implementation and Internals. Prentice-Hall,
ISBM 0-13-472242-6.


```c
    There is more detail here than most application developers will want
    or need, but some subjects (i.e., Out-Of-Band data) are covered here
    better than in any other text.  The text includes a complete TCP/IP
    implementation for Xinu.  It should be easily understandable by Amiga
    developers, in part, because Xinu happens to have a rather Exec-like
    IPC mechanism.
```
Stevens, W.R. (1990), Unix Network Programming.  Prentice-Hall,
ISBN 0-13-949876-1.


    This book starts at the beginning and methodically leads the reader
    through many advanced topics.  If it weren't for the fact that it
    serves as a reference and a tutorial, it could be thought of as the
    RKMs for AS225 software development.  It introduces network protocols
    in some detail, and sockets in great detail.  It includes source and
    discussion of several real-world examples: ping, tftp, rlogin, lpr,
    rcmd, rmt, etc.  Everyone in the Amiga Networking group owns a copy.
RFCs
----

All Internet standards start life as Requests For Comments.  They are
still called RFCs even if they become required, recommended, or elective.
If you wish to implement a standard Internet application, you should
obtain any currently applicable RFC(s) and study them closely.  Here is
one way to obtain RFCs:

CSNET:
------


```c
    CSNET Coordination and Information Center (CIC)
            Hotline: (617) 873-2777
    10 Moulton Street, Cambridge, MA 02138
            Email:  cic@sh.cs.net
        Info-Server requests to: info-server@sh.cs.net
```
The CSNET Info-Server stocks all RFCs with numbers higher than 900, unless
(like RFC 900) they have been obsoleted by later RFCs.  The Info-Server
also stocks selected RFCs with numbers lower than 900.

The CSNET Info-Server is an automatic program that delivers information by
electronic mail.  To order a document from the Info-Server, send a message
to "info-server@sh.cs.net".  You do not need a subject field.  The text of
your message must be in a special format, such as:


             REQUEST: rfc
              TOPIC: heLP
              Topic: RFC822
             request: END
The text may any combination of upper-case and lower-case letters.

The above request asks for two documents "HELP" and "RFC822" from the
collection "RFC".  Your message must have a "REQUEST" line, and one or
more "TOPIC:" lines to specify one or more documents. The optional
statement "REQUEST: END" terminates your specification.  Any subsequent
text in the message is ignored by the Info-Server.


    NOTICE:
    -------
    The Topic: field must be of the form "rfc822", and NOT "822" or
    "rfc822.txt".

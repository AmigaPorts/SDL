---
title: Application Protocols
manual: amiga-mail
chapter: amiga-mail
section: application-protocols
functions: []
libraries: []
---

# Application Protocols

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Every networked program must agree on how to send data across the network
and on what meaning to attach to that data.  Therefore, the application
itself has a protocol.  This is the application layer of the ISO reference
model and TCP/IP protocol stack.  The application-specific protocol can
include such things as what transport protocol will be used, what
initialization takes place, how any security is implemented, what format
data will be in, etc.

For standard Internet applications (ftp for example), the application
protocols are specified in detail in one or more reference documents
called Requests for Comments, or RFCs.  RFCs are the specifications for
Internet protocols and standard applications.  Even if you aren't
implementing a standard Internet application, the RFCs offer insight into
the complexities of application protocols and how they should be
specified.  See the "[References](amiga-mail/references.md)" section of this article for more
information on RFCs and standard Internet applications.

Normally application protocols are general enough that network
applications can be ported to any machine which supports the network
protocol.  Neither the client nor the server knows (or cares) what type of
machine is at the other end.  Sometimes only one half of the application
(client or server) is available for a given machine.  For example, the
currently released version of AS225 includes an NFS (Network File System)
client program, but no NFS server program.  To use NFS with AS225 requires
access to any machine with an NFS server--it does not require any
particular type of machine.


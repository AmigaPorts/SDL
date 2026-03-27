---
title: Network Applications
manual: amiga-mail
chapter: amiga-mail
section: network-applications
functions: []
libraries: []
---

# Network Applications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most network applications are built around a client/server model.  In the
client/server model, a server application runs on one machine somewhere on
a network.  That server waits for a request for a particular service it
provides. These requests come from client applications that are running on
other machines on the network.  A service can be as simple as echoing back
text sent to the server or as complex as providing a remote login
facility.  For example, the ftp (File Transfer Program) application copies
files between networked machines.  Ftp actually consists of two programs,
a client and a server.  The server waits around for a client to request
some service, like listing a directory or transferring a file.

On most networks, each machine is capable of running both client and
server programs simultaneously, but on some networks a machine is either a
client or a server and may only run programs of that type.  The focus of
this article is peer-to-peer networks (the former), not client-server
networks (the latter).


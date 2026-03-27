---
title: Kinds of Servers
manual: amiga-mail
chapter: amiga-mail
section: kinds-of-servers
functions: []
libraries: []
---

# Kinds of Servers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two kinds of servers.  Those which process one request at a time
are called "iterative servers".  Those which simultaneously service
multiple requests (often by spawning a process to handle each request) are
called "concurrent servers".  Iterative servers are generally easier to
write, but are only suitable for services which can be handled quickly
and/or will not be accessed by multiple clients.  Applications which use
connectionless protocols (UDP) frequently have iterative servers, while
applications with connection-oriented protocols (TCP) usually have
concurrent servers.


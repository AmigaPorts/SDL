---
title: VIII-17: Developing Network Applications for the Amiga
manual: amiga-mail
chapter: amiga-mail
section: viii-17-developing-network-applications-for-the-amiga
functions: []
libraries: []
---

# VIII-17: Developing Network Applications for the Amiga

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Dale Larson


When you run a wire between two or more computers, you have a network.
Big Deal.  When your applications use that wire however, you have a
revolution. Although some of the following software is only internal or
experimental, these are things I can do now with my Amiga, with software
that I have now:


```c
    * From my Amiga, I can transparently access filesystems on Suns,
      on the local Vax system (cbmvax), and on other Amigas.

    * Whenever I print, I send my files to a network printer.

    * I continuously receive mail on my Amiga--from as far as
      Seattle, Sydney and Denmark, and near as a desk next to mine.

    * Every night when I go home, my Amigas at work (and several
      others) are used to do distributed graphics rendering.  The
      process is started over the network and all data is sent over
      the network.  A picture that would have taken a week can be
      finished overnight.
```
In the scheme of what is possible, this is only the tip of the iceberg.


```c
    * In a high school environment, a network could allow students
      to interactively participate in computer simulations.  It could
      allow them to collaborate electronically.  It could allow
      teachers to electronically monitor and assist students.  It
      could save schools money because peripherals such as printers,
      hard-drives and CD-ROMs could be easily shared.  Even the
      computational power of one expensive machine could be shared by
      the students.

    * A small office can use a network for an email-like facility
      for phone messages and other notes.  Another application might
      replace the intercom. Form letters can be kept in a central
      database accessed by a word processor.  A distributed
      appointment calendar could allow a secretary to add a new
      appointment even as the boss is looking at what his afternoon
      schedule is.  A distributed database application would allow
      access to such things as a central client database, outstanding
      orders and the present inventory.

    * Imagine multi-player games that use the computational power of
      each machine connected by a high speed Local Area Network (LAN).

    * In a software development environment, several programmers can
      work on the same project, updating the same sources.  Debugging
      information could be sent over the network, or a debugger on one
      machine could control the programs on others (For example, there
      is a version of Wack that runs over a network).

    * Multimedia applications might do any number of exciting things
      with the network.  A few of the applications which have been
      experimented with on other machines are: real-time audio and
      video conferencing, interactive demos for groups, and shared
      electronic blackboards.
```
In much the same way as all applications are candidates for a GUI
interface, all applications are candidates for becoming network
applications.  The GUI has only changed the ways in which people interact
with their computers.  Networks will change the ways in which people
interact with each other.

This article introduces some of the principles of writing network programs
using the AS225's Berkeley Socket interface.  Even more so than in most of
software development, networking seems simple in theory, but, in reality,
gets complicated in a hurry.  To develop network software for AS225, you
will need to obtain the Network Developer's kit from CATS.  It has all the
necessary include files and Autodocs to develop for the AS225's
socket.library.  Also, you should plan read at least some of the material
in the "References" section of this article.

 [Protocol Layers and the Berkeley Sockets Interface](amiga-mail/protocol-layers-and-the-berkeley-sockets-interface.md) 
 [Network Applications](amiga-mail/network-applications.md) 
 [Application Protocols](amiga-mail/application-protocols.md) 
 [Kinds of Servers](amiga-mail/kinds-of-servers.md) 
 [Addresses](amiga-mail/addresses.md) 
 [Finding Servers](amiga-mail/finding-servers.md) 
 [Reserved Ports](amiga-mail/reserved-ports.md) 
 [Skeleton for Applications Using TCP (connection-based)](amiga-mail/skeleton-for-applications-using-tcp-connection-based.md) 
 [Skeleton for Applications Using UDP (connectionless)](amiga-mail/skeleton-for-applications-using-udp-connectionless.md) 
 [Which Protocol Is Right For My Application?](amiga-mail/which-protocol-is-right-for-my-application.md) 
 [The Shared Socket Library](amiga-mail/the-shared-socket-library.md) 
 [References](amiga-mail/references.md) 


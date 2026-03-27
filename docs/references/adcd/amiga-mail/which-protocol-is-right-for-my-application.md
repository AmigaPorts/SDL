---
title: Which Protocol Is Right For My Application?
manual: amiga-mail
chapter: amiga-mail
section: which-protocol-is-right-for-my-application
functions: []
libraries: []
---

# Which Protocol Is Right For My Application?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Generally, if your application requires moving bulk data to far away
places, you should be using TCP.  For many other applications, TCP is also
appropriate just because its reliability makes it easy to use.  TCP is so
easy to use because it provides so much functionality.  The price paid for
ease of use is performance.

TCP does a good job of moving bulk data from one side of the planet to
another. For data which will only be sent across one physical network (one
LAN), or for data sent in small pieces, TCP doesn't perform so well.  A
much more specific set of functionality can always provide better
performance than the most general set can. For performance-critical
applications which don't move bulk data, UDP is usually the protocol of
choice.  Unfortunately, since UDP doesn't provide reliability, the
application protocol must.  This means a much more complicated application
protocol.  It isn't nearly as bad as it sounds, though, and Stevens (1990)
offers two examples.


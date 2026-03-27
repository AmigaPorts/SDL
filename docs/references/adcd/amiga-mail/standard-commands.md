---
title: Standard Commands
manual: amiga-mail
chapter: amiga-mail
section: standard-commands
functions: []
libraries: []
---

# Standard Commands

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

See the SANA-II Network Device Driver [Autodocs](amiga-mail/developer-support-package-sana2device-doc.md) for full details on each of
the SANA-II device commands. Extended commands are explained in the
sections below.

Many of the Exec device standard commands are no-ops in SANA-II devices,
but this may not always be the case. For example, CMD_RESET might someday
be used for dynamically reconfiguring hardware. This should present no
compatibility problems for properly written drivers.

 [Broadcast and Multicast](amiga-mail/broadcast-and-multicast.md)      [Configuration](amiga-mail/configuration.md) 
 [Stats](amiga-mail/stats.md)                        [On-line](amiga-mail/on-line.md) 


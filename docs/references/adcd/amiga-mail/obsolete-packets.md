---
title: Obsolete Packets
manual: amiga-mail
chapter: amiga-mail
section: obsolete-packets
functions: []
libraries: []
---

# Obsolete Packets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several packet types that are documented within the system
include files that are obsolete.  A file system is not expected to
handle these packets and any program which sends these packets can
not expect them to work:

ACTION_DISK_CHANGE      33      <Obsolete>


ACTION_DISK_TYPE        32      <Obsolete>


ACTION_EVENT             6      <Obsolete>


ACTION_GET_BLOCK         2      <Obsolete>


ACTION_SET_MAP           4      <Obsolete>

Of particular note here is ACTION_DISK_CHANGE.  The DiskChange
command uses the ACTION_INHIBIT packet to accomplish its task.


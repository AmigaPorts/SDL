---
title: VIII-51: SANA-II Network Device Driver Specification
manual: amiga-mail
chapter: amiga-mail
section: viii-51-sana-ii-network-device-driver-specification
functions: []
libraries: []
---

# VIII-51: SANA-II Network Device Driver Specification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Amiga Networking Group -  Brian Jackson, Dale Larson


                          Greg Miller, Kenneth Dyke
The SANA-II Network Device Driver Specification is a standard for an Amiga
software interface between networking hardware and network protocol stacks
(or for software tools such as network monitors). A network protocol stack
is a layer of software that network applications use to address particular
processes on remote machines and to send data reliably in spite of
hardware errors. There are several common network protocol stacks
including TCP/IP, OSI, AppleTalk, DECNet and Novell.

SANA-II device drivers are intended to allow multiple network protocol
stacks running on the same machine to share one network device. For
example, the TCP/IP and AppleTalk protocol stacks could both run on the
same machine over one ethernet board. The device drivers are also intended
to allow network protocol stacks to be written in a hardware-independent
fashion so that a different version of each protocol stack doesn't have to
be written for each networking hardware device.

The standard does not address the writing of network applications.
Application writers must not use SANA-II Device Drivers directly. Network
applications must use the API provided by the network protocol software
the application supports. There is not an Amiga standard network API at
the time of this writing, though there is the AS225 TCP/IP package and its
socket.library as well as other (third-party) packages.

To write a SANA-II device driver, you will need to be familiar with the
specification documents for the hardware you are writing to and with the
SANA-II Network Device Driver Specification.

To write a network protocol stack which will use SANA-II device drivers,
you should have general familiarity with common network hardware and must
be very familiar with the SANA-II Network Device Driver Specification as
well as the specification for the protocol you are developing. If you are
creating a new protocol, you must obtain a protocol type number for any
hardware on which your protocol will be used.

Commodore supports the SANA-II specification by providing drivers for the
Commodore-Amiga network hardware. We have an A2065.device (Ethernet) and
intend to produce an A2060.device (ARCNET). We also try to examine review
copies of third-party SANA-II networking hardware and software to try to
make sure that they interoperate with our products.

This standard has undergone several drafts with long periods for comment
from developers and the Amiga community at large. These drafts include a
UseNet release which was also distributed on the Fish Disks in June, 1991
(as well as published in the '91 DevCon notes), and the November 7 Draft
for Final Comment and Approval distributed via Bix, ADSP and UseNet. There
were also several intermediate drafts with more limited distribution.

This version of the specification is final. Any new version of the
standard (i.e., to add new features) is planned to be backward compatible.
No SANA-II device driver or software utilizing those drivers should be
written to any earlier version of the specification.

Distribution of this version of the standard is unlimited. Anyone may
write Amiga software which implements a SANA-II network device driver or
which calls a SANA-II network device driver without restriction and may
freely distribute such software that they have written. Amiga is a
registered trademark of Commodore-Amiga, Inc. Ethernet is a trademark of
Xerox Corporation. ARCNET is a trademark of Datapoint Corporation. DECNet
is a trademark of Digital Equipment Corporation. AppleTalk is a trademark
of Apple Computer, Inc.

It is important to try to test each SANA-II device driver against all
software which uses SANA-II devices. Available example programs are
valuable in initial testing. The Amiga Networking Group is interested in
receiving evaluation and/or beta test copies of all Amiga networking
hardware, SANA-II device drivers and software which uses SANA-II devices.
However, we make no assurances regarding any testing which we may or may
not perform with such evaluation copies. Contact:


    Amiga Networking Group
    Commodore International Services Corporation
    Technology Group
    1200 Wilson Drive
    West Chester, PA 19380, USA
 [Driver Form](amiga-mail/driver-form.md)                  [Ethernet Packet Types](amiga-mail/ethernet-packet-types.md)     [Errors](amiga-mail/errors.md) 
 [Opening a SANA-II Device](amiga-mail/opening-a-sana-ii-device.md)     [ARCNET Frames](amiga-mail/arcnet-frames.md)             [Standard Commands](amiga-mail/standard-commands.md) 
 [Buffer Management](amiga-mail/buffer-management.md)            [Addressing](amiga-mail/addressing.md)                [Acknowledgments](amiga-mail/acknowledgments.md) 
 [Packet Type](amiga-mail/packet-type.md)                  [Hardware Type](amiga-mail/hardware-type.md)             [Unresolved Issues](amiga-mail/unresolved-issues.md) 

 [SANA-II Developer Support Package](amiga-mail/viii-51-sana-ii-network-device-driver-specification-2.md) 


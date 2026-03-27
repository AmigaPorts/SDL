---
title: VIII-51: SANA-II Network Device Driver Specification
manual: amiga-mail
chapter: amiga-mail
section: viii-51-sana-ii-network-device-driver-specification-3
functions: []
libraries: []
---

# VIII-51: SANA-II Network Device Driver Specification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**	$Filename: ARCNET.txt $
**	$Revision: 1.3 $
**	$Date: 92/01/10 15:18:56 $

S2WireType_Arcnet	7

ios2_DataLength:

```c
    506 byte MTU (because of the possibility of two byte Types).
    Packets of size 254, 255, or 256 bytes are padded to 257 bytes before
    transmition.
```
Station Address:

    ARCNET hardware may have addresses set with jumpers, DIP switches
    or software.  Different drivers may therefore behave differently
    with S2_CONFIGINTERFACE.

    Hardware addresses should be assigned by users from highest to lowest
    because there is some efficiency gained in the token passing scheme
    this way.  For example, on a three node network, hardware numbers 254,
    253 and 252 should be used rather than 1, 2 and 3.
Raw reads and writes:
	Short Packets (1-253 bytes)
		Destination Address		(1 byte)
		Source Address			(1 byte)
		Count (256-N-Type length)	(1 byte)
		Padding				(to byte number Count)
		Type				(1 or 2 bytes)
		Data				(N bytes)

	Long Packets (257-506 bytes)
		Destination Address		(1 byte)
		Source Address			(1 byte)
		zero				(1 byte)
		Count (512-N-Type length)	(1 byte)
		Padding				(to byte number Count)
		Type				(1 or 2 bytes)
		Data				(N bytes)


Multicast:	Not Supported

Broadcast:	Supported

Promiscuous:	Generally Not Supported

Packet Type Numbers for ARCNET are assigned by:
	Datapoint Corporation

Some Common Packet Type Numbers

	decimal  hex    description
	-------  ---    -----------
	221      DD     AppleTalk
	240      F0     TCP/IP -- IP   (RFC 1051)
	241      F1     TCP/IP -- ARP  (RFC 1051)
	212      F0     TCP/IP    IP   (RFC 1201, proposed)
	213      F1     TCP/IP -- ARP  (RFC 1201, proposed)
	214	 D6	TCP/IP -- RARP (RFC 1201, proposed)
	247      F7     Banyan Vines
	250      FA     Novell IPX


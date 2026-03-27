---
title: SANA-II Developer Support Package / ethernet.txt
manual: amiga-mail
chapter: amiga-mail
section: sana-ii-developer-support-package-ethernet-txt
functions: []
libraries: []
---

# SANA-II Developer Support Package / ethernet.txt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**	$Filename: ethernet.txt $
**	$Revision: 1.2 $
**	$Date: 92/01/10 15:18:46 $


#define S2WireType_Ethernet             1

ios2_DataLength:
	valid ethernet packets have 64 to 1500 bytes of data.

Address format:
	Ethernet addresses consist of 47 bits of address information and
	a 1 bit multicast flag. The standard for expressing ethernet
	addresses is as 6 bytes (octets) in the order in which the bytes
	are transmitted with the low-order bits in a byte transmitted
	first. The multicast flag bit is the least-significant bit of the
	first byte.

	Ethernet addresses in a Sana2IOReq occupy the first 6 bytes of
	an address field in transmission order with the low-order bits in
	a byte transmitted first.

Station Address:
	Each ethernet board must have a unique ethernet hardware address.
	Drivers will override any attempt to set the address to anything
	other than the ROM address.

Raw reads and writes:
	6 bytes of destination address,
	6 bytes of source address,
	2 bytes of type,
	64 to 1500 bytes of data
	(followed by 4 byte CRC value covering all of the above
	 which is hardware generated and checked, hence not included
	 in even raw packets)

Multicast:	Supported

Broadcast:	Supported

Promiscuous:	Supported

Packet Type Numbers for Ethernet are assigned by:

	Xerox Corporation
	Xerox Systems Institute
	475 Oakmead Parkway, Sunnyvale, CA 94086
	Attn: Ms. Fonda Pallone
	(408) 737-4652


Some Common Packet Type Numbers:


```c
      decimal  Hex        Description
      -------  ---        -----------
         000   0000-05DC  IEEE 802.3 Length Field
        2048   0800       TCP/IP -- IP
        2054   0806       TCP/IP -- ARP
       32821   8035       TCP/IP -- RARP
       32923   809B       Appletalk
       33011   80F3       AppleTalk AARP (Kinetics)
       33100   814C       SNMP
       33079   8137-8138  Novell, Inc.
```

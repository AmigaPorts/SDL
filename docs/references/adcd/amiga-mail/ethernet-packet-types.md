---
title: Ethernet Packet Types
manual: amiga-mail
chapter: amiga-mail
section: ethernet-packet-types
functions: []
libraries: []
---

# Ethernet Packet Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Ethernet has a special problem with packet types. Two types of ethernet
frames can be sent over the same wire--ethernet and 802.3. These frames
differ in that the Type field of an ethernet frame is the Length field of
an 802.3 frame. This creates a problem in that demultiplexing incoming
packets can be cumbersome and inefficient, as well as requiring driver
users to be aware of the frame type used.

All 802.3 frames have numbers less than 1500 in the Type field. The only
frames with numbers less than 1500 in the type field are 802.3 frames.
SANA-II ethernet drivers abnormally return packets contained in ethernet
frames when the requested Type falls within the 802.3 range--if the Type
requested is within the 802.3 range, the driver returns the next packet
contained within an 802.3 frame, regardless of the type specified for the
packet within the 802.3 frame. This requires that there be no more than
one driver user requesting 802.3 packets and that it do its own
interpretation of the frames.


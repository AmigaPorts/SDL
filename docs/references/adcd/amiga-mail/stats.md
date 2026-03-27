---
title: Stats
manual: amiga-mail
chapter: amiga-mail
section: stats
functions: []
libraries: []
---

# Stats

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  S2_TRACKTYPE     S2_GETTYPESTATS      S2_GETGLOBALSTATS
  S2_UNTRACKTYPE   S2_GETSPECIALSTATS   S2_READORPHAN

There are many statistics which may be very important to someone trying to
debug, tune or optimize a protocol stack, as well as to the end user who
may need to tune parameters or investigate a problem. Some of these
statistics can only be kept by the SANA-II driver, thus there are several
required and optional statistics and commands for this purpose.

S2_TRACKTYPE tells the device driver to gather statistics for a particular
packet type. S2_UNTRACKTYPE tells it to stop (keeping statistics by type
causes the driver to use additional resources). S2_GETTYPESTATS returns
any statistics accumulated by the driver for a type being tracked (stats
are lost when a type is S2_UNTRACKTYPE'd). Drivers are required to
implement the functionality of type tracking. The stats are returned in a
struct Sana2PacketTypeStats:



```c
        struct Sana2PacketTypeStats
        {
          ULONG PacketsSent;
          ULONG PacketsReceived;
          ULONG BytesSent;
          ULONG BytesReceived;
          ULONG PacketsDropped;
        };

    PacketsSent     - Number of packets of a particular type sent.
    PacketsReceived - Number of packets of a particular type that
                      satisfied a read command.
    BytesSent       - Number of bytes of data sent in packets of a
                      particular type.
    BytesReceived   - Number of bytes of data of a particular packet
                      type that satisfied a read command.
    PacketsDropped  - Number of packets of a particular type that were
                      received while there were no pending reads of that
                      packet type.
```
S2_GETGLOBALSTATS returns global statistics kept by the driver. Drivers
are required to keep all applicable statistics. Since all are applicable
to most hardware, most drivers will maintain all statistics. The stats are
returned in a struct Sana2DeviceStats:



```c
        struct Sana2DeviceStats
        {
          ULONG PacketsReceived;
          ULONG PacketsSent;
          ULONG BadData;
          ULONG Overruns;
          ULONG UnknownTypesReceived;
          ULONG Reconfigurations;
          struct timeval LastStart;
        };

    PacketsReceived     - Number of packets that this unit has received.
    PacketsSent         - Number of packets that this unit has sent.
    BadData             - Number of bad packets received (i.e., hardware
                          CRC failed).
    Overruns            - Number of packets dropped due to insufficient
                          resources available in the network interface.
    UnknownTypeReceived - Number of packets received that had no pending
                          read command with the appropriate packet type.
    Reconfigurations    - Number of network reconfigurations since this
                          unit was last configured.
    LastStart           - The time when this unit last went on-line.
```
S2_GETSPECIALSTATS returns any special statistics kept by a particular
driver. Each new wire type will have a set of documented, required
statistics for that wire type and a standard set of optional statistics
for that wire type (optional because they might not be available from all
hardware). The data returned by S2_GETSPECIALSTATS will require
wire-specific interpretation. See <[devices/sana2specialstats.h](amiga-mail/viii-51-include-devices-sana2specialstats-h.md)> for
currently defined special statistics. The statistics are returned in the
following structures:



```c
        struct Sana2SpecialStatRecord
        {
          ULONG Type;
          ULONG Count;
          char *String;
        };

    Type   - Statistic identifier.
    Count  - Statistic itself.
    String - An identifying, null-terminated string for the statistic.
             Should be plain ASCII with no formatting characters.


        struct Sana2SpecialStatHeader
        {
          ULONG RecordCountMax;
          ULONG RecordCountSupplied;
          struct Sana2SpecialStatRecord[RecordCountMax];
        };

    RecordCountMax      - There is space for this many records into which
                          statistics may be placed.
    RecordCountSupplied - Number of statistic records supplied.
```
S2_READORPHAN is not, strictly speaking, a statistical function. It is a
request to read any packet of a type for which there is no outstanding
CMD_READ. S2_READORPHAN might be used in the same manner as many
statistics, though, such as to determine what packet types are causing
overruns, etc.


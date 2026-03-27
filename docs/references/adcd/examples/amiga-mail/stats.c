/* Source: ADCD 2.1
 * Section: stats
 * Library: amiga-mail
 * ADCD reference: amiga-mail/stats.md
 */

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

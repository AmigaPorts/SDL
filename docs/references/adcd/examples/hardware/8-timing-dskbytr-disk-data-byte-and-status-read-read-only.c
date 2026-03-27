/* Source: ADCD 2.1
 * Section: 8-timing-dskbytr-disk-data-byte-and-status-read-read-only
 * Library: hardware
 * ADCD reference: hardware/8-timing-dskbytr-disk-data-byte-and-status-read-read-only.md
 */

                 Table 8-7: DSKBYTR Register

     Bit
     Number  Name       Function
     ------  ----       --------
     15      DSKBYT     When set, indicates that this register contains
                        a valid byte of data (reset by reading this
                        register).

     14      DMAON      Indicates when DMA is actually enabled.  All the
                        various DMA bits must be true.  This means the
                        DMAEN bit in  [DSKLEN](../Hardware_Manual_guide/node0192.html) , and the DSKEN & DMAEN bits
                        in  [DMACON](../Hardware_Manual_guide/node0170.html) .

     13      DISKWRITE  The disk write bit (in  [DSKLEN](../Hardware_Manual_guide/node0192.html) ) is enabled.

     12      WORDEQUAL  Indicates the  [DSKSYNC](../Hardware_Manual_guide/node0195.html)  register equals the disk
                        input stream.  This bit is true only while the
                        input stream matches the sync register (as
                        little as two microseconds).

     11-8               Currently unused; don't depend on read value.

     7-0     DATA       Disk byte data.

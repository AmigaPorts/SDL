/* Source: ADCD 2.1
 * Section: 32-rigiddiskblock-and-alternate-filesystems-partitionblock
 * Library: libraries
 * ADCD reference: libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md
 */

                           containing:

       de_TableSize        size of Environment vector
       de_SizeBlock        == 128 (for 512 bytes/logical block)
       de_SecOrg           == 0
       de_Surfaces         number of heads (see [layout discussion](../Libraries_Manual_guide/node0420.html))
       de_SectorPerBlock   == 1
       de_BlocksPerTrack   blocks per track (see [layout discussion](../Libraries_Manual_guide/node0420.html))

       de_Reserved         DOS reserved blocks at start of partition.
                           Must be >= 1.  2 is recommended.

       de_PreAlloc         DOS reserved blocks at end of partition
                           Valid only for filesystem type DOS^A (the
                           fast file system).  Zero otherwise.

       de_Interleave       DOS interleave
                           Valid only for filesystem type DOS^@ (the
                           old file system).  Zero otherwise.

       de_LowCyl           starting cylinder
       de_HighCyl          max cylinder
       de_NumBuffers       initial # DOS of buffers.

       de_BufMemType       type of mem to allocate for buffers
                           The second argument to AllocMem().

       de_MaxTransfer      max number of bytes to transfer at a time.
                           Drivers should be written to handle requests
                           of any length.

       de_Mask             address mask to block out certain memory
                           Normally $00ffffff  for DMA devices.

       de_BootPri          Boot priority for [autoboot](../Libraries_Manual_guide/node041B.html)
                           Suggested value: zero.  Keep less than
                           five, so it won't override a boot floppy.

       de_DosType          ASCII string showing filesystem type;
                           DOS^@ ($444F5300) is old filesystem,
                           DOS^A ($444F5301) is fast file system.
                           UNI<anything> is a Unix partition.

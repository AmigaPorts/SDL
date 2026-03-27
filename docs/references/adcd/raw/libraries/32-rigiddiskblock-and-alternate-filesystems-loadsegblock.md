# 32 / / RigidDiskBlock and Alternate Filesystems / LoadSegBlock


This is the current specification of the LoadSegBlock. The end of data
occurs when lsb_Next is NULL ($FFFFFFFF), and the summed data is exhausted.


   lsb_ID                  == 'LSEG'

   lsb_SummedLongs         size of this checksummed structure

```c
                           Note that this is not 64 like most of the other
                           structures.  This is the number of valid longs
                           in this image, like [bbb_SummedLongs](../Libraries_Manual_guide/node0421.html#line6).
```
   lsb_ChkSum              block checksum (longword sum to zero)

   lsb_HostID              SCSI Target ID of host

```c
                           This describes the initiator ID for the creator
                           of these blocks.  (see [rdb_HostID](../Libraries_Manual_guide/node0420.html#line8) discussion)
```
   lsb_Next                block number of the next LoadSegBlock

   lsb_LoadData            data for "loadseg"

```c
                           The data starts here and continues as long
                           as indicated by lsb_SummedLongs-5: e.g. if
                           lsb_SummedLongs is 128 (ie. for 512 byte
                           blocks), 123 longs of data are valid here.
```

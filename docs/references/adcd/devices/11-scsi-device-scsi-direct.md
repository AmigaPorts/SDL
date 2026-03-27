---
title: 11 SCSI Device / SCSI-Direct
manual: devices
chapter: devices
section: 11-scsi-device-scsi-direct
functions: []
libraries: []
---

# 11 SCSI Device / SCSI-Direct

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SCSI-direct is the facility of the Amiga's SCSI device interface that
allows low-level SCSI commands to be passed directly to a SCSI unit on the
bus. This makes it possible to support the special features of tape
drives, hard disks and other SCSI equipment that do not fit into the
Amiga's normal I/O model. For example, with SCSI-direct, special commands
can be sent to hard drives to modify various drive parameters that are
normally inaccessible or which differ from drive to drive.

In order to use SCSI-direct, you must first open the SCSI device for the
unit you want to use in the manner described above.  You then send an
HD_SCSICMD I/O request with a pointer to a SCSI command data structure.

The SCSI device uses a special data structure for SCSI-direct
commands named SCSICmd.

   struct SCSICmd
   {
```c
    UWORD *scsi_Data;      /* word aligned data for SCSI Data Phase */
                           /* (optional) data need not be byte aligned */
                           /* (optional) data need not be bus accessible */
    ULONG  scsi_Length;    /* even length of Data area */
                           /* (optional) data can have odd length */
                           /* (optional) data length can be > 2**24 */
    ULONG  scsi_Actual;    /* actual Data used */
    UBYTE *scsi_Command;   /* SCSI Command (same options as scsi_Data) */
    UWORD  scsi_CmdLength; /* length of Command */
    UWORD  scsi_CmdActual; /* actual Command used */
    UBYTE  scsi_Flags;     /* includes intended data direction */
    UBYTE  scsi_Status;    /* SCSI status of command */
    UBYTE *scsi_SenseData; /* sense data: filled if SCSIF_[OLD]AUTOSENSE */
                           /* is set and scsi_Status has CHECK CONDITION */
                           /* (bit 1) set */
    UWORD  scsi_SenseLength;/* size of scsi_SenseData, also bytes to */
                           /* request w/ SCSIF_AUTOSENSE, must be 4..255 */
    UWORD  scsi_SenseActual;/* amount actually fetched (0 = no sense) */
```
   };

See the include file devices/[scsidisk.h](autodocs-2.0/includes-devices-scsidisk-h.md) for the complete structure
definition.

SCSICmd will contain the SCSI command and any associated data that you
wish to pass to the SCSI unit.  You set its fields to the values required
by the unit and the command.  When you have opened the SCSI device and set
the SCSICmd to the proper values, you are ready for SCSI-direct.

You send a SCSI-direct command by passing an [IOStdReq](devices/11-scsi-device-device-interface.md) to the SCSI device
with a pointer to the SCSICmd structure set in io_Data, the size of the
SCSICmd structure set in io_Length and HD_SCSICMD set in io_Command.:


```c
    struct IOStdReq *SCSIreq = NULL;
    struct SCSICmd Cmd;           /* where the actual SCSI command goes */

    SCSIreq->io_Length  = sizeof(struct SCSICmd);
    SCSIreq->io_Data    = (APTR)&Cmd;
    SCSIreq->io_Command = HD_SCSICMD;
    DoIO(SCSIreq);
```
The SCSICmd structure must be filled in prior to passing it to the SCSI
unit.  How it is filled in depends on the SCSI-direct being passed to the
unit.  Below is an example of setting up a SCSICmd structure for the
MODE_SENSE SCSI-direct command.

   UBYTE *buffer;           /* a data buffer used for mode sense data */
   UBYTE  Sense[20];        /* buffer for request sense data */
   struct SCSICmd Cmd;      /* where the actual SCSI command goes */

   /* the command being sent */

   static UBYTE ModeSense[]={ 0x1a,0,0xff,0,254,0 };

   Cmd.scsi_Data = (UWORD *)buffer;     /* where we put mode sense data */
   Cmd.scsi_Length = 254;               /* how much we will accept      */
   Cmd.scsi_CmdLength = 6;              /* length of the command        */
   Cmd.scsi_Flags = SCSIF_AUTOSENSE |   /* do automatic REQUEST_SENSE   */
```c
                    SCSIF_READ;         /* set expected data direction  */
```
   Cmd.scsi_SenseData = (UBYTE *)Sense; /* where sense data will go     */
   Cmd.scsi_SenseLength = 18;           /* how much we will accept      */
   Cmd.scsi_SenseActual = 0;            /* how much has been received   */

   Cmd.scsi_Command=(UBYTE *)ModeSense; /* issuing a MODE_SENSE command */

The fields of the SCSICmd are:

scsi_data
   This field points to the data buffer for the SCSI data phase (if any is
   expected).It is generally the job of the driver software to ensure that
   the given buffer is DMA-accessible and to drop to programmed I/O if it
   isn't.  The filing system provides a stop-gap fix for non-conforming
   drivers with the AddressMask parameter in DEVS:mountlist. For absolute
   safety, restrict all direct reads and writes to Chip RAM.

scsi_Length
   This is the expected length of data to be transferred.  If an unknown
   amount of data is to be transferred from target to host, set the
   scsi_Length to be larger than the maximum amount of data expected. Some
   controllers explicitly use scsi_Length as the amount of data to
   transfer. The A2091, A590 and A3000 drivers always do programmed I/O
   for data transfers under 256 bytes or when the DMA chip doesn't support
   the required alignment.

scsi_Actual
   How much data was actually received from or sent to the SCSI unit in
   response to the SCSI-direct command.

scsi_Command
   The SCSI-direct command.

scsi_CmdLength
   The length of the SCSI-direct command in bytes.

scsi_CmdActual
   The actual number of bytes of the SCSI-direct command that were
   transferred to the SCSI unit.

scsi_Flags
   These flags contain the intended data direction for the SCSI command. It
   is not strictly necessary to set the data direction flag since the SCSI
   protocol will inform the driver which direction data transfers will be
   going.  However, some controllers use this information to set up DMA
   before issuing the command .  It can also be used as a sanity check in
   case the data phase goes the wrong way.

   One flag in particular, is worth noting.  SCSIF_AUTOSENSE is used to
   make the driver perform an automatic REQUEST SENSE if the target returns
   CHECK CONDITION for a SCSI command.  The reason for having the driver do
   this is the multitasking nature of the Amiga.If two tasks were accessing
   the same drive and the first received a CHECK CONDITION, the second task
   would destroy the sense information when it sent a command.
   SCSIF_AUTOSENSE prevents the caller from having to make two I/O requests
   and removes this window of vulnerability.

scsi_Status
   The status of the SCSI-direct command. The values returned in this field
   can be found in the SCSI specification.  For example, 2 is
   CHECK_CONDITION.

scsi_SenseActual
   If the SCSIF_AUTOSENSE flag is set, it is important to initialize this
   field to zero before issuing a SCSI command because some drivers don't
   support AUTOSENSE and won't initialize the field.

scsi_SenseData
   This field is used only for SCSIF_AUTOSENSE.  If a REQUEST SENSE command
   is directly sent to the driver, the data will be deposited in the buffer
   pointed to by scsi_Data.

Keep in mind that SCSI-direct is geared toward an initiator role so it
can't be expected to perform target-like operations.  You can only send
commands to a device, not receive them from an initiator.  There is no
provision for SCSI messaging, either.  This is due mainly to the
interactive nature of the extended messages (such as synchronous transfer
requests) which have to be handled by the driver because it knows the
limitations of the controller card and has to be made aware of such
protocol changes.


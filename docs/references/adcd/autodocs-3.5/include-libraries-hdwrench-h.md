---
title: include/libraries/hdwrench.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-libraries-hdwrench-h
functions: []
libraries: []
---

# include/libraries/hdwrench.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef LIBRARIES_HDWRENCH_H
#define LIBRARIES_HDWRENCH_H

/*
**	$VER: hdwrench.h 44.3 (29.7.1999)
**	Includes Release 44.1
**
**	Disk Prep Support Library API includes
**
**	(C) Copyright 1999 Joanne B. Dow, Wizardess Designs,
**	    for license to Amiga, Inc.
**
**	    All Rights Reserved
*/

/*****************************************************************************/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef DEVICES_HARDBLOCKS_H
#include <devices/hardblocks.h>
#endif

/*****************************************************************************/

struct HDWLibrary
{
```c
        struct Library       ml_Lib;
        ULONG                ml_SegList;
        ULONG                ml_Flags;
        APTR                 ml_ExecBase; /* pointer to exec base  */
        long                *ml_relocs;   /* pointer to relocs.    */
        struct HDWLibrary   *ml_origbase; /* pointer to original library base  */
        long                 ml_numjmps;
```
};

#define  HDWBaseName    "hdwrench.library"

/* === General Constant Defines === */

/* Artificial unassigned value for the RDB structures. */
#define UNASSIGNED  (ULONG) -131L

/* End block number link within RDB structures */
#define RDBEND      (ULONG) -1L

#define DEFAULT_RDBBLOCKSHI 63

/* === Structure & Typedefs === */

typedef struct
{
```c
    USHORT  ready [ 16 ];   /* Tests ready and first block read */
    USHORT  there [ 16 ];   /* Tests as "there" but fails other tests */
```
} ValidIDstruct;


/* Actual disk read write return structure: */
struct rw_return                /* Should fit within a ULONG */
{
```c
    USHORT  success;            /* Error code */
    USHORT  failed_word;        /* 0 on reads. */
    USHORT  block_written;      /* 0 on reads. */
```
};

enum rw_success_val             /* Return values for rw_return.success field. */
{
```c
    success = 0,                /* 0 */
    success_on_retry_write,     /* 1 */
    success_on_retry_read,      /* 2 */
    failed_on_write,            /* 3 */
    failed_on_reread,           /* 4 */
    illegal_command,            /* 5 */
    io_command_failure,         /* 6 */
    scsi_command_failure,       /* 7 */
    out_of_memory,              /* 8 */
    no_more_disk_blocks,        /* 9 */
    rdsk_not_located,           /* 10 */
    io_device_not_open,         /* 11 */
    invalid_blocksize_found,    /* 12 */
    no_callback_hook,           /* 13 */
    user_aborted,               /* 14 */
    operation_not_permitted     /* 15 */
```
};

/* Internal bootblock structure. Create dummy structures to pass to read
 * and write functions as necessary. Be sure that bb_BlockNum is filled in
 * and that the actual size of the data area pointed to by the union is
 * sufficiently large to contain one disk block.
 */
typedef struct bootblock
{
```c
    struct MinNode   bb_Node;
    LONG             allocsize;
    LONG             bb_BlockNum;
    WORD             bb_Changed;
    LONG             unit;              /* Unit number for THIS set of RDBs. */
    char             DeviceName [32];   /* Device name */
    struct rw_return bb_RWErrors;
    BOOL             wflag;             /* Written out flag. */
    BYTE             spares[4-sizeof(BOOL)];/* Fill out short word */

    union
    {
        struct       RigidDiskBlock bd_RDB;
        struct       PartitionBlock bd_PB;
        struct       FileSysHeaderBlock bd_FHB;
        struct       LoadSegBlock bd_LSB;
        struct       BadBlockBlock bd_BB;
        UBYTE        bd_Bytes[512];     /* NB: This is the MINIMUM size we */
        UWORD        bd_Words[256];     /* can have here. It MAY be extended */
        ULONG        bd_Longs[128];     /* if actual block size is larger. */
    } bb_Data;
```
} BootBlock;

/*  ==== Error report values for other functions ==== */
#define E_NOERROR           0

#define E_ILLEGAL_SLASH     200
#define E_EOF_IN_COMMENT    201
#define E_ILLEGAL_STAR      202
#define E_TOKEN_TO_LONG     203
#define E_MEMORY_PANIC      204
#define E_PREMATURE_EOF     205
#define E_MISSING_EQUALS    206
#define E_ILLEGAL_T_F       207
#define E_ILLEGAL_TOKEN     208
#define E_DUPLICATE_DISK    209
#define E_NOT_LEGAL_NAME    210
#define E_EXCEEDED_SIZE_LIM 211
#define E_FILE_WRITE_ERROR  212
#define E_TOOMANY_FS        213
#define E_FSAVE_CONFUSION   214
#define E_FS_CANNOT_OPEN    215
#define E_LOST_IN_RDB_SPACE 216
#define E_FS_WRITE_ERROR    217
#define E_MULTIPLE_RDSKS    218
#define E_RDSK_NOT_1ST      219
#define E_NO_RDBS_LOADED    220
#define E_RDBS_ALREADY_IN   221     /* RDBs already loaded. */
#define E_FAILED_FILEOPEN   222
#define E_FILE_READ_FAILED  223
#define E_FILE_NOT_RDBS     224
#define E_NO_BLOCKSIZE_SPEC 225
#define E_FILE_WRITE_FAILED 226
#define E_MEMORYP_NULL      227     /* prospective "memp" is null */
#define E_ILLEGAL_BLOCKSIZE 228
#define E_INSUFFICIENT_MEM  229
#define E_RENUMBER_FAILED   230
#define E_BLOCKS_EXCEEDED   231     /* Too many RDB blocks */
#define E_INCOMPLETE_FSDESC 232
#define E_FS_NOT_FOUND      233
#define E_LIST_SCREWEDUP    234
#define E_NO_SUCH_DIR       235
#define E_EXALL_ERROR       236
#define E_UNIT_DIFFERS      237

#define T_RENUMBER_LEFT     300

#define W_DUPLICATE_FS      100
#define W_FS_NO_WRITE       101

/* Definitions for type field in FileSave */
#define DRIVEINIT   0
#define FILESYSTEM  1

struct DefaultsArray
{
```c
    ULONG   TotalBlocks;
    UWORD   BytesPerBlock;
    UWORD   BlocksPerSurface;
    UWORD   Surfaces;
    UWORD   Cylinders;          /* note: MaxCyl = Cylinders - 1; */
    UWORD   UnusedBlocks;
```
};

/* Defaults Array filling error bit array */
#define DA_NOERRORS             0
#define DA_NO_CAPACITY_REPORT   1
#define DA_NO_OPTIMIZE          2
#define DA_BAD_MODESENSE_4      4
#define DA_BAD_MODESENSE_3      8
#define DA_FAILED               256
#define DA_NO_DRIVE_OPEN        DA_FAILED
#define DA_RIDICULOUS_VALUES    ( DA_FAILED << 1 )

/* Defaults Array filling "Optimize" Flags */
#define DA_OPTIMIZE             1   /* Optimize storage if possible */
#define DA_HUGE                 2   /* Allow partitioning huge disks */
#define DA_HF_WAY               4   /* Use the old HardFrame algorithm */
/* Note: DA_HF_WAY is forces DA_OPTIMIZE and DA_HUGE off. */
/*       DA_BAD_MODESENSE_3 and DA_BAD_MODESENSE_4 only happen with DA_HF_WAY */
/*       Errors below DA_FAILED are informational. */

/*  ==== Mountfile Recognized Strings ==== */
#ifdef DONT_EVER_COMPILE_ME /* This stuff is for reference only, thank you. */

#ifdef FORREAL
#define EXTERN
#else
#define EXTERN  extern
#endif

EXTERN const char   *_Tokens[]
#ifdef FORREAL
= {
```c
    "/",                    /*0 */
    "#",
    "=",
    "device",
    "surfaces",
    "blockspertrack",
    "reserved",
    "prealloc",
    "interleave",
    "lowcyl",
    "highcyl",              /* 10 */
    "buffers",
    "bufmemtype",
    "maxtransfer",
    "mask",
    "bootpri",
    "dostype",
    "unit",
    "flags",
    "stacksize",
    "priority",             /* 20 */
    "globvec",
    "filesystem",
    "mount",
    "heads",
    "bytesperblock",
    "disk",
    "rdblow",
    "rdbhi",
    "reselect",
    "hilun",                /* 30 */
    "hiid",
    "hidrive",
    "cylinders",
    "cylinderblocks",
    "mincyl",
    "maxcyl",
    "hicard",
    "blocksize",
    "bootable",
    "readonly",             /* 40 */
    "driveinit",
    "baud",
    "control",
    "bootblocks",
    "synch",
    "sectorsperblock",
    "\xff"
```
}
#endif
;

#define TSLASH          0
#define THACK           1
#define TEQUALS         2
#define TDEVICE         3
#define TSURFACES       4
#define TBLOCKSPERTRACK 5
#define TRESERVED       6
#define TPREALLOC       7
#define TINTERLEAVE     8
#define TLOWCYL         9
#define THICYL          10
#define TBUFFERS        11
#define TBUFMEMTYPE     12
#define TMAXTRANSFER    13
#define TMASK           14
#define TBOOTPRI        15
#define TDOSTYPE        16
#define TUNIT           17
#define TFLAGS          18
#define TSTACKSIZE      19
#define TPRIORITY       20
#define TGLOBVEC        21
#define TFILESYSTEM     22
#define TMOUNT          23
#define THEADS          24
#define TBYTESPERBLOCK  25
#define TDISK           26
#define TRDBLOW         27
#define TRDBHI          28
#define TRESELECT       29
#define THILUN          30
#define THIID           31
#define TLASTDRIVE      32
#define TCYLINDERS      33
#define TCYLINDERBLOCKS 34
#define TMINCYL         35
#define TMAXCYL         36
#define THICARD         37
#define TBLOCKSIZE      38
#define TBOOTABLE       39
#define TREADONLY       40
#define TDRIVEINIT      41
#define TBAUD           42
#define TCONTROL        43
#define TBOOTBLOCKS     44
#define TSYNCH          45
#define TSECSPERBLOCK   46

#define TokenCount      46
#define TNOMATCH        TokenCount + 1

#endif /* COMPILEME */



typedef struct
{
```c
    STRPTR  devicename;
    LONG    board;
    LONG    address;
    LONG    lun;
    STRPTR  messagestring;
    LONG    extra;
    LONG    param1;
    LONG    param2;
    LONG    param3;
```
} HDWCallbackMsg;

#define EXTRA_BEFORE_TEST       0
#define EXTRA_AFTER_TEST        1
#define EXTRA_BEFORE_FORMAT     2       /* with no way to stop once you start.*/
#define EXTRA_BEFORE_VERIFY     3       /* Setup the verify requester and
                                           return "go ahead" */
#define EXTRA_UPDATE_VERIFY     4       /* New string for requester - return
                                           any Abort received */
#define EXTRA_VERIFY_REASSIGN   5       /* New string - return "Yes" or "No" */
#define EXTRA_VERIFY_FINISHED   6       /* Notify user, accept OK, close */

#define INQBUFSIZE  36  /* Standard size of Inquiry buffer */

/****************************************************************************/

/*
 *	Callback messages for the hdwrench.library tester program.
 *	These strings are "suggested" English strings for use with
 *	the hdwrench.library callback hook.
 */

#ifdef USE_SUGGESTED_MESSAGES
    /* MESSAGE */                                   /* .extra usages */
char *callback_messages[] =
{
```c
    /* A) FINDVALID_SCANNING_STRING */              /* 0 and 1 */
    "Scanning: %s: %d%d%d",         /* from message: devicename, board, lun, addr */

    /* B) LONGTIME_NOABORT_WARNING */               /* 2 */
    "You are about to format LUN %d on\n"
    "drive %d attached to board %d\n\n"
    "***WARNING WARNING WARNING***\n"
    "It can take up to several hours\n"
    "to format a hard disk. And there\n"
    "is no safe way to abort.\n\n"
    "Are you VERY sure you want to do this?\n",
    /* C) LONGTIME_VERIFY_WARNING */                /* 3 */
    "LUN %d on drive %d on board %d\n"
    "            Note\n"
    "It can take up to several hours\n"
    "to verify a hard disk. However,\n"
    "you can abort during verify.\n\n"
    "No data will be changed on the\n"
    "drive.\n\n"
    "Do you wish to continue?\n",

    /* D) FORMAT_USER_ABORTED_STRING */             /* 6 */
    "User Aborted. Your drive is safe!\n",

    /* E) FORMAT_MOUNTED_DRIVE */                   /* 4 */
    "%s\nShould we format a mounted drive?\n",

    /* F) FORMAT_NOT_PERMITTED */                   /* 6 */
    "%s\nFormatting the system disk\nis not permitted. Aborting...\n",

    /* G) FORMAT_UNRECOGNIZED_STATUS */             /* 6 */
    "Unrecognized SCSI status byte 0x%2.2x returned.\n",

    /* H) FORMAT_RESERVATION_CONFLICT */            /* 6 */
    "Device is reserved by another initiator.\n",

    /* I) FORMAT_DRIVE_BUSY */                      /* 6 */
    "Drive is busy.\n",

    /* J) FORMAT_COMMAND_PROBLEM */                 /* 6 */
    "Unknown problem issuing SCSI Direct command!\n",

    /* K) FORMAT_SUCCESS_STRING */                  /* 6 */
    "Format completed with no errors.",

    /* L) FORMAT_FAILED_STRING */                   /* 6 maybe */
    "Format failed! Your drive may be dead.\n",

    /* M) VERIFY_USER_ABORTED_STRING */             /* 6 */
    "User Aborted.\n",

    /* N) VERIFY_READCAPACITY_FAILED */             /* 6 */
    "ReadCapacity failed! Verify impossible.\n",

    /* O) VERIFY_PROGRESS */                        /* 4 */
    "Verifying blocks %d to %d of %d.\r",

    /* P) VERIFY_REASSIGN_Q */                      /* 5 */
    "Block %d is bad.\n"
    "Reassign this bad block?",

    /* Q) VERIFY_COMPLETED_STRING */                /* 6 */
    "Verify completed:\n"
    "    %d errors,\n"
    "    %d successful reassignments,\n"
    "and %d failed reassignments\n",

    /* R) VERIFY_ERROR_UNKNOWN_LOC */               /* 4 */
    "Medium error at unknown location!\n"
    "You should back up the drive and low-level format\n",

    /* S) VERIFY_HARDWARE_ERROR */                  /* 4 */
    "Hardware error %ld!\n",

    /* T) VERIFY_RECOVERED_ERROR */                 /* 4 */
    "Recovered read error at block %ld\n",

    /* U) VERIFY_RECOVERED_UNKNOWN_LOC */           /* 4 */
    "Recovered error at unknown location!\n"
    "You should consider backing up the\n"
    "drive and reformatting\n",

    /* V) VERIFY_ILLEGAL_REQUEST */                 /* 4 */
    "Drive returned an Illegal Request Error (%ld)\n",

    /* W) VERIFY_UNKNOWN_ERROR */
    "Unknown error: sense key %ld (more)\n"
    "Device returned sense code %ld (more)\n"
    "Consult drive documentation\n",

    /* X) VERIFY_CONTINUE */                        /* 4 */
    "Continuing verify at block %d...\n",

    /* Y) VERIFY_SEEK_ERROR */                      /* 4 */
    "seek eror!\n",

    /* Z) VERIFY_MEDIUM_ERROR */                    /* 4 */
    "Medium error at unknown location!\n"
    "You should back up the drive and low-level format\n",

    /* [) VERIFY_ILLEGAL_COMMAND */                 /* 4 */
    "Illegal command!\n",

    /* \) VERIFY_ILLEGAL_ADDRESS */                 /* 4 */
    "Illegal address %ld!",

    /* ]) VERIFY_BAD_ARGUEMENT */                   /* 4 */
    "Bad command arguement!\n",

    /* ^) VERIFY_CARTRIDGE_CHANGED */               /* 4 */
    "Cartridge changed",

    /* _) VERIFY_ILLEGAL_LUN */                     /* 4 */
    "Invalid LUN addressed!",

    /* `) VERIFY_UNFORMATTED_DRIVE */               /* 4 */
    "Unformatted drive!",

    /* a) VERIFY_NONEXTENDED_SENSE */               /* 4 */
    "Non-extended sense error is 0x%x",

    /* b) VERIFY_NO_SCSI_ERROR_RETURNED */          /* 4 */
    "Device didn't return good sense data!",

    /* other */
    "Illegal callback message %x"                   /* any */
```
};

#define MIN_MESSAGE 'A'
#define MAX_MESSAGE 'b'

#endif /* USE_SUGGESTED_MESSAGES */

#endif	/* LIBRARIES_HDWRENCH_H */


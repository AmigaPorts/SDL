# AHI (Audio Hardware Interface) Reference

## Overview

AHI (Audio Hardware Interface) is the retargetable audio system for AmigaOS. It provides
a unified API over heterogeneous audio hardware: AGA Paula, sound cards (Toccata, Melody,
Prelude), and software mixing. AHI v4 or later is required for SDL2; v4 is the version
shipped with AmigaOS 3.9 and available as a free download for 3.1/3.5.

AHI has two usage models:

  1. Device interface (CMD_WRITE / CMD_READ) -- low-level I/O request model, suitable
     for streaming pre-mixed buffers. This is what the SDL2 audio backend uses.

  2. Library interface (AHI_AllocAudio / AHI_SetSound etc.) -- higher-level mixer
     interface with per-channel control and optional PlayerFunc callback. Useful for
     music players and games that need per-channel control.

For an SDL-style callback driver the device interface is simpler and maps better to
SDL_AudioDriverImpl. The library interface is documented for completeness.

AHI is distributed as "ahi.device" -- an Amiga device (not a library). The library
functions (AHI_AllocAudio etc.) are accessed via the device base, not via a separate
OpenLibrary call.

Version history relevant to SDL2:
  - V2: Added input gain, output volume, input/output selection
  - V4: Added CMD_WRITE/CMD_READ, AHI_PlayA(), 16-bit stereo (AHIST_S16S), NSCMD_DEVICEQUERY
  - V6: Added 32-bit sample types, AntiClick, updated preferences

## Headers

```c
#include <proto/ahi.h>        /* Inlines: requires AHIBase global */
#include <devices/ahi.h>      /* Structures, constants, error codes, tag names */
#include <clib/ahi_protos.h>  /* Plain C prototypes (use proto/ahi.h instead) */
```

For the device interface only:

```c
#include <exec/io.h>          /* struct IOStdReq, OpenDevice, CloseDevice */
#include <exec/memory.h>      /* AllocMem, FreeMem */
#include <proto/exec.h>       /* CreateMsgPort, DeleteMsgPort, CreateIORequest */
#include <devices/ahi.h>      /* struct AHIRequest, AHINAME, AHIST_*, etc. */
```

## Library Base

AHI uses a device, not a library. The library functions (AHI_AllocAudio etc.) are
reached by setting AHIBase to the device base returned by OpenDevice:

```c
struct Library    *AHIBase = NULL;
struct MsgPort    *AHImp   = NULL;
struct AHIRequest *AHIio   = NULL;

static BOOL ahi_open_device(void)
{
    AHImp = CreateMsgPort();
    if (!AHImp) return FALSE;

    AHIio = (struct AHIRequest *)CreateIORequest(AHImp,
                                                  sizeof(struct AHIRequest));
    if (!AHIio) {
        DeleteMsgPort(AHImp);
        AHImp = NULL;
        return FALSE;
    }

    AHIio->ahir_Version = 4;   /* Require V4 minimum */

    if (OpenDevice(AHINAME, AHI_DEFAULT_UNIT,
                   (struct IORequest *)AHIio, 0L) != 0) {
        DeleteIORequest((struct IORequest *)AHIio);
        AHIio = NULL;
        DeleteMsgPort(AHImp);
        AHImp = NULL;
        return FALSE;
    }

    /* Now AHIBase is valid for library-interface calls */
    AHIBase = (struct Library *)AHIio->ahir_Std.io_Device;
    return TRUE;
}

static void ahi_close_device(void)
{
    if (AHIio) {
        CloseDevice((struct IORequest *)AHIio);
        DeleteIORequest((struct IORequest *)AHIio);
        AHIio   = NULL;
        AHIBase = NULL;
    }
    if (AHImp) {
        DeleteMsgPort(AHImp);
        AHImp = NULL;
    }
}
```

Note: AHINAME is defined in <devices/ahi.h> as "ahi.device".

Note: AHI_DEFAULT_UNIT (0) uses the user's preferred audio hardware as set in
AHI Preferences. AHI_NO_UNIT (255) must be used when using the library interface
(AHI_AllocAudio etc.) without the device interface.

## Structures

### struct AHIRequest

```c
struct AHIRequest {
    struct IOStdReq  ahir_Std;        /* Standard IO: io_Device, io_Unit,
                                         io_Command, io_Data, io_Length,
                                         io_Actual, io_Error, io_Offset */
    UWORD            ahir_Version;    /* Set before OpenDevice(); min version req */
    UWORD            ahir_Pad1;
    ULONG            ahir_Private[2]; /* Internal -- do not touch */
    ULONG            ahir_Type;       /* Sample format: AHIST_M16S etc. */
    ULONG            ahir_Frequency;  /* Playback/record frequency in Hz */
    Fixed            ahir_Volume;     /* 0 (mute) to 0x10000 (full) */
    Fixed            ahir_Position;   /* 0 = far left, 0x8000 = center,
                                         0x10000 = far right */
    struct AHIRequest *ahir_Link;     /* For double-buffering: pointer to the
                                         previous request, or NULL */
};
```

### struct AHIAudioCtrl

```c
struct AHIAudioCtrl {
    APTR  ahiac_UserData;   /* Your private data pointer (set via AHIA_UserData) */
    /* All other fields are private */
};
```

### struct AHISampleInfo

```c
struct AHISampleInfo {
    ULONG  ahisi_Type;      /* Sample format: AHIST_M8S, AHIST_M16S, etc. */
    APTR   ahisi_Address;   /* Pointer to sample data in MEMF_PUBLIC memory */
    ULONG  ahisi_Length;    /* Number of sample FRAMES (not bytes) */
};
```

Frame size depends on format:
  - AHIST_M8S:  1 byte per frame
  - AHIST_M16S: 2 bytes per frame
  - AHIST_S8S:  2 bytes per frame (L+R)
  - AHIST_S16S: 4 bytes per frame (L+R)

### struct AHIRecordMessage

```c
struct AHIRecordMessage {
    ULONG  ahirm_Type;    /* Currently always AHIST_S16S -- CHECK THIS */
    APTR   ahirm_Buffer;  /* Pointer to recorded samples (valid until next call) */
    ULONG  ahirm_Length;  /* Number of sample FRAMES in buffer */
};
```

### struct AHISoundMessage

```c
struct AHISoundMessage {
    UWORD  ahism_Channel;  /* Channel number that triggered SoundFunc */
};
```

## Constants

### Device Name and Units

```c
#define AHINAME             "ahi.device"
#define AHI_DEFAULT_UNIT    0U    /* User's preferred hardware */
#define AHI_NO_UNIT         255U  /* For library interface without device I/O */
```

### Special IDs and Values

```c
#define AHI_INVALID_ID      (~0UL)   /* Invalid/not found audio mode */
#define AHI_DEFAULT_ID      0UL      /* User's preferred mode (AllocAudio only) */
#define AHI_LOOPBACK_ID     1UL      /* Loopback mode (renders to sample buffer) */
#define AHI_DEFAULT_FREQ    0UL      /* User's preferred frequency (AllocAudio only) */
#define AHI_MIXFREQ         (~0UL)   /* Use mixing frequency for SetFreq() */
#define AHI_NOSOUND         0xffffU  /* Turn a channel off */
```

### Sample Formats (AHIST_*)

These constants specify the format of PCM sample data. All sample data on 68k is
big-endian (native 68k byte order -- no byte swapping needed when generating samples
in C on 68k).

```c
#define AHIST_M8S    0UL   /* Mono,   8-bit signed  (BYTE)       */
#define AHIST_M16S   1UL   /* Mono,  16-bit signed  (WORD)       */
#define AHIST_S8S    2UL   /* Stereo, 8-bit signed  (BYTE L, BYTE R) V4+ */
#define AHIST_S16S   3UL   /* Stereo,16-bit signed  (WORD L, WORD R) V4+ */
#define AHIST_M32S   8UL   /* Mono,  32-bit signed  (LONG)       V6+ */
#define AHIST_S32S   10UL  /* Stereo,32-bit signed  (LONG L, LONG R) V6+ */
```

AHIST_M8U (unsigned 8-bit mono) exists but is marked OBSOLETE. Do not use it.

For SDL2 the primary format is AHIST_S16S (stereo 16-bit) at 44100 Hz.

### Sound Types for AHI_LoadSound()

```c
#define AHIST_SAMPLE         0UL   /* Static sample -- fixed buffer, not modified
                                      while loaded; driver may upload to card RAM */
#define AHIST_DYNAMICSAMPLE  1UL   /* Dynamic sample -- buffer may be updated
                                      between AHI_SetSound() calls; higher CPU cost
                                      on DSP cards, required for streaming audio */
```

### SetVol/SetFreq/SetSound Flags

```c
#define AHISF_NONE    0UL          /* No flags (V6 name for 0) */
#define AHISF_IMM     (1UL<<0)     /* Take effect immediately, not at next period */
#define AHISF_NODELAY (1UL<<1)     /* Don't wait for zero-crossing before applying */
```

### Error Codes

```c
#define AHIE_OK           0UL   /* No error */
#define AHIE_NOMEM        1UL   /* Out of memory */
#define AHIE_BADSOUNDTYPE 2UL   /* Unknown sound type (AHIST_*) */
#define AHIE_BADSAMPLETYPE 3UL  /* Unknown or unsupported sample format */
#define AHIE_ABORTED      4UL   /* User-triggered abort */
#define AHIE_UNKNOWN      5UL   /* Unknown error */
#define AHIE_HALFDUPLEX   6UL   /* CMD_WRITE/CMD_READ clash on half-duplex hardware */
```

## Device Interface Functions

The device interface sends IO requests to ahi.device via SendIO()/WaitIO(). It does
NOT require AHIBase or the AHI_AllocAudio library interface. It uses a single MsgPort
shared between two AHIRequest structures for double-buffering.

### CMD_WRITE

Play samples from a buffer.

**IO Request Fields:**

| Field           | Value                                    |
|-----------------|------------------------------------------|
| io_Command      | CMD_WRITE                                |
| io_Data         | Pointer to sample buffer                 |
| io_Length       | Buffer size in bytes (multiple of frame) |
| io_Offset       | Must be 0                                |
| ahir_Type       | AHIST_S16S (or other format)             |
| ahir_Frequency  | Playback frequency in Hz (e.g. 44100)    |
| ahir_Volume     | 0x10000 for full volume                  |
| ahir_Position   | 0x8000 for center                        |
| ahir_Link       | Pointer to previous request (double-buf) |

**Returns:** io_Error = 0 on success; io_Actual = bytes played.

### CMD_READ

Record samples into a buffer.

**IO Request Fields:**

| Field           | Value                                       |
|-----------------|---------------------------------------------|
| io_Command      | CMD_READ                                    |
| io_Data         | Pointer to destination buffer               |
| io_Length       | Buffer size in bytes (multiple of frame)    |
| io_Offset       | 0 on first call; use returned value after   |
| ahir_Type       | Desired record format (signed types only)   |
| ahir_Frequency  | Desired record frequency in Hz              |

**Returns:** io_Error = 0 on success; io_Actual = bytes recorded; io_Offset updated.

## Library Interface Functions

### AHI_AllocAudioA / AHI_AllocAudio

**Synopsis:** `struct AHIAudioCtrl *AHI_AllocAudioA(struct TagItem *tags)`

**Register:** A1 = tags; returns D0

**Description:** Allocates and initializes the audio hardware and selects the optimal
mixing routine. Playback does not start until AHI_ControlAudioA() with AHIC_Play=TRUE.

**Tags:**

| Tag                  | Type          | Description                              |
|----------------------|---------------|------------------------------------------|
| AHIA_AudioID         | ULONG         | Audio mode ID; AHI_DEFAULT_ID for user pref |
| AHIA_MixFreq         | ULONG         | Desired mixing frequency; AHI_DEFAULT_FREQ for user pref |
| AHIA_Channels        | UWORD         | Number of channels (REQUIRED)            |
| AHIA_Sounds          | UWORD         | Number of sound IDs to allocate (REQUIRED) |
| AHIA_PlayerFunc      | struct Hook * | Callback called at AHIA_PlayerFreq rate  |
| AHIA_PlayerFreq      | Fixed         | PlayerFunc call rate in Hz (Fixed = Hz<<16); REQUIRED if PlayerFunc set |
| AHIA_MinPlayerFreq   | Fixed         | Minimum PlayerFreq you will use; REQUIRED if PlayerFunc set |
| AHIA_MaxPlayerFreq   | Fixed         | Maximum PlayerFreq you will use; REQUIRED if PlayerFunc set |
| AHIA_SoundFunc       | struct Hook * | Called when a sound starts (interrupt context) |
| AHIA_RecordFunc      | struct Hook * | Called with recorded samples (interrupt context) |
| AHIA_UserData        | APTR          | Stored in ahiac_UserData; retrieve from AudioCtrl |
| AHIA_AntiClickSamples| ULONG         | Samples to smooth on volume/sound change (V6) |

**Returns:** Pointer to AHIAudioCtrl, or NULL on failure.

**Notes:**
- AHIA_Channels and AHIA_Sounds are mandatory. Missing either causes failure.
- AHIA_PlayerFreq uses Fixed type (16.16 fixed point). 50 Hz = (50 << 16).
  Values below 0x10000 are treated as integers for compatibility (see BUGS).
  Always use Fixed: 44 Hz = 0x002C0000, 50 Hz = 0x00320000.
- PlayerFunc result (MixFreq / PlayerFreq) must fit in a UWORD: keep PlayerFreq
  such that MixFreq/PlayerFreq <= 65535 and >= 80.
- For SDL2 audio: use 1 channel with AHIST_DYNAMICSAMPLE and a PlayerFunc that
  calls AHI_SetSound() with the next buffer.

**Example:**

```c
struct AHIAudioCtrl *audioctrl;

audioctrl = AHI_AllocAudio(
    AHIA_AudioID,       AHI_DEFAULT_ID,
    AHIA_MixFreq,       44100UL,
    AHIA_Channels,      1UL,
    AHIA_Sounds,        2UL,         /* 2 sounds for double-buffering */
    AHIA_PlayerFunc,    &player_hook,
    AHIA_PlayerFreq,    (Fixed)(44100UL << 16) / (ULONG)buffer_frames,
    AHIA_MinPlayerFreq, (Fixed)(44100UL << 16) / (ULONG)buffer_frames,
    AHIA_MaxPlayerFreq, (Fixed)(44100UL << 16) / (ULONG)buffer_frames,
    AHIA_UserData,      my_data,
    TAG_DONE);

if (!audioctrl) {
    /* allocation failed -- hardware busy or not enough memory */
}
```

---

### AHI_FreeAudio

**Synopsis:** `void AHI_FreeAudio(struct AHIAudioCtrl *audioctrl)`

**Register:** A2 = audioctrl

**Description:** Frees the AHIAudioCtrl and all resources allocated by
AHI_AllocAudioA(). Implicitly calls AHI_UnloadSound() for all loaded sounds.
Playback must be stopped first via AHI_ControlAudio(audioctrl, AHIC_Play, FALSE, TAG_DONE).

**Parameters:**
- audioctrl -- AHIAudioCtrl from AHI_AllocAudioA(). NULL is safe (no-op).

---

### AHI_ControlAudioA / AHI_ControlAudio

**Synopsis:** `ULONG AHI_ControlAudioA(struct AHIAudioCtrl *audioctrl, struct TagItem *tags)`

**Registers:** A2 = audioctrl, A1 = tags; returns D0

**Description:** Start/stop playback, query state, and dynamically update PlayerFunc
parameters. Can also be called from within a PlayerFunc to change PlayerFreq.

**Tags:**

| Tag                    | Type    | Description                                       |
|------------------------|---------|---------------------------------------------------|
| AHIC_Play              | BOOL    | TRUE = start playback+PlayerFunc; FALSE = stop    |
| AHIC_Record            | BOOL    | TRUE = start recording+RecordFunc; FALSE = stop   |
| AHIC_MonitorVolume     | Fixed   | Input monitor volume (see AHI_GetAudioAttrs range) |
| AHIC_MonitorVolume_Query | Fixed * | Get current monitor volume                      |
| AHIC_MixFreq_Query     | ULONG * | Get actual mixing frequency                       |
| AHIC_InputGain         | Fixed   | Input gain (V2+)                                  |
| AHIC_InputGain_Query   | Fixed * | Get input gain (V2+)                              |
| AHIC_OutputVolume      | Fixed   | Output volume (V2+)                               |
| AHIC_OutputVolume_Query| Fixed * | Get output volume (V2+)                           |
| AHIA_PlayerFunc        | struct Hook * | Update PlayerFunc (safe from interrupt)     |
| AHIA_PlayerFreq        | Fixed   | Update PlayerFreq (safe from interrupt)           |
| AHIA_SoundFunc         | struct Hook * | Update SoundFunc (safe from interrupt)      |
| AHIA_UserData          | APTR    | Update UserData (safe from interrupt)             |

**Returns:** AHIE_OK (0) on success, or an AHIE_* error code.

**Notes:**
- AHIC_Play and AHIC_Record MUST NOT be called from an interrupt or PlayerFunc.
  Call only from task/process context.
- AHIA_PlayerFreq may be changed from the PlayerFunc itself.
- After AHIC_Play(TRUE): PlayerFunc will be called at the specified rate.
  AHI_SetVol/SetFreq/SetSound are safe to call from PlayerFunc.

**Example:**

```c
/* Start playback */
ULONG err = AHI_ControlAudio(audioctrl,
    AHIC_Play, TRUE,
    TAG_DONE);
if (err != AHIE_OK) { /* handle error */ }

/* Stop playback */
AHI_ControlAudio(audioctrl,
    AHIC_Play, FALSE,
    TAG_DONE);
```

---

### AHI_LoadSound

**Synopsis:** `ULONG AHI_LoadSound(UWORD sound, ULONG type, APTR info, struct AHIAudioCtrl *audioctrl)`

**Registers:** D0:16 = sound, D1 = type, A0 = info, A2 = audioctrl; returns D0

**Description:** Registers a sound buffer for use with AHI_SetSound(). The sound
parameter is a slot number from 0 to (AHIA_Sounds - 1).

**Parameters:**
- sound -- Slot number (0 to AHIA_Sounds-1)
- type  -- AHIST_SAMPLE or AHIST_DYNAMICSAMPLE
- info  -- Pointer to struct AHISampleInfo
- audioctrl -- From AHI_AllocAudioA()

**Returns:** AHIE_OK on success, or AHIE_BADSAMPLETYPE / AHIE_NOMEM.

**Notes:**
- AHIST_SAMPLE: Buffer must NOT be modified while the sound is loaded. Some
  hardware drivers may upload to card RAM. Allocate with MEMF_PUBLIC.
- AHIST_DYNAMICSAMPLE: Buffer CAN be updated. Required for SDL-style streaming.
  Has higher CPU cost on DSP cards.
- Memory must be in MEMF_PUBLIC -- NOT swappable, NOT Chip RAM required
  (AHI handles any needed DMA transfers).

**Example:**

```c
struct AHISampleInfo si;
BYTE *buffer = AllocMem(buffer_bytes, MEMF_PUBLIC | MEMF_CLEAR);

si.ahisi_Type    = AHIST_S16S;
si.ahisi_Address = buffer;
si.ahisi_Length  = buffer_frames;  /* number of frames, not bytes */

ULONG err = AHI_LoadSound(0, AHIST_DYNAMICSAMPLE, &si, audioctrl);
```

---

### AHI_UnloadSound

**Synopsis:** `void AHI_UnloadSound(UWORD sound, struct AHIAudioCtrl *audioctrl)`

**Registers:** D0:16 = sound, A2 = audioctrl

**Description:** Frees resources associated with a loaded sound. Does not break a
Forbid() state. Called automatically for all sounds by AHI_FreeAudio().

---

### AHI_SetVol

**Synopsis:** `void AHI_SetVol(UWORD channel, Fixed volume, sposition pan, struct AHIAudioCtrl *audioctrl, ULONG flags)`

**Registers:** D0 = channel, D1 = volume, D2 = pan, A2 = audioctrl, D3 = flags

**Description:** Sets the volume and stereo pan position for a channel. Call only
from the PlayerFunc or SoundFunc for deterministic timing.

**Parameters:**
- channel  -- Channel number (0 to AHIA_Channels-1)
- volume   -- Fixed-point volume: 0x0 (mute) to 0x10000 (full). Fixed = LONG.
- pan      -- Stereo position: 0x0 (full left) to 0x10000 (full right),
              0x8000 is center
- audioctrl -- From AHI_AllocAudioA()
- flags    -- AHISF_IMM to apply immediately; 0 to apply at next period

**Notes:**
- The Fixed type is a 16.16 fixed-point LONG (same as typedef in <devices/ahi.h>).
  Full volume = 0x00010000L. Half volume = 0x00008000L.
- Panning is only effective if the audio mode supports it (AHIDB_Panning=TRUE).
  On modes without panning, even channels go left, odd channels go right.

---

### AHI_SetFreq

**Synopsis:** `void AHI_SetFreq(UWORD channel, ULONG freq, struct AHIAudioCtrl *audioctrl, ULONG flags)`

**Registers:** D0 = channel, D1 = freq, A2 = audioctrl, D2 = flags

**Description:** Sets the playback frequency for a channel.

**Parameters:**
- channel  -- Channel number
- freq     -- Frequency in Hz, or AHI_MIXFREQ to use the mixing frequency
- audioctrl -- From AHI_AllocAudioA()
- flags    -- AHISF_IMM or 0

---

### AHI_SetSound

**Synopsis:** `void AHI_SetSound(UWORD channel, UWORD sound, ULONG offset, LONG length, struct AHIAudioCtrl *audioctrl, ULONG flags)`

**Registers:** D0 = channel, D1 = sound, D2 = offset, D3 = length, A2 = audioctrl, D4 = flags

**Description:** Triggers playback of a loaded sound on a channel, optionally at
a specific offset and length.

**Parameters:**
- channel  -- Channel number
- sound    -- Sound slot (from AHI_LoadSound()) or AHI_NOSOUND to silence channel
- offset   -- Start offset in sample frames (0 = beginning)
- length   -- Number of frames to play (0 = entire sound)
- audioctrl -- From AHI_AllocAudioA()
- flags    -- AHISF_IMM or 0

**Notes:**
- Calling AHI_SetSound with the current sound playing starts the sound over.
- For double-buffering: while sound slot 0 plays, fill slot 1; then switch.
  Use AHIA_SoundFunc to be notified when sound starts (to know when to switch).

---

### AHI_BestAudioIDA / AHI_BestAudioID

**Synopsis:** `ULONG AHI_BestAudioIDA(struct TagItem *tags)`

**Register:** A1 = tags; returns D0

**Description:** Searches the audio mode database for the mode that best matches
the requested capabilities.

**Tags (selection criteria):**

| Tag              | Type  | Description                              |
|------------------|-------|------------------------------------------|
| AHIDB_Volume     | BOOL  | TRUE: must support volume changes        |
| AHIDB_Stereo     | BOOL  | TRUE: must have stereo output            |
| AHIDB_Panning    | BOOL  | TRUE: must support stereo panning        |
| AHIDB_HiFi       | BOOL  | TRUE: must use full-precision mixing     |
| AHIDB_Record     | BOOL  | TRUE: must support recording             |
| AHIDB_Realtime   | BOOL  | TRUE: must be realtime (not disk render) |
| AHIDB_FullDuplex | BOOL  | TRUE: must play and record simultaneously |
| AHIDB_Bits       | UBYTE | Must have >= this many output bits        |
| AHIDB_MaxChannels| UWORD | Must support >= this many channels       |
| AHIDB_MinMixFreq | ULONG | Min supported frequency must be <= this  |
| AHIDB_MaxMixFreq | ULONG | Max supported frequency must be >= this  |
| AHIB_Dizzy       | struct TagItem * | Secondary preference list (V4) |

**Returns:** Best matching AudioID, or AHI_INVALID_ID if none found.

**Example:**

```c
ULONG best_id = AHI_BestAudioID(
    AHIDB_Stereo,     TRUE,
    AHIDB_Realtime,   TRUE,
    AHIDB_Bits,       16,
    AHIDB_MaxMixFreq, 44100UL,
    TAG_DONE);

if (best_id == AHI_INVALID_ID) {
    /* Fall back to AHI_DEFAULT_ID */
    best_id = AHI_DEFAULT_ID;
}
```

---

### AHI_NextAudioID

**Synopsis:** `ULONG AHI_NextAudioID(ULONG last_id)`

**Register:** D0 = last_id; returns D0

**Description:** Iterate through all registered audio mode IDs.

**Parameters:**
- last_id -- Previous ID, or AHI_INVALID_ID to start iteration

**Returns:** Next AudioID, or AHI_INVALID_ID if no more modes.

**Example:**

```c
ULONG id = AHI_INVALID_ID;
while ((id = AHI_NextAudioID(id)) != AHI_INVALID_ID) {
    /* examine mode with AHI_GetAudioAttrsA() */
}
```

---

### AHI_GetAudioAttrsA / AHI_GetAudioAttrs

**Synopsis:** `BOOL AHI_GetAudioAttrsA(ULONG id, struct AHIAudioCtrl *audioctrl, struct TagItem *tags)`

**Registers:** D0 = id, A2 = audioctrl, A1 = tags; returns D0

**Description:** Query attributes of an audio mode. Use AHI_INVALID_ID with a
valid audioctrl pointer to query the currently allocated mode (recommended).

**Key Query Tags:**

| Tag               | ti_Data type | Description                    |
|-------------------|-------------|--------------------------------|
| AHIDB_Stereo      | ULONG *     | TRUE if stereo output          |
| AHIDB_Panning     | ULONG *     | TRUE if panning supported      |
| AHIDB_Volume      | ULONG *     | TRUE if volume changes supported |
| AHIDB_HiFi        | ULONG *     | TRUE if full-precision mixing  |
| AHIDB_Realtime    | ULONG *     | TRUE if realtime               |
| AHIDB_Bits        | ULONG *     | Output resolution in bits      |
| AHIDB_MaxChannels | ULONG *     | Maximum supported channels     |
| AHIDB_MinMixFreq  | ULONG *     | Minimum mixing frequency       |
| AHIDB_MaxMixFreq  | ULONG *     | Maximum mixing frequency       |
| AHIDB_Name        | STRPTR      | Human-readable mode name (needs AHIDB_BufferLen) |
| AHIDB_BufferLen   | ULONG       | Length of string buffer for name/author/etc. |

**Returns:** TRUE on success, FALSE if attributes unavailable.

---

### AHI_SampleFrameSize (V4+)

**Synopsis:** `ULONG AHI_SampleFrameSize(ULONG sampletype)`

**Register:** D0 = sampletype; returns D0

**Description:** Returns the number of bytes in one sample frame for the given format.

**Returns:** Bytes per frame, or 0 for invalid type.

| Format       | Bytes |
|--------------|-------|
| AHIST_M8S    | 1     |
| AHIST_M16S   | 2     |
| AHIST_S8S    | 2     |
| AHIST_S16S   | 4     |
| AHIST_M32S   | 4     |
| AHIST_S32S   | 8     |

---

## Sound Hook (PlayerFunc) -- Interrupt Context

### Hook Signature

The PlayerFunc hook follows the standard Amiga hook calling convention:

```c
/* A0 = (struct Hook *)hook
 * A2 = (struct AHIAudioCtrl *)audioctrl
 * A1 = undefined (do NOT assume any value)
 * Returns: nothing (but d0 must be preserved or set to 0)
 */
static ULONG player_func_code(
    register struct Hook        *hook    __asm("a0"),
    register struct AHIAudioCtrl *ctrl   __asm("a2"),
    register APTR               message  __asm("a1"))
{
    struct MyAudioData *data = (struct MyAudioData *)ctrl->ahiac_UserData;
    /* ... refill buffer and call AHI_SetSound() ... */
    return 0;
}

/* Hook structure must be in global or static storage */
static struct Hook player_hook = {
    {NULL, NULL},    /* MinNode for list linking */
    (HOOKFUNC)player_func_code,  /* h_Entry */
    NULL,            /* h_SubEntry */
    NULL             /* h_Data (optional) */
};
```

### Interrupt Restrictions

The PlayerFunc is called from an interrupt context. The following are FORBIDDEN:

- AllocMem() / FreeMem()
- OpenLibrary() / CloseLibrary()
- Any Wait() call
- Any DOS calls (Read, Write, Open, Close)
- Signal() -- use instead: do work in the PlayerFunc, then Signal() a task only
  if your code tests CheckIO() in a separate process

The following are SAFE:

- AHI_SetVol(), AHI_SetFreq(), AHI_SetSound()
- Reading/writing data in pre-allocated buffers
- Atomic flag reads/writes (UBYTE or ULONG aligned)
- Signal() to a pre-allocated task's signal bit

### Register Preservation

The PlayerFunc MUST preserve d2-d7 and a2-a6 (standard Amiga interrupt hook
convention). bebbo-gcc handles this with the __asm register parameters but you
must ensure your function does not corrupt scratch registers of the caller.

---

## Usage Patterns

### Pattern 1: Device Interface Double-Buffering (SDL-style Callback)

This is the recommended pattern for SDL2 audio backend. It uses CMD_WRITE with
two alternating AHIRequest structures linked via ahir_Link for gapless playback.

```c
#define AUDIO_BUFSIZE  2048   /* frames per buffer */
#define AUDIO_FORMAT   AHIST_S16S
#define AUDIO_FREQ     44100

struct {
    struct MsgPort    *port;
    struct AHIRequest *req[2];
    WORD              *buf[2];
    int                current;
    BOOL               playing;
} ahi;

/* Initialize: called once at device open */
static BOOL ahi_audio_init(void)
{
    int i;
    ULONG bufbytes = AUDIO_BUFSIZE * AHI_SampleFrameSize(AUDIO_FORMAT);

    ahi.port = CreateMsgPort();
    if (!ahi.port) return FALSE;

    ahi.req[0] = (struct AHIRequest *)
        CreateIORequest(ahi.port, sizeof(struct AHIRequest));
    if (!ahi.req[0]) goto fail;

    ahi.req[0]->ahir_Version = 4;
    if (OpenDevice(AHINAME, AHI_DEFAULT_UNIT,
                   (struct IORequest *)ahi.req[0], 0L) != 0)
        goto fail;

    /* Clone req[0] for req[1] -- share same MsgPort and device */
    ahi.req[1] = AllocMem(sizeof(struct AHIRequest), MEMF_PUBLIC | MEMF_CLEAR);
    if (!ahi.req[1]) goto fail;
    CopyMem(ahi.req[0], ahi.req[1], sizeof(struct AHIRequest));

    /* Allocate two audio buffers in public (non-chip, non-fast) memory */
    for (i = 0; i < 2; i++) {
        ahi.buf[i] = AllocMem(bufbytes, MEMF_PUBLIC | MEMF_CLEAR);
        if (!ahi.buf[i]) goto fail;
    }

    ahi.current = 0;
    ahi.playing = FALSE;
    return TRUE;

fail:
    ahi_audio_close();
    return FALSE;
}

/* Fill one buffer via SDL callback, then submit it */
static void ahi_audio_play(void *userdata, BYTE *stream, int len)
{
    struct AHIRequest *req = ahi.req[ahi.current];
    WORD *buf = ahi.buf[ahi.current];
    ULONG bufbytes = AUDIO_BUFSIZE * AHI_SampleFrameSize(AUDIO_FORMAT);

    /* Wait for previous use of this slot to complete */
    if (ahi.playing) {
        WaitIO((struct IORequest *)req);
    }

    /* Fill buffer with SDL callback audio */
    SDL_memcpy(buf, stream, len);

    /* Configure request */
    req->ahir_Std.io_Command  = CMD_WRITE;
    req->ahir_Std.io_Data     = buf;
    req->ahir_Std.io_Length   = bufbytes;
    req->ahir_Std.io_Offset   = 0;
    req->ahir_Type            = AUDIO_FORMAT;
    req->ahir_Frequency       = AUDIO_FREQ;
    req->ahir_Volume          = 0x10000L;   /* full volume */
    req->ahir_Position        = 0x8000L;    /* center */
    /* Link to previous request so playback is gapless */
    req->ahir_Link = ahi.playing ? ahi.req[ahi.current ^ 1] : NULL;

    SendIO((struct IORequest *)req);
    ahi.playing = TRUE;
    ahi.current ^= 1;   /* swap to other buffer */
}

/* Flush and close */
static void ahi_audio_close(void)
{
    int i;
    if (ahi.req[0] && ahi.playing) {
        AbortIO((struct IORequest *)ahi.req[0]);
        WaitIO ((struct IORequest *)ahi.req[0]);
    }
    if (ahi.req[1] && ahi.playing) {
        AbortIO((struct IORequest *)ahi.req[1]);
        WaitIO ((struct IORequest *)ahi.req[1]);
    }
    if (ahi.req[0] && ahi.req[0]->ahir_Std.io_Device) {
        CloseDevice((struct IORequest *)ahi.req[0]);
    }
    if (ahi.req[1]) {
        FreeMem(ahi.req[1], sizeof(struct AHIRequest));
        ahi.req[1] = NULL;
    }
    if (ahi.req[0]) {
        DeleteIORequest((struct IORequest *)ahi.req[0]);
        ahi.req[0] = NULL;
    }
    for (i = 0; i < 2; i++) {
        if (ahi.buf[i]) {
            FreeMem(ahi.buf[i], AUDIO_BUFSIZE *
                    AHI_SampleFrameSize(AUDIO_FORMAT));
            ahi.buf[i] = NULL;
        }
    }
    if (ahi.port) {
        DeleteMsgPort(ahi.port);
        ahi.port = NULL;
    }
    ahi.playing = FALSE;
}
```

### Pattern 2: Library Interface with PlayerFunc (Music Player Style)

Use this when you need per-channel control, or when the device interface is
unavailable (AHI_NO_UNIT mode for non-blocking operation).

```c
/* Global state -- must be static/global, not on stack */
static struct AHIAudioCtrl *s_audioctrl = NULL;
static UBYTE  *s_buf[2]   = {NULL, NULL};
static int     s_curbuf    = 0;
static ULONG   s_bufbytes  = 0;
static BOOL    s_ready[2]  = {FALSE, FALSE};

static struct Hook s_player_hook;

/* The PlayerFunc -- called at audio callback rate from interrupt */
static ULONG ASM player_func(
    register struct Hook         *hook  __asm("a0"),
    register struct AHIAudioCtrl *ctrl  __asm("a2"),
    register APTR                 msg   __asm("a1"))
{
    int next = s_curbuf ^ 1;

    if (s_ready[next]) {
        /* Switch AHI to the pre-filled next buffer */
        AHI_SetSound(0, next, 0, 0, ctrl, AHISF_NONE);
        s_ready[next] = FALSE;
        s_curbuf = next;
    }
    /* Signal the audio thread to fill the idle buffer */
    /* (use Signal() to a task here -- never AllocMem in interrupt) */
    return 0;
}

static BOOL library_audio_init(ULONG freq, ULONG frames)
{
    int i;
    ULONG player_hz;
    struct AHISampleInfo si;

    s_bufbytes = frames * AHI_SampleFrameSize(AHIST_S16S);
    player_hz  = freq / frames;   /* callback rate in Hz */

    /* Open device to get AHIBase, then use library interface */
    if (!ahi_open_device()) return FALSE;   /* see "Library Base" above */

    for (i = 0; i < 2; i++) {
        s_buf[i] = AllocMem(s_bufbytes, MEMF_PUBLIC | MEMF_CLEAR);
        if (!s_buf[i]) return FALSE;
    }

    /* Initialize hook */
    s_player_hook.h_Entry    = (HOOKFUNC)player_func;
    s_player_hook.h_SubEntry = NULL;
    s_player_hook.h_Data     = NULL;

    s_audioctrl = AHI_AllocAudio(
        AHIA_AudioID,       AHI_DEFAULT_ID,
        AHIA_MixFreq,       freq,
        AHIA_Channels,      1UL,
        AHIA_Sounds,        2UL,
        AHIA_PlayerFunc,    &s_player_hook,
        AHIA_PlayerFreq,    (Fixed)((ULONG)player_hz << 16),
        AHIA_MinPlayerFreq, (Fixed)((ULONG)player_hz << 16),
        AHIA_MaxPlayerFreq, (Fixed)((ULONG)player_hz << 16),
        TAG_DONE);

    if (!s_audioctrl) return FALSE;

    /* Register both sound slots */
    for (i = 0; i < 2; i++) {
        si.ahisi_Type    = AHIST_S16S;
        si.ahisi_Address = s_buf[i];
        si.ahisi_Length  = frames;
        if (AHI_LoadSound((UWORD)i, AHIST_DYNAMICSAMPLE, &si, s_audioctrl)
                != AHIE_OK)
            return FALSE;
    }

    /* Set volume and frequency for channel 0 */
    AHI_SetVol(0, 0x10000L, 0x8000L, s_audioctrl, AHISF_NONE);
    AHI_SetFreq(0, freq, s_audioctrl, AHISF_NONE);
    AHI_SetSound(0, 0, 0, 0, s_audioctrl, AHISF_NONE);
    s_curbuf = 0;

    /* Start playback */
    AHI_ControlAudio(s_audioctrl, AHIC_Play, TRUE, TAG_DONE);
    return TRUE;
}

static void library_audio_close(void)
{
    int i;
    if (s_audioctrl) {
        AHI_ControlAudio(s_audioctrl, AHIC_Play, FALSE, TAG_DONE);
        AHI_FreeAudio(s_audioctrl);
        s_audioctrl = NULL;
    }
    for (i = 0; i < 2; i++) {
        if (s_buf[i]) {
            FreeMem(s_buf[i], s_bufbytes);
            s_buf[i] = NULL;
        }
    }
    ahi_close_device();
}
```

### Pattern 3: Querying the Actual Mixing Frequency

The mixing frequency AHI selects may differ from what you requested. Always query
the actual frequency after AHI_AllocAudio() and AHI_ControlAudio():

```c
ULONG actual_freq = 0;
AHI_ControlAudio(s_audioctrl,
    AHIC_MixFreq_Query, &actual_freq,
    TAG_DONE);
/* Recompute PlayerFreq if needed based on actual_freq */
```

---

## SDL2 Audio Backend Integration Notes

### Mapping SDL_AudioDriverImpl callbacks to AHI

| SDL2 callback        | AHI operation                                   |
|----------------------|-------------------------------------------------|
| Init()               | OpenDevice(AHINAME), validate version >= 4      |
| DetectDevices()      | AHI_NextAudioID + AHI_GetAudioAttrs enumerate   |
| OpenDevice()         | CreateMsgPort/IORequest, AllocMem buffers        |
| PlayDevice()         | CMD_WRITE via SendIO with ahir_Link chaining    |
| WaitDevice()         | WaitIO on the inflight request                  |
| GetDeviceBuf()       | Return the idle buffer (not the inflight one)   |
| CloseDevice()        | AbortIO, WaitIO, CloseDevice, free allocations  |
| Deinitialize()       | (nothing; device already closed above)          |

### Format Selection

SDL2 may request formats AHI does not support. Map as follows:

| SDL format     | AHI type     | Notes                                  |
|----------------|--------------|----------------------------------------|
| AUDIO_S16MSB   | AHIST_S16S   | Native 68k big-endian -- exact match   |
| AUDIO_S16LSB   | AHIST_S16S   | Must byte-swap buffer before sending   |
| AUDIO_S8       | AHIST_S8S    | 8-bit stereo                           |
| AUDIO_U8       | (n/a)        | Convert to AHIST_M8S signed or S16S    |

Prefer AUDIO_S16MSB (big-endian 16-bit) as it maps directly to AHIST_S16S
without any byte-swapping on 68k.

### Buffer Size Guidance

Buffer sizes that work well on AHI:
- 512 frames at 44100 Hz = ~11.6 ms latency (good for games)
- 1024 frames at 44100 Hz = ~23.2 ms latency (safe default)
- 2048 frames at 44100 Hz = ~46.4 ms latency (very safe, use if glitches)

Smaller buffers increase CPU load from more frequent interrupts.
Larger buffers increase audio latency.

For PlayerFreq calculation: PlayerFreq (Hz) = MixFreq / BufferFrames.
Verify MixFreq / PlayerFreq fits in a UWORD (< 65535) and is > 80.

### Memory Allocation for Audio Buffers

Audio buffers must be allocated with MEMF_PUBLIC (not MEMF_CHIP, not MEMF_FAST
alone). AHI handles any required DMA transfers internally:

```c
buf = AllocMem(bufbytes, MEMF_PUBLIC | MEMF_CLEAR);
```

Do NOT use malloc() or SDL_malloc() for audio buffers passed to AHI -- these
may return addresses that AHI's DMA logic cannot access on some hardware.

---

## Related Crash Patterns

- crash-patterns.md #7: Stack overflow. Audio buffers declared as local arrays
  will blow the stack. Always allocate audio buffers with AllocMem.
- crash-patterns.md #10: Large local buffers. Same issue -- never declare
  WORD buf[BUFSIZE] on the stack in audio callback code.
- crash-patterns.md #15: Alignment. AHI sample data must be WORD-aligned
  (2-byte) for 16-bit formats. AllocMem guarantees this.
- crash-patterns.md #16: Struct-by-value returns at -O2. The AHISampleInfo
  struct is small (12 bytes) and passed by pointer -- no risk. But any
  audio processing code using structs should be compiled at -O0 initially.

---

## Version Notes

| Feature                        | Min Version |
|--------------------------------|-------------|
| Library interface (AllocAudio) | V2          |
| CMD_WRITE / CMD_READ           | V4          |
| Stereo sample types (AHIST_S8S, AHIST_S16S) | V4 |
| AHI_PlayA()                    | V4          |
| AHI_SampleFrameSize()          | V4          |
| NSCMD_DEVICEQUERY              | V4          |
| 32-bit sample types (M32S, S32S) | V6        |
| AHIA_AntiClickSamples          | V6          |

AHI V4 minimum is safe for all AmigaOS 3.x installations with AHI installed.
AmigaOS 3.9 shipped with AHI V5. AmigaOS 3.1/3.5 users must install AHI separately.

For the SDL2 audio backend, require V4:

```c
AHIio->ahir_Version = 4;   /* Minimum V4 for CMD_WRITE */
```

---

## Sources

- `/opt/m68k-amigaos/m68k-amigaos/include/devices/ahi.h` (toolchain, V6.0 header)
- `/opt/m68k-amigaos/m68k-amigaos/doc/ahi.doc` (toolchain autodoc)
- `/opt/m68k-amigaos/m68k-amigaos/include/clib/ahi_protos.h` (function prototypes)
- `/opt/m68k-amigaos/m68k-amigaos/include/inline/ahi.h` (register conventions)
- AmigaPorts/libSDL12 audio/amigaos/SDL_ahiaudio.c (device interface double-buffer pattern)
- AmigaPorts/SDL src/audio/amigaos4/SDL_os4audio.c (SDL2 OS4 audio backend reference)
- https://wiki.amigaos.net/wiki/AHI_Device

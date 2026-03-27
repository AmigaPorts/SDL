# SDL2 Audio Backend Contract

## Overview

This document describes what SDL2 expects from a platform audio backend driver,
with focus on what the AmigaOS 3.x AHI backend (Phase 3) must implement.

SDL2 audio uses a driver/impl architecture. The backend provides:
1. An AudioBootStrap struct for registration
2. An init function that fills SDL_AudioDriverImpl function pointers
3. A hidden private data struct (SDL_PrivateAudioData) per open device

The core SDL2 audio system creates a dedicated audio thread per open output
device. That thread calls GetDeviceBuf/PlayDevice/WaitDevice in a tight loop.
The backend does NOT call SDL2 -- SDL2 calls the backend.

Source files read to produce this document:
- src/audio/SDL_sysaudio.h
- src/audio/SDL_audio.c
- src/audio/dummy/SDL_dummyaudio.c
- src/audio/disk/SDL_diskaudio.c
- src/audio/amigaos3/SDL_os3audio.c

---

## 1. AudioBootStrap -- Registration

```c
/* src/audio/SDL_sysaudio.h */
typedef struct AudioBootStrap
{
    const char *name;                          /* short driver name, e.g. "ahi" */
    const char *desc;                          /* human readable, e.g. "AmigaOS AHI Audio" */
    SDL_bool (*init)(SDL_AudioDriverImpl *impl); /* fill impl, return SDL_TRUE on success */
    SDL_bool demand_only;                      /* SDL_TRUE = only used when explicitly requested */
} AudioBootStrap;
```

The bootstrap entry must be declared extern in SDL_sysaudio.h and added to the
static bootstrap[] array in SDL_audio.c, guarded by #ifdef SDL_AUDIO_DRIVER_AHI.
Our stub already does this -- see OS3AHI_bootstrap in src/audio/amigaos3/.

### How SDL2 walks the bootstrap array

During SDL_AudioInit():
- If no driver name is requested: iterates bootstrap[] in order, skipping
  demand_only entries, calls bootstrap[i]->init() until one returns SDL_TRUE.
- If a driver name is given: finds matching bootstrap[i]->name, calls init().

If init() returns SDL_FALSE, SDL2 tries the next driver in the list.
DISK and DUMMY backends are at the end of the list as fallbacks.

### demand_only flag

Set demand_only = SDL_FALSE for AHI. It is a real audio driver that should be
tried automatically.

Set demand_only = SDL_TRUE only for drivers that should never be auto-selected
(DISK and DUMMY use this).

---

## 2. SDL_AudioDriverImpl -- Function Pointers

The init function receives a pointer to SDL_AudioDriverImpl and must fill in
the function pointers it supports. SDL2 installs no-op stubs for any pointer
left NULL, so only supported functions need to be set.

```c
/* src/audio/SDL_sysaudio.h */
typedef struct SDL_AudioDriverImpl
{
    void  (*DetectDevices)(void);
    int   (*OpenDevice)(_THIS, const char *devname);
    void  (*ThreadInit)(_THIS);
    void  (*ThreadDeinit)(_THIS);
    void  (*WaitDevice)(_THIS);
    void  (*PlayDevice)(_THIS);
    Uint8 *(*GetDeviceBuf)(_THIS);
    int   (*CaptureFromDevice)(_THIS, void *buffer, int buflen);
    void  (*FlushCapture)(_THIS);
    void  (*CloseDevice)(_THIS);
    void  (*LockDevice)(_THIS);
    void  (*UnlockDevice)(_THIS);
    void  (*FreeDeviceHandle)(void *handle);
    void  (*Deinitialize)(void);
    int   (*GetDefaultAudioInfo)(char **name, SDL_AudioSpec *spec, int iscapture);

    SDL_bool ProvidesOwnCallbackThread;
    SDL_bool HasCaptureSupport;
    SDL_bool OnlyHasDefaultOutputDevice;
    SDL_bool OnlyHasDefaultCaptureDevice;
    SDL_bool AllowsArbitraryDeviceNames;
    SDL_bool SupportsNonPow2Samples;
} SDL_AudioDriverImpl;
```

The macro _THIS expands to SDL_AudioDevice *_this throughout the audio subsystem.

### 2.1 DetectDevices

```c
void (*DetectDevices)(void);
```

Called once during SDL_GetNumAudioDevices() or SDL_GetAudioDeviceName() to
enumerate available devices. The backend must call SDL_AddAudioDevice() once
per device found.

For AHI: call SDL_AddAudioDevice() for each AHI audio mode found, or simply
call it once for the default output if OnlyHasDefaultOutputDevice is set.

If OnlyHasDefaultOutputDevice is SDL_TRUE, DetectDevices is still called but
the result is not used for device enumeration -- the default device name is
used instead. In that case, DetectDevices can be left NULL or be a no-op.

The disk backend example:
```c
static void DISKAUDIO_DetectDevices(void)
{
    SDL_AddAudioDevice(SDL_FALSE, DEFAULT_OUTPUT_DEVNAME, NULL, (void *)0x1);
    SDL_AddAudioDevice(SDL_TRUE,  DEFAULT_INPUT_DEVNAME,  NULL, (void *)0x2);
}
```

SDL_AddAudioDevice signature:
```c
void SDL_AddAudioDevice(const SDL_bool iscapture,
                        const char *name,
                        SDL_AudioSpec *spec,  /* may be NULL */
                        void *handle);        /* opaque, must not be NULL */
```

The handle is an opaque pointer the backend assigns. SDL2 stores it in
SDL_AudioDeviceItem.handle and passes it back in _this->handle when
OpenDevice is called for that device. handle must NOT be NULL -- SDL2
asserts this. Use (void *)0x1 as a sentinel for backends with one device.

### 2.2 OpenDevice

```c
int (*OpenDevice)(_THIS, const char *devname);
```

Called when the application calls SDL_OpenAudioDevice(). At this point:
- _this->spec contains the negotiated audio specification (freq, format,
  channels, samples already adjusted by SDL2)
- _this->iscapture is SDL_TRUE for capture devices
- _this->handle is the handle value from SDL_AddAudioDevice()
- devname is the device name string (may be NULL for default device)

The backend must:
1. Open the actual hardware (e.g. OpenDevice("ahi.device", ...))
2. Configure hardware to match _this->spec where possible
3. Allocate a mix buffer of _this->spec.size bytes
4. Allocate and fill _this->hidden (the private data struct)

CRITICAL: _this->hidden must be non-NULL after OpenDevice returns 0.
SDL2 asserts this immediately after OpenDevice:
    SDL_assert(device->hidden != NULL);

Return 0 on success, -1 on failure (call SDL_SetError() with reason).

If hardware does not support the requested format, the backend may adjust
_this->spec fields (freq, format, channels, samples) before returning.
SDL2 will insert a converter/resampler stream if the adjusted spec differs
from what the application requested.

After OpenDevice returns, SDL_CalculateAudioSpec() is called on _this->spec
to recalculate spec.silence and spec.size from the (possibly adjusted) values.

### 2.3 ThreadInit and ThreadDeinit

```c
void (*ThreadInit)(_THIS);
void (*ThreadDeinit)(_THIS);
```

Called at the start and end of the SDL2 audio thread, running in the context
of that thread. Use for any per-thread initialization the audio hardware or
OS requires (e.g. thread priority adjustment, library base initialization if
the library requires per-task bases).

For AHI: may be needed if ahi.device must be opened per-task. On AmigaOS,
OpenDevice() called from the main task may require the device to be used
from the same task. If AHI device I/O must happen from the audio thread,
open ahi.device here, not in OpenDevice().

Both default to no-ops. Leave NULL if not needed.

### 2.4 GetDeviceBuf

```c
Uint8 *(*GetDeviceBuf)(_THIS);
```

Called from the SDL2 audio thread to obtain a buffer SDL2 will mix audio into.
Must return a pointer to a writable buffer of at least _this->spec.size bytes.
Returning NULL causes SDL2 to mix into its internal work_buffer instead (and
then not call PlayDevice for that iteration).

For double-buffering: return alternating buffer pointers so PlayDevice can
be submitting buffer N while SDL2 fills buffer N+1.

For AHI: return a pointer to a DMA-safe mix buffer. Typical pattern:

```c
static Uint8 *OS3AHI_GetDeviceBuf(_THIS)
{
    struct SDL_PrivateAudioData *h = _this->hidden;
    return h->mixbuf[h->current_buf];
}
```

### 2.5 PlayDevice

```c
void (*PlayDevice)(_THIS);
```

Called from the SDL2 audio thread immediately after SDL2 has filled the
buffer returned by GetDeviceBuf(). The backend must submit that buffer
to the hardware for playback.

For double-buffered DMA playback: queue the filled buffer to the hardware
and toggle the current_buf index so GetDeviceBuf returns the other buffer
next iteration.

For AHI: call AHI_SetSound() or write to the AHI IORequest to start playing
the filled buffer.

### 2.6 WaitDevice

```c
void (*WaitDevice)(_THIS);
```

Called from the SDL2 audio thread immediately after PlayDevice(). The backend
must block here until the hardware is ready to accept the next buffer. This
is the pacing mechanism -- it prevents the audio thread from running ahead
of the hardware.

For blocking I/O AHI: WaitIO() on the completed request.
For timed waits: SDL_Delay((spec.samples * 1000) / spec.freq).

The disk backend uses a fixed io_delay:
```c
static void DISKAUDIO_WaitDevice(_THIS)
{
    SDL_Delay(_this->hidden->io_delay);
}
```

The audio loop in SDL_RunAudio():
```c
current_audio.impl.PlayDevice(device);
current_audio.impl.WaitDevice(device);
```

WaitDevice must not return too early (causes audio distortion from buffer
re-fill before playback completes) or too late (causes audio dropout).

### 2.7 CloseDevice

```c
void (*CloseDevice)(_THIS);
```

Called when the application calls SDL_CloseAudioDevice() or on error.
By this point the audio thread has already been shut down (SDL_AtomicSet
shutdown=1 and the thread has exited).

The backend must:
1. Stop hardware playback
2. Close ahi.device (CloseDevice())
3. Free all buffers
4. Free _this->hidden

```c
static void OS3AHI_CloseDevice(_THIS)
{
    struct SDL_PrivateAudioData *h = _this->hidden;
    if (!h) return;
    /* stop AHI, close device, free buffers */
    SDL_free(h->mixbuf[0]);
    SDL_free(h->mixbuf[1]);
    SDL_free(h);
    _this->hidden = NULL;
}
```

### 2.8 Deinitialize

```c
void (*Deinitialize)(void);
```

Called when SDL_AudioQuit() runs. Global cleanup only -- not per-device.
Close any libraries opened in init (e.g. AHIBase if opened globally).
Leave NULL if no global cleanup needed.

### 2.9 LockDevice and UnlockDevice

```c
void (*LockDevice)(_THIS);
void (*UnlockDevice)(_THIS);
```

Called from SDL_LockAudioDevice() / SDL_UnlockAudioDevice(). Used to
serialize access between the audio callback thread and the application.

If these are left NULL, SDL2 uses its own SDL_mutex (device->mixer_lock)
for synchronization. This is correct for most backends including AHI.
Only override these if the backend has its own locking mechanism that
SDL2's mutex would conflict with.

### 2.10 FreeDeviceHandle

```c
void (*FreeDeviceHandle)(void *handle);
```

Called when SDL2 is done with a handle value previously passed to
SDL_AddAudioDevice(). If handles are heap-allocated strings, free them here.
For sentinel values like (void *)0x1, leave this NULL (no-op is the default).

### 2.11 CaptureFromDevice and FlushCapture

```c
int  (*CaptureFromDevice)(_THIS, void *buffer, int buflen);
void (*FlushCapture)(_THIS);
```

For audio capture (recording) only. AHI supports capture but Phase 3
only needs output. Set HasCaptureSupport = SDL_FALSE and leave these NULL.

CaptureFromDevice must fill buffer with buflen bytes of audio data.
It should block until data is available. Returns bytes written, or -1 on error.

FlushCapture discards any buffered capture data (called when paused).

---

## 3. SDL_AudioDevice -- The _this Struct

The audio thread and all impl callbacks receive _this, a pointer to the
SDL_AudioDevice for the currently open device.

```c
/* src/audio/SDL_sysaudio.h */
struct SDL_AudioDevice
{
    SDL_AudioDeviceID    id;           /* device ID (1-based) */
    SDL_AudioSpec        spec;         /* hardware spec (what backend runs at) */
    SDL_AudioSpec        callbackspec; /* app spec (before conversion) */
    SDL_AudioStream     *stream;       /* resampler/converter, or NULL if formats match */
    SDL_atomic_t         shutdown;     /* set to 1 to signal thread exit */
    SDL_atomic_t         enabled;      /* 0 if device failed/disconnected */
    SDL_atomic_t         paused;       /* 1 if paused */
    SDL_bool             iscapture;    /* SDL_TRUE for capture device */
    Uint8               *work_buffer;  /* SDL2-owned scratch buffer */
    Uint32               work_buffer_len;
    SDL_mutex           *mixer_lock;   /* protects callback */
    SDL_Thread          *thread;       /* the audio thread */
    SDL_threadID         threadid;
    SDL_DataQueue       *buffer_queue; /* for SDL_QueueAudio() path */
    struct SDL_PrivateAudioData *hidden; /* BACKEND PRIVATE DATA */
    void                *handle;       /* handle from SDL_AddAudioDevice() */
};
```

Key fields for the backend:

**spec** -- The hardware audio specification. The backend sets this in
OpenDevice() to reflect what the hardware actually runs at. SDL2 reads this
after OpenDevice() to decide whether a resampler/converter is needed.

Fields in SDL_AudioSpec:
```c
typedef struct SDL_AudioSpec
{
    int              freq;      /* samples per second (e.g. 44100) */
    SDL_AudioFormat  format;    /* AUDIO_S16SYS, AUDIO_U8, etc. */
    Uint8            channels;  /* 1=mono, 2=stereo */
    Uint8            silence;   /* silence value (calculated by SDL2) */
    Uint16           samples;   /* buffer size in sample frames */
    Uint16           padding;   /* unused */
    Uint32           size;      /* buffer size in bytes (calculated by SDL2) */
    SDL_AudioCallback callback; /* app callback (not used by backend) */
    void            *userdata;
} SDL_AudioSpec;
```

spec.size = (SDL_AUDIO_BITSIZE(format) / 8) * channels * samples
spec.silence = 0x00 for signed formats, 0x80 for AUDIO_U8

**hidden** -- Backend private data. Must be non-NULL after OpenDevice returns 0.
Cast to your SDL_PrivateAudioData struct. SDL2 never reads or writes this field.

**shutdown** -- Read with SDL_AtomicGet(&device->shutdown). When this is 1,
the audio thread loop should exit. Do not poll this in WaitDevice -- SDL2
checks it in the outer loop.

---

## 4. Audio Thread Model

SDL2 creates one OS thread per open output device (unless ProvidesOwnCallbackThread
is SDL_TRUE). The thread runs SDL_RunAudio() in src/audio/SDL_audio.c.

The loop structure (simplified from SDL_RunAudio):

```
ThreadInit(device)

while not shutdown:
    data = GetDeviceBuf(device)        /* get buffer to fill */
    if data == NULL:
        data = device->work_buffer     /* use scratch buffer */

    SDL_LockMutex(device->mixer_lock)
    if paused:
        memset(data, silence, callbackspec.size)
    else:
        callback(userdata, data, callbackspec.size)  /* app fills data */
    SDL_UnlockMutex(device->mixer_lock)

    if device->stream:                 /* format conversion needed */
        SDL_AudioStreamPut(stream, data, callbackspec.size)
        while stream has >= spec.size bytes:
            data = GetDeviceBuf(device)
            SDL_AudioStreamGet(stream, data, spec.size)
            PlayDevice(device)
            WaitDevice(device)
    else if data == work_buffer:
        SDL_Delay(samples * 1000 / freq)   /* device disabled, pace anyway */
    else:
        PlayDevice(device)             /* data is hardware buffer */
        WaitDevice(device)

ThreadDeinit(device)
```

Key points:
- The app callback receives data in callbackspec format (what the app requested)
- The backend receives data in spec format (what the hardware runs at)
- If these differ, SDL2 inserts an SDL_AudioStream to convert/resample
- GetDeviceBuf must return a buffer sized spec.size, not callbackspec.size
- WaitDevice paces the loop -- without it, the CPU will spin at 100%
- LockDevice/UnlockDevice (or mixer_lock) serialize callback vs SDL_LockAudioDevice

### ProvidesOwnCallbackThread

If ProvidesOwnCallbackThread = SDL_TRUE, SDL2 does NOT create an audio thread.
The backend is responsible for driving audio (e.g. using a hardware interrupt
or its own thread). The backend calls the application callback directly.

For AHI with interrupt-driven mixing: set this to SDL_TRUE and call the
app callback from within the AHI interrupt handler or a dedicated task.

For AHI with polling/WaitIO: set this to SDL_FALSE and use the standard
SDL2 audio thread with WaitDevice blocking on WaitIO().

---

## 5. SDL_AudioFormat -- Format Constants

```c
/* include/SDL_audio.h */
#define AUDIO_U8        0x0008  /* unsigned 8-bit */
#define AUDIO_S8        0x8008  /* signed 8-bit */
#define AUDIO_U16LSB    0x0010  /* unsigned 16-bit little-endian */
#define AUDIO_S16LSB    0x8010  /* signed 16-bit little-endian */
#define AUDIO_U16MSB    0x1010  /* unsigned 16-bit big-endian */
#define AUDIO_S16MSB    0x9010  /* signed 16-bit big-endian */
#define AUDIO_S32LSB    0x8020  /* signed 32-bit little-endian */
#define AUDIO_S32MSB    0x9020  /* signed 32-bit big-endian */
#define AUDIO_F32LSB    0x8120  /* 32-bit float little-endian */
#define AUDIO_F32MSB    0x9120  /* 32-bit float big-endian */

/* System byte order aliases */
#define AUDIO_S16SYS    AUDIO_S16MSB   /* 68k is big-endian */
#define AUDIO_S32SYS    AUDIO_S32MSB
#define AUDIO_F32SYS    AUDIO_F32MSB
```

On 68k (big-endian), AUDIO_S16SYS = AUDIO_S16MSB = 0x9010.

For AHI: AHI uses its own sample type constants. Mapping:
- AUDIO_U8    -> AHIST_M8S (mono) or AHIST_S8S (stereo)
- AUDIO_S16SYS -> AHIST_M16S (mono) or AHIST_S16S (stereo)

AHI does not natively support S32 or F32. If the app requests these, set
spec.format to AUDIO_S16SYS in OpenDevice() and SDL2 will convert.

### Format query macros

```c
SDL_AUDIO_BITSIZE(fmt)        /* bit depth: 8, 16, 32 */
SDL_AUDIO_ISFLOAT(fmt)        /* non-zero if floating-point */
SDL_AUDIO_ISBIGENDIAN(fmt)    /* non-zero if big-endian */
SDL_AUDIO_ISSIGNED(fmt)       /* non-zero if signed */
```

---

## 6. Format Negotiation in OpenDevice

When OpenDevice is called, _this->spec contains what SDL2 wants from the
hardware (based on the application request, possibly rounded to power-of-2
samples if SupportsNonPow2Samples is SDL_FALSE).

The backend may modify _this->spec fields to reflect what the hardware
actually supports. After OpenDevice returns, SDL2 compares the (possibly
modified) _this->spec against what the app originally requested and builds
a resampler/converter if they differ.

Typical negotiation pattern:

```c
static int OS3AHI_OpenDevice(_THIS, const char *devname)
{
    struct SDL_PrivateAudioData *h;
    int freq = _this->spec.freq;

    /* Clamp to AHI-supported rates */
    if (freq < 4000)  freq = 4000;
    if (freq > 56000) freq = 56000;
    _this->spec.freq = freq;

    /* AHI supports 8-bit and 16-bit signed big-endian */
    if (_this->spec.format != AUDIO_S16SYS &&
        _this->spec.format != AUDIO_S8) {
        _this->spec.format = AUDIO_S16SYS;  /* fall back to S16 */
    }

    /* AHI supports mono and stereo */
    if (_this->spec.channels > 2) {
        _this->spec.channels = 2;
    }

    /* SDL2 recalculates spec.size and spec.silence after we return */

    h = SDL_malloc(sizeof(*h));
    if (!h) return SDL_OutOfMemory();
    SDL_zerop(h);

    /* Allocate mix buffers sized to spec.size */
    /* ... open ahi.device ... */

    _this->hidden = h;
    return 0;
}
```

SDL_CalculateAudioSpec() is called by SDL2 core after OpenDevice returns,
recalculating spec.size and spec.silence from the (possibly adjusted) spec.
Do NOT calculate spec.size yourself.

### SDL_AUDIO_ALLOW flags

The application passes allowed_changes flags to SDL_OpenAudioDevice():
- SDL_AUDIO_ALLOW_FREQUENCY_CHANGE
- SDL_AUDIO_ALLOW_FORMAT_CHANGE
- SDL_AUDIO_ALLOW_CHANNELS_CHANGE
- SDL_AUDIO_ALLOW_SAMPLES_CHANGE

SDL2 core handles these flags AFTER OpenDevice returns. The backend does not
see them. The backend should always set spec to what the hardware provides,
and SDL2 decides whether to build a converter based on the allow flags.

---

## 7. Device Enumeration Flags

These boolean fields in SDL_AudioDriverImpl control enumeration behavior:

**OnlyHasDefaultOutputDevice** (SDL_TRUE for AHI Phase 3):
- SDL2 does not call DetectDevices() for output enumeration
- SDL_GetNumAudioDevices(0) returns 1
- SDL_GetAudioDeviceName(0, 0) returns DEFAULT_OUTPUT_DEVNAME
- OpenDevice() is called with devname=NULL for the default device
- Simplest correct setting for AHI: set this SDL_TRUE

**OnlyHasDefaultCaptureDevice**:
- Same as above but for capture. Set SDL_TRUE if HasCaptureSupport is SDL_FALSE.

**HasCaptureSupport**:
- SDL_FALSE means CaptureFromDevice is never called
- Set SDL_FALSE for Phase 3 (output only)

**AllowsArbitraryDeviceNames**:
- SDL_TRUE means OpenDevice may be called with any devname string
- SDL_FALSE means devname must match a name registered via SDL_AddAudioDevice
- Set SDL_FALSE when OnlyHasDefaultOutputDevice is SDL_TRUE

**SupportsNonPow2Samples**:
- SDL_FALSE causes SDL2 to round spec.samples up to the nearest power of 2
  before calling OpenDevice()
- AHI has no restriction here; set SDL_TRUE to preserve the app's buffer size
- If unsure, set SDL_FALSE (safe default, disk and most backends use SDL_FALSE)

---

## 8. Callback vs Queue Model

The application can use either:

**Callback model**: app provides a SDL_AudioCallback in SDL_AudioSpec.callback.
SDL2's audio thread calls this each iteration to fill the mix buffer.

**Queue model**: app calls SDL_QueueAudio() to push data. SDL_AudioSpec.callback
is NULL. SDL2 installs an internal SDL_BufferQueueDrainCallback and drains
the queue from its audio thread.

The backend does not need to handle this distinction. From the backend's
perspective, PlayDevice/WaitDevice/GetDeviceBuf work the same in both cases.
SDL2 core manages the queue transparently.

---

## 9. SDL_PrivateAudioData -- Backend Private Struct

The backend defines its own private data struct and assigns it to _this->hidden.
SDL2 never dereferences _this->hidden -- it only asserts it is non-NULL after
OpenDevice.

Typical contents for an AHI backend:

```c
struct SDL_PrivateAudioData
{
    struct MsgPort   *ahi_port;       /* MsgPort for AHI I/O */
    struct AHIRequest *ahi_req[2];    /* double-buffered AHI requests */
    int               current_req;   /* which request is being filled */
    Uint8            *mixbuf[2];      /* two mix buffers for double-buffering */
    ULONG             ahi_type;       /* AHIST_* sample type */
    ULONG             freq;           /* actual playback frequency */
};
```

On 68k: keep this struct under 512 bytes to avoid stack pressure when
functions take it by pointer. See crash-patterns.md #7 and #10.

---

## 10. Minimal AHI Backend Implementation Plan

For Phase 3, the minimum required function pointers:

| Function pointer     | Required? | Notes                              |
|---------------------|-----------|------------------------------------|
| OpenDevice          | YES       | open ahi.device, alloc buffers     |
| CloseDevice         | YES       | close device, free everything      |
| GetDeviceBuf        | YES       | return pointer to mix buffer       |
| PlayDevice          | YES       | submit buffer to AHI               |
| WaitDevice          | YES       | block until buffer consumed        |
| DetectDevices       | no        | set OnlyHasDefaultOutputDevice     |
| ThreadInit          | maybe     | if ahi.device must be opened here  |
| ThreadDeinit        | maybe     | if opened in ThreadInit            |
| Deinitialize        | no        | leave NULL unless global state     |
| LockDevice          | no        | SDL2 mutex is sufficient           |
| UnlockDevice        | no        | SDL2 mutex is sufficient           |

Flags to set in init():

```c
impl->OpenDevice              = OS3AHI_OpenDevice;
impl->CloseDevice             = OS3AHI_CloseDevice;
impl->GetDeviceBuf            = OS3AHI_GetDeviceBuf;
impl->PlayDevice              = OS3AHI_PlayDevice;
impl->WaitDevice              = OS3AHI_WaitDevice;

impl->OnlyHasDefaultOutputDevice = SDL_TRUE;
impl->OnlyHasDefaultCaptureDevice = SDL_TRUE;
impl->HasCaptureSupport       = SDL_FALSE;
impl->SupportsNonPow2Samples  = SDL_TRUE;
```

---

## 11. Error Reporting

Use SDL_SetError() to report errors from OpenDevice:

```c
if (OpenDevice("ahi.device", 0, &req, 0, UNIT_VHIFI) != 0) {
    return SDL_SetError("OS3AHI: Cannot open ahi.device (error %ld)",
                        (long)req->ahir_Std.io_Error);
}
```

SDL_OpenedAudioDeviceDisconnected() notifies SDL2 that an open device has
failed during playback (e.g. hardware removed). From PlayDevice or WaitDevice:

```c
SDL_OpenedAudioDeviceDisconnected(_this);
```

This sets device->enabled = 0. The audio thread will then stop calling
PlayDevice/WaitDevice until the device is re-enabled or closed.

---

## 12. AmigaOS-Specific Notes for AHI

### ahi.device opening

AHI is opened as an Exec device, not a library:

```c
#include <proto/exec.h>
#include <devices/ahi.h>

struct MsgPort   *port = CreateMsgPort();
struct AHIRequest *req = CreateIORequest(port, sizeof(struct AHIRequest));
req->ahir_Version = 4;  /* AHI V4 minimum */
if (OpenDevice(AHINAME, AHI_DEFAULT_UNIT, (struct IORequest *)req, 0)) {
    /* failed */
}
```

AHIBase is set automatically when ahi.device is opened:
```c
struct Library *AHIBase;   /* set by OpenDevice() */
```

### Double-buffering with AHI

AHI uses IORequests for sound playback. For double-buffering:
1. Allocate two AHIRequest structs and two mix buffers
2. GetDeviceBuf returns mixbuf[current]
3. PlayDevice: set req[current]->ahir_Std.io_Data = mixbuf[current],
   set sample count, call BeginIO() (non-blocking)
4. WaitDevice: WaitIO(req[!current]) to wait for the previous request
5. Toggle current

This ensures one buffer is always playing while the other is being filled.
The first iteration has nothing to wait for -- handle this with a flag.

### Task context

ahi.device I/O requests must be sent from the same task (Exec Task) that
opened the device. If ThreadInit is used to open ahi.device in the audio
thread, the IORequests must also be created in ThreadInit (same task context).

Do NOT open ahi.device in OS3AHI_OpenDevice if the audio thread will be
doing the I/O -- the main task context will differ from the audio thread.
Instead, store the device parameters in _this->hidden and open ahi.device
in ThreadInit.

### Relation to crash-patterns.md

- crash-patterns.md #7: SDL2 audio thread stack. SDL2 creates the thread
  with SDL_CreateThreadInternal with stack size 0 (system default). AmigaOS
  default stack is 4KB. AHI I/O adds hidden stack depth. If audio thread
  stack overflows, symptom is silent audio or Guru. May need to configure
  SDL thread stack size.
- crash-patterns.md #10: keep mix buffers heap-allocated, not on the stack.
- crash-patterns.md #16: avoid returning SDL_PrivateAudioData by value at -O2.
  Always pass as pointer through _this->hidden.

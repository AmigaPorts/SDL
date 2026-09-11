/* Automatically generated header (sfdc 1.11e)! Do not edit! */

#ifndef _GATEPROTO_SDL2_H
#define _GATEPROTO_SDL2_H

#include <SDL.h>
#include <SDL_syswm.h>

#define _sfdc_strarg(a) _sfdc_strarg2(a)
#define _sfdc_strarg2(a) #a

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#undef __USE_INLINE__
#define _NO_INLINE
#define __NOLIBBASE__
#define __NOGLOBALIFACE__
#include <proto/sdl2.h>
#undef _NO_INLINE
#undef __NOLIBBASE__
#undef __NOGLOBALIFACE__
#include <stdarg.h>
#include <interfaces/exec.h>
#include <exec/emulation.h>

int
SDL2Gate_SDL_Init(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Init;

int
SDL2Gate_SDL_InitSubSystem(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_InitSubSystem;

void
SDL2Gate_SDL_QuitSubSystem(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_QuitSubSystem;

Uint32
SDL2Gate_SDL_WasInit(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WasInit;

void
SDL2Gate_SDL_Quit(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Quit;

SDL_AssertState
SDL2Gate_SDL_ReportAssertion(struct SDL2IFace* _iface,
     SDL_AssertData * ___a,
     const char * ___b,
     const char * ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReportAssertion;

void
SDL2Gate_SDL_SetAssertionHandler(struct SDL2IFace* _iface,
     SDL_AssertionHandler ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetAssertionHandler;

const SDL_AssertData*
SDL2Gate_SDL_GetAssertionReport(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetAssertionReport;

void
SDL2Gate_SDL_ResetAssertionReport(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ResetAssertionReport;

SDL_bool
SDL2Gate_SDL_AtomicTryLock(struct SDL2IFace* _iface,
     SDL_SpinLock * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicTryLock;

void
SDL2Gate_SDL_AtomicLock(struct SDL2IFace* _iface,
     SDL_SpinLock * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicLock;

void
SDL2Gate_SDL_AtomicUnlock(struct SDL2IFace* _iface,
     SDL_SpinLock * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicUnlock;

SDL_bool
SDL2Gate_SDL_AtomicCAS(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicCAS;

int
SDL2Gate_SDL_AtomicSet(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicSet;

int
SDL2Gate_SDL_AtomicGet(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicGet;

int
SDL2Gate_SDL_AtomicAdd(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicAdd;

SDL_bool
SDL2Gate_SDL_AtomicCASPtr(struct SDL2IFace* _iface,
     void * * ___a,
     void * ___b,
     void * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicCASPtr;

void*
SDL2Gate_SDL_AtomicSetPtr(struct SDL2IFace* _iface,
     void * * ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicSetPtr;

void*
SDL2Gate_SDL_AtomicGetPtr(struct SDL2IFace* _iface,
     void * * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicGetPtr;

int
SDL2Gate_SDL_GetNumAudioDrivers(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumAudioDrivers;

const char*
SDL2Gate_SDL_GetAudioDriver(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetAudioDriver;

int
SDL2Gate_SDL_AudioInit(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioInit;

void
SDL2Gate_SDL_AudioQuit(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioQuit;

const char*
SDL2Gate_SDL_GetCurrentAudioDriver(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetCurrentAudioDriver;

int
SDL2Gate_SDL_OpenAudio(struct SDL2IFace* _iface,
     SDL_AudioSpec * ___a,
     SDL_AudioSpec * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OpenAudio;

int
SDL2Gate_SDL_GetNumAudioDevices(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumAudioDevices;

const char*
SDL2Gate_SDL_GetAudioDeviceName(struct SDL2IFace* _iface,
     int ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetAudioDeviceName;

SDL_AudioDeviceID
SDL2Gate_SDL_OpenAudioDevice(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b,
     const SDL_AudioSpec * ___c,
     SDL_AudioSpec * ___d,
     int ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OpenAudioDevice;

void
SDL2Gate_SDL_PauseAudio(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PauseAudio;

void
SDL2Gate_SDL_PauseAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PauseAudioDevice;

SDL_AudioSpec*
SDL2Gate_SDL_LoadWAV_RW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     int ___b,
     SDL_AudioSpec * ___c,
     Uint8 * * ___d,
     Uint32 * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadWAV_RW;

void
SDL2Gate_SDL_FreeWAV(struct SDL2IFace* _iface,
     Uint8 * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreeWAV;

int
SDL2Gate_SDL_BuildAudioCVT(struct SDL2IFace* _iface,
     SDL_AudioCVT * ___a,
     SDL_AudioFormat ___b,
     Uint8 ___c,
     int ___d,
     SDL_AudioFormat ___e,
     Uint8 ___f,
     int ___g);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_BuildAudioCVT;

int
SDL2Gate_SDL_ConvertAudio(struct SDL2IFace* _iface,
     SDL_AudioCVT * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertAudio;

void
SDL2Gate_SDL_MixAudio(struct SDL2IFace* _iface,
     Uint8 * ___a,
     const Uint8 * ___b,
     Uint32 ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MixAudio;

void
SDL2Gate_SDL_MixAudioFormat(struct SDL2IFace* _iface,
     Uint8 * ___a,
     const Uint8 * ___b,
     SDL_AudioFormat ___c,
     Uint32 ___d,
     int ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MixAudioFormat;

void
SDL2Gate_SDL_LockAudio(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockAudio;

void
SDL2Gate_SDL_LockAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockAudioDevice;

void
SDL2Gate_SDL_UnlockAudio(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockAudio;

void
SDL2Gate_SDL_UnlockAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockAudioDevice;

void
SDL2Gate_SDL_CloseAudio(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CloseAudio;

void
SDL2Gate_SDL_CloseAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CloseAudioDevice;

int
SDL2Gate_SDL_SetClipboardText(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetClipboardText;

char*
SDL2Gate_SDL_GetClipboardText(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetClipboardText;

SDL_bool
SDL2Gate_SDL_HasClipboardText(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasClipboardText;

int
SDL2Gate_SDL_GetCPUCount(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetCPUCount;

int
SDL2Gate_SDL_GetCPUCacheLineSize(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetCPUCacheLineSize;

SDL_bool
SDL2Gate_SDL_HasRDTSC(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasRDTSC;

SDL_bool
SDL2Gate_SDL_HasAltiVec(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasAltiVec;

SDL_bool
SDL2Gate_SDL_HasMMX(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasMMX;

SDL_bool
SDL2Gate_SDL_Has3DNow(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Has3DNow;

SDL_bool
SDL2Gate_SDL_HasSSE(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE;

SDL_bool
SDL2Gate_SDL_HasSSE2(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE2;

SDL_bool
SDL2Gate_SDL_HasSSE3(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE3;

SDL_bool
SDL2Gate_SDL_HasSSE41(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE41;

SDL_bool
SDL2Gate_SDL_HasSSE42(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE42;

int
SDL2Gate_SDL_GetSystemRAM(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetSystemRAM;

const char*
SDL2Gate_SDL_GetError(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetError;

void
SDL2Gate_SDL_ClearError(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ClearError;

int
SDL2Gate_SDL_Error(struct SDL2IFace* _iface,
     SDL_errorcode ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Error;

void
SDL2Gate_SDL_PumpEvents(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PumpEvents;

int
SDL2Gate_SDL_PeepEvents(struct SDL2IFace* _iface,
     SDL_Event * ___a,
     int ___b,
     SDL_eventaction ___c,
     Uint32 ___d,
     Uint32 ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PeepEvents;

SDL_bool
SDL2Gate_SDL_HasEvent(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasEvent;

SDL_bool
SDL2Gate_SDL_HasEvents(struct SDL2IFace* _iface,
     Uint32 ___a,
     Uint32 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasEvents;

void
SDL2Gate_SDL_FlushEvent(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FlushEvent;

void
SDL2Gate_SDL_FlushEvents(struct SDL2IFace* _iface,
     Uint32 ___a,
     Uint32 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FlushEvents;

int
SDL2Gate_SDL_PollEvent(struct SDL2IFace* _iface,
     SDL_Event * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PollEvent;

int
SDL2Gate_SDL_WaitEvent(struct SDL2IFace* _iface,
     SDL_Event * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WaitEvent;

int
SDL2Gate_SDL_WaitEventTimeout(struct SDL2IFace* _iface,
     SDL_Event * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WaitEventTimeout;

int
SDL2Gate_SDL_PushEvent(struct SDL2IFace* _iface,
     SDL_Event * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PushEvent;

void
SDL2Gate_SDL_SetEventFilter(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetEventFilter;

SDL_bool
SDL2Gate_SDL_GetEventFilter(struct SDL2IFace* _iface,
     SDL_EventFilter * ___a,
     void * * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetEventFilter;

void
SDL2Gate_SDL_AddEventWatch(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AddEventWatch;

void
SDL2Gate_SDL_DelEventWatch(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DelEventWatch;

void
SDL2Gate_SDL_FilterEvents(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FilterEvents;

Uint8
SDL2Gate_SDL_EventState(struct SDL2IFace* _iface,
     Uint32 ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_EventState;

Uint32
SDL2Gate_SDL_RegisterEvents(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RegisterEvents;

char*
SDL2Gate_SDL_GetBasePath(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetBasePath;

char*
SDL2Gate_SDL_GetPrefPath(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPrefPath;

int
SDL2Gate_SDL_GameControllerAddMapping(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerAddMapping;

char*
SDL2Gate_SDL_GameControllerMapping(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerMapping;

SDL_bool
SDL2Gate_SDL_IsGameController(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsGameController;

const char*
SDL2Gate_SDL_GameControllerNameForIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerNameForIndex;

SDL_GameController*
SDL2Gate_SDL_GameControllerOpen(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerOpen;

const char*
SDL2Gate_SDL_GameControllerName(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerName;

SDL_bool
SDL2Gate_SDL_GameControllerGetAttached(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAttached;

SDL_Joystick*
SDL2Gate_SDL_GameControllerGetJoystick(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetJoystick;

int
SDL2Gate_SDL_GameControllerEventState(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerEventState;

void
SDL2Gate_SDL_GameControllerUpdate(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerUpdate;

SDL_GameControllerAxis
SDL2Gate_SDL_GameControllerGetAxisFromString(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAxisFromString;

const char*
SDL2Gate_SDL_GameControllerGetStringForAxis(struct SDL2IFace* _iface,
     SDL_GameControllerAxis ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetStringForAxis;

Sint16
SDL2Gate_SDL_GameControllerGetAxis(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerAxis ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAxis;

SDL_GameControllerButton
SDL2Gate_SDL_GameControllerGetButtonFromString(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetButtonFromString;

const char*
SDL2Gate_SDL_GameControllerGetStringForButton(struct SDL2IFace* _iface,
     SDL_GameControllerButton ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetStringForButton;

Uint8
SDL2Gate_SDL_GameControllerGetButton(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerButton ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetButton;

void
SDL2Gate_SDL_GameControllerClose(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerClose;

int
SDL2Gate_SDL_RecordGesture(struct SDL2IFace* _iface,
     SDL_TouchID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RecordGesture;

int
SDL2Gate_SDL_SaveAllDollarTemplates(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SaveAllDollarTemplates;

int
SDL2Gate_SDL_SaveDollarTemplate(struct SDL2IFace* _iface,
     SDL_GestureID ___a,
     SDL_RWops * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SaveDollarTemplate;

int
SDL2Gate_SDL_LoadDollarTemplates(struct SDL2IFace* _iface,
     SDL_TouchID ___a,
     SDL_RWops * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadDollarTemplates;

int
SDL2Gate_SDL_NumHaptics(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_NumHaptics;

const char*
SDL2Gate_SDL_HapticName(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticName;

SDL_Haptic*
SDL2Gate_SDL_HapticOpen(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpen;

int
SDL2Gate_SDL_HapticOpened(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpened;

int
SDL2Gate_SDL_HapticIndex(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticIndex;

int
SDL2Gate_SDL_MouseIsHaptic(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MouseIsHaptic;

SDL_Haptic*
SDL2Gate_SDL_HapticOpenFromMouse(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpenFromMouse;

int
SDL2Gate_SDL_JoystickIsHaptic(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickIsHaptic;

SDL_Haptic*
SDL2Gate_SDL_HapticOpenFromJoystick(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpenFromJoystick;

void
SDL2Gate_SDL_HapticClose(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticClose;

int
SDL2Gate_SDL_HapticNumEffects(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNumEffects;

int
SDL2Gate_SDL_HapticNumEffectsPlaying(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNumEffectsPlaying;

unsigned int
SDL2Gate_SDL_HapticQuery(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticQuery;

int
SDL2Gate_SDL_HapticNumAxes(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNumAxes;

int
SDL2Gate_SDL_HapticEffectSupported(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     SDL_HapticEffect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticEffectSupported;

int
SDL2Gate_SDL_HapticNewEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     SDL_HapticEffect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNewEffect;

int
SDL2Gate_SDL_HapticUpdateEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b,
     SDL_HapticEffect * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticUpdateEffect;

int
SDL2Gate_SDL_HapticRunEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRunEffect;

int
SDL2Gate_SDL_HapticStopEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticStopEffect;

void
SDL2Gate_SDL_HapticDestroyEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticDestroyEffect;

int
SDL2Gate_SDL_HapticGetEffectStatus(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticGetEffectStatus;

int
SDL2Gate_SDL_HapticSetGain(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticSetGain;

int
SDL2Gate_SDL_HapticSetAutocenter(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticSetAutocenter;

int
SDL2Gate_SDL_HapticPause(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticPause;

int
SDL2Gate_SDL_HapticUnpause(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticUnpause;

int
SDL2Gate_SDL_HapticStopAll(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticStopAll;

int
SDL2Gate_SDL_HapticRumbleSupported(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumbleSupported;

int
SDL2Gate_SDL_HapticRumbleInit(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumbleInit;

int
SDL2Gate_SDL_HapticRumblePlay(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     float ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumblePlay;

int
SDL2Gate_SDL_HapticRumbleStop(struct SDL2IFace* _iface,
     SDL_Haptic * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumbleStop;

SDL_bool
SDL2Gate_SDL_SetHintWithPriority(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     SDL_HintPriority ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetHintWithPriority;

SDL_bool
SDL2Gate_SDL_SetHint(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetHint;

const char*
SDL2Gate_SDL_GetHint(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetHint;

void
SDL2Gate_SDL_AddHintCallback(struct SDL2IFace* _iface,
     const char * ___a,
     SDL_HintCallback ___b,
     void * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AddHintCallback;

void
SDL2Gate_SDL_DelHintCallback(struct SDL2IFace* _iface,
     const char * ___a,
     SDL_HintCallback ___b,
     void * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DelHintCallback;

void
SDL2Gate_SDL_ClearHints(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ClearHints;

int
SDL2Gate_SDL_NumJoysticks(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_NumJoysticks;

const char*
SDL2Gate_SDL_JoystickNameForIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNameForIndex;

SDL_Joystick*
SDL2Gate_SDL_JoystickOpen(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickOpen;

const char*
SDL2Gate_SDL_JoystickName(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickName;

SDL_bool
SDL2Gate_SDL_JoystickGetAttached(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetAttached;

SDL_JoystickID
SDL2Gate_SDL_JoystickInstanceID(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickInstanceID;

int
SDL2Gate_SDL_JoystickNumAxes(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumAxes;

int
SDL2Gate_SDL_JoystickNumBalls(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumBalls;

int
SDL2Gate_SDL_JoystickNumHats(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumHats;

int
SDL2Gate_SDL_JoystickNumButtons(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumButtons;

void
SDL2Gate_SDL_JoystickUpdate(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickUpdate;

int
SDL2Gate_SDL_JoystickEventState(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickEventState;

Sint16
SDL2Gate_SDL_JoystickGetAxis(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetAxis;

Uint8
SDL2Gate_SDL_JoystickGetHat(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetHat;

int
SDL2Gate_SDL_JoystickGetBall(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     int * ___c,
     int * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetBall;

Uint8
SDL2Gate_SDL_JoystickGetButton(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetButton;

void
SDL2Gate_SDL_JoystickClose(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickClose;

SDL_Window*
SDL2Gate_SDL_GetKeyboardFocus(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyboardFocus;

const Uint8*
SDL2Gate_SDL_GetKeyboardState(struct SDL2IFace* _iface,
     int * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyboardState;

SDL_Keymod
SDL2Gate_SDL_GetModState(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetModState;

void
SDL2Gate_SDL_SetModState(struct SDL2IFace* _iface,
     SDL_Keymod ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetModState;

SDL_Keycode
SDL2Gate_SDL_GetKeyFromScancode(struct SDL2IFace* _iface,
     SDL_Scancode ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyFromScancode;

SDL_Scancode
SDL2Gate_SDL_GetScancodeFromKey(struct SDL2IFace* _iface,
     SDL_Keycode ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetScancodeFromKey;

const char*
SDL2Gate_SDL_GetScancodeName(struct SDL2IFace* _iface,
     SDL_Scancode ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetScancodeName;

SDL_Scancode
SDL2Gate_SDL_GetScancodeFromName(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetScancodeFromName;

const char*
SDL2Gate_SDL_GetKeyName(struct SDL2IFace* _iface,
     SDL_Keycode ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyName;

SDL_Keycode
SDL2Gate_SDL_GetKeyFromName(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyFromName;

void
SDL2Gate_SDL_StartTextInput(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_StartTextInput;

SDL_bool
SDL2Gate_SDL_IsTextInputActive(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsTextInputActive;

void
SDL2Gate_SDL_StopTextInput(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_StopTextInput;

void
SDL2Gate_SDL_SetTextInputRect(struct SDL2IFace* _iface,
     const SDL_Rect * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextInputRect;

SDL_bool
SDL2Gate_SDL_HasScreenKeyboardSupport(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasScreenKeyboardSupport;

SDL_bool
SDL2Gate_SDL_IsScreenKeyboardShown(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsScreenKeyboardShown;

void*
SDL2Gate_SDL_LoadObject(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadObject;

void*
SDL2Gate_SDL_LoadFunction(struct SDL2IFace* _iface,
     void * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadFunction;

void
SDL2Gate_SDL_UnloadObject(struct SDL2IFace* _iface,
     void * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnloadObject;

void
SDL2Gate_SDL_LogSetAllPriority(struct SDL2IFace* _iface,
     SDL_LogPriority ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LogSetAllPriority;

void
SDL2Gate_SDL_LogSetPriority(struct SDL2IFace* _iface,
     int ___a,
     SDL_LogPriority ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LogSetPriority;

SDL_LogPriority
SDL2Gate_SDL_LogGetPriority(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LogGetPriority;

void
SDL2Gate_SDL_LogResetPriorities(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LogResetPriorities;

void
SDL2Gate_SDL_LogGetOutputFunction(struct SDL2IFace* _iface,
     SDL_LogOutputFunction * ___a,
     void * * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LogGetOutputFunction;

void
SDL2Gate_SDL_LogSetOutputFunction(struct SDL2IFace* _iface,
     SDL_LogOutputFunction ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LogSetOutputFunction;

void
SDL2Gate_SDL_SetMainReady(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetMainReady;

int
SDL2Gate_SDL_ShowMessageBox(struct SDL2IFace* _iface,
     const SDL_MessageBoxData * ___a,
     int * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ShowMessageBox;

int
SDL2Gate_SDL_ShowSimpleMessageBox(struct SDL2IFace* _iface,
     Uint32 ___a,
     const char * ___b,
     const char * ___c,
     SDL_Window * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ShowSimpleMessageBox;

SDL_Window*
SDL2Gate_SDL_GetMouseFocus(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetMouseFocus;

Uint32
SDL2Gate_SDL_GetMouseState(struct SDL2IFace* _iface,
     int * ___a,
     int * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetMouseState;

Uint32
SDL2Gate_SDL_GetRelativeMouseState(struct SDL2IFace* _iface,
     int * ___a,
     int * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRelativeMouseState;

void
SDL2Gate_SDL_WarpMouseInWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WarpMouseInWindow;

int
SDL2Gate_SDL_SetRelativeMouseMode(struct SDL2IFace* _iface,
     SDL_bool ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetRelativeMouseMode;

SDL_bool
SDL2Gate_SDL_GetRelativeMouseMode(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRelativeMouseMode;

SDL_Cursor*
SDL2Gate_SDL_CreateCursor(struct SDL2IFace* _iface,
     const Uint8 * ___a,
     const Uint8 * ___b,
     int ___c,
     int ___d,
     int ___e,
     int ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateCursor;

SDL_Cursor*
SDL2Gate_SDL_CreateColorCursor(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateColorCursor;

SDL_Cursor*
SDL2Gate_SDL_CreateSystemCursor(struct SDL2IFace* _iface,
     SDL_SystemCursor ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateSystemCursor;

void
SDL2Gate_SDL_SetCursor(struct SDL2IFace* _iface,
     SDL_Cursor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetCursor;

SDL_Cursor*
SDL2Gate_SDL_GetCursor(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetCursor;

SDL_Cursor*
SDL2Gate_SDL_GetDefaultCursor(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDefaultCursor;

void
SDL2Gate_SDL_FreeCursor(struct SDL2IFace* _iface,
     SDL_Cursor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreeCursor;

int
SDL2Gate_SDL_ShowCursor(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ShowCursor;

SDL_mutex*
SDL2Gate_SDL_CreateMutex(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateMutex;

int
SDL2Gate_SDL_LockMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockMutex;

int
SDL2Gate_SDL_TryLockMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_TryLockMutex;

int
SDL2Gate_SDL_UnlockMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockMutex;

void
SDL2Gate_SDL_DestroyMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyMutex;

SDL_sem*
SDL2Gate_SDL_CreateSemaphore(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateSemaphore;

void
SDL2Gate_SDL_DestroySemaphore(struct SDL2IFace* _iface,
     SDL_sem * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroySemaphore;

int
SDL2Gate_SDL_SemWait(struct SDL2IFace* _iface,
     SDL_sem * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SemWait;

int
SDL2Gate_SDL_SemTryWait(struct SDL2IFace* _iface,
     SDL_sem * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SemTryWait;

int
SDL2Gate_SDL_SemWaitTimeout(struct SDL2IFace* _iface,
     SDL_sem * ___a,
     Uint32 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SemWaitTimeout;

int
SDL2Gate_SDL_SemPost(struct SDL2IFace* _iface,
     SDL_sem * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SemPost;

Uint32
SDL2Gate_SDL_SemValue(struct SDL2IFace* _iface,
     SDL_sem * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SemValue;

SDL_cond*
SDL2Gate_SDL_CreateCond(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateCond;

void
SDL2Gate_SDL_DestroyCond(struct SDL2IFace* _iface,
     SDL_cond * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyCond;

int
SDL2Gate_SDL_CondSignal(struct SDL2IFace* _iface,
     SDL_cond * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CondSignal;

int
SDL2Gate_SDL_CondBroadcast(struct SDL2IFace* _iface,
     SDL_cond * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CondBroadcast;

int
SDL2Gate_SDL_CondWait(struct SDL2IFace* _iface,
     SDL_cond * ___a,
     SDL_mutex * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CondWait;

int
SDL2Gate_SDL_CondWaitTimeout(struct SDL2IFace* _iface,
     SDL_cond * ___a,
     SDL_mutex * ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CondWaitTimeout;

const char*
SDL2Gate_SDL_GetPixelFormatName(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPixelFormatName;

SDL_bool
SDL2Gate_SDL_PixelFormatEnumToMasks(struct SDL2IFace* _iface,
     Uint32 ___a,
     int * ___b,
     Uint32 * ___c,
     Uint32 * ___d,
     Uint32 * ___e,
     Uint32 * ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PixelFormatEnumToMasks;

Uint32
SDL2Gate_SDL_MasksToPixelFormatEnum(struct SDL2IFace* _iface,
     int ___a,
     Uint32 ___b,
     Uint32 ___c,
     Uint32 ___d,
     Uint32 ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MasksToPixelFormatEnum;

SDL_PixelFormat*
SDL2Gate_SDL_AllocFormat(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AllocFormat;

void
SDL2Gate_SDL_FreeFormat(struct SDL2IFace* _iface,
     SDL_PixelFormat * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreeFormat;

SDL_Palette*
SDL2Gate_SDL_AllocPalette(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AllocPalette;

int
SDL2Gate_SDL_SetPixelFormatPalette(struct SDL2IFace* _iface,
     SDL_PixelFormat * ___a,
     SDL_Palette * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetPixelFormatPalette;

int
SDL2Gate_SDL_SetPaletteColors(struct SDL2IFace* _iface,
     SDL_Palette * ___a,
     const SDL_Color * ___b,
     int ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetPaletteColors;

void
SDL2Gate_SDL_FreePalette(struct SDL2IFace* _iface,
     SDL_Palette * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreePalette;

Uint32
SDL2Gate_SDL_MapRGB(struct SDL2IFace* _iface,
     const SDL_PixelFormat * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MapRGB;

Uint32
SDL2Gate_SDL_MapRGBA(struct SDL2IFace* _iface,
     const SDL_PixelFormat * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d,
     Uint8 ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MapRGBA;

void
SDL2Gate_SDL_GetRGB(struct SDL2IFace* _iface,
     Uint32 ___a,
     const SDL_PixelFormat * ___b,
     Uint8 * ___c,
     Uint8 * ___d,
     Uint8 * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRGB;

void
SDL2Gate_SDL_GetRGBA(struct SDL2IFace* _iface,
     Uint32 ___a,
     const SDL_PixelFormat * ___b,
     Uint8 * ___c,
     Uint8 * ___d,
     Uint8 * ___e,
     Uint8 * ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRGBA;

void
SDL2Gate_SDL_CalculateGammaRamp(struct SDL2IFace* _iface,
     float ___a,
     Uint16 * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CalculateGammaRamp;

const char*
SDL2Gate_SDL_GetPlatform(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPlatform;

SDL_bool
SDL2Gate_SDL_HasIntersection(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasIntersection;

SDL_bool
SDL2Gate_SDL_IntersectRect(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     const SDL_Rect * ___b,
     SDL_Rect * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectRect;

void
SDL2Gate_SDL_UnionRect(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     const SDL_Rect * ___b,
     SDL_Rect * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnionRect;

SDL_bool
SDL2Gate_SDL_EnclosePoints(struct SDL2IFace* _iface,
     const SDL_Point * ___a,
     int ___b,
     const SDL_Rect * ___c,
     SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_EnclosePoints;

SDL_bool
SDL2Gate_SDL_IntersectRectAndLine(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     int * ___b,
     int * ___c,
     int * ___d,
     int * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectRectAndLine;

int
SDL2Gate_SDL_GetNumRenderDrivers(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumRenderDrivers;

int
SDL2Gate_SDL_GetRenderDriverInfo(struct SDL2IFace* _iface,
     int ___a,
     SDL_RendererInfo * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderDriverInfo;

int
SDL2Gate_SDL_CreateWindowAndRenderer(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     Uint32 ___c,
     SDL_Window * * ___d,
     SDL_Renderer * * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateWindowAndRenderer;

SDL_Renderer*
SDL2Gate_SDL_CreateRenderer(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRenderer;

SDL_Renderer*
SDL2Gate_SDL_CreateSoftwareRenderer(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateSoftwareRenderer;

SDL_Renderer*
SDL2Gate_SDL_GetRenderer(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderer;

int
SDL2Gate_SDL_GetRendererInfo(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_RendererInfo * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRendererInfo;

int
SDL2Gate_SDL_GetRendererOutputSize(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRendererOutputSize;

SDL_Texture*
SDL2Gate_SDL_CreateTexture(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     Uint32 ___b,
     int ___c,
     int ___d,
     int ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateTexture;

SDL_Texture*
SDL2Gate_SDL_CreateTextureFromSurface(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Surface * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateTextureFromSurface;

int
SDL2Gate_SDL_QueryTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint32 * ___b,
     int * ___c,
     int * ___d,
     int * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_QueryTexture;

int
SDL2Gate_SDL_SetTextureColorMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureColorMod;

int
SDL2Gate_SDL_GetTextureColorMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 * ___b,
     Uint8 * ___c,
     Uint8 * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureColorMod;

int
SDL2Gate_SDL_SetTextureAlphaMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureAlphaMod;

int
SDL2Gate_SDL_GetTextureAlphaMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureAlphaMod;

int
SDL2Gate_SDL_SetTextureBlendMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_BlendMode ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureBlendMode;

int
SDL2Gate_SDL_GetTextureBlendMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_BlendMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureBlendMode;

int
SDL2Gate_SDL_UpdateTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     const void * ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateTexture;

int
SDL2Gate_SDL_UpdateYUVTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     const Uint8 * ___c,
     int ___d,
     const Uint8 * ___e,
     int ___f,
     const Uint8 * ___g,
     int ___h);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateYUVTexture;

int
SDL2Gate_SDL_LockTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     void * * ___c,
     int * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockTexture;

void
SDL2Gate_SDL_UnlockTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockTexture;

SDL_bool
SDL2Gate_SDL_RenderTargetSupported(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderTargetSupported;

int
SDL2Gate_SDL_SetRenderTarget(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetRenderTarget;

SDL_Texture*
SDL2Gate_SDL_GetRenderTarget(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderTarget;

int
SDL2Gate_SDL_RenderSetLogicalSize(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetLogicalSize;

void
SDL2Gate_SDL_RenderGetLogicalSize(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetLogicalSize;

int
SDL2Gate_SDL_RenderSetViewport(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetViewport;

void
SDL2Gate_SDL_RenderGetViewport(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetViewport;

int
SDL2Gate_SDL_RenderSetClipRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetClipRect;

void
SDL2Gate_SDL_RenderGetClipRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetClipRect;

int
SDL2Gate_SDL_RenderSetScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetScale;

void
SDL2Gate_SDL_RenderGetScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float * ___b,
     float * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetScale;

int
SDL2Gate_SDL_SetRenderDrawColor(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d,
     Uint8 ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetRenderDrawColor;

int
SDL2Gate_SDL_GetRenderDrawColor(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     Uint8 * ___b,
     Uint8 * ___c,
     Uint8 * ___d,
     Uint8 * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderDrawColor;

int
SDL2Gate_SDL_SetRenderDrawBlendMode(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_BlendMode ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetRenderDrawBlendMode;

int
SDL2Gate_SDL_GetRenderDrawBlendMode(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_BlendMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderDrawBlendMode;

int
SDL2Gate_SDL_RenderClear(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderClear;

int
SDL2Gate_SDL_RenderDrawPoint(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPoint;

int
SDL2Gate_SDL_RenderDrawPoints(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Point * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPoints;

int
SDL2Gate_SDL_RenderDrawLine(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLine;

int
SDL2Gate_SDL_RenderDrawLines(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Point * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLines;

int
SDL2Gate_SDL_RenderDrawRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRect;

int
SDL2Gate_SDL_RenderDrawRects(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRects;

int
SDL2Gate_SDL_RenderFillRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRect;

int
SDL2Gate_SDL_RenderFillRects(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRects;

int
SDL2Gate_SDL_RenderCopy(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopy;

int
SDL2Gate_SDL_RenderCopyEx(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_Rect * ___d,
     const double ___e,
     const SDL_Point * ___f,
     const SDL_RendererFlip ___g);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopyEx;

int
SDL2Gate_SDL_RenderReadPixels(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b,
     Uint32 ___c,
     void * ___d,
     int ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderReadPixels;

void
SDL2Gate_SDL_RenderPresent(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderPresent;

void
SDL2Gate_SDL_DestroyTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyTexture;

void
SDL2Gate_SDL_DestroyRenderer(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyRenderer;

int
SDL2Gate_SDL_GL_BindTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     float * ___b,
     float * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_BindTexture;

int
SDL2Gate_SDL_GL_UnbindTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_UnbindTexture;

SDL_RWops*
SDL2Gate_SDL_RWFromFile(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWFromFile;

SDL_RWops*
SDL2Gate_SDL_RWFromMem(struct SDL2IFace* _iface,
     void * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWFromMem;

SDL_RWops*
SDL2Gate_SDL_RWFromConstMem(struct SDL2IFace* _iface,
     const void * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWFromConstMem;

SDL_RWops*
SDL2Gate_SDL_AllocRW(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AllocRW;

void
SDL2Gate_SDL_FreeRW(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreeRW;

Uint8
SDL2Gate_SDL_ReadU8(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadU8;

Uint16
SDL2Gate_SDL_ReadLE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadLE16;

Uint16
SDL2Gate_SDL_ReadBE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadBE16;

Uint32
SDL2Gate_SDL_ReadLE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadLE32;

Uint32
SDL2Gate_SDL_ReadBE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadBE32;

Uint64
SDL2Gate_SDL_ReadLE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadLE64;

Uint64
SDL2Gate_SDL_ReadBE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ReadBE64;

size_t
SDL2Gate_SDL_WriteU8(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint8 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteU8;

size_t
SDL2Gate_SDL_WriteLE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint16 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteLE16;

size_t
SDL2Gate_SDL_WriteBE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint16 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteBE16;

size_t
SDL2Gate_SDL_WriteLE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint32 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteLE32;

size_t
SDL2Gate_SDL_WriteBE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint32 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteBE32;

size_t
SDL2Gate_SDL_WriteLE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint64 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteLE64;

size_t
SDL2Gate_SDL_WriteBE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint64 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WriteBE64;

SDL_Window*
SDL2Gate_SDL_CreateShapedWindow(struct SDL2IFace* _iface,
     const char * ___a,
     unsigned int ___b,
     unsigned int ___c,
     unsigned int ___d,
     unsigned int ___e,
     Uint32 ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateShapedWindow;

SDL_bool
SDL2Gate_SDL_IsShapedWindow(struct SDL2IFace* _iface,
     const SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsShapedWindow;

int
SDL2Gate_SDL_SetWindowShape(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_Surface * ___b,
     SDL_WindowShapeMode * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowShape;

int
SDL2Gate_SDL_GetShapedWindowMode(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_WindowShapeMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetShapedWindowMode;

void*
SDL2Gate_SDL_malloc(struct SDL2IFace* _iface,
     size_t ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_malloc;

void*
SDL2Gate_SDL_calloc(struct SDL2IFace* _iface,
     size_t ___a,
     size_t ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_calloc;

void*
SDL2Gate_SDL_realloc(struct SDL2IFace* _iface,
     void * ___a,
     size_t ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_realloc;

void
SDL2Gate_SDL_free(struct SDL2IFace* _iface,
     void * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_free;

char*
SDL2Gate_SDL_getenv(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_getenv;

int
SDL2Gate_SDL_setenv(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_setenv;

void
SDL2Gate_SDL_qsort(struct SDL2IFace* _iface,
     void * ___a,
     size_t ___b,
     size_t ___c,
     SDL_CompareCallback ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_qsort;

int
SDL2Gate_SDL_abs(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_abs;

int
SDL2Gate_SDL_isdigit(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isdigit;

int
SDL2Gate_SDL_isspace(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isspace;

int
SDL2Gate_SDL_toupper(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_toupper;

int
SDL2Gate_SDL_tolower(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_tolower;

void*
SDL2Gate_SDL_memset(struct SDL2IFace* _iface,
     SDL_OUT_BYTECAP(c) void * ___a,
     int ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_memset;

void*
SDL2Gate_SDL_memcpy(struct SDL2IFace* _iface,
     SDL_OUT_BYTECAP(c) void * ___a,
     SDL_IN_BYTECAP(c) const void * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_memcpy;

void*
SDL2Gate_SDL_memmove(struct SDL2IFace* _iface,
     SDL_OUT_BYTECAP(c) void * ___a,
     SDL_IN_BYTECAP(c) const void * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_memmove;

int
SDL2Gate_SDL_memcmp(struct SDL2IFace* _iface,
     const void * ___a,
     const void * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_memcmp;

size_t
SDL2Gate_SDL_wcslen(struct SDL2IFace* _iface,
     const wchar_t * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcslen;

size_t
SDL2Gate_SDL_wcslcpy(struct SDL2IFace* _iface,
     SDL_OUT_Z_CAP(c) wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcslcpy;

size_t
SDL2Gate_SDL_wcslcat(struct SDL2IFace* _iface,
     SDL_INOUT_Z_CAP(c) wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcslcat;

size_t
SDL2Gate_SDL_strlen(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strlen;

size_t
SDL2Gate_SDL_strlcpy(struct SDL2IFace* _iface,
     SDL_OUT_Z_CAP(c) char * ___a,
     const char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strlcpy;

size_t
SDL2Gate_SDL_utf8strlcpy(struct SDL2IFace* _iface,
     SDL_OUT_Z_CAP(c) char * ___a,
     const char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_utf8strlcpy;

size_t
SDL2Gate_SDL_strlcat(struct SDL2IFace* _iface,
     SDL_INOUT_Z_CAP(c) char * ___a,
     const char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strlcat;

char*
SDL2Gate_SDL_strdup(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strdup;

char*
SDL2Gate_SDL_strrev(struct SDL2IFace* _iface,
     char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strrev;

char*
SDL2Gate_SDL_strupr(struct SDL2IFace* _iface,
     char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strupr;

char*
SDL2Gate_SDL_strlwr(struct SDL2IFace* _iface,
     char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strlwr;

char*
SDL2Gate_SDL_strchr(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strchr;

char*
SDL2Gate_SDL_strrchr(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strrchr;

char*
SDL2Gate_SDL_strstr(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strstr;

char*
SDL2Gate_SDL_itoa(struct SDL2IFace* _iface,
     int ___a,
     char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_itoa;

char*
SDL2Gate_SDL_uitoa(struct SDL2IFace* _iface,
     unsigned int ___a,
     char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_uitoa;

char*
SDL2Gate_SDL_ltoa(struct SDL2IFace* _iface,
     long ___a,
     char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ltoa;

char*
SDL2Gate_SDL_ultoa(struct SDL2IFace* _iface,
     unsigned long ___a,
     char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ultoa;

char*
SDL2Gate_SDL_lltoa(struct SDL2IFace* _iface,
     Sint64 ___a,
     char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_lltoa;

char*
SDL2Gate_SDL_ulltoa(struct SDL2IFace* _iface,
     Uint64 ___a,
     char * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ulltoa;

int
SDL2Gate_SDL_atoi(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_atoi;

double
SDL2Gate_SDL_atof(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_atof;

long
SDL2Gate_SDL_strtol(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strtol;

unsigned long
SDL2Gate_SDL_strtoul(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strtoul;

Sint64
SDL2Gate_SDL_strtoll(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strtoll;

Uint64
SDL2Gate_SDL_strtoull(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strtoull;

double
SDL2Gate_SDL_strtod(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strtod;

int
SDL2Gate_SDL_strcmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strcmp;

int
SDL2Gate_SDL_strncmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strncmp;

int
SDL2Gate_SDL_strcasecmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strcasecmp;

int
SDL2Gate_SDL_strncasecmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strncasecmp;

double
SDL2Gate_SDL_acos(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_acos;

double
SDL2Gate_SDL_asin(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_asin;

double
SDL2Gate_SDL_atan(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_atan;

double
SDL2Gate_SDL_atan2(struct SDL2IFace* _iface,
     double ___a,
     double ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_atan2;

double
SDL2Gate_SDL_ceil(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ceil;

double
SDL2Gate_SDL_copysign(struct SDL2IFace* _iface,
     double ___a,
     double ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_copysign;

double
SDL2Gate_SDL_cos(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_cos;

float
SDL2Gate_SDL_cosf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_cosf;

double
SDL2Gate_SDL_fabs(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_fabs;

double
SDL2Gate_SDL_floor(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_floor;

double
SDL2Gate_SDL_log(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_log;

double
SDL2Gate_SDL_pow(struct SDL2IFace* _iface,
     double ___a,
     double ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_pow;

double
SDL2Gate_SDL_scalbn(struct SDL2IFace* _iface,
     double ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_scalbn;

double
SDL2Gate_SDL_sin(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_sin;

float
SDL2Gate_SDL_sinf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_sinf;

double
SDL2Gate_SDL_sqrt(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_sqrt;

SDL_iconv_t
SDL2Gate_SDL_iconv_open(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_iconv_open;

int
SDL2Gate_SDL_iconv_close(struct SDL2IFace* _iface,
     SDL_iconv_t ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_iconv_close;

size_t
SDL2Gate_SDL_iconv(struct SDL2IFace* _iface,
     SDL_iconv_t ___a,
     const char * * ___b,
     size_t * ___c,
     char * * ___d,
     size_t * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_iconv;

char*
SDL2Gate_SDL_iconv_string(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     const char * ___c,
     size_t ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_iconv_string;

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurface(struct SDL2IFace* _iface,
     Uint32 ___a,
     int ___b,
     int ___c,
     int ___d,
     Uint32 ___e,
     Uint32 ___f,
     Uint32 ___g,
     Uint32 ___h);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurface;

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurfaceFrom(struct SDL2IFace* _iface,
     void * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e,
     Uint32 ___f,
     Uint32 ___g,
     Uint32 ___h,
     Uint32 ___i);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurfaceFrom;

void
SDL2Gate_SDL_FreeSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreeSurface;

int
SDL2Gate_SDL_SetSurfacePalette(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Palette * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfacePalette;

int
SDL2Gate_SDL_LockSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockSurface;

void
SDL2Gate_SDL_UnlockSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockSurface;

SDL_Surface*
SDL2Gate_SDL_LoadBMP_RW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadBMP_RW;

int
SDL2Gate_SDL_SaveBMP_RW(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_RWops * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SaveBMP_RW;

int
SDL2Gate_SDL_SetSurfaceRLE(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceRLE;

int
SDL2Gate_SDL_SetColorKey(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     int ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetColorKey;

int
SDL2Gate_SDL_GetColorKey(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint32 * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetColorKey;

int
SDL2Gate_SDL_SetSurfaceColorMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceColorMod;

int
SDL2Gate_SDL_GetSurfaceColorMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 * ___b,
     Uint8 * ___c,
     Uint8 * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetSurfaceColorMod;

int
SDL2Gate_SDL_SetSurfaceAlphaMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceAlphaMod;

int
SDL2Gate_SDL_GetSurfaceAlphaMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetSurfaceAlphaMod;

int
SDL2Gate_SDL_SetSurfaceBlendMode(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_BlendMode ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceBlendMode;

int
SDL2Gate_SDL_GetSurfaceBlendMode(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_BlendMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetSurfaceBlendMode;

SDL_bool
SDL2Gate_SDL_SetClipRect(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetClipRect;

void
SDL2Gate_SDL_GetClipRect(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetClipRect;

SDL_Surface*
SDL2Gate_SDL_ConvertSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_PixelFormat * ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertSurface;

SDL_Surface*
SDL2Gate_SDL_ConvertSurfaceFormat(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint32 ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertSurfaceFormat;

int
SDL2Gate_SDL_ConvertPixels(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     Uint32 ___c,
     const void * ___d,
     int ___e,
     Uint32 ___f,
     void * ___g,
     int ___h);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertPixels;

int
SDL2Gate_SDL_FillRect(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FillRect;

int
SDL2Gate_SDL_FillRects(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     int ___c,
     Uint32 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FillRects;

int
SDL2Gate_SDL_UpperBlit(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpperBlit;

int
SDL2Gate_SDL_LowerBlit(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LowerBlit;

int
SDL2Gate_SDL_SoftStretch(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     const SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SoftStretch;

int
SDL2Gate_SDL_UpperBlitScaled(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpperBlitScaled;

int
SDL2Gate_SDL_LowerBlitScaled(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LowerBlitScaled;

SDL_bool
SDL2Gate_SDL_GetWindowWMInfo(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_SysWMinfo * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowWMInfo;

const char*
SDL2Gate_SDL_GetThreadName(struct SDL2IFace* _iface,
     SDL_Thread * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetThreadName;

SDL_threadID
SDL2Gate_SDL_ThreadID(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ThreadID;

SDL_threadID
SDL2Gate_SDL_GetThreadID(struct SDL2IFace* _iface,
     SDL_Thread * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetThreadID;

int
SDL2Gate_SDL_SetThreadPriority(struct SDL2IFace* _iface,
     SDL_ThreadPriority ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetThreadPriority;

void
SDL2Gate_SDL_WaitThread(struct SDL2IFace* _iface,
     SDL_Thread * ___a,
     int * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WaitThread;

void
SDL2Gate_SDL_DetachThread(struct SDL2IFace* _iface,
     SDL_Thread * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DetachThread;

SDL_TLSID
SDL2Gate_SDL_TLSCreate(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_TLSCreate;

void*
SDL2Gate_SDL_TLSGet(struct SDL2IFace* _iface,
     SDL_TLSID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_TLSGet;

int
SDL2Gate_SDL_TLSSet(struct SDL2IFace* _iface,
     SDL_TLSID ___a,
     const void * ___b,
     SDL_TLSDestructorCallback ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_TLSSet;

Uint32
SDL2Gate_SDL_GetTicks(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTicks;

Uint64
SDL2Gate_SDL_GetPerformanceCounter(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPerformanceCounter;

Uint64
SDL2Gate_SDL_GetPerformanceFrequency(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPerformanceFrequency;

void
SDL2Gate_SDL_Delay(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Delay;

SDL_TimerID
SDL2Gate_SDL_AddTimer(struct SDL2IFace* _iface,
     Uint32 ___a,
     SDL_TimerCallback ___b,
     void * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AddTimer;

SDL_bool
SDL2Gate_SDL_RemoveTimer(struct SDL2IFace* _iface,
     SDL_TimerID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RemoveTimer;

int
SDL2Gate_SDL_GetNumTouchDevices(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumTouchDevices;

SDL_TouchID
SDL2Gate_SDL_GetTouchDevice(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchDevice;

int
SDL2Gate_SDL_GetNumTouchFingers(struct SDL2IFace* _iface,
     SDL_TouchID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumTouchFingers;

SDL_Finger*
SDL2Gate_SDL_GetTouchFinger(struct SDL2IFace* _iface,
     SDL_TouchID ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchFinger;

void
SDL2Gate_SDL_GetVersion(struct SDL2IFace* _iface,
     SDL_version * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetVersion;

const char*
SDL2Gate_SDL_GetRevision(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRevision;

int
SDL2Gate_SDL_GetRevisionNumber(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRevisionNumber;

int
SDL2Gate_SDL_GetNumVideoDrivers(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumVideoDrivers;

const char*
SDL2Gate_SDL_GetVideoDriver(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetVideoDriver;

int
SDL2Gate_SDL_VideoInit(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_VideoInit;

void
SDL2Gate_SDL_VideoQuit(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_VideoQuit;

const char*
SDL2Gate_SDL_GetCurrentVideoDriver(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetCurrentVideoDriver;

int
SDL2Gate_SDL_GetNumVideoDisplays(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumVideoDisplays;

const char*
SDL2Gate_SDL_GetDisplayName(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayName;

int
SDL2Gate_SDL_GetDisplayBounds(struct SDL2IFace* _iface,
     int ___a,
     SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayBounds;

int
SDL2Gate_SDL_GetNumDisplayModes(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumDisplayModes;

int
SDL2Gate_SDL_GetDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     SDL_DisplayMode * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayMode;

int
SDL2Gate_SDL_GetDesktopDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     SDL_DisplayMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDesktopDisplayMode;

int
SDL2Gate_SDL_GetCurrentDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     SDL_DisplayMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetCurrentDisplayMode;

SDL_DisplayMode*
SDL2Gate_SDL_GetClosestDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     const SDL_DisplayMode * ___b,
     SDL_DisplayMode * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetClosestDisplayMode;

int
SDL2Gate_SDL_GetWindowDisplayIndex(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowDisplayIndex;

int
SDL2Gate_SDL_SetWindowDisplayMode(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const SDL_DisplayMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowDisplayMode;

int
SDL2Gate_SDL_GetWindowDisplayMode(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_DisplayMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowDisplayMode;

Uint32
SDL2Gate_SDL_GetWindowPixelFormat(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowPixelFormat;

SDL_Window*
SDL2Gate_SDL_CreateWindow(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e,
     Uint32 ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateWindow;

SDL_Window*
SDL2Gate_SDL_CreateWindowFrom(struct SDL2IFace* _iface,
     const void * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateWindowFrom;

Uint32
SDL2Gate_SDL_GetWindowID(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowID;

SDL_Window*
SDL2Gate_SDL_GetWindowFromID(struct SDL2IFace* _iface,
     Uint32 ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowFromID;

Uint32
SDL2Gate_SDL_GetWindowFlags(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowFlags;

void
SDL2Gate_SDL_SetWindowTitle(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowTitle;

const char*
SDL2Gate_SDL_GetWindowTitle(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowTitle;

void
SDL2Gate_SDL_SetWindowIcon(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_Surface * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowIcon;

void*
SDL2Gate_SDL_SetWindowData(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const char * ___b,
     void * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowData;

void*
SDL2Gate_SDL_GetWindowData(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowData;

void
SDL2Gate_SDL_SetWindowPosition(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowPosition;

void
SDL2Gate_SDL_GetWindowPosition(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowPosition;

void
SDL2Gate_SDL_SetWindowSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowSize;

void
SDL2Gate_SDL_GetWindowSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowSize;

void
SDL2Gate_SDL_SetWindowMinimumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMinimumSize;

void
SDL2Gate_SDL_GetWindowMinimumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMinimumSize;

void
SDL2Gate_SDL_SetWindowMaximumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMaximumSize;

void
SDL2Gate_SDL_GetWindowMaximumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMaximumSize;

void
SDL2Gate_SDL_SetWindowBordered(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowBordered;

void
SDL2Gate_SDL_ShowWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ShowWindow;

void
SDL2Gate_SDL_HideWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HideWindow;

void
SDL2Gate_SDL_RaiseWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RaiseWindow;

void
SDL2Gate_SDL_MaximizeWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MaximizeWindow;

void
SDL2Gate_SDL_MinimizeWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MinimizeWindow;

void
SDL2Gate_SDL_RestoreWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RestoreWindow;

int
SDL2Gate_SDL_SetWindowFullscreen(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     Uint32 ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowFullscreen;

SDL_Surface*
SDL2Gate_SDL_GetWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowSurface;

int
SDL2Gate_SDL_UpdateWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateWindowSurface;

int
SDL2Gate_SDL_UpdateWindowSurfaceRects(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const SDL_Rect * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateWindowSurfaceRects;

void
SDL2Gate_SDL_SetWindowGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowGrab;

SDL_bool
SDL2Gate_SDL_GetWindowGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowGrab;

int
SDL2Gate_SDL_SetWindowBrightness(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     float ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowBrightness;

float
SDL2Gate_SDL_GetWindowBrightness(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowBrightness;

int
SDL2Gate_SDL_SetWindowGammaRamp(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const Uint16 * ___b,
     const Uint16 * ___c,
     const Uint16 * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowGammaRamp;

int
SDL2Gate_SDL_GetWindowGammaRamp(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     Uint16 * ___b,
     Uint16 * ___c,
     Uint16 * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowGammaRamp;

void
SDL2Gate_SDL_DestroyWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyWindow;

SDL_bool
SDL2Gate_SDL_IsScreenSaverEnabled(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsScreenSaverEnabled;

void
SDL2Gate_SDL_EnableScreenSaver(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_EnableScreenSaver;

void
SDL2Gate_SDL_DisableScreenSaver(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DisableScreenSaver;

int
SDL2Gate_SDL_GL_LoadLibrary(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_LoadLibrary;

void*
SDL2Gate_SDL_GL_GetProcAddress(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetProcAddress;

void
SDL2Gate_SDL_GL_UnloadLibrary(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_UnloadLibrary;

SDL_bool
SDL2Gate_SDL_GL_ExtensionSupported(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_ExtensionSupported;

int
SDL2Gate_SDL_GL_SetAttribute(struct SDL2IFace* _iface,
     SDL_GLattr ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_SetAttribute;

int
SDL2Gate_SDL_GL_GetAttribute(struct SDL2IFace* _iface,
     SDL_GLattr ___a,
     int * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetAttribute;

SDL_GLContext
SDL2Gate_SDL_GL_CreateContext(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_CreateContext;

int
SDL2Gate_SDL_GL_MakeCurrent(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_GLContext ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_MakeCurrent;

SDL_Window*
SDL2Gate_SDL_GL_GetCurrentWindow(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetCurrentWindow;

SDL_GLContext
SDL2Gate_SDL_GL_GetCurrentContext(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetCurrentContext;

void
SDL2Gate_SDL_GL_GetDrawableSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetDrawableSize;

int
SDL2Gate_SDL_GL_SetSwapInterval(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_SetSwapInterval;

int
SDL2Gate_SDL_GL_GetSwapInterval(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetSwapInterval;

void
SDL2Gate_SDL_GL_SwapWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_SwapWindow;

void
SDL2Gate_SDL_GL_DeleteContext(struct SDL2IFace* _iface,
     SDL_GLContext ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_DeleteContext;

int
SDL2Gate_SDL_GameControllerAddMappingsFromRW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerAddMappingsFromRW;

void
SDL2Gate_SDL_GL_ResetAttributes(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GL_ResetAttributes;

SDL_bool
SDL2Gate_SDL_HasAVX(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasAVX;

SDL_AssertionHandler
SDL2Gate_SDL_GetDefaultAssertionHandler(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDefaultAssertionHandler;

SDL_AssertionHandler
SDL2Gate_SDL_GetAssertionHandler(struct SDL2IFace* _iface,
     void * * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetAssertionHandler;

SDL_bool
SDL2Gate_SDL_RenderIsClipEnabled(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderIsClipEnabled;

int
SDL2Gate_SDL_WarpMouseGlobal(struct SDL2IFace* _iface,
     int ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_WarpMouseGlobal;

float
SDL2Gate_SDL_sqrtf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_sqrtf;

double
SDL2Gate_SDL_tan(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_tan;

float
SDL2Gate_SDL_tanf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_tanf;

int
SDL2Gate_SDL_CaptureMouse(struct SDL2IFace* _iface,
     SDL_bool ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CaptureMouse;

int
SDL2Gate_SDL_SetWindowHitTest(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_HitTest ___b,
     void * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowHitTest;

Uint32
SDL2Gate_SDL_GetGlobalMouseState(struct SDL2IFace* _iface,
     int * ___a,
     int * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetGlobalMouseState;

SDL_bool
SDL2Gate_SDL_HasAVX2(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasAVX2;

int
SDL2Gate_SDL_QueueAudio(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a,
     const void * ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_QueueAudio;

Uint32
SDL2Gate_SDL_GetQueuedAudioSize(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetQueuedAudioSize;

void
SDL2Gate_SDL_ClearQueuedAudio(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ClearQueuedAudio;

SDL_Window*
SDL2Gate_SDL_GetGrabbedWindow(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetGrabbedWindow;

int
SDL2Gate_SDL_GetDisplayDPI(struct SDL2IFace* _iface,
     int ___a,
     float * ___b,
     float * ___c,
     float * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayDPI;

SDL_JoystickPowerLevel
SDL2Gate_SDL_JoystickCurrentPowerLevel(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickCurrentPowerLevel;

SDL_GameController*
SDL2Gate_SDL_GameControllerFromInstanceID(struct SDL2IFace* _iface,
     SDL_JoystickID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerFromInstanceID;

SDL_Joystick*
SDL2Gate_SDL_JoystickFromInstanceID(struct SDL2IFace* _iface,
     SDL_JoystickID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickFromInstanceID;

int
SDL2Gate_SDL_GetDisplayUsableBounds(struct SDL2IFace* _iface,
     int ___a,
     SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayUsableBounds;

int
SDL2Gate_SDL_GetWindowBordersSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c,
     int * ___d,
     int * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowBordersSize;

int
SDL2Gate_SDL_SetWindowOpacity(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     float ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowOpacity;

int
SDL2Gate_SDL_GetWindowOpacity(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     float * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowOpacity;

int
SDL2Gate_SDL_SetWindowInputFocus(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowInputFocus;

int
SDL2Gate_SDL_SetWindowModalFor(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_Window * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowModalFor;

int
SDL2Gate_SDL_RenderSetIntegerScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetIntegerScale;

SDL_bool
SDL2Gate_SDL_RenderGetIntegerScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetIntegerScale;

Uint32
SDL2Gate_SDL_DequeueAudio(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a,
     void * ___b,
     Uint32 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DequeueAudio;

void
SDL2Gate_SDL_SetWindowResizable(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowResizable;

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurfaceWithFormat(struct SDL2IFace* _iface,
     Uint32 ___a,
     int ___b,
     int ___c,
     int ___d,
     Uint32 ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurfaceWithFormat;

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurfaceWithFormatFrom(struct SDL2IFace* _iface,
     void * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e,
     Uint32 ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurfaceWithFormatFrom;

SDL_bool
SDL2Gate_SDL_GetHintBoolean(struct SDL2IFace* _iface,
     const char * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetHintBoolean;

Uint16
SDL2Gate_SDL_JoystickGetDeviceVendor(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceVendor;

Uint16
SDL2Gate_SDL_JoystickGetDeviceProduct(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceProduct;

Uint16
SDL2Gate_SDL_JoystickGetDeviceProductVersion(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceProductVersion;

Uint16
SDL2Gate_SDL_JoystickGetVendor(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetVendor;

Uint16
SDL2Gate_SDL_JoystickGetProduct(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetProduct;

Uint16
SDL2Gate_SDL_JoystickGetProductVersion(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetProductVersion;

Uint16
SDL2Gate_SDL_GameControllerGetVendor(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetVendor;

Uint16
SDL2Gate_SDL_GameControllerGetProduct(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetProduct;

Uint16
SDL2Gate_SDL_GameControllerGetProductVersion(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetProductVersion;

SDL_bool
SDL2Gate_SDL_HasNEON(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasNEON;

int
SDL2Gate_SDL_GameControllerNumMappings(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerNumMappings;

char*
SDL2Gate_SDL_GameControllerMappingForIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerMappingForIndex;

SDL_bool
SDL2Gate_SDL_JoystickGetAxisInitialState(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Sint16 * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetAxisInitialState;

SDL_JoystickType
SDL2Gate_SDL_JoystickGetDeviceType(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceType;

SDL_JoystickType
SDL2Gate_SDL_JoystickGetType(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetType;

void
SDL2Gate_SDL_MemoryBarrierReleaseFunction(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MemoryBarrierReleaseFunction;

void
SDL2Gate_SDL_MemoryBarrierAcquireFunction(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_MemoryBarrierAcquireFunction;

SDL_JoystickID
SDL2Gate_SDL_JoystickGetDeviceInstanceID(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceInstanceID;

size_t
SDL2Gate_SDL_utf8strlen(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_utf8strlen;

void*
SDL2Gate_SDL_LoadFile_RW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     size_t * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadFile_RW;

int
SDL2Gate_SDL_wcscmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcscmp;

SDL_BlendMode
SDL2Gate_SDL_ComposeCustomBlendMode(struct SDL2IFace* _iface,
     SDL_BlendFactor ___a,
     SDL_BlendFactor ___b,
     SDL_BlendOperation ___c,
     SDL_BlendFactor ___d,
     SDL_BlendFactor ___e,
     SDL_BlendOperation ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ComposeCustomBlendMode;

SDL_Surface*
SDL2Gate_SDL_DuplicateSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DuplicateSurface;

void
SDL2Gate_SDL_LockJoysticks(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockJoysticks;

void
SDL2Gate_SDL_UnlockJoysticks(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockJoysticks;

void
SDL2Gate_SDL_GetMemoryFunctions(struct SDL2IFace* _iface,
     SDL_malloc_func * ___a,
     SDL_calloc_func * ___b,
     SDL_realloc_func * ___c,
     SDL_free_func * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetMemoryFunctions;

int
SDL2Gate_SDL_SetMemoryFunctions(struct SDL2IFace* _iface,
     SDL_malloc_func ___a,
     SDL_calloc_func ___b,
     SDL_realloc_func ___c,
     SDL_free_func ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetMemoryFunctions;

int
SDL2Gate_SDL_GetNumAllocations(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumAllocations;

SDL_AudioStream*
SDL2Gate_SDL_NewAudioStream(struct SDL2IFace* _iface,
     const SDL_AudioFormat ___a,
     const Uint8 ___b,
     const int ___c,
     const SDL_AudioFormat ___d,
     const Uint8 ___e,
     const int ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_NewAudioStream;

int
SDL2Gate_SDL_AudioStreamPut(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a,
     const void * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamPut;

int
SDL2Gate_SDL_AudioStreamGet(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a,
     void * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamGet;

void
SDL2Gate_SDL_AudioStreamClear(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamClear;

int
SDL2Gate_SDL_AudioStreamAvailable(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamAvailable;

void
SDL2Gate_SDL_FreeAudioStream(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FreeAudioStream;

int
SDL2Gate_SDL_AudioStreamFlush(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamFlush;

float
SDL2Gate_SDL_acosf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_acosf;

float
SDL2Gate_SDL_asinf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_asinf;

float
SDL2Gate_SDL_atanf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_atanf;

float
SDL2Gate_SDL_atan2f(struct SDL2IFace* _iface,
     float ___a,
     float ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_atan2f;

float
SDL2Gate_SDL_ceilf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ceilf;

float
SDL2Gate_SDL_copysignf(struct SDL2IFace* _iface,
     float ___a,
     float ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_copysignf;

float
SDL2Gate_SDL_fabsf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_fabsf;

float
SDL2Gate_SDL_floorf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_floorf;

float
SDL2Gate_SDL_logf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_logf;

float
SDL2Gate_SDL_powf(struct SDL2IFace* _iface,
     float ___a,
     float ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_powf;

float
SDL2Gate_SDL_scalbnf(struct SDL2IFace* _iface,
     float ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_scalbnf;

double
SDL2Gate_SDL_fmod(struct SDL2IFace* _iface,
     double ___a,
     double ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_fmod;

float
SDL2Gate_SDL_fmodf(struct SDL2IFace* _iface,
     float ___a,
     float ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_fmodf;

void
SDL2Gate_SDL_SetYUVConversionMode(struct SDL2IFace* _iface,
     SDL_YUV_CONVERSION_MODE ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetYUVConversionMode;

SDL_YUV_CONVERSION_MODE
SDL2Gate_SDL_GetYUVConversionMode(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetYUVConversionMode;

SDL_YUV_CONVERSION_MODE
SDL2Gate_SDL_GetYUVConversionModeForResolution(struct SDL2IFace* _iface,
     int ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetYUVConversionModeForResolution;

void*
SDL2Gate_SDL_RenderGetMetalLayer(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetMetalLayer;

void*
SDL2Gate_SDL_RenderGetMetalCommandEncoder(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetMetalCommandEncoder;

double
SDL2Gate_SDL_log10(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_log10;

float
SDL2Gate_SDL_log10f(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_log10f;

char*
SDL2Gate_SDL_GameControllerMappingForDeviceIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerMappingForDeviceIndex;

SDL_bool
SDL2Gate_SDL_HasAVX512F(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasAVX512F;

double
SDL2Gate_SDL_exp(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_exp;

float
SDL2Gate_SDL_expf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_expf;

wchar_t*
SDL2Gate_SDL_wcsdup(struct SDL2IFace* _iface,
     const wchar_t * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcsdup;

int
SDL2Gate_SDL_GameControllerRumble(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerRumble;

int
SDL2Gate_SDL_JoystickRumble(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickRumble;

int
SDL2Gate_SDL_NumSensors(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_NumSensors;

const char*
SDL2Gate_SDL_SensorGetDeviceName(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceName;

SDL_SensorType
SDL2Gate_SDL_SensorGetDeviceType(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceType;

int
SDL2Gate_SDL_SensorGetDeviceNonPortableType(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceNonPortableType;

SDL_SensorID
SDL2Gate_SDL_SensorGetDeviceInstanceID(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceInstanceID;

SDL_Sensor*
SDL2Gate_SDL_SensorOpen(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorOpen;

SDL_Sensor*
SDL2Gate_SDL_SensorFromInstanceID(struct SDL2IFace* _iface,
     SDL_SensorID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorFromInstanceID;

const char*
SDL2Gate_SDL_SensorGetName(struct SDL2IFace* _iface,
     SDL_Sensor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetName;

SDL_SensorType
SDL2Gate_SDL_SensorGetType(struct SDL2IFace* _iface,
     SDL_Sensor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetType;

int
SDL2Gate_SDL_SensorGetNonPortableType(struct SDL2IFace* _iface,
     SDL_Sensor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetNonPortableType;

SDL_SensorID
SDL2Gate_SDL_SensorGetInstanceID(struct SDL2IFace* _iface,
     SDL_Sensor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetInstanceID;

int
SDL2Gate_SDL_SensorGetData(struct SDL2IFace* _iface,
     SDL_Sensor * ___a,
     float * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetData;

void
SDL2Gate_SDL_SensorClose(struct SDL2IFace* _iface,
     SDL_Sensor * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorClose;

void
SDL2Gate_SDL_SensorUpdate(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorUpdate;

SDL_bool
SDL2Gate_SDL_IsTablet(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsTablet;

SDL_DisplayOrientation
SDL2Gate_SDL_GetDisplayOrientation(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayOrientation;

SDL_bool
SDL2Gate_SDL_HasColorKey(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasColorKey;

int
SDL2Gate_SDL_JoystickGetDevicePlayerIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDevicePlayerIndex;

int
SDL2Gate_SDL_JoystickGetPlayerIndex(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetPlayerIndex;

int
SDL2Gate_SDL_GameControllerGetPlayerIndex(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetPlayerIndex;

int
SDL2Gate_SDL_RenderFlush(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFlush;

int
SDL2Gate_SDL_RenderDrawPointF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPointF;

int
SDL2Gate_SDL_RenderDrawPointsF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FPoint * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPointsF;

int
SDL2Gate_SDL_RenderDrawLineF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c,
     float ___d,
     float ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLineF;

int
SDL2Gate_SDL_RenderDrawLinesF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FPoint * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLinesF;

int
SDL2Gate_SDL_RenderDrawRectF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRectF;

int
SDL2Gate_SDL_RenderDrawRectsF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRectsF;

int
SDL2Gate_SDL_RenderFillRectF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRectF;

int
SDL2Gate_SDL_RenderFillRectsF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRectsF;

int
SDL2Gate_SDL_RenderCopyF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_FRect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopyF;

int
SDL2Gate_SDL_RenderCopyExF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_FRect * ___d,
     const double ___e,
     const SDL_FPoint * ___f,
     const SDL_RendererFlip ___g);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopyExF;

SDL_TouchDeviceType
SDL2Gate_SDL_GetTouchDeviceType(struct SDL2IFace* _iface,
     SDL_TouchID ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchDeviceType;

size_t
SDL2Gate_SDL_SIMDGetAlignment(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDGetAlignment;

void*
SDL2Gate_SDL_SIMDAlloc(struct SDL2IFace* _iface,
     const size_t ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDAlloc;

void
SDL2Gate_SDL_SIMDFree(struct SDL2IFace* _iface,
     void * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDFree;

Sint64
SDL2Gate_SDL_RWsize(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWsize;

Sint64
SDL2Gate_SDL_RWseek(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Sint64 ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWseek;

Sint64
SDL2Gate_SDL_RWtell(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWtell;

size_t
SDL2Gate_SDL_RWread(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     void * ___b,
     size_t ___c,
     size_t ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWread;

size_t
SDL2Gate_SDL_RWwrite(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     const void * ___b,
     size_t ___c,
     size_t ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWwrite;

int
SDL2Gate_SDL_RWclose(struct SDL2IFace* _iface,
     SDL_RWops * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RWclose;

void*
SDL2Gate_SDL_LoadFile(struct SDL2IFace* _iface,
     const char * ___a,
     size_t * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LoadFile;

SDL_MetalView
SDL2Gate_SDL_Metal_CreateView(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_CreateView;

void
SDL2Gate_SDL_Metal_DestroyView(struct SDL2IFace* _iface,
     SDL_MetalView ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_DestroyView;

int
SDL2Gate_SDL_LockTextureToSurface(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockTextureToSurface;

SDL_bool
SDL2Gate_SDL_HasARMSIMD(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasARMSIMD;

char*
SDL2Gate_SDL_strtokr(struct SDL2IFace* _iface,
     char * ___a,
     const char * ___b,
     char * * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strtokr;

wchar_t*
SDL2Gate_SDL_wcsstr(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcsstr;

int
SDL2Gate_SDL_wcsncmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcsncmp;

SDL_GameControllerType
SDL2Gate_SDL_GameControllerTypeForIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerTypeForIndex;

SDL_GameControllerType
SDL2Gate_SDL_GameControllerGetType(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetType;

SDL_GameController*
SDL2Gate_SDL_GameControllerFromPlayerIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerFromPlayerIndex;

void
SDL2Gate_SDL_GameControllerSetPlayerIndex(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSetPlayerIndex;

SDL_Joystick*
SDL2Gate_SDL_JoystickFromPlayerIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickFromPlayerIndex;

void
SDL2Gate_SDL_JoystickSetPlayerIndex(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetPlayerIndex;

int
SDL2Gate_SDL_SetTextureScaleMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_ScaleMode ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureScaleMode;

int
SDL2Gate_SDL_GetTextureScaleMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_ScaleMode * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureScaleMode;

void
SDL2Gate_SDL_OnApplicationWillTerminate(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationWillTerminate;

void
SDL2Gate_SDL_OnApplicationDidReceiveMemoryWarning(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationDidReceiveMemoryWarning;

void
SDL2Gate_SDL_OnApplicationWillResignActive(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationWillResignActive;

void
SDL2Gate_SDL_OnApplicationDidEnterBackground(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationDidEnterBackground;

void
SDL2Gate_SDL_OnApplicationWillEnterForeground(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationWillEnterForeground;

void
SDL2Gate_SDL_OnApplicationDidBecomeActive(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationDidBecomeActive;

int
SDL2Gate_SDL_isupper(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isupper;

int
SDL2Gate_SDL_islower(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_islower;

int
SDL2Gate_SDL_JoystickAttachVirtual(struct SDL2IFace* _iface,
     SDL_JoystickType ___a,
     int ___b,
     int ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickAttachVirtual;

int
SDL2Gate_SDL_JoystickDetachVirtual(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickDetachVirtual;

SDL_bool
SDL2Gate_SDL_JoystickIsVirtual(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickIsVirtual;

int
SDL2Gate_SDL_JoystickSetVirtualAxis(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Sint16 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetVirtualAxis;

int
SDL2Gate_SDL_JoystickSetVirtualButton(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Uint8 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetVirtualButton;

int
SDL2Gate_SDL_JoystickSetVirtualHat(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Uint8 ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetVirtualHat;

char*
SDL2Gate_SDL_GetErrorMsg(struct SDL2IFace* _iface,
     char * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetErrorMsg;

void
SDL2Gate_SDL_LockSensors(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_LockSensors;

void
SDL2Gate_SDL_UnlockSensors(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockSensors;

void*
SDL2Gate_SDL_Metal_GetLayer(struct SDL2IFace* _iface,
     SDL_MetalView ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_GetLayer;

void
SDL2Gate_SDL_Metal_GetDrawableSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_GetDrawableSize;

double
SDL2Gate_SDL_trunc(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_trunc;

float
SDL2Gate_SDL_truncf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_truncf;

SDL_Locale *
SDL2Gate_SDL_GetPreferredLocales(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPreferredLocales;

void*
SDL2Gate_SDL_SIMDRealloc(struct SDL2IFace* _iface,
     void * ___a,
     const size_t ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDRealloc;

int
SDL2Gate_SDL_OpenURL(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_OpenURL;

SDL_bool
SDL2Gate_SDL_HasSurfaceRLE(struct SDL2IFace* _iface,
     SDL_Surface * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasSurfaceRLE;

SDL_bool
SDL2Gate_SDL_GameControllerHasLED(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasLED;

int
SDL2Gate_SDL_GameControllerSetLED(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSetLED;

SDL_bool
SDL2Gate_SDL_JoystickHasLED(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickHasLED;

int
SDL2Gate_SDL_JoystickSetLED(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetLED;

int
SDL2Gate_SDL_GameControllerRumbleTriggers(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerRumbleTriggers;

int
SDL2Gate_SDL_JoystickRumbleTriggers(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickRumbleTriggers;

SDL_bool
SDL2Gate_SDL_GameControllerHasAxis(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerAxis ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasAxis;

SDL_bool
SDL2Gate_SDL_GameControllerHasButton(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerButton ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasButton;

int
SDL2Gate_SDL_GameControllerGetNumTouchpads(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetNumTouchpads;

int
SDL2Gate_SDL_GameControllerGetNumTouchpadFingers(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetNumTouchpadFingers;

int
SDL2Gate_SDL_GameControllerGetTouchpadFinger(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     int ___b,
     int ___c,
     Uint8 * ___d,
     float * ___e,
     float * ___f,
     float * ___g);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetTouchpadFinger;

Uint32
SDL2Gate_SDL_crc32(struct SDL2IFace* _iface,
     Uint32 ___a,
     const void * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_crc32;

const char*
SDL2Gate_SDL_GameControllerGetSerial(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSerial;

const char*
SDL2Gate_SDL_JoystickGetSerial(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetSerial;

SDL_bool
SDL2Gate_SDL_GameControllerHasSensor(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasSensor;

int
SDL2Gate_SDL_GameControllerSetSensorEnabled(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b,
     SDL_bool ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSetSensorEnabled;

SDL_bool
SDL2Gate_SDL_GameControllerIsSensorEnabled(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerIsSensorEnabled;

int
SDL2Gate_SDL_GameControllerGetSensorData(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b,
     float * ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSensorData;

int
SDL2Gate_SDL_wcscasecmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcscasecmp;

int
SDL2Gate_SDL_wcsncasecmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_wcsncasecmp;

double
SDL2Gate_SDL_round(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_round;

float
SDL2Gate_SDL_roundf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_roundf;

long
SDL2Gate_SDL_lround(struct SDL2IFace* _iface,
     double ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_lround;

long
SDL2Gate_SDL_lroundf(struct SDL2IFace* _iface,
     float ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_lroundf;

int
SDL2Gate_SDL_SoftStretchLinear(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     const SDL_Rect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SoftStretchLinear;

int
SDL2Gate_SDL_UpdateNVTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     const Uint8 * ___c,
     int ___d,
     const Uint8 * ___e,
     int ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateNVTexture;

void
SDL2Gate_SDL_SetWindowKeyboardGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowKeyboardGrab;

void
SDL2Gate_SDL_SetWindowMouseGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMouseGrab;

SDL_bool
SDL2Gate_SDL_GetWindowKeyboardGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowKeyboardGrab;

SDL_bool
SDL2Gate_SDL_GetWindowMouseGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMouseGrab;

int
SDL2Gate_SDL_isalpha(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isalpha;

int
SDL2Gate_SDL_isalnum(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isalnum;

int
SDL2Gate_SDL_isblank(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isblank;

int
SDL2Gate_SDL_iscntrl(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_iscntrl;

int
SDL2Gate_SDL_isxdigit(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isxdigit;

int
SDL2Gate_SDL_ispunct(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ispunct;

int
SDL2Gate_SDL_isprint(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isprint;

int
SDL2Gate_SDL_isgraph(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_isgraph;

int
SDL2Gate_SDL_GetAudioDeviceSpec(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     SDL_AudioSpec * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetAudioDeviceSpec;

void
SDL2Gate_SDL_TLSCleanup(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_TLSCleanup;

void
SDL2Gate_SDL_SetWindowAlwaysOnTop(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowAlwaysOnTop;

int
SDL2Gate_SDL_FlashWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_FlashOperation ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_FlashWindow;

int
SDL2Gate_SDL_GameControllerSendEffect(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     const void * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSendEffect;

int
SDL2Gate_SDL_JoystickSendEffect(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     const void * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSendEffect;

float
SDL2Gate_SDL_GameControllerGetSensorDataRate(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSensorDataRate;

int
SDL2Gate_SDL_SetTextureUserData(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     void * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureUserData;

void*
SDL2Gate_SDL_GetTextureUserData(struct SDL2IFace* _iface,
     SDL_Texture * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureUserData;

int
SDL2Gate_SDL_RenderGeometry(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Vertex * ___c,
     int ___d,
     const int * ___e,
     int ___f);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGeometry;

int
SDL2Gate_SDL_RenderSetVSync(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetVSync;

void*
SDL2Gate_SDL_GetWindowICCProfile(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     size_t * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowICCProfile;

Uint64
SDL2Gate_SDL_GetTicks64(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTicks64;

const char*
SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForButton(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerButton ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForButton;

const char*
SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForAxis(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerAxis ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForAxis;

int
SDL2Gate_SDL_hid_init(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_init;

int
SDL2Gate_SDL_hid_exit(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_exit;

Uint32
SDL2Gate_SDL_hid_device_change_count(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_device_change_count;

SDL_hid_device_info*
SDL2Gate_SDL_hid_enumerate(struct SDL2IFace* _iface,
     unsigned short ___a,
     unsigned short ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_enumerate;

void
SDL2Gate_SDL_hid_free_enumeration(struct SDL2IFace* _iface,
     SDL_hid_device_info * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_free_enumeration;

SDL_hid_device*
SDL2Gate_SDL_hid_open(struct SDL2IFace* _iface,
     unsigned short ___a,
     unsigned short ___b,
     const wchar_t * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_open;

SDL_hid_device*
SDL2Gate_SDL_hid_open_path(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_open_path;

int
SDL2Gate_SDL_hid_write(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     const unsigned char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_write;

int
SDL2Gate_SDL_hid_read_timeout(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     unsigned char * ___b,
     size_t ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_read_timeout;

int
SDL2Gate_SDL_hid_read(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     unsigned char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_read;

int
SDL2Gate_SDL_hid_set_nonblocking(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     int ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_set_nonblocking;

int
SDL2Gate_SDL_hid_send_feature_report(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     const unsigned char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_send_feature_report;

int
SDL2Gate_SDL_hid_get_feature_report(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     unsigned char * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_feature_report;

void
SDL2Gate_SDL_hid_close(struct SDL2IFace* _iface,
     SDL_hid_device * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_close;

int
SDL2Gate_SDL_hid_get_manufacturer_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_manufacturer_string;

int
SDL2Gate_SDL_hid_get_product_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_product_string;

int
SDL2Gate_SDL_hid_get_serial_number_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     wchar_t * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_serial_number_string;

int
SDL2Gate_SDL_hid_get_indexed_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     int ___b,
     wchar_t * ___c,
     size_t ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_indexed_string;

int
SDL2Gate_SDL_SetWindowMouseRect(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const SDL_Rect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMouseRect;

const SDL_Rect*
SDL2Gate_SDL_GetWindowMouseRect(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMouseRect;

void
SDL2Gate_SDL_RenderWindowToLogical(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c,
     float * ___d,
     float * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderWindowToLogical;

void
SDL2Gate_SDL_RenderLogicalToWindow(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c,
     int * ___d,
     int * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderLogicalToWindow;

SDL_bool
SDL2Gate_SDL_JoystickHasRumble(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickHasRumble;

SDL_bool
SDL2Gate_SDL_JoystickHasRumbleTriggers(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickHasRumbleTriggers;

SDL_bool
SDL2Gate_SDL_GameControllerHasRumble(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasRumble;

SDL_bool
SDL2Gate_SDL_GameControllerHasRumbleTriggers(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasRumbleTriggers;

void
SDL2Gate_SDL_hid_ble_scan(struct SDL2IFace* _iface,
     SDL_bool ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_hid_ble_scan;

int
SDL2Gate_SDL_PremultiplyAlpha(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     Uint32 ___c,
     const void * ___d,
     int ___e,
     Uint32 ___f,
     void * ___g,
     int ___h);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_PremultiplyAlpha;

const char*
SDL2Gate_SDL_GetTouchName(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchName;

void
SDL2Gate_SDL_ClearComposition(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ClearComposition;

SDL_bool
SDL2Gate_SDL_IsTextInputShown(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IsTextInputShown;

SDL_bool
SDL2Gate_SDL_HasIntersectionF(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     const SDL_FRect * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasIntersectionF;

SDL_bool
SDL2Gate_SDL_IntersectFRect(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     const SDL_FRect * ___b,
     SDL_FRect * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectFRect;

void
SDL2Gate_SDL_UnionFRect(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     const SDL_FRect * ___b,
     SDL_FRect * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_UnionFRect;

SDL_bool
SDL2Gate_SDL_EncloseFPoints(struct SDL2IFace* _iface,
     const SDL_FPoint * ___a,
     int ___b,
     const SDL_FRect * ___c,
     SDL_FRect * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_EncloseFPoints;

SDL_bool
SDL2Gate_SDL_IntersectFRectAndLine(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     float * ___b,
     float * ___c,
     float * ___d,
     float * ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectFRectAndLine;

SDL_Window*
SDL2Gate_SDL_RenderGetWindow(struct SDL2IFace* _iface,
     SDL_Renderer * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetWindow;

void*
SDL2Gate_SDL_bsearch(struct SDL2IFace* _iface,
     const void * ___a,
     const void * ___b,
     size_t ___c,
     size_t ___d,
     SDL_CompareCallback ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_bsearch;

const char*
SDL2Gate_SDL_GameControllerPathForIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerPathForIndex;

const char*
SDL2Gate_SDL_GameControllerPath(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerPath;

const char*
SDL2Gate_SDL_JoystickPathForIndex(struct SDL2IFace* _iface,
     int ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickPathForIndex;

const char*
SDL2Gate_SDL_JoystickPath(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickPath;

int
SDL2Gate_SDL_JoystickAttachVirtualEx(struct SDL2IFace* _iface,
     const SDL_VirtualJoystickDesc * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickAttachVirtualEx;

Uint16
SDL2Gate_SDL_GameControllerGetFirmwareVersion(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetFirmwareVersion;

Uint16
SDL2Gate_SDL_JoystickGetFirmwareVersion(struct SDL2IFace* _iface,
     SDL_Joystick * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetFirmwareVersion;

SDL_bool
SDL2Gate_SDL_HasLSX(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasLSX;

SDL_bool
SDL2Gate_SDL_HasLASX(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasLASX;

size_t
SDL2Gate_SDL_utf8strnlen(struct SDL2IFace* _iface,
     const char * ___a,
     size_t ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_utf8strnlen;

void
SDL2Gate_SDL_GetOriginalMemoryFunctions(struct SDL2IFace* _iface,
     SDL_malloc_func * ___a,
     SDL_calloc_func * ___b,
     SDL_realloc_func * ___c,
     SDL_free_func * ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetOriginalMemoryFunctions;

void
SDL2Gate_SDL_ResetKeyboard(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ResetKeyboard;

int
SDL2Gate_SDL_GetDefaultAudioInfo(struct SDL2IFace* _iface,
     char * * ___a,
     SDL_AudioSpec * ___b,
     int ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetDefaultAudioInfo;

int
SDL2Gate_SDL_GetPointDisplayIndex(struct SDL2IFace* _iface,
     const SDL_Point * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPointDisplayIndex;

int
SDL2Gate_SDL_GetRectDisplayIndex(struct SDL2IFace* _iface,
     const SDL_Rect * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetRectDisplayIndex;

SDL_bool
SDL2Gate_SDL_ResetHint(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ResetHint;

Uint16
SDL2Gate_SDL_crc16(struct SDL2IFace* _iface,
     Uint16 ___a,
     const void * ___b,
     size_t ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_crc16;

void
SDL2Gate_SDL_GetWindowSizeInPixels(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowSizeInPixels;

int
SDL2Gate_SDL_SetPrimarySelectionText(struct SDL2IFace* _iface,
     const char * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SetPrimarySelectionText;

char*
SDL2Gate_SDL_GetPrimarySelectionText(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GetPrimarySelectionText;

SDL_bool
SDL2Gate_SDL_HasPrimarySelectionText(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasPrimarySelectionText;

int
SDL2Gate_SDL_GameControllerGetSensorDataWithTimestamp(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b,
     Uint64 * ___c,
     float * ___d,
     int ___e);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSensorDataWithTimestamp;

int
SDL2Gate_SDL_SensorGetDataWithTimestamp(struct SDL2IFace* _iface,
     SDL_Sensor * ___a,
     Uint64 * ___b,
     float * ___c,
     int ___d);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDataWithTimestamp;

void
SDL2Gate_SDL_ResetHints(struct SDL2IFace* _iface);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_ResetHints;

char*
SDL2Gate_SDL_strcasestr(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_strcasestr;

SDL_bool
SDL2Gate_SDL_HasWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_HasWindowSurface;

int
SDL2Gate_SDL_DestroyWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyWindowSurface;

Uint64
SDL2Gate_SDL_GameControllerGetSteamHandle(struct SDL2IFace* _iface,
     SDL_GameController * ___a);

extern CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSteamHandle;


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _GATEPROTO_SDL2_H */

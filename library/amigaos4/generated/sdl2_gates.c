/* Automatically generated gatestubs (sfdc 1.11e)! Do not edit! */

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

int SDL_Init(Uint32 ___a);

int
SDL2Gate_SDL_Init(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_Init(___a);
}

STATIC int 
SDL2Gate_SDL_InitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_Init(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Init = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_InitPPC };

int SDL_InitSubSystem(Uint32 ___a);

int
SDL2Gate_SDL_InitSubSystem(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_InitSubSystem(___a);
}

STATIC int 
SDL2Gate_SDL_InitSubSystemPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_InitSubSystem(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_InitSubSystem = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_InitSubSystemPPC };

void SDL_QuitSubSystem(Uint32 ___a);

void
SDL2Gate_SDL_QuitSubSystem(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_QuitSubSystem(___a);
}

STATIC void 
SDL2Gate_SDL_QuitSubSystemPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_QuitSubSystem(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_QuitSubSystem = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_QuitSubSystemPPC };

Uint32 SDL_WasInit(Uint32 ___a);

Uint32
SDL2Gate_SDL_WasInit(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_WasInit(___a);
}

STATIC Uint32 
SDL2Gate_SDL_WasInitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_WasInit(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WasInit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WasInitPPC };

void SDL_Quit(void);

void
SDL2Gate_SDL_Quit(struct SDL2IFace* _iface)
{
  return SDL_Quit();
}

STATIC void 
SDL2Gate_SDL_QuitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_Quit();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Quit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_QuitPPC };

SDL_AssertState SDL_ReportAssertion(SDL_AssertData * ___a, const char * ___b, const char * ___c, int ___d);

SDL_AssertState
SDL2Gate_SDL_ReportAssertion(struct SDL2IFace* _iface,
     SDL_AssertData * ___a,
     const char * ___b,
     const char * ___c,
     int ___d)
{
  return SDL_ReportAssertion(___a, ___b, ___c, ___d);
}

STATIC SDL_AssertState 
SDL2Gate_SDL_ReportAssertionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AssertData * ___a = (SDL_AssertData *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  const char * ___c = (const char *) regarray[REG68K_A2/4];
  int ___d = (int) regarray[REG68K_D0/4];

  return _iface->SDL_ReportAssertion(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReportAssertion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReportAssertionPPC };

void SDL_SetAssertionHandler(SDL_AssertionHandler ___a, void * ___b);

void
SDL2Gate_SDL_SetAssertionHandler(struct SDL2IFace* _iface,
     SDL_AssertionHandler ___a,
     void * ___b)
{
  return SDL_SetAssertionHandler(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetAssertionHandlerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AssertionHandler ___a = (SDL_AssertionHandler) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_SetAssertionHandler(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetAssertionHandler = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetAssertionHandlerPPC };

const SDL_AssertData* SDL_GetAssertionReport(void);

const SDL_AssertData*
SDL2Gate_SDL_GetAssertionReport(struct SDL2IFace* _iface)
{
  return SDL_GetAssertionReport();
}

STATIC const SDL_AssertData* 
SDL2Gate_SDL_GetAssertionReportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetAssertionReport();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetAssertionReport = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetAssertionReportPPC };

void SDL_ResetAssertionReport(void);

void
SDL2Gate_SDL_ResetAssertionReport(struct SDL2IFace* _iface)
{
  return SDL_ResetAssertionReport();
}

STATIC void 
SDL2Gate_SDL_ResetAssertionReportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ResetAssertionReport();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ResetAssertionReport = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ResetAssertionReportPPC };

SDL_bool SDL_AtomicTryLock(SDL_SpinLock * ___a);

SDL_bool
SDL2Gate_SDL_AtomicTryLock(struct SDL2IFace* _iface,
     SDL_SpinLock * ___a)
{
  return SDL_AtomicTryLock(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_AtomicTryLockPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_SpinLock * ___a = (SDL_SpinLock *) regarray[REG68K_A0/4];

  return _iface->SDL_AtomicTryLock(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicTryLock = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicTryLockPPC };

void SDL_AtomicLock(SDL_SpinLock * ___a);

void
SDL2Gate_SDL_AtomicLock(struct SDL2IFace* _iface,
     SDL_SpinLock * ___a)
{
  return SDL_AtomicLock(___a);
}

STATIC void 
SDL2Gate_SDL_AtomicLockPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_SpinLock * ___a = (SDL_SpinLock *) regarray[REG68K_A0/4];

  return _iface->SDL_AtomicLock(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicLock = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicLockPPC };

void SDL_AtomicUnlock(SDL_SpinLock * ___a);

void
SDL2Gate_SDL_AtomicUnlock(struct SDL2IFace* _iface,
     SDL_SpinLock * ___a)
{
  return SDL_AtomicUnlock(___a);
}

STATIC void 
SDL2Gate_SDL_AtomicUnlockPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_SpinLock * ___a = (SDL_SpinLock *) regarray[REG68K_A0/4];

  return _iface->SDL_AtomicUnlock(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicUnlock = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicUnlockPPC };

SDL_bool SDL_AtomicCAS(SDL_atomic_t * ___a, int ___b, int ___c);

SDL_bool
SDL2Gate_SDL_AtomicCAS(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a,
     int ___b,
     int ___c)
{
  return SDL_AtomicCAS(___a, ___b, ___c);
}

STATIC SDL_bool 
SDL2Gate_SDL_AtomicCASPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_atomic_t * ___a = (SDL_atomic_t *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_AtomicCAS(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicCAS = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicCASPPC };

int SDL_AtomicSet(SDL_atomic_t * ___a, int ___b);

int
SDL2Gate_SDL_AtomicSet(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a,
     int ___b)
{
  return SDL_AtomicSet(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_AtomicSetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_atomic_t * ___a = (SDL_atomic_t *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_AtomicSet(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicSet = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicSetPPC };

int SDL_AtomicGet(SDL_atomic_t * ___a);

int
SDL2Gate_SDL_AtomicGet(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a)
{
  return SDL_AtomicGet(___a);
}

STATIC int 
SDL2Gate_SDL_AtomicGetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_atomic_t * ___a = (SDL_atomic_t *) regarray[REG68K_A0/4];

  return _iface->SDL_AtomicGet(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicGet = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicGetPPC };

int SDL_AtomicAdd(SDL_atomic_t * ___a, int ___b);

int
SDL2Gate_SDL_AtomicAdd(struct SDL2IFace* _iface,
     SDL_atomic_t * ___a,
     int ___b)
{
  return SDL_AtomicAdd(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_AtomicAddPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_atomic_t * ___a = (SDL_atomic_t *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_AtomicAdd(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicAdd = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicAddPPC };

SDL_bool SDL_AtomicCASPtr(void * * ___a, void * ___b, void * ___c);

SDL_bool
SDL2Gate_SDL_AtomicCASPtr(struct SDL2IFace* _iface,
     void * * ___a,
     void * ___b,
     void * ___c)
{
  return SDL_AtomicCASPtr(___a, ___b, ___c);
}

STATIC SDL_bool 
SDL2Gate_SDL_AtomicCASPtrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * * ___a = (void * *) regarray[REG68K_A0/4];
  void * ___b = (void *) regarray[REG68K_A1/4];
  void * ___c = (void *) regarray[REG68K_A2/4];

  return _iface->SDL_AtomicCASPtr(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicCASPtr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicCASPtrPPC };

void* SDL_AtomicSetPtr(void * * ___a, void * ___b);

void*
SDL2Gate_SDL_AtomicSetPtr(struct SDL2IFace* _iface,
     void * * ___a,
     void * ___b)
{
  return SDL_AtomicSetPtr(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_AtomicSetPtrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * * ___a = (void * *) regarray[REG68K_A0/4];
  void * ___b = (void *) regarray[REG68K_A1/4];

  return _iface->SDL_AtomicSetPtr(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicSetPtr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicSetPtrPPC };

void* SDL_AtomicGetPtr(void * * ___a);

void*
SDL2Gate_SDL_AtomicGetPtr(struct SDL2IFace* _iface,
     void * * ___a)
{
  return SDL_AtomicGetPtr(___a);
}

STATIC void* 
SDL2Gate_SDL_AtomicGetPtrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * * ___a = (void * *) regarray[REG68K_A0/4];

  return _iface->SDL_AtomicGetPtr(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AtomicGetPtr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AtomicGetPtrPPC };

int SDL_GetNumAudioDrivers(void);

int
SDL2Gate_SDL_GetNumAudioDrivers(struct SDL2IFace* _iface)
{
  return SDL_GetNumAudioDrivers();
}

STATIC int 
SDL2Gate_SDL_GetNumAudioDriversPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetNumAudioDrivers();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumAudioDrivers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumAudioDriversPPC };

const char* SDL_GetAudioDriver(int ___a);

const char*
SDL2Gate_SDL_GetAudioDriver(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetAudioDriver(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetAudioDriverPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetAudioDriver(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetAudioDriver = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetAudioDriverPPC };

int SDL_AudioInit(const char * ___a);

int
SDL2Gate_SDL_AudioInit(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_AudioInit(___a);
}

STATIC int 
SDL2Gate_SDL_AudioInitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_AudioInit(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioInit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioInitPPC };

void SDL_AudioQuit(void);

void
SDL2Gate_SDL_AudioQuit(struct SDL2IFace* _iface)
{
  return SDL_AudioQuit();
}

STATIC void 
SDL2Gate_SDL_AudioQuitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_AudioQuit();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioQuit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioQuitPPC };

const char* SDL_GetCurrentAudioDriver(void);

const char*
SDL2Gate_SDL_GetCurrentAudioDriver(struct SDL2IFace* _iface)
{
  return SDL_GetCurrentAudioDriver();
}

STATIC const char* 
SDL2Gate_SDL_GetCurrentAudioDriverPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetCurrentAudioDriver();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetCurrentAudioDriver = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetCurrentAudioDriverPPC };

int SDL_OpenAudio(SDL_AudioSpec * ___a, SDL_AudioSpec * ___b);

int
SDL2Gate_SDL_OpenAudio(struct SDL2IFace* _iface,
     SDL_AudioSpec * ___a,
     SDL_AudioSpec * ___b)
{
  return SDL_OpenAudio(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_OpenAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioSpec * ___a = (SDL_AudioSpec *) regarray[REG68K_A0/4];
  SDL_AudioSpec * ___b = (SDL_AudioSpec *) regarray[REG68K_A1/4];

  return _iface->SDL_OpenAudio(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OpenAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OpenAudioPPC };

int SDL_GetNumAudioDevices(int ___a);

int
SDL2Gate_SDL_GetNumAudioDevices(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetNumAudioDevices(___a);
}

STATIC int 
SDL2Gate_SDL_GetNumAudioDevicesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetNumAudioDevices(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumAudioDevices = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumAudioDevicesPPC };

const char* SDL_GetAudioDeviceName(int ___a, int ___b);

const char*
SDL2Gate_SDL_GetAudioDeviceName(struct SDL2IFace* _iface,
     int ___a,
     int ___b)
{
  return SDL_GetAudioDeviceName(___a, ___b);
}

STATIC const char* 
SDL2Gate_SDL_GetAudioDeviceNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_GetAudioDeviceName(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetAudioDeviceName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetAudioDeviceNamePPC };

SDL_AudioDeviceID SDL_OpenAudioDevice(const char * ___a, int ___b, const SDL_AudioSpec * ___c, SDL_AudioSpec * ___d, int ___e);

SDL_AudioDeviceID
SDL2Gate_SDL_OpenAudioDevice(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b,
     const SDL_AudioSpec * ___c,
     SDL_AudioSpec * ___d,
     int ___e)
{
  return SDL_OpenAudioDevice(___a, ___b, ___c, ___d, ___e);
}

STATIC SDL_AudioDeviceID 
SDL2Gate_SDL_OpenAudioDevicePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  const SDL_AudioSpec * ___c = (const SDL_AudioSpec *) regarray[REG68K_A1/4];
  SDL_AudioSpec * ___d = (SDL_AudioSpec *) regarray[REG68K_A2/4];
  int ___e = (int) regarray[REG68K_D1/4];

  return _iface->SDL_OpenAudioDevice(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OpenAudioDevice = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OpenAudioDevicePPC };

void SDL_PauseAudio(int ___a);

void
SDL2Gate_SDL_PauseAudio(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_PauseAudio(___a);
}

STATIC void 
SDL2Gate_SDL_PauseAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_PauseAudio(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PauseAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PauseAudioPPC };

void SDL_PauseAudioDevice(SDL_AudioDeviceID ___a, int ___b);

void
SDL2Gate_SDL_PauseAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a,
     int ___b)
{
  return SDL_PauseAudioDevice(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_PauseAudioDevicePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_PauseAudioDevice(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PauseAudioDevice = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PauseAudioDevicePPC };

SDL_AudioSpec* SDL_LoadWAV_RW(SDL_RWops * ___a, int ___b, SDL_AudioSpec * ___c, Uint8 * * ___d, Uint32 * ___e);

SDL_AudioSpec*
SDL2Gate_SDL_LoadWAV_RW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     int ___b,
     SDL_AudioSpec * ___c,
     Uint8 * * ___d,
     Uint32 * ___e)
{
  return SDL_LoadWAV_RW(___a, ___b, ___c, ___d, ___e);
}

STATIC SDL_AudioSpec* 
SDL2Gate_SDL_LoadWAV_RWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  SDL_AudioSpec * ___c = (SDL_AudioSpec *) regarray[REG68K_A1/4];
  Uint8 * * ___d = (Uint8 * *) regarray[REG68K_A2/4];
  Uint32 * ___e = (Uint32 *) regarray[REG68K_A3/4];

  return _iface->SDL_LoadWAV_RW(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadWAV_RW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadWAV_RWPPC };

void SDL_FreeWAV(Uint8 * ___a);

void
SDL2Gate_SDL_FreeWAV(struct SDL2IFace* _iface,
     Uint8 * ___a)
{
  return SDL_FreeWAV(___a);
}

STATIC void 
SDL2Gate_SDL_FreeWAVPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint8 * ___a = (Uint8 *) regarray[REG68K_A0/4];

  return _iface->SDL_FreeWAV(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreeWAV = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreeWAVPPC };

int SDL_BuildAudioCVT(SDL_AudioCVT * ___a, SDL_AudioFormat ___b, Uint8 ___c, int ___d, SDL_AudioFormat ___e, Uint8 ___f, int ___g);

int
SDL2Gate_SDL_BuildAudioCVT(struct SDL2IFace* _iface,
     SDL_AudioCVT * ___a,
     SDL_AudioFormat ___b,
     Uint8 ___c,
     int ___d,
     SDL_AudioFormat ___e,
     Uint8 ___f,
     int ___g)
{
  return SDL_BuildAudioCVT(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

STATIC int 
SDL2Gate_SDL_BuildAudioCVTPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioCVT * ___a = (SDL_AudioCVT *) regarray[REG68K_A0/4];
  SDL_AudioFormat ___b = (SDL_AudioFormat) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  int ___d = (int) regarray[REG68K_D2/4];
  SDL_AudioFormat ___e = (SDL_AudioFormat) regarray[REG68K_D3/4];
  Uint8 ___f = (Uint8) regarray[REG68K_D4/4];
  int ___g = (int) regarray[REG68K_D5/4];

  return _iface->SDL_BuildAudioCVT(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_BuildAudioCVT = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_BuildAudioCVTPPC };

int SDL_ConvertAudio(SDL_AudioCVT * ___a);

int
SDL2Gate_SDL_ConvertAudio(struct SDL2IFace* _iface,
     SDL_AudioCVT * ___a)
{
  return SDL_ConvertAudio(___a);
}

STATIC int 
SDL2Gate_SDL_ConvertAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioCVT * ___a = (SDL_AudioCVT *) regarray[REG68K_A0/4];

  return _iface->SDL_ConvertAudio(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ConvertAudioPPC };

void SDL_MixAudio(Uint8 * ___a, const Uint8 * ___b, Uint32 ___c, int ___d);

void
SDL2Gate_SDL_MixAudio(struct SDL2IFace* _iface,
     Uint8 * ___a,
     const Uint8 * ___b,
     Uint32 ___c,
     int ___d)
{
  return SDL_MixAudio(___a, ___b, ___c, ___d);
}

STATIC void 
SDL2Gate_SDL_MixAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint8 * ___a = (Uint8 *) regarray[REG68K_A0/4];
  const Uint8 * ___b = (const Uint8 *) regarray[REG68K_A1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D0/4];
  int ___d = (int) regarray[REG68K_D1/4];

  return _iface->SDL_MixAudio(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MixAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MixAudioPPC };

void SDL_MixAudioFormat(Uint8 * ___a, const Uint8 * ___b, SDL_AudioFormat ___c, Uint32 ___d, int ___e);

void
SDL2Gate_SDL_MixAudioFormat(struct SDL2IFace* _iface,
     Uint8 * ___a,
     const Uint8 * ___b,
     SDL_AudioFormat ___c,
     Uint32 ___d,
     int ___e)
{
  return SDL_MixAudioFormat(___a, ___b, ___c, ___d, ___e);
}

STATIC void 
SDL2Gate_SDL_MixAudioFormatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint8 * ___a = (Uint8 *) regarray[REG68K_A0/4];
  const Uint8 * ___b = (const Uint8 *) regarray[REG68K_A1/4];
  SDL_AudioFormat ___c = (SDL_AudioFormat) regarray[REG68K_D0/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D1/4];
  int ___e = (int) regarray[REG68K_D2/4];

  return _iface->SDL_MixAudioFormat(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MixAudioFormat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MixAudioFormatPPC };

void SDL_LockAudio(void);

void
SDL2Gate_SDL_LockAudio(struct SDL2IFace* _iface)
{
  return SDL_LockAudio();
}

STATIC void 
SDL2Gate_SDL_LockAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_LockAudio();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockAudioPPC };

void SDL_LockAudioDevice(SDL_AudioDeviceID ___a);

void
SDL2Gate_SDL_LockAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a)
{
  return SDL_LockAudioDevice(___a);
}

STATIC void 
SDL2Gate_SDL_LockAudioDevicePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];

  return _iface->SDL_LockAudioDevice(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockAudioDevice = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockAudioDevicePPC };

void SDL_UnlockAudio(void);

void
SDL2Gate_SDL_UnlockAudio(struct SDL2IFace* _iface)
{
  return SDL_UnlockAudio();
}

STATIC void 
SDL2Gate_SDL_UnlockAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_UnlockAudio();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockAudioPPC };

void SDL_UnlockAudioDevice(SDL_AudioDeviceID ___a);

void
SDL2Gate_SDL_UnlockAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a)
{
  return SDL_UnlockAudioDevice(___a);
}

STATIC void 
SDL2Gate_SDL_UnlockAudioDevicePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];

  return _iface->SDL_UnlockAudioDevice(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockAudioDevice = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockAudioDevicePPC };

void SDL_CloseAudio(void);

void
SDL2Gate_SDL_CloseAudio(struct SDL2IFace* _iface)
{
  return SDL_CloseAudio();
}

STATIC void 
SDL2Gate_SDL_CloseAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_CloseAudio();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CloseAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CloseAudioPPC };

void SDL_CloseAudioDevice(SDL_AudioDeviceID ___a);

void
SDL2Gate_SDL_CloseAudioDevice(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a)
{
  return SDL_CloseAudioDevice(___a);
}

STATIC void 
SDL2Gate_SDL_CloseAudioDevicePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];

  return _iface->SDL_CloseAudioDevice(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CloseAudioDevice = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CloseAudioDevicePPC };

int SDL_SetClipboardText(const char * ___a);

int
SDL2Gate_SDL_SetClipboardText(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_SetClipboardText(___a);
}

STATIC int 
SDL2Gate_SDL_SetClipboardTextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_SetClipboardText(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetClipboardText = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetClipboardTextPPC };

char* SDL_GetClipboardText(void);

char*
SDL2Gate_SDL_GetClipboardText(struct SDL2IFace* _iface)
{
  return SDL_GetClipboardText();
}

STATIC char* 
SDL2Gate_SDL_GetClipboardTextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetClipboardText();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetClipboardText = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetClipboardTextPPC };

SDL_bool SDL_HasClipboardText(void);

SDL_bool
SDL2Gate_SDL_HasClipboardText(struct SDL2IFace* _iface)
{
  return SDL_HasClipboardText();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasClipboardTextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasClipboardText();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasClipboardText = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasClipboardTextPPC };

int SDL_GetCPUCount(void);

int
SDL2Gate_SDL_GetCPUCount(struct SDL2IFace* _iface)
{
  return SDL_GetCPUCount();
}

STATIC int 
SDL2Gate_SDL_GetCPUCountPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetCPUCount();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetCPUCount = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetCPUCountPPC };

int SDL_GetCPUCacheLineSize(void);

int
SDL2Gate_SDL_GetCPUCacheLineSize(struct SDL2IFace* _iface)
{
  return SDL_GetCPUCacheLineSize();
}

STATIC int 
SDL2Gate_SDL_GetCPUCacheLineSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetCPUCacheLineSize();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetCPUCacheLineSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetCPUCacheLineSizePPC };

SDL_bool SDL_HasRDTSC(void);

SDL_bool
SDL2Gate_SDL_HasRDTSC(struct SDL2IFace* _iface)
{
  return SDL_HasRDTSC();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasRDTSCPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasRDTSC();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasRDTSC = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasRDTSCPPC };

SDL_bool SDL_HasAltiVec(void);

SDL_bool
SDL2Gate_SDL_HasAltiVec(struct SDL2IFace* _iface)
{
  return SDL_HasAltiVec();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasAltiVecPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasAltiVec();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasAltiVec = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasAltiVecPPC };

SDL_bool SDL_HasMMX(void);

SDL_bool
SDL2Gate_SDL_HasMMX(struct SDL2IFace* _iface)
{
  return SDL_HasMMX();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasMMXPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasMMX();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasMMX = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasMMXPPC };

SDL_bool SDL_Has3DNow(void);

SDL_bool
SDL2Gate_SDL_Has3DNow(struct SDL2IFace* _iface)
{
  return SDL_Has3DNow();
}

STATIC SDL_bool 
SDL2Gate_SDL_Has3DNowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_Has3DNow();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Has3DNow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_Has3DNowPPC };

SDL_bool SDL_HasSSE(void);

SDL_bool
SDL2Gate_SDL_HasSSE(struct SDL2IFace* _iface)
{
  return SDL_HasSSE();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasSSEPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasSSE();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasSSEPPC };

SDL_bool SDL_HasSSE2(void);

SDL_bool
SDL2Gate_SDL_HasSSE2(struct SDL2IFace* _iface)
{
  return SDL_HasSSE2();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasSSE2PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasSSE2();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE2 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasSSE2PPC };

SDL_bool SDL_HasSSE3(void);

SDL_bool
SDL2Gate_SDL_HasSSE3(struct SDL2IFace* _iface)
{
  return SDL_HasSSE3();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasSSE3PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasSSE3();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE3 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasSSE3PPC };

SDL_bool SDL_HasSSE41(void);

SDL_bool
SDL2Gate_SDL_HasSSE41(struct SDL2IFace* _iface)
{
  return SDL_HasSSE41();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasSSE41PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasSSE41();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE41 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasSSE41PPC };

SDL_bool SDL_HasSSE42(void);

SDL_bool
SDL2Gate_SDL_HasSSE42(struct SDL2IFace* _iface)
{
  return SDL_HasSSE42();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasSSE42PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasSSE42();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasSSE42 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasSSE42PPC };

int SDL_GetSystemRAM(void);

int
SDL2Gate_SDL_GetSystemRAM(struct SDL2IFace* _iface)
{
  return SDL_GetSystemRAM();
}

STATIC int 
SDL2Gate_SDL_GetSystemRAMPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetSystemRAM();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetSystemRAM = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetSystemRAMPPC };

const char* SDL_GetError(void);

const char*
SDL2Gate_SDL_GetError(struct SDL2IFace* _iface)
{
  return SDL_GetError();
}

STATIC const char* 
SDL2Gate_SDL_GetErrorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetError();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetError = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetErrorPPC };

void SDL_ClearError(void);

void
SDL2Gate_SDL_ClearError(struct SDL2IFace* _iface)
{
  return SDL_ClearError();
}

STATIC void 
SDL2Gate_SDL_ClearErrorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ClearError();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ClearError = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ClearErrorPPC };

int SDL_Error(SDL_errorcode ___a);

int
SDL2Gate_SDL_Error(struct SDL2IFace* _iface,
     SDL_errorcode ___a)
{
  return SDL_Error(___a);
}

STATIC int 
SDL2Gate_SDL_ErrorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_errorcode ___a = (SDL_errorcode) regarray[REG68K_D0/4];

  return _iface->SDL_Error(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Error = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ErrorPPC };

void SDL_PumpEvents(void);

void
SDL2Gate_SDL_PumpEvents(struct SDL2IFace* _iface)
{
  return SDL_PumpEvents();
}

STATIC void 
SDL2Gate_SDL_PumpEventsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_PumpEvents();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PumpEvents = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PumpEventsPPC };

int SDL_PeepEvents(SDL_Event * ___a, int ___b, SDL_eventaction ___c, Uint32 ___d, Uint32 ___e);

int
SDL2Gate_SDL_PeepEvents(struct SDL2IFace* _iface,
     SDL_Event * ___a,
     int ___b,
     SDL_eventaction ___c,
     Uint32 ___d,
     Uint32 ___e)
{
  return SDL_PeepEvents(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_PeepEventsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Event * ___a = (SDL_Event *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  SDL_eventaction ___c = (SDL_eventaction) regarray[REG68K_D1/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D2/4];
  Uint32 ___e = (Uint32) regarray[REG68K_D3/4];

  return _iface->SDL_PeepEvents(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PeepEvents = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PeepEventsPPC };

SDL_bool SDL_HasEvent(Uint32 ___a);

SDL_bool
SDL2Gate_SDL_HasEvent(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_HasEvent(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasEventPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_HasEvent(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasEvent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasEventPPC };

SDL_bool SDL_HasEvents(Uint32 ___a, Uint32 ___b);

SDL_bool
SDL2Gate_SDL_HasEvents(struct SDL2IFace* _iface,
     Uint32 ___a,
     Uint32 ___b)
{
  return SDL_HasEvents(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasEventsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_HasEvents(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasEvents = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasEventsPPC };

void SDL_FlushEvent(Uint32 ___a);

void
SDL2Gate_SDL_FlushEvent(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_FlushEvent(___a);
}

STATIC void 
SDL2Gate_SDL_FlushEventPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_FlushEvent(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FlushEvent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FlushEventPPC };

void SDL_FlushEvents(Uint32 ___a, Uint32 ___b);

void
SDL2Gate_SDL_FlushEvents(struct SDL2IFace* _iface,
     Uint32 ___a,
     Uint32 ___b)
{
  return SDL_FlushEvents(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_FlushEventsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_FlushEvents(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FlushEvents = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FlushEventsPPC };

int SDL_PollEvent(SDL_Event * ___a);

int
SDL2Gate_SDL_PollEvent(struct SDL2IFace* _iface,
     SDL_Event * ___a)
{
  return SDL_PollEvent(___a);
}

STATIC int 
SDL2Gate_SDL_PollEventPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Event * ___a = (SDL_Event *) regarray[REG68K_A0/4];

  return _iface->SDL_PollEvent(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PollEvent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PollEventPPC };

int SDL_WaitEvent(SDL_Event * ___a);

int
SDL2Gate_SDL_WaitEvent(struct SDL2IFace* _iface,
     SDL_Event * ___a)
{
  return SDL_WaitEvent(___a);
}

STATIC int 
SDL2Gate_SDL_WaitEventPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Event * ___a = (SDL_Event *) regarray[REG68K_A0/4];

  return _iface->SDL_WaitEvent(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WaitEvent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WaitEventPPC };

int SDL_WaitEventTimeout(SDL_Event * ___a, int ___b);

int
SDL2Gate_SDL_WaitEventTimeout(struct SDL2IFace* _iface,
     SDL_Event * ___a,
     int ___b)
{
  return SDL_WaitEventTimeout(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_WaitEventTimeoutPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Event * ___a = (SDL_Event *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_WaitEventTimeout(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WaitEventTimeout = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WaitEventTimeoutPPC };

int SDL_PushEvent(SDL_Event * ___a);

int
SDL2Gate_SDL_PushEvent(struct SDL2IFace* _iface,
     SDL_Event * ___a)
{
  return SDL_PushEvent(___a);
}

STATIC int 
SDL2Gate_SDL_PushEventPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Event * ___a = (SDL_Event *) regarray[REG68K_A0/4];

  return _iface->SDL_PushEvent(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PushEvent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PushEventPPC };

void SDL_SetEventFilter(SDL_EventFilter ___a, void * ___b);

void
SDL2Gate_SDL_SetEventFilter(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b)
{
  return SDL_SetEventFilter(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetEventFilterPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_EventFilter ___a = (SDL_EventFilter) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_SetEventFilter(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetEventFilter = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetEventFilterPPC };

SDL_bool SDL_GetEventFilter(SDL_EventFilter * ___a, void * * ___b);

SDL_bool
SDL2Gate_SDL_GetEventFilter(struct SDL2IFace* _iface,
     SDL_EventFilter * ___a,
     void * * ___b)
{
  return SDL_GetEventFilter(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GetEventFilterPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_EventFilter * ___a = (SDL_EventFilter *) regarray[REG68K_A0/4];
  void * * ___b = (void * *) regarray[REG68K_A1/4];

  return _iface->SDL_GetEventFilter(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetEventFilter = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetEventFilterPPC };

void SDL_AddEventWatch(SDL_EventFilter ___a, void * ___b);

void
SDL2Gate_SDL_AddEventWatch(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b)
{
  return SDL_AddEventWatch(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_AddEventWatchPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_EventFilter ___a = (SDL_EventFilter) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_AddEventWatch(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AddEventWatch = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AddEventWatchPPC };

void SDL_DelEventWatch(SDL_EventFilter ___a, void * ___b);

void
SDL2Gate_SDL_DelEventWatch(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b)
{
  return SDL_DelEventWatch(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_DelEventWatchPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_EventFilter ___a = (SDL_EventFilter) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_DelEventWatch(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DelEventWatch = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DelEventWatchPPC };

void SDL_FilterEvents(SDL_EventFilter ___a, void * ___b);

void
SDL2Gate_SDL_FilterEvents(struct SDL2IFace* _iface,
     SDL_EventFilter ___a,
     void * ___b)
{
  return SDL_FilterEvents(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_FilterEventsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_EventFilter ___a = (SDL_EventFilter) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_FilterEvents(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FilterEvents = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FilterEventsPPC };

Uint8 SDL_EventState(Uint32 ___a, int ___b);

Uint8
SDL2Gate_SDL_EventState(struct SDL2IFace* _iface,
     Uint32 ___a,
     int ___b)
{
  return SDL_EventState(___a, ___b);
}

STATIC Uint8 
SDL2Gate_SDL_EventStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_EventState(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_EventState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_EventStatePPC };

Uint32 SDL_RegisterEvents(int ___a);

Uint32
SDL2Gate_SDL_RegisterEvents(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_RegisterEvents(___a);
}

STATIC Uint32 
SDL2Gate_SDL_RegisterEventsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RegisterEvents(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RegisterEvents = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RegisterEventsPPC };

char* SDL_GetBasePath(void);

char*
SDL2Gate_SDL_GetBasePath(struct SDL2IFace* _iface)
{
  return SDL_GetBasePath();
}

STATIC char* 
SDL2Gate_SDL_GetBasePathPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetBasePath();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetBasePath = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetBasePathPPC };

char* SDL_GetPrefPath(const char * ___a, const char * ___b);

char*
SDL2Gate_SDL_GetPrefPath(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_GetPrefPath(___a, ___b);
}

STATIC char* 
SDL2Gate_SDL_GetPrefPathPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_GetPrefPath(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPrefPath = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPrefPathPPC };

int SDL_GameControllerAddMapping(const char * ___a);

int
SDL2Gate_SDL_GameControllerAddMapping(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GameControllerAddMapping(___a);
}

STATIC int 
SDL2Gate_SDL_GameControllerAddMappingPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerAddMapping(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerAddMapping = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerAddMappingPPC };

char* SDL_GameControllerMapping(SDL_GameController * ___a);

char*
SDL2Gate_SDL_GameControllerMapping(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerMapping(___a);
}

STATIC char* 
SDL2Gate_SDL_GameControllerMappingPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerMapping(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerMapping = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerMappingPPC };

SDL_bool SDL_IsGameController(int ___a);

SDL_bool
SDL2Gate_SDL_IsGameController(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_IsGameController(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_IsGameControllerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_IsGameController(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsGameController = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsGameControllerPPC };

const char* SDL_GameControllerNameForIndex(int ___a);

const char*
SDL2Gate_SDL_GameControllerNameForIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerNameForIndex(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerNameForIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerNameForIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerNameForIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerNameForIndexPPC };

SDL_GameController* SDL_GameControllerOpen(int ___a);

SDL_GameController*
SDL2Gate_SDL_GameControllerOpen(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerOpen(___a);
}

STATIC SDL_GameController* 
SDL2Gate_SDL_GameControllerOpenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerOpen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerOpen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerOpenPPC };

const char* SDL_GameControllerName(SDL_GameController * ___a);

const char*
SDL2Gate_SDL_GameControllerName(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerNamePPC };

SDL_bool SDL_GameControllerGetAttached(SDL_GameController * ___a);

SDL_bool
SDL2Gate_SDL_GameControllerGetAttached(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetAttached(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerGetAttachedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetAttached(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAttached = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetAttachedPPC };

SDL_Joystick* SDL_GameControllerGetJoystick(SDL_GameController * ___a);

SDL_Joystick*
SDL2Gate_SDL_GameControllerGetJoystick(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetJoystick(___a);
}

STATIC SDL_Joystick* 
SDL2Gate_SDL_GameControllerGetJoystickPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetJoystick(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetJoystick = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetJoystickPPC };

int SDL_GameControllerEventState(int ___a);

int
SDL2Gate_SDL_GameControllerEventState(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerEventState(___a);
}

STATIC int 
SDL2Gate_SDL_GameControllerEventStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerEventState(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerEventState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerEventStatePPC };

void SDL_GameControllerUpdate(void);

void
SDL2Gate_SDL_GameControllerUpdate(struct SDL2IFace* _iface)
{
  return SDL_GameControllerUpdate();
}

STATIC void 
SDL2Gate_SDL_GameControllerUpdatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GameControllerUpdate();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerUpdate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerUpdatePPC };

SDL_GameControllerAxis SDL_GameControllerGetAxisFromString(const char * ___a);

SDL_GameControllerAxis
SDL2Gate_SDL_GameControllerGetAxisFromString(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GameControllerGetAxisFromString(___a);
}

STATIC SDL_GameControllerAxis 
SDL2Gate_SDL_GameControllerGetAxisFromStringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetAxisFromString(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAxisFromString = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetAxisFromStringPPC };

const char* SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis ___a);

const char*
SDL2Gate_SDL_GameControllerGetStringForAxis(struct SDL2IFace* _iface,
     SDL_GameControllerAxis ___a)
{
  return SDL_GameControllerGetStringForAxis(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerGetStringForAxisPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameControllerAxis ___a = (SDL_GameControllerAxis) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetStringForAxis(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetStringForAxis = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetStringForAxisPPC };

Sint16 SDL_GameControllerGetAxis(SDL_GameController * ___a, SDL_GameControllerAxis ___b);

Sint16
SDL2Gate_SDL_GameControllerGetAxis(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerAxis ___b)
{
  return SDL_GameControllerGetAxis(___a, ___b);
}

STATIC Sint16 
SDL2Gate_SDL_GameControllerGetAxisPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_GameControllerAxis ___b = (SDL_GameControllerAxis) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetAxis(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAxis = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetAxisPPC };

SDL_GameControllerButton SDL_GameControllerGetButtonFromString(const char * ___a);

SDL_GameControllerButton
SDL2Gate_SDL_GameControllerGetButtonFromString(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GameControllerGetButtonFromString(___a);
}

STATIC SDL_GameControllerButton 
SDL2Gate_SDL_GameControllerGetButtonFromStringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetButtonFromString(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetButtonFromString = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetButtonFromStringPPC };

const char* SDL_GameControllerGetStringForButton(SDL_GameControllerButton ___a);

const char*
SDL2Gate_SDL_GameControllerGetStringForButton(struct SDL2IFace* _iface,
     SDL_GameControllerButton ___a)
{
  return SDL_GameControllerGetStringForButton(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerGetStringForButtonPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameControllerButton ___a = (SDL_GameControllerButton) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetStringForButton(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetStringForButton = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetStringForButtonPPC };

Uint8 SDL_GameControllerGetButton(SDL_GameController * ___a, SDL_GameControllerButton ___b);

Uint8
SDL2Gate_SDL_GameControllerGetButton(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerButton ___b)
{
  return SDL_GameControllerGetButton(___a, ___b);
}

STATIC Uint8 
SDL2Gate_SDL_GameControllerGetButtonPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_GameControllerButton ___b = (SDL_GameControllerButton) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetButton(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetButton = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetButtonPPC };

void SDL_GameControllerClose(SDL_GameController * ___a);

void
SDL2Gate_SDL_GameControllerClose(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerClose(___a);
}

STATIC void 
SDL2Gate_SDL_GameControllerClosePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerClose(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerClose = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerClosePPC };

int SDL_RecordGesture(SDL_TouchID ___a);

int
SDL2Gate_SDL_RecordGesture(struct SDL2IFace* _iface,
     SDL_TouchID ___a)
{
  return SDL_RecordGesture(___a);
}

STATIC int 
SDL2Gate_SDL_RecordGesturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TouchID ___a = (SDL_TouchID) regarray[REG68K_D0/4];

  return _iface->SDL_RecordGesture(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RecordGesture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RecordGesturePPC };

int SDL_SaveAllDollarTemplates(SDL_RWops * ___a);

int
SDL2Gate_SDL_SaveAllDollarTemplates(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_SaveAllDollarTemplates(___a);
}

STATIC int 
SDL2Gate_SDL_SaveAllDollarTemplatesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_SaveAllDollarTemplates(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SaveAllDollarTemplates = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SaveAllDollarTemplatesPPC };

int SDL_SaveDollarTemplate(SDL_GestureID ___a, SDL_RWops * ___b);

int
SDL2Gate_SDL_SaveDollarTemplate(struct SDL2IFace* _iface,
     SDL_GestureID ___a,
     SDL_RWops * ___b)
{
  return SDL_SaveDollarTemplate(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SaveDollarTemplatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GestureID ___a = (SDL_GestureID) regarray[REG68K_D0/4];
  SDL_RWops * ___b = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_SaveDollarTemplate(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SaveDollarTemplate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SaveDollarTemplatePPC };

int SDL_LoadDollarTemplates(SDL_TouchID ___a, SDL_RWops * ___b);

int
SDL2Gate_SDL_LoadDollarTemplates(struct SDL2IFace* _iface,
     SDL_TouchID ___a,
     SDL_RWops * ___b)
{
  return SDL_LoadDollarTemplates(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_LoadDollarTemplatesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TouchID ___a = (SDL_TouchID) regarray[REG68K_D0/4];
  SDL_RWops * ___b = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_LoadDollarTemplates(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadDollarTemplates = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadDollarTemplatesPPC };

int SDL_NumHaptics(void);

int
SDL2Gate_SDL_NumHaptics(struct SDL2IFace* _iface)
{
  return SDL_NumHaptics();
}

STATIC int 
SDL2Gate_SDL_NumHapticsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_NumHaptics();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_NumHaptics = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_NumHapticsPPC };

const char* SDL_HapticName(int ___a);

const char*
SDL2Gate_SDL_HapticName(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_HapticName(___a);
}

STATIC const char* 
SDL2Gate_SDL_HapticNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticNamePPC };

SDL_Haptic* SDL_HapticOpen(int ___a);

SDL_Haptic*
SDL2Gate_SDL_HapticOpen(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_HapticOpen(___a);
}

STATIC SDL_Haptic* 
SDL2Gate_SDL_HapticOpenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticOpen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticOpenPPC };

int SDL_HapticOpened(int ___a);

int
SDL2Gate_SDL_HapticOpened(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_HapticOpened(___a);
}

STATIC int 
SDL2Gate_SDL_HapticOpenedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticOpened(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpened = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticOpenedPPC };

int SDL_HapticIndex(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticIndex(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticIndex(___a);
}

STATIC int 
SDL2Gate_SDL_HapticIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticIndexPPC };

int SDL_MouseIsHaptic(void);

int
SDL2Gate_SDL_MouseIsHaptic(struct SDL2IFace* _iface)
{
  return SDL_MouseIsHaptic();
}

STATIC int 
SDL2Gate_SDL_MouseIsHapticPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_MouseIsHaptic();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MouseIsHaptic = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MouseIsHapticPPC };

SDL_Haptic* SDL_HapticOpenFromMouse(void);

SDL_Haptic*
SDL2Gate_SDL_HapticOpenFromMouse(struct SDL2IFace* _iface)
{
  return SDL_HapticOpenFromMouse();
}

STATIC SDL_Haptic* 
SDL2Gate_SDL_HapticOpenFromMousePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HapticOpenFromMouse();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpenFromMouse = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticOpenFromMousePPC };

int SDL_JoystickIsHaptic(SDL_Joystick * ___a);

int
SDL2Gate_SDL_JoystickIsHaptic(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickIsHaptic(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickIsHapticPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickIsHaptic(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickIsHaptic = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickIsHapticPPC };

SDL_Haptic* SDL_HapticOpenFromJoystick(SDL_Joystick * ___a);

SDL_Haptic*
SDL2Gate_SDL_HapticOpenFromJoystick(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_HapticOpenFromJoystick(___a);
}

STATIC SDL_Haptic* 
SDL2Gate_SDL_HapticOpenFromJoystickPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticOpenFromJoystick(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticOpenFromJoystick = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticOpenFromJoystickPPC };

void SDL_HapticClose(SDL_Haptic * ___a);

void
SDL2Gate_SDL_HapticClose(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticClose(___a);
}

STATIC void 
SDL2Gate_SDL_HapticClosePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticClose(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticClose = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticClosePPC };

int SDL_HapticNumEffects(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticNumEffects(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticNumEffects(___a);
}

STATIC int 
SDL2Gate_SDL_HapticNumEffectsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticNumEffects(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNumEffects = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticNumEffectsPPC };

int SDL_HapticNumEffectsPlaying(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticNumEffectsPlaying(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticNumEffectsPlaying(___a);
}

STATIC int 
SDL2Gate_SDL_HapticNumEffectsPlayingPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticNumEffectsPlaying(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNumEffectsPlaying = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticNumEffectsPlayingPPC };

unsigned int SDL_HapticQuery(SDL_Haptic * ___a);

unsigned int
SDL2Gate_SDL_HapticQuery(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticQuery(___a);
}

STATIC unsigned int 
SDL2Gate_SDL_HapticQueryPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticQuery(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticQuery = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticQueryPPC };

int SDL_HapticNumAxes(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticNumAxes(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticNumAxes(___a);
}

STATIC int 
SDL2Gate_SDL_HapticNumAxesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticNumAxes(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNumAxes = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticNumAxesPPC };

int SDL_HapticEffectSupported(SDL_Haptic * ___a, SDL_HapticEffect * ___b);

int
SDL2Gate_SDL_HapticEffectSupported(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     SDL_HapticEffect * ___b)
{
  return SDL_HapticEffectSupported(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_HapticEffectSupportedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  SDL_HapticEffect * ___b = (SDL_HapticEffect *) regarray[REG68K_A1/4];

  return _iface->SDL_HapticEffectSupported(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticEffectSupported = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticEffectSupportedPPC };

int SDL_HapticNewEffect(SDL_Haptic * ___a, SDL_HapticEffect * ___b);

int
SDL2Gate_SDL_HapticNewEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     SDL_HapticEffect * ___b)
{
  return SDL_HapticNewEffect(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_HapticNewEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  SDL_HapticEffect * ___b = (SDL_HapticEffect *) regarray[REG68K_A1/4];

  return _iface->SDL_HapticNewEffect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticNewEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticNewEffectPPC };

int SDL_HapticUpdateEffect(SDL_Haptic * ___a, int ___b, SDL_HapticEffect * ___c);

int
SDL2Gate_SDL_HapticUpdateEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b,
     SDL_HapticEffect * ___c)
{
  return SDL_HapticUpdateEffect(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_HapticUpdateEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  SDL_HapticEffect * ___c = (SDL_HapticEffect *) regarray[REG68K_A1/4];

  return _iface->SDL_HapticUpdateEffect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticUpdateEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticUpdateEffectPPC };

int SDL_HapticRunEffect(SDL_Haptic * ___a, int ___b, Uint32 ___c);

int
SDL2Gate_SDL_HapticRunEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b,
     Uint32 ___c)
{
  return SDL_HapticRunEffect(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_HapticRunEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_HapticRunEffect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRunEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticRunEffectPPC };

int SDL_HapticStopEffect(SDL_Haptic * ___a, int ___b);

int
SDL2Gate_SDL_HapticStopEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b)
{
  return SDL_HapticStopEffect(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_HapticStopEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticStopEffect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticStopEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticStopEffectPPC };

void SDL_HapticDestroyEffect(SDL_Haptic * ___a, int ___b);

void
SDL2Gate_SDL_HapticDestroyEffect(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b)
{
  return SDL_HapticDestroyEffect(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_HapticDestroyEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticDestroyEffect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticDestroyEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticDestroyEffectPPC };

int SDL_HapticGetEffectStatus(SDL_Haptic * ___a, int ___b);

int
SDL2Gate_SDL_HapticGetEffectStatus(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b)
{
  return SDL_HapticGetEffectStatus(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_HapticGetEffectStatusPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticGetEffectStatus(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticGetEffectStatus = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticGetEffectStatusPPC };

int SDL_HapticSetGain(SDL_Haptic * ___a, int ___b);

int
SDL2Gate_SDL_HapticSetGain(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b)
{
  return SDL_HapticSetGain(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_HapticSetGainPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticSetGain(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticSetGain = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticSetGainPPC };

int SDL_HapticSetAutocenter(SDL_Haptic * ___a, int ___b);

int
SDL2Gate_SDL_HapticSetAutocenter(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     int ___b)
{
  return SDL_HapticSetAutocenter(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_HapticSetAutocenterPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_HapticSetAutocenter(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticSetAutocenter = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticSetAutocenterPPC };

int SDL_HapticPause(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticPause(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticPause(___a);
}

STATIC int 
SDL2Gate_SDL_HapticPausePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticPause(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticPause = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticPausePPC };

int SDL_HapticUnpause(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticUnpause(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticUnpause(___a);
}

STATIC int 
SDL2Gate_SDL_HapticUnpausePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticUnpause(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticUnpause = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticUnpausePPC };

int SDL_HapticStopAll(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticStopAll(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticStopAll(___a);
}

STATIC int 
SDL2Gate_SDL_HapticStopAllPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticStopAll(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticStopAll = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticStopAllPPC };

int SDL_HapticRumbleSupported(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticRumbleSupported(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticRumbleSupported(___a);
}

STATIC int 
SDL2Gate_SDL_HapticRumbleSupportedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticRumbleSupported(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumbleSupported = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticRumbleSupportedPPC };

int SDL_HapticRumbleInit(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticRumbleInit(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticRumbleInit(___a);
}

STATIC int 
SDL2Gate_SDL_HapticRumbleInitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticRumbleInit(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumbleInit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticRumbleInitPPC };

int SDL_HapticRumblePlay(SDL_Haptic * ___a, float ___b, Uint32 ___c);

int
SDL2Gate_SDL_HapticRumblePlay(struct SDL2IFace* _iface,
     SDL_Haptic * ___a,
     float ___b,
     Uint32 ___c)
{
  return SDL_HapticRumblePlay(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_HapticRumblePlayPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_HapticRumblePlay(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumblePlay = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticRumblePlayPPC };

int SDL_HapticRumbleStop(SDL_Haptic * ___a);

int
SDL2Gate_SDL_HapticRumbleStop(struct SDL2IFace* _iface,
     SDL_Haptic * ___a)
{
  return SDL_HapticRumbleStop(___a);
}

STATIC int 
SDL2Gate_SDL_HapticRumbleStopPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Haptic * ___a = (SDL_Haptic *) regarray[REG68K_A0/4];

  return _iface->SDL_HapticRumbleStop(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HapticRumbleStop = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HapticRumbleStopPPC };

SDL_bool SDL_SetHintWithPriority(const char * ___a, const char * ___b, SDL_HintPriority ___c);

SDL_bool
SDL2Gate_SDL_SetHintWithPriority(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     SDL_HintPriority ___c)
{
  return SDL_SetHintWithPriority(___a, ___b, ___c);
}

STATIC SDL_bool 
SDL2Gate_SDL_SetHintWithPriorityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  SDL_HintPriority ___c = (SDL_HintPriority) regarray[REG68K_D0/4];

  return _iface->SDL_SetHintWithPriority(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetHintWithPriority = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetHintWithPriorityPPC };

SDL_bool SDL_SetHint(const char * ___a, const char * ___b);

SDL_bool
SDL2Gate_SDL_SetHint(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_SetHint(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_SetHintPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_SetHint(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetHint = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetHintPPC };

const char* SDL_GetHint(const char * ___a);

const char*
SDL2Gate_SDL_GetHint(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GetHint(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetHintPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GetHint(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetHint = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetHintPPC };

void SDL_AddHintCallback(const char * ___a, SDL_HintCallback ___b, void * ___c);

void
SDL2Gate_SDL_AddHintCallback(struct SDL2IFace* _iface,
     const char * ___a,
     SDL_HintCallback ___b,
     void * ___c)
{
  return SDL_AddHintCallback(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_AddHintCallbackPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  SDL_HintCallback ___b = (SDL_HintCallback) regarray[REG68K_D0/4];
  void * ___c = (void *) regarray[REG68K_A1/4];

  return _iface->SDL_AddHintCallback(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AddHintCallback = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AddHintCallbackPPC };

void SDL_DelHintCallback(const char * ___a, SDL_HintCallback ___b, void * ___c);

void
SDL2Gate_SDL_DelHintCallback(struct SDL2IFace* _iface,
     const char * ___a,
     SDL_HintCallback ___b,
     void * ___c)
{
  return SDL_DelHintCallback(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_DelHintCallbackPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  SDL_HintCallback ___b = (SDL_HintCallback) regarray[REG68K_D0/4];
  void * ___c = (void *) regarray[REG68K_A1/4];

  return _iface->SDL_DelHintCallback(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DelHintCallback = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DelHintCallbackPPC };

void SDL_ClearHints(void);

void
SDL2Gate_SDL_ClearHints(struct SDL2IFace* _iface)
{
  return SDL_ClearHints();
}

STATIC void 
SDL2Gate_SDL_ClearHintsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ClearHints();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ClearHints = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ClearHintsPPC };

int SDL_NumJoysticks(void);

int
SDL2Gate_SDL_NumJoysticks(struct SDL2IFace* _iface)
{
  return SDL_NumJoysticks();
}

STATIC int 
SDL2Gate_SDL_NumJoysticksPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_NumJoysticks();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_NumJoysticks = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_NumJoysticksPPC };

const char* SDL_JoystickNameForIndex(int ___a);

const char*
SDL2Gate_SDL_JoystickNameForIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickNameForIndex(___a);
}

STATIC const char* 
SDL2Gate_SDL_JoystickNameForIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickNameForIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNameForIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickNameForIndexPPC };

SDL_Joystick* SDL_JoystickOpen(int ___a);

SDL_Joystick*
SDL2Gate_SDL_JoystickOpen(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickOpen(___a);
}

STATIC SDL_Joystick* 
SDL2Gate_SDL_JoystickOpenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickOpen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickOpen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickOpenPPC };

const char* SDL_JoystickName(SDL_Joystick * ___a);

const char*
SDL2Gate_SDL_JoystickName(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickName(___a);
}

STATIC const char* 
SDL2Gate_SDL_JoystickNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickNamePPC };

SDL_bool SDL_JoystickGetAttached(SDL_Joystick * ___a);

SDL_bool
SDL2Gate_SDL_JoystickGetAttached(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetAttached(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_JoystickGetAttachedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetAttached(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetAttached = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetAttachedPPC };

SDL_JoystickID SDL_JoystickInstanceID(SDL_Joystick * ___a);

SDL_JoystickID
SDL2Gate_SDL_JoystickInstanceID(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickInstanceID(___a);
}

STATIC SDL_JoystickID 
SDL2Gate_SDL_JoystickInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickInstanceIDPPC };

int SDL_JoystickNumAxes(SDL_Joystick * ___a);

int
SDL2Gate_SDL_JoystickNumAxes(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickNumAxes(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickNumAxesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickNumAxes(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumAxes = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickNumAxesPPC };

int SDL_JoystickNumBalls(SDL_Joystick * ___a);

int
SDL2Gate_SDL_JoystickNumBalls(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickNumBalls(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickNumBallsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickNumBalls(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumBalls = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickNumBallsPPC };

int SDL_JoystickNumHats(SDL_Joystick * ___a);

int
SDL2Gate_SDL_JoystickNumHats(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickNumHats(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickNumHatsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickNumHats(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumHats = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickNumHatsPPC };

int SDL_JoystickNumButtons(SDL_Joystick * ___a);

int
SDL2Gate_SDL_JoystickNumButtons(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickNumButtons(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickNumButtonsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickNumButtons(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickNumButtons = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickNumButtonsPPC };

void SDL_JoystickUpdate(void);

void
SDL2Gate_SDL_JoystickUpdate(struct SDL2IFace* _iface)
{
  return SDL_JoystickUpdate();
}

STATIC void 
SDL2Gate_SDL_JoystickUpdatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_JoystickUpdate();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickUpdate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickUpdatePPC };

int SDL_JoystickEventState(int ___a);

int
SDL2Gate_SDL_JoystickEventState(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickEventState(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickEventStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickEventState(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickEventState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickEventStatePPC };

Sint16 SDL_JoystickGetAxis(SDL_Joystick * ___a, int ___b);

Sint16
SDL2Gate_SDL_JoystickGetAxis(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b)
{
  return SDL_JoystickGetAxis(___a, ___b);
}

STATIC Sint16 
SDL2Gate_SDL_JoystickGetAxisPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetAxis(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetAxis = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetAxisPPC };

Uint8 SDL_JoystickGetHat(SDL_Joystick * ___a, int ___b);

Uint8
SDL2Gate_SDL_JoystickGetHat(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b)
{
  return SDL_JoystickGetHat(___a, ___b);
}

STATIC Uint8 
SDL2Gate_SDL_JoystickGetHatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetHat(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetHat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetHatPPC };

int SDL_JoystickGetBall(SDL_Joystick * ___a, int ___b, int * ___c, int * ___d);

int
SDL2Gate_SDL_JoystickGetBall(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     int * ___c,
     int * ___d)
{
  return SDL_JoystickGetBall(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_JoystickGetBallPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int * ___c = (int *) regarray[REG68K_A1/4];
  int * ___d = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_JoystickGetBall(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetBall = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetBallPPC };

Uint8 SDL_JoystickGetButton(SDL_Joystick * ___a, int ___b);

Uint8
SDL2Gate_SDL_JoystickGetButton(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b)
{
  return SDL_JoystickGetButton(___a, ___b);
}

STATIC Uint8 
SDL2Gate_SDL_JoystickGetButtonPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetButton(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetButton = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetButtonPPC };

void SDL_JoystickClose(SDL_Joystick * ___a);

void
SDL2Gate_SDL_JoystickClose(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickClose(___a);
}

STATIC void 
SDL2Gate_SDL_JoystickClosePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickClose(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickClose = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickClosePPC };

SDL_Window* SDL_GetKeyboardFocus(void);

SDL_Window*
SDL2Gate_SDL_GetKeyboardFocus(struct SDL2IFace* _iface)
{
  return SDL_GetKeyboardFocus();
}

STATIC SDL_Window* 
SDL2Gate_SDL_GetKeyboardFocusPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetKeyboardFocus();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyboardFocus = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetKeyboardFocusPPC };

const Uint8* SDL_GetKeyboardState(int * ___a);

const Uint8*
SDL2Gate_SDL_GetKeyboardState(struct SDL2IFace* _iface,
     int * ___a)
{
  return SDL_GetKeyboardState(___a);
}

STATIC const Uint8* 
SDL2Gate_SDL_GetKeyboardStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int * ___a = (int *) regarray[REG68K_A0/4];

  return _iface->SDL_GetKeyboardState(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyboardState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetKeyboardStatePPC };

SDL_Keymod SDL_GetModState(void);

SDL_Keymod
SDL2Gate_SDL_GetModState(struct SDL2IFace* _iface)
{
  return SDL_GetModState();
}

STATIC SDL_Keymod 
SDL2Gate_SDL_GetModStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetModState();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetModState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetModStatePPC };

void SDL_SetModState(SDL_Keymod ___a);

void
SDL2Gate_SDL_SetModState(struct SDL2IFace* _iface,
     SDL_Keymod ___a)
{
  return SDL_SetModState(___a);
}

STATIC void 
SDL2Gate_SDL_SetModStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Keymod ___a = (SDL_Keymod) regarray[REG68K_D0/4];

  return _iface->SDL_SetModState(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetModState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetModStatePPC };

SDL_Keycode SDL_GetKeyFromScancode(SDL_Scancode ___a);

SDL_Keycode
SDL2Gate_SDL_GetKeyFromScancode(struct SDL2IFace* _iface,
     SDL_Scancode ___a)
{
  return SDL_GetKeyFromScancode(___a);
}

STATIC SDL_Keycode 
SDL2Gate_SDL_GetKeyFromScancodePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Scancode ___a = (SDL_Scancode) regarray[REG68K_D0/4];

  return _iface->SDL_GetKeyFromScancode(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyFromScancode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetKeyFromScancodePPC };

SDL_Scancode SDL_GetScancodeFromKey(SDL_Keycode ___a);

SDL_Scancode
SDL2Gate_SDL_GetScancodeFromKey(struct SDL2IFace* _iface,
     SDL_Keycode ___a)
{
  return SDL_GetScancodeFromKey(___a);
}

STATIC SDL_Scancode 
SDL2Gate_SDL_GetScancodeFromKeyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Keycode ___a = (SDL_Keycode) regarray[REG68K_D0/4];

  return _iface->SDL_GetScancodeFromKey(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetScancodeFromKey = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetScancodeFromKeyPPC };

const char* SDL_GetScancodeName(SDL_Scancode ___a);

const char*
SDL2Gate_SDL_GetScancodeName(struct SDL2IFace* _iface,
     SDL_Scancode ___a)
{
  return SDL_GetScancodeName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetScancodeNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Scancode ___a = (SDL_Scancode) regarray[REG68K_D0/4];

  return _iface->SDL_GetScancodeName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetScancodeName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetScancodeNamePPC };

SDL_Scancode SDL_GetScancodeFromName(const char * ___a);

SDL_Scancode
SDL2Gate_SDL_GetScancodeFromName(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GetScancodeFromName(___a);
}

STATIC SDL_Scancode 
SDL2Gate_SDL_GetScancodeFromNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GetScancodeFromName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetScancodeFromName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetScancodeFromNamePPC };

const char* SDL_GetKeyName(SDL_Keycode ___a);

const char*
SDL2Gate_SDL_GetKeyName(struct SDL2IFace* _iface,
     SDL_Keycode ___a)
{
  return SDL_GetKeyName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetKeyNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Keycode ___a = (SDL_Keycode) regarray[REG68K_D0/4];

  return _iface->SDL_GetKeyName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetKeyNamePPC };

SDL_Keycode SDL_GetKeyFromName(const char * ___a);

SDL_Keycode
SDL2Gate_SDL_GetKeyFromName(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GetKeyFromName(___a);
}

STATIC SDL_Keycode 
SDL2Gate_SDL_GetKeyFromNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GetKeyFromName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetKeyFromName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetKeyFromNamePPC };

void SDL_StartTextInput(void);

void
SDL2Gate_SDL_StartTextInput(struct SDL2IFace* _iface)
{
  return SDL_StartTextInput();
}

STATIC void 
SDL2Gate_SDL_StartTextInputPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_StartTextInput();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_StartTextInput = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_StartTextInputPPC };

SDL_bool SDL_IsTextInputActive(void);

SDL_bool
SDL2Gate_SDL_IsTextInputActive(struct SDL2IFace* _iface)
{
  return SDL_IsTextInputActive();
}

STATIC SDL_bool 
SDL2Gate_SDL_IsTextInputActivePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_IsTextInputActive();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsTextInputActive = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsTextInputActivePPC };

void SDL_StopTextInput(void);

void
SDL2Gate_SDL_StopTextInput(struct SDL2IFace* _iface)
{
  return SDL_StopTextInput();
}

STATIC void 
SDL2Gate_SDL_StopTextInputPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_StopTextInput();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_StopTextInput = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_StopTextInputPPC };

void SDL_SetTextInputRect(const SDL_Rect * ___a);

void
SDL2Gate_SDL_SetTextInputRect(struct SDL2IFace* _iface,
     const SDL_Rect * ___a)
{
  return SDL_SetTextInputRect(___a);
}

STATIC void 
SDL2Gate_SDL_SetTextInputRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Rect * ___a = (const SDL_Rect *) regarray[REG68K_A0/4];

  return _iface->SDL_SetTextInputRect(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextInputRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetTextInputRectPPC };

SDL_bool SDL_HasScreenKeyboardSupport(void);

SDL_bool
SDL2Gate_SDL_HasScreenKeyboardSupport(struct SDL2IFace* _iface)
{
  return SDL_HasScreenKeyboardSupport();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasScreenKeyboardSupportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasScreenKeyboardSupport();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasScreenKeyboardSupport = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasScreenKeyboardSupportPPC };

SDL_bool SDL_IsScreenKeyboardShown(SDL_Window * ___a);

SDL_bool
SDL2Gate_SDL_IsScreenKeyboardShown(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_IsScreenKeyboardShown(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_IsScreenKeyboardShownPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_IsScreenKeyboardShown(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsScreenKeyboardShown = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsScreenKeyboardShownPPC };

void* SDL_LoadObject(const char * ___a);

void*
SDL2Gate_SDL_LoadObject(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_LoadObject(___a);
}

STATIC void* 
SDL2Gate_SDL_LoadObjectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_LoadObject(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadObject = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadObjectPPC };

void* SDL_LoadFunction(void * ___a, const char * ___b);

void*
SDL2Gate_SDL_LoadFunction(struct SDL2IFace* _iface,
     void * ___a,
     const char * ___b)
{
  return SDL_LoadFunction(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_LoadFunctionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_LoadFunction(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadFunction = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadFunctionPPC };

void SDL_UnloadObject(void * ___a);

void
SDL2Gate_SDL_UnloadObject(struct SDL2IFace* _iface,
     void * ___a)
{
  return SDL_UnloadObject(___a);
}

STATIC void 
SDL2Gate_SDL_UnloadObjectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_UnloadObject(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnloadObject = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnloadObjectPPC };

void SDL_LogSetAllPriority(SDL_LogPriority ___a);

void
SDL2Gate_SDL_LogSetAllPriority(struct SDL2IFace* _iface,
     SDL_LogPriority ___a)
{
  return SDL_LogSetAllPriority(___a);
}

STATIC void 
SDL2Gate_SDL_LogSetAllPriorityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_LogPriority ___a = (SDL_LogPriority) regarray[REG68K_D0/4];

  return _iface->SDL_LogSetAllPriority(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LogSetAllPriority = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LogSetAllPriorityPPC };

void SDL_LogSetPriority(int ___a, SDL_LogPriority ___b);

void
SDL2Gate_SDL_LogSetPriority(struct SDL2IFace* _iface,
     int ___a,
     SDL_LogPriority ___b)
{
  return SDL_LogSetPriority(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_LogSetPriorityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  SDL_LogPriority ___b = (SDL_LogPriority) regarray[REG68K_D1/4];

  return _iface->SDL_LogSetPriority(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LogSetPriority = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LogSetPriorityPPC };

SDL_LogPriority SDL_LogGetPriority(int ___a);

SDL_LogPriority
SDL2Gate_SDL_LogGetPriority(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_LogGetPriority(___a);
}

STATIC SDL_LogPriority 
SDL2Gate_SDL_LogGetPriorityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_LogGetPriority(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LogGetPriority = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LogGetPriorityPPC };

void SDL_LogResetPriorities(void);

void
SDL2Gate_SDL_LogResetPriorities(struct SDL2IFace* _iface)
{
  return SDL_LogResetPriorities();
}

STATIC void 
SDL2Gate_SDL_LogResetPrioritiesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_LogResetPriorities();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LogResetPriorities = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LogResetPrioritiesPPC };

void SDL_LogGetOutputFunction(SDL_LogOutputFunction * ___a, void * * ___b);

void
SDL2Gate_SDL_LogGetOutputFunction(struct SDL2IFace* _iface,
     SDL_LogOutputFunction * ___a,
     void * * ___b)
{
  return SDL_LogGetOutputFunction(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_LogGetOutputFunctionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_LogOutputFunction * ___a = (SDL_LogOutputFunction *) regarray[REG68K_A0/4];
  void * * ___b = (void * *) regarray[REG68K_A1/4];

  return _iface->SDL_LogGetOutputFunction(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LogGetOutputFunction = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LogGetOutputFunctionPPC };

void SDL_LogSetOutputFunction(SDL_LogOutputFunction ___a, void * ___b);

void
SDL2Gate_SDL_LogSetOutputFunction(struct SDL2IFace* _iface,
     SDL_LogOutputFunction ___a,
     void * ___b)
{
  return SDL_LogSetOutputFunction(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_LogSetOutputFunctionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_LogOutputFunction ___a = (SDL_LogOutputFunction) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_LogSetOutputFunction(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LogSetOutputFunction = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LogSetOutputFunctionPPC };

void SDL_SetMainReady(void);

void
SDL2Gate_SDL_SetMainReady(struct SDL2IFace* _iface)
{
  return SDL_SetMainReady();
}

STATIC void 
SDL2Gate_SDL_SetMainReadyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_SetMainReady();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetMainReady = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetMainReadyPPC };

int SDL_ShowMessageBox(const SDL_MessageBoxData * ___a, int * ___b);

int
SDL2Gate_SDL_ShowMessageBox(struct SDL2IFace* _iface,
     const SDL_MessageBoxData * ___a,
     int * ___b)
{
  return SDL_ShowMessageBox(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_ShowMessageBoxPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_MessageBoxData * ___a = (const SDL_MessageBoxData *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];

  return _iface->SDL_ShowMessageBox(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ShowMessageBox = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ShowMessageBoxPPC };

int SDL_ShowSimpleMessageBox(Uint32 ___a, const char * ___b, const char * ___c, SDL_Window * ___d);

int
SDL2Gate_SDL_ShowSimpleMessageBox(struct SDL2IFace* _iface,
     Uint32 ___a,
     const char * ___b,
     const char * ___c,
     SDL_Window * ___d)
{
  return SDL_ShowSimpleMessageBox(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_ShowSimpleMessageBoxPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  const char * ___b = (const char *) regarray[REG68K_A0/4];
  const char * ___c = (const char *) regarray[REG68K_A1/4];
  SDL_Window * ___d = (SDL_Window *) regarray[REG68K_A2/4];

  return _iface->SDL_ShowSimpleMessageBox(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ShowSimpleMessageBox = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ShowSimpleMessageBoxPPC };

SDL_Window* SDL_GetMouseFocus(void);

SDL_Window*
SDL2Gate_SDL_GetMouseFocus(struct SDL2IFace* _iface)
{
  return SDL_GetMouseFocus();
}

STATIC SDL_Window* 
SDL2Gate_SDL_GetMouseFocusPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetMouseFocus();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetMouseFocus = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetMouseFocusPPC };

Uint32 SDL_GetMouseState(int * ___a, int * ___b);

Uint32
SDL2Gate_SDL_GetMouseState(struct SDL2IFace* _iface,
     int * ___a,
     int * ___b)
{
  return SDL_GetMouseState(___a, ___b);
}

STATIC Uint32 
SDL2Gate_SDL_GetMouseStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int * ___a = (int *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];

  return _iface->SDL_GetMouseState(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetMouseState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetMouseStatePPC };

Uint32 SDL_GetRelativeMouseState(int * ___a, int * ___b);

Uint32
SDL2Gate_SDL_GetRelativeMouseState(struct SDL2IFace* _iface,
     int * ___a,
     int * ___b)
{
  return SDL_GetRelativeMouseState(___a, ___b);
}

STATIC Uint32 
SDL2Gate_SDL_GetRelativeMouseStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int * ___a = (int *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];

  return _iface->SDL_GetRelativeMouseState(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRelativeMouseState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRelativeMouseStatePPC };

void SDL_WarpMouseInWindow(SDL_Window * ___a, int ___b, int ___c);

void
SDL2Gate_SDL_WarpMouseInWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c)
{
  return SDL_WarpMouseInWindow(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_WarpMouseInWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_WarpMouseInWindow(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WarpMouseInWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WarpMouseInWindowPPC };

int SDL_SetRelativeMouseMode(SDL_bool ___a);

int
SDL2Gate_SDL_SetRelativeMouseMode(struct SDL2IFace* _iface,
     SDL_bool ___a)
{
  return SDL_SetRelativeMouseMode(___a);
}

STATIC int 
SDL2Gate_SDL_SetRelativeMouseModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_bool ___a = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetRelativeMouseMode(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetRelativeMouseMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetRelativeMouseModePPC };

SDL_bool SDL_GetRelativeMouseMode(void);

SDL_bool
SDL2Gate_SDL_GetRelativeMouseMode(struct SDL2IFace* _iface)
{
  return SDL_GetRelativeMouseMode();
}

STATIC SDL_bool 
SDL2Gate_SDL_GetRelativeMouseModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetRelativeMouseMode();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRelativeMouseMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRelativeMouseModePPC };

SDL_Cursor* SDL_CreateCursor(const Uint8 * ___a, const Uint8 * ___b, int ___c, int ___d, int ___e, int ___f);

SDL_Cursor*
SDL2Gate_SDL_CreateCursor(struct SDL2IFace* _iface,
     const Uint8 * ___a,
     const Uint8 * ___b,
     int ___c,
     int ___d,
     int ___e,
     int ___f)
{
  return SDL_CreateCursor(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_Cursor* 
SDL2Gate_SDL_CreateCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const Uint8 * ___a = (const Uint8 *) regarray[REG68K_A0/4];
  const Uint8 * ___b = (const Uint8 *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];
  int ___d = (int) regarray[REG68K_D1/4];
  int ___e = (int) regarray[REG68K_D2/4];
  int ___f = (int) regarray[REG68K_D3/4];

  return _iface->SDL_CreateCursor(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateCursorPPC };

SDL_Cursor* SDL_CreateColorCursor(SDL_Surface * ___a, int ___b, int ___c);

SDL_Cursor*
SDL2Gate_SDL_CreateColorCursor(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     int ___b,
     int ___c)
{
  return SDL_CreateColorCursor(___a, ___b, ___c);
}

STATIC SDL_Cursor* 
SDL2Gate_SDL_CreateColorCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_CreateColorCursor(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateColorCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateColorCursorPPC };

SDL_Cursor* SDL_CreateSystemCursor(SDL_SystemCursor ___a);

SDL_Cursor*
SDL2Gate_SDL_CreateSystemCursor(struct SDL2IFace* _iface,
     SDL_SystemCursor ___a)
{
  return SDL_CreateSystemCursor(___a);
}

STATIC SDL_Cursor* 
SDL2Gate_SDL_CreateSystemCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_SystemCursor ___a = (SDL_SystemCursor) regarray[REG68K_D0/4];

  return _iface->SDL_CreateSystemCursor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateSystemCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateSystemCursorPPC };

void SDL_SetCursor(SDL_Cursor * ___a);

void
SDL2Gate_SDL_SetCursor(struct SDL2IFace* _iface,
     SDL_Cursor * ___a)
{
  return SDL_SetCursor(___a);
}

STATIC void 
SDL2Gate_SDL_SetCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Cursor * ___a = (SDL_Cursor *) regarray[REG68K_A0/4];

  return _iface->SDL_SetCursor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetCursorPPC };

SDL_Cursor* SDL_GetCursor(void);

SDL_Cursor*
SDL2Gate_SDL_GetCursor(struct SDL2IFace* _iface)
{
  return SDL_GetCursor();
}

STATIC SDL_Cursor* 
SDL2Gate_SDL_GetCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetCursor();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetCursorPPC };

SDL_Cursor* SDL_GetDefaultCursor(void);

SDL_Cursor*
SDL2Gate_SDL_GetDefaultCursor(struct SDL2IFace* _iface)
{
  return SDL_GetDefaultCursor();
}

STATIC SDL_Cursor* 
SDL2Gate_SDL_GetDefaultCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetDefaultCursor();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDefaultCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDefaultCursorPPC };

void SDL_FreeCursor(SDL_Cursor * ___a);

void
SDL2Gate_SDL_FreeCursor(struct SDL2IFace* _iface,
     SDL_Cursor * ___a)
{
  return SDL_FreeCursor(___a);
}

STATIC void 
SDL2Gate_SDL_FreeCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Cursor * ___a = (SDL_Cursor *) regarray[REG68K_A0/4];

  return _iface->SDL_FreeCursor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreeCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreeCursorPPC };

int SDL_ShowCursor(int ___a);

int
SDL2Gate_SDL_ShowCursor(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_ShowCursor(___a);
}

STATIC int 
SDL2Gate_SDL_ShowCursorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_ShowCursor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ShowCursor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ShowCursorPPC };

SDL_mutex* SDL_CreateMutex(void);

SDL_mutex*
SDL2Gate_SDL_CreateMutex(struct SDL2IFace* _iface)
{
  return SDL_CreateMutex();
}

STATIC SDL_mutex* 
SDL2Gate_SDL_CreateMutexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_CreateMutex();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateMutex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateMutexPPC };

int SDL_LockMutex(SDL_mutex * ___a);

int
SDL2Gate_SDL_LockMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a)
{
  return SDL_LockMutex(___a);
}

STATIC int 
SDL2Gate_SDL_LockMutexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_mutex * ___a = (SDL_mutex *) regarray[REG68K_A0/4];

  return _iface->SDL_LockMutex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockMutex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockMutexPPC };

int SDL_TryLockMutex(SDL_mutex * ___a);

int
SDL2Gate_SDL_TryLockMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a)
{
  return SDL_TryLockMutex(___a);
}

STATIC int 
SDL2Gate_SDL_TryLockMutexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_mutex * ___a = (SDL_mutex *) regarray[REG68K_A0/4];

  return _iface->SDL_TryLockMutex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_TryLockMutex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_TryLockMutexPPC };

int SDL_UnlockMutex(SDL_mutex * ___a);

int
SDL2Gate_SDL_UnlockMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a)
{
  return SDL_UnlockMutex(___a);
}

STATIC int 
SDL2Gate_SDL_UnlockMutexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_mutex * ___a = (SDL_mutex *) regarray[REG68K_A0/4];

  return _iface->SDL_UnlockMutex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockMutex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockMutexPPC };

void SDL_DestroyMutex(SDL_mutex * ___a);

void
SDL2Gate_SDL_DestroyMutex(struct SDL2IFace* _iface,
     SDL_mutex * ___a)
{
  return SDL_DestroyMutex(___a);
}

STATIC void 
SDL2Gate_SDL_DestroyMutexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_mutex * ___a = (SDL_mutex *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroyMutex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyMutex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroyMutexPPC };

SDL_sem* SDL_CreateSemaphore(Uint32 ___a);

SDL_sem*
SDL2Gate_SDL_CreateSemaphore(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_CreateSemaphore(___a);
}

STATIC SDL_sem* 
SDL2Gate_SDL_CreateSemaphorePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_CreateSemaphore(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateSemaphore = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateSemaphorePPC };

void SDL_DestroySemaphore(SDL_sem * ___a);

void
SDL2Gate_SDL_DestroySemaphore(struct SDL2IFace* _iface,
     SDL_sem * ___a)
{
  return SDL_DestroySemaphore(___a);
}

STATIC void 
SDL2Gate_SDL_DestroySemaphorePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_sem * ___a = (SDL_sem *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroySemaphore(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroySemaphore = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroySemaphorePPC };

int SDL_SemWait(SDL_sem * ___a);

int
SDL2Gate_SDL_SemWait(struct SDL2IFace* _iface,
     SDL_sem * ___a)
{
  return SDL_SemWait(___a);
}

STATIC int 
SDL2Gate_SDL_SemWaitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_sem * ___a = (SDL_sem *) regarray[REG68K_A0/4];

  return _iface->SDL_SemWait(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SemWait = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SemWaitPPC };

int SDL_SemTryWait(SDL_sem * ___a);

int
SDL2Gate_SDL_SemTryWait(struct SDL2IFace* _iface,
     SDL_sem * ___a)
{
  return SDL_SemTryWait(___a);
}

STATIC int 
SDL2Gate_SDL_SemTryWaitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_sem * ___a = (SDL_sem *) regarray[REG68K_A0/4];

  return _iface->SDL_SemTryWait(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SemTryWait = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SemTryWaitPPC };

int SDL_SemWaitTimeout(SDL_sem * ___a, Uint32 ___b);

int
SDL2Gate_SDL_SemWaitTimeout(struct SDL2IFace* _iface,
     SDL_sem * ___a,
     Uint32 ___b)
{
  return SDL_SemWaitTimeout(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SemWaitTimeoutPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_sem * ___a = (SDL_sem *) regarray[REG68K_A0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_SemWaitTimeout(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SemWaitTimeout = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SemWaitTimeoutPPC };

int SDL_SemPost(SDL_sem * ___a);

int
SDL2Gate_SDL_SemPost(struct SDL2IFace* _iface,
     SDL_sem * ___a)
{
  return SDL_SemPost(___a);
}

STATIC int 
SDL2Gate_SDL_SemPostPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_sem * ___a = (SDL_sem *) regarray[REG68K_A0/4];

  return _iface->SDL_SemPost(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SemPost = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SemPostPPC };

Uint32 SDL_SemValue(SDL_sem * ___a);

Uint32
SDL2Gate_SDL_SemValue(struct SDL2IFace* _iface,
     SDL_sem * ___a)
{
  return SDL_SemValue(___a);
}

STATIC Uint32 
SDL2Gate_SDL_SemValuePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_sem * ___a = (SDL_sem *) regarray[REG68K_A0/4];

  return _iface->SDL_SemValue(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SemValue = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SemValuePPC };

SDL_cond* SDL_CreateCond(void);

SDL_cond*
SDL2Gate_SDL_CreateCond(struct SDL2IFace* _iface)
{
  return SDL_CreateCond();
}

STATIC SDL_cond* 
SDL2Gate_SDL_CreateCondPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_CreateCond();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateCond = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateCondPPC };

void SDL_DestroyCond(SDL_cond * ___a);

void
SDL2Gate_SDL_DestroyCond(struct SDL2IFace* _iface,
     SDL_cond * ___a)
{
  return SDL_DestroyCond(___a);
}

STATIC void 
SDL2Gate_SDL_DestroyCondPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_cond * ___a = (SDL_cond *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroyCond(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyCond = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroyCondPPC };

int SDL_CondSignal(SDL_cond * ___a);

int
SDL2Gate_SDL_CondSignal(struct SDL2IFace* _iface,
     SDL_cond * ___a)
{
  return SDL_CondSignal(___a);
}

STATIC int 
SDL2Gate_SDL_CondSignalPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_cond * ___a = (SDL_cond *) regarray[REG68K_A0/4];

  return _iface->SDL_CondSignal(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CondSignal = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CondSignalPPC };

int SDL_CondBroadcast(SDL_cond * ___a);

int
SDL2Gate_SDL_CondBroadcast(struct SDL2IFace* _iface,
     SDL_cond * ___a)
{
  return SDL_CondBroadcast(___a);
}

STATIC int 
SDL2Gate_SDL_CondBroadcastPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_cond * ___a = (SDL_cond *) regarray[REG68K_A0/4];

  return _iface->SDL_CondBroadcast(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CondBroadcast = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CondBroadcastPPC };

int SDL_CondWait(SDL_cond * ___a, SDL_mutex * ___b);

int
SDL2Gate_SDL_CondWait(struct SDL2IFace* _iface,
     SDL_cond * ___a,
     SDL_mutex * ___b)
{
  return SDL_CondWait(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_CondWaitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_cond * ___a = (SDL_cond *) regarray[REG68K_A0/4];
  SDL_mutex * ___b = (SDL_mutex *) regarray[REG68K_A1/4];

  return _iface->SDL_CondWait(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CondWait = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CondWaitPPC };

int SDL_CondWaitTimeout(SDL_cond * ___a, SDL_mutex * ___b, Uint32 ___c);

int
SDL2Gate_SDL_CondWaitTimeout(struct SDL2IFace* _iface,
     SDL_cond * ___a,
     SDL_mutex * ___b,
     Uint32 ___c)
{
  return SDL_CondWaitTimeout(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_CondWaitTimeoutPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_cond * ___a = (SDL_cond *) regarray[REG68K_A0/4];
  SDL_mutex * ___b = (SDL_mutex *) regarray[REG68K_A1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_CondWaitTimeout(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CondWaitTimeout = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CondWaitTimeoutPPC };

const char* SDL_GetPixelFormatName(Uint32 ___a);

const char*
SDL2Gate_SDL_GetPixelFormatName(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_GetPixelFormatName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetPixelFormatNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_GetPixelFormatName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPixelFormatName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPixelFormatNamePPC };

SDL_bool SDL_PixelFormatEnumToMasks(Uint32 ___a, int * ___b, Uint32 * ___c, Uint32 * ___d, Uint32 * ___e, Uint32 * ___f);

SDL_bool
SDL2Gate_SDL_PixelFormatEnumToMasks(struct SDL2IFace* _iface,
     Uint32 ___a,
     int * ___b,
     Uint32 * ___c,
     Uint32 * ___d,
     Uint32 * ___e,
     Uint32 * ___f)
{
  return SDL_PixelFormatEnumToMasks(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_bool 
SDL2Gate_SDL_PixelFormatEnumToMasksPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  int * ___b = (int *) regarray[REG68K_A0/4];
  Uint32 * ___c = (Uint32 *) regarray[REG68K_A1/4];
  Uint32 * ___d = (Uint32 *) regarray[REG68K_A2/4];
  Uint32 * ___e = (Uint32 *) regarray[REG68K_A3/4];
  Uint32 * ___f = (Uint32 *) regarray[REG68K_D1/4];

  return _iface->SDL_PixelFormatEnumToMasks(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PixelFormatEnumToMasks = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PixelFormatEnumToMasksPPC };

Uint32 SDL_MasksToPixelFormatEnum(int ___a, Uint32 ___b, Uint32 ___c, Uint32 ___d, Uint32 ___e);

Uint32
SDL2Gate_SDL_MasksToPixelFormatEnum(struct SDL2IFace* _iface,
     int ___a,
     Uint32 ___b,
     Uint32 ___c,
     Uint32 ___d,
     Uint32 ___e)
{
  return SDL_MasksToPixelFormatEnum(___a, ___b, ___c, ___d, ___e);
}

STATIC Uint32 
SDL2Gate_SDL_MasksToPixelFormatEnumPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D2/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D3/4];
  Uint32 ___e = (Uint32) regarray[REG68K_D4/4];

  return _iface->SDL_MasksToPixelFormatEnum(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MasksToPixelFormatEnum = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MasksToPixelFormatEnumPPC };

SDL_PixelFormat* SDL_AllocFormat(Uint32 ___a);

SDL_PixelFormat*
SDL2Gate_SDL_AllocFormat(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_AllocFormat(___a);
}

STATIC SDL_PixelFormat* 
SDL2Gate_SDL_AllocFormatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_AllocFormat(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AllocFormat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AllocFormatPPC };

void SDL_FreeFormat(SDL_PixelFormat * ___a);

void
SDL2Gate_SDL_FreeFormat(struct SDL2IFace* _iface,
     SDL_PixelFormat * ___a)
{
  return SDL_FreeFormat(___a);
}

STATIC void 
SDL2Gate_SDL_FreeFormatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_PixelFormat * ___a = (SDL_PixelFormat *) regarray[REG68K_A0/4];

  return _iface->SDL_FreeFormat(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreeFormat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreeFormatPPC };

SDL_Palette* SDL_AllocPalette(int ___a);

SDL_Palette*
SDL2Gate_SDL_AllocPalette(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_AllocPalette(___a);
}

STATIC SDL_Palette* 
SDL2Gate_SDL_AllocPalettePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_AllocPalette(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AllocPalette = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AllocPalettePPC };

int SDL_SetPixelFormatPalette(SDL_PixelFormat * ___a, SDL_Palette * ___b);

int
SDL2Gate_SDL_SetPixelFormatPalette(struct SDL2IFace* _iface,
     SDL_PixelFormat * ___a,
     SDL_Palette * ___b)
{
  return SDL_SetPixelFormatPalette(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetPixelFormatPalettePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_PixelFormat * ___a = (SDL_PixelFormat *) regarray[REG68K_A0/4];
  SDL_Palette * ___b = (SDL_Palette *) regarray[REG68K_A1/4];

  return _iface->SDL_SetPixelFormatPalette(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetPixelFormatPalette = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetPixelFormatPalettePPC };

int SDL_SetPaletteColors(SDL_Palette * ___a, const SDL_Color * ___b, int ___c, int ___d);

int
SDL2Gate_SDL_SetPaletteColors(struct SDL2IFace* _iface,
     SDL_Palette * ___a,
     const SDL_Color * ___b,
     int ___c,
     int ___d)
{
  return SDL_SetPaletteColors(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SetPaletteColorsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Palette * ___a = (SDL_Palette *) regarray[REG68K_A0/4];
  const SDL_Color * ___b = (const SDL_Color *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];
  int ___d = (int) regarray[REG68K_D1/4];

  return _iface->SDL_SetPaletteColors(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetPaletteColors = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetPaletteColorsPPC };

void SDL_FreePalette(SDL_Palette * ___a);

void
SDL2Gate_SDL_FreePalette(struct SDL2IFace* _iface,
     SDL_Palette * ___a)
{
  return SDL_FreePalette(___a);
}

STATIC void 
SDL2Gate_SDL_FreePalettePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Palette * ___a = (SDL_Palette *) regarray[REG68K_A0/4];

  return _iface->SDL_FreePalette(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreePalette = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreePalettePPC };

Uint32 SDL_MapRGB(const SDL_PixelFormat * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d);

Uint32
SDL2Gate_SDL_MapRGB(struct SDL2IFace* _iface,
     const SDL_PixelFormat * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d)
{
  return SDL_MapRGB(___a, ___b, ___c, ___d);
}

STATIC Uint32 
SDL2Gate_SDL_MapRGBPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_PixelFormat * ___a = (const SDL_PixelFormat *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];

  return _iface->SDL_MapRGB(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MapRGB = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MapRGBPPC };

Uint32 SDL_MapRGBA(const SDL_PixelFormat * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d, Uint8 ___e);

Uint32
SDL2Gate_SDL_MapRGBA(struct SDL2IFace* _iface,
     const SDL_PixelFormat * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d,
     Uint8 ___e)
{
  return SDL_MapRGBA(___a, ___b, ___c, ___d, ___e);
}

STATIC Uint32 
SDL2Gate_SDL_MapRGBAPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_PixelFormat * ___a = (const SDL_PixelFormat *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];
  Uint8 ___e = (Uint8) regarray[REG68K_D3/4];

  return _iface->SDL_MapRGBA(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MapRGBA = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MapRGBAPPC };

void SDL_GetRGB(Uint32 ___a, const SDL_PixelFormat * ___b, Uint8 * ___c, Uint8 * ___d, Uint8 * ___e);

void
SDL2Gate_SDL_GetRGB(struct SDL2IFace* _iface,
     Uint32 ___a,
     const SDL_PixelFormat * ___b,
     Uint8 * ___c,
     Uint8 * ___d,
     Uint8 * ___e)
{
  return SDL_GetRGB(___a, ___b, ___c, ___d, ___e);
}

STATIC void 
SDL2Gate_SDL_GetRGBPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  const SDL_PixelFormat * ___b = (const SDL_PixelFormat *) regarray[REG68K_A0/4];
  Uint8 * ___c = (Uint8 *) regarray[REG68K_A1/4];
  Uint8 * ___d = (Uint8 *) regarray[REG68K_A2/4];
  Uint8 * ___e = (Uint8 *) regarray[REG68K_A3/4];

  return _iface->SDL_GetRGB(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRGB = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRGBPPC };

void SDL_GetRGBA(Uint32 ___a, const SDL_PixelFormat * ___b, Uint8 * ___c, Uint8 * ___d, Uint8 * ___e, Uint8 * ___f);

void
SDL2Gate_SDL_GetRGBA(struct SDL2IFace* _iface,
     Uint32 ___a,
     const SDL_PixelFormat * ___b,
     Uint8 * ___c,
     Uint8 * ___d,
     Uint8 * ___e,
     Uint8 * ___f)
{
  return SDL_GetRGBA(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC void 
SDL2Gate_SDL_GetRGBAPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  const SDL_PixelFormat * ___b = (const SDL_PixelFormat *) regarray[REG68K_A0/4];
  Uint8 * ___c = (Uint8 *) regarray[REG68K_A1/4];
  Uint8 * ___d = (Uint8 *) regarray[REG68K_A2/4];
  Uint8 * ___e = (Uint8 *) regarray[REG68K_A3/4];
  Uint8 * ___f = (Uint8 *) regarray[REG68K_D1/4];

  return _iface->SDL_GetRGBA(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRGBA = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRGBAPPC };

void SDL_CalculateGammaRamp(float ___a, Uint16 * ___b);

void
SDL2Gate_SDL_CalculateGammaRamp(struct SDL2IFace* _iface,
     float ___a,
     Uint16 * ___b)
{
  return SDL_CalculateGammaRamp(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_CalculateGammaRampPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];
  Uint16 * ___b = (Uint16 *) regarray[REG68K_A0/4];

  return _iface->SDL_CalculateGammaRamp(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CalculateGammaRamp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CalculateGammaRampPPC };

const char* SDL_GetPlatform(void);

const char*
SDL2Gate_SDL_GetPlatform(struct SDL2IFace* _iface)
{
  return SDL_GetPlatform();
}

STATIC const char* 
SDL2Gate_SDL_GetPlatformPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetPlatform();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPlatform = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPlatformPPC };

SDL_bool SDL_HasIntersection(const SDL_Rect * ___a, const SDL_Rect * ___b);

SDL_bool
SDL2Gate_SDL_HasIntersection(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     const SDL_Rect * ___b)
{
  return SDL_HasIntersection(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasIntersectionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Rect * ___a = (const SDL_Rect *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_HasIntersection(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasIntersection = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasIntersectionPPC };

SDL_bool SDL_IntersectRect(const SDL_Rect * ___a, const SDL_Rect * ___b, SDL_Rect * ___c);

SDL_bool
SDL2Gate_SDL_IntersectRect(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     const SDL_Rect * ___b,
     SDL_Rect * ___c)
{
  return SDL_IntersectRect(___a, ___b, ___c);
}

STATIC SDL_bool 
SDL2Gate_SDL_IntersectRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Rect * ___a = (const SDL_Rect *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Rect * ___c = (SDL_Rect *) regarray[REG68K_A2/4];

  return _iface->SDL_IntersectRect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IntersectRectPPC };

void SDL_UnionRect(const SDL_Rect * ___a, const SDL_Rect * ___b, SDL_Rect * ___c);

void
SDL2Gate_SDL_UnionRect(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     const SDL_Rect * ___b,
     SDL_Rect * ___c)
{
  return SDL_UnionRect(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_UnionRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Rect * ___a = (const SDL_Rect *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Rect * ___c = (SDL_Rect *) regarray[REG68K_A2/4];

  return _iface->SDL_UnionRect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnionRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnionRectPPC };

SDL_bool SDL_EnclosePoints(const SDL_Point * ___a, int ___b, const SDL_Rect * ___c, SDL_Rect * ___d);

SDL_bool
SDL2Gate_SDL_EnclosePoints(struct SDL2IFace* _iface,
     const SDL_Point * ___a,
     int ___b,
     const SDL_Rect * ___c,
     SDL_Rect * ___d)
{
  return SDL_EnclosePoints(___a, ___b, ___c, ___d);
}

STATIC SDL_bool 
SDL2Gate_SDL_EnclosePointsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Point * ___a = (const SDL_Point *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  const SDL_Rect * ___c = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Rect * ___d = (SDL_Rect *) regarray[REG68K_A2/4];

  return _iface->SDL_EnclosePoints(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_EnclosePoints = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_EnclosePointsPPC };

SDL_bool SDL_IntersectRectAndLine(const SDL_Rect * ___a, int * ___b, int * ___c, int * ___d, int * ___e);

SDL_bool
SDL2Gate_SDL_IntersectRectAndLine(struct SDL2IFace* _iface,
     const SDL_Rect * ___a,
     int * ___b,
     int * ___c,
     int * ___d,
     int * ___e)
{
  return SDL_IntersectRectAndLine(___a, ___b, ___c, ___d, ___e);
}

STATIC SDL_bool 
SDL2Gate_SDL_IntersectRectAndLinePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Rect * ___a = (const SDL_Rect *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];
  int * ___d = (int *) regarray[REG68K_A3/4];
  int * ___e = (int *) regarray[REG68K_D0/4];

  return _iface->SDL_IntersectRectAndLine(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectRectAndLine = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IntersectRectAndLinePPC };

int SDL_GetNumRenderDrivers(void);

int
SDL2Gate_SDL_GetNumRenderDrivers(struct SDL2IFace* _iface)
{
  return SDL_GetNumRenderDrivers();
}

STATIC int 
SDL2Gate_SDL_GetNumRenderDriversPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetNumRenderDrivers();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumRenderDrivers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumRenderDriversPPC };

int SDL_GetRenderDriverInfo(int ___a, SDL_RendererInfo * ___b);

int
SDL2Gate_SDL_GetRenderDriverInfo(struct SDL2IFace* _iface,
     int ___a,
     SDL_RendererInfo * ___b)
{
  return SDL_GetRenderDriverInfo(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetRenderDriverInfoPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  SDL_RendererInfo * ___b = (SDL_RendererInfo *) regarray[REG68K_A0/4];

  return _iface->SDL_GetRenderDriverInfo(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderDriverInfo = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRenderDriverInfoPPC };

int SDL_CreateWindowAndRenderer(int ___a, int ___b, Uint32 ___c, SDL_Window * * ___d, SDL_Renderer * * ___e);

int
SDL2Gate_SDL_CreateWindowAndRenderer(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     Uint32 ___c,
     SDL_Window * * ___d,
     SDL_Renderer * * ___e)
{
  return SDL_CreateWindowAndRenderer(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_CreateWindowAndRendererPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D2/4];
  SDL_Window * * ___d = (SDL_Window * *) regarray[REG68K_A0/4];
  SDL_Renderer * * ___e = (SDL_Renderer * *) regarray[REG68K_A1/4];

  return _iface->SDL_CreateWindowAndRenderer(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateWindowAndRenderer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateWindowAndRendererPPC };

SDL_Renderer* SDL_CreateRenderer(SDL_Window * ___a, int ___b, Uint32 ___c);

SDL_Renderer*
SDL2Gate_SDL_CreateRenderer(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     Uint32 ___c)
{
  return SDL_CreateRenderer(___a, ___b, ___c);
}

STATIC SDL_Renderer* 
SDL2Gate_SDL_CreateRendererPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_CreateRenderer(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRenderer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateRendererPPC };

SDL_Renderer* SDL_CreateSoftwareRenderer(SDL_Surface * ___a);

SDL_Renderer*
SDL2Gate_SDL_CreateSoftwareRenderer(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_CreateSoftwareRenderer(___a);
}

STATIC SDL_Renderer* 
SDL2Gate_SDL_CreateSoftwareRendererPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_CreateSoftwareRenderer(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateSoftwareRenderer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateSoftwareRendererPPC };

SDL_Renderer* SDL_GetRenderer(SDL_Window * ___a);

SDL_Renderer*
SDL2Gate_SDL_GetRenderer(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetRenderer(___a);
}

STATIC SDL_Renderer* 
SDL2Gate_SDL_GetRendererPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetRenderer(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRendererPPC };

int SDL_GetRendererInfo(SDL_Renderer * ___a, SDL_RendererInfo * ___b);

int
SDL2Gate_SDL_GetRendererInfo(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_RendererInfo * ___b)
{
  return SDL_GetRendererInfo(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetRendererInfoPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_RendererInfo * ___b = (SDL_RendererInfo *) regarray[REG68K_A1/4];

  return _iface->SDL_GetRendererInfo(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRendererInfo = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRendererInfoPPC };

int SDL_GetRendererOutputSize(SDL_Renderer * ___a, int * ___b, int * ___c);

int
SDL2Gate_SDL_GetRendererOutputSize(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GetRendererOutputSize(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GetRendererOutputSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GetRendererOutputSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRendererOutputSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRendererOutputSizePPC };

SDL_Texture* SDL_CreateTexture(SDL_Renderer * ___a, Uint32 ___b, int ___c, int ___d, int ___e);

SDL_Texture*
SDL2Gate_SDL_CreateTexture(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     Uint32 ___b,
     int ___c,
     int ___d,
     int ___e)
{
  return SDL_CreateTexture(___a, ___b, ___c, ___d, ___e);
}

STATIC SDL_Texture* 
SDL2Gate_SDL_CreateTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  int ___d = (int) regarray[REG68K_D2/4];
  int ___e = (int) regarray[REG68K_D3/4];

  return _iface->SDL_CreateTexture(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateTexturePPC };

SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer * ___a, SDL_Surface * ___b);

SDL_Texture*
SDL2Gate_SDL_CreateTextureFromSurface(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Surface * ___b)
{
  return SDL_CreateTextureFromSurface(___a, ___b);
}

STATIC SDL_Texture* 
SDL2Gate_SDL_CreateTextureFromSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Surface * ___b = (SDL_Surface *) regarray[REG68K_A1/4];

  return _iface->SDL_CreateTextureFromSurface(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateTextureFromSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateTextureFromSurfacePPC };

int SDL_QueryTexture(SDL_Texture * ___a, Uint32 * ___b, int * ___c, int * ___d, int * ___e);

int
SDL2Gate_SDL_QueryTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint32 * ___b,
     int * ___c,
     int * ___d,
     int * ___e)
{
  return SDL_QueryTexture(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_QueryTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  Uint32 * ___b = (Uint32 *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];
  int * ___d = (int *) regarray[REG68K_A3/4];
  int * ___e = (int *) regarray[REG68K_D0/4];

  return _iface->SDL_QueryTexture(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_QueryTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_QueryTexturePPC };

int SDL_SetTextureColorMod(SDL_Texture * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d);

int
SDL2Gate_SDL_SetTextureColorMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d)
{
  return SDL_SetTextureColorMod(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SetTextureColorModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];

  return _iface->SDL_SetTextureColorMod(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureColorMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetTextureColorModPPC };

int SDL_GetTextureColorMod(SDL_Texture * ___a, Uint8 * ___b, Uint8 * ___c, Uint8 * ___d);

int
SDL2Gate_SDL_GetTextureColorMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 * ___b,
     Uint8 * ___c,
     Uint8 * ___d)
{
  return SDL_GetTextureColorMod(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GetTextureColorModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  Uint8 * ___b = (Uint8 *) regarray[REG68K_A1/4];
  Uint8 * ___c = (Uint8 *) regarray[REG68K_A2/4];
  Uint8 * ___d = (Uint8 *) regarray[REG68K_A3/4];

  return _iface->SDL_GetTextureColorMod(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureColorMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTextureColorModPPC };

int SDL_SetTextureAlphaMod(SDL_Texture * ___a, Uint8 ___b);

int
SDL2Gate_SDL_SetTextureAlphaMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 ___b)
{
  return SDL_SetTextureAlphaMod(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetTextureAlphaModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];

  return _iface->SDL_SetTextureAlphaMod(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureAlphaMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetTextureAlphaModPPC };

int SDL_GetTextureAlphaMod(SDL_Texture * ___a, Uint8 * ___b);

int
SDL2Gate_SDL_GetTextureAlphaMod(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     Uint8 * ___b)
{
  return SDL_GetTextureAlphaMod(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetTextureAlphaModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  Uint8 * ___b = (Uint8 *) regarray[REG68K_A1/4];

  return _iface->SDL_GetTextureAlphaMod(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureAlphaMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTextureAlphaModPPC };

int SDL_SetTextureBlendMode(SDL_Texture * ___a, SDL_BlendMode ___b);

int
SDL2Gate_SDL_SetTextureBlendMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_BlendMode ___b)
{
  return SDL_SetTextureBlendMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetTextureBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  SDL_BlendMode ___b = (SDL_BlendMode) regarray[REG68K_D0/4];

  return _iface->SDL_SetTextureBlendMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetTextureBlendModePPC };

int SDL_GetTextureBlendMode(SDL_Texture * ___a, SDL_BlendMode * ___b);

int
SDL2Gate_SDL_GetTextureBlendMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_BlendMode * ___b)
{
  return SDL_GetTextureBlendMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetTextureBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  SDL_BlendMode * ___b = (SDL_BlendMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetTextureBlendMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTextureBlendModePPC };

int SDL_UpdateTexture(SDL_Texture * ___a, const SDL_Rect * ___b, const void * ___c, int ___d);

int
SDL2Gate_SDL_UpdateTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     const void * ___c,
     int ___d)
{
  return SDL_UpdateTexture(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_UpdateTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  const void * ___c = (const void *) regarray[REG68K_A2/4];
  int ___d = (int) regarray[REG68K_D0/4];

  return _iface->SDL_UpdateTexture(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpdateTexturePPC };

int SDL_UpdateYUVTexture(SDL_Texture * ___a, const SDL_Rect * ___b, const Uint8 * ___c, int ___d, const Uint8 * ___e, int ___f, const Uint8 * ___g, int ___h);

int
SDL2Gate_SDL_UpdateYUVTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     const Uint8 * ___c,
     int ___d,
     const Uint8 * ___e,
     int ___f,
     const Uint8 * ___g,
     int ___h)
{
  return SDL_UpdateYUVTexture(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

STATIC int 
SDL2Gate_SDL_UpdateYUVTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  const Uint8 * ___c = (const Uint8 *) regarray[REG68K_A2/4];
  int ___d = (int) regarray[REG68K_D0/4];
  const Uint8 * ___e = (const Uint8 *) regarray[REG68K_A3/4];
  int ___f = (int) regarray[REG68K_D1/4];
  const Uint8 * ___g = (const Uint8 *) regarray[REG68K_D2/4];
  int ___h = (int) regarray[REG68K_D3/4];

  return _iface->SDL_UpdateYUVTexture(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateYUVTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpdateYUVTexturePPC };

int SDL_LockTexture(SDL_Texture * ___a, const SDL_Rect * ___b, void * * ___c, int * ___d);

int
SDL2Gate_SDL_LockTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     void * * ___c,
     int * ___d)
{
  return SDL_LockTexture(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_LockTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  void * * ___c = (void * *) regarray[REG68K_A2/4];
  int * ___d = (int *) regarray[REG68K_A3/4];

  return _iface->SDL_LockTexture(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockTexturePPC };

void SDL_UnlockTexture(SDL_Texture * ___a);

void
SDL2Gate_SDL_UnlockTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a)
{
  return SDL_UnlockTexture(___a);
}

STATIC void 
SDL2Gate_SDL_UnlockTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];

  return _iface->SDL_UnlockTexture(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockTexturePPC };

SDL_bool SDL_RenderTargetSupported(SDL_Renderer * ___a);

SDL_bool
SDL2Gate_SDL_RenderTargetSupported(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderTargetSupported(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_RenderTargetSupportedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderTargetSupported(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderTargetSupported = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderTargetSupportedPPC };

int SDL_SetRenderTarget(SDL_Renderer * ___a, SDL_Texture * ___b);

int
SDL2Gate_SDL_SetRenderTarget(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b)
{
  return SDL_SetRenderTarget(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetRenderTargetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Texture * ___b = (SDL_Texture *) regarray[REG68K_A1/4];

  return _iface->SDL_SetRenderTarget(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetRenderTarget = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetRenderTargetPPC };

SDL_Texture* SDL_GetRenderTarget(SDL_Renderer * ___a);

SDL_Texture*
SDL2Gate_SDL_GetRenderTarget(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_GetRenderTarget(___a);
}

STATIC SDL_Texture* 
SDL2Gate_SDL_GetRenderTargetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_GetRenderTarget(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderTarget = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRenderTargetPPC };

int SDL_RenderSetLogicalSize(SDL_Renderer * ___a, int ___b, int ___c);

int
SDL2Gate_SDL_RenderSetLogicalSize(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c)
{
  return SDL_RenderSetLogicalSize(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderSetLogicalSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_RenderSetLogicalSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetLogicalSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderSetLogicalSizePPC };

void SDL_RenderGetLogicalSize(SDL_Renderer * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_RenderGetLogicalSize(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_RenderGetLogicalSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_RenderGetLogicalSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_RenderGetLogicalSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetLogicalSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetLogicalSizePPC };

int SDL_RenderSetViewport(SDL_Renderer * ___a, const SDL_Rect * ___b);

int
SDL2Gate_SDL_RenderSetViewport(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b)
{
  return SDL_RenderSetViewport(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderSetViewportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderSetViewport(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetViewport = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderSetViewportPPC };

void SDL_RenderGetViewport(SDL_Renderer * ___a, SDL_Rect * ___b);

void
SDL2Gate_SDL_RenderGetViewport(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Rect * ___b)
{
  return SDL_RenderGetViewport(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_RenderGetViewportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderGetViewport(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetViewport = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetViewportPPC };

int SDL_RenderSetClipRect(SDL_Renderer * ___a, const SDL_Rect * ___b);

int
SDL2Gate_SDL_RenderSetClipRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b)
{
  return SDL_RenderSetClipRect(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderSetClipRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderSetClipRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetClipRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderSetClipRectPPC };

void SDL_RenderGetClipRect(SDL_Renderer * ___a, SDL_Rect * ___b);

void
SDL2Gate_SDL_RenderGetClipRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Rect * ___b)
{
  return SDL_RenderGetClipRect(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_RenderGetClipRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderGetClipRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetClipRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetClipRectPPC };

int SDL_RenderSetScale(SDL_Renderer * ___a, float ___b, float ___c);

int
SDL2Gate_SDL_RenderSetScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c)
{
  return SDL_RenderSetScale(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderSetScalePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];
  float ___c = (float) regarray[REG68K_D1/4];

  return _iface->SDL_RenderSetScale(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetScale = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderSetScalePPC };

void SDL_RenderGetScale(SDL_Renderer * ___a, float * ___b, float * ___c);

void
SDL2Gate_SDL_RenderGetScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float * ___b,
     float * ___c)
{
  return SDL_RenderGetScale(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_RenderGetScalePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  float * ___b = (float *) regarray[REG68K_A1/4];
  float * ___c = (float *) regarray[REG68K_A2/4];

  return _iface->SDL_RenderGetScale(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetScale = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetScalePPC };

int SDL_SetRenderDrawColor(SDL_Renderer * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d, Uint8 ___e);

int
SDL2Gate_SDL_SetRenderDrawColor(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d,
     Uint8 ___e)
{
  return SDL_SetRenderDrawColor(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_SetRenderDrawColorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];
  Uint8 ___e = (Uint8) regarray[REG68K_D3/4];

  return _iface->SDL_SetRenderDrawColor(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetRenderDrawColor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetRenderDrawColorPPC };

int SDL_GetRenderDrawColor(SDL_Renderer * ___a, Uint8 * ___b, Uint8 * ___c, Uint8 * ___d, Uint8 * ___e);

int
SDL2Gate_SDL_GetRenderDrawColor(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     Uint8 * ___b,
     Uint8 * ___c,
     Uint8 * ___d,
     Uint8 * ___e)
{
  return SDL_GetRenderDrawColor(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_GetRenderDrawColorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  Uint8 * ___b = (Uint8 *) regarray[REG68K_A1/4];
  Uint8 * ___c = (Uint8 *) regarray[REG68K_A2/4];
  Uint8 * ___d = (Uint8 *) regarray[REG68K_A3/4];
  Uint8 * ___e = (Uint8 *) regarray[REG68K_D0/4];

  return _iface->SDL_GetRenderDrawColor(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderDrawColor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRenderDrawColorPPC };

int SDL_SetRenderDrawBlendMode(SDL_Renderer * ___a, SDL_BlendMode ___b);

int
SDL2Gate_SDL_SetRenderDrawBlendMode(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_BlendMode ___b)
{
  return SDL_SetRenderDrawBlendMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetRenderDrawBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_BlendMode ___b = (SDL_BlendMode) regarray[REG68K_D0/4];

  return _iface->SDL_SetRenderDrawBlendMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetRenderDrawBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetRenderDrawBlendModePPC };

int SDL_GetRenderDrawBlendMode(SDL_Renderer * ___a, SDL_BlendMode * ___b);

int
SDL2Gate_SDL_GetRenderDrawBlendMode(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_BlendMode * ___b)
{
  return SDL_GetRenderDrawBlendMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetRenderDrawBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_BlendMode * ___b = (SDL_BlendMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetRenderDrawBlendMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRenderDrawBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRenderDrawBlendModePPC };

int SDL_RenderClear(SDL_Renderer * ___a);

int
SDL2Gate_SDL_RenderClear(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderClear(___a);
}

STATIC int 
SDL2Gate_SDL_RenderClearPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderClear(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderClear = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderClearPPC };

int SDL_RenderDrawPoint(SDL_Renderer * ___a, int ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawPoint(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c)
{
  return SDL_RenderDrawPoint(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawPointPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_RenderDrawPoint(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPoint = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawPointPPC };

int SDL_RenderDrawPoints(SDL_Renderer * ___a, const SDL_Point * ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawPoints(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Point * ___b,
     int ___c)
{
  return SDL_RenderDrawPoints(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawPointsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Point * ___b = (const SDL_Point *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderDrawPoints(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPoints = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawPointsPPC };

int SDL_RenderDrawLine(SDL_Renderer * ___a, int ___b, int ___c, int ___d, int ___e);

int
SDL2Gate_SDL_RenderDrawLine(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e)
{
  return SDL_RenderDrawLine(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_RenderDrawLinePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  int ___d = (int) regarray[REG68K_D2/4];
  int ___e = (int) regarray[REG68K_D3/4];

  return _iface->SDL_RenderDrawLine(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLine = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawLinePPC };

int SDL_RenderDrawLines(SDL_Renderer * ___a, const SDL_Point * ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawLines(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Point * ___b,
     int ___c)
{
  return SDL_RenderDrawLines(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawLinesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Point * ___b = (const SDL_Point *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderDrawLines(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLines = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawLinesPPC };

int SDL_RenderDrawRect(SDL_Renderer * ___a, const SDL_Rect * ___b);

int
SDL2Gate_SDL_RenderDrawRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b)
{
  return SDL_RenderDrawRect(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderDrawRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderDrawRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawRectPPC };

int SDL_RenderDrawRects(SDL_Renderer * ___a, const SDL_Rect * ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawRects(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b,
     int ___c)
{
  return SDL_RenderDrawRects(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawRectsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderDrawRects(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRects = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawRectsPPC };

int SDL_RenderFillRect(SDL_Renderer * ___a, const SDL_Rect * ___b);

int
SDL2Gate_SDL_RenderFillRect(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b)
{
  return SDL_RenderFillRect(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderFillRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderFillRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderFillRectPPC };

int SDL_RenderFillRects(SDL_Renderer * ___a, const SDL_Rect * ___b, int ___c);

int
SDL2Gate_SDL_RenderFillRects(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b,
     int ___c)
{
  return SDL_RenderFillRects(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderFillRectsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderFillRects(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRects = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderFillRectsPPC };

int SDL_RenderCopy(SDL_Renderer * ___a, SDL_Texture * ___b, const SDL_Rect * ___c, const SDL_Rect * ___d);

int
SDL2Gate_SDL_RenderCopy(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_Rect * ___d)
{
  return SDL_RenderCopy(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_RenderCopyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Texture * ___b = (SDL_Texture *) regarray[REG68K_A1/4];
  const SDL_Rect * ___c = (const SDL_Rect *) regarray[REG68K_A2/4];
  const SDL_Rect * ___d = (const SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_RenderCopy(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopy = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderCopyPPC };

int SDL_RenderCopyEx(SDL_Renderer * ___a, SDL_Texture * ___b, const SDL_Rect * ___c, const SDL_Rect * ___d, const double ___e, const SDL_Point * ___f, const SDL_RendererFlip ___g);

int
SDL2Gate_SDL_RenderCopyEx(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_Rect * ___d,
     const double ___e,
     const SDL_Point * ___f,
     const SDL_RendererFlip ___g)
{
  return SDL_RenderCopyEx(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

STATIC int 
SDL2Gate_SDL_RenderCopyExPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Texture * ___b = (SDL_Texture *) regarray[REG68K_A1/4];
  const SDL_Rect * ___c = (const SDL_Rect *) regarray[REG68K_A2/4];
  const SDL_Rect * ___d = (const SDL_Rect *) regarray[REG68K_A3/4];
  const double ___e = (const double) regarray[REG68K_D0/4];
  const SDL_Point * ___f = (const SDL_Point *) regarray[REG68K_D2/4];
  const SDL_RendererFlip ___g = (const SDL_RendererFlip) regarray[REG68K_D3/4];

  return _iface->SDL_RenderCopyEx(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopyEx = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderCopyExPPC };

int SDL_RenderReadPixels(SDL_Renderer * ___a, const SDL_Rect * ___b, Uint32 ___c, void * ___d, int ___e);

int
SDL2Gate_SDL_RenderReadPixels(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_Rect * ___b,
     Uint32 ___c,
     void * ___d,
     int ___e)
{
  return SDL_RenderReadPixels(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_RenderReadPixelsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D0/4];
  void * ___d = (void *) regarray[REG68K_A2/4];
  int ___e = (int) regarray[REG68K_D1/4];

  return _iface->SDL_RenderReadPixels(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderReadPixels = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderReadPixelsPPC };

void SDL_RenderPresent(SDL_Renderer * ___a);

void
SDL2Gate_SDL_RenderPresent(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderPresent(___a);
}

STATIC void 
SDL2Gate_SDL_RenderPresentPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderPresent(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderPresent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderPresentPPC };

void SDL_DestroyTexture(SDL_Texture * ___a);

void
SDL2Gate_SDL_DestroyTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a)
{
  return SDL_DestroyTexture(___a);
}

STATIC void 
SDL2Gate_SDL_DestroyTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroyTexture(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroyTexturePPC };

void SDL_DestroyRenderer(SDL_Renderer * ___a);

void
SDL2Gate_SDL_DestroyRenderer(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_DestroyRenderer(___a);
}

STATIC void 
SDL2Gate_SDL_DestroyRendererPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroyRenderer(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyRenderer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroyRendererPPC };

int SDL_GL_BindTexture(SDL_Texture * ___a, float * ___b, float * ___c);

int
SDL2Gate_SDL_GL_BindTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     float * ___b,
     float * ___c)
{
  return SDL_GL_BindTexture(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GL_BindTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  float * ___b = (float *) regarray[REG68K_A1/4];
  float * ___c = (float *) regarray[REG68K_A2/4];

  return _iface->SDL_GL_BindTexture(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_BindTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_BindTexturePPC };

int SDL_GL_UnbindTexture(SDL_Texture * ___a);

int
SDL2Gate_SDL_GL_UnbindTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a)
{
  return SDL_GL_UnbindTexture(___a);
}

STATIC int 
SDL2Gate_SDL_GL_UnbindTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_UnbindTexture(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_UnbindTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_UnbindTexturePPC };

SDL_RWops* SDL_RWFromFile(const char * ___a, const char * ___b);

SDL_RWops*
SDL2Gate_SDL_RWFromFile(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_RWFromFile(___a, ___b);
}

STATIC SDL_RWops* 
SDL2Gate_SDL_RWFromFilePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_RWFromFile(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWFromFile = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWFromFilePPC };

SDL_RWops* SDL_RWFromMem(void * ___a, int ___b);

SDL_RWops*
SDL2Gate_SDL_RWFromMem(struct SDL2IFace* _iface,
     void * ___a,
     int ___b)
{
  return SDL_RWFromMem(___a, ___b);
}

STATIC SDL_RWops* 
SDL2Gate_SDL_RWFromMemPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RWFromMem(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWFromMem = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWFromMemPPC };

SDL_RWops* SDL_RWFromConstMem(const void * ___a, int ___b);

SDL_RWops*
SDL2Gate_SDL_RWFromConstMem(struct SDL2IFace* _iface,
     const void * ___a,
     int ___b)
{
  return SDL_RWFromConstMem(___a, ___b);
}

STATIC SDL_RWops* 
SDL2Gate_SDL_RWFromConstMemPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const void * ___a = (const void *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RWFromConstMem(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWFromConstMem = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWFromConstMemPPC };

SDL_RWops* SDL_AllocRW(void);

SDL_RWops*
SDL2Gate_SDL_AllocRW(struct SDL2IFace* _iface)
{
  return SDL_AllocRW();
}

STATIC SDL_RWops* 
SDL2Gate_SDL_AllocRWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_AllocRW();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AllocRW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AllocRWPPC };

void SDL_FreeRW(SDL_RWops * ___a);

void
SDL2Gate_SDL_FreeRW(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_FreeRW(___a);
}

STATIC void 
SDL2Gate_SDL_FreeRWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_FreeRW(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreeRW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreeRWPPC };

Uint8 SDL_ReadU8(SDL_RWops * ___a);

Uint8
SDL2Gate_SDL_ReadU8(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadU8(___a);
}

STATIC Uint8 
SDL2Gate_SDL_ReadU8PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadU8(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadU8 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadU8PPC };

Uint16 SDL_ReadLE16(SDL_RWops * ___a);

Uint16
SDL2Gate_SDL_ReadLE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadLE16(___a);
}

STATIC Uint16 
SDL2Gate_SDL_ReadLE16PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadLE16(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadLE16 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadLE16PPC };

Uint16 SDL_ReadBE16(SDL_RWops * ___a);

Uint16
SDL2Gate_SDL_ReadBE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadBE16(___a);
}

STATIC Uint16 
SDL2Gate_SDL_ReadBE16PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadBE16(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadBE16 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadBE16PPC };

Uint32 SDL_ReadLE32(SDL_RWops * ___a);

Uint32
SDL2Gate_SDL_ReadLE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadLE32(___a);
}

STATIC Uint32 
SDL2Gate_SDL_ReadLE32PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadLE32(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadLE32 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadLE32PPC };

Uint32 SDL_ReadBE32(SDL_RWops * ___a);

Uint32
SDL2Gate_SDL_ReadBE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadBE32(___a);
}

STATIC Uint32 
SDL2Gate_SDL_ReadBE32PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadBE32(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadBE32 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadBE32PPC };

Uint64 SDL_ReadLE64(SDL_RWops * ___a);

Uint64
SDL2Gate_SDL_ReadLE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadLE64(___a);
}

STATIC Uint64 
SDL2Gate_SDL_ReadLE64PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadLE64(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadLE64 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadLE64PPC };

Uint64 SDL_ReadBE64(SDL_RWops * ___a);

Uint64
SDL2Gate_SDL_ReadBE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_ReadBE64(___a);
}

STATIC Uint64 
SDL2Gate_SDL_ReadBE64PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_ReadBE64(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ReadBE64 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ReadBE64PPC };

size_t SDL_WriteU8(SDL_RWops * ___a, Uint8 ___b);

size_t
SDL2Gate_SDL_WriteU8(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint8 ___b)
{
  return SDL_WriteU8(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteU8PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];

  return _iface->SDL_WriteU8(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteU8 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteU8PPC };

size_t SDL_WriteLE16(SDL_RWops * ___a, Uint16 ___b);

size_t
SDL2Gate_SDL_WriteLE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint16 ___b)
{
  return SDL_WriteLE16(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteLE16PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint16 ___b = (Uint16) regarray[REG68K_D0/4];

  return _iface->SDL_WriteLE16(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteLE16 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteLE16PPC };

size_t SDL_WriteBE16(SDL_RWops * ___a, Uint16 ___b);

size_t
SDL2Gate_SDL_WriteBE16(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint16 ___b)
{
  return SDL_WriteBE16(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteBE16PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint16 ___b = (Uint16) regarray[REG68K_D0/4];

  return _iface->SDL_WriteBE16(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteBE16 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteBE16PPC };

size_t SDL_WriteLE32(SDL_RWops * ___a, Uint32 ___b);

size_t
SDL2Gate_SDL_WriteLE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint32 ___b)
{
  return SDL_WriteLE32(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteLE32PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_WriteLE32(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteLE32 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteLE32PPC };

size_t SDL_WriteBE32(SDL_RWops * ___a, Uint32 ___b);

size_t
SDL2Gate_SDL_WriteBE32(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint32 ___b)
{
  return SDL_WriteBE32(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteBE32PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_WriteBE32(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteBE32 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteBE32PPC };

size_t SDL_WriteLE64(SDL_RWops * ___a, Uint64 ___b);

size_t
SDL2Gate_SDL_WriteLE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint64 ___b)
{
  return SDL_WriteLE64(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteLE64PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint64 ___b = (Uint64) regarray[REG68K_D0/4];

  return _iface->SDL_WriteLE64(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteLE64 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteLE64PPC };

size_t SDL_WriteBE64(SDL_RWops * ___a, Uint64 ___b);

size_t
SDL2Gate_SDL_WriteBE64(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Uint64 ___b)
{
  return SDL_WriteBE64(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_WriteBE64PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Uint64 ___b = (Uint64) regarray[REG68K_D0/4];

  return _iface->SDL_WriteBE64(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WriteBE64 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WriteBE64PPC };

SDL_Window* SDL_CreateShapedWindow(const char * ___a, unsigned int ___b, unsigned int ___c, unsigned int ___d, unsigned int ___e, Uint32 ___f);

SDL_Window*
SDL2Gate_SDL_CreateShapedWindow(struct SDL2IFace* _iface,
     const char * ___a,
     unsigned int ___b,
     unsigned int ___c,
     unsigned int ___d,
     unsigned int ___e,
     Uint32 ___f)
{
  return SDL_CreateShapedWindow(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_Window* 
SDL2Gate_SDL_CreateShapedWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  unsigned int ___b = (unsigned int) regarray[REG68K_D0/4];
  unsigned int ___c = (unsigned int) regarray[REG68K_D1/4];
  unsigned int ___d = (unsigned int) regarray[REG68K_D2/4];
  unsigned int ___e = (unsigned int) regarray[REG68K_D3/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D4/4];

  return _iface->SDL_CreateShapedWindow(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateShapedWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateShapedWindowPPC };

SDL_bool SDL_IsShapedWindow(const SDL_Window * ___a);

SDL_bool
SDL2Gate_SDL_IsShapedWindow(struct SDL2IFace* _iface,
     const SDL_Window * ___a)
{
  return SDL_IsShapedWindow(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_IsShapedWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Window * ___a = (const SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_IsShapedWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsShapedWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsShapedWindowPPC };

int SDL_SetWindowShape(SDL_Window * ___a, SDL_Surface * ___b, SDL_WindowShapeMode * ___c);

int
SDL2Gate_SDL_SetWindowShape(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_Surface * ___b,
     SDL_WindowShapeMode * ___c)
{
  return SDL_SetWindowShape(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_SetWindowShapePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_Surface * ___b = (SDL_Surface *) regarray[REG68K_A1/4];
  SDL_WindowShapeMode * ___c = (SDL_WindowShapeMode *) regarray[REG68K_A2/4];

  return _iface->SDL_SetWindowShape(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowShape = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowShapePPC };

int SDL_GetShapedWindowMode(SDL_Window * ___a, SDL_WindowShapeMode * ___b);

int
SDL2Gate_SDL_GetShapedWindowMode(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_WindowShapeMode * ___b)
{
  return SDL_GetShapedWindowMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetShapedWindowModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_WindowShapeMode * ___b = (SDL_WindowShapeMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetShapedWindowMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetShapedWindowMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetShapedWindowModePPC };

void* SDL_malloc(size_t ___a);

void*
SDL2Gate_SDL_malloc(struct SDL2IFace* _iface,
     size_t ___a)
{
  return SDL_malloc(___a);
}

STATIC void* 
SDL2Gate_SDL_mallocPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  size_t ___a = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_malloc(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_malloc = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_mallocPPC };

void* SDL_calloc(size_t ___a, size_t ___b);

void*
SDL2Gate_SDL_calloc(struct SDL2IFace* _iface,
     size_t ___a,
     size_t ___b)
{
  return SDL_calloc(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_callocPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  size_t ___a = (size_t) regarray[REG68K_D0/4];
  size_t ___b = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_calloc(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_calloc = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_callocPPC };

void* SDL_realloc(void * ___a, size_t ___b);

void*
SDL2Gate_SDL_realloc(struct SDL2IFace* _iface,
     void * ___a,
     size_t ___b)
{
  return SDL_realloc(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_reallocPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  size_t ___b = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_realloc(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_realloc = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_reallocPPC };

void SDL_free(void * ___a);

void
SDL2Gate_SDL_free(struct SDL2IFace* _iface,
     void * ___a)
{
  return SDL_free(___a);
}

STATIC void 
SDL2Gate_SDL_freePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_free(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_free = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_freePPC };

char* SDL_getenv(const char * ___a);

char*
SDL2Gate_SDL_getenv(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_getenv(___a);
}

STATIC char* 
SDL2Gate_SDL_getenvPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_getenv(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_getenv = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_getenvPPC };

int SDL_setenv(const char * ___a, const char * ___b, int ___c);

int
SDL2Gate_SDL_setenv(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     int ___c)
{
  return SDL_setenv(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_setenvPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_setenv(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_setenv = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_setenvPPC };

void SDL_qsort(void * ___a, size_t ___b, size_t ___c, SDL_CompareCallback ___d);

void
SDL2Gate_SDL_qsort(struct SDL2IFace* _iface,
     void * ___a,
     size_t ___b,
     size_t ___c,
     SDL_CompareCallback ___d)
{
  return SDL_qsort(___a, ___b, ___c, ___d);
}

STATIC void 
SDL2Gate_SDL_qsortPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  size_t ___b = (size_t) regarray[REG68K_D0/4];
  size_t ___c = (size_t) regarray[REG68K_D1/4];
  SDL_CompareCallback ___d = (SDL_CompareCallback) regarray[REG68K_D2/4];

  return _iface->SDL_qsort(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_qsort = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_qsortPPC };

int SDL_abs(int ___a);

int
SDL2Gate_SDL_abs(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_abs(___a);
}

STATIC int 
SDL2Gate_SDL_absPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_abs(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_abs = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_absPPC };

int SDL_isdigit(int ___a);

int
SDL2Gate_SDL_isdigit(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isdigit(___a);
}

STATIC int 
SDL2Gate_SDL_isdigitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isdigit(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isdigit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isdigitPPC };

int SDL_isspace(int ___a);

int
SDL2Gate_SDL_isspace(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isspace(___a);
}

STATIC int 
SDL2Gate_SDL_isspacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isspace(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isspace = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isspacePPC };

int SDL_toupper(int ___a);

int
SDL2Gate_SDL_toupper(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_toupper(___a);
}

STATIC int 
SDL2Gate_SDL_toupperPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_toupper(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_toupper = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_toupperPPC };

int SDL_tolower(int ___a);

int
SDL2Gate_SDL_tolower(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_tolower(___a);
}

STATIC int 
SDL2Gate_SDL_tolowerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_tolower(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_tolower = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_tolowerPPC };

void* SDL_memset(SDL_OUT_BYTECAP(c) void * ___a, int ___b, size_t ___c);

void*
SDL2Gate_SDL_memset(struct SDL2IFace* _iface,
     SDL_OUT_BYTECAP(c) void * ___a,
     int ___b,
     size_t ___c)
{
  return SDL_memset(___a, ___b, ___c);
}

STATIC void* 
SDL2Gate_SDL_memsetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_OUT_BYTECAP(c) void * ___a = (SDL_OUT_BYTECAP(c) void *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  size_t ___c = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_memset(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_memset = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_memsetPPC };

void* SDL_memcpy(SDL_OUT_BYTECAP(c) void * ___a, SDL_IN_BYTECAP(c) const void * ___b, size_t ___c);

void*
SDL2Gate_SDL_memcpy(struct SDL2IFace* _iface,
     SDL_OUT_BYTECAP(c) void * ___a,
     SDL_IN_BYTECAP(c) const void * ___b,
     size_t ___c)
{
  return SDL_memcpy(___a, ___b, ___c);
}

STATIC void* 
SDL2Gate_SDL_memcpyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_OUT_BYTECAP(c) void * ___a = (SDL_OUT_BYTECAP(c) void *) regarray[REG68K_A0/4];
  SDL_IN_BYTECAP(c) const void * ___b = (SDL_IN_BYTECAP(c) const void *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_memcpy(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_memcpy = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_memcpyPPC };

void* SDL_memmove(SDL_OUT_BYTECAP(c) void * ___a, SDL_IN_BYTECAP(c) const void * ___b, size_t ___c);

void*
SDL2Gate_SDL_memmove(struct SDL2IFace* _iface,
     SDL_OUT_BYTECAP(c) void * ___a,
     SDL_IN_BYTECAP(c) const void * ___b,
     size_t ___c)
{
  return SDL_memmove(___a, ___b, ___c);
}

STATIC void* 
SDL2Gate_SDL_memmovePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_OUT_BYTECAP(c) void * ___a = (SDL_OUT_BYTECAP(c) void *) regarray[REG68K_A0/4];
  SDL_IN_BYTECAP(c) const void * ___b = (SDL_IN_BYTECAP(c) const void *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_memmove(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_memmove = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_memmovePPC };

int SDL_memcmp(const void * ___a, const void * ___b, size_t ___c);

int
SDL2Gate_SDL_memcmp(struct SDL2IFace* _iface,
     const void * ___a,
     const void * ___b,
     size_t ___c)
{
  return SDL_memcmp(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_memcmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const void * ___a = (const void *) regarray[REG68K_A0/4];
  const void * ___b = (const void *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_memcmp(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_memcmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_memcmpPPC };

size_t SDL_wcslen(const wchar_t * ___a);

size_t
SDL2Gate_SDL_wcslen(struct SDL2IFace* _iface,
     const wchar_t * ___a)
{
  return SDL_wcslen(___a);
}

STATIC size_t 
SDL2Gate_SDL_wcslenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];

  return _iface->SDL_wcslen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcslen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcslenPPC };

size_t SDL_wcslcpy(SDL_OUT_Z_CAP(c) wchar_t * ___a, const wchar_t * ___b, size_t ___c);

size_t
SDL2Gate_SDL_wcslcpy(struct SDL2IFace* _iface,
     SDL_OUT_Z_CAP(c) wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c)
{
  return SDL_wcslcpy(___a, ___b, ___c);
}

STATIC size_t 
SDL2Gate_SDL_wcslcpyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_OUT_Z_CAP(c) wchar_t * ___a = (SDL_OUT_Z_CAP(c) wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_wcslcpy(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcslcpy = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcslcpyPPC };

size_t SDL_wcslcat(SDL_INOUT_Z_CAP(c) wchar_t * ___a, const wchar_t * ___b, size_t ___c);

size_t
SDL2Gate_SDL_wcslcat(struct SDL2IFace* _iface,
     SDL_INOUT_Z_CAP(c) wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c)
{
  return SDL_wcslcat(___a, ___b, ___c);
}

STATIC size_t 
SDL2Gate_SDL_wcslcatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_INOUT_Z_CAP(c) wchar_t * ___a = (SDL_INOUT_Z_CAP(c) wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_wcslcat(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcslcat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcslcatPPC };

size_t SDL_strlen(const char * ___a);

size_t
SDL2Gate_SDL_strlen(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_strlen(___a);
}

STATIC size_t 
SDL2Gate_SDL_strlenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_strlen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strlen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strlenPPC };

size_t SDL_strlcpy(SDL_OUT_Z_CAP(c) char * ___a, const char * ___b, size_t ___c);

size_t
SDL2Gate_SDL_strlcpy(struct SDL2IFace* _iface,
     SDL_OUT_Z_CAP(c) char * ___a,
     const char * ___b,
     size_t ___c)
{
  return SDL_strlcpy(___a, ___b, ___c);
}

STATIC size_t 
SDL2Gate_SDL_strlcpyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_OUT_Z_CAP(c) char * ___a = (SDL_OUT_Z_CAP(c) char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_strlcpy(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strlcpy = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strlcpyPPC };

size_t SDL_utf8strlcpy(SDL_OUT_Z_CAP(c) char * ___a, const char * ___b, size_t ___c);

size_t
SDL2Gate_SDL_utf8strlcpy(struct SDL2IFace* _iface,
     SDL_OUT_Z_CAP(c) char * ___a,
     const char * ___b,
     size_t ___c)
{
  return SDL_utf8strlcpy(___a, ___b, ___c);
}

STATIC size_t 
SDL2Gate_SDL_utf8strlcpyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_OUT_Z_CAP(c) char * ___a = (SDL_OUT_Z_CAP(c) char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_utf8strlcpy(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_utf8strlcpy = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_utf8strlcpyPPC };

size_t SDL_strlcat(SDL_INOUT_Z_CAP(c) char * ___a, const char * ___b, size_t ___c);

size_t
SDL2Gate_SDL_strlcat(struct SDL2IFace* _iface,
     SDL_INOUT_Z_CAP(c) char * ___a,
     const char * ___b,
     size_t ___c)
{
  return SDL_strlcat(___a, ___b, ___c);
}

STATIC size_t 
SDL2Gate_SDL_strlcatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_INOUT_Z_CAP(c) char * ___a = (SDL_INOUT_Z_CAP(c) char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_strlcat(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strlcat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strlcatPPC };

char* SDL_strdup(const char * ___a);

char*
SDL2Gate_SDL_strdup(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_strdup(___a);
}

STATIC char* 
SDL2Gate_SDL_strdupPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_strdup(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strdup = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strdupPPC };

char* SDL_strrev(char * ___a);

char*
SDL2Gate_SDL_strrev(struct SDL2IFace* _iface,
     char * ___a)
{
  return SDL_strrev(___a);
}

STATIC char* 
SDL2Gate_SDL_strrevPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  char * ___a = (char *) regarray[REG68K_A0/4];

  return _iface->SDL_strrev(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strrev = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strrevPPC };

char* SDL_strupr(char * ___a);

char*
SDL2Gate_SDL_strupr(struct SDL2IFace* _iface,
     char * ___a)
{
  return SDL_strupr(___a);
}

STATIC char* 
SDL2Gate_SDL_struprPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  char * ___a = (char *) regarray[REG68K_A0/4];

  return _iface->SDL_strupr(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strupr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_struprPPC };

char* SDL_strlwr(char * ___a);

char*
SDL2Gate_SDL_strlwr(struct SDL2IFace* _iface,
     char * ___a)
{
  return SDL_strlwr(___a);
}

STATIC char* 
SDL2Gate_SDL_strlwrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  char * ___a = (char *) regarray[REG68K_A0/4];

  return _iface->SDL_strlwr(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strlwr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strlwrPPC };

char* SDL_strchr(const char * ___a, int ___b);

char*
SDL2Gate_SDL_strchr(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b)
{
  return SDL_strchr(___a, ___b);
}

STATIC char* 
SDL2Gate_SDL_strchrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_strchr(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strchr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strchrPPC };

char* SDL_strrchr(const char * ___a, int ___b);

char*
SDL2Gate_SDL_strrchr(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b)
{
  return SDL_strrchr(___a, ___b);
}

STATIC char* 
SDL2Gate_SDL_strrchrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_strrchr(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strrchr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strrchrPPC };

char* SDL_strstr(const char * ___a, const char * ___b);

char*
SDL2Gate_SDL_strstr(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_strstr(___a, ___b);
}

STATIC char* 
SDL2Gate_SDL_strstrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_strstr(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strstr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strstrPPC };

char* SDL_itoa(int ___a, char * ___b, int ___c);

char*
SDL2Gate_SDL_itoa(struct SDL2IFace* _iface,
     int ___a,
     char * ___b,
     int ___c)
{
  return SDL_itoa(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_itoaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  char * ___b = (char *) regarray[REG68K_A0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_itoa(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_itoa = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_itoaPPC };

char* SDL_uitoa(unsigned int ___a, char * ___b, int ___c);

char*
SDL2Gate_SDL_uitoa(struct SDL2IFace* _iface,
     unsigned int ___a,
     char * ___b,
     int ___c)
{
  return SDL_uitoa(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_uitoaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  unsigned int ___a = (unsigned int) regarray[REG68K_D0/4];
  char * ___b = (char *) regarray[REG68K_A0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_uitoa(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_uitoa = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_uitoaPPC };

char* SDL_ltoa(long ___a, char * ___b, int ___c);

char*
SDL2Gate_SDL_ltoa(struct SDL2IFace* _iface,
     long ___a,
     char * ___b,
     int ___c)
{
  return SDL_ltoa(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_ltoaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  long ___a = (long) regarray[REG68K_D0/4];
  char * ___b = (char *) regarray[REG68K_A0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_ltoa(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ltoa = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ltoaPPC };

char* SDL_ultoa(unsigned long ___a, char * ___b, int ___c);

char*
SDL2Gate_SDL_ultoa(struct SDL2IFace* _iface,
     unsigned long ___a,
     char * ___b,
     int ___c)
{
  return SDL_ultoa(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_ultoaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  unsigned long ___a = (unsigned long) regarray[REG68K_D0/4];
  char * ___b = (char *) regarray[REG68K_A0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_ultoa(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ultoa = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ultoaPPC };

char* SDL_lltoa(Sint64 ___a, char * ___b, int ___c);

char*
SDL2Gate_SDL_lltoa(struct SDL2IFace* _iface,
     Sint64 ___a,
     char * ___b,
     int ___c)
{
  return SDL_lltoa(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_lltoaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Sint64 ___a = (Sint64) regarray[REG68K_D0/4];
  char * ___b = (char *) regarray[REG68K_A0/4];
  int ___c = (int) regarray[REG68K_D2/4];

  return _iface->SDL_lltoa(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_lltoa = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_lltoaPPC };

char* SDL_ulltoa(Uint64 ___a, char * ___b, int ___c);

char*
SDL2Gate_SDL_ulltoa(struct SDL2IFace* _iface,
     Uint64 ___a,
     char * ___b,
     int ___c)
{
  return SDL_ulltoa(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_ulltoaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint64 ___a = (Uint64) regarray[REG68K_D0/4];
  char * ___b = (char *) regarray[REG68K_A0/4];
  int ___c = (int) regarray[REG68K_D2/4];

  return _iface->SDL_ulltoa(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ulltoa = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ulltoaPPC };

int SDL_atoi(const char * ___a);

int
SDL2Gate_SDL_atoi(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_atoi(___a);
}

STATIC int 
SDL2Gate_SDL_atoiPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_atoi(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_atoi = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_atoiPPC };

double SDL_atof(const char * ___a);

double
SDL2Gate_SDL_atof(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_atof(___a);
}

STATIC double 
SDL2Gate_SDL_atofPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_atof(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_atof = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_atofPPC };

long SDL_strtol(const char * ___a, char * * ___b, int ___c);

long
SDL2Gate_SDL_strtol(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c)
{
  return SDL_strtol(___a, ___b, ___c);
}

STATIC long 
SDL2Gate_SDL_strtolPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  char * * ___b = (char * *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_strtol(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strtol = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strtolPPC };

unsigned long SDL_strtoul(const char * ___a, char * * ___b, int ___c);

unsigned long
SDL2Gate_SDL_strtoul(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c)
{
  return SDL_strtoul(___a, ___b, ___c);
}

STATIC unsigned long 
SDL2Gate_SDL_strtoulPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  char * * ___b = (char * *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_strtoul(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strtoul = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strtoulPPC };

Sint64 SDL_strtoll(const char * ___a, char * * ___b, int ___c);

Sint64
SDL2Gate_SDL_strtoll(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c)
{
  return SDL_strtoll(___a, ___b, ___c);
}

STATIC Sint64 
SDL2Gate_SDL_strtollPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  char * * ___b = (char * *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_strtoll(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strtoll = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strtollPPC };

Uint64 SDL_strtoull(const char * ___a, char * * ___b, int ___c);

Uint64
SDL2Gate_SDL_strtoull(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b,
     int ___c)
{
  return SDL_strtoull(___a, ___b, ___c);
}

STATIC Uint64 
SDL2Gate_SDL_strtoullPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  char * * ___b = (char * *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_strtoull(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strtoull = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strtoullPPC };

double SDL_strtod(const char * ___a, char * * ___b);

double
SDL2Gate_SDL_strtod(struct SDL2IFace* _iface,
     const char * ___a,
     char * * ___b)
{
  return SDL_strtod(___a, ___b);
}

STATIC double 
SDL2Gate_SDL_strtodPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  char * * ___b = (char * *) regarray[REG68K_A1/4];

  return _iface->SDL_strtod(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strtod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strtodPPC };

int SDL_strcmp(const char * ___a, const char * ___b);

int
SDL2Gate_SDL_strcmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_strcmp(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_strcmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_strcmp(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strcmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strcmpPPC };

int SDL_strncmp(const char * ___a, const char * ___b, size_t ___c);

int
SDL2Gate_SDL_strncmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     size_t ___c)
{
  return SDL_strncmp(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_strncmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_strncmp(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strncmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strncmpPPC };

int SDL_strcasecmp(const char * ___a, const char * ___b);

int
SDL2Gate_SDL_strcasecmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_strcasecmp(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_strcasecmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_strcasecmp(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strcasecmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strcasecmpPPC };

int SDL_strncasecmp(const char * ___a, const char * ___b, size_t ___c);

int
SDL2Gate_SDL_strncasecmp(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     size_t ___c)
{
  return SDL_strncasecmp(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_strncasecmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_strncasecmp(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strncasecmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strncasecmpPPC };

double SDL_acos(double ___a);

double
SDL2Gate_SDL_acos(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_acos(___a);
}

STATIC double 
SDL2Gate_SDL_acosPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_acos(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_acos = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_acosPPC };

double SDL_asin(double ___a);

double
SDL2Gate_SDL_asin(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_asin(___a);
}

STATIC double 
SDL2Gate_SDL_asinPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_asin(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_asin = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_asinPPC };

double SDL_atan(double ___a);

double
SDL2Gate_SDL_atan(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_atan(___a);
}

STATIC double 
SDL2Gate_SDL_atanPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_atan(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_atan = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_atanPPC };

double SDL_atan2(double ___a, double ___b);

double
SDL2Gate_SDL_atan2(struct SDL2IFace* _iface,
     double ___a,
     double ___b)
{
  return SDL_atan2(___a, ___b);
}

STATIC double 
SDL2Gate_SDL_atan2PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];
  double ___b = (double) regarray[REG68K_D2/4];

  return _iface->SDL_atan2(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_atan2 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_atan2PPC };

double SDL_ceil(double ___a);

double
SDL2Gate_SDL_ceil(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_ceil(___a);
}

STATIC double 
SDL2Gate_SDL_ceilPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_ceil(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ceil = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ceilPPC };

double SDL_copysign(double ___a, double ___b);

double
SDL2Gate_SDL_copysign(struct SDL2IFace* _iface,
     double ___a,
     double ___b)
{
  return SDL_copysign(___a, ___b);
}

STATIC double 
SDL2Gate_SDL_copysignPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];
  double ___b = (double) regarray[REG68K_D2/4];

  return _iface->SDL_copysign(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_copysign = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_copysignPPC };

double SDL_cos(double ___a);

double
SDL2Gate_SDL_cos(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_cos(___a);
}

STATIC double 
SDL2Gate_SDL_cosPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_cos(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_cos = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_cosPPC };

float SDL_cosf(float ___a);

float
SDL2Gate_SDL_cosf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_cosf(___a);
}

STATIC float 
SDL2Gate_SDL_cosfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_cosf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_cosf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_cosfPPC };

double SDL_fabs(double ___a);

double
SDL2Gate_SDL_fabs(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_fabs(___a);
}

STATIC double 
SDL2Gate_SDL_fabsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_fabs(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_fabs = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_fabsPPC };

double SDL_floor(double ___a);

double
SDL2Gate_SDL_floor(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_floor(___a);
}

STATIC double 
SDL2Gate_SDL_floorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_floor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_floor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_floorPPC };

double SDL_log(double ___a);

double
SDL2Gate_SDL_log(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_log(___a);
}

STATIC double 
SDL2Gate_SDL_logPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_log(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_log = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_logPPC };

double SDL_pow(double ___a, double ___b);

double
SDL2Gate_SDL_pow(struct SDL2IFace* _iface,
     double ___a,
     double ___b)
{
  return SDL_pow(___a, ___b);
}

STATIC double 
SDL2Gate_SDL_powPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];
  double ___b = (double) regarray[REG68K_D2/4];

  return _iface->SDL_pow(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_pow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_powPPC };

double SDL_scalbn(double ___a, int ___b);

double
SDL2Gate_SDL_scalbn(struct SDL2IFace* _iface,
     double ___a,
     int ___b)
{
  return SDL_scalbn(___a, ___b);
}

STATIC double 
SDL2Gate_SDL_scalbnPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D2/4];

  return _iface->SDL_scalbn(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_scalbn = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_scalbnPPC };

double SDL_sin(double ___a);

double
SDL2Gate_SDL_sin(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_sin(___a);
}

STATIC double 
SDL2Gate_SDL_sinPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_sin(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_sin = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_sinPPC };

float SDL_sinf(float ___a);

float
SDL2Gate_SDL_sinf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_sinf(___a);
}

STATIC float 
SDL2Gate_SDL_sinfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_sinf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_sinf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_sinfPPC };

double SDL_sqrt(double ___a);

double
SDL2Gate_SDL_sqrt(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_sqrt(___a);
}

STATIC double 
SDL2Gate_SDL_sqrtPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_sqrt(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_sqrt = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_sqrtPPC };

SDL_iconv_t SDL_iconv_open(const char * ___a, const char * ___b);

SDL_iconv_t
SDL2Gate_SDL_iconv_open(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_iconv_open(___a, ___b);
}

STATIC SDL_iconv_t 
SDL2Gate_SDL_iconv_openPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_iconv_open(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_iconv_open = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_iconv_openPPC };

int SDL_iconv_close(SDL_iconv_t ___a);

int
SDL2Gate_SDL_iconv_close(struct SDL2IFace* _iface,
     SDL_iconv_t ___a)
{
  return SDL_iconv_close(___a);
}

STATIC int 
SDL2Gate_SDL_iconv_closePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_iconv_t ___a = (SDL_iconv_t) regarray[REG68K_D0/4];

  return _iface->SDL_iconv_close(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_iconv_close = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_iconv_closePPC };

size_t SDL_iconv(SDL_iconv_t ___a, const char * * ___b, size_t * ___c, char * * ___d, size_t * ___e);

size_t
SDL2Gate_SDL_iconv(struct SDL2IFace* _iface,
     SDL_iconv_t ___a,
     const char * * ___b,
     size_t * ___c,
     char * * ___d,
     size_t * ___e)
{
  return SDL_iconv(___a, ___b, ___c, ___d, ___e);
}

STATIC size_t 
SDL2Gate_SDL_iconvPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_iconv_t ___a = (SDL_iconv_t) regarray[REG68K_D0/4];
  const char * * ___b = (const char * *) regarray[REG68K_A0/4];
  size_t * ___c = (size_t *) regarray[REG68K_A1/4];
  char * * ___d = (char * *) regarray[REG68K_A2/4];
  size_t * ___e = (size_t *) regarray[REG68K_A3/4];

  return _iface->SDL_iconv(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_iconv = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_iconvPPC };

char* SDL_iconv_string(const char * ___a, const char * ___b, const char * ___c, size_t ___d);

char*
SDL2Gate_SDL_iconv_string(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b,
     const char * ___c,
     size_t ___d)
{
  return SDL_iconv_string(___a, ___b, ___c, ___d);
}

STATIC char* 
SDL2Gate_SDL_iconv_stringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  const char * ___c = (const char *) regarray[REG68K_A2/4];
  size_t ___d = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_iconv_string(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_iconv_string = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_iconv_stringPPC };

SDL_Surface* SDL_CreateRGBSurface(Uint32 ___a, int ___b, int ___c, int ___d, Uint32 ___e, Uint32 ___f, Uint32 ___g, Uint32 ___h);

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurface(struct SDL2IFace* _iface,
     Uint32 ___a,
     int ___b,
     int ___c,
     int ___d,
     Uint32 ___e,
     Uint32 ___f,
     Uint32 ___g,
     Uint32 ___h)
{
  return SDL_CreateRGBSurface(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_CreateRGBSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  int ___c = (int) regarray[REG68K_D2/4];
  int ___d = (int) regarray[REG68K_D3/4];
  Uint32 ___e = (Uint32) regarray[REG68K_D4/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D5/4];
  Uint32 ___g = (Uint32) regarray[REG68K_D6/4];
  Uint32 ___h = (Uint32) regarray[REG68K_D7/4];

  return _iface->SDL_CreateRGBSurface(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateRGBSurfacePPC };

SDL_Surface* SDL_CreateRGBSurfaceFrom(void * ___a, int ___b, int ___c, int ___d, int ___e, Uint32 ___f, Uint32 ___g, Uint32 ___h, Uint32 ___i);

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
     Uint32 ___i)
{
  return SDL_CreateRGBSurfaceFrom(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h, ___i);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_CreateRGBSurfaceFromPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  int ___d = (int) regarray[REG68K_D2/4];
  int ___e = (int) regarray[REG68K_D3/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D4/4];
  Uint32 ___g = (Uint32) regarray[REG68K_D5/4];
  Uint32 ___h = (Uint32) regarray[REG68K_D6/4];
  Uint32 ___i = (Uint32) regarray[REG68K_D7/4];

  return _iface->SDL_CreateRGBSurfaceFrom(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h, ___i);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurfaceFrom = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateRGBSurfaceFromPPC };

void SDL_FreeSurface(SDL_Surface * ___a);

void
SDL2Gate_SDL_FreeSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_FreeSurface(___a);
}

STATIC void 
SDL2Gate_SDL_FreeSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_FreeSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreeSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreeSurfacePPC };

int SDL_SetSurfacePalette(SDL_Surface * ___a, SDL_Palette * ___b);

int
SDL2Gate_SDL_SetSurfacePalette(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Palette * ___b)
{
  return SDL_SetSurfacePalette(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetSurfacePalettePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_Palette * ___b = (SDL_Palette *) regarray[REG68K_A1/4];

  return _iface->SDL_SetSurfacePalette(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfacePalette = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetSurfacePalettePPC };

int SDL_LockSurface(SDL_Surface * ___a);

int
SDL2Gate_SDL_LockSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_LockSurface(___a);
}

STATIC int 
SDL2Gate_SDL_LockSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_LockSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockSurfacePPC };

void SDL_UnlockSurface(SDL_Surface * ___a);

void
SDL2Gate_SDL_UnlockSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_UnlockSurface(___a);
}

STATIC void 
SDL2Gate_SDL_UnlockSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_UnlockSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockSurfacePPC };

SDL_Surface* SDL_LoadBMP_RW(SDL_RWops * ___a, int ___b);

SDL_Surface*
SDL2Gate_SDL_LoadBMP_RW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     int ___b)
{
  return SDL_LoadBMP_RW(___a, ___b);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_LoadBMP_RWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_LoadBMP_RW(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadBMP_RW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadBMP_RWPPC };

int SDL_SaveBMP_RW(SDL_Surface * ___a, SDL_RWops * ___b, int ___c);

int
SDL2Gate_SDL_SaveBMP_RW(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_RWops * ___b,
     int ___c)
{
  return SDL_SaveBMP_RW(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_SaveBMP_RWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_RWops * ___b = (SDL_RWops *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SaveBMP_RW(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SaveBMP_RW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SaveBMP_RWPPC };

int SDL_SetSurfaceRLE(SDL_Surface * ___a, int ___b);

int
SDL2Gate_SDL_SetSurfaceRLE(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     int ___b)
{
  return SDL_SetSurfaceRLE(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetSurfaceRLEPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SetSurfaceRLE(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceRLE = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetSurfaceRLEPPC };

int SDL_SetColorKey(SDL_Surface * ___a, int ___b, Uint32 ___c);

int
SDL2Gate_SDL_SetColorKey(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     int ___b,
     Uint32 ___c)
{
  return SDL_SetColorKey(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_SetColorKeyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_SetColorKey(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetColorKey = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetColorKeyPPC };

int SDL_GetColorKey(SDL_Surface * ___a, Uint32 * ___b);

int
SDL2Gate_SDL_GetColorKey(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint32 * ___b)
{
  return SDL_GetColorKey(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetColorKeyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  Uint32 * ___b = (Uint32 *) regarray[REG68K_A1/4];

  return _iface->SDL_GetColorKey(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetColorKey = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetColorKeyPPC };

int SDL_SetSurfaceColorMod(SDL_Surface * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d);

int
SDL2Gate_SDL_SetSurfaceColorMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d)
{
  return SDL_SetSurfaceColorMod(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SetSurfaceColorModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];

  return _iface->SDL_SetSurfaceColorMod(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceColorMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetSurfaceColorModPPC };

int SDL_GetSurfaceColorMod(SDL_Surface * ___a, Uint8 * ___b, Uint8 * ___c, Uint8 * ___d);

int
SDL2Gate_SDL_GetSurfaceColorMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 * ___b,
     Uint8 * ___c,
     Uint8 * ___d)
{
  return SDL_GetSurfaceColorMod(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GetSurfaceColorModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  Uint8 * ___b = (Uint8 *) regarray[REG68K_A1/4];
  Uint8 * ___c = (Uint8 *) regarray[REG68K_A2/4];
  Uint8 * ___d = (Uint8 *) regarray[REG68K_A3/4];

  return _iface->SDL_GetSurfaceColorMod(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetSurfaceColorMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetSurfaceColorModPPC };

int SDL_SetSurfaceAlphaMod(SDL_Surface * ___a, Uint8 ___b);

int
SDL2Gate_SDL_SetSurfaceAlphaMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 ___b)
{
  return SDL_SetSurfaceAlphaMod(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetSurfaceAlphaModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];

  return _iface->SDL_SetSurfaceAlphaMod(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceAlphaMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetSurfaceAlphaModPPC };

int SDL_GetSurfaceAlphaMod(SDL_Surface * ___a, Uint8 * ___b);

int
SDL2Gate_SDL_GetSurfaceAlphaMod(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint8 * ___b)
{
  return SDL_GetSurfaceAlphaMod(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetSurfaceAlphaModPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  Uint8 * ___b = (Uint8 *) regarray[REG68K_A1/4];

  return _iface->SDL_GetSurfaceAlphaMod(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetSurfaceAlphaMod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetSurfaceAlphaModPPC };

int SDL_SetSurfaceBlendMode(SDL_Surface * ___a, SDL_BlendMode ___b);

int
SDL2Gate_SDL_SetSurfaceBlendMode(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_BlendMode ___b)
{
  return SDL_SetSurfaceBlendMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetSurfaceBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_BlendMode ___b = (SDL_BlendMode) regarray[REG68K_D0/4];

  return _iface->SDL_SetSurfaceBlendMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetSurfaceBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetSurfaceBlendModePPC };

int SDL_GetSurfaceBlendMode(SDL_Surface * ___a, SDL_BlendMode * ___b);

int
SDL2Gate_SDL_GetSurfaceBlendMode(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_BlendMode * ___b)
{
  return SDL_GetSurfaceBlendMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetSurfaceBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_BlendMode * ___b = (SDL_BlendMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetSurfaceBlendMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetSurfaceBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetSurfaceBlendModePPC };

SDL_bool SDL_SetClipRect(SDL_Surface * ___a, const SDL_Rect * ___b);

SDL_bool
SDL2Gate_SDL_SetClipRect(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b)
{
  return SDL_SetClipRect(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_SetClipRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_SetClipRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetClipRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetClipRectPPC };

void SDL_GetClipRect(SDL_Surface * ___a, SDL_Rect * ___b);

void
SDL2Gate_SDL_GetClipRect(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Rect * ___b)
{
  return SDL_GetClipRect(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_GetClipRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_GetClipRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetClipRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetClipRectPPC };

SDL_Surface* SDL_ConvertSurface(SDL_Surface * ___a, const SDL_PixelFormat * ___b, Uint32 ___c);

SDL_Surface*
SDL2Gate_SDL_ConvertSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_PixelFormat * ___b,
     Uint32 ___c)
{
  return SDL_ConvertSurface(___a, ___b, ___c);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_ConvertSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_PixelFormat * ___b = (const SDL_PixelFormat *) regarray[REG68K_A1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_ConvertSurface(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ConvertSurfacePPC };

SDL_Surface* SDL_ConvertSurfaceFormat(SDL_Surface * ___a, Uint32 ___b, Uint32 ___c);

SDL_Surface*
SDL2Gate_SDL_ConvertSurfaceFormat(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     Uint32 ___b,
     Uint32 ___c)
{
  return SDL_ConvertSurfaceFormat(___a, ___b, ___c);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_ConvertSurfaceFormatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_ConvertSurfaceFormat(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertSurfaceFormat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ConvertSurfaceFormatPPC };

int SDL_ConvertPixels(int ___a, int ___b, Uint32 ___c, const void * ___d, int ___e, Uint32 ___f, void * ___g, int ___h);

int
SDL2Gate_SDL_ConvertPixels(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     Uint32 ___c,
     const void * ___d,
     int ___e,
     Uint32 ___f,
     void * ___g,
     int ___h)
{
  return SDL_ConvertPixels(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

STATIC int 
SDL2Gate_SDL_ConvertPixelsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D2/4];
  const void * ___d = (const void *) regarray[REG68K_A0/4];
  int ___e = (int) regarray[REG68K_D3/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D4/4];
  void * ___g = (void *) regarray[REG68K_A1/4];
  int ___h = (int) regarray[REG68K_D5/4];

  return _iface->SDL_ConvertPixels(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ConvertPixels = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ConvertPixelsPPC };

int SDL_FillRect(SDL_Surface * ___a, const SDL_Rect * ___b, Uint32 ___c);

int
SDL2Gate_SDL_FillRect(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     Uint32 ___c)
{
  return SDL_FillRect(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_FillRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_FillRect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FillRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FillRectPPC };

int SDL_FillRects(SDL_Surface * ___a, const SDL_Rect * ___b, int ___c, Uint32 ___d);

int
SDL2Gate_SDL_FillRects(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     int ___c,
     Uint32 ___d)
{
  return SDL_FillRects(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_FillRectsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_FillRects(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FillRects = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FillRectsPPC };

int SDL_UpperBlit(SDL_Surface * ___a, const SDL_Rect * ___b, SDL_Surface * ___c, SDL_Rect * ___d);

int
SDL2Gate_SDL_UpperBlit(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d)
{
  return SDL_UpperBlit(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_UpperBlitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * ___c = (SDL_Surface *) regarray[REG68K_A2/4];
  SDL_Rect * ___d = (SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_UpperBlit(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpperBlit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpperBlitPPC };

int SDL_LowerBlit(SDL_Surface * ___a, SDL_Rect * ___b, SDL_Surface * ___c, SDL_Rect * ___d);

int
SDL2Gate_SDL_LowerBlit(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d)
{
  return SDL_LowerBlit(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_LowerBlitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * ___c = (SDL_Surface *) regarray[REG68K_A2/4];
  SDL_Rect * ___d = (SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_LowerBlit(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LowerBlit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LowerBlitPPC };

int SDL_SoftStretch(SDL_Surface * ___a, const SDL_Rect * ___b, SDL_Surface * ___c, const SDL_Rect * ___d);

int
SDL2Gate_SDL_SoftStretch(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     const SDL_Rect * ___d)
{
  return SDL_SoftStretch(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SoftStretchPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * ___c = (SDL_Surface *) regarray[REG68K_A2/4];
  const SDL_Rect * ___d = (const SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_SoftStretch(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SoftStretch = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SoftStretchPPC };

int SDL_UpperBlitScaled(SDL_Surface * ___a, const SDL_Rect * ___b, SDL_Surface * ___c, SDL_Rect * ___d);

int
SDL2Gate_SDL_UpperBlitScaled(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d)
{
  return SDL_UpperBlitScaled(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_UpperBlitScaledPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * ___c = (SDL_Surface *) regarray[REG68K_A2/4];
  SDL_Rect * ___d = (SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_UpperBlitScaled(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpperBlitScaled = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpperBlitScaledPPC };

int SDL_LowerBlitScaled(SDL_Surface * ___a, SDL_Rect * ___b, SDL_Surface * ___c, SDL_Rect * ___d);

int
SDL2Gate_SDL_LowerBlitScaled(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     SDL_Rect * ___b,
     SDL_Surface * ___c,
     SDL_Rect * ___d)
{
  return SDL_LowerBlitScaled(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_LowerBlitScaledPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * ___c = (SDL_Surface *) regarray[REG68K_A2/4];
  SDL_Rect * ___d = (SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_LowerBlitScaled(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LowerBlitScaled = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LowerBlitScaledPPC };

SDL_bool SDL_GetWindowWMInfo(SDL_Window * ___a, SDL_SysWMinfo * ___b);

SDL_bool
SDL2Gate_SDL_GetWindowWMInfo(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_SysWMinfo * ___b)
{
  return SDL_GetWindowWMInfo(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GetWindowWMInfoPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_SysWMinfo * ___b = (SDL_SysWMinfo *) regarray[REG68K_A1/4];

  return _iface->SDL_GetWindowWMInfo(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowWMInfo = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowWMInfoPPC };

const char* SDL_GetThreadName(SDL_Thread * ___a);

const char*
SDL2Gate_SDL_GetThreadName(struct SDL2IFace* _iface,
     SDL_Thread * ___a)
{
  return SDL_GetThreadName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetThreadNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Thread * ___a = (SDL_Thread *) regarray[REG68K_A0/4];

  return _iface->SDL_GetThreadName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetThreadName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetThreadNamePPC };

SDL_threadID SDL_ThreadID(void);

SDL_threadID
SDL2Gate_SDL_ThreadID(struct SDL2IFace* _iface)
{
  return SDL_ThreadID();
}

STATIC SDL_threadID 
SDL2Gate_SDL_ThreadIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ThreadID();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ThreadID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ThreadIDPPC };

SDL_threadID SDL_GetThreadID(SDL_Thread * ___a);

SDL_threadID
SDL2Gate_SDL_GetThreadID(struct SDL2IFace* _iface,
     SDL_Thread * ___a)
{
  return SDL_GetThreadID(___a);
}

STATIC SDL_threadID 
SDL2Gate_SDL_GetThreadIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Thread * ___a = (SDL_Thread *) regarray[REG68K_A0/4];

  return _iface->SDL_GetThreadID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetThreadID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetThreadIDPPC };

int SDL_SetThreadPriority(SDL_ThreadPriority ___a);

int
SDL2Gate_SDL_SetThreadPriority(struct SDL2IFace* _iface,
     SDL_ThreadPriority ___a)
{
  return SDL_SetThreadPriority(___a);
}

STATIC int 
SDL2Gate_SDL_SetThreadPriorityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_ThreadPriority ___a = (SDL_ThreadPriority) regarray[REG68K_D0/4];

  return _iface->SDL_SetThreadPriority(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetThreadPriority = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetThreadPriorityPPC };

void SDL_WaitThread(SDL_Thread * ___a, int * ___b);

void
SDL2Gate_SDL_WaitThread(struct SDL2IFace* _iface,
     SDL_Thread * ___a,
     int * ___b)
{
  return SDL_WaitThread(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_WaitThreadPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Thread * ___a = (SDL_Thread *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];

  return _iface->SDL_WaitThread(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WaitThread = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WaitThreadPPC };

void SDL_DetachThread(SDL_Thread * ___a);

void
SDL2Gate_SDL_DetachThread(struct SDL2IFace* _iface,
     SDL_Thread * ___a)
{
  return SDL_DetachThread(___a);
}

STATIC void 
SDL2Gate_SDL_DetachThreadPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Thread * ___a = (SDL_Thread *) regarray[REG68K_A0/4];

  return _iface->SDL_DetachThread(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DetachThread = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DetachThreadPPC };

SDL_TLSID SDL_TLSCreate(void);

SDL_TLSID
SDL2Gate_SDL_TLSCreate(struct SDL2IFace* _iface)
{
  return SDL_TLSCreate();
}

STATIC SDL_TLSID 
SDL2Gate_SDL_TLSCreatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_TLSCreate();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_TLSCreate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_TLSCreatePPC };

void* SDL_TLSGet(SDL_TLSID ___a);

void*
SDL2Gate_SDL_TLSGet(struct SDL2IFace* _iface,
     SDL_TLSID ___a)
{
  return SDL_TLSGet(___a);
}

STATIC void* 
SDL2Gate_SDL_TLSGetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TLSID ___a = (SDL_TLSID) regarray[REG68K_D0/4];

  return _iface->SDL_TLSGet(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_TLSGet = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_TLSGetPPC };

int SDL_TLSSet(SDL_TLSID ___a, const void * ___b, SDL_TLSDestructorCallback ___c);

int
SDL2Gate_SDL_TLSSet(struct SDL2IFace* _iface,
     SDL_TLSID ___a,
     const void * ___b,
     SDL_TLSDestructorCallback ___c)
{
  return SDL_TLSSet(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_TLSSetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TLSID ___a = (SDL_TLSID) regarray[REG68K_D0/4];
  const void * ___b = (const void *) regarray[REG68K_A0/4];
  SDL_TLSDestructorCallback ___c = (SDL_TLSDestructorCallback) regarray[REG68K_D1/4];

  return _iface->SDL_TLSSet(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_TLSSet = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_TLSSetPPC };

Uint32 SDL_GetTicks(void);

Uint32
SDL2Gate_SDL_GetTicks(struct SDL2IFace* _iface)
{
  return SDL_GetTicks();
}

STATIC Uint32 
SDL2Gate_SDL_GetTicksPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetTicks();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTicks = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTicksPPC };

Uint64 SDL_GetPerformanceCounter(void);

Uint64
SDL2Gate_SDL_GetPerformanceCounter(struct SDL2IFace* _iface)
{
  return SDL_GetPerformanceCounter();
}

STATIC Uint64 
SDL2Gate_SDL_GetPerformanceCounterPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetPerformanceCounter();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPerformanceCounter = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPerformanceCounterPPC };

Uint64 SDL_GetPerformanceFrequency(void);

Uint64
SDL2Gate_SDL_GetPerformanceFrequency(struct SDL2IFace* _iface)
{
  return SDL_GetPerformanceFrequency();
}

STATIC Uint64 
SDL2Gate_SDL_GetPerformanceFrequencyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetPerformanceFrequency();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPerformanceFrequency = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPerformanceFrequencyPPC };

void SDL_Delay(Uint32 ___a);

void
SDL2Gate_SDL_Delay(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_Delay(___a);
}

STATIC void 
SDL2Gate_SDL_DelayPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_Delay(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Delay = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DelayPPC };

SDL_TimerID SDL_AddTimer(Uint32 ___a, SDL_TimerCallback ___b, void * ___c);

SDL_TimerID
SDL2Gate_SDL_AddTimer(struct SDL2IFace* _iface,
     Uint32 ___a,
     SDL_TimerCallback ___b,
     void * ___c)
{
  return SDL_AddTimer(___a, ___b, ___c);
}

STATIC SDL_TimerID 
SDL2Gate_SDL_AddTimerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  SDL_TimerCallback ___b = (SDL_TimerCallback) regarray[REG68K_D1/4];
  void * ___c = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_AddTimer(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AddTimer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AddTimerPPC };

SDL_bool SDL_RemoveTimer(SDL_TimerID ___a);

SDL_bool
SDL2Gate_SDL_RemoveTimer(struct SDL2IFace* _iface,
     SDL_TimerID ___a)
{
  return SDL_RemoveTimer(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_RemoveTimerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TimerID ___a = (SDL_TimerID) regarray[REG68K_D0/4];

  return _iface->SDL_RemoveTimer(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RemoveTimer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RemoveTimerPPC };

int SDL_GetNumTouchDevices(void);

int
SDL2Gate_SDL_GetNumTouchDevices(struct SDL2IFace* _iface)
{
  return SDL_GetNumTouchDevices();
}

STATIC int 
SDL2Gate_SDL_GetNumTouchDevicesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetNumTouchDevices();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumTouchDevices = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumTouchDevicesPPC };

SDL_TouchID SDL_GetTouchDevice(int ___a);

SDL_TouchID
SDL2Gate_SDL_GetTouchDevice(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetTouchDevice(___a);
}

STATIC SDL_TouchID 
SDL2Gate_SDL_GetTouchDevicePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetTouchDevice(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchDevice = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTouchDevicePPC };

int SDL_GetNumTouchFingers(SDL_TouchID ___a);

int
SDL2Gate_SDL_GetNumTouchFingers(struct SDL2IFace* _iface,
     SDL_TouchID ___a)
{
  return SDL_GetNumTouchFingers(___a);
}

STATIC int 
SDL2Gate_SDL_GetNumTouchFingersPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TouchID ___a = (SDL_TouchID) regarray[REG68K_D0/4];

  return _iface->SDL_GetNumTouchFingers(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumTouchFingers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumTouchFingersPPC };

SDL_Finger* SDL_GetTouchFinger(SDL_TouchID ___a, int ___b);

SDL_Finger*
SDL2Gate_SDL_GetTouchFinger(struct SDL2IFace* _iface,
     SDL_TouchID ___a,
     int ___b)
{
  return SDL_GetTouchFinger(___a, ___b);
}

STATIC SDL_Finger* 
SDL2Gate_SDL_GetTouchFingerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TouchID ___a = (SDL_TouchID) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D2/4];

  return _iface->SDL_GetTouchFinger(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchFinger = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTouchFingerPPC };

void SDL_GetVersion(SDL_version * ___a);

void
SDL2Gate_SDL_GetVersion(struct SDL2IFace* _iface,
     SDL_version * ___a)
{
  return SDL_GetVersion(___a);
}

STATIC void 
SDL2Gate_SDL_GetVersionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_version * ___a = (SDL_version *) regarray[REG68K_A0/4];

  return _iface->SDL_GetVersion(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetVersion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetVersionPPC };

const char* SDL_GetRevision(void);

const char*
SDL2Gate_SDL_GetRevision(struct SDL2IFace* _iface)
{
  return SDL_GetRevision();
}

STATIC const char* 
SDL2Gate_SDL_GetRevisionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetRevision();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRevision = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRevisionPPC };

int SDL_GetRevisionNumber(void);

int
SDL2Gate_SDL_GetRevisionNumber(struct SDL2IFace* _iface)
{
  return SDL_GetRevisionNumber();
}

STATIC int 
SDL2Gate_SDL_GetRevisionNumberPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetRevisionNumber();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRevisionNumber = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRevisionNumberPPC };

int SDL_GetNumVideoDrivers(void);

int
SDL2Gate_SDL_GetNumVideoDrivers(struct SDL2IFace* _iface)
{
  return SDL_GetNumVideoDrivers();
}

STATIC int 
SDL2Gate_SDL_GetNumVideoDriversPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetNumVideoDrivers();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumVideoDrivers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumVideoDriversPPC };

const char* SDL_GetVideoDriver(int ___a);

const char*
SDL2Gate_SDL_GetVideoDriver(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetVideoDriver(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetVideoDriverPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetVideoDriver(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetVideoDriver = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetVideoDriverPPC };

int SDL_VideoInit(const char * ___a);

int
SDL2Gate_SDL_VideoInit(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_VideoInit(___a);
}

STATIC int 
SDL2Gate_SDL_VideoInitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_VideoInit(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_VideoInit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_VideoInitPPC };

void SDL_VideoQuit(void);

void
SDL2Gate_SDL_VideoQuit(struct SDL2IFace* _iface)
{
  return SDL_VideoQuit();
}

STATIC void 
SDL2Gate_SDL_VideoQuitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_VideoQuit();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_VideoQuit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_VideoQuitPPC };

const char* SDL_GetCurrentVideoDriver(void);

const char*
SDL2Gate_SDL_GetCurrentVideoDriver(struct SDL2IFace* _iface)
{
  return SDL_GetCurrentVideoDriver();
}

STATIC const char* 
SDL2Gate_SDL_GetCurrentVideoDriverPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetCurrentVideoDriver();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetCurrentVideoDriver = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetCurrentVideoDriverPPC };

int SDL_GetNumVideoDisplays(void);

int
SDL2Gate_SDL_GetNumVideoDisplays(struct SDL2IFace* _iface)
{
  return SDL_GetNumVideoDisplays();
}

STATIC int 
SDL2Gate_SDL_GetNumVideoDisplaysPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetNumVideoDisplays();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumVideoDisplays = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumVideoDisplaysPPC };

const char* SDL_GetDisplayName(int ___a);

const char*
SDL2Gate_SDL_GetDisplayName(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetDisplayName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetDisplayNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetDisplayName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDisplayNamePPC };

int SDL_GetDisplayBounds(int ___a, SDL_Rect * ___b);

int
SDL2Gate_SDL_GetDisplayBounds(struct SDL2IFace* _iface,
     int ___a,
     SDL_Rect * ___b)
{
  return SDL_GetDisplayBounds(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetDisplayBoundsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A0/4];

  return _iface->SDL_GetDisplayBounds(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayBounds = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDisplayBoundsPPC };

int SDL_GetNumDisplayModes(int ___a);

int
SDL2Gate_SDL_GetNumDisplayModes(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetNumDisplayModes(___a);
}

STATIC int 
SDL2Gate_SDL_GetNumDisplayModesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetNumDisplayModes(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumDisplayModes = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumDisplayModesPPC };

int SDL_GetDisplayMode(int ___a, int ___b, SDL_DisplayMode * ___c);

int
SDL2Gate_SDL_GetDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     SDL_DisplayMode * ___c)
{
  return SDL_GetDisplayMode(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GetDisplayModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  SDL_DisplayMode * ___c = (SDL_DisplayMode *) regarray[REG68K_A0/4];

  return _iface->SDL_GetDisplayMode(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDisplayModePPC };

int SDL_GetDesktopDisplayMode(int ___a, SDL_DisplayMode * ___b);

int
SDL2Gate_SDL_GetDesktopDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     SDL_DisplayMode * ___b)
{
  return SDL_GetDesktopDisplayMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetDesktopDisplayModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  SDL_DisplayMode * ___b = (SDL_DisplayMode *) regarray[REG68K_A0/4];

  return _iface->SDL_GetDesktopDisplayMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDesktopDisplayMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDesktopDisplayModePPC };

int SDL_GetCurrentDisplayMode(int ___a, SDL_DisplayMode * ___b);

int
SDL2Gate_SDL_GetCurrentDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     SDL_DisplayMode * ___b)
{
  return SDL_GetCurrentDisplayMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetCurrentDisplayModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  SDL_DisplayMode * ___b = (SDL_DisplayMode *) regarray[REG68K_A0/4];

  return _iface->SDL_GetCurrentDisplayMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetCurrentDisplayMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetCurrentDisplayModePPC };

SDL_DisplayMode* SDL_GetClosestDisplayMode(int ___a, const SDL_DisplayMode * ___b, SDL_DisplayMode * ___c);

SDL_DisplayMode*
SDL2Gate_SDL_GetClosestDisplayMode(struct SDL2IFace* _iface,
     int ___a,
     const SDL_DisplayMode * ___b,
     SDL_DisplayMode * ___c)
{
  return SDL_GetClosestDisplayMode(___a, ___b, ___c);
}

STATIC SDL_DisplayMode* 
SDL2Gate_SDL_GetClosestDisplayModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  const SDL_DisplayMode * ___b = (const SDL_DisplayMode *) regarray[REG68K_A0/4];
  SDL_DisplayMode * ___c = (SDL_DisplayMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetClosestDisplayMode(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetClosestDisplayMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetClosestDisplayModePPC };

int SDL_GetWindowDisplayIndex(SDL_Window * ___a);

int
SDL2Gate_SDL_GetWindowDisplayIndex(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowDisplayIndex(___a);
}

STATIC int 
SDL2Gate_SDL_GetWindowDisplayIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowDisplayIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowDisplayIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowDisplayIndexPPC };

int SDL_SetWindowDisplayMode(SDL_Window * ___a, const SDL_DisplayMode * ___b);

int
SDL2Gate_SDL_SetWindowDisplayMode(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const SDL_DisplayMode * ___b)
{
  return SDL_SetWindowDisplayMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetWindowDisplayModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const SDL_DisplayMode * ___b = (const SDL_DisplayMode *) regarray[REG68K_A1/4];

  return _iface->SDL_SetWindowDisplayMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowDisplayMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowDisplayModePPC };

int SDL_GetWindowDisplayMode(SDL_Window * ___a, SDL_DisplayMode * ___b);

int
SDL2Gate_SDL_GetWindowDisplayMode(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_DisplayMode * ___b)
{
  return SDL_GetWindowDisplayMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetWindowDisplayModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_DisplayMode * ___b = (SDL_DisplayMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetWindowDisplayMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowDisplayMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowDisplayModePPC };

Uint32 SDL_GetWindowPixelFormat(SDL_Window * ___a);

Uint32
SDL2Gate_SDL_GetWindowPixelFormat(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowPixelFormat(___a);
}

STATIC Uint32 
SDL2Gate_SDL_GetWindowPixelFormatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowPixelFormat(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowPixelFormat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowPixelFormatPPC };

SDL_Window* SDL_CreateWindow(const char * ___a, int ___b, int ___c, int ___d, int ___e, Uint32 ___f);

SDL_Window*
SDL2Gate_SDL_CreateWindow(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e,
     Uint32 ___f)
{
  return SDL_CreateWindow(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_Window* 
SDL2Gate_SDL_CreateWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  int ___d = (int) regarray[REG68K_D2/4];
  int ___e = (int) regarray[REG68K_D3/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D4/4];

  return _iface->SDL_CreateWindow(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateWindowPPC };

SDL_Window* SDL_CreateWindowFrom(const void * ___a);

SDL_Window*
SDL2Gate_SDL_CreateWindowFrom(struct SDL2IFace* _iface,
     const void * ___a)
{
  return SDL_CreateWindowFrom(___a);
}

STATIC SDL_Window* 
SDL2Gate_SDL_CreateWindowFromPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const void * ___a = (const void *) regarray[REG68K_A0/4];

  return _iface->SDL_CreateWindowFrom(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateWindowFrom = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateWindowFromPPC };

Uint32 SDL_GetWindowID(SDL_Window * ___a);

Uint32
SDL2Gate_SDL_GetWindowID(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowID(___a);
}

STATIC Uint32 
SDL2Gate_SDL_GetWindowIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowIDPPC };

SDL_Window* SDL_GetWindowFromID(Uint32 ___a);

SDL_Window*
SDL2Gate_SDL_GetWindowFromID(struct SDL2IFace* _iface,
     Uint32 ___a)
{
  return SDL_GetWindowFromID(___a);
}

STATIC SDL_Window* 
SDL2Gate_SDL_GetWindowFromIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_GetWindowFromID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowFromID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowFromIDPPC };

Uint32 SDL_GetWindowFlags(SDL_Window * ___a);

Uint32
SDL2Gate_SDL_GetWindowFlags(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowFlags(___a);
}

STATIC Uint32 
SDL2Gate_SDL_GetWindowFlagsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowFlags(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowFlags = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowFlagsPPC };

void SDL_SetWindowTitle(SDL_Window * ___a, const char * ___b);

void
SDL2Gate_SDL_SetWindowTitle(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const char * ___b)
{
  return SDL_SetWindowTitle(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowTitlePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_SetWindowTitle(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowTitle = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowTitlePPC };

const char* SDL_GetWindowTitle(SDL_Window * ___a);

const char*
SDL2Gate_SDL_GetWindowTitle(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowTitle(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetWindowTitlePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowTitle(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowTitle = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowTitlePPC };

void SDL_SetWindowIcon(SDL_Window * ___a, SDL_Surface * ___b);

void
SDL2Gate_SDL_SetWindowIcon(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_Surface * ___b)
{
  return SDL_SetWindowIcon(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowIconPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_Surface * ___b = (SDL_Surface *) regarray[REG68K_A1/4];

  return _iface->SDL_SetWindowIcon(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowIcon = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowIconPPC };

void* SDL_SetWindowData(SDL_Window * ___a, const char * ___b, void * ___c);

void*
SDL2Gate_SDL_SetWindowData(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const char * ___b,
     void * ___c)
{
  return SDL_SetWindowData(___a, ___b, ___c);
}

STATIC void* 
SDL2Gate_SDL_SetWindowDataPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  void * ___c = (void *) regarray[REG68K_A2/4];

  return _iface->SDL_SetWindowData(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowData = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowDataPPC };

void* SDL_GetWindowData(SDL_Window * ___a, const char * ___b);

void*
SDL2Gate_SDL_GetWindowData(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const char * ___b)
{
  return SDL_GetWindowData(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_GetWindowDataPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_GetWindowData(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowData = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowDataPPC };

void SDL_SetWindowPosition(SDL_Window * ___a, int ___b, int ___c);

void
SDL2Gate_SDL_SetWindowPosition(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c)
{
  return SDL_SetWindowPosition(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_SetWindowPositionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_SetWindowPosition(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowPosition = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowPositionPPC };

void SDL_GetWindowPosition(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_GetWindowPosition(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GetWindowPosition(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_GetWindowPositionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GetWindowPosition(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowPosition = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowPositionPPC };

void SDL_SetWindowSize(SDL_Window * ___a, int ___b, int ___c);

void
SDL2Gate_SDL_SetWindowSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c)
{
  return SDL_SetWindowSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_SetWindowSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_SetWindowSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowSizePPC };

void SDL_GetWindowSize(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_GetWindowSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GetWindowSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_GetWindowSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GetWindowSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowSizePPC };

void SDL_SetWindowMinimumSize(SDL_Window * ___a, int ___b, int ___c);

void
SDL2Gate_SDL_SetWindowMinimumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c)
{
  return SDL_SetWindowMinimumSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_SetWindowMinimumSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_SetWindowMinimumSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMinimumSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowMinimumSizePPC };

void SDL_GetWindowMinimumSize(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_GetWindowMinimumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GetWindowMinimumSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_GetWindowMinimumSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GetWindowMinimumSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMinimumSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowMinimumSizePPC };

void SDL_SetWindowMaximumSize(SDL_Window * ___a, int ___b, int ___c);

void
SDL2Gate_SDL_SetWindowMaximumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int ___b,
     int ___c)
{
  return SDL_SetWindowMaximumSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_SetWindowMaximumSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];

  return _iface->SDL_SetWindowMaximumSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMaximumSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowMaximumSizePPC };

void SDL_GetWindowMaximumSize(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_GetWindowMaximumSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GetWindowMaximumSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_GetWindowMaximumSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GetWindowMaximumSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMaximumSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowMaximumSizePPC };

void SDL_SetWindowBordered(SDL_Window * ___a, SDL_bool ___b);

void
SDL2Gate_SDL_SetWindowBordered(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b)
{
  return SDL_SetWindowBordered(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowBorderedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowBordered(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowBordered = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowBorderedPPC };

void SDL_ShowWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_ShowWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_ShowWindow(___a);
}

STATIC void 
SDL2Gate_SDL_ShowWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_ShowWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ShowWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ShowWindowPPC };

void SDL_HideWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_HideWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_HideWindow(___a);
}

STATIC void 
SDL2Gate_SDL_HideWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_HideWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HideWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HideWindowPPC };

void SDL_RaiseWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_RaiseWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_RaiseWindow(___a);
}

STATIC void 
SDL2Gate_SDL_RaiseWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_RaiseWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RaiseWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RaiseWindowPPC };

void SDL_MaximizeWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_MaximizeWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_MaximizeWindow(___a);
}

STATIC void 
SDL2Gate_SDL_MaximizeWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_MaximizeWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MaximizeWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MaximizeWindowPPC };

void SDL_MinimizeWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_MinimizeWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_MinimizeWindow(___a);
}

STATIC void 
SDL2Gate_SDL_MinimizeWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_MinimizeWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MinimizeWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MinimizeWindowPPC };

void SDL_RestoreWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_RestoreWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_RestoreWindow(___a);
}

STATIC void 
SDL2Gate_SDL_RestoreWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_RestoreWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RestoreWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RestoreWindowPPC };

int SDL_SetWindowFullscreen(SDL_Window * ___a, Uint32 ___b);

int
SDL2Gate_SDL_SetWindowFullscreen(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     Uint32 ___b)
{
  return SDL_SetWindowFullscreen(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetWindowFullscreenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  Uint32 ___b = (Uint32) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowFullscreen(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowFullscreen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowFullscreenPPC };

SDL_Surface* SDL_GetWindowSurface(SDL_Window * ___a);

SDL_Surface*
SDL2Gate_SDL_GetWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowSurface(___a);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_GetWindowSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowSurfacePPC };

int SDL_UpdateWindowSurface(SDL_Window * ___a);

int
SDL2Gate_SDL_UpdateWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_UpdateWindowSurface(___a);
}

STATIC int 
SDL2Gate_SDL_UpdateWindowSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_UpdateWindowSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateWindowSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpdateWindowSurfacePPC };

int SDL_UpdateWindowSurfaceRects(SDL_Window * ___a, const SDL_Rect * ___b, int ___c);

int
SDL2Gate_SDL_UpdateWindowSurfaceRects(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const SDL_Rect * ___b,
     int ___c)
{
  return SDL_UpdateWindowSurfaceRects(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_UpdateWindowSurfaceRectsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_UpdateWindowSurfaceRects(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateWindowSurfaceRects = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpdateWindowSurfaceRectsPPC };

void SDL_SetWindowGrab(SDL_Window * ___a, SDL_bool ___b);

void
SDL2Gate_SDL_SetWindowGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b)
{
  return SDL_SetWindowGrab(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowGrabPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowGrab(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowGrab = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowGrabPPC };

SDL_bool SDL_GetWindowGrab(SDL_Window * ___a);

SDL_bool
SDL2Gate_SDL_GetWindowGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowGrab(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GetWindowGrabPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowGrab(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowGrab = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowGrabPPC };

int SDL_SetWindowBrightness(SDL_Window * ___a, float ___b);

int
SDL2Gate_SDL_SetWindowBrightness(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     float ___b)
{
  return SDL_SetWindowBrightness(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetWindowBrightnessPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowBrightness(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowBrightness = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowBrightnessPPC };

float SDL_GetWindowBrightness(SDL_Window * ___a);

float
SDL2Gate_SDL_GetWindowBrightness(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowBrightness(___a);
}

STATIC float 
SDL2Gate_SDL_GetWindowBrightnessPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowBrightness(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowBrightness = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowBrightnessPPC };

int SDL_SetWindowGammaRamp(SDL_Window * ___a, const Uint16 * ___b, const Uint16 * ___c, const Uint16 * ___d);

int
SDL2Gate_SDL_SetWindowGammaRamp(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const Uint16 * ___b,
     const Uint16 * ___c,
     const Uint16 * ___d)
{
  return SDL_SetWindowGammaRamp(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SetWindowGammaRampPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const Uint16 * ___b = (const Uint16 *) regarray[REG68K_A1/4];
  const Uint16 * ___c = (const Uint16 *) regarray[REG68K_A2/4];
  const Uint16 * ___d = (const Uint16 *) regarray[REG68K_A3/4];

  return _iface->SDL_SetWindowGammaRamp(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowGammaRamp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowGammaRampPPC };

int SDL_GetWindowGammaRamp(SDL_Window * ___a, Uint16 * ___b, Uint16 * ___c, Uint16 * ___d);

int
SDL2Gate_SDL_GetWindowGammaRamp(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     Uint16 * ___b,
     Uint16 * ___c,
     Uint16 * ___d)
{
  return SDL_GetWindowGammaRamp(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GetWindowGammaRampPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  Uint16 * ___b = (Uint16 *) regarray[REG68K_A1/4];
  Uint16 * ___c = (Uint16 *) regarray[REG68K_A2/4];
  Uint16 * ___d = (Uint16 *) regarray[REG68K_A3/4];

  return _iface->SDL_GetWindowGammaRamp(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowGammaRamp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowGammaRampPPC };

void SDL_DestroyWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_DestroyWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_DestroyWindow(___a);
}

STATIC void 
SDL2Gate_SDL_DestroyWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroyWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroyWindowPPC };

SDL_bool SDL_IsScreenSaverEnabled(void);

SDL_bool
SDL2Gate_SDL_IsScreenSaverEnabled(struct SDL2IFace* _iface)
{
  return SDL_IsScreenSaverEnabled();
}

STATIC SDL_bool 
SDL2Gate_SDL_IsScreenSaverEnabledPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_IsScreenSaverEnabled();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsScreenSaverEnabled = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsScreenSaverEnabledPPC };

void SDL_EnableScreenSaver(void);

void
SDL2Gate_SDL_EnableScreenSaver(struct SDL2IFace* _iface)
{
  return SDL_EnableScreenSaver();
}

STATIC void 
SDL2Gate_SDL_EnableScreenSaverPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_EnableScreenSaver();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_EnableScreenSaver = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_EnableScreenSaverPPC };

void SDL_DisableScreenSaver(void);

void
SDL2Gate_SDL_DisableScreenSaver(struct SDL2IFace* _iface)
{
  return SDL_DisableScreenSaver();
}

STATIC void 
SDL2Gate_SDL_DisableScreenSaverPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_DisableScreenSaver();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DisableScreenSaver = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DisableScreenSaverPPC };

int SDL_GL_LoadLibrary(const char * ___a);

int
SDL2Gate_SDL_GL_LoadLibrary(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GL_LoadLibrary(___a);
}

STATIC int 
SDL2Gate_SDL_GL_LoadLibraryPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_LoadLibrary(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_LoadLibrary = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_LoadLibraryPPC };

void* SDL_GL_GetProcAddress(const char * ___a);

void*
SDL2Gate_SDL_GL_GetProcAddress(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GL_GetProcAddress(___a);
}

STATIC void* 
SDL2Gate_SDL_GL_GetProcAddressPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_GetProcAddress(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetProcAddress = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_GetProcAddressPPC };

void SDL_GL_UnloadLibrary(void);

void
SDL2Gate_SDL_GL_UnloadLibrary(struct SDL2IFace* _iface)
{
  return SDL_GL_UnloadLibrary();
}

STATIC void 
SDL2Gate_SDL_GL_UnloadLibraryPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GL_UnloadLibrary();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_UnloadLibrary = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_UnloadLibraryPPC };

SDL_bool SDL_GL_ExtensionSupported(const char * ___a);

SDL_bool
SDL2Gate_SDL_GL_ExtensionSupported(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_GL_ExtensionSupported(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GL_ExtensionSupportedPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_ExtensionSupported(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_ExtensionSupported = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_ExtensionSupportedPPC };

int SDL_GL_SetAttribute(SDL_GLattr ___a, int ___b);

int
SDL2Gate_SDL_GL_SetAttribute(struct SDL2IFace* _iface,
     SDL_GLattr ___a,
     int ___b)
{
  return SDL_GL_SetAttribute(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GL_SetAttributePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GLattr ___a = (SDL_GLattr) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_GL_SetAttribute(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_SetAttribute = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_SetAttributePPC };

int SDL_GL_GetAttribute(SDL_GLattr ___a, int * ___b);

int
SDL2Gate_SDL_GL_GetAttribute(struct SDL2IFace* _iface,
     SDL_GLattr ___a,
     int * ___b)
{
  return SDL_GL_GetAttribute(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GL_GetAttributePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GLattr ___a = (SDL_GLattr) regarray[REG68K_D0/4];
  int * ___b = (int *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_GetAttribute(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetAttribute = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_GetAttributePPC };

SDL_GLContext SDL_GL_CreateContext(SDL_Window * ___a);

SDL_GLContext
SDL2Gate_SDL_GL_CreateContext(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GL_CreateContext(___a);
}

STATIC SDL_GLContext 
SDL2Gate_SDL_GL_CreateContextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_CreateContext(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_CreateContext = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_CreateContextPPC };

int SDL_GL_MakeCurrent(SDL_Window * ___a, SDL_GLContext ___b);

int
SDL2Gate_SDL_GL_MakeCurrent(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_GLContext ___b)
{
  return SDL_GL_MakeCurrent(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GL_MakeCurrentPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_GLContext ___b = (SDL_GLContext) regarray[REG68K_D0/4];

  return _iface->SDL_GL_MakeCurrent(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_MakeCurrent = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_MakeCurrentPPC };

SDL_Window* SDL_GL_GetCurrentWindow(void);

SDL_Window*
SDL2Gate_SDL_GL_GetCurrentWindow(struct SDL2IFace* _iface)
{
  return SDL_GL_GetCurrentWindow();
}

STATIC SDL_Window* 
SDL2Gate_SDL_GL_GetCurrentWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GL_GetCurrentWindow();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetCurrentWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_GetCurrentWindowPPC };

SDL_GLContext SDL_GL_GetCurrentContext(void);

SDL_GLContext
SDL2Gate_SDL_GL_GetCurrentContext(struct SDL2IFace* _iface)
{
  return SDL_GL_GetCurrentContext();
}

STATIC SDL_GLContext 
SDL2Gate_SDL_GL_GetCurrentContextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GL_GetCurrentContext();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetCurrentContext = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_GetCurrentContextPPC };

void SDL_GL_GetDrawableSize(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_GL_GetDrawableSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GL_GetDrawableSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_GL_GetDrawableSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GL_GetDrawableSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetDrawableSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_GetDrawableSizePPC };

int SDL_GL_SetSwapInterval(int ___a);

int
SDL2Gate_SDL_GL_SetSwapInterval(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GL_SetSwapInterval(___a);
}

STATIC int 
SDL2Gate_SDL_GL_SetSwapIntervalPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GL_SetSwapInterval(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_SetSwapInterval = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_SetSwapIntervalPPC };

int SDL_GL_GetSwapInterval(void);

int
SDL2Gate_SDL_GL_GetSwapInterval(struct SDL2IFace* _iface)
{
  return SDL_GL_GetSwapInterval();
}

STATIC int 
SDL2Gate_SDL_GL_GetSwapIntervalPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GL_GetSwapInterval();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_GetSwapInterval = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_GetSwapIntervalPPC };

void SDL_GL_SwapWindow(SDL_Window * ___a);

void
SDL2Gate_SDL_GL_SwapWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GL_SwapWindow(___a);
}

STATIC void 
SDL2Gate_SDL_GL_SwapWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GL_SwapWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_SwapWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_SwapWindowPPC };

void SDL_GL_DeleteContext(SDL_GLContext ___a);

void
SDL2Gate_SDL_GL_DeleteContext(struct SDL2IFace* _iface,
     SDL_GLContext ___a)
{
  return SDL_GL_DeleteContext(___a);
}

STATIC void 
SDL2Gate_SDL_GL_DeleteContextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GLContext ___a = (SDL_GLContext) regarray[REG68K_D0/4];

  return _iface->SDL_GL_DeleteContext(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_DeleteContext = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_DeleteContextPPC };

int SDL_GameControllerAddMappingsFromRW(SDL_RWops * ___a, int ___b);

int
SDL2Gate_SDL_GameControllerAddMappingsFromRW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     int ___b)
{
  return SDL_GameControllerAddMappingsFromRW(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GameControllerAddMappingsFromRWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerAddMappingsFromRW(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerAddMappingsFromRW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerAddMappingsFromRWPPC };

void SDL_GL_ResetAttributes(void);

void
SDL2Gate_SDL_GL_ResetAttributes(struct SDL2IFace* _iface)
{
  return SDL_GL_ResetAttributes();
}

STATIC void 
SDL2Gate_SDL_GL_ResetAttributesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GL_ResetAttributes();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GL_ResetAttributes = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GL_ResetAttributesPPC };

SDL_bool SDL_HasAVX(void);

SDL_bool
SDL2Gate_SDL_HasAVX(struct SDL2IFace* _iface)
{
  return SDL_HasAVX();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasAVXPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasAVX();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasAVX = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasAVXPPC };

SDL_AssertionHandler SDL_GetDefaultAssertionHandler(void);

SDL_AssertionHandler
SDL2Gate_SDL_GetDefaultAssertionHandler(struct SDL2IFace* _iface)
{
  return SDL_GetDefaultAssertionHandler();
}

STATIC SDL_AssertionHandler 
SDL2Gate_SDL_GetDefaultAssertionHandlerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetDefaultAssertionHandler();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDefaultAssertionHandler = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDefaultAssertionHandlerPPC };

SDL_AssertionHandler SDL_GetAssertionHandler(void * * ___a);

SDL_AssertionHandler
SDL2Gate_SDL_GetAssertionHandler(struct SDL2IFace* _iface,
     void * * ___a)
{
  return SDL_GetAssertionHandler(___a);
}

STATIC SDL_AssertionHandler 
SDL2Gate_SDL_GetAssertionHandlerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * * ___a = (void * *) regarray[REG68K_A0/4];

  return _iface->SDL_GetAssertionHandler(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetAssertionHandler = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetAssertionHandlerPPC };

SDL_bool SDL_RenderIsClipEnabled(SDL_Renderer * ___a);

SDL_bool
SDL2Gate_SDL_RenderIsClipEnabled(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderIsClipEnabled(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_RenderIsClipEnabledPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderIsClipEnabled(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderIsClipEnabled = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderIsClipEnabledPPC };

int SDL_WarpMouseGlobal(int ___a, int ___b);

int
SDL2Gate_SDL_WarpMouseGlobal(struct SDL2IFace* _iface,
     int ___a,
     int ___b)
{
  return SDL_WarpMouseGlobal(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_WarpMouseGlobalPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_WarpMouseGlobal(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_WarpMouseGlobal = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_WarpMouseGlobalPPC };

float SDL_sqrtf(float ___a);

float
SDL2Gate_SDL_sqrtf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_sqrtf(___a);
}

STATIC float 
SDL2Gate_SDL_sqrtfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_sqrtf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_sqrtf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_sqrtfPPC };

double SDL_tan(double ___a);

double
SDL2Gate_SDL_tan(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_tan(___a);
}

STATIC double 
SDL2Gate_SDL_tanPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_tan(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_tan = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_tanPPC };

float SDL_tanf(float ___a);

float
SDL2Gate_SDL_tanf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_tanf(___a);
}

STATIC float 
SDL2Gate_SDL_tanfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_tanf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_tanf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_tanfPPC };

int SDL_CaptureMouse(SDL_bool ___a);

int
SDL2Gate_SDL_CaptureMouse(struct SDL2IFace* _iface,
     SDL_bool ___a)
{
  return SDL_CaptureMouse(___a);
}

STATIC int 
SDL2Gate_SDL_CaptureMousePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_bool ___a = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_CaptureMouse(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CaptureMouse = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CaptureMousePPC };

int SDL_SetWindowHitTest(SDL_Window * ___a, SDL_HitTest ___b, void * ___c);

int
SDL2Gate_SDL_SetWindowHitTest(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_HitTest ___b,
     void * ___c)
{
  return SDL_SetWindowHitTest(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_SetWindowHitTestPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_HitTest ___b = (SDL_HitTest) regarray[REG68K_D0/4];
  void * ___c = (void *) regarray[REG68K_A1/4];

  return _iface->SDL_SetWindowHitTest(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowHitTest = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowHitTestPPC };

Uint32 SDL_GetGlobalMouseState(int * ___a, int * ___b);

Uint32
SDL2Gate_SDL_GetGlobalMouseState(struct SDL2IFace* _iface,
     int * ___a,
     int * ___b)
{
  return SDL_GetGlobalMouseState(___a, ___b);
}

STATIC Uint32 
SDL2Gate_SDL_GetGlobalMouseStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int * ___a = (int *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];

  return _iface->SDL_GetGlobalMouseState(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetGlobalMouseState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetGlobalMouseStatePPC };

SDL_bool SDL_HasAVX2(void);

SDL_bool
SDL2Gate_SDL_HasAVX2(struct SDL2IFace* _iface)
{
  return SDL_HasAVX2();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasAVX2PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasAVX2();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasAVX2 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasAVX2PPC };

int SDL_QueueAudio(SDL_AudioDeviceID ___a, const void * ___b, Uint32 ___c);

int
SDL2Gate_SDL_QueueAudio(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a,
     const void * ___b,
     Uint32 ___c)
{
  return SDL_QueueAudio(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_QueueAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];
  const void * ___b = (const void *) regarray[REG68K_A0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_QueueAudio(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_QueueAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_QueueAudioPPC };

Uint32 SDL_GetQueuedAudioSize(SDL_AudioDeviceID ___a);

Uint32
SDL2Gate_SDL_GetQueuedAudioSize(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a)
{
  return SDL_GetQueuedAudioSize(___a);
}

STATIC Uint32 
SDL2Gate_SDL_GetQueuedAudioSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];

  return _iface->SDL_GetQueuedAudioSize(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetQueuedAudioSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetQueuedAudioSizePPC };

void SDL_ClearQueuedAudio(SDL_AudioDeviceID ___a);

void
SDL2Gate_SDL_ClearQueuedAudio(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a)
{
  return SDL_ClearQueuedAudio(___a);
}

STATIC void 
SDL2Gate_SDL_ClearQueuedAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];

  return _iface->SDL_ClearQueuedAudio(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ClearQueuedAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ClearQueuedAudioPPC };

SDL_Window* SDL_GetGrabbedWindow(void);

SDL_Window*
SDL2Gate_SDL_GetGrabbedWindow(struct SDL2IFace* _iface)
{
  return SDL_GetGrabbedWindow();
}

STATIC SDL_Window* 
SDL2Gate_SDL_GetGrabbedWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetGrabbedWindow();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetGrabbedWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetGrabbedWindowPPC };

int SDL_GetDisplayDPI(int ___a, float * ___b, float * ___c, float * ___d);

int
SDL2Gate_SDL_GetDisplayDPI(struct SDL2IFace* _iface,
     int ___a,
     float * ___b,
     float * ___c,
     float * ___d)
{
  return SDL_GetDisplayDPI(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GetDisplayDPIPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  float * ___b = (float *) regarray[REG68K_A0/4];
  float * ___c = (float *) regarray[REG68K_A1/4];
  float * ___d = (float *) regarray[REG68K_A2/4];

  return _iface->SDL_GetDisplayDPI(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayDPI = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDisplayDPIPPC };

SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel(SDL_Joystick * ___a);

SDL_JoystickPowerLevel
SDL2Gate_SDL_JoystickCurrentPowerLevel(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickCurrentPowerLevel(___a);
}

STATIC SDL_JoystickPowerLevel 
SDL2Gate_SDL_JoystickCurrentPowerLevelPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickCurrentPowerLevel(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickCurrentPowerLevel = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickCurrentPowerLevelPPC };

SDL_GameController* SDL_GameControllerFromInstanceID(SDL_JoystickID ___a);

SDL_GameController*
SDL2Gate_SDL_GameControllerFromInstanceID(struct SDL2IFace* _iface,
     SDL_JoystickID ___a)
{
  return SDL_GameControllerFromInstanceID(___a);
}

STATIC SDL_GameController* 
SDL2Gate_SDL_GameControllerFromInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_JoystickID ___a = (SDL_JoystickID) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerFromInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerFromInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerFromInstanceIDPPC };

SDL_Joystick* SDL_JoystickFromInstanceID(SDL_JoystickID ___a);

SDL_Joystick*
SDL2Gate_SDL_JoystickFromInstanceID(struct SDL2IFace* _iface,
     SDL_JoystickID ___a)
{
  return SDL_JoystickFromInstanceID(___a);
}

STATIC SDL_Joystick* 
SDL2Gate_SDL_JoystickFromInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_JoystickID ___a = (SDL_JoystickID) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickFromInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickFromInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickFromInstanceIDPPC };

int SDL_GetDisplayUsableBounds(int ___a, SDL_Rect * ___b);

int
SDL2Gate_SDL_GetDisplayUsableBounds(struct SDL2IFace* _iface,
     int ___a,
     SDL_Rect * ___b)
{
  return SDL_GetDisplayUsableBounds(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetDisplayUsableBoundsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  SDL_Rect * ___b = (SDL_Rect *) regarray[REG68K_A0/4];

  return _iface->SDL_GetDisplayUsableBounds(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayUsableBounds = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDisplayUsableBoundsPPC };

int SDL_GetWindowBordersSize(SDL_Window * ___a, int * ___b, int * ___c, int * ___d, int * ___e);

int
SDL2Gate_SDL_GetWindowBordersSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c,
     int * ___d,
     int * ___e)
{
  return SDL_GetWindowBordersSize(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_GetWindowBordersSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];
  int * ___d = (int *) regarray[REG68K_A3/4];
  int * ___e = (int *) regarray[REG68K_D0/4];

  return _iface->SDL_GetWindowBordersSize(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowBordersSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowBordersSizePPC };

int SDL_SetWindowOpacity(SDL_Window * ___a, float ___b);

int
SDL2Gate_SDL_SetWindowOpacity(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     float ___b)
{
  return SDL_SetWindowOpacity(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetWindowOpacityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowOpacity(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowOpacity = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowOpacityPPC };

int SDL_GetWindowOpacity(SDL_Window * ___a, float * ___b);

int
SDL2Gate_SDL_GetWindowOpacity(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     float * ___b)
{
  return SDL_GetWindowOpacity(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetWindowOpacityPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  float * ___b = (float *) regarray[REG68K_A1/4];

  return _iface->SDL_GetWindowOpacity(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowOpacity = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowOpacityPPC };

int SDL_SetWindowInputFocus(SDL_Window * ___a);

int
SDL2Gate_SDL_SetWindowInputFocus(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_SetWindowInputFocus(___a);
}

STATIC int 
SDL2Gate_SDL_SetWindowInputFocusPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_SetWindowInputFocus(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowInputFocus = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowInputFocusPPC };

int SDL_SetWindowModalFor(SDL_Window * ___a, SDL_Window * ___b);

int
SDL2Gate_SDL_SetWindowModalFor(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_Window * ___b)
{
  return SDL_SetWindowModalFor(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetWindowModalForPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_Window * ___b = (SDL_Window *) regarray[REG68K_A1/4];

  return _iface->SDL_SetWindowModalFor(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowModalFor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowModalForPPC };

int SDL_RenderSetIntegerScale(SDL_Renderer * ___a, SDL_bool ___b);

int
SDL2Gate_SDL_RenderSetIntegerScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_bool ___b)
{
  return SDL_RenderSetIntegerScale(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderSetIntegerScalePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_RenderSetIntegerScale(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetIntegerScale = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderSetIntegerScalePPC };

SDL_bool SDL_RenderGetIntegerScale(SDL_Renderer * ___a);

SDL_bool
SDL2Gate_SDL_RenderGetIntegerScale(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderGetIntegerScale(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_RenderGetIntegerScalePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderGetIntegerScale(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetIntegerScale = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetIntegerScalePPC };

Uint32 SDL_DequeueAudio(SDL_AudioDeviceID ___a, void * ___b, Uint32 ___c);

Uint32
SDL2Gate_SDL_DequeueAudio(struct SDL2IFace* _iface,
     SDL_AudioDeviceID ___a,
     void * ___b,
     Uint32 ___c)
{
  return SDL_DequeueAudio(___a, ___b, ___c);
}

STATIC Uint32 
SDL2Gate_SDL_DequeueAudioPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioDeviceID ___a = (SDL_AudioDeviceID) regarray[REG68K_D0/4];
  void * ___b = (void *) regarray[REG68K_A0/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D1/4];

  return _iface->SDL_DequeueAudio(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DequeueAudio = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DequeueAudioPPC };

void SDL_SetWindowResizable(SDL_Window * ___a, SDL_bool ___b);

void
SDL2Gate_SDL_SetWindowResizable(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b)
{
  return SDL_SetWindowResizable(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowResizablePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowResizable(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowResizable = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowResizablePPC };

SDL_Surface* SDL_CreateRGBSurfaceWithFormat(Uint32 ___a, int ___b, int ___c, int ___d, Uint32 ___e);

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurfaceWithFormat(struct SDL2IFace* _iface,
     Uint32 ___a,
     int ___b,
     int ___c,
     int ___d,
     Uint32 ___e)
{
  return SDL_CreateRGBSurfaceWithFormat(___a, ___b, ___c, ___d, ___e);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_CreateRGBSurfaceWithFormatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  int ___c = (int) regarray[REG68K_D2/4];
  int ___d = (int) regarray[REG68K_D3/4];
  Uint32 ___e = (Uint32) regarray[REG68K_D4/4];

  return _iface->SDL_CreateRGBSurfaceWithFormat(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurfaceWithFormat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateRGBSurfaceWithFormatPPC };

SDL_Surface* SDL_CreateRGBSurfaceWithFormatFrom(void * ___a, int ___b, int ___c, int ___d, int ___e, Uint32 ___f);

SDL_Surface*
SDL2Gate_SDL_CreateRGBSurfaceWithFormatFrom(struct SDL2IFace* _iface,
     void * ___a,
     int ___b,
     int ___c,
     int ___d,
     int ___e,
     Uint32 ___f)
{
  return SDL_CreateRGBSurfaceWithFormatFrom(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_CreateRGBSurfaceWithFormatFromPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  int ___d = (int) regarray[REG68K_D2/4];
  int ___e = (int) regarray[REG68K_D3/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D4/4];

  return _iface->SDL_CreateRGBSurfaceWithFormatFrom(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_CreateRGBSurfaceWithFormatFrom = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_CreateRGBSurfaceWithFormatFromPPC };

SDL_bool SDL_GetHintBoolean(const char * ___a, SDL_bool ___b);

SDL_bool
SDL2Gate_SDL_GetHintBoolean(struct SDL2IFace* _iface,
     const char * ___a,
     SDL_bool ___b)
{
  return SDL_GetHintBoolean(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GetHintBooleanPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_GetHintBoolean(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetHintBoolean = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetHintBooleanPPC };

Uint16 SDL_JoystickGetDeviceVendor(int ___a);

Uint16
SDL2Gate_SDL_JoystickGetDeviceVendor(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickGetDeviceVendor(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetDeviceVendorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetDeviceVendor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceVendor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetDeviceVendorPPC };

Uint16 SDL_JoystickGetDeviceProduct(int ___a);

Uint16
SDL2Gate_SDL_JoystickGetDeviceProduct(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickGetDeviceProduct(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetDeviceProductPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetDeviceProduct(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceProduct = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetDeviceProductPPC };

Uint16 SDL_JoystickGetDeviceProductVersion(int ___a);

Uint16
SDL2Gate_SDL_JoystickGetDeviceProductVersion(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickGetDeviceProductVersion(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetDeviceProductVersionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetDeviceProductVersion(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceProductVersion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetDeviceProductVersionPPC };

Uint16 SDL_JoystickGetVendor(SDL_Joystick * ___a);

Uint16
SDL2Gate_SDL_JoystickGetVendor(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetVendor(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetVendorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetVendor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetVendor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetVendorPPC };

Uint16 SDL_JoystickGetProduct(SDL_Joystick * ___a);

Uint16
SDL2Gate_SDL_JoystickGetProduct(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetProduct(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetProductPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetProduct(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetProduct = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetProductPPC };

Uint16 SDL_JoystickGetProductVersion(SDL_Joystick * ___a);

Uint16
SDL2Gate_SDL_JoystickGetProductVersion(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetProductVersion(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetProductVersionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetProductVersion(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetProductVersion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetProductVersionPPC };

Uint16 SDL_GameControllerGetVendor(SDL_GameController * ___a);

Uint16
SDL2Gate_SDL_GameControllerGetVendor(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetVendor(___a);
}

STATIC Uint16 
SDL2Gate_SDL_GameControllerGetVendorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetVendor(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetVendor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetVendorPPC };

Uint16 SDL_GameControllerGetProduct(SDL_GameController * ___a);

Uint16
SDL2Gate_SDL_GameControllerGetProduct(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetProduct(___a);
}

STATIC Uint16 
SDL2Gate_SDL_GameControllerGetProductPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetProduct(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetProduct = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetProductPPC };

Uint16 SDL_GameControllerGetProductVersion(SDL_GameController * ___a);

Uint16
SDL2Gate_SDL_GameControllerGetProductVersion(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetProductVersion(___a);
}

STATIC Uint16 
SDL2Gate_SDL_GameControllerGetProductVersionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetProductVersion(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetProductVersion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetProductVersionPPC };

SDL_bool SDL_HasNEON(void);

SDL_bool
SDL2Gate_SDL_HasNEON(struct SDL2IFace* _iface)
{
  return SDL_HasNEON();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasNEONPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasNEON();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasNEON = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasNEONPPC };

int SDL_GameControllerNumMappings(void);

int
SDL2Gate_SDL_GameControllerNumMappings(struct SDL2IFace* _iface)
{
  return SDL_GameControllerNumMappings();
}

STATIC int 
SDL2Gate_SDL_GameControllerNumMappingsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GameControllerNumMappings();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerNumMappings = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerNumMappingsPPC };

char* SDL_GameControllerMappingForIndex(int ___a);

char*
SDL2Gate_SDL_GameControllerMappingForIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerMappingForIndex(___a);
}

STATIC char* 
SDL2Gate_SDL_GameControllerMappingForIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerMappingForIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerMappingForIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerMappingForIndexPPC };

SDL_bool SDL_JoystickGetAxisInitialState(SDL_Joystick * ___a, int ___b, Sint16 * ___c);

SDL_bool
SDL2Gate_SDL_JoystickGetAxisInitialState(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Sint16 * ___c)
{
  return SDL_JoystickGetAxisInitialState(___a, ___b, ___c);
}

STATIC SDL_bool 
SDL2Gate_SDL_JoystickGetAxisInitialStatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Sint16 * ___c = (Sint16 *) regarray[REG68K_A1/4];

  return _iface->SDL_JoystickGetAxisInitialState(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetAxisInitialState = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetAxisInitialStatePPC };

SDL_JoystickType SDL_JoystickGetDeviceType(int ___a);

SDL_JoystickType
SDL2Gate_SDL_JoystickGetDeviceType(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickGetDeviceType(___a);
}

STATIC SDL_JoystickType 
SDL2Gate_SDL_JoystickGetDeviceTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetDeviceType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetDeviceTypePPC };

SDL_JoystickType SDL_JoystickGetType(SDL_Joystick * ___a);

SDL_JoystickType
SDL2Gate_SDL_JoystickGetType(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetType(___a);
}

STATIC SDL_JoystickType 
SDL2Gate_SDL_JoystickGetTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetTypePPC };

void SDL_MemoryBarrierReleaseFunction(void);

void
SDL2Gate_SDL_MemoryBarrierReleaseFunction(struct SDL2IFace* _iface)
{
  return SDL_MemoryBarrierReleaseFunction();
}

STATIC void 
SDL2Gate_SDL_MemoryBarrierReleaseFunctionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_MemoryBarrierReleaseFunction();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MemoryBarrierReleaseFunction = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MemoryBarrierReleaseFunctionPPC };

void SDL_MemoryBarrierAcquireFunction(void);

void
SDL2Gate_SDL_MemoryBarrierAcquireFunction(struct SDL2IFace* _iface)
{
  return SDL_MemoryBarrierAcquireFunction();
}

STATIC void 
SDL2Gate_SDL_MemoryBarrierAcquireFunctionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_MemoryBarrierAcquireFunction();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_MemoryBarrierAcquireFunction = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_MemoryBarrierAcquireFunctionPPC };

SDL_JoystickID SDL_JoystickGetDeviceInstanceID(int ___a);

SDL_JoystickID
SDL2Gate_SDL_JoystickGetDeviceInstanceID(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickGetDeviceInstanceID(___a);
}

STATIC SDL_JoystickID 
SDL2Gate_SDL_JoystickGetDeviceInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetDeviceInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDeviceInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetDeviceInstanceIDPPC };

size_t SDL_utf8strlen(const char * ___a);

size_t
SDL2Gate_SDL_utf8strlen(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_utf8strlen(___a);
}

STATIC size_t 
SDL2Gate_SDL_utf8strlenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_utf8strlen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_utf8strlen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_utf8strlenPPC };

void* SDL_LoadFile_RW(SDL_RWops * ___a, size_t * ___b, int ___c);

void*
SDL2Gate_SDL_LoadFile_RW(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     size_t * ___b,
     int ___c)
{
  return SDL_LoadFile_RW(___a, ___b, ___c);
}

STATIC void* 
SDL2Gate_SDL_LoadFile_RWPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  size_t * ___b = (size_t *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_LoadFile_RW(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadFile_RW = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadFile_RWPPC };

int SDL_wcscmp(const wchar_t * ___a, const wchar_t * ___b);

int
SDL2Gate_SDL_wcscmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b)
{
  return SDL_wcscmp(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_wcscmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];

  return _iface->SDL_wcscmp(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcscmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcscmpPPC };

SDL_BlendMode SDL_ComposeCustomBlendMode(SDL_BlendFactor ___a, SDL_BlendFactor ___b, SDL_BlendOperation ___c, SDL_BlendFactor ___d, SDL_BlendFactor ___e, SDL_BlendOperation ___f);

SDL_BlendMode
SDL2Gate_SDL_ComposeCustomBlendMode(struct SDL2IFace* _iface,
     SDL_BlendFactor ___a,
     SDL_BlendFactor ___b,
     SDL_BlendOperation ___c,
     SDL_BlendFactor ___d,
     SDL_BlendFactor ___e,
     SDL_BlendOperation ___f)
{
  return SDL_ComposeCustomBlendMode(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_BlendMode 
SDL2Gate_SDL_ComposeCustomBlendModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_BlendFactor ___a = (SDL_BlendFactor) regarray[REG68K_D0/4];
  SDL_BlendFactor ___b = (SDL_BlendFactor) regarray[REG68K_D1/4];
  SDL_BlendOperation ___c = (SDL_BlendOperation) regarray[REG68K_D2/4];
  SDL_BlendFactor ___d = (SDL_BlendFactor) regarray[REG68K_D3/4];
  SDL_BlendFactor ___e = (SDL_BlendFactor) regarray[REG68K_D4/4];
  SDL_BlendOperation ___f = (SDL_BlendOperation) regarray[REG68K_D5/4];

  return _iface->SDL_ComposeCustomBlendMode(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ComposeCustomBlendMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ComposeCustomBlendModePPC };

SDL_Surface* SDL_DuplicateSurface(SDL_Surface * ___a);

SDL_Surface*
SDL2Gate_SDL_DuplicateSurface(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_DuplicateSurface(___a);
}

STATIC SDL_Surface* 
SDL2Gate_SDL_DuplicateSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_DuplicateSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DuplicateSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DuplicateSurfacePPC };

void SDL_LockJoysticks(void);

void
SDL2Gate_SDL_LockJoysticks(struct SDL2IFace* _iface)
{
  return SDL_LockJoysticks();
}

STATIC void 
SDL2Gate_SDL_LockJoysticksPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_LockJoysticks();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockJoysticks = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockJoysticksPPC };

void SDL_UnlockJoysticks(void);

void
SDL2Gate_SDL_UnlockJoysticks(struct SDL2IFace* _iface)
{
  return SDL_UnlockJoysticks();
}

STATIC void 
SDL2Gate_SDL_UnlockJoysticksPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_UnlockJoysticks();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockJoysticks = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockJoysticksPPC };

void SDL_GetMemoryFunctions(SDL_malloc_func * ___a, SDL_calloc_func * ___b, SDL_realloc_func * ___c, SDL_free_func * ___d);

void
SDL2Gate_SDL_GetMemoryFunctions(struct SDL2IFace* _iface,
     SDL_malloc_func * ___a,
     SDL_calloc_func * ___b,
     SDL_realloc_func * ___c,
     SDL_free_func * ___d)
{
  return SDL_GetMemoryFunctions(___a, ___b, ___c, ___d);
}

STATIC void 
SDL2Gate_SDL_GetMemoryFunctionsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_malloc_func * ___a = (SDL_malloc_func *) regarray[REG68K_A0/4];
  SDL_calloc_func * ___b = (SDL_calloc_func *) regarray[REG68K_A1/4];
  SDL_realloc_func * ___c = (SDL_realloc_func *) regarray[REG68K_A2/4];
  SDL_free_func * ___d = (SDL_free_func *) regarray[REG68K_A3/4];

  return _iface->SDL_GetMemoryFunctions(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetMemoryFunctions = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetMemoryFunctionsPPC };

int SDL_SetMemoryFunctions(SDL_malloc_func ___a, SDL_calloc_func ___b, SDL_realloc_func ___c, SDL_free_func ___d);

int
SDL2Gate_SDL_SetMemoryFunctions(struct SDL2IFace* _iface,
     SDL_malloc_func ___a,
     SDL_calloc_func ___b,
     SDL_realloc_func ___c,
     SDL_free_func ___d)
{
  return SDL_SetMemoryFunctions(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SetMemoryFunctionsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_malloc_func ___a = (SDL_malloc_func) regarray[REG68K_D0/4];
  SDL_calloc_func ___b = (SDL_calloc_func) regarray[REG68K_D1/4];
  SDL_realloc_func ___c = (SDL_realloc_func) regarray[REG68K_D2/4];
  SDL_free_func ___d = (SDL_free_func) regarray[REG68K_D3/4];

  return _iface->SDL_SetMemoryFunctions(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetMemoryFunctions = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetMemoryFunctionsPPC };

int SDL_GetNumAllocations(void);

int
SDL2Gate_SDL_GetNumAllocations(struct SDL2IFace* _iface)
{
  return SDL_GetNumAllocations();
}

STATIC int 
SDL2Gate_SDL_GetNumAllocationsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetNumAllocations();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetNumAllocations = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetNumAllocationsPPC };

SDL_AudioStream* SDL_NewAudioStream(const SDL_AudioFormat ___a, const Uint8 ___b, const int ___c, const SDL_AudioFormat ___d, const Uint8 ___e, const int ___f);

SDL_AudioStream*
SDL2Gate_SDL_NewAudioStream(struct SDL2IFace* _iface,
     const SDL_AudioFormat ___a,
     const Uint8 ___b,
     const int ___c,
     const SDL_AudioFormat ___d,
     const Uint8 ___e,
     const int ___f)
{
  return SDL_NewAudioStream(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC SDL_AudioStream* 
SDL2Gate_SDL_NewAudioStreamPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_AudioFormat ___a = (const SDL_AudioFormat) regarray[REG68K_D0/4];
  const Uint8 ___b = (const Uint8) regarray[REG68K_D1/4];
  const int ___c = (const int) regarray[REG68K_D2/4];
  const SDL_AudioFormat ___d = (const SDL_AudioFormat) regarray[REG68K_D3/4];
  const Uint8 ___e = (const Uint8) regarray[REG68K_D4/4];
  const int ___f = (const int) regarray[REG68K_D5/4];

  return _iface->SDL_NewAudioStream(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_NewAudioStream = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_NewAudioStreamPPC };

int SDL_AudioStreamPut(SDL_AudioStream * ___a, const void * ___b, int ___c);

int
SDL2Gate_SDL_AudioStreamPut(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a,
     const void * ___b,
     int ___c)
{
  return SDL_AudioStreamPut(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_AudioStreamPutPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioStream * ___a = (SDL_AudioStream *) regarray[REG68K_A0/4];
  const void * ___b = (const void *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_AudioStreamPut(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamPut = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioStreamPutPPC };

int SDL_AudioStreamGet(SDL_AudioStream * ___a, void * ___b, int ___c);

int
SDL2Gate_SDL_AudioStreamGet(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a,
     void * ___b,
     int ___c)
{
  return SDL_AudioStreamGet(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_AudioStreamGetPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioStream * ___a = (SDL_AudioStream *) regarray[REG68K_A0/4];
  void * ___b = (void *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_AudioStreamGet(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamGet = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioStreamGetPPC };

void SDL_AudioStreamClear(SDL_AudioStream * ___a);

void
SDL2Gate_SDL_AudioStreamClear(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a)
{
  return SDL_AudioStreamClear(___a);
}

STATIC void 
SDL2Gate_SDL_AudioStreamClearPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioStream * ___a = (SDL_AudioStream *) regarray[REG68K_A0/4];

  return _iface->SDL_AudioStreamClear(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamClear = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioStreamClearPPC };

int SDL_AudioStreamAvailable(SDL_AudioStream * ___a);

int
SDL2Gate_SDL_AudioStreamAvailable(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a)
{
  return SDL_AudioStreamAvailable(___a);
}

STATIC int 
SDL2Gate_SDL_AudioStreamAvailablePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioStream * ___a = (SDL_AudioStream *) regarray[REG68K_A0/4];

  return _iface->SDL_AudioStreamAvailable(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamAvailable = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioStreamAvailablePPC };

void SDL_FreeAudioStream(SDL_AudioStream * ___a);

void
SDL2Gate_SDL_FreeAudioStream(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a)
{
  return SDL_FreeAudioStream(___a);
}

STATIC void 
SDL2Gate_SDL_FreeAudioStreamPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioStream * ___a = (SDL_AudioStream *) regarray[REG68K_A0/4];

  return _iface->SDL_FreeAudioStream(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FreeAudioStream = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FreeAudioStreamPPC };

int SDL_AudioStreamFlush(SDL_AudioStream * ___a);

int
SDL2Gate_SDL_AudioStreamFlush(struct SDL2IFace* _iface,
     SDL_AudioStream * ___a)
{
  return SDL_AudioStreamFlush(___a);
}

STATIC int 
SDL2Gate_SDL_AudioStreamFlushPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_AudioStream * ___a = (SDL_AudioStream *) regarray[REG68K_A0/4];

  return _iface->SDL_AudioStreamFlush(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_AudioStreamFlush = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_AudioStreamFlushPPC };

float SDL_acosf(float ___a);

float
SDL2Gate_SDL_acosf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_acosf(___a);
}

STATIC float 
SDL2Gate_SDL_acosfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_acosf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_acosf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_acosfPPC };

float SDL_asinf(float ___a);

float
SDL2Gate_SDL_asinf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_asinf(___a);
}

STATIC float 
SDL2Gate_SDL_asinfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_asinf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_asinf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_asinfPPC };

float SDL_atanf(float ___a);

float
SDL2Gate_SDL_atanf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_atanf(___a);
}

STATIC float 
SDL2Gate_SDL_atanfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_atanf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_atanf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_atanfPPC };

float SDL_atan2f(float ___a, float ___b);

float
SDL2Gate_SDL_atan2f(struct SDL2IFace* _iface,
     float ___a,
     float ___b)
{
  return SDL_atan2f(___a, ___b);
}

STATIC float 
SDL2Gate_SDL_atan2fPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];
  float ___b = (float) regarray[REG68K_D1/4];

  return _iface->SDL_atan2f(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_atan2f = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_atan2fPPC };

float SDL_ceilf(float ___a);

float
SDL2Gate_SDL_ceilf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_ceilf(___a);
}

STATIC float 
SDL2Gate_SDL_ceilfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_ceilf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ceilf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ceilfPPC };

float SDL_copysignf(float ___a, float ___b);

float
SDL2Gate_SDL_copysignf(struct SDL2IFace* _iface,
     float ___a,
     float ___b)
{
  return SDL_copysignf(___a, ___b);
}

STATIC float 
SDL2Gate_SDL_copysignfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];
  float ___b = (float) regarray[REG68K_D1/4];

  return _iface->SDL_copysignf(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_copysignf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_copysignfPPC };

float SDL_fabsf(float ___a);

float
SDL2Gate_SDL_fabsf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_fabsf(___a);
}

STATIC float 
SDL2Gate_SDL_fabsfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_fabsf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_fabsf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_fabsfPPC };

float SDL_floorf(float ___a);

float
SDL2Gate_SDL_floorf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_floorf(___a);
}

STATIC float 
SDL2Gate_SDL_floorfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_floorf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_floorf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_floorfPPC };

float SDL_logf(float ___a);

float
SDL2Gate_SDL_logf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_logf(___a);
}

STATIC float 
SDL2Gate_SDL_logfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_logf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_logf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_logfPPC };

float SDL_powf(float ___a, float ___b);

float
SDL2Gate_SDL_powf(struct SDL2IFace* _iface,
     float ___a,
     float ___b)
{
  return SDL_powf(___a, ___b);
}

STATIC float 
SDL2Gate_SDL_powfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];
  float ___b = (float) regarray[REG68K_D1/4];

  return _iface->SDL_powf(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_powf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_powfPPC };

float SDL_scalbnf(float ___a, int ___b);

float
SDL2Gate_SDL_scalbnf(struct SDL2IFace* _iface,
     float ___a,
     int ___b)
{
  return SDL_scalbnf(___a, ___b);
}

STATIC float 
SDL2Gate_SDL_scalbnfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_scalbnf(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_scalbnf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_scalbnfPPC };

double SDL_fmod(double ___a, double ___b);

double
SDL2Gate_SDL_fmod(struct SDL2IFace* _iface,
     double ___a,
     double ___b)
{
  return SDL_fmod(___a, ___b);
}

STATIC double 
SDL2Gate_SDL_fmodPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];
  double ___b = (double) regarray[REG68K_D2/4];

  return _iface->SDL_fmod(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_fmod = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_fmodPPC };

float SDL_fmodf(float ___a, float ___b);

float
SDL2Gate_SDL_fmodf(struct SDL2IFace* _iface,
     float ___a,
     float ___b)
{
  return SDL_fmodf(___a, ___b);
}

STATIC float 
SDL2Gate_SDL_fmodfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];
  float ___b = (float) regarray[REG68K_D1/4];

  return _iface->SDL_fmodf(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_fmodf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_fmodfPPC };

void SDL_SetYUVConversionMode(SDL_YUV_CONVERSION_MODE ___a);

void
SDL2Gate_SDL_SetYUVConversionMode(struct SDL2IFace* _iface,
     SDL_YUV_CONVERSION_MODE ___a)
{
  return SDL_SetYUVConversionMode(___a);
}

STATIC void 
SDL2Gate_SDL_SetYUVConversionModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_YUV_CONVERSION_MODE ___a = (SDL_YUV_CONVERSION_MODE) regarray[REG68K_D0/4];

  return _iface->SDL_SetYUVConversionMode(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetYUVConversionMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetYUVConversionModePPC };

SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionMode(void);

SDL_YUV_CONVERSION_MODE
SDL2Gate_SDL_GetYUVConversionMode(struct SDL2IFace* _iface)
{
  return SDL_GetYUVConversionMode();
}

STATIC SDL_YUV_CONVERSION_MODE 
SDL2Gate_SDL_GetYUVConversionModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetYUVConversionMode();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetYUVConversionMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetYUVConversionModePPC };

SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionModeForResolution(int ___a, int ___b);

SDL_YUV_CONVERSION_MODE
SDL2Gate_SDL_GetYUVConversionModeForResolution(struct SDL2IFace* _iface,
     int ___a,
     int ___b)
{
  return SDL_GetYUVConversionModeForResolution(___a, ___b);
}

STATIC SDL_YUV_CONVERSION_MODE 
SDL2Gate_SDL_GetYUVConversionModeForResolutionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];

  return _iface->SDL_GetYUVConversionModeForResolution(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetYUVConversionModeForResolution = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetYUVConversionModeForResolutionPPC };

void* SDL_RenderGetMetalLayer(SDL_Renderer * ___a);

void*
SDL2Gate_SDL_RenderGetMetalLayer(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderGetMetalLayer(___a);
}

STATIC void* 
SDL2Gate_SDL_RenderGetMetalLayerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderGetMetalLayer(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetMetalLayer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetMetalLayerPPC };

void* SDL_RenderGetMetalCommandEncoder(SDL_Renderer * ___a);

void*
SDL2Gate_SDL_RenderGetMetalCommandEncoder(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderGetMetalCommandEncoder(___a);
}

STATIC void* 
SDL2Gate_SDL_RenderGetMetalCommandEncoderPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderGetMetalCommandEncoder(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetMetalCommandEncoder = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetMetalCommandEncoderPPC };

double SDL_log10(double ___a);

double
SDL2Gate_SDL_log10(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_log10(___a);
}

STATIC double 
SDL2Gate_SDL_log10PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_log10(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_log10 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_log10PPC };

float SDL_log10f(float ___a);

float
SDL2Gate_SDL_log10f(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_log10f(___a);
}

STATIC float 
SDL2Gate_SDL_log10fPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_log10f(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_log10f = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_log10fPPC };

char* SDL_GameControllerMappingForDeviceIndex(int ___a);

char*
SDL2Gate_SDL_GameControllerMappingForDeviceIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerMappingForDeviceIndex(___a);
}

STATIC char* 
SDL2Gate_SDL_GameControllerMappingForDeviceIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerMappingForDeviceIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerMappingForDeviceIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerMappingForDeviceIndexPPC };

SDL_bool SDL_HasAVX512F(void);

SDL_bool
SDL2Gate_SDL_HasAVX512F(struct SDL2IFace* _iface)
{
  return SDL_HasAVX512F();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasAVX512FPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasAVX512F();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasAVX512F = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasAVX512FPPC };

double SDL_exp(double ___a);

double
SDL2Gate_SDL_exp(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_exp(___a);
}

STATIC double 
SDL2Gate_SDL_expPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_exp(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_exp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_expPPC };

float SDL_expf(float ___a);

float
SDL2Gate_SDL_expf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_expf(___a);
}

STATIC float 
SDL2Gate_SDL_expfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_expf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_expf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_expfPPC };

wchar_t* SDL_wcsdup(const wchar_t * ___a);

wchar_t*
SDL2Gate_SDL_wcsdup(struct SDL2IFace* _iface,
     const wchar_t * ___a)
{
  return SDL_wcsdup(___a);
}

STATIC wchar_t* 
SDL2Gate_SDL_wcsdupPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];

  return _iface->SDL_wcsdup(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcsdup = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcsdupPPC };

int SDL_GameControllerRumble(SDL_GameController * ___a, Uint16 ___b, Uint16 ___c, Uint32 ___d);

int
SDL2Gate_SDL_GameControllerRumble(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d)
{
  return SDL_GameControllerRumble(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GameControllerRumblePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  Uint16 ___b = (Uint16) regarray[REG68K_D0/4];
  Uint16 ___c = (Uint16) regarray[REG68K_D1/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D2/4];

  return _iface->SDL_GameControllerRumble(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerRumble = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerRumblePPC };

int SDL_JoystickRumble(SDL_Joystick * ___a, Uint16 ___b, Uint16 ___c, Uint32 ___d);

int
SDL2Gate_SDL_JoystickRumble(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d)
{
  return SDL_JoystickRumble(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_JoystickRumblePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  Uint16 ___b = (Uint16) regarray[REG68K_D0/4];
  Uint16 ___c = (Uint16) regarray[REG68K_D1/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D2/4];

  return _iface->SDL_JoystickRumble(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickRumble = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickRumblePPC };

int SDL_NumSensors(void);

int
SDL2Gate_SDL_NumSensors(struct SDL2IFace* _iface)
{
  return SDL_NumSensors();
}

STATIC int 
SDL2Gate_SDL_NumSensorsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_NumSensors();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_NumSensors = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_NumSensorsPPC };

const char* SDL_SensorGetDeviceName(int ___a);

const char*
SDL2Gate_SDL_SensorGetDeviceName(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_SensorGetDeviceName(___a);
}

STATIC const char* 
SDL2Gate_SDL_SensorGetDeviceNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorGetDeviceName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetDeviceNamePPC };

SDL_SensorType SDL_SensorGetDeviceType(int ___a);

SDL_SensorType
SDL2Gate_SDL_SensorGetDeviceType(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_SensorGetDeviceType(___a);
}

STATIC SDL_SensorType 
SDL2Gate_SDL_SensorGetDeviceTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorGetDeviceType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetDeviceTypePPC };

int SDL_SensorGetDeviceNonPortableType(int ___a);

int
SDL2Gate_SDL_SensorGetDeviceNonPortableType(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_SensorGetDeviceNonPortableType(___a);
}

STATIC int 
SDL2Gate_SDL_SensorGetDeviceNonPortableTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorGetDeviceNonPortableType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceNonPortableType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetDeviceNonPortableTypePPC };

SDL_SensorID SDL_SensorGetDeviceInstanceID(int ___a);

SDL_SensorID
SDL2Gate_SDL_SensorGetDeviceInstanceID(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_SensorGetDeviceInstanceID(___a);
}

STATIC SDL_SensorID 
SDL2Gate_SDL_SensorGetDeviceInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorGetDeviceInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDeviceInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetDeviceInstanceIDPPC };

SDL_Sensor* SDL_SensorOpen(int ___a);

SDL_Sensor*
SDL2Gate_SDL_SensorOpen(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_SensorOpen(___a);
}

STATIC SDL_Sensor* 
SDL2Gate_SDL_SensorOpenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorOpen(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorOpen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorOpenPPC };

SDL_Sensor* SDL_SensorFromInstanceID(SDL_SensorID ___a);

SDL_Sensor*
SDL2Gate_SDL_SensorFromInstanceID(struct SDL2IFace* _iface,
     SDL_SensorID ___a)
{
  return SDL_SensorFromInstanceID(___a);
}

STATIC SDL_Sensor* 
SDL2Gate_SDL_SensorFromInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_SensorID ___a = (SDL_SensorID) regarray[REG68K_D0/4];

  return _iface->SDL_SensorFromInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorFromInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorFromInstanceIDPPC };

const char* SDL_SensorGetName(SDL_Sensor * ___a);

const char*
SDL2Gate_SDL_SensorGetName(struct SDL2IFace* _iface,
     SDL_Sensor * ___a)
{
  return SDL_SensorGetName(___a);
}

STATIC const char* 
SDL2Gate_SDL_SensorGetNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];

  return _iface->SDL_SensorGetName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetNamePPC };

SDL_SensorType SDL_SensorGetType(SDL_Sensor * ___a);

SDL_SensorType
SDL2Gate_SDL_SensorGetType(struct SDL2IFace* _iface,
     SDL_Sensor * ___a)
{
  return SDL_SensorGetType(___a);
}

STATIC SDL_SensorType 
SDL2Gate_SDL_SensorGetTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];

  return _iface->SDL_SensorGetType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetTypePPC };

int SDL_SensorGetNonPortableType(SDL_Sensor * ___a);

int
SDL2Gate_SDL_SensorGetNonPortableType(struct SDL2IFace* _iface,
     SDL_Sensor * ___a)
{
  return SDL_SensorGetNonPortableType(___a);
}

STATIC int 
SDL2Gate_SDL_SensorGetNonPortableTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];

  return _iface->SDL_SensorGetNonPortableType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetNonPortableType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetNonPortableTypePPC };

SDL_SensorID SDL_SensorGetInstanceID(SDL_Sensor * ___a);

SDL_SensorID
SDL2Gate_SDL_SensorGetInstanceID(struct SDL2IFace* _iface,
     SDL_Sensor * ___a)
{
  return SDL_SensorGetInstanceID(___a);
}

STATIC SDL_SensorID 
SDL2Gate_SDL_SensorGetInstanceIDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];

  return _iface->SDL_SensorGetInstanceID(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetInstanceID = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetInstanceIDPPC };

int SDL_SensorGetData(SDL_Sensor * ___a, float * ___b, int ___c);

int
SDL2Gate_SDL_SensorGetData(struct SDL2IFace* _iface,
     SDL_Sensor * ___a,
     float * ___b,
     int ___c)
{
  return SDL_SensorGetData(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_SensorGetDataPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];
  float * ___b = (float *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorGetData(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetData = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetDataPPC };

void SDL_SensorClose(SDL_Sensor * ___a);

void
SDL2Gate_SDL_SensorClose(struct SDL2IFace* _iface,
     SDL_Sensor * ___a)
{
  return SDL_SensorClose(___a);
}

STATIC void 
SDL2Gate_SDL_SensorClosePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];

  return _iface->SDL_SensorClose(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorClose = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorClosePPC };

void SDL_SensorUpdate(void);

void
SDL2Gate_SDL_SensorUpdate(struct SDL2IFace* _iface)
{
  return SDL_SensorUpdate();
}

STATIC void 
SDL2Gate_SDL_SensorUpdatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_SensorUpdate();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorUpdate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorUpdatePPC };

SDL_bool SDL_IsTablet(void);

SDL_bool
SDL2Gate_SDL_IsTablet(struct SDL2IFace* _iface)
{
  return SDL_IsTablet();
}

STATIC SDL_bool 
SDL2Gate_SDL_IsTabletPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_IsTablet();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsTablet = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsTabletPPC };

SDL_DisplayOrientation SDL_GetDisplayOrientation(int ___a);

SDL_DisplayOrientation
SDL2Gate_SDL_GetDisplayOrientation(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetDisplayOrientation(___a);
}

STATIC SDL_DisplayOrientation 
SDL2Gate_SDL_GetDisplayOrientationPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetDisplayOrientation(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDisplayOrientation = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDisplayOrientationPPC };

SDL_bool SDL_HasColorKey(SDL_Surface * ___a);

SDL_bool
SDL2Gate_SDL_HasColorKey(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_HasColorKey(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasColorKeyPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_HasColorKey(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasColorKey = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasColorKeyPPC };

int SDL_JoystickGetDevicePlayerIndex(int ___a);

int
SDL2Gate_SDL_JoystickGetDevicePlayerIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickGetDevicePlayerIndex(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickGetDevicePlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickGetDevicePlayerIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetDevicePlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetDevicePlayerIndexPPC };

int SDL_JoystickGetPlayerIndex(SDL_Joystick * ___a);

int
SDL2Gate_SDL_JoystickGetPlayerIndex(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetPlayerIndex(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickGetPlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetPlayerIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetPlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetPlayerIndexPPC };

int SDL_GameControllerGetPlayerIndex(SDL_GameController * ___a);

int
SDL2Gate_SDL_GameControllerGetPlayerIndex(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetPlayerIndex(___a);
}

STATIC int 
SDL2Gate_SDL_GameControllerGetPlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetPlayerIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetPlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetPlayerIndexPPC };

int SDL_RenderFlush(SDL_Renderer * ___a);

int
SDL2Gate_SDL_RenderFlush(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderFlush(___a);
}

STATIC int 
SDL2Gate_SDL_RenderFlushPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderFlush(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFlush = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderFlushPPC };

int SDL_RenderDrawPointF(SDL_Renderer * ___a, float ___b, float ___c);

int
SDL2Gate_SDL_RenderDrawPointF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c)
{
  return SDL_RenderDrawPointF(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawPointFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];
  float ___c = (float) regarray[REG68K_D1/4];

  return _iface->SDL_RenderDrawPointF(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPointF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawPointFPPC };

int SDL_RenderDrawPointsF(SDL_Renderer * ___a, const SDL_FPoint * ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawPointsF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FPoint * ___b,
     int ___c)
{
  return SDL_RenderDrawPointsF(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawPointsFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_FPoint * ___b = (const SDL_FPoint *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderDrawPointsF(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawPointsF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawPointsFPPC };

int SDL_RenderDrawLineF(SDL_Renderer * ___a, float ___b, float ___c, float ___d, float ___e);

int
SDL2Gate_SDL_RenderDrawLineF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c,
     float ___d,
     float ___e)
{
  return SDL_RenderDrawLineF(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_RenderDrawLineFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];
  float ___c = (float) regarray[REG68K_D1/4];
  float ___d = (float) regarray[REG68K_D2/4];
  float ___e = (float) regarray[REG68K_D3/4];

  return _iface->SDL_RenderDrawLineF(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLineF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawLineFPPC };

int SDL_RenderDrawLinesF(SDL_Renderer * ___a, const SDL_FPoint * ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawLinesF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FPoint * ___b,
     int ___c)
{
  return SDL_RenderDrawLinesF(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawLinesFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_FPoint * ___b = (const SDL_FPoint *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderDrawLinesF(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawLinesF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawLinesFPPC };

int SDL_RenderDrawRectF(SDL_Renderer * ___a, const SDL_FRect * ___b);

int
SDL2Gate_SDL_RenderDrawRectF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b)
{
  return SDL_RenderDrawRectF(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderDrawRectFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderDrawRectF(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRectF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawRectFPPC };

int SDL_RenderDrawRectsF(SDL_Renderer * ___a, const SDL_FRect * ___b, int ___c);

int
SDL2Gate_SDL_RenderDrawRectsF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b,
     int ___c)
{
  return SDL_RenderDrawRectsF(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderDrawRectsFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderDrawRectsF(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderDrawRectsF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderDrawRectsFPPC };

int SDL_RenderFillRectF(SDL_Renderer * ___a, const SDL_FRect * ___b);

int
SDL2Gate_SDL_RenderFillRectF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b)
{
  return SDL_RenderFillRectF(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderFillRectFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];

  return _iface->SDL_RenderFillRectF(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRectF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderFillRectFPPC };

int SDL_RenderFillRectsF(SDL_Renderer * ___a, const SDL_FRect * ___b, int ___c);

int
SDL2Gate_SDL_RenderFillRectsF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     const SDL_FRect * ___b,
     int ___c)
{
  return SDL_RenderFillRectsF(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_RenderFillRectsFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderFillRectsF(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderFillRectsF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderFillRectsFPPC };

int SDL_RenderCopyF(SDL_Renderer * ___a, SDL_Texture * ___b, const SDL_Rect * ___c, const SDL_FRect * ___d);

int
SDL2Gate_SDL_RenderCopyF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_FRect * ___d)
{
  return SDL_RenderCopyF(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_RenderCopyFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Texture * ___b = (SDL_Texture *) regarray[REG68K_A1/4];
  const SDL_Rect * ___c = (const SDL_Rect *) regarray[REG68K_A2/4];
  const SDL_FRect * ___d = (const SDL_FRect *) regarray[REG68K_A3/4];

  return _iface->SDL_RenderCopyF(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopyF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderCopyFPPC };

int SDL_RenderCopyExF(SDL_Renderer * ___a, SDL_Texture * ___b, const SDL_Rect * ___c, const SDL_FRect * ___d, const double ___e, const SDL_FPoint * ___f, const SDL_RendererFlip ___g);

int
SDL2Gate_SDL_RenderCopyExF(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Rect * ___c,
     const SDL_FRect * ___d,
     const double ___e,
     const SDL_FPoint * ___f,
     const SDL_RendererFlip ___g)
{
  return SDL_RenderCopyExF(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

STATIC int 
SDL2Gate_SDL_RenderCopyExFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Texture * ___b = (SDL_Texture *) regarray[REG68K_A1/4];
  const SDL_Rect * ___c = (const SDL_Rect *) regarray[REG68K_A2/4];
  const SDL_FRect * ___d = (const SDL_FRect *) regarray[REG68K_A3/4];
  const double ___e = (const double) regarray[REG68K_D0/4];
  const SDL_FPoint * ___f = (const SDL_FPoint *) regarray[REG68K_D2/4];
  const SDL_RendererFlip ___g = (const SDL_RendererFlip) regarray[REG68K_D3/4];

  return _iface->SDL_RenderCopyExF(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderCopyExF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderCopyExFPPC };

SDL_TouchDeviceType SDL_GetTouchDeviceType(SDL_TouchID ___a);

SDL_TouchDeviceType
SDL2Gate_SDL_GetTouchDeviceType(struct SDL2IFace* _iface,
     SDL_TouchID ___a)
{
  return SDL_GetTouchDeviceType(___a);
}

STATIC SDL_TouchDeviceType 
SDL2Gate_SDL_GetTouchDeviceTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_TouchID ___a = (SDL_TouchID) regarray[REG68K_D0/4];

  return _iface->SDL_GetTouchDeviceType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchDeviceType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTouchDeviceTypePPC };

size_t SDL_SIMDGetAlignment(void);

size_t
SDL2Gate_SDL_SIMDGetAlignment(struct SDL2IFace* _iface)
{
  return SDL_SIMDGetAlignment();
}

STATIC size_t 
SDL2Gate_SDL_SIMDGetAlignmentPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_SIMDGetAlignment();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDGetAlignment = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SIMDGetAlignmentPPC };

void* SDL_SIMDAlloc(const size_t ___a);

void*
SDL2Gate_SDL_SIMDAlloc(struct SDL2IFace* _iface,
     const size_t ___a)
{
  return SDL_SIMDAlloc(___a);
}

STATIC void* 
SDL2Gate_SDL_SIMDAllocPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const size_t ___a = (const size_t) regarray[REG68K_D0/4];

  return _iface->SDL_SIMDAlloc(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDAlloc = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SIMDAllocPPC };

void SDL_SIMDFree(void * ___a);

void
SDL2Gate_SDL_SIMDFree(struct SDL2IFace* _iface,
     void * ___a)
{
  return SDL_SIMDFree(___a);
}

STATIC void 
SDL2Gate_SDL_SIMDFreePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];

  return _iface->SDL_SIMDFree(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDFree = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SIMDFreePPC };

Sint64 SDL_RWsize(SDL_RWops * ___a);

Sint64
SDL2Gate_SDL_RWsize(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_RWsize(___a);
}

STATIC Sint64 
SDL2Gate_SDL_RWsizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_RWsize(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWsize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWsizePPC };

Sint64 SDL_RWseek(SDL_RWops * ___a, Sint64 ___b, int ___c);

Sint64
SDL2Gate_SDL_RWseek(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     Sint64 ___b,
     int ___c)
{
  return SDL_RWseek(___a, ___b, ___c);
}

STATIC Sint64 
SDL2Gate_SDL_RWseekPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  Sint64 ___b = (Sint64) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D2/4];

  return _iface->SDL_RWseek(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWseek = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWseekPPC };

Sint64 SDL_RWtell(SDL_RWops * ___a);

Sint64
SDL2Gate_SDL_RWtell(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_RWtell(___a);
}

STATIC Sint64 
SDL2Gate_SDL_RWtellPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_RWtell(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWtell = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWtellPPC };

size_t SDL_RWread(SDL_RWops * ___a, void * ___b, size_t ___c, size_t ___d);

size_t
SDL2Gate_SDL_RWread(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     void * ___b,
     size_t ___c,
     size_t ___d)
{
  return SDL_RWread(___a, ___b, ___c, ___d);
}

STATIC size_t 
SDL2Gate_SDL_RWreadPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  void * ___b = (void *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];
  size_t ___d = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_RWread(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWread = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWreadPPC };

size_t SDL_RWwrite(SDL_RWops * ___a, const void * ___b, size_t ___c, size_t ___d);

size_t
SDL2Gate_SDL_RWwrite(struct SDL2IFace* _iface,
     SDL_RWops * ___a,
     const void * ___b,
     size_t ___c,
     size_t ___d)
{
  return SDL_RWwrite(___a, ___b, ___c, ___d);
}

STATIC size_t 
SDL2Gate_SDL_RWwritePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];
  const void * ___b = (const void *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];
  size_t ___d = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_RWwrite(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWwrite = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWwritePPC };

int SDL_RWclose(SDL_RWops * ___a);

int
SDL2Gate_SDL_RWclose(struct SDL2IFace* _iface,
     SDL_RWops * ___a)
{
  return SDL_RWclose(___a);
}

STATIC int 
SDL2Gate_SDL_RWclosePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_RWops * ___a = (SDL_RWops *) regarray[REG68K_A0/4];

  return _iface->SDL_RWclose(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RWclose = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RWclosePPC };

void* SDL_LoadFile(const char * ___a, size_t * ___b);

void*
SDL2Gate_SDL_LoadFile(struct SDL2IFace* _iface,
     const char * ___a,
     size_t * ___b)
{
  return SDL_LoadFile(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_LoadFilePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  size_t * ___b = (size_t *) regarray[REG68K_A1/4];

  return _iface->SDL_LoadFile(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LoadFile = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LoadFilePPC };

SDL_MetalView SDL_Metal_CreateView(SDL_Window * ___a);

SDL_MetalView
SDL2Gate_SDL_Metal_CreateView(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_Metal_CreateView(___a);
}

STATIC SDL_MetalView 
SDL2Gate_SDL_Metal_CreateViewPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_Metal_CreateView(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_CreateView = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_Metal_CreateViewPPC };

void SDL_Metal_DestroyView(SDL_MetalView ___a);

void
SDL2Gate_SDL_Metal_DestroyView(struct SDL2IFace* _iface,
     SDL_MetalView ___a)
{
  return SDL_Metal_DestroyView(___a);
}

STATIC void 
SDL2Gate_SDL_Metal_DestroyViewPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_MetalView ___a = (SDL_MetalView) regarray[REG68K_D0/4];

  return _iface->SDL_Metal_DestroyView(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_DestroyView = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_Metal_DestroyViewPPC };

int SDL_LockTextureToSurface(SDL_Texture * ___a, const SDL_Rect * ___b, SDL_Surface * * ___c);

int
SDL2Gate_SDL_LockTextureToSurface(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * * ___c)
{
  return SDL_LockTextureToSurface(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_LockTextureToSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * * ___c = (SDL_Surface * *) regarray[REG68K_A2/4];

  return _iface->SDL_LockTextureToSurface(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockTextureToSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockTextureToSurfacePPC };

SDL_bool SDL_HasARMSIMD(void);

SDL_bool
SDL2Gate_SDL_HasARMSIMD(struct SDL2IFace* _iface)
{
  return SDL_HasARMSIMD();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasARMSIMDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasARMSIMD();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasARMSIMD = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasARMSIMDPPC };

char* SDL_strtokr(char * ___a, const char * ___b, char * * ___c);

char*
SDL2Gate_SDL_strtokr(struct SDL2IFace* _iface,
     char * ___a,
     const char * ___b,
     char * * ___c)
{
  return SDL_strtokr(___a, ___b, ___c);
}

STATIC char* 
SDL2Gate_SDL_strtokrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  char * ___a = (char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];
  char * * ___c = (char * *) regarray[REG68K_A2/4];

  return _iface->SDL_strtokr(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strtokr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strtokrPPC };

wchar_t* SDL_wcsstr(const wchar_t * ___a, const wchar_t * ___b);

wchar_t*
SDL2Gate_SDL_wcsstr(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b)
{
  return SDL_wcsstr(___a, ___b);
}

STATIC wchar_t* 
SDL2Gate_SDL_wcsstrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];

  return _iface->SDL_wcsstr(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcsstr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcsstrPPC };

int SDL_wcsncmp(const wchar_t * ___a, const wchar_t * ___b, size_t ___c);

int
SDL2Gate_SDL_wcsncmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c)
{
  return SDL_wcsncmp(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_wcsncmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_wcsncmp(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcsncmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcsncmpPPC };

SDL_GameControllerType SDL_GameControllerTypeForIndex(int ___a);

SDL_GameControllerType
SDL2Gate_SDL_GameControllerTypeForIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerTypeForIndex(___a);
}

STATIC SDL_GameControllerType 
SDL2Gate_SDL_GameControllerTypeForIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerTypeForIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerTypeForIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerTypeForIndexPPC };

SDL_GameControllerType SDL_GameControllerGetType(SDL_GameController * ___a);

SDL_GameControllerType
SDL2Gate_SDL_GameControllerGetType(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetType(___a);
}

STATIC SDL_GameControllerType 
SDL2Gate_SDL_GameControllerGetTypePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetType(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetType = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetTypePPC };

SDL_GameController* SDL_GameControllerFromPlayerIndex(int ___a);

SDL_GameController*
SDL2Gate_SDL_GameControllerFromPlayerIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerFromPlayerIndex(___a);
}

STATIC SDL_GameController* 
SDL2Gate_SDL_GameControllerFromPlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerFromPlayerIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerFromPlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerFromPlayerIndexPPC };

void SDL_GameControllerSetPlayerIndex(SDL_GameController * ___a, int ___b);

void
SDL2Gate_SDL_GameControllerSetPlayerIndex(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     int ___b)
{
  return SDL_GameControllerSetPlayerIndex(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_GameControllerSetPlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerSetPlayerIndex(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSetPlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerSetPlayerIndexPPC };

SDL_Joystick* SDL_JoystickFromPlayerIndex(int ___a);

SDL_Joystick*
SDL2Gate_SDL_JoystickFromPlayerIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickFromPlayerIndex(___a);
}

STATIC SDL_Joystick* 
SDL2Gate_SDL_JoystickFromPlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickFromPlayerIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickFromPlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickFromPlayerIndexPPC };

void SDL_JoystickSetPlayerIndex(SDL_Joystick * ___a, int ___b);

void
SDL2Gate_SDL_JoystickSetPlayerIndex(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b)
{
  return SDL_JoystickSetPlayerIndex(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_JoystickSetPlayerIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickSetPlayerIndex(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetPlayerIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickSetPlayerIndexPPC };

int SDL_SetTextureScaleMode(SDL_Texture * ___a, SDL_ScaleMode ___b);

int
SDL2Gate_SDL_SetTextureScaleMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_ScaleMode ___b)
{
  return SDL_SetTextureScaleMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetTextureScaleModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  SDL_ScaleMode ___b = (SDL_ScaleMode) regarray[REG68K_D0/4];

  return _iface->SDL_SetTextureScaleMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureScaleMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetTextureScaleModePPC };

int SDL_GetTextureScaleMode(SDL_Texture * ___a, SDL_ScaleMode * ___b);

int
SDL2Gate_SDL_GetTextureScaleMode(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     SDL_ScaleMode * ___b)
{
  return SDL_GetTextureScaleMode(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GetTextureScaleModePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  SDL_ScaleMode * ___b = (SDL_ScaleMode *) regarray[REG68K_A1/4];

  return _iface->SDL_GetTextureScaleMode(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureScaleMode = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTextureScaleModePPC };

void SDL_OnApplicationWillTerminate(void);

void
SDL2Gate_SDL_OnApplicationWillTerminate(struct SDL2IFace* _iface)
{
  return SDL_OnApplicationWillTerminate();
}

STATIC void 
SDL2Gate_SDL_OnApplicationWillTerminatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_OnApplicationWillTerminate();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationWillTerminate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OnApplicationWillTerminatePPC };

void SDL_OnApplicationDidReceiveMemoryWarning(void);

void
SDL2Gate_SDL_OnApplicationDidReceiveMemoryWarning(struct SDL2IFace* _iface)
{
  return SDL_OnApplicationDidReceiveMemoryWarning();
}

STATIC void 
SDL2Gate_SDL_OnApplicationDidReceiveMemoryWarningPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_OnApplicationDidReceiveMemoryWarning();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationDidReceiveMemoryWarning = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OnApplicationDidReceiveMemoryWarningPPC };

void SDL_OnApplicationWillResignActive(void);

void
SDL2Gate_SDL_OnApplicationWillResignActive(struct SDL2IFace* _iface)
{
  return SDL_OnApplicationWillResignActive();
}

STATIC void 
SDL2Gate_SDL_OnApplicationWillResignActivePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_OnApplicationWillResignActive();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationWillResignActive = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OnApplicationWillResignActivePPC };

void SDL_OnApplicationDidEnterBackground(void);

void
SDL2Gate_SDL_OnApplicationDidEnterBackground(struct SDL2IFace* _iface)
{
  return SDL_OnApplicationDidEnterBackground();
}

STATIC void 
SDL2Gate_SDL_OnApplicationDidEnterBackgroundPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_OnApplicationDidEnterBackground();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationDidEnterBackground = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OnApplicationDidEnterBackgroundPPC };

void SDL_OnApplicationWillEnterForeground(void);

void
SDL2Gate_SDL_OnApplicationWillEnterForeground(struct SDL2IFace* _iface)
{
  return SDL_OnApplicationWillEnterForeground();
}

STATIC void 
SDL2Gate_SDL_OnApplicationWillEnterForegroundPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_OnApplicationWillEnterForeground();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationWillEnterForeground = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OnApplicationWillEnterForegroundPPC };

void SDL_OnApplicationDidBecomeActive(void);

void
SDL2Gate_SDL_OnApplicationDidBecomeActive(struct SDL2IFace* _iface)
{
  return SDL_OnApplicationDidBecomeActive();
}

STATIC void 
SDL2Gate_SDL_OnApplicationDidBecomeActivePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_OnApplicationDidBecomeActive();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OnApplicationDidBecomeActive = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OnApplicationDidBecomeActivePPC };

int SDL_isupper(int ___a);

int
SDL2Gate_SDL_isupper(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isupper(___a);
}

STATIC int 
SDL2Gate_SDL_isupperPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isupper(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isupper = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isupperPPC };

int SDL_islower(int ___a);

int
SDL2Gate_SDL_islower(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_islower(___a);
}

STATIC int 
SDL2Gate_SDL_islowerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_islower(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_islower = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_islowerPPC };

int SDL_JoystickAttachVirtual(SDL_JoystickType ___a, int ___b, int ___c, int ___d);

int
SDL2Gate_SDL_JoystickAttachVirtual(struct SDL2IFace* _iface,
     SDL_JoystickType ___a,
     int ___b,
     int ___c,
     int ___d)
{
  return SDL_JoystickAttachVirtual(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_JoystickAttachVirtualPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_JoystickType ___a = (SDL_JoystickType) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  int ___c = (int) regarray[REG68K_D2/4];
  int ___d = (int) regarray[REG68K_D3/4];

  return _iface->SDL_JoystickAttachVirtual(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickAttachVirtual = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickAttachVirtualPPC };

int SDL_JoystickDetachVirtual(int ___a);

int
SDL2Gate_SDL_JoystickDetachVirtual(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickDetachVirtual(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickDetachVirtualPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickDetachVirtual(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickDetachVirtual = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickDetachVirtualPPC };

SDL_bool SDL_JoystickIsVirtual(int ___a);

SDL_bool
SDL2Gate_SDL_JoystickIsVirtual(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickIsVirtual(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_JoystickIsVirtualPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickIsVirtual(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickIsVirtual = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickIsVirtualPPC };

int SDL_JoystickSetVirtualAxis(SDL_Joystick * ___a, int ___b, Sint16 ___c);

int
SDL2Gate_SDL_JoystickSetVirtualAxis(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Sint16 ___c)
{
  return SDL_JoystickSetVirtualAxis(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_JoystickSetVirtualAxisPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Sint16 ___c = (Sint16) regarray[REG68K_D1/4];

  return _iface->SDL_JoystickSetVirtualAxis(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetVirtualAxis = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickSetVirtualAxisPPC };

int SDL_JoystickSetVirtualButton(SDL_Joystick * ___a, int ___b, Uint8 ___c);

int
SDL2Gate_SDL_JoystickSetVirtualButton(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Uint8 ___c)
{
  return SDL_JoystickSetVirtualButton(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_JoystickSetVirtualButtonPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];

  return _iface->SDL_JoystickSetVirtualButton(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetVirtualButton = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickSetVirtualButtonPPC };

int SDL_JoystickSetVirtualHat(SDL_Joystick * ___a, int ___b, Uint8 ___c);

int
SDL2Gate_SDL_JoystickSetVirtualHat(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     int ___b,
     Uint8 ___c)
{
  return SDL_JoystickSetVirtualHat(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_JoystickSetVirtualHatPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];

  return _iface->SDL_JoystickSetVirtualHat(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetVirtualHat = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickSetVirtualHatPPC };

char* SDL_GetErrorMsg(char * ___a, int ___b);

char*
SDL2Gate_SDL_GetErrorMsg(struct SDL2IFace* _iface,
     char * ___a,
     int ___b)
{
  return SDL_GetErrorMsg(___a, ___b);
}

STATIC char* 
SDL2Gate_SDL_GetErrorMsgPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  char * ___a = (char *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetErrorMsg(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetErrorMsg = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetErrorMsgPPC };

void SDL_LockSensors(void);

void
SDL2Gate_SDL_LockSensors(struct SDL2IFace* _iface)
{
  return SDL_LockSensors();
}

STATIC void 
SDL2Gate_SDL_LockSensorsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_LockSensors();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_LockSensors = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_LockSensorsPPC };

void SDL_UnlockSensors(void);

void
SDL2Gate_SDL_UnlockSensors(struct SDL2IFace* _iface)
{
  return SDL_UnlockSensors();
}

STATIC void 
SDL2Gate_SDL_UnlockSensorsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_UnlockSensors();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnlockSensors = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnlockSensorsPPC };

void* SDL_Metal_GetLayer(SDL_MetalView ___a);

void*
SDL2Gate_SDL_Metal_GetLayer(struct SDL2IFace* _iface,
     SDL_MetalView ___a)
{
  return SDL_Metal_GetLayer(___a);
}

STATIC void* 
SDL2Gate_SDL_Metal_GetLayerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_MetalView ___a = (SDL_MetalView) regarray[REG68K_D0/4];

  return _iface->SDL_Metal_GetLayer(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_GetLayer = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_Metal_GetLayerPPC };

void SDL_Metal_GetDrawableSize(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_Metal_GetDrawableSize(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_Metal_GetDrawableSize(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_Metal_GetDrawableSizePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_Metal_GetDrawableSize(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_Metal_GetDrawableSize = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_Metal_GetDrawableSizePPC };

double SDL_trunc(double ___a);

double
SDL2Gate_SDL_trunc(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_trunc(___a);
}

STATIC double 
SDL2Gate_SDL_truncPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_trunc(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_trunc = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_truncPPC };

float SDL_truncf(float ___a);

float
SDL2Gate_SDL_truncf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_truncf(___a);
}

STATIC float 
SDL2Gate_SDL_truncfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_truncf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_truncf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_truncfPPC };

SDL_Locale * SDL_GetPreferredLocales(void);

SDL_Locale *
SDL2Gate_SDL_GetPreferredLocales(struct SDL2IFace* _iface)
{
  return SDL_GetPreferredLocales();
}

STATIC SDL_Locale * 
SDL2Gate_SDL_GetPreferredLocalesPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetPreferredLocales();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPreferredLocales = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPreferredLocalesPPC };

void* SDL_SIMDRealloc(void * ___a, const size_t ___b);

void*
SDL2Gate_SDL_SIMDRealloc(struct SDL2IFace* _iface,
     void * ___a,
     const size_t ___b)
{
  return SDL_SIMDRealloc(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_SIMDReallocPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  void * ___a = (void *) regarray[REG68K_A0/4];
  const size_t ___b = (const size_t) regarray[REG68K_D0/4];

  return _iface->SDL_SIMDRealloc(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SIMDRealloc = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SIMDReallocPPC };

int SDL_OpenURL(const char * ___a);

int
SDL2Gate_SDL_OpenURL(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_OpenURL(___a);
}

STATIC int 
SDL2Gate_SDL_OpenURLPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_OpenURL(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_OpenURL = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_OpenURLPPC };

SDL_bool SDL_HasSurfaceRLE(SDL_Surface * ___a);

SDL_bool
SDL2Gate_SDL_HasSurfaceRLE(struct SDL2IFace* _iface,
     SDL_Surface * ___a)
{
  return SDL_HasSurfaceRLE(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasSurfaceRLEPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];

  return _iface->SDL_HasSurfaceRLE(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasSurfaceRLE = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasSurfaceRLEPPC };

SDL_bool SDL_GameControllerHasLED(SDL_GameController * ___a);

SDL_bool
SDL2Gate_SDL_GameControllerHasLED(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerHasLED(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerHasLEDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerHasLED(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasLED = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerHasLEDPPC };

int SDL_GameControllerSetLED(SDL_GameController * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d);

int
SDL2Gate_SDL_GameControllerSetLED(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d)
{
  return SDL_GameControllerSetLED(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GameControllerSetLEDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];

  return _iface->SDL_GameControllerSetLED(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSetLED = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerSetLEDPPC };

SDL_bool SDL_JoystickHasLED(SDL_Joystick * ___a);

SDL_bool
SDL2Gate_SDL_JoystickHasLED(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickHasLED(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_JoystickHasLEDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickHasLED(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickHasLED = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickHasLEDPPC };

int SDL_JoystickSetLED(SDL_Joystick * ___a, Uint8 ___b, Uint8 ___c, Uint8 ___d);

int
SDL2Gate_SDL_JoystickSetLED(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     Uint8 ___b,
     Uint8 ___c,
     Uint8 ___d)
{
  return SDL_JoystickSetLED(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_JoystickSetLEDPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  Uint8 ___b = (Uint8) regarray[REG68K_D0/4];
  Uint8 ___c = (Uint8) regarray[REG68K_D1/4];
  Uint8 ___d = (Uint8) regarray[REG68K_D2/4];

  return _iface->SDL_JoystickSetLED(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSetLED = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickSetLEDPPC };

int SDL_GameControllerRumbleTriggers(SDL_GameController * ___a, Uint16 ___b, Uint16 ___c, Uint32 ___d);

int
SDL2Gate_SDL_GameControllerRumbleTriggers(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d)
{
  return SDL_GameControllerRumbleTriggers(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GameControllerRumbleTriggersPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  Uint16 ___b = (Uint16) regarray[REG68K_D0/4];
  Uint16 ___c = (Uint16) regarray[REG68K_D1/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D2/4];

  return _iface->SDL_GameControllerRumbleTriggers(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerRumbleTriggers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerRumbleTriggersPPC };

int SDL_JoystickRumbleTriggers(SDL_Joystick * ___a, Uint16 ___b, Uint16 ___c, Uint32 ___d);

int
SDL2Gate_SDL_JoystickRumbleTriggers(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     Uint16 ___b,
     Uint16 ___c,
     Uint32 ___d)
{
  return SDL_JoystickRumbleTriggers(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_JoystickRumbleTriggersPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  Uint16 ___b = (Uint16) regarray[REG68K_D0/4];
  Uint16 ___c = (Uint16) regarray[REG68K_D1/4];
  Uint32 ___d = (Uint32) regarray[REG68K_D2/4];

  return _iface->SDL_JoystickRumbleTriggers(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickRumbleTriggers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickRumbleTriggersPPC };

SDL_bool SDL_GameControllerHasAxis(SDL_GameController * ___a, SDL_GameControllerAxis ___b);

SDL_bool
SDL2Gate_SDL_GameControllerHasAxis(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerAxis ___b)
{
  return SDL_GameControllerHasAxis(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerHasAxisPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_GameControllerAxis ___b = (SDL_GameControllerAxis) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerHasAxis(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasAxis = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerHasAxisPPC };

SDL_bool SDL_GameControllerHasButton(SDL_GameController * ___a, SDL_GameControllerButton ___b);

SDL_bool
SDL2Gate_SDL_GameControllerHasButton(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerButton ___b)
{
  return SDL_GameControllerHasButton(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerHasButtonPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_GameControllerButton ___b = (SDL_GameControllerButton) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerHasButton(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasButton = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerHasButtonPPC };

int SDL_GameControllerGetNumTouchpads(SDL_GameController * ___a);

int
SDL2Gate_SDL_GameControllerGetNumTouchpads(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetNumTouchpads(___a);
}

STATIC int 
SDL2Gate_SDL_GameControllerGetNumTouchpadsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetNumTouchpads(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetNumTouchpads = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetNumTouchpadsPPC };

int SDL_GameControllerGetNumTouchpadFingers(SDL_GameController * ___a, int ___b);

int
SDL2Gate_SDL_GameControllerGetNumTouchpadFingers(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     int ___b)
{
  return SDL_GameControllerGetNumTouchpadFingers(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_GameControllerGetNumTouchpadFingersPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetNumTouchpadFingers(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetNumTouchpadFingers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetNumTouchpadFingersPPC };

int SDL_GameControllerGetTouchpadFinger(SDL_GameController * ___a, int ___b, int ___c, Uint8 * ___d, float * ___e, float * ___f, float * ___g);

int
SDL2Gate_SDL_GameControllerGetTouchpadFinger(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     int ___b,
     int ___c,
     Uint8 * ___d,
     float * ___e,
     float * ___f,
     float * ___g)
{
  return SDL_GameControllerGetTouchpadFinger(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

STATIC int 
SDL2Gate_SDL_GameControllerGetTouchpadFingerPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  Uint8 * ___d = (Uint8 *) regarray[REG68K_A1/4];
  float * ___e = (float *) regarray[REG68K_A2/4];
  float * ___f = (float *) regarray[REG68K_A3/4];
  float * ___g = (float *) regarray[REG68K_D2/4];

  return _iface->SDL_GameControllerGetTouchpadFinger(___a, ___b, ___c, ___d, ___e, ___f, ___g);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetTouchpadFinger = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetTouchpadFingerPPC };

Uint32 SDL_crc32(Uint32 ___a, const void * ___b, size_t ___c);

Uint32
SDL2Gate_SDL_crc32(struct SDL2IFace* _iface,
     Uint32 ___a,
     const void * ___b,
     size_t ___c)
{
  return SDL_crc32(___a, ___b, ___c);
}

STATIC Uint32 
SDL2Gate_SDL_crc32PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint32 ___a = (Uint32) regarray[REG68K_D0/4];
  const void * ___b = (const void *) regarray[REG68K_A0/4];
  size_t ___c = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_crc32(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_crc32 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_crc32PPC };

const char* SDL_GameControllerGetSerial(SDL_GameController * ___a);

const char*
SDL2Gate_SDL_GameControllerGetSerial(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetSerial(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerGetSerialPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetSerial(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSerial = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetSerialPPC };

const char* SDL_JoystickGetSerial(SDL_Joystick * ___a);

const char*
SDL2Gate_SDL_JoystickGetSerial(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetSerial(___a);
}

STATIC const char* 
SDL2Gate_SDL_JoystickGetSerialPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetSerial(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetSerial = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetSerialPPC };

SDL_bool SDL_GameControllerHasSensor(SDL_GameController * ___a, SDL_SensorType ___b);

SDL_bool
SDL2Gate_SDL_GameControllerHasSensor(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b)
{
  return SDL_GameControllerHasSensor(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerHasSensorPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_SensorType ___b = (SDL_SensorType) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerHasSensor(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasSensor = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerHasSensorPPC };

int SDL_GameControllerSetSensorEnabled(SDL_GameController * ___a, SDL_SensorType ___b, SDL_bool ___c);

int
SDL2Gate_SDL_GameControllerSetSensorEnabled(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b,
     SDL_bool ___c)
{
  return SDL_GameControllerSetSensorEnabled(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GameControllerSetSensorEnabledPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_SensorType ___b = (SDL_SensorType) regarray[REG68K_D0/4];
  SDL_bool ___c = (SDL_bool) regarray[REG68K_D1/4];

  return _iface->SDL_GameControllerSetSensorEnabled(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSetSensorEnabled = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerSetSensorEnabledPPC };

SDL_bool SDL_GameControllerIsSensorEnabled(SDL_GameController * ___a, SDL_SensorType ___b);

SDL_bool
SDL2Gate_SDL_GameControllerIsSensorEnabled(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b)
{
  return SDL_GameControllerIsSensorEnabled(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerIsSensorEnabledPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_SensorType ___b = (SDL_SensorType) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerIsSensorEnabled(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerIsSensorEnabled = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerIsSensorEnabledPPC };

int SDL_GameControllerGetSensorData(SDL_GameController * ___a, SDL_SensorType ___b, float * ___c, int ___d);

int
SDL2Gate_SDL_GameControllerGetSensorData(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b,
     float * ___c,
     int ___d)
{
  return SDL_GameControllerGetSensorData(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_GameControllerGetSensorDataPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_SensorType ___b = (SDL_SensorType) regarray[REG68K_D0/4];
  float * ___c = (float *) regarray[REG68K_A1/4];
  int ___d = (int) regarray[REG68K_D1/4];

  return _iface->SDL_GameControllerGetSensorData(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSensorData = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetSensorDataPPC };

int SDL_wcscasecmp(const wchar_t * ___a, const wchar_t * ___b);

int
SDL2Gate_SDL_wcscasecmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b)
{
  return SDL_wcscasecmp(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_wcscasecmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];

  return _iface->SDL_wcscasecmp(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcscasecmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcscasecmpPPC };

int SDL_wcsncasecmp(const wchar_t * ___a, const wchar_t * ___b, size_t ___c);

int
SDL2Gate_SDL_wcsncasecmp(struct SDL2IFace* _iface,
     const wchar_t * ___a,
     const wchar_t * ___b,
     size_t ___c)
{
  return SDL_wcsncasecmp(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_wcsncasecmpPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const wchar_t * ___a = (const wchar_t *) regarray[REG68K_A0/4];
  const wchar_t * ___b = (const wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_wcsncasecmp(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_wcsncasecmp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_wcsncasecmpPPC };

double SDL_round(double ___a);

double
SDL2Gate_SDL_round(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_round(___a);
}

STATIC double 
SDL2Gate_SDL_roundPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_round(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_round = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_roundPPC };

float SDL_roundf(float ___a);

float
SDL2Gate_SDL_roundf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_roundf(___a);
}

STATIC float 
SDL2Gate_SDL_roundfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_roundf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_roundf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_roundfPPC };

long SDL_lround(double ___a);

long
SDL2Gate_SDL_lround(struct SDL2IFace* _iface,
     double ___a)
{
  return SDL_lround(___a);
}

STATIC long 
SDL2Gate_SDL_lroundPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  double ___a = (double) regarray[REG68K_D0/4];

  return _iface->SDL_lround(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_lround = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_lroundPPC };

long SDL_lroundf(float ___a);

long
SDL2Gate_SDL_lroundf(struct SDL2IFace* _iface,
     float ___a)
{
  return SDL_lroundf(___a);
}

STATIC long 
SDL2Gate_SDL_lroundfPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  float ___a = (float) regarray[REG68K_D0/4];

  return _iface->SDL_lroundf(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_lroundf = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_lroundfPPC };

int SDL_SoftStretchLinear(SDL_Surface * ___a, const SDL_Rect * ___b, SDL_Surface * ___c, const SDL_Rect * ___d);

int
SDL2Gate_SDL_SoftStretchLinear(struct SDL2IFace* _iface,
     SDL_Surface * ___a,
     const SDL_Rect * ___b,
     SDL_Surface * ___c,
     const SDL_Rect * ___d)
{
  return SDL_SoftStretchLinear(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SoftStretchLinearPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Surface * ___a = (SDL_Surface *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  SDL_Surface * ___c = (SDL_Surface *) regarray[REG68K_A2/4];
  const SDL_Rect * ___d = (const SDL_Rect *) regarray[REG68K_A3/4];

  return _iface->SDL_SoftStretchLinear(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SoftStretchLinear = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SoftStretchLinearPPC };

int SDL_UpdateNVTexture(SDL_Texture * ___a, const SDL_Rect * ___b, const Uint8 * ___c, int ___d, const Uint8 * ___e, int ___f);

int
SDL2Gate_SDL_UpdateNVTexture(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     const SDL_Rect * ___b,
     const Uint8 * ___c,
     int ___d,
     const Uint8 * ___e,
     int ___f)
{
  return SDL_UpdateNVTexture(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC int 
SDL2Gate_SDL_UpdateNVTexturePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];
  const Uint8 * ___c = (const Uint8 *) regarray[REG68K_A2/4];
  int ___d = (int) regarray[REG68K_D0/4];
  const Uint8 * ___e = (const Uint8 *) regarray[REG68K_A3/4];
  int ___f = (int) regarray[REG68K_D1/4];

  return _iface->SDL_UpdateNVTexture(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UpdateNVTexture = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UpdateNVTexturePPC };

void SDL_SetWindowKeyboardGrab(SDL_Window * ___a, SDL_bool ___b);

void
SDL2Gate_SDL_SetWindowKeyboardGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b)
{
  return SDL_SetWindowKeyboardGrab(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowKeyboardGrabPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowKeyboardGrab(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowKeyboardGrab = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowKeyboardGrabPPC };

void SDL_SetWindowMouseGrab(SDL_Window * ___a, SDL_bool ___b);

void
SDL2Gate_SDL_SetWindowMouseGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b)
{
  return SDL_SetWindowMouseGrab(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowMouseGrabPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowMouseGrab(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMouseGrab = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowMouseGrabPPC };

SDL_bool SDL_GetWindowKeyboardGrab(SDL_Window * ___a);

SDL_bool
SDL2Gate_SDL_GetWindowKeyboardGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowKeyboardGrab(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GetWindowKeyboardGrabPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowKeyboardGrab(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowKeyboardGrab = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowKeyboardGrabPPC };

SDL_bool SDL_GetWindowMouseGrab(SDL_Window * ___a);

SDL_bool
SDL2Gate_SDL_GetWindowMouseGrab(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowMouseGrab(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GetWindowMouseGrabPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowMouseGrab(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMouseGrab = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowMouseGrabPPC };

int SDL_isalpha(int ___a);

int
SDL2Gate_SDL_isalpha(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isalpha(___a);
}

STATIC int 
SDL2Gate_SDL_isalphaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isalpha(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isalpha = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isalphaPPC };

int SDL_isalnum(int ___a);

int
SDL2Gate_SDL_isalnum(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isalnum(___a);
}

STATIC int 
SDL2Gate_SDL_isalnumPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isalnum(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isalnum = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isalnumPPC };

int SDL_isblank(int ___a);

int
SDL2Gate_SDL_isblank(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isblank(___a);
}

STATIC int 
SDL2Gate_SDL_isblankPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isblank(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isblank = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isblankPPC };

int SDL_iscntrl(int ___a);

int
SDL2Gate_SDL_iscntrl(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_iscntrl(___a);
}

STATIC int 
SDL2Gate_SDL_iscntrlPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_iscntrl(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_iscntrl = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_iscntrlPPC };

int SDL_isxdigit(int ___a);

int
SDL2Gate_SDL_isxdigit(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isxdigit(___a);
}

STATIC int 
SDL2Gate_SDL_isxdigitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isxdigit(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isxdigit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isxdigitPPC };

int SDL_ispunct(int ___a);

int
SDL2Gate_SDL_ispunct(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_ispunct(___a);
}

STATIC int 
SDL2Gate_SDL_ispunctPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_ispunct(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ispunct = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ispunctPPC };

int SDL_isprint(int ___a);

int
SDL2Gate_SDL_isprint(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isprint(___a);
}

STATIC int 
SDL2Gate_SDL_isprintPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isprint(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isprint = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isprintPPC };

int SDL_isgraph(int ___a);

int
SDL2Gate_SDL_isgraph(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_isgraph(___a);
}

STATIC int 
SDL2Gate_SDL_isgraphPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_isgraph(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_isgraph = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_isgraphPPC };

int SDL_GetAudioDeviceSpec(int ___a, int ___b, SDL_AudioSpec * ___c);

int
SDL2Gate_SDL_GetAudioDeviceSpec(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     SDL_AudioSpec * ___c)
{
  return SDL_GetAudioDeviceSpec(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GetAudioDeviceSpecPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  SDL_AudioSpec * ___c = (SDL_AudioSpec *) regarray[REG68K_A0/4];

  return _iface->SDL_GetAudioDeviceSpec(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetAudioDeviceSpec = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetAudioDeviceSpecPPC };

void SDL_TLSCleanup(void);

void
SDL2Gate_SDL_TLSCleanup(struct SDL2IFace* _iface)
{
  return SDL_TLSCleanup();
}

STATIC void 
SDL2Gate_SDL_TLSCleanupPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_TLSCleanup();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_TLSCleanup = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_TLSCleanupPPC };

void SDL_SetWindowAlwaysOnTop(SDL_Window * ___a, SDL_bool ___b);

void
SDL2Gate_SDL_SetWindowAlwaysOnTop(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_bool ___b)
{
  return SDL_SetWindowAlwaysOnTop(___a, ___b);
}

STATIC void 
SDL2Gate_SDL_SetWindowAlwaysOnTopPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_bool ___b = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_SetWindowAlwaysOnTop(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowAlwaysOnTop = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowAlwaysOnTopPPC };

int SDL_FlashWindow(SDL_Window * ___a, SDL_FlashOperation ___b);

int
SDL2Gate_SDL_FlashWindow(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     SDL_FlashOperation ___b)
{
  return SDL_FlashWindow(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_FlashWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  SDL_FlashOperation ___b = (SDL_FlashOperation) regarray[REG68K_D0/4];

  return _iface->SDL_FlashWindow(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_FlashWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_FlashWindowPPC };

int SDL_GameControllerSendEffect(SDL_GameController * ___a, const void * ___b, int ___c);

int
SDL2Gate_SDL_GameControllerSendEffect(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     const void * ___b,
     int ___c)
{
  return SDL_GameControllerSendEffect(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GameControllerSendEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  const void * ___b = (const void *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerSendEffect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerSendEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerSendEffectPPC };

int SDL_JoystickSendEffect(SDL_Joystick * ___a, const void * ___b, int ___c);

int
SDL2Gate_SDL_JoystickSendEffect(struct SDL2IFace* _iface,
     SDL_Joystick * ___a,
     const void * ___b,
     int ___c)
{
  return SDL_JoystickSendEffect(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_JoystickSendEffectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];
  const void * ___b = (const void *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickSendEffect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickSendEffect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickSendEffectPPC };

float SDL_GameControllerGetSensorDataRate(SDL_GameController * ___a, SDL_SensorType ___b);

float
SDL2Gate_SDL_GameControllerGetSensorDataRate(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b)
{
  return SDL_GameControllerGetSensorDataRate(___a, ___b);
}

STATIC float 
SDL2Gate_SDL_GameControllerGetSensorDataRatePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_SensorType ___b = (SDL_SensorType) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetSensorDataRate(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSensorDataRate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetSensorDataRatePPC };

int SDL_SetTextureUserData(SDL_Texture * ___a, void * ___b);

int
SDL2Gate_SDL_SetTextureUserData(struct SDL2IFace* _iface,
     SDL_Texture * ___a,
     void * ___b)
{
  return SDL_SetTextureUserData(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetTextureUserDataPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];
  void * ___b = (void *) regarray[REG68K_A1/4];

  return _iface->SDL_SetTextureUserData(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetTextureUserData = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetTextureUserDataPPC };

void* SDL_GetTextureUserData(SDL_Texture * ___a);

void*
SDL2Gate_SDL_GetTextureUserData(struct SDL2IFace* _iface,
     SDL_Texture * ___a)
{
  return SDL_GetTextureUserData(___a);
}

STATIC void* 
SDL2Gate_SDL_GetTextureUserDataPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Texture * ___a = (SDL_Texture *) regarray[REG68K_A0/4];

  return _iface->SDL_GetTextureUserData(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTextureUserData = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTextureUserDataPPC };

int SDL_RenderGeometry(SDL_Renderer * ___a, SDL_Texture * ___b, const SDL_Vertex * ___c, int ___d, const int * ___e, int ___f);

int
SDL2Gate_SDL_RenderGeometry(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     SDL_Texture * ___b,
     const SDL_Vertex * ___c,
     int ___d,
     const int * ___e,
     int ___f)
{
  return SDL_RenderGeometry(___a, ___b, ___c, ___d, ___e, ___f);
}

STATIC int 
SDL2Gate_SDL_RenderGeometryPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  SDL_Texture * ___b = (SDL_Texture *) regarray[REG68K_A1/4];
  const SDL_Vertex * ___c = (const SDL_Vertex *) regarray[REG68K_A2/4];
  int ___d = (int) regarray[REG68K_D0/4];
  const int * ___e = (const int *) regarray[REG68K_A3/4];
  int ___f = (int) regarray[REG68K_D1/4];

  return _iface->SDL_RenderGeometry(___a, ___b, ___c, ___d, ___e, ___f);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGeometry = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGeometryPPC };

int SDL_RenderSetVSync(SDL_Renderer * ___a, int ___b);

int
SDL2Gate_SDL_RenderSetVSync(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b)
{
  return SDL_RenderSetVSync(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_RenderSetVSyncPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_RenderSetVSync(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderSetVSync = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderSetVSyncPPC };

void* SDL_GetWindowICCProfile(SDL_Window * ___a, size_t * ___b);

void*
SDL2Gate_SDL_GetWindowICCProfile(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     size_t * ___b)
{
  return SDL_GetWindowICCProfile(___a, ___b);
}

STATIC void* 
SDL2Gate_SDL_GetWindowICCProfilePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  size_t * ___b = (size_t *) regarray[REG68K_A1/4];

  return _iface->SDL_GetWindowICCProfile(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowICCProfile = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowICCProfilePPC };

Uint64 SDL_GetTicks64(void);

Uint64
SDL2Gate_SDL_GetTicks64(struct SDL2IFace* _iface)
{
  return SDL_GetTicks64();
}

STATIC Uint64 
SDL2Gate_SDL_GetTicks64PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetTicks64();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTicks64 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTicks64PPC };

const char* SDL_GameControllerGetAppleSFSymbolsNameForButton(SDL_GameController * ___a, SDL_GameControllerButton ___b);

const char*
SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForButton(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerButton ___b)
{
  return SDL_GameControllerGetAppleSFSymbolsNameForButton(___a, ___b);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForButtonPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_GameControllerButton ___b = (SDL_GameControllerButton) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetAppleSFSymbolsNameForButton(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForButton = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForButtonPPC };

const char* SDL_GameControllerGetAppleSFSymbolsNameForAxis(SDL_GameController * ___a, SDL_GameControllerAxis ___b);

const char*
SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForAxis(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_GameControllerAxis ___b)
{
  return SDL_GameControllerGetAppleSFSymbolsNameForAxis(___a, ___b);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForAxisPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_GameControllerAxis ___b = (SDL_GameControllerAxis) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerGetAppleSFSymbolsNameForAxis(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForAxis = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetAppleSFSymbolsNameForAxisPPC };

int SDL_hid_init(void);

int
SDL2Gate_SDL_hid_init(struct SDL2IFace* _iface)
{
  return SDL_hid_init();
}

STATIC int 
SDL2Gate_SDL_hid_initPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_hid_init();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_init = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_initPPC };

int SDL_hid_exit(void);

int
SDL2Gate_SDL_hid_exit(struct SDL2IFace* _iface)
{
  return SDL_hid_exit();
}

STATIC int 
SDL2Gate_SDL_hid_exitPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_hid_exit();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_exit = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_exitPPC };

Uint32 SDL_hid_device_change_count(void);

Uint32
SDL2Gate_SDL_hid_device_change_count(struct SDL2IFace* _iface)
{
  return SDL_hid_device_change_count();
}

STATIC Uint32 
SDL2Gate_SDL_hid_device_change_countPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_hid_device_change_count();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_device_change_count = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_device_change_countPPC };

SDL_hid_device_info* SDL_hid_enumerate(unsigned short ___a, unsigned short ___b);

SDL_hid_device_info*
SDL2Gate_SDL_hid_enumerate(struct SDL2IFace* _iface,
     unsigned short ___a,
     unsigned short ___b)
{
  return SDL_hid_enumerate(___a, ___b);
}

STATIC SDL_hid_device_info* 
SDL2Gate_SDL_hid_enumeratePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  unsigned short ___a = (unsigned short) regarray[REG68K_D0/4];
  unsigned short ___b = (unsigned short) regarray[REG68K_D1/4];

  return _iface->SDL_hid_enumerate(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_enumerate = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_enumeratePPC };

void SDL_hid_free_enumeration(SDL_hid_device_info * ___a);

void
SDL2Gate_SDL_hid_free_enumeration(struct SDL2IFace* _iface,
     SDL_hid_device_info * ___a)
{
  return SDL_hid_free_enumeration(___a);
}

STATIC void 
SDL2Gate_SDL_hid_free_enumerationPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device_info * ___a = (SDL_hid_device_info *) regarray[REG68K_A0/4];

  return _iface->SDL_hid_free_enumeration(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_free_enumeration = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_free_enumerationPPC };

SDL_hid_device* SDL_hid_open(unsigned short ___a, unsigned short ___b, const wchar_t * ___c);

SDL_hid_device*
SDL2Gate_SDL_hid_open(struct SDL2IFace* _iface,
     unsigned short ___a,
     unsigned short ___b,
     const wchar_t * ___c)
{
  return SDL_hid_open(___a, ___b, ___c);
}

STATIC SDL_hid_device* 
SDL2Gate_SDL_hid_openPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  unsigned short ___a = (unsigned short) regarray[REG68K_D0/4];
  unsigned short ___b = (unsigned short) regarray[REG68K_D1/4];
  const wchar_t * ___c = (const wchar_t *) regarray[REG68K_A0/4];

  return _iface->SDL_hid_open(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_open = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_openPPC };

SDL_hid_device* SDL_hid_open_path(const char * ___a, int ___b);

SDL_hid_device*
SDL2Gate_SDL_hid_open_path(struct SDL2IFace* _iface,
     const char * ___a,
     int ___b)
{
  return SDL_hid_open_path(___a, ___b);
}

STATIC SDL_hid_device* 
SDL2Gate_SDL_hid_open_pathPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_hid_open_path(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_open_path = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_open_pathPPC };

int SDL_hid_write(SDL_hid_device * ___a, const unsigned char * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_write(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     const unsigned char * ___b,
     size_t ___c)
{
  return SDL_hid_write(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_writePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  const unsigned char * ___b = (const unsigned char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_write(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_write = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_writePPC };

int SDL_hid_read_timeout(SDL_hid_device * ___a, unsigned char * ___b, size_t ___c, int ___d);

int
SDL2Gate_SDL_hid_read_timeout(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     unsigned char * ___b,
     size_t ___c,
     int ___d)
{
  return SDL_hid_read_timeout(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_hid_read_timeoutPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  unsigned char * ___b = (unsigned char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];
  int ___d = (int) regarray[REG68K_D1/4];

  return _iface->SDL_hid_read_timeout(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_read_timeout = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_read_timeoutPPC };

int SDL_hid_read(SDL_hid_device * ___a, unsigned char * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_read(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     unsigned char * ___b,
     size_t ___c)
{
  return SDL_hid_read(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_readPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  unsigned char * ___b = (unsigned char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_read(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_read = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_readPPC };

int SDL_hid_set_nonblocking(SDL_hid_device * ___a, int ___b);

int
SDL2Gate_SDL_hid_set_nonblocking(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     int ___b)
{
  return SDL_hid_set_nonblocking(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_hid_set_nonblockingPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];

  return _iface->SDL_hid_set_nonblocking(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_set_nonblocking = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_set_nonblockingPPC };

int SDL_hid_send_feature_report(SDL_hid_device * ___a, const unsigned char * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_send_feature_report(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     const unsigned char * ___b,
     size_t ___c)
{
  return SDL_hid_send_feature_report(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_send_feature_reportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  const unsigned char * ___b = (const unsigned char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_send_feature_report(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_send_feature_report = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_send_feature_reportPPC };

int SDL_hid_get_feature_report(SDL_hid_device * ___a, unsigned char * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_get_feature_report(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     unsigned char * ___b,
     size_t ___c)
{
  return SDL_hid_get_feature_report(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_get_feature_reportPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  unsigned char * ___b = (unsigned char *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_get_feature_report(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_feature_report = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_get_feature_reportPPC };

void SDL_hid_close(SDL_hid_device * ___a);

void
SDL2Gate_SDL_hid_close(struct SDL2IFace* _iface,
     SDL_hid_device * ___a)
{
  return SDL_hid_close(___a);
}

STATIC void 
SDL2Gate_SDL_hid_closePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];

  return _iface->SDL_hid_close(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_close = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_closePPC };

int SDL_hid_get_manufacturer_string(SDL_hid_device * ___a, wchar_t * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_get_manufacturer_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     wchar_t * ___b,
     size_t ___c)
{
  return SDL_hid_get_manufacturer_string(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_get_manufacturer_stringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  wchar_t * ___b = (wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_get_manufacturer_string(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_manufacturer_string = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_get_manufacturer_stringPPC };

int SDL_hid_get_product_string(SDL_hid_device * ___a, wchar_t * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_get_product_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     wchar_t * ___b,
     size_t ___c)
{
  return SDL_hid_get_product_string(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_get_product_stringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  wchar_t * ___b = (wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_get_product_string(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_product_string = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_get_product_stringPPC };

int SDL_hid_get_serial_number_string(SDL_hid_device * ___a, wchar_t * ___b, size_t ___c);

int
SDL2Gate_SDL_hid_get_serial_number_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     wchar_t * ___b,
     size_t ___c)
{
  return SDL_hid_get_serial_number_string(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_hid_get_serial_number_stringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  wchar_t * ___b = (wchar_t *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_hid_get_serial_number_string(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_serial_number_string = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_get_serial_number_stringPPC };

int SDL_hid_get_indexed_string(SDL_hid_device * ___a, int ___b, wchar_t * ___c, size_t ___d);

int
SDL2Gate_SDL_hid_get_indexed_string(struct SDL2IFace* _iface,
     SDL_hid_device * ___a,
     int ___b,
     wchar_t * ___c,
     size_t ___d)
{
  return SDL_hid_get_indexed_string(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_hid_get_indexed_stringPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_hid_device * ___a = (SDL_hid_device *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  wchar_t * ___c = (wchar_t *) regarray[REG68K_A1/4];
  size_t ___d = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_hid_get_indexed_string(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_get_indexed_string = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_get_indexed_stringPPC };

int SDL_SetWindowMouseRect(SDL_Window * ___a, const SDL_Rect * ___b);

int
SDL2Gate_SDL_SetWindowMouseRect(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     const SDL_Rect * ___b)
{
  return SDL_SetWindowMouseRect(___a, ___b);
}

STATIC int 
SDL2Gate_SDL_SetWindowMouseRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  const SDL_Rect * ___b = (const SDL_Rect *) regarray[REG68K_A1/4];

  return _iface->SDL_SetWindowMouseRect(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetWindowMouseRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetWindowMouseRectPPC };

const SDL_Rect* SDL_GetWindowMouseRect(SDL_Window * ___a);

const SDL_Rect*
SDL2Gate_SDL_GetWindowMouseRect(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_GetWindowMouseRect(___a);
}

STATIC const SDL_Rect* 
SDL2Gate_SDL_GetWindowMouseRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_GetWindowMouseRect(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowMouseRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowMouseRectPPC };

void SDL_RenderWindowToLogical(SDL_Renderer * ___a, int ___b, int ___c, float * ___d, float * ___e);

void
SDL2Gate_SDL_RenderWindowToLogical(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     int ___b,
     int ___c,
     float * ___d,
     float * ___e)
{
  return SDL_RenderWindowToLogical(___a, ___b, ___c, ___d, ___e);
}

STATIC void 
SDL2Gate_SDL_RenderWindowToLogicalPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  int ___c = (int) regarray[REG68K_D1/4];
  float * ___d = (float *) regarray[REG68K_A1/4];
  float * ___e = (float *) regarray[REG68K_A2/4];

  return _iface->SDL_RenderWindowToLogical(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderWindowToLogical = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderWindowToLogicalPPC };

void SDL_RenderLogicalToWindow(SDL_Renderer * ___a, float ___b, float ___c, int * ___d, int * ___e);

void
SDL2Gate_SDL_RenderLogicalToWindow(struct SDL2IFace* _iface,
     SDL_Renderer * ___a,
     float ___b,
     float ___c,
     int * ___d,
     int * ___e)
{
  return SDL_RenderLogicalToWindow(___a, ___b, ___c, ___d, ___e);
}

STATIC void 
SDL2Gate_SDL_RenderLogicalToWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];
  float ___b = (float) regarray[REG68K_D0/4];
  float ___c = (float) regarray[REG68K_D1/4];
  int * ___d = (int *) regarray[REG68K_A1/4];
  int * ___e = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_RenderLogicalToWindow(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderLogicalToWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderLogicalToWindowPPC };

SDL_bool SDL_JoystickHasRumble(SDL_Joystick * ___a);

SDL_bool
SDL2Gate_SDL_JoystickHasRumble(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickHasRumble(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_JoystickHasRumblePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickHasRumble(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickHasRumble = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickHasRumblePPC };

SDL_bool SDL_JoystickHasRumbleTriggers(SDL_Joystick * ___a);

SDL_bool
SDL2Gate_SDL_JoystickHasRumbleTriggers(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickHasRumbleTriggers(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_JoystickHasRumbleTriggersPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickHasRumbleTriggers(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickHasRumbleTriggers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickHasRumbleTriggersPPC };

SDL_bool SDL_GameControllerHasRumble(SDL_GameController * ___a);

SDL_bool
SDL2Gate_SDL_GameControllerHasRumble(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerHasRumble(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerHasRumblePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerHasRumble(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasRumble = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerHasRumblePPC };

SDL_bool SDL_GameControllerHasRumbleTriggers(SDL_GameController * ___a);

SDL_bool
SDL2Gate_SDL_GameControllerHasRumbleTriggers(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerHasRumbleTriggers(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_GameControllerHasRumbleTriggersPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerHasRumbleTriggers(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerHasRumbleTriggers = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerHasRumbleTriggersPPC };

void SDL_hid_ble_scan(SDL_bool ___a);

void
SDL2Gate_SDL_hid_ble_scan(struct SDL2IFace* _iface,
     SDL_bool ___a)
{
  return SDL_hid_ble_scan(___a);
}

STATIC void 
SDL2Gate_SDL_hid_ble_scanPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_bool ___a = (SDL_bool) regarray[REG68K_D0/4];

  return _iface->SDL_hid_ble_scan(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_hid_ble_scan = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_hid_ble_scanPPC };

int SDL_PremultiplyAlpha(int ___a, int ___b, Uint32 ___c, const void * ___d, int ___e, Uint32 ___f, void * ___g, int ___h);

int
SDL2Gate_SDL_PremultiplyAlpha(struct SDL2IFace* _iface,
     int ___a,
     int ___b,
     Uint32 ___c,
     const void * ___d,
     int ___e,
     Uint32 ___f,
     void * ___g,
     int ___h)
{
  return SDL_PremultiplyAlpha(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

STATIC int 
SDL2Gate_SDL_PremultiplyAlphaPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];
  int ___b = (int) regarray[REG68K_D1/4];
  Uint32 ___c = (Uint32) regarray[REG68K_D2/4];
  const void * ___d = (const void *) regarray[REG68K_A0/4];
  int ___e = (int) regarray[REG68K_D3/4];
  Uint32 ___f = (Uint32) regarray[REG68K_D4/4];
  void * ___g = (void *) regarray[REG68K_A1/4];
  int ___h = (int) regarray[REG68K_D5/4];

  return _iface->SDL_PremultiplyAlpha(___a, ___b, ___c, ___d, ___e, ___f, ___g, ___h);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_PremultiplyAlpha = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_PremultiplyAlphaPPC };

const char* SDL_GetTouchName(int ___a);

const char*
SDL2Gate_SDL_GetTouchName(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GetTouchName(___a);
}

STATIC const char* 
SDL2Gate_SDL_GetTouchNamePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetTouchName(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetTouchName = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetTouchNamePPC };

void SDL_ClearComposition(void);

void
SDL2Gate_SDL_ClearComposition(struct SDL2IFace* _iface)
{
  return SDL_ClearComposition();
}

STATIC void 
SDL2Gate_SDL_ClearCompositionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ClearComposition();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ClearComposition = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ClearCompositionPPC };

SDL_bool SDL_IsTextInputShown(void);

SDL_bool
SDL2Gate_SDL_IsTextInputShown(struct SDL2IFace* _iface)
{
  return SDL_IsTextInputShown();
}

STATIC SDL_bool 
SDL2Gate_SDL_IsTextInputShownPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_IsTextInputShown();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IsTextInputShown = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IsTextInputShownPPC };

SDL_bool SDL_HasIntersectionF(const SDL_FRect * ___a, const SDL_FRect * ___b);

SDL_bool
SDL2Gate_SDL_HasIntersectionF(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     const SDL_FRect * ___b)
{
  return SDL_HasIntersectionF(___a, ___b);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasIntersectionFPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_FRect * ___a = (const SDL_FRect *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];

  return _iface->SDL_HasIntersectionF(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasIntersectionF = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasIntersectionFPPC };

SDL_bool SDL_IntersectFRect(const SDL_FRect * ___a, const SDL_FRect * ___b, SDL_FRect * ___c);

SDL_bool
SDL2Gate_SDL_IntersectFRect(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     const SDL_FRect * ___b,
     SDL_FRect * ___c)
{
  return SDL_IntersectFRect(___a, ___b, ___c);
}

STATIC SDL_bool 
SDL2Gate_SDL_IntersectFRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_FRect * ___a = (const SDL_FRect *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];
  SDL_FRect * ___c = (SDL_FRect *) regarray[REG68K_A2/4];

  return _iface->SDL_IntersectFRect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectFRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IntersectFRectPPC };

void SDL_UnionFRect(const SDL_FRect * ___a, const SDL_FRect * ___b, SDL_FRect * ___c);

void
SDL2Gate_SDL_UnionFRect(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     const SDL_FRect * ___b,
     SDL_FRect * ___c)
{
  return SDL_UnionFRect(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_UnionFRectPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_FRect * ___a = (const SDL_FRect *) regarray[REG68K_A0/4];
  const SDL_FRect * ___b = (const SDL_FRect *) regarray[REG68K_A1/4];
  SDL_FRect * ___c = (SDL_FRect *) regarray[REG68K_A2/4];

  return _iface->SDL_UnionFRect(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_UnionFRect = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_UnionFRectPPC };

SDL_bool SDL_EncloseFPoints(const SDL_FPoint * ___a, int ___b, const SDL_FRect * ___c, SDL_FRect * ___d);

SDL_bool
SDL2Gate_SDL_EncloseFPoints(struct SDL2IFace* _iface,
     const SDL_FPoint * ___a,
     int ___b,
     const SDL_FRect * ___c,
     SDL_FRect * ___d)
{
  return SDL_EncloseFPoints(___a, ___b, ___c, ___d);
}

STATIC SDL_bool 
SDL2Gate_SDL_EncloseFPointsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_FPoint * ___a = (const SDL_FPoint *) regarray[REG68K_A0/4];
  int ___b = (int) regarray[REG68K_D0/4];
  const SDL_FRect * ___c = (const SDL_FRect *) regarray[REG68K_A1/4];
  SDL_FRect * ___d = (SDL_FRect *) regarray[REG68K_A2/4];

  return _iface->SDL_EncloseFPoints(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_EncloseFPoints = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_EncloseFPointsPPC };

SDL_bool SDL_IntersectFRectAndLine(const SDL_FRect * ___a, float * ___b, float * ___c, float * ___d, float * ___e);

SDL_bool
SDL2Gate_SDL_IntersectFRectAndLine(struct SDL2IFace* _iface,
     const SDL_FRect * ___a,
     float * ___b,
     float * ___c,
     float * ___d,
     float * ___e)
{
  return SDL_IntersectFRectAndLine(___a, ___b, ___c, ___d, ___e);
}

STATIC SDL_bool 
SDL2Gate_SDL_IntersectFRectAndLinePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_FRect * ___a = (const SDL_FRect *) regarray[REG68K_A0/4];
  float * ___b = (float *) regarray[REG68K_A1/4];
  float * ___c = (float *) regarray[REG68K_A2/4];
  float * ___d = (float *) regarray[REG68K_A3/4];
  float * ___e = (float *) regarray[REG68K_D0/4];

  return _iface->SDL_IntersectFRectAndLine(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_IntersectFRectAndLine = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_IntersectFRectAndLinePPC };

SDL_Window* SDL_RenderGetWindow(SDL_Renderer * ___a);

SDL_Window*
SDL2Gate_SDL_RenderGetWindow(struct SDL2IFace* _iface,
     SDL_Renderer * ___a)
{
  return SDL_RenderGetWindow(___a);
}

STATIC SDL_Window* 
SDL2Gate_SDL_RenderGetWindowPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Renderer * ___a = (SDL_Renderer *) regarray[REG68K_A0/4];

  return _iface->SDL_RenderGetWindow(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_RenderGetWindow = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_RenderGetWindowPPC };

void* SDL_bsearch(const void * ___a, const void * ___b, size_t ___c, size_t ___d, SDL_CompareCallback ___e);

void*
SDL2Gate_SDL_bsearch(struct SDL2IFace* _iface,
     const void * ___a,
     const void * ___b,
     size_t ___c,
     size_t ___d,
     SDL_CompareCallback ___e)
{
  return SDL_bsearch(___a, ___b, ___c, ___d, ___e);
}

STATIC void* 
SDL2Gate_SDL_bsearchPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const void * ___a = (const void *) regarray[REG68K_A0/4];
  const void * ___b = (const void *) regarray[REG68K_A1/4];
  size_t ___c = (size_t) regarray[REG68K_D0/4];
  size_t ___d = (size_t) regarray[REG68K_D1/4];
  SDL_CompareCallback ___e = (SDL_CompareCallback) regarray[REG68K_D2/4];

  return _iface->SDL_bsearch(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_bsearch = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_bsearchPPC };

const char* SDL_GameControllerPathForIndex(int ___a);

const char*
SDL2Gate_SDL_GameControllerPathForIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_GameControllerPathForIndex(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerPathForIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GameControllerPathForIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerPathForIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerPathForIndexPPC };

const char* SDL_GameControllerPath(SDL_GameController * ___a);

const char*
SDL2Gate_SDL_GameControllerPath(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerPath(___a);
}

STATIC const char* 
SDL2Gate_SDL_GameControllerPathPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerPath(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerPath = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerPathPPC };

const char* SDL_JoystickPathForIndex(int ___a);

const char*
SDL2Gate_SDL_JoystickPathForIndex(struct SDL2IFace* _iface,
     int ___a)
{
  return SDL_JoystickPathForIndex(___a);
}

STATIC const char* 
SDL2Gate_SDL_JoystickPathForIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  int ___a = (int) regarray[REG68K_D0/4];

  return _iface->SDL_JoystickPathForIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickPathForIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickPathForIndexPPC };

const char* SDL_JoystickPath(SDL_Joystick * ___a);

const char*
SDL2Gate_SDL_JoystickPath(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickPath(___a);
}

STATIC const char* 
SDL2Gate_SDL_JoystickPathPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickPath(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickPath = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickPathPPC };

int SDL_JoystickAttachVirtualEx(const SDL_VirtualJoystickDesc * ___a);

int
SDL2Gate_SDL_JoystickAttachVirtualEx(struct SDL2IFace* _iface,
     const SDL_VirtualJoystickDesc * ___a)
{
  return SDL_JoystickAttachVirtualEx(___a);
}

STATIC int 
SDL2Gate_SDL_JoystickAttachVirtualExPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_VirtualJoystickDesc * ___a = (const SDL_VirtualJoystickDesc *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickAttachVirtualEx(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickAttachVirtualEx = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickAttachVirtualExPPC };

Uint16 SDL_GameControllerGetFirmwareVersion(SDL_GameController * ___a);

Uint16
SDL2Gate_SDL_GameControllerGetFirmwareVersion(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetFirmwareVersion(___a);
}

STATIC Uint16 
SDL2Gate_SDL_GameControllerGetFirmwareVersionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetFirmwareVersion(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetFirmwareVersion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetFirmwareVersionPPC };

Uint16 SDL_JoystickGetFirmwareVersion(SDL_Joystick * ___a);

Uint16
SDL2Gate_SDL_JoystickGetFirmwareVersion(struct SDL2IFace* _iface,
     SDL_Joystick * ___a)
{
  return SDL_JoystickGetFirmwareVersion(___a);
}

STATIC Uint16 
SDL2Gate_SDL_JoystickGetFirmwareVersionPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Joystick * ___a = (SDL_Joystick *) regarray[REG68K_A0/4];

  return _iface->SDL_JoystickGetFirmwareVersion(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_JoystickGetFirmwareVersion = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_JoystickGetFirmwareVersionPPC };

SDL_bool SDL_HasLSX(void);

SDL_bool
SDL2Gate_SDL_HasLSX(struct SDL2IFace* _iface)
{
  return SDL_HasLSX();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasLSXPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasLSX();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasLSX = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasLSXPPC };

SDL_bool SDL_HasLASX(void);

SDL_bool
SDL2Gate_SDL_HasLASX(struct SDL2IFace* _iface)
{
  return SDL_HasLASX();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasLASXPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasLASX();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasLASX = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasLASXPPC };

size_t SDL_utf8strnlen(const char * ___a, size_t ___b);

size_t
SDL2Gate_SDL_utf8strnlen(struct SDL2IFace* _iface,
     const char * ___a,
     size_t ___b)
{
  return SDL_utf8strnlen(___a, ___b);
}

STATIC size_t 
SDL2Gate_SDL_utf8strnlenPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  size_t ___b = (size_t) regarray[REG68K_D0/4];

  return _iface->SDL_utf8strnlen(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_utf8strnlen = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_utf8strnlenPPC };

void SDL_GetOriginalMemoryFunctions(SDL_malloc_func * ___a, SDL_calloc_func * ___b, SDL_realloc_func * ___c, SDL_free_func * ___d);

void
SDL2Gate_SDL_GetOriginalMemoryFunctions(struct SDL2IFace* _iface,
     SDL_malloc_func * ___a,
     SDL_calloc_func * ___b,
     SDL_realloc_func * ___c,
     SDL_free_func * ___d)
{
  return SDL_GetOriginalMemoryFunctions(___a, ___b, ___c, ___d);
}

STATIC void 
SDL2Gate_SDL_GetOriginalMemoryFunctionsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_malloc_func * ___a = (SDL_malloc_func *) regarray[REG68K_A0/4];
  SDL_calloc_func * ___b = (SDL_calloc_func *) regarray[REG68K_A1/4];
  SDL_realloc_func * ___c = (SDL_realloc_func *) regarray[REG68K_A2/4];
  SDL_free_func * ___d = (SDL_free_func *) regarray[REG68K_A3/4];

  return _iface->SDL_GetOriginalMemoryFunctions(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetOriginalMemoryFunctions = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetOriginalMemoryFunctionsPPC };

void SDL_ResetKeyboard(void);

void
SDL2Gate_SDL_ResetKeyboard(struct SDL2IFace* _iface)
{
  return SDL_ResetKeyboard();
}

STATIC void 
SDL2Gate_SDL_ResetKeyboardPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ResetKeyboard();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ResetKeyboard = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ResetKeyboardPPC };

int SDL_GetDefaultAudioInfo(char * * ___a, SDL_AudioSpec * ___b, int ___c);

int
SDL2Gate_SDL_GetDefaultAudioInfo(struct SDL2IFace* _iface,
     char * * ___a,
     SDL_AudioSpec * ___b,
     int ___c)
{
  return SDL_GetDefaultAudioInfo(___a, ___b, ___c);
}

STATIC int 
SDL2Gate_SDL_GetDefaultAudioInfoPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  char * * ___a = (char * *) regarray[REG68K_A0/4];
  SDL_AudioSpec * ___b = (SDL_AudioSpec *) regarray[REG68K_A1/4];
  int ___c = (int) regarray[REG68K_D0/4];

  return _iface->SDL_GetDefaultAudioInfo(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetDefaultAudioInfo = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetDefaultAudioInfoPPC };

int SDL_GetPointDisplayIndex(const SDL_Point * ___a);

int
SDL2Gate_SDL_GetPointDisplayIndex(struct SDL2IFace* _iface,
     const SDL_Point * ___a)
{
  return SDL_GetPointDisplayIndex(___a);
}

STATIC int 
SDL2Gate_SDL_GetPointDisplayIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Point * ___a = (const SDL_Point *) regarray[REG68K_A0/4];

  return _iface->SDL_GetPointDisplayIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPointDisplayIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPointDisplayIndexPPC };

int SDL_GetRectDisplayIndex(const SDL_Rect * ___a);

int
SDL2Gate_SDL_GetRectDisplayIndex(struct SDL2IFace* _iface,
     const SDL_Rect * ___a)
{
  return SDL_GetRectDisplayIndex(___a);
}

STATIC int 
SDL2Gate_SDL_GetRectDisplayIndexPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const SDL_Rect * ___a = (const SDL_Rect *) regarray[REG68K_A0/4];

  return _iface->SDL_GetRectDisplayIndex(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetRectDisplayIndex = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetRectDisplayIndexPPC };

SDL_bool SDL_ResetHint(const char * ___a);

SDL_bool
SDL2Gate_SDL_ResetHint(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_ResetHint(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_ResetHintPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_ResetHint(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ResetHint = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ResetHintPPC };

Uint16 SDL_crc16(Uint16 ___a, const void * ___b, size_t ___c);

Uint16
SDL2Gate_SDL_crc16(struct SDL2IFace* _iface,
     Uint16 ___a,
     const void * ___b,
     size_t ___c)
{
  return SDL_crc16(___a, ___b, ___c);
}

STATIC Uint16 
SDL2Gate_SDL_crc16PPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  Uint16 ___a = (Uint16) regarray[REG68K_D0/4];
  const void * ___b = (const void *) regarray[REG68K_A0/4];
  size_t ___c = (size_t) regarray[REG68K_D1/4];

  return _iface->SDL_crc16(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_crc16 = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_crc16PPC };

void SDL_GetWindowSizeInPixels(SDL_Window * ___a, int * ___b, int * ___c);

void
SDL2Gate_SDL_GetWindowSizeInPixels(struct SDL2IFace* _iface,
     SDL_Window * ___a,
     int * ___b,
     int * ___c)
{
  return SDL_GetWindowSizeInPixels(___a, ___b, ___c);
}

STATIC void 
SDL2Gate_SDL_GetWindowSizeInPixelsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];
  int * ___b = (int *) regarray[REG68K_A1/4];
  int * ___c = (int *) regarray[REG68K_A2/4];

  return _iface->SDL_GetWindowSizeInPixels(___a, ___b, ___c);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetWindowSizeInPixels = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetWindowSizeInPixelsPPC };

int SDL_SetPrimarySelectionText(const char * ___a);

int
SDL2Gate_SDL_SetPrimarySelectionText(struct SDL2IFace* _iface,
     const char * ___a)
{
  return SDL_SetPrimarySelectionText(___a);
}

STATIC int 
SDL2Gate_SDL_SetPrimarySelectionTextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];

  return _iface->SDL_SetPrimarySelectionText(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SetPrimarySelectionText = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SetPrimarySelectionTextPPC };

char* SDL_GetPrimarySelectionText(void);

char*
SDL2Gate_SDL_GetPrimarySelectionText(struct SDL2IFace* _iface)
{
  return SDL_GetPrimarySelectionText();
}

STATIC char* 
SDL2Gate_SDL_GetPrimarySelectionTextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_GetPrimarySelectionText();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GetPrimarySelectionText = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GetPrimarySelectionTextPPC };

SDL_bool SDL_HasPrimarySelectionText(void);

SDL_bool
SDL2Gate_SDL_HasPrimarySelectionText(struct SDL2IFace* _iface)
{
  return SDL_HasPrimarySelectionText();
}

STATIC SDL_bool 
SDL2Gate_SDL_HasPrimarySelectionTextPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_HasPrimarySelectionText();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasPrimarySelectionText = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasPrimarySelectionTextPPC };

int SDL_GameControllerGetSensorDataWithTimestamp(SDL_GameController * ___a, SDL_SensorType ___b, Uint64 * ___c, float * ___d, int ___e);

int
SDL2Gate_SDL_GameControllerGetSensorDataWithTimestamp(struct SDL2IFace* _iface,
     SDL_GameController * ___a,
     SDL_SensorType ___b,
     Uint64 * ___c,
     float * ___d,
     int ___e)
{
  return SDL_GameControllerGetSensorDataWithTimestamp(___a, ___b, ___c, ___d, ___e);
}

STATIC int 
SDL2Gate_SDL_GameControllerGetSensorDataWithTimestampPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];
  SDL_SensorType ___b = (SDL_SensorType) regarray[REG68K_D0/4];
  Uint64 * ___c = (Uint64 *) regarray[REG68K_A1/4];
  float * ___d = (float *) regarray[REG68K_A2/4];
  int ___e = (int) regarray[REG68K_D1/4];

  return _iface->SDL_GameControllerGetSensorDataWithTimestamp(___a, ___b, ___c, ___d, ___e);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSensorDataWithTimestamp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetSensorDataWithTimestampPPC };

int SDL_SensorGetDataWithTimestamp(SDL_Sensor * ___a, Uint64 * ___b, float * ___c, int ___d);

int
SDL2Gate_SDL_SensorGetDataWithTimestamp(struct SDL2IFace* _iface,
     SDL_Sensor * ___a,
     Uint64 * ___b,
     float * ___c,
     int ___d)
{
  return SDL_SensorGetDataWithTimestamp(___a, ___b, ___c, ___d);
}

STATIC int 
SDL2Gate_SDL_SensorGetDataWithTimestampPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Sensor * ___a = (SDL_Sensor *) regarray[REG68K_A0/4];
  Uint64 * ___b = (Uint64 *) regarray[REG68K_A1/4];
  float * ___c = (float *) regarray[REG68K_A2/4];
  int ___d = (int) regarray[REG68K_D0/4];

  return _iface->SDL_SensorGetDataWithTimestamp(___a, ___b, ___c, ___d);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_SensorGetDataWithTimestamp = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_SensorGetDataWithTimestampPPC };

void SDL_ResetHints(void);

void
SDL2Gate_SDL_ResetHints(struct SDL2IFace* _iface)
{
  return SDL_ResetHints();
}

STATIC void 
SDL2Gate_SDL_ResetHintsPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;

  return _iface->SDL_ResetHints();
}

CONST struct EmuTrap m68kSDL2Gate_SDL_ResetHints = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_ResetHintsPPC };

char* SDL_strcasestr(const char * ___a, const char * ___b);

char*
SDL2Gate_SDL_strcasestr(struct SDL2IFace* _iface,
     const char * ___a,
     const char * ___b)
{
  return SDL_strcasestr(___a, ___b);
}

STATIC char* 
SDL2Gate_SDL_strcasestrPPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  const char * ___a = (const char *) regarray[REG68K_A0/4];
  const char * ___b = (const char *) regarray[REG68K_A1/4];

  return _iface->SDL_strcasestr(___a, ___b);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_strcasestr = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_strcasestrPPC };

SDL_bool SDL_HasWindowSurface(SDL_Window * ___a);

SDL_bool
SDL2Gate_SDL_HasWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_HasWindowSurface(___a);
}

STATIC SDL_bool 
SDL2Gate_SDL_HasWindowSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_HasWindowSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_HasWindowSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_HasWindowSurfacePPC };

int SDL_DestroyWindowSurface(SDL_Window * ___a);

int
SDL2Gate_SDL_DestroyWindowSurface(struct SDL2IFace* _iface,
     SDL_Window * ___a)
{
  return SDL_DestroyWindowSurface(___a);
}

STATIC int 
SDL2Gate_SDL_DestroyWindowSurfacePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_Window * ___a = (SDL_Window *) regarray[REG68K_A0/4];

  return _iface->SDL_DestroyWindowSurface(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_DestroyWindowSurface = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_DestroyWindowSurfacePPC };

Uint64 SDL_GameControllerGetSteamHandle(SDL_GameController * ___a);

Uint64
SDL2Gate_SDL_GameControllerGetSteamHandle(struct SDL2IFace* _iface,
     SDL_GameController * ___a)
{
  return SDL_GameControllerGetSteamHandle(___a);
}

STATIC Uint64 
SDL2Gate_SDL_GameControllerGetSteamHandlePPC(ULONG *regarray)
{
  struct Library * _base = (struct Library *) regarray[REG68K_A6/4];
  struct ExtendedLibrary * ExtLib = (struct ExtendedLibrary *) ((ULONG) _base + _base->lib_PosSize);
  struct SDL2IFace* _iface = (struct SDL2IFace*) ExtLib->MainIFace;
  SDL_GameController * ___a = (SDL_GameController *) regarray[REG68K_A0/4];

  return _iface->SDL_GameControllerGetSteamHandle(___a);
}

CONST struct EmuTrap m68kSDL2Gate_SDL_GameControllerGetSteamHandle = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *)) SDL2Gate_SDL_GameControllerGetSteamHandlePPC };


#ifdef __cplusplus
}
#endif /* __cplusplus */

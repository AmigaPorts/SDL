/*
  SDL2 Joystick -- AmigaOS 3.x (gameport.device)
  Phase 0: Stub -- reports 0 joysticks.
  Phase 5: Real gameport.device polling.
*/

#include "../../SDL_internal.h"

#if SDL_JOYSTICK_AMIGAOS3

#include "SDL_joystick.h"
#include "../SDL_sysjoystick.h"
#include "../SDL_joystick_c.h"

static int OS3_JoystickInit(void) { return 0; }
static int OS3_JoystickGetCount(void) { return 0; }
static void OS3_JoystickDetect(void) { }
static const char *OS3_JoystickGetDeviceName(int index) { return NULL; }
static const char *OS3_JoystickGetDevicePath(int index) { return NULL; }
static int OS3_JoystickGetDeviceSteamVirtualGamepadSlot(int index) { return -1; }
static int OS3_JoystickGetDevicePlayerIndex(int index) { return -1; }
static void OS3_JoystickSetDevicePlayerIndex(int index, int player) { }
static SDL_JoystickGUID OS3_JoystickGetDeviceGUID(int index)
{
    SDL_JoystickGUID guid;
    SDL_zero(guid);
    return guid;
}
static SDL_JoystickID OS3_JoystickGetDeviceInstanceID(int index) { return -1; }
static int OS3_JoystickOpen(SDL_Joystick *joy, int index) { return SDL_SetError("No joystick"); }
static int OS3_JoystickRumble(SDL_Joystick *joy, Uint16 lo, Uint16 hi) { return SDL_Unsupported(); }
static int OS3_JoystickRumbleTriggers(SDL_Joystick *joy, Uint16 lo, Uint16 hi) { return SDL_Unsupported(); }
static Uint32 OS3_JoystickGetCapabilities(SDL_Joystick *joy) { return 0; }
static int OS3_JoystickSetLED(SDL_Joystick *joy, Uint8 r, Uint8 g, Uint8 b) { return SDL_Unsupported(); }
static int OS3_JoystickSendEffect(SDL_Joystick *joy, const void *data, int size) { return SDL_Unsupported(); }
static int OS3_JoystickSetSensorsEnabled(SDL_Joystick *joy, SDL_bool enabled) { return SDL_Unsupported(); }
static void OS3_JoystickUpdate(SDL_Joystick *joy) { }
static void OS3_JoystickClose(SDL_Joystick *joy) { }
static void OS3_JoystickQuit(void) { }
static SDL_bool OS3_JoystickGetGamepadMapping(int index, SDL_GamepadMapping *out) { return SDL_FALSE; }

SDL_JoystickDriver SDL_AMIGAOS3_JoystickDriver = {
    OS3_JoystickInit,
    OS3_JoystickGetCount,
    OS3_JoystickDetect,
    OS3_JoystickGetDeviceName,
    OS3_JoystickGetDevicePath,
    OS3_JoystickGetDeviceSteamVirtualGamepadSlot,
    OS3_JoystickGetDevicePlayerIndex,
    OS3_JoystickSetDevicePlayerIndex,
    OS3_JoystickGetDeviceGUID,
    OS3_JoystickGetDeviceInstanceID,
    OS3_JoystickOpen,
    OS3_JoystickRumble,
    OS3_JoystickRumbleTriggers,
    OS3_JoystickGetCapabilities,
    OS3_JoystickSetLED,
    OS3_JoystickSendEffect,
    OS3_JoystickSetSensorsEnabled,
    OS3_JoystickUpdate,
    OS3_JoystickClose,
    OS3_JoystickQuit,
    OS3_JoystickGetGamepadMapping
};

#endif /* SDL_JOYSTICK_AMIGAOS3 */

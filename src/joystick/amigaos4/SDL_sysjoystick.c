/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "SDL_internal.h"

#if defined(SDL_JOYSTICK_AMIGAINPUT)

#include "../SDL_sysjoystick.h"
#include "../SDL_joystick_c.h"
#include "../../video/amigaos4/SDL_os4library.h"

#include <amigainput/amigainput.h>
#include <proto/amigainput.h>

#include "../../main/amigaos4/SDL_os4debug.h"

#define MAX_AXES 8
#define MAX_BUTTONS 16
#define MAX_HATS 8

#define BUFFER_OFFSET(buffer, offset) (((int32 *)buffer)[offset])

// Per-joystick data private to driver
struct joystick_hwdata
{
    AIN_DeviceHandle   *handle;

    uint32              axisBufferOffset[MAX_AXES];
    int32               axisData[MAX_AXES];
    TEXT                axisName[MAX_AXES][32];

    uint32              buttonBufferOffset[MAX_BUTTONS];
    int32               buttonData[MAX_BUTTONS];

    uint32              hatBufferOffset[MAX_HATS];
    int32               hatData[MAX_HATS];
};

struct SDL_JoystickDeviceData
{
    AIN_DeviceID id;
};

struct JoystickData
{
    APTR context;
    uint32 count;
};

// TODO: get rid of static data
static struct JoystickData joystickData;

static struct Library   *SDL_AIN_Base;
static struct AIN_IFace *SDL_IAIN;

// Convert AmigaInput hat data to SDL hat data.
static Uint8
AMIGAINPUT_MapHatData(const int hat_data)
{
    switch (hat_data) {
        case 1:  return SDL_HAT_UP;
        case 2:  return SDL_HAT_UP | SDL_HAT_RIGHT;
        case 3:  return SDL_HAT_RIGHT;
        case 4:  return SDL_HAT_DOWN | SDL_HAT_RIGHT;
        case 5:  return SDL_HAT_DOWN;
        case 6:  return SDL_HAT_DOWN | SDL_HAT_LEFT;
        case 7:  return SDL_HAT_LEFT;
        case 8:  return SDL_HAT_UP | SDL_HAT_LEFT;
        default: return SDL_HAT_CENTERED;
    }
}

static SDL_GUID
AMIGAINPUT_MakeGuid(const char* const name)
{
    Uint16 vendor = 0;
    Uint16 product = 0;
    Uint16 version = 0;
    Uint8 signature = 0;
    Uint8 data = 0;
    const char *vendorName = NULL;

    return SDL_CreateJoystickGUID(SDL_HARDWARE_BUS_USB,
                                  vendor,
                                  product,
                                  version,
                                  vendorName,
                                  name,
                                  signature,
                                  data);
}

static BOOL
AMIGAINPUT_EnumerateJoysticks(AIN_Device *device, void *UserData)
{
    dprintf("Name '%s', type %lu, subtype %lu, buttons %lu, axes %lu, hats %lu, device id %lu\n",
            device->DeviceName,
            device->Type,
            device->SubType,
            device->NumButtons,
            device->NumAxes,
            device->NumHats,
            device->DeviceID);

    if (device->Type != AINDT_JOYSTICK) {
        dprintf("Not a joystick\n");
        return FALSE;
    }

    if (device->NumAxes == 0) {
        dprintf("Not enough axes\n");
        return FALSE;
    }

    if (device->NumButtons == 0) {
        dprintf("Not enough buttons\n");
        return FALSE;
    }

    AIN_DeviceHandle *handle = SDL_IAIN->AIN_ObtainDevice(joystickData.context, device->DeviceID);

    if (!handle) {
        dprintf("Failed to obtain joystick '%s' (device id %lu) - ignoring\n", device->DeviceName, device->DeviceID);
        return FALSE;
    }

    SDL_JoystickDevice *joystickDevice = SDL_CreateJoystickDevice(&SDL_AMIGAINPUT_JoystickDriver, sizeof(AIN_DeviceID));

    if (joystickDevice) {
        SDL_JoystickDeviceData *data = (SDL_JoystickDeviceData *)(joystickDevice + 1);
        data->id = device->DeviceID;
        joystickDevice->internal = data;
        joystickDevice->name = SDL_strdup(device->DeviceName);
        joystickDevice->guid = AMIGAINPUT_MakeGuid(joystickDevice->name);

#ifdef DEBUG
        const SDL_JoystickID id =
#endif
              SDL_AddJoystickDevice(joystickDevice);
        dprintf("Added joystick %u (device id %lu) '%s'\n", id, data->id, joystickDevice->name);

        joystickData.count++;
    } else {
        dprintf("Failed to create joystick device\n");
    }

    SDL_IAIN->AIN_ReleaseDevice(joystickData.context, handle);

    return TRUE;
}

static BOOL
AMIGAINPUT_OpenLibrary(void)
{
    dprintf("Called\n");

    SDL_AIN_Base = OS4_OpenLibrary("AmigaInput.library", 53);

    if (SDL_AIN_Base) {
        SDL_IAIN = (struct AIN_IFace *)OS4_GetInterface(SDL_AIN_Base);

        if (!SDL_IAIN) {
            OS4_CloseLibrary(&SDL_AIN_Base);
        }
    } else {
        dprintf("Failed to open AmigaInput.library\n");
    }

    return SDL_AIN_Base != NULL;
}

static void
AMIGAINPUT_CloseLibrary(void)
{
    dprintf("Called\n");

    OS4_DropInterface((void *)&SDL_IAIN);
    OS4_CloseLibrary(&SDL_AIN_Base);
}

static bool
AMIGAINPUT_Init(void)
{
    if (!AMIGAINPUT_OpenLibrary()) {
        return SDL_SetError("Failed to open AmigaInput library");
    }

    joystickData.context = SDL_IAIN->AIN_CreateContext(1, NULL);

    if (!joystickData.context) {
        return SDL_SetError("Failed to create AmigaInput context");
    }

    // NOTE: AmigaInput doesn't seem to handle hotplugged/removed joysticks very well.
    // Report only devices detected at startup to SDL.

#ifdef DEBUG
    const BOOL result =
#endif
        SDL_IAIN->AIN_EnumDevices(joystickData.context, AMIGAINPUT_EnumerateJoysticks, NULL);

    dprintf("EnumDevices returned %d\n", result);
    dprintf("Found %lu joysticks\n", joystickData.count);

    return true;
}

static void
AMIGAINPUT_SwapAxis(struct joystick_hwdata * hwdata, int a, int b)
{
    // Back up the original position axis data
    TEXT tmpstr[32];
    const uint32 tmpoffset = hwdata->axisBufferOffset[a];
    strlcpy(tmpstr, hwdata->axisName[a], sizeof(tmpstr));

    // Move this one to original
    hwdata->axisBufferOffset[a] = hwdata->axisBufferOffset[b];
    strlcpy(hwdata->axisName[a], hwdata->axisName[b], 32);

    // Put the old original here
    hwdata->axisBufferOffset[b] = tmpoffset;
    strlcpy(hwdata->axisName[b], tmpstr, 32);
}

static bool
AMIGAINPUT_Open(SDL_Joystick *joystick, SDL_JoystickDevice *device)
{
    const SDL_JoystickDeviceData *data = (SDL_JoystickDeviceData *)(device + 1);
    const AIN_DeviceID id = data->id;
    AIN_DeviceHandle *handle = SDL_IAIN->AIN_ObtainDevice(joystickData.context, id);

    dprintf("Opening joystick %d (device id %lu) '%s'\n", joystick->instance_id, id, device->name);

    if (!handle) {
        return SDL_SetError("Failed to open device");
    }

    joystick->hwdata = SDL_calloc(1, sizeof(struct joystick_hwdata));

    if (!joystick->hwdata) {
        SDL_IAIN->AIN_ReleaseDevice(joystickData.context, handle);
        return SDL_OutOfMemory();
    }

    struct joystick_hwdata *hwdata = joystick->hwdata;
    uint32 num_axes = 0;
    uint32 num_buttons = 0;
    uint32 num_hats = 0;

    BOOL result = TRUE;

    hwdata->handle = handle;

    result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_NUMAXES,    0, &num_axes, 4);
    result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_NUMBUTTONS, 0, &num_buttons, 4);
    result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_NUMHATS,    0, &num_hats, 4);

    // dprintf ("Found %d axes, %d buttons, %d hats\n", num_axes, num_buttons, num_hats);

    joystick->naxes    = num_axes < MAX_AXES       ? num_axes    : MAX_AXES;
    joystick->nbuttons = num_buttons < MAX_BUTTONS ? num_buttons : MAX_BUTTONS;
    joystick->nhats    = num_hats < MAX_HATS       ? num_hats    : MAX_HATS;

    // Ensure all axis names are null terminated
    for (int i = 0; i < MAX_AXES; i++) {
        hwdata->axisName[i][0] = 0;
    }

    // Query offsets in ReadDevice buffer for axes' data
    for (int i = 0; i < joystick->naxes; i++) {
        result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_AXIS_OFFSET, i, &(hwdata->axisBufferOffset[i]), 4);
        result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_AXISNAME,    i, &(hwdata->axisName[i][0]), 32 );
    }

    // Sort the axes so that X and Y come first
    for (int i = 0; i < joystick->naxes; i++) {
        if ((strcasecmp(&hwdata->axisName[i][0], "X-Axis") == 0) && (i != 0)) {
            dprintf("Swap X-axis\n");
            AMIGAINPUT_SwapAxis(hwdata, 0, i);
            continue;
        }

        if ((strcasecmp(&hwdata->axisName[i][0], "Y-Axis") == 0) && (i != 1)) {
            dprintf("Swap Y-axis\n");
            AMIGAINPUT_SwapAxis(hwdata, 1, i);
            continue;
        }
    }

    // Query offsets in ReadDevice buffer for buttons' data
    for (int i = 0; i < joystick->nbuttons; i++) {
        result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_BUTTON_OFFSET, i, &(hwdata->buttonBufferOffset[i]), 4);
    }

    // Query offsets in ReadDevice buffer for hats' data
    for (int i = 0; i < joystick->nhats; i++) {
        result = result && SDL_IAIN->AIN_Query(joystickData.context, id, AINQ_HAT_OFFSET, i, &(hwdata->hatBufferOffset[i]), 4);
    }

    if (!result) {
        SDL_IAIN->AIN_ReleaseDevice(joystickData.context, handle);
        return SDL_SetError("Failed to query joystick data");
    }

    dprintf("Successful\n");
    return true;
}

static void
AMIGAINPUT_Update(SDL_Joystick *joystick)
{
    struct joystick_hwdata *hwdata = joystick->hwdata;
    void                   *buffer;

    //dprintf("Called joystick %p, hwdata %p\n", joystick, hwdata);

    if (!hwdata) {
        dprintf("No hwdata\n");
        return;
    }

    // Poll device for data

    if (!SDL_IAIN->AIN_ReadDevice(joystickData.context, hwdata->handle, &buffer)) {
        dprintf("Read device failed\n");
        return;
    }

    const Uint64 timestamp = SDL_GetTicksNS();

    // Extract axis data from buffer and notify SDL of any changes in axis state
    for (int i = 0; i < joystick->naxes; i++) {
        int axisdata = BUFFER_OFFSET(buffer, hwdata->axisBufferOffset[i]);

        // Clamp axis data to 16-bits to work around possible AI driver bugs
        if (axisdata > 32767) {
            axisdata = 32767;
        }

        if (axisdata < -32768) {
            axisdata = -32768;
        }

        if (axisdata != hwdata->axisData[i]) {
            SDL_SendJoystickAxis(timestamp, joystick, i, (Sint16)axisdata);
            hwdata->axisData[i] = axisdata;
            //dprintf("Send axis %d\n", i);
        }
    }

    // Extract button data from buffer and notify SDL of any changes in button state
    //
    // Note: SDL doesn't support analog buttons.
    for (int i = 0; i < joystick->nbuttons; i++) {
        const int buttondata = BUFFER_OFFSET(buffer, hwdata->buttonBufferOffset[i]);

        if (buttondata != hwdata->buttonData[i]) {
            SDL_SendJoystickButton(timestamp, joystick, i, buttondata ? true : false);
            hwdata->buttonData[i] = buttondata;
            //dprintf("Send button %d\n", i);
        }
    }

    // Extract hat data from buffer and notify SDL of any changes in hat state
    for (int i = 0; i < joystick->nhats; i++) {
        const int hatdata = BUFFER_OFFSET(buffer, hwdata->hatBufferOffset[i]);

        if (hatdata != hwdata->hatData[i]) {
            SDL_SendJoystickHat(timestamp, joystick, i, AMIGAINPUT_MapHatData(hatdata));
            hwdata->hatData[i] = hatdata;
            //dprintf("Send hat %d\n", i);
        }
    }
}

static void
AMIGAINPUT_Close(SDL_Joystick * joystick)
{
    dprintf("Closing joystick %d '%s'\n", joystick->instance_id, joystick->name);

    SDL_IAIN->AIN_ReleaseDevice(joystickData.context, joystick->hwdata->handle);

    SDL_free(joystick->hwdata);
    joystick->hwdata = NULL;
}

static void
AMIGAINPUT_Quit(void)
{
    joystickData.count = 0;

    if (joystickData.context) {
        SDL_IAIN->AIN_DeleteContext(joystickData.context);
        joystickData.context = NULL;
    }

    AMIGAINPUT_CloseLibrary();
}

SDL_JoystickDriver SDL_AMIGAINPUT_JoystickDriver =
{
    AMIGAINPUT_Init,
    NULL /* AMIGAINPUT_QueryDevices */,
    NULL /* AMIGAINPUT_DetectDevices */, // TODO: implement?
    NULL /* AMIGAINPUT_PrepareDevice */,
    NULL /* AMIGAINPUT_UpdateSteamVirtualGamepadSlot */,
    NULL /* AMIGAINPUT_GetGamepadMapping */,
    AMIGAINPUT_Open,
    NULL /* AMIGAINPUT_Rumble */,
    NULL /* AMIGAINPUT_RumbleTriggers */,
    NULL /* AMIGAINPUT_SetLED */,
    NULL /* AMIGAINPUT_SendEffect */,
    NULL /* AMIGAINPUT_SetSensorsEnabled */,
    NULL /* AMIGAINPUT_SetPlayerIndex */,
    AMIGAINPUT_Update,
    AMIGAINPUT_Close,
    AMIGAINPUT_Quit
};

#endif // SDL_JOYSTICK_AMIGAINPUT

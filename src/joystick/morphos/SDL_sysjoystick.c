/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2020 Sam Lantinga <slouken@libsdl.org>

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

#include "SDL_sysjoystick_c.h"

#ifdef SDL_JOYSTICK_MORPHOS

#include "../SDL_sysjoystick.h"
#include "../SDL_joystick_c.h"
#include "SDL_endian.h"
#include "SDL_joystick.h"

#include <dos/dos.h>
#include <exec/execbase.h>
#include <libraries/sensors.h>
#include <libraries/sensors_hid.h>
#include <proto/exec.h>
#define USE_INLINE_STDARG
#include <proto/sensors.h>
#undef USE_INLINE_STDARG
#include <proto/threadpool.h>
#include <proto/utility.h>

// SDL2 deadzone is around 409, we need 1638
#define DEADZONE_MIN (-0.05)
#define DEADZONE_MAX (0.05)

#define JOYSTICK_MIN -1.0
#define JOYSTICK_MAX 1.0

#define CLAMP(val) \
			(((val) <= (DEADZONE_MAX) && (val) >= (DEADZONE_MIN)) ? (0) : \
			((val) > (JOYSTICK_MAX)) ? (JOYSTICK_MAX) : (((val) < (JOYSTICK_MIN)) ? (JOYSTICK_MIN) : (val)))
//#define HOT_PLUG
#define MAX_JOYSTICKS 32

APTR sensorlist;
APTR JoySensor[MAX_JOYSTICKS];
int joystick_count;

static int SDL_SYS_JoystickGetCount(void)
{
	return joystick_count;
}

/* Function to scan the system for joysticks.
 * It should return 0, or -1 on an unrecoverable fatal error.
 */
static int
SDL_SYS_JoystickInit(void)
{
	int rc = -1;

	APTR sensor = NULL;
	ULONG count = 0;

	D("[%s] Obtain sensor list...\n", __FUNCTION__);
	sensorlist = ObtainSensorsListTags(SENSORS_Class, SensorClass_HID, /*SENSORS_Type, SensorType_HID_Gamepad,*/ TAG_DONE);
	while ((sensor = NextSensor(sensor, sensorlist, NULL)) && count < MAX_JOYSTICKS)
	{
		JoySensor[count++] = sensor;
	}

	D("[%s] Found %ld joysticks...\n", __FUNCTION__, count);
	joystick_count = count;
	rc = count;
	return rc;
}

static void
SDL_SYS_JoystickDetect(void)
{
}

/* Function to get the device-dependent name of a joystick */
static const char *
SDL_SYS_JoystickGetDeviceName(int device_index)
{
	APTR sensor = JoySensor[device_index];
	const char *name = NULL;
	GetSensorAttrTags(sensor, SENSORS_HID_Name, (IPTR)&name, TAG_DONE);
	return name;
}

/* Function to perform the mapping from device index to the instance id for this index */
static
SDL_JoystickID SDL_SYS_JoystickGetDeviceInstanceID(int device_index)
{
	return device_index;
}

/* Function to sort Sensors */
/*static int
SortSensorFunc(const void *a, const void *b)
{
	LONG ida = 0;
	LONG idb = 0;
	GetSensorAttrTags((APTR)a, SENSORS_HIDInput_ID, (IPTR)&ida, TAG_DONE);
	GetSensorAttrTags((APTR)b, SENSORS_HIDInput_ID, (IPTR)&idb, TAG_DONE);
	if (ida < idb)
		return -1;
	if (ida > idb)
		return 1;
	return 0;
}*/

/* Function to open a joystick for use.
   The joystick to open is specified by the index field of the joystick.
   This should fill the nbuttons and naxes fields of the joystick structure.
   It returns 0, or -1 if there is an error.
 */
static int
SDL_SYS_JoystickOpen(SDL_Joystick * joystick, int device_index)
{
	D("[%s]\n", __FUNCTION__);
	APTR sensor = JoySensor[device_index];
	int rc = -1;

	if (sensor) {
		size_t buttons = 0, naxes = 0, nhats = 0, nsticks = 0, nrumbles=0;
		CONST_STRPTR name = "<unknown>";
		//ULONG id;
		struct joystick_hwdata *hwdata = SDL_calloc(1, sizeof(*hwdata));

		hwdata->main_sensor = sensor;

		hwdata->child_sensors = ObtainSensorsListTags(
			SENSORS_Parent, (IPTR)hwdata->main_sensor,
			SENSORS_Class, SensorClass_HID,
			TAG_DONE);

		sensor = NULL;
		while ((sensor = NextSensor(sensor, hwdata->child_sensors, NULL))) {
			ULONG type = SensorType_HIDInput_Unknown, Limb, color;
			/*GetSensorAttrTags(sensor, 
								SENSORS_HIDInput_ID, (IPTR)&id, 
								SENSORS_HIDInput_Name, (IPTR)&name, 
								SENSORS_HIDInput_Limb, (IPTR)&Limb, 
								SENSORS_HIDInput_Color, (IPTR)&color, 
								TAG_DONE);
			D("[%s] sensor id: %d name: %s Limb:%d LimbName:%s color:%d\n", __FUNCTION__, id, name, Limb, color);	*/
			
			if (GetSensorAttrTags(sensor, SENSORS_Type, (IPTR)&type, TAG_DONE)) {
				switch (type) {
					case SensorType_HIDInput_Trigger:
						if (buttons < MAX_BUTTONS) {
							hwdata->button[buttons++] = sensor;
						}
						break;
					case SensorType_HIDInput_Stick:
						if (nhats < MAX_HATS) {
							hwdata->hat[nhats++] = sensor;
						}
						break;
					case SensorType_HIDInput_Analog:
					case SensorType_HIDInput_AnalogStick:
					case SensorType_HIDInput_3DStick:
						if (nsticks < MAX_STICKS) {
							hwdata->stick[nsticks] = sensor;
							hwdata->stickType[nsticks] = type;
							nsticks++;
							if (type == SensorType_HIDInput_AnalogStick)
								naxes += 2;
							else if (type == SensorType_HIDInput_3DStick)
								naxes += 4;
							else
								naxes++;
						}
						break;
					case SensorType_HIDInput_Rumble:
						if (nrumbles < MAX_RUMBLE) {
							GetSensorAttrTags(sensor, SENSORS_HID_Name, (IPTR)&name, TAG_DONE);
							D("[%s] Rumble SensorName: %s\n", __FUNCTION__, name);
							hwdata->rumble[nrumbles] = sensor;
							nrumbles++;
						}
						break;
					case SensorType_HIDInput_Battery:
						GetSensorAttrTags(sensor, SENSORS_HID_Name, (IPTR)&name, TAG_DONE);
						D("[%s] Battery SensorName: %s\n", __FUNCTION__, name);
					    // Force "Xbox360 Controller" (WIRED) to use SDL_JOYSTICK_POWER_WIRED
						if (strcmp((const char *)SDL_SYS_JoystickGetDeviceName(device_index),(const char *)"Xbox360 Controller") == 0) {
							SDL_PrivateJoystickBatteryLevel(joystick, SDL_JOYSTICK_POWER_WIRED);  
							hwdata->battery = NULL;
						} else {							
							hwdata->battery = sensor;
						}
						break;
					case SensorType_HIDInput_Knob:
						GetSensorAttrTags(sensor, SENSORS_HID_Name, (IPTR)&name, TAG_DONE);
						D("[%s] Knob SensorType: %d\n", __FUNCTION__, name);
						break;
					case SensorType_HIDInput_Wheel:
						GetSensorAttrTags(sensor, SENSORS_HID_Name, (IPTR)&name, TAG_DONE);
						D("[%s] Wheel SensorType: %d\n", __FUNCTION__, name);
						break;
					default:
						D("[%s] unknown SensorType: %d\n", __FUNCTION__, type);
						continue;
				}
			}
		}

#ifdef HOT_PLUG
		if ((hwdata->notifyPort = CreateMsgPort())) {
			hwdata->sensorsNotify = StartSensorNotifyTags(sensor,
				SENSORS_Notification_Destination, (IPTR)hwdata->notifyPort,
				SENSORS_Notification_UserData, (IPTR)SDL_SYS_JoystickGetDeviceInstanceID(device_index),
				SENSORS_Notification_Removed, TRUE,
				TAG_DONE);
		}
#endif

		joystick->naxes = naxes;
		joystick->nhats = nhats;
		joystick->nbuttons = buttons;
		//SDL_qsort(hwdata->button, joystick->nbuttons, sizeof(APTR), SortSensorFunc);
		hwdata->numSticks = nsticks;
		hwdata->numRumbles = nrumbles;
		joystick->hwdata = hwdata;
		joystick->name = (char *)SDL_SYS_JoystickGetDeviceName(device_index);
		rc = 0;
	}
	return rc;
}

static void
SDL_SYS_JoystickUpdate(SDL_Joystick * joystick)
{
	struct joystick_hwdata *hwdata = joystick->hwdata;
	int i, j;
	Sint16 sval;
	double btn_value, bt_value, x_value, y_value, z_value, ns_value, ew_value, z_rotation;

	for (i = 0; i < joystick->nbuttons; i++) {
		GetSensorAttrTags(hwdata->button[i], SENSORS_HIDInput_Value, (IPTR)&btn_value, TAG_DONE);
		if ((joystick->buttons[i] && btn_value == 0.0) || (joystick->buttons[i] == 0 && btn_value > 0.0)) {
			SDL_PrivateJoystickButton(joystick, i, btn_value == 0.0 ? 0 : 1);
		}
	}

	for (i = 0; i < joystick->nhats; i++) {
		GetSensorAttrTags(hwdata->hat[i],
			SENSORS_HIDInput_EW_Value, (IPTR)&ew_value,
			SENSORS_HIDInput_NS_Value, (IPTR)&ns_value,
			TAG_DONE);
		Uint8 value_hat = SDL_HAT_CENTERED;
		if (ns_value >= 1.0) {
			value_hat |= SDL_HAT_DOWN;
		} else if (ns_value <= -1.0) {
			value_hat |= SDL_HAT_UP;
		}
		if (ew_value >= 1.0) {
			value_hat |= SDL_HAT_RIGHT;
		} else if (ew_value <= -1.0) {
			value_hat |= SDL_HAT_LEFT;
		}
		SDL_PrivateJoystickHat(joystick, i, value_hat);
	}

	j = 0;
	for (i = 0; i < hwdata->numSticks; i++) {
		switch (hwdata->stickType[i]) {
			case SensorType_HIDInput_3DStick:
				GetSensorAttrTags(hwdata->stick[i],
					SENSORS_HIDInput_X_Index, (IPTR)&x_value,
					SENSORS_HIDInput_Y_Index, (IPTR)&y_value,
					SENSORS_HIDInput_Z_Index, (IPTR)&z_value,
					SENSORS_HIDInput_Z_Rotation, (IPTR)&z_rotation,
					TAG_DONE);

				sval = (Sint16)(CLAMP(x_value) * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j, sval);

				sval = (Sint16)(CLAMP(y_value) * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j+1, sval);

				sval = (Sint16)(CLAMP(z_value) * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j+2, sval);

				sval = (Sint16)(CLAMP(z_rotation) * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j+3, sval);
				
				j += 4;
				break;

			case SensorType_HIDInput_Analog:
				GetSensorAttrTags(hwdata->stick[i], SENSORS_HIDInput_Value, (IPTR)&btn_value, TAG_DONE);

				sval = (Sint16)(btn_value * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j, sval);

				j++;
				break;

			case SensorType_HIDInput_AnalogStick:
				GetSensorAttrTags(hwdata->stick[i],
					SENSORS_HIDInput_EW_Value, (IPTR)&ew_value,
					SENSORS_HIDInput_NS_Value, (IPTR)&ns_value,
					TAG_DONE);

				sval = (Sint16)(CLAMP(ew_value) * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j, sval);

				sval = (Sint16)(CLAMP(ns_value) * SDL_JOYSTICK_AXIS_MAX);
				SDL_PrivateJoystickAxis(joystick, j+1, sval);

				j += 2;
				break;
		}
	}
	
	if (hwdata->battery) {
	   SDL_JoystickPowerLevel ePowerLevel = SDL_JOYSTICK_POWER_UNKNOWN;
	   GetSensorAttrTags(hwdata->battery,
					SENSORS_HIDInput_Value, (IPTR)&bt_value,
					TAG_DONE);
	   ULONG level = bt_value*100;
	   switch (level)
	   {
		   case 0 ... 5:
			    ePowerLevel = SDL_JOYSTICK_POWER_EMPTY;
                break;
		   case 6 ... 20:
			   ePowerLevel = SDL_JOYSTICK_POWER_LOW;
		    	break;
		   case 21 ... 70:
			    ePowerLevel = SDL_JOYSTICK_POWER_MEDIUM;
		        break;
		   case 71 ... 100:
			    ePowerLevel = SDL_JOYSTICK_POWER_FULL;
		   		break;
	   }
        SDL_PrivateJoystickBatteryLevel(joystick, ePowerLevel);  
	}
	
#ifdef HOT_PLUG
	if (hwdata->notifyPort) {
		struct SensorsNotificationMessage *notifyMsg;
		while ((notifyMsg = (struct SensorsNotificationMessage *)GetMsg(hwdata->notifyPort))) {
			if (GetTagData(SENSORS_Notification_Removed, FALSE, notifyMsg->Notifications)) {
				SDL_PrivateJoystickRemoved((SDL_JoystickID)notifyMsg->UserData);
			}
			ReplyMsg(notifyMsg);
		}
	}
#endif
}

/* Function to close a joystick after use */
void
SDL_SYS_JoystickClose(SDL_Joystick * joystick)
{
	D("[%s]\n", __FUNCTION__);
	struct joystick_hwdata *hwdata = joystick->hwdata;
	if (hwdata) {
#ifdef HOT_PLUG
		if (hwdata->sensorsNotify) {
			EndSensorNotify(hwdata->sensorsNotify, NULL);
		}
		if (hwdata->notifyPort) {
			struct Message *notifyMsg;
			while ((notifyMsg = GetMsg(hwdata->notifyPort)))
				ReplyMsg(notifyMsg);
			DeleteMsgPort(hwdata->notifyPort);
		}
#endif
		ReleaseSensorsList(hwdata->child_sensors, NULL);
		SDL_free(hwdata);
		joystick->hwdata = NULL;
	}
}

/* Function to perform any system-specific joystick related cleanup */
static void
SDL_SYS_JoystickQuit(void)
{
	D("[%s]\n", __FUNCTION__);
	if (sensorlist)
		ReleaseSensorsList(sensorlist, NULL);
}

static SDL_JoystickGUID
SDL_SYS_JoystickGetDeviceGUID( int device_index )
{
	SDL_JoystickGUID guid;
	APTR sensor = JoySensor[device_index];
	Uint16 *guid16 = (Uint16 *)guid.data;
	const char *name = NULL;

	ULONG product, vendor;
	
	GetSensorAttrTags(sensor,
			SENSORS_HID_Name, (IPTR)&name,
			SENSORS_HID_Product, (IPTR)&product,
			SENSORS_HID_Vendor, (IPTR)&vendor,
			TAG_DONE);

	SDL_zero(guid);
	SDL_memset(guid.data, 0, sizeof(guid.data));

	*guid16++ = SDL_SwapLE16(SDL_HARDWARE_BUS_USB);
    *guid16++ = 0;

    if (vendor && product) {
        *guid16++ = SDL_SwapLE16(vendor);
        *guid16++ = 0;
        *guid16++ = SDL_SwapLE16(product);
        *guid16++ = 0;
        *guid16++ = 0;
        *guid16++ = 0;
    } else {
        SDL_strlcpy((char*)guid16, name, sizeof(guid.data) - 4);
    }
	
	return guid;
}

/*
 Rumble experimental
 Add duration in function, impossible to stop rumble in progress, so SDL2 can't stop it
*/
static int
SDL_SYS_JoystickRumble(SDL_Joystick * joystick, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, Uint32 duration_ms)
{
	struct joystick_hwdata *hwdata = joystick->hwdata;
	if (hwdata) {
		if (hwdata->numRumbles) {
			DOUBLE lpower=(DOUBLE)(low_frequency_rumble/65535), hpower=(DOUBLE)(high_frequency_rumble/65535);
			ULONG duration = duration_ms;
			if (duration != 0 && (lpower > 0.0 || hpower > 0.0)) { 
				D("[%s] SetSensorAttrTags lpower=%f - hpower=%f - duration=%d\n", __FUNCTION__,lpower, hpower, duration);
				SetSensorAttrTags(hwdata->rumble[0], 
					SENSORS_HIDInput_Rumble_Power, (IPTR)&lpower, 
					SENSORS_HIDInput_Rumble_Duration, duration, 
					TAG_DONE);
				SetSensorAttrTags(hwdata->rumble[1], 
					SENSORS_HIDInput_Rumble_Power , (IPTR)&hpower, 
					SENSORS_HIDInput_Rumble_Duration, duration, 
					TAG_DONE);
			}
		}	
	}		
    return 0;
}

static int
SDL_SYS_JoystickGetDevicePlayerIndex(int device_index)
{
    return device_index;
}

static void
SDL_SYS_JoystickSetDevicePlayerIndex(int device_index, int player_index)
{
}

static SDL_bool
SDL_SYS_GetGamepadMapping(int device_index, SDL_GamepadMapping * out)
{
    return SDL_FALSE;
}

static int
SDL_SYS_JoystickRumbleTriggers(SDL_Joystick * joystick, Uint16 left_rumble, Uint16 right_rumble)
{
    return SDL_Unsupported();
}

static SDL_bool
SDL_SYS_JoystickHasLED(SDL_Joystick * joystick)
{
    return SDL_FALSE;
}

static int
SDL_SYS_JoystickSetLED(SDL_Joystick * joystick, Uint8 red, Uint8 green, Uint8 blue)
{
    return SDL_Unsupported();
}

static int
SDL_SYS_JoystickSetSensorsEnabled(SDL_Joystick *joystick, SDL_bool enabled)
{
    return SDL_Unsupported();
}

SDL_JoystickDriver SDL_MORPHOS_JoystickDriver =
{
    SDL_SYS_JoystickInit,
    SDL_SYS_JoystickGetCount,
    SDL_SYS_JoystickDetect,
    SDL_SYS_JoystickGetDeviceName,
    SDL_SYS_JoystickGetDevicePlayerIndex,
    SDL_SYS_JoystickSetDevicePlayerIndex,
    SDL_SYS_JoystickGetDeviceGUID,
    SDL_SYS_JoystickGetDeviceInstanceID,
    SDL_SYS_JoystickOpen,
    SDL_SYS_JoystickRumble,
    SDL_SYS_JoystickRumbleTriggers,
    SDL_SYS_JoystickHasLED,
    SDL_SYS_JoystickSetLED,
	SDL_SYS_JoystickSetSensorsEnabled,
    SDL_SYS_JoystickUpdate,
    SDL_SYS_JoystickClose,
    SDL_SYS_JoystickQuit,
	SDL_SYS_GetGamepadMapping
};

#endif

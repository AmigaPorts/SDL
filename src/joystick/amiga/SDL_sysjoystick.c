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

#include "../../SDL_internal.h"

#ifdef SDL_JOYSTICK_AMIGA

#include "SDL_joystick.h"
#include "SDL_timer.h"
#include "../SDL_sysjoystick.h"
#include "../SDL_joystick_c.h"

#define USE_INLINE_STDARG
#include <libraries/lowlevel.h>
#ifndef NO_LOWLEVEL_EXT
#include <libraries/lowlevel_ext.h>
#endif

#include <proto/exec.h>
#include <proto/lowlevel.h>
#include <proto/graphics.h>
#include <stdlib.h>

#include "SDL_events.h"

/* The maximum number of joysticks we'll detect */
#define MAX_JOYSTICKS 4 /* lowlevel.library is limited to 4 ports */

static const ULONG joybut[] =
{
	JPF_BUTTON_RED,
	JPF_BUTTON_BLUE,
	JPF_BUTTON_GREEN,
	JPF_BUTTON_YELLOW,
	JPF_BUTTON_PLAY,
	JPF_BUTTON_FORWARD,
	JPF_BUTTON_REVERSE
};

struct joystick_hwdata
{
	ULONG joystate;
#ifndef NO_LOWLEVEL_EXT
	ULONG joystate_ext;
	ULONG supports_analog;
#endif
};

static int PortIndex(int index)
{
	switch(index)
	{
		case 0:
			return 1;
			break;
		case 1:
			return 0;
			break;
		default:
			break;
	}
	return index;
}

#define MAX_JOY_NAME 64
static char SDL_JoyNames[MAX_JOYSTICKS * MAX_JOY_NAME];

static Uint8 SDL_numjoysticks = 0;

static int SDL_SYS_JoystickGetCount(void)
{
	D("[%s]\n", __FUNCTION__);
	return SDL_numjoysticks;
}

static void SDL_SYS_JoystickDetect() 
{
	//D("[%s]\n", __FUNCTION__);
}

static int SDL_SYS_JoystickInit(void)
{
	int numjoysticks = 0;
	ULONG joyflag = 0;

	D("[%s]\n", __FUNCTION__);

	if (SDL_numjoysticks == 0)
	{
		if(LowLevelBase) {
			CloseLibrary(LowLevelBase);
			LowLevelBase = NULL;
		}
		
		if ((LowLevelBase = OpenLibrary("lowlevel.library",37)))
		{
			numjoysticks = 0;

			while (numjoysticks < MAX_JOYSTICKS)
			{
				int index = PortIndex(numjoysticks);
				joyflag = ReadJoyPort(index);

				if((joyflag&JP_TYPE_MASK) == JP_TYPE_NOTAVAIL)
				{
					break;
				}

				numjoysticks++;
			}

			SDL_numjoysticks = numjoysticks;
			return numjoysticks;
		}
		else
		{
			/* failed to open lowlevel.library! */
			SDL_SetError("Unable to open lowlevel.library");
			return 0;
		}
	}
	else
	{
		return SDL_numjoysticks;
	}
}

static const char *SDL_SYS_JoystickGetDeviceName(int device_index)
{
	const char *name = NULL;

	D("[%s] device_index %d\n", __FUNCTION__, device_index);

	if (LowLevelBase && device_index < MAX_JOYSTICKS)
	{
		ULONG joyflag;

		joyflag = ReadJoyPort(PortIndex(device_index));

		if (!(joyflag&JP_TYPE_MASK) == JP_TYPE_NOTAVAIL)
		{
			const char *type;

			switch (joyflag & JP_TYPE_MASK)
			{
				case JP_TYPE_GAMECTLR:
					type ="a Game Controller";
					break;

				case JP_TYPE_MOUSE:
					type ="a Mouse";
					break;

				case JP_TYPE_JOYSTK:
					type ="a Joystick";
					break;

				default:
				case JP_TYPE_UNKNOWN:
					type ="an unknown device";
					break;
			}

			name = &SDL_JoyNames[device_index * MAX_JOY_NAME];

			NewRawDoFmt("Port %ld is %s", NULL, (STRPTR)name, device_index, type);
		}
	}
	else
	{
		SDL_SetError("No joystick available with that index");
	}

	return name;
}


static int SDL_SYS_JoystickOpen(SDL_Joystick * joystick, int device_index)
{
	ULONG temp;
	
	D("[%s] joystick 0x%08lx device_index %d\n", __FUNCTION__, joystick, device_index);
	
	if(!LowLevelBase)
	{
		if(SDL_SYS_JoystickInit() < 1)
		{
			SDL_SetError("Initialize Joysticks first!");
			return -1;
		}
	}

	joystick->hwdata = (struct joystick_hwdata *) malloc(sizeof(*joystick->hwdata));

	if ( joystick->hwdata == NULL )
	{
		SDL_OutOfMemory();
		return -1;
	}

	SetJoyPortAttrs(PortIndex(joystick->instance_id), SJA_Type, SJA_TYPE_GAMECTLR, TAG_END);

	temp = ReadJoyPort(PortIndex(joystick->instance_id));

	if((temp & JP_TYPE_MASK)==JP_TYPE_GAMECTLR)
	{
		joystick->nbuttons = 7;
		joystick->nhats = 1;
	}
	else if((temp & JP_TYPE_MASK) == JP_TYPE_JOYSTK)
	{
		joystick->nbuttons = 3;
		joystick->nhats = 1;
	}
	else if((temp & JP_TYPE_MASK) == JP_TYPE_MOUSE)
	{
		joystick->nbuttons = 3;
		joystick->nhats = 0;
	}
	else if((temp & JP_TYPE_MASK) == JP_TYPE_UNKNOWN)
	{
		joystick->nbuttons = 3;
		joystick->nhats = 1;
	}
	else if((temp & JP_TYPE_MASK) == JP_TYPE_NOTAVAIL)
	{
		joystick->nbuttons = 0; 
		joystick->nhats = 0; 
	} else {
		// Default, same as 
		joystick->nbuttons = 3; 
		joystick->nhats = 1; 
	}
		
	joystick->nballs = 0;
	joystick->naxes = 0;
	joystick->hwdata->joystate = 0L;
#ifndef NO_LOWLEVEL_EXT
	joystick->hwdata->joystate_ext = 0L;
	joystick->hwdata->supports_analog = 0;

	if (LowLevelBase->lib_Version > 50 || (LowLevelBase->lib_Version >= 50 && LowLevelBase->lib_Revision >= 17)) {
		joystick->hwdata->supports_analog = 1;
		joystick->naxes = 2;
	}
#endif

	return 0;
}


static void SDL_SYS_JoystickUpdate(SDL_Joystick *joystick)
{
	ULONG data;
#ifndef NO_LOWLEVEL_EXT
	ULONG data_ext = 0;
#endif
	int	i, index;

	/*if(!LowLevelBase)
	{
		if(SDL_JoystickInit() < 1)
		{
			D("Initialize Joysticks first!\n");
			return;
		}
	}*/

	index = PortIndex(joystick->instance_id);

	data = ReadJoyPort(index);
#ifndef NO_LOWLEVEL_EXT
	if (joystick->hwdata->supports_analog)
		data_ext = ReadJoyPort(index + JP_ANALOGUE_PORT_MAGIC);
#endif

	//D("[%s] joystick 0x%08lx index %d data 0x%08lx data_ext 0x%08lx\n", __FUNCTION__, joystick, index, data, data_ext);

	/* only send an event when something changed */

	/* hats */
	if((joystick->hwdata->joystate & JP_DIRECTION_MASK) != (data & JP_DIRECTION_MASK))
	{
		if(joystick->nhats)
		{
			Uint8 value_hat = SDL_HAT_CENTERED;

			if(data & JPF_JOY_DOWN)
			{
				value_hat |= SDL_HAT_DOWN;
			}
			else if(data & JPF_JOY_UP)
			{
				value_hat |= SDL_HAT_UP;
			}

			if(data & JPF_JOY_LEFT)
			{
				value_hat |= SDL_HAT_LEFT;
			}
			else if(data & JPF_JOY_RIGHT)
			{
				value_hat |= SDL_HAT_RIGHT;
			}

			SDL_PrivateJoystickHat(joystick, 0, value_hat);
		}
	}

	/* axes */
#ifndef NO_LOWLEVEL_EXT
	if (joystick->hwdata->supports_analog && data_ext & JP_TYPE_ANALOGUE)
	{
		if((joystick->hwdata->joystate_ext & JP_XAXIS_MASK) != (data_ext & JP_XAXIS_MASK))
		{
			Sint16 value;

			value = (data_ext & JP_XAXIS_MASK) * 2*32767 / 255 - 32767;
			SDL_PrivateJoystickAxis(joystick, 0, value);
		}

		if((joystick->hwdata->joystate_ext & JP_YAXIS_MASK) != (data_ext & JP_YAXIS_MASK))
		{
			Sint16 value;

			value = ((data_ext & JP_YAXIS_MASK)>>8) * 2*32767 / 255 - 32767;
			SDL_PrivateJoystickAxis(joystick, 1, value);
		}
	}
#endif

	/* Joy buttons */
	for(i = 0; i < joystick->nbuttons; i++)
	{
		if( (data & joybut[i]) )
		{
			/*
			if(i == 1)
			{
				data &= ~(joybut[2]);
			}
			*/

			if(!(joystick->hwdata->joystate & joybut[i]))
			{
				SDL_PrivateJoystickButton(joystick, i, SDL_PRESSED);
			}
		}
		else if(joystick->hwdata->joystate & joybut[i])
		{
			SDL_PrivateJoystickButton(joystick, i, SDL_RELEASED);
		}
	}

	joystick->hwdata->joystate = data;
#ifndef NO_LOWLEVEL_EXT
	joystick->hwdata->joystate_ext = data_ext;
#endif
}

static void SDL_SYS_JoystickClose(SDL_Joystick *joystick)
{
	D("[%s] joystick 0x%08lx\n", __FUNCTION__, joystick);

	if(LowLevelBase)	/* ne to reinitialize */
	{
		//int index = PortIndex(joystick->instance_id);
		//SetJoyPortAttrs(index, SJA_Type, SJA_TYPE_AUTOSENSE, TAG_END);
	}

	if(joystick->hwdata)
	{
		SDL_free(joystick->hwdata);
	}
	
	return;
}

/* Function to perform any system-specific joystick related cleanup */
static void SDL_SYS_JoystickQuit(void)
{
	D("[%s]\n", __FUNCTION__);

	if(LowLevelBase)
	{
		CloseLibrary(LowLevelBase);
		LowLevelBase = NULL;
	}

	return;
}

static int SDL_SYS_JoystickGetDevicePlayerIndex(int device_index)
{
	D("[%s] device_index %d\n", __FUNCTION__, device_index);

	return device_index;
}

static void SDL_SYS_JoystickSetDevicePlayerIndex(int device_index, int player_index)
{
	D("[%s] Not implemented\n", __FUNCTION__);
}

static SDL_JoystickGUID SDL_SYS_JoystickGetDeviceGUID(int device_index)
{
	D("[%s] device_index %d\n", __FUNCTION__, device_index);

	SDL_JoystickGUID guid;
	const char *name = SDL_SYS_JoystickGetDeviceName(device_index);
	SDL_zero(guid);
	SDL_memcpy(&guid, name, SDL_min(sizeof(guid), SDL_strlen(name)));
	return guid;
}

static SDL_JoystickID SDL_SYS_JoystickGetDeviceInstanceID(int device_index)
{
	D("[%s] device_index %d\n", __FUNCTION__, device_index);
	return device_index;
}

static int SDL_SYS_JoystickRumble(SDL_Joystick * joystick, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble)
{
	D("[%s] joystick 0x%08lx low %d high %d\n", __FUNCTION__, joystick, low_frequency_rumble, high_frequency_rumble);

	if (!LowLevelBase) {
		return SDL_Unsupported();
	}

#ifndef NO_LOWLEVEL_EXT
	if (joystick) {
		int index = PortIndex(joystick->instance_id);

		if (low_frequency_rumble > 0 || high_frequency_rumble > 0) {
			SetJoyPortAttrs(index, SJA_RumbleSetSlowMotor, low_frequency_rumble >> 8, SJA_RumbleSetFastMotor, low_frequency_rumble >> 8, TAG_END);
		} else {
			SetJoyPortAttrs(index, SJA_RumbleOff, 0, TAG_END);
		}
	}
#endif

	return 0;
}

SDL_JoystickDriver SDL_AMIGA_JoystickDriver =
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
    SDL_SYS_JoystickUpdate,
    SDL_SYS_JoystickClose,
    SDL_SYS_JoystickQuit,
};

#endif

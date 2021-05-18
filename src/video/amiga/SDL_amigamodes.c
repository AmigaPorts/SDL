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


#include "SDL_amigamodes.h"
#include "SDL_amigavideo.h"

#include <machine/endian.h>

#include <cybergraphx/cybergraphics.h>
#include <intuition/extensions.h>
#include <intuition/monitorclass.h>
#include <proto/alib.h>
#include <proto/cybergraphics.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/screennotify.h>
#include <proto/exec.h>

static Uint32
AMIGA_SDLPixelFormatToDepth(Uint32 pixfmt)
{
	switch (pixfmt)
	{
		case SDL_PIXELFORMAT_INDEX8:
			return 8;

		case SDL_PIXELFORMAT_RGB555:
			return 15;

		case SDL_PIXELFORMAT_RGB565:
		case SDL_PIXELFORMAT_BGR565:
			return 16;

		case SDL_PIXELFORMAT_RGB888:
		case SDL_PIXELFORMAT_BGR888:
			return 24;

		default:
		case SDL_PIXELFORMAT_ARGB8888:
		case SDL_PIXELFORMAT_BGRA8888:
		case SDL_PIXELFORMAT_RGBA8888:
			return 32;
	}
}

static Uint32
AMIGA_GetSDLPixelFormat(Uint32 pixfmt, Uint32 default_pixfmt)
{
	D("[%s]\n", __FUNCTION__);

	switch (pixfmt)
	{
		#if BYTEORDER == LITTLE_ENDIAN
		case PIXFMT_RGB15PC: return SDL_PIXELFORMAT_RGB555;   // Will not work on big endian machine
		case PIXFMT_BGR15PC: return SDL_PIXELFORMAT_BGR555;   // Will not work on big endian machine
		case PIXFMT_RGB16PC: return SDL_PIXELFORMAT_RGB565;   // Will not work on big endian machine
		case PIXFMT_BGR16PC: return SDL_PIXELFORMAT_BGR565;   // Will not work on big endian machine
		#else
		case PIXFMT_RGB15PC:
		case PIXFMT_BGR15PC:
		case PIXFMT_RGB16PC:
		case PIXFMT_BGR16PC:
			return default_pixfmt;
		#endif

		case PIXFMT_LUT8   : return SDL_PIXELFORMAT_INDEX8;
		case PIXFMT_RGB15  : return SDL_PIXELFORMAT_RGB555;
		case PIXFMT_RGB15X : return SDL_PIXELFORMAT_RGB555;
		case PIXFMT_RGB16  : return SDL_PIXELFORMAT_RGB565;
		case PIXFMT_BGR16  : return SDL_PIXELFORMAT_BGR565;
		case PIXFMT_RGB24  : return SDL_PIXELFORMAT_RGB888;
		case PIXFMT_BGR24  : return SDL_PIXELFORMAT_BGR888;
		case PIXFMT_ARGB32 : return SDL_PIXELFORMAT_ARGB8888;
		case PIXFMT_BGRA32 : return SDL_PIXELFORMAT_BGRA8888;
		case PIXFMT_RGBA32 : return SDL_PIXELFORMAT_RGBA8888;
		default            : return SDL_PIXELFORMAT_BGRA8888;
	}
}

static int
AMIGA_GetRefreshRate(struct Screen *s)
{
	ULONG modeid = getv(s, SA_DisplayID);
	APTR handle = FindDisplayInfo(modeid);
	ULONG freq = 60;

	D("[%s]\n", __FUNCTION__);

	if (handle)
	{
		struct MonitorInfo mi;

		if (GetDisplayInfoData(handle, (UBYTE *)&mi, sizeof(mi), DTAG_MNTR, 0) >= sizeof(mi))
		{
			if (mi.TotalRows)
			{
				freq = (ULONG)(1000000000L / ((FLOAT)mi.TotalColorClocks * 280.0 * (FLOAT)mi.TotalRows / 1000.0) + 5.0);
			}
		}
	}

	return freq;
}

#define MAX_SDL_PIXEL_FORMATS 10

static const struct
{
	Uint32 PixFmt, NewPixFmt;
} pixelformats[MAX_SDL_PIXEL_FORMATS] =
{
	{ PIXFMT_LUT8  , SDL_PIXELFORMAT_INDEX8 },
	{ PIXFMT_RGB15 , SDL_PIXELFORMAT_RGB555 },
	{ PIXFMT_RGB15X, SDL_PIXELFORMAT_RGB555 },
	{ PIXFMT_RGB16 , SDL_PIXELFORMAT_RGB565 },
	{ PIXFMT_BGR16 , SDL_PIXELFORMAT_BGR565 },
	{ PIXFMT_RGB24 , SDL_PIXELFORMAT_RGB888 },
	{ PIXFMT_BGR24 , SDL_PIXELFORMAT_BGR888 },
	{ PIXFMT_ARGB32, SDL_PIXELFORMAT_ARGB8888 },
	{ PIXFMT_BGRA32, SDL_PIXELFORMAT_BGRA8888 },
	{ PIXFMT_RGBA32, SDL_PIXELFORMAT_RGBA8888 },
};

int
AMIGA_InitModes(_THIS)
{
	Uint32 pixfmt = SDL_PIXELFORMAT_BGRA8888;
	int width = 1920, height = 1080, dispcount = 0;
	SDL_VideoDisplay display;
	SDL_DisplayMode mode;
	Object **monitors;
	struct Screen *s;
	APTR mon;

	D("[%s]\n", __FUNCTION__);
	SDL_zero(display);

	mode.w = 1920;
	mode.h = 1080;
	mode.refresh_rate = 60;
	mode.format = SDL_PIXELFORMAT_ARGB8888;
	mode.driverdata = NULL;

	s = LockPubScreen("Workbench");
	mon = NULL;

	if (s)
	{
		SDL_DisplayModeData *modedata;

		// This is not actual view size but virtual screens are so 90s
		width = s->Width;
		height = s->Height;

		pixfmt = AMIGA_GetSDLPixelFormat(getv(s, SA_PixelFormat), SDL_PIXELFORMAT_ARGB8888);
		mon = (APTR)getv(s, SA_MonitorObject);

		UnlockPubScreen(NULL, s);

		modedata = SDL_malloc(sizeof(*modedata));

		if (modedata)
		{
			modedata->monitor = mon;

			mode.format = pixfmt;
			mode.w = width;
			mode.h = height;
			mode.refresh_rate = AMIGA_GetRefreshRate(s);
			mode.driverdata = SDL_malloc(4);

			display.desktop_mode = mode;
			display.current_mode = mode;
			display.driverdata = modedata;
			display.name = (char *)getv(mon, MA_MonitorName);

			SDL_AddVideoDisplay(&display, SDL_FALSE);
			dispcount++;

			mode.driverdata = NULL;

			D("[%s] Added Workbench screen\n", __FUNCTION__);
		}
	}

	// Add other monitors (not desktop)
	if ((monitors = GetMonitorList(NULL)))
	{
		APTR m;
		int i, j;

		for (i = 0; (m = monitors[i]); i++)
		{
			if (m != mon)
			{
				SDL_DisplayModeData *modedata = SDL_malloc(sizeof(*modedata));

				if (modedata)
				{
					ULONG *fmt = (ULONG *)getv(m, MA_PixelFormats);

					for (j = MAX_SDL_PIXEL_FORMATS - 1; j >= 0; j--)
					{
						Uint32 pixfmt = pixelformats[j].PixFmt;

						if (fmt[pixfmt])
						{
							mode.format = pixelformats[j].NewPixFmt;
							D("[%s] Add %ld/%ld pixfmt %ld\n", __FUNCTION__, mode.w, mode.h, mode.format);
							break;
						}
					}

					modedata->monitor = m;

					display.desktop_mode = mode;
					display.current_mode = mode;
					display.driverdata = modedata;
					display.name = (char *)getv(mon, MA_MonitorName);

					D("[%s] Add video display '%s'\n", __FUNCTION__, display.name);

					SDL_AddVideoDisplay(&display, SDL_FALSE);
					dispcount++;
				}
			}
		}

		FreeMonitorList(monitors);
	}

	return dispcount > 0 ? 0 : -1;
}

static int
AMIGA_CheckMonitor(APTR mon, ULONG id)
{
	IPTR tags[] = { GMLA_DisplayID, id, TAG_DONE };
	Object **monlist = GetMonitorList((struct TagItem *)&tags);
	int rc = 0;
	D("[%s] find mon 0x%08lx\n", __FUNCTION__, mon);

	if (monlist)
	{
		int idx;

		for (idx = 0; monlist[idx]; idx++)
		{
			if (monlist[idx] == mon)
			{
				rc = 1;
				break;
			}
		}

		FreeMonitorList(monlist);
	}

	return rc;
}

void
AMIGA_GetDisplayModes(_THIS, SDL_VideoDisplay * sdl_display)
{
	SDL_DisplayModeData *md = sdl_display->driverdata;
	D("[%s]\n", __FUNCTION__);

	if (md)
	{
		ULONG i, *fmt = (ULONG *)getv(md->monitor, MA_PixelFormats);
		SDL_DisplayMode mode = sdl_display->desktop_mode;

		for (i = 0; i < MAX_SDL_PIXEL_FORMATS; i++)
		{
			Uint32 pixfmt = pixelformats[i].PixFmt;

			if (fmt[pixfmt])
			{
				ULONG nextid = INVALID_ID;

				mode.format = pixelformats[i].NewPixFmt;

				// Go through display database to find out what modes are available to this monitor
				D("[%s] Go through display database\n", __FUNCTION__);
				while ((nextid = NextDisplayInfo(nextid)) != INVALID_ID)
				{
					if (GetCyberIDAttr(CYBRIDATTR_PIXFMT, nextid) == pixfmt)
					{
						D("[%s] id 0x%08lx matches to pixfmt %ld\n", __FUNCTION__, nextid, pixfmt);

						if (AMIGA_CheckMonitor(md->monitor, nextid))
						{
							mode.w = GetCyberIDAttr(CYBRIDATTR_WIDTH, nextid);
							mode.h = GetCyberIDAttr(CYBRIDATTR_HEIGHT, nextid);
							mode.driverdata = sdl_display->desktop_mode.driverdata ? SDL_malloc(4) : NULL;

							SDL_AddDisplayMode(sdl_display, &mode);
						}
					}

					D("[%s] Mode 0x%08lx checked.\n", __FUNCTION__, nextid);
				}

				D("[%s] finished pixel format %ld\n", __FUNCTION__, pixfmt);
			}
		}
	}
}

int
AMIGA_GetScreen(_THIS, BYTE fullscreen, SDL_bool support3d)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	struct Screen *screen;
	int use_wb_screen = 0;
	ULONG openError = 0;
	
	D("[%s] Use monitor '%s'\n", __FUNCTION__, data->ScrMonName ? data->ScrMonName : (STRPTR)"Workbench");

	if (!fullscreen && data->ScrMonName == NULL)
	{
		data->CustomScreen = NULL;
		screen = LockPubScreen("Workbench");
		use_wb_screen = 1;
	}
	else
	{
		struct TagItem screentags[] =
		{
			{SA_Quiet, TRUE},
			{SA_ShowTitle, FALSE},
			{SA_AutoScroll, TRUE},
			{SA_Title, (IPTR)"SDL2"},
			{SA_AdaptSize, TRUE},
			{SA_ErrorCode, &openError},
			{support3d ? SA_3DSupport : TAG_IGNORE, TRUE},
			{TAG_DONE}
		};

		D("[%s] Open screen %ldx%ldx%ld\n", __FUNCTION__, data->ScrWidth, data->ScrHeight, data->ScrDepth);

		if (fullscreen && data->ScrMonName == NULL)
		{
			screen = OpenScreenTags(NULL,
				//SA_LikeWorkbench, TRUE,
				SA_Width, data->ScrWidth,
				SA_Height, data->ScrHeight,
				SA_Depth, data->ScrDepth,
				TAG_MORE, (IPTR)screentags);
		}
		else
		{
			screen = OpenScreenTags(NULL,
				SA_Width, data->ScrWidth,
				SA_Height, data->ScrHeight,
				SA_Depth, data->ScrDepth,
				SA_MonitorName, data->ScrMonName,
				TAG_MORE, (IPTR)screentags);
		}

		data->CustomScreen = screen;
	}

	if (screen == NULL)
	{
		if (data->ScrMonName != NULL)
			screen = LockPubScreen("Workbench");

		if (screen == NULL) {
			switch (openError) {
            case OSERR_NOMONITOR:
                SDL_SetError("Monitor for display mode not available");
                break;
            case OSERR_NOCHIPS:
                SDL_SetError("Newer custom chips required");
                break;
            case OSERR_NOMEM:
            case OSERR_NOCHIPMEM:
                SDL_OutOfMemory();
                break;
            case OSERR_PUBNOTUNIQUE:
                SDL_SetError("Public screen name not unique");
                break;
            case OSERR_UNKNOWNMODE:
            case OSERR_TOODEEP:
                SDL_SetError("Unknown display mode");
                break;
            case OSERR_ATTACHFAIL:
                SDL_SetError("Attachment failed");
                break;
            default:
				SDL_SetError("Failed to get screen.");
				break;
			}
			return -1;
		}
		use_wb_screen = 1;
	}

	data->WScreen = screen;

	if (use_wb_screen)
	{
		data->ScreenNotifyHandle = AddWorkbenchClient(&data->ScreenNotifyPort, -20);
	}

	if (data->ScreenSaverSuspendCount)
	{
		size_t i;

		for (i = data->ScreenSaverSuspendCount; i > 0; i--)
			SetAttrs(screen, SA_StopBlanker, TRUE, TAG_DONE);
	}

	return 0;
}

int
AMIGA_SetDisplayMode(_THIS, SDL_VideoDisplay *display, SDL_DisplayMode *mode)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;

	D("[%s]\n", __FUNCTION__);

	AMIGA_CloseWindows(_this);
	AMIGA_CloseDisplay(_this);

	data->sdlpixfmt = mode->format;
	data->ScrMonName = NULL;

	// NULL means non-WB mode
	data->ScrWidth = mode->w;
	data->ScrHeight = mode->h;
	data->ScrDepth = AMIGA_SDLPixelFormatToDepth(mode->format);

	if (mode->driverdata == NULL)
	{
		data->ScrMonName = display->name;
		D("[%s] Use monitor %s\n", __FUNCTION__, data->ScrMonName);
	}

	//AMIGA_GetScreen(_this);
	//AMIGA_OpenWindows(_this);

	return 0;
}

int
AMIGA_GetDisplayBounds(_THIS, SDL_VideoDisplay * display, SDL_Rect * rect)
{
    /*SDL_DisplayModeData *data = (SDL_DisplayModeData *) display->current_mode.driverdata;

    rect->x = data->x;
    rect->y = data->y;
    rect->w = display->current_mode.w;
    rect->h = display->current_mode.h;*/

    //dprintf("x=%d, y=%d, w=%d, h=%d\n", rect->x, rect->y, rect->w, rect->h);

    return 0;
}
/* vi: set ts=4 sw=4 expandtab: */

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

#include "SDL_video.h"
#include "SDL_mouse.h"
#include "../SDL_sysvideo.h"
#include "../SDL_pixels_c.h"
#include "SDL_hints.h"

#include "SDL_amigaclipboard.h"
#include "SDL_amigaevents.h"
#include "SDL_amigaframebuffer.h"
#include "SDL_amigakeyboard.h"
#include "SDL_amigamodes.h"
#include "SDL_amigamouse.h"
#include "SDL_amigashape.h"
#include "SDL_amigavideo.h"
#include "SDL_amigawindow.h"
#include "SDL_amigamessagebox.h"
#include "SDL_amigaopengl.h"

#include <exec/execbase.h>
#include <intuition/pointerclass.h>
#include <proto/commodities.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/icon.h>
#include <proto/intuition.h>
#include <proto/screennotify.h>
#include <proto/wb.h>


void
AMIGA_CloseDisplay(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	D("[%s]\n", __FUNCTION__);

	if (data->CustomScreen)
	{
		CloseScreen(data->CustomScreen);
	}
	else if (data->WScreen)
	{
		if (data->ScreenSaverSuspendCount)
		{
			size_t i;

			for (i = data->ScreenSaverSuspendCount; i > 0; i--)
				SetAttrs(data->WScreen, SA_StopBlanker, FALSE, TAG_DONE);
		}

		UnlockPubScreen(NULL, data->WScreen);

		if (data->ScreenNotifyHandle)
		{
			while (!RemWorkbenchClient(data->ScreenNotifyHandle))
				Delay(10);

			data->ScreenNotifyHandle = NULL;
		}
	}

	data->CustomScreen = NULL;
	data->WScreen = NULL;
}

size_t getv(APTR obj, size_t attr)
{
	size_t val;
	GetAttr(attr, obj, (ULONG *)&val);
	return val;
}

void
AMIGA_HideApp(_THIS, size_t with_app_icon)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	D("[%s] %siconify\n", __FUNCTION__, with_app_icon ? "" : "no ");

	AMIGA_CloseWindows(_this);
	AMIGA_CloseDisplay(_this);

	if (with_app_icon && data->AppIcon)
	{
		data->AppIconRef = AddAppIconA(0, 0, FilePart(data->FullAppName), &data->WBPort, 0, data->AppIcon, NULL);
	}
}

void
AMIGA_ShowApp(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	D("[%s]\n", __FUNCTION__);

	if (data->AppIconRef)
	{
		struct Message *msg;

		RemoveAppIcon(data->AppIconRef);
		data->AppIconRef = NULL;

		while ((msg = GetMsg(&data->WBPort)) != NULL)
			ReplyMsg(msg);
	}

	//AMIGA_GetScreen(_this);
	AMIGA_OpenWindows(_this);
	AMIGA_GL_ResizeContext(_this, _this->current_glwin);
}

static int
AMIGA_VideoInit(_THIS)
{
	D("[%s]\n", __FUNCTION__);

	if (AMIGA_InitModes(_this) < 0)
	{
		return SDL_SetError("Failed to initialize modes");
	}

	AMIGA_InitKeyboard(_this);
	AMIGA_InitMouse(_this);

	SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");
	SDL_SetHint(SDL_HINT_GAMECONTROLLERCONFIG_FILE, "ENV:gamecontrollerdb.txt");
	
	return 0;
}

static void
AMIGA_VideoQuit(_THIS)
{
	//SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	D("[%s]\n", __FUNCTION__);

	AMIGA_CloseWindows(_this);
	AMIGA_CloseDisplay(_this);

	AMIGA_QuitMouse(_this);
}

static void
AMIGA_DeleteDevice(SDL_VideoDevice * device)
{
	SDL_VideoData *data = (SDL_VideoData *) device->driverdata;
	D("[%s]\n", __FUNCTION__);

	FreeSignal(data->ScreenNotifyPort.mp_SigBit);
	FreeSignal(data->BrokerPort.mp_SigBit);
	FreeSignal(data->WBPort.mp_SigBit);
	FreeSignal(data->WinPort.mp_SigBit);

	if (data->BrokerRef)
		DeleteCxObjAll(data->BrokerRef);

	if (data->AppIcon)
		FreeDiskObject(data->AppIcon);

	SDL_free(data);
	SDL_free(device);
}

void
AMIGA_SuspendScreenSaver(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	LONG suspend = _this->suspend_screensaver;

	D("[%s] screen 0x%08lx, suspend %ld\n", __FUNCTION__, data->WScreen, suspend);

	if (suspend == 0 && data->ScreenSaverSuspendCount == 0)
		return;

	data->ScreenSaverSuspendCount += suspend ? 1 : -1;

	if (data->WScreen)
	{
		SetAttrs(data->WScreen, SA_StopBlanker, suspend, TAG_DONE);
	}
}

static
CONST_STRPTR AMIGA_GetTaskName()
{
	struct Process *task = (struct Process *)FindTask(NULL);
	STRPTR name = "SDL";

	if (task->pr_Task.tc_Node.ln_Type == NT_PROCESS || task->pr_Task.tc_Node.ln_Type == NT_TASK)
	{
		if (task->pr_Task.tc_Node.ln_Type == NT_PROCESS && task->pr_CLI)
		{
			struct CommandLineInterface *cli = (struct CommandLineInterface *)BADDR(task->pr_CLI);

			if (cli->cli_Module && cli->cli_CommandName)
			{
				CONST_STRPTR src = (CONST_STRPTR)BADDR(cli->cli_CommandName);
				size_t len = *src + 1;

				if (len <= 1)
				{
					src = "SDL";
					len = sizeof("SDL");
				}
				else
				{
					if (src[1] == '"' && src[len] == '"')
						len -= 2;

					src++;
				}

				name = SDL_malloc(len);

				if (name)
					stccpy(name, src, len);
			}
		}
		else
		{
			size_t len = strlen(task->pr_Task.tc_Node.ln_Name) + sizeof("PROGDIR:");

			name = SDL_malloc(len);

			if (name)
			{
				strcpy(name, "PROGDIR:");
				strcpy(name+8, task->pr_Task.tc_Node.ln_Name);
			}
		}
	}

	D("[%s] '%s'\n", __FUNCTION__, name);
	return name;
}

static void
AMIGA_InitPort(struct MsgPort *port)
{
	port->mp_Node.ln_Name = "SDL";
	port->mp_Flags = PA_SIGNAL;
	port->mp_SigTask = SysBase->ThisTask;

	NEWLIST(&port->mp_MsgList);

	port->mp_SigBit = AllocSignal(-1);
}

static void
AMIGA_InitBroker(SDL_VideoData *data)
{
	D("[%s]\n", __FUNCTION__);
	STRPTR name = FilePart(data->FullAppName);

	data->AppBroker.nb_Version = NB_VERSION;
	data->AppBroker.nb_Name = name;
	data->AppBroker.nb_Title = name;
	data->AppBroker.nb_Descr = "SDL";
	data->AppBroker.nb_Unique = NBU_DUPLICATE;
	data->AppBroker.nb_Flags = COF_SHOW_HIDE;
	data->AppBroker.nb_Pri = 0;
	data->AppBroker.nb_Port = &data->BrokerPort;
	data->AppBroker.nb_ReservedChannel = 0;

	data->BrokerRef = CxBroker(&data->AppBroker, NULL);

	if (data->BrokerRef)
	{
		ActivateCxObj(data->BrokerRef, 1);
	}
}

static SDL_VideoDevice *
AMIGA_CreateDevice(int devindex)
{
	/* Initialize all variables that we clean on shutdown */
	SDL_VideoDevice *device = (SDL_VideoDevice *) SDL_calloc(1, sizeof(SDL_VideoDevice));
	D("[%s]\n", __FUNCTION__);

	if (device)
	{
		SDL_VideoData *data = (struct SDL_VideoData *) SDL_calloc(1, sizeof(SDL_VideoData));

		device->driverdata = data;

		if (data)
		{
			AMIGA_InitPort(&data->ScreenNotifyPort);
			AMIGA_InitPort(&data->BrokerPort);
			AMIGA_InitPort(&data->WBPort);
			AMIGA_InitPort(&data->WinPort);

			data->ScrNotifySig = 1 << data->ScreenNotifyPort.mp_SigBit;
			data->BrokerSig = 1 << data->BrokerPort.mp_SigBit;
			data->WBSig = 1 << data->WBPort.mp_SigBit;
			data->WinSig = 1 << data->WinPort.mp_SigBit;

			data->sdlpixfmt = SDL_PIXELFORMAT_ARGB8888;

			NEWLIST(&data->windowlist);

			data->FullAppName = AMIGA_GetTaskName();
			data->AppIcon = GetDiskObject((STRPTR)data->FullAppName);

			if (data->AppIcon == NULL)
			{
				data->AppIcon = GetDiskObject((STRPTR)"ENVARC:Sys/def_SDL");
			}

			if (data->AppIcon)
			{
				data->AppIcon->do_CurrentX = NO_ICON_POSITION;
				data->AppIcon->do_CurrentY = NO_ICON_POSITION;
				data->AppIcon->do_Type = 0;
			}

			AMIGA_InitBroker(data);

			data->VideoDevice = device;

			/* Set the function pointers */
			device->VideoInit = AMIGA_VideoInit;
			device->VideoQuit = AMIGA_VideoQuit;
			device->GetDisplayModes = AMIGA_GetDisplayModes;
			//device->GetDisplayBounds = AMIGA_GetDisplayBounds;;
			device->SetDisplayMode = AMIGA_SetDisplayMode;
			device->SuspendScreenSaver = AMIGA_SuspendScreenSaver;
			device->PumpEvents = AMIGA_PumpEvents;

			device->CreateSDLWindow = AMIGA_CreateWindow;
			device->CreateSDLWindowFrom = AMIGA_CreateWindowFrom;
			device->SetWindowTitle = AMIGA_SetWindowTitle;
			device->SetWindowIcon = AMIGA_SetWindowIcon;
			device->SetWindowPosition = AMIGA_SetWindowPosition;
			device->SetWindowSize = AMIGA_SetWindowSize;
			device->SetWindowMinimumSize = AMIGA_SetWindowMinimumSize;
			device->SetWindowMaximumSize = AMIGA_SetWindowMaximumSize;
			device->ShowWindow = AMIGA_ShowWindow;
			device->HideWindow = AMIGA_HideWindow;
			device->RaiseWindow = AMIGA_RaiseWindow;
			device->MaximizeWindow = AMIGA_MaximizeWindow;
			device->MinimizeWindow = AMIGA_MinimizeWindow;
			device->RestoreWindow = AMIGA_RestoreWindow;
			device->SetWindowBordered = AMIGA_SetWindowBordered;
			device->SetWindowFullscreen = AMIGA_SetWindowFullscreen;
 			device->SetWindowGammaRamp = AMIGA_SetWindowGammaRamp;
			device->SetWindowGrab = AMIGA_SetWindowGrab;
			device->DestroyWindow = AMIGA_DestroyWindow;
			device->CreateWindowFramebuffer = AMIGA_CreateWindowFramebuffer;
			device->UpdateWindowFramebuffer = AMIGA_UpdateWindowFramebuffer;
			device->DestroyWindowFramebuffer = AMIGA_DestroyWindowFramebuffer;
			device->GetWindowWMInfo = AMIGA_GetWindowWMInfo;

			device->shape_driver.CreateShaper = AMIGA_CreateShaper;
			device->shape_driver.SetWindowShape = AMIGA_SetWindowShape;
			device->shape_driver.ResizeWindowShape = AMIGA_ResizeWindowShape;

			device->GL_LoadLibrary = AMIGA_GL_LoadLibrary;
			device->GL_GetProcAddress = AMIGA_GL_GetProcAddress;
			device->GL_UnloadLibrary = AMIGA_GL_UnloadLibrary;
			device->GL_CreateContext = AMIGA_GL_CreateContext;
			device->GL_MakeCurrent = AMIGA_GL_MakeCurrent;
			device->GL_GetDrawableSize = AMIGA_GL_GetDrawableSize;
			device->GL_SetSwapInterval = AMIGA_GL_SetSwapInterval;
			device->GL_GetSwapInterval = AMIGA_GL_GetSwapInterval;
			device->GL_SwapWindow = AMIGA_GL_SwapWindow;
			device->GL_DeleteContext = AMIGA_GL_DeleteContext;

			device->SetClipboardText = AMIGA_SetClipboardText;
			device->GetClipboardText = AMIGA_GetClipboardText;
			device->HasClipboardText = AMIGA_HasClipboardText;

			//device->ShowMessageBox = AMIGA_ShowMessageBox;
			
			device->SetWindowResizable = AMIGA_SetWindowResizable;
			//device->GetWindowBordersSize = AMIGA_GetWindowBordersSize;
			device->SetWindowOpacity = AMIGA_SetWindowOpacity;
			
			device->free = AMIGA_DeleteDevice;

			return device;
		}

		SDL_free(device);
	}

	SDL_OutOfMemory();
	return NULL;
}

VideoBootStrap AMIGA_bootstrap = {
	"amiga", "SDL Amiga video driver",
	AMIGA_CreateDevice
};

/* vim: set ts=4 sw=4 expandtab: */

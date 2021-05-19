/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2021 Sam Lantinga <slouken@libsdl.org>

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

#include "SDL_scancode.h"
#include "../SDL_sysvideo.h"
#include "../../events/SDL_events_c.h"
#include "../../events/SDL_mouse_c.h"
#include "../../events/scancodes_amiga.h"
#include "../../core/morphos/SDL_library.h"

#include "SDL_amigavideo.h"
#include "SDL_amigawindow.h"
#include "SDL_amigaopengl.h"
#include "SDL_amigamouse.h"

#include "SDL_timer.h"
#include "SDL_syswm.h"
#include "SDL.h"

#include <devices/rawkeycodes.h>
#include <intuition/extensions.h>
#include <intuition/intuimessageclass.h>
#include <libraries/screennotify.h>
#include <rexx/errors.h>
#include <rexx/storage.h>
#include <workbench/workbench.h>
#include <workbench/startup.h>
#include <exec/system.h>

#include <proto/dos.h>
#include <proto/alib.h>
#include <proto/commodities.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/keymap.h>
#include <proto/locale.h>
#include <proto/screennotify.h>
#include <libraries/gadtools.h>

void AHIAUD_Mute(ULONG mute);

static void
AMIGA_DispatchMouseButtons(const struct IntuiMessage *m, const SDL_WindowData *data)
{
	int state = (m->Code & IECODE_UP_PREFIX) ? SDL_RELEASED : SDL_PRESSED;

	switch (m->Code & ~(IECODE_UP_PREFIX))
	{
		case IECODE_LBUTTON:
			SDL_SendMouseButton(data->window, 0, state, SDL_BUTTON_LEFT);
			break;
		case IECODE_RBUTTON:
			SDL_SendMouseButton(data->window, 0, state, SDL_BUTTON_RIGHT);
			break;
		case IECODE_MBUTTON:
			SDL_SendMouseButton(data->window, 0, state, SDL_BUTTON_MIDDLE);
			break;
	}
}

static int
AMIGA_TranslateUnicode(struct IntuiMessage *m, char *buffer)
{
	int length;

#ifdef __MORPHOS__
	WCHAR keycode;

	GetAttr(IMSGA_UCS4, m, (ULONG *)&keycode);
	length = UTF8_Encode(keycode, buffer);
#else
	struct InputEvent ie;

	ie.ie_Class = IECLASS_RAWKEY;
	ie.ie_SubClass = 0;
	ie.ie_Code  = m->Code & ~(IECODE_UP_PREFIX);
	ie.ie_Qualifier = m->Qualifier;
	ie.ie_EventAddress = NULL;

	length = MapRawKey(&ie, buffer, sizeof(buffer), 0);
#endif

	return length;
}

static void
AMIGA_DispatchRawKey(struct IntuiMessage *m, const SDL_WindowData *data)
{
	SDL_Scancode s;
	UWORD code = m->Code;
	UWORD rawkey = m->Code & 0x7F;

	switch (code)
	{
		case RAWKEY_NM_WHEEL_UP:
			SDL_SendMouseWheel(data->window, 0, 0, 1, SDL_MOUSEWHEEL_NORMAL);
			break;

		case RAWKEY_NM_WHEEL_DOWN:
			SDL_SendMouseWheel(data->window, 0, 0, -1, SDL_MOUSEWHEEL_NORMAL);
			break;

		case RAWKEY_NM_WHEEL_LEFT:
			SDL_SendMouseWheel(data->window, 0, -1, 0, SDL_MOUSEWHEEL_NORMAL);
			break;

		case RAWKEY_NM_WHEEL_RIGHT:
			SDL_SendMouseWheel(data->window, 0, 1, 0,  SDL_MOUSEWHEEL_NORMAL);
			break;

		case RAWKEY_NM_BUTTON_FOURTH:
			SDL_SendMouseButton(data->window, 0, SDL_PRESSED, SDL_BUTTON_X1);
			break;

		case RAWKEY_NM_BUTTON_FOURTH | IECODE_UP_PREFIX:
			SDL_SendMouseButton(data->window, 0, SDL_RELEASED, SDL_BUTTON_X1);
			break;

		default:
			if (rawkey < sizeof(amiga_scancode_table) / sizeof(amiga_scancode_table[0])) {
				s = amiga_scancode_table[rawkey];
				if (m->Code <= 127) {
					char text[10];
					int length = AMIGA_TranslateUnicode(m, text);
					SDL_SendKeyboardKey(SDL_PRESSED, s);
					if (length > 0) {
						text[length] = '\0';
						SDL_SendKeyboardText(text);
					}
				} else {
					SDL_SendKeyboardKey(SDL_RELEASED, s);
				}
			}
			break;
	}
}

static void
AMIGA_MouseMove(_THIS, struct IntuiMessage *m, SDL_WindowData *data)
{

	if (!SDL_GetRelativeMouseMode())
	{
		struct Screen *s = data->win->WScreen;
		int x = (s->MouseX - data->win->LeftEdge - data->win->BorderLeft);
		int y = (s->MouseY - data->win->TopEdge - data->win->BorderTop);
		SDL_SendMouseMotion(data->window, 0, 0, x, y);
	}
	else
	{
		if (data->first_deltamove)
		{
			data->first_deltamove = 0;
			return;
		}
		SDL_SendMouseMotion(data->window, 0, 1, m->MouseX, m->MouseY);
	}
}

static void
AMIGA_HandleActivation(_THIS, struct IntuiMessage *m, SDL_bool activated)
{
	SDL_WindowData *data = (SDL_WindowData *)m->IDCMPWindow->UserData;
	if(data->window)
	{
		if (activated)
		{
			SDL_SendWindowEvent(data->window, SDL_WINDOWEVENT_SHOWN, 0, 0);

			if (SDL_GetKeyboardFocus() != data->window)
			{
				SDL_SetKeyboardFocus(data->window);
			}
			SDL_SetMouseFocus(data->window);
			AMIGA_MouseMove(_this, m, data);
		}
		else
		{
			if (SDL_GetKeyboardFocus() == data->window)
			{
				SDL_SetKeyboardFocus(NULL);
			}
			if (SDL_GetMouseFocus() == data->window)
			{
				SDL_SetMouseFocus(NULL);
			}
		}
	}
}

static void
AMIGA_ChangeWindow(_THIS, const struct IntuiMessage *m, SDL_WindowData *data)
{
	struct Window *w = data->win;

	if (data->curr_x != w->LeftEdge || data->curr_h != w->TopEdge)
	{
		data->curr_x = w->LeftEdge;
		data->curr_y = w->TopEdge;
		SDL_SendWindowEvent(data->window, SDL_WINDOWEVENT_MOVED, data->curr_x, data->curr_y);
	}

	if (data->curr_w != w->Width || data->curr_h != w->Height)
	{
		data->curr_w = w->Width;
		data->curr_h = w->Height;
		SDL_SendWindowEvent(data->window, SDL_WINDOWEVENT_RESIZED, (data->curr_w - w->BorderLeft - w->BorderRight), (data->curr_h - w->BorderTop - w->BorderBottom));
		AMIGA_GL_ResizeContext(_this, data->window);
	}
}

static void AMIGA_GadgetEvent(_THIS, const struct IntuiMessage *m)
{
	D("[%s]\n", __FUNCTION__);

	switch (((struct Gadget *)m->IAddress)->GadgetID)
	{
		case ETI_Iconify:
			AMIGA_HideApp(_this, TRUE);
			break;
		/*case ETI_Jump:
			D("[%s] JUMP TO *\n", __FUNCTION__);
			SDL_WindowData *data = (SDL_WindowData *)m->IDCMPWindow->UserData;
			SDL_SetWindowFullscreen(data->window, data->winflags);
			break;*/
	}
}

static const char porters[] = "Bruno Peloille (BeWorld)\nSzilard Biro (BSzili)\n";
static const char bases[] = "SDL 2.0.3 sources by Ilkka Lehtoranta";

static void
AMIGA_AboutSDL(struct Window *window)
{
	struct EasyStruct es;
	es.es_StructSize   = sizeof(struct EasyStruct);
	es.es_Flags        = 0;
	es.es_Title        = "SDL2";
	es.es_TextFormat   = "SDL %ld.%ld.%ld -MorphOS-\nCompiled on " __AMIGADATE__ "\n\nSimple DirectMedia Layer is cross-platform development library designed to\nprovide low level access audio, keyboard, mouse, joysticks, and graphics hardware.\n\nSDL 2.0 is distributed under zlib license.\nThis license allows you to use SDL freely in any software.\n\nPorters:\n%s\nBased on %s\n\nwww.libsdl.org";
	es.es_GadgetFormat = "Ok";

	EasyRequest(window, &es, NULL, SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL, (ULONG)porters, (ULONG)bases);
}

static void
AMIGA_AboutSystem(struct Window *window)
{
	
	struct EasyStruct es;
	es.es_StructSize   = sizeof(struct EasyStruct);
	es.es_Flags        = 0;
	es.es_Title        = "About System";
	es.es_TextFormat   = "System: %s - Vendor: %s\n\nHas Altivec: %s\n";
	es.es_GadgetFormat = "Ok";

	char			System[256];
	char			Vendor[256];

	NewGetSystemAttrs(&System,sizeof(System),SYSTEMINFOTYPE_SYSTEM,TAG_DONE);
	NewGetSystemAttrs(&Vendor,sizeof(Vendor),SYSTEMINFOTYPE_VENDOR,TAG_DONE);

	EasyRequest(window, &es, NULL, System, Vendor, ((HasAltiVec)?"Yes":"No"));
	
}

static void
AMIGA_Joystick(struct Window *window)
{
	char text1[2000] = "";
	char text2[254] = "";
	int i;
    int controller_count = 0;
    char guid[64];
	
	SDL_InitSubSystem(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	
	for (i = 0; i < SDL_NumJoysticks(); ++i) {
    	const char *name;
		char text[254] = "";
		SDL_JoystickGetGUIDString(SDL_JoystickGetDeviceGUID(i),
                                  guid, sizeof (guid));

		SDL_Joystick *joystick = SDL_JoystickOpen(i);
        if (joystick != NULL) 
		{		
			if (SDL_IsGameController(i)) {
				controller_count++;
				name = SDL_GameControllerNameForIndex(i);
			}else{
				name = SDL_JoystickNameForIndex(i);	
			}			
		
			snprintf(text, sizeof(text), "%d: %s (guid %s, VID 0x%.4x, PID 0x%.4x, player index = %d)\n",
				 i, name ? name : "Unknown", guid,
				SDL_JoystickGetDeviceVendor(i), SDL_JoystickGetDeviceProduct(i), SDL_JoystickGetDevicePlayerIndex(i));
			strcat(text1, text);
			snprintf(text, sizeof(text),"    Joystick has %d axes, %d hats, %d balls, and %d buttons\n",
			   SDL_JoystickNumAxes(joystick), SDL_JoystickNumHats(joystick),
			   SDL_JoystickNumBalls(joystick), SDL_JoystickNumButtons(joystick));
			strcat(text1, text);
			 SDL_JoystickClose(joystick);
		}
	}
	
	snprintf(text2, sizeof(text2),"There are %d game controller(s) attached (%d joystick(s))\n", controller_count, SDL_NumJoysticks());
	struct EasyStruct es;
	es.es_StructSize   = sizeof(struct EasyStruct);
	es.es_Flags        = 0;
	es.es_Title        = "SDL2 Joystick/GameController";
	es.es_TextFormat   = "SDL %ld.%ld.%ld -MorphOS-\n\n%s\n%s";
	es.es_GadgetFormat = "Ok";

	EasyRequest(window, &es, NULL, SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL, (ULONG)text2, (ULONG)text1);
}

static void
AMIGA_Priority(ULONG prio)
{
	LONG pri = prio ? -1 : 0;
	NewSetTaskAttrsA(NULL, &pri, sizeof(pri), TASKINFOTYPE_PRI, NULL);	
}

static void
AMIGA_DispatchEvent(_THIS, struct IntuiMessage *m)
{
	SDL_WindowData *data = (SDL_WindowData *)m->IDCMPWindow->UserData;

	switch (m->Class)
	{
		case IDCMP_MENUPICK:
			{
				struct MenuItem *item = ItemAddress(data->menu, m->Code);
				if (item)
				{
					switch ((ULONG)GTMENUITEM_USERDATA(item))
					{
						case MID_ABOUT:
							AMIGA_AboutSDL(data->win);
							break;
						case MID_QUIT:
							SDL_SendWindowEvent(data->window, SDL_WINDOWEVENT_CLOSE, 0, 0);
							break;
						case MID_HIDE:
							AMIGA_HideApp(_this, TRUE);
							break;
						case MID_MUTE:
							AHIAUD_Mute(item->Flags & CHECKED);
							break;
						case MID_PRIORITY:
							AMIGA_Priority(item->Flags & CHECKED);
							break;
						case MID_JOYSTICK:
							AMIGA_Joystick(data->win);
							break;	
						case MID_ABOUTSYS:
							AMIGA_AboutSystem(data->win);
						default:
							break;
					}
				}
			}
			break;
		case IDCMP_REFRESHWINDOW:
			BeginRefresh(m->IDCMPWindow);
			SDL_SendWindowEvent(data->window, SDL_WINDOWEVENT_EXPOSED, 0, 0);
			EndRefresh(m->IDCMPWindow, TRUE);
			break;

		case IDCMP_CLOSEWINDOW:
			SDL_SendWindowEvent(data->window, SDL_WINDOWEVENT_CLOSE, 0, 0);
         break;

		case IDCMP_MOUSEMOVE:
			AMIGA_MouseMove(_this, m, data);
			break;

		case IDCMP_MOUSEBUTTONS:
			AMIGA_DispatchMouseButtons(m, data);
			break;

		case IDCMP_RAWKEY:
			AMIGA_DispatchRawKey(m, data);
			break;

		case IDCMP_ACTIVEWINDOW:
			AMIGA_HandleActivation(_this, m, SDL_TRUE);
			break;

		case IDCMP_INACTIVEWINDOW:
			AMIGA_HandleActivation(_this, m, SDL_FALSE);
			break;

		case IDCMP_CHANGEWINDOW:
			AMIGA_ChangeWindow(_this, m, data);
			break;

		case IDCMP_GADGETUP:
			AMIGA_GadgetEvent(_this, m);
			break;
	}
}

static void
AMIGA_CheckBrokerMsg(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	CxMsg *msg;

	while ((msg = (CxMsg *)GetMsg(&data->BrokerPort)))
	{
		size_t id = CxMsgID(msg);
		size_t tp = CxMsgType(msg);

		D("[%s] check CxMsg\n", __FUNCTION__);

		ReplyMsg((APTR)msg);

		if (tp == CXM_COMMAND)
		{
			switch (id)
			{
				case CXCMD_KILL:
					SDL_SendAppEvent(SDL_QUIT);
					break;

				case CXCMD_APPEAR:
					AMIGA_ShowApp(_this);
					break;

				case CXCMD_DISAPPEAR:
					AMIGA_HideApp(_this, TRUE);
					break;
			}
		}
	}
}

static void
AMIGA_CheckScreenEvent(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;

	for (;;)
	{
		struct ScreenNotifyMessage *snm;

		while ((snm = (struct ScreenNotifyMessage *)GetMsg(&data->ScreenNotifyPort)) != NULL)
		{
			D("[%s] check ScreenNotifyMessage\n", __FUNCTION__);

			switch ((size_t)snm->snm_Value)
			{
				case FALSE:
					AMIGA_HideApp(_this, FALSE);
					break;

				case TRUE:
					AMIGA_ShowApp(_this);
					break;
			}
		}

		if (data->WScreen)
			break;

		WaitPort(&data->ScreenNotifyPort);
	}
}

static void
AMIGA_CheckWBEvents(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	struct AppMessage *msg;
	char filename[1024];
	while ((msg = (struct AppMessage *)GetMsg(&data->WBPort)) != NULL)
	{
		D("[%s] check AppMessage\n", __FUNCTION__);

		switch (msg->am_Type) {
			case AMTYPE_APPWINDOW:
				{
				    SDL_Window *window = (SDL_Window *)msg->am_UserData;
					struct WBArg *argptr = msg->am_ArgList;
				    for (int i = 0; i < msg->am_NumArgs; i++) {
						if (argptr->wa_Lock) {
							NameFromLock(argptr->wa_Lock, filename, 1024);
							AddPart(filename, argptr->wa_Name, 1024);

							D("[%s] SDL_SendDropfile : '%s'\n", __FUNCTION__, filename);
							SDL_SendDropFile(window, filename);
							argptr++;
						}
					}
					SDL_SendDropComplete(window);
				}
				break;
			case AMTYPE_APPICON:
				AMIGA_ShowApp(_this);
				break;
			default:
				//D("[%s] Unknown AppMsg %d %p\n", __FUNCTION__, msg->am_Type, (APTR)msg->am_UserData);
				break;
		}

	}
}

void
AMIGA_PumpEvents(_THIS)
{
	SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
	struct IntuiMessage *m;

	LONG check_mousecoord = 0;
	size_t sigs = SetSignal(0, data->ScrNotifySig | data->BrokerSig | data->WBSig | data->WinSig | SIGBREAKF_CTRL_C);

	if (sigs & data->WinSig)
	{
		SDL_WindowData *wdata;
		while ((m = (struct IntuiMessage *)GetMsg(&data->WinPort)))
		{
			wdata = (SDL_WindowData *)m->IDCMPWindow->UserData;
			if  (m->Class == IDCMP_MOUSEMOVE && !SDL_GetRelativeMouseMode())
			{
				check_mousecoord = TRUE;
			}
			AMIGA_DispatchEvent(_this, m);
			ReplyMsg((struct Message *)m);
		}

		if (check_mousecoord)
		{
			struct Screen *s = wdata->win->WScreen;
			LONG mx = s->MouseX;
			LONG my = s->MouseY;
			LONG ws = wdata->win->LeftEdge + wdata->win->BorderLeft;
			LONG wy = wdata->win->TopEdge + wdata->win->BorderTop;
			LONG wx2 = wdata->win->LeftEdge + wdata->win->Width - wdata->win->BorderRight;
			LONG wy2 = wdata->win->TopEdge + wdata->win->Height - wdata->win->BorderBottom;
			if (mx >= ws && my >= wy && mx <= wx2 && my <= wy2)
			{
				wdata->win->Flags |= WFLG_RMBTRAP;
				
				if (data->CurrentPointer)	
				{
					if (!IS_SYSTEM_CURSOR(data->CurrentPointer))
					{
						SDL_AmigaCursor *ac = (SDL_AmigaCursor *)data->CurrentPointer;
						if (ac->Pointer.mouseptr)
						{
							SetWindowPointer(wdata->win,WA_Pointer,(size_t)ac->Pointer.mouseptr,TAG_DONE);
						}
					}
				}else{
					size_t pointertags[] = { WA_PointerType, POINTERTYPE_INVISIBLE, TAG_DONE };
					SetAttrsA(wdata->win, (struct TagItem *)&pointertags);
				}
				
			}
			else
			{
				wdata->win->Flags &= ~WFLG_RMBTRAP;
				ClearPointer(wdata->win);
			}
		}
	}

	if (sigs & data->ScrNotifySig && data->ScreenNotifyHandle)
		AMIGA_CheckScreenEvent(_this);

	if (sigs & data->BrokerSig)
		AMIGA_CheckBrokerMsg(_this);

	if (sigs & data->WBSig)
		AMIGA_CheckWBEvents(_this);

	if (sigs & SIGBREAKF_CTRL_C)
		SDL_SendAppEvent(SDL_QUIT);
}

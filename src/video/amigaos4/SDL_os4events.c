/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2023 Sam Lantinga <slouken@libsdl.org>

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

#if SDL_VIDEO_DRIVER_AMIGAOS4

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/keymap.h>
#include <proto/wb.h>

#include <workbench/startup.h>

#include "SDL_os4video.h"
#include "SDL_os4shape.h"
#include "SDL_os4mouse.h"
#include "SDL_os4window.h"
#include "SDL_os4events.h"

#include "../../events/SDL_keyboard_c.h"
#include "../../events/SDL_mouse_c.h"
#include "../../events/SDL_windowevents_c.h"
#include "../../events/scancodes_amiga.h"
#include "../../events/SDL_events_c.h"

#undef DEBUG
#include "../../main/amigaos4/SDL_os4debug.h"

extern SDL_bool (*OS4_ResizeGlContext)(SDL_VideoDevice *_this, SDL_Window * window);

struct MyIntuiMessage
{
    uint32 Class;
    uint16 Code;
    uint16 Qualifier;

    struct Gadget *Gadget;
    struct Window *IDCMPWindow;

    int16  RelativeMouseX;
    int16  RelativeMouseY;

    int16  WindowMouseX; // Absolute pointer position, relative to
    int16  WindowMouseY; // top-left corner of inner window

    int16  ScreenMouseX;
    int16  ScreenMouseY;

    int16  Width; // Inner window dimensions
    int16  Height;
};

struct QualifierItem
{
    UWORD qualifier;
    SDL_Keymod keymod;
    const char* name;
};

extern OS4_GlobalMouseState globalMouseState;

static void
OS4_SyncKeyModifiers(SDL_VideoDevice *_this)
{
    int i;

    const UWORD qualifiers = IInput->PeekQualifier();

    const struct QualifierItem map[] = {
        { IEQUALIFIER_LSHIFT, SDL_KMOD_LSHIFT, "Left Shift" },
        { IEQUALIFIER_RSHIFT, SDL_KMOD_RSHIFT, "Right Shift" },
        { IEQUALIFIER_CAPSLOCK, SDL_KMOD_CAPS, "Capslock" },
        { IEQUALIFIER_CONTROL, SDL_KMOD_CTRL, "Control" },
        { IEQUALIFIER_LALT, SDL_KMOD_LALT, "Left Alt" },
        { IEQUALIFIER_RALT, SDL_KMOD_RALT, "Right Alt" },
        { IEQUALIFIER_LCOMMAND, SDL_KMOD_LGUI, "Left Amiga" },
        { IEQUALIFIER_RCOMMAND, SDL_KMOD_RGUI, "Right Amiga" }
    };

    dprintf("Current qualifiers: %u\n", qualifiers);

    for (i = 0; i < SDL_arraysize(map); i++) {
        dprintf("%s %s\n", map[i].name, (qualifiers & map[i].qualifier) ? "ON" : "off");
        SDL_ToggleModState(map[i].keymod, (qualifiers & map[i].qualifier) != 0);
    }
}

static SDL_bool
OS4_IsModifier(SDL_Scancode code)
{
    switch (code) {
        case SDL_SCANCODE_LSHIFT:
        case SDL_SCANCODE_RSHIFT:
        case SDL_SCANCODE_CAPSLOCK:
        case SDL_SCANCODE_LCTRL:
        case SDL_SCANCODE_RCTRL:
        case SDL_SCANCODE_LALT:
        case SDL_SCANCODE_RALT:
        case SDL_SCANCODE_LGUI:
        case SDL_SCANCODE_RGUI:
            return SDL_TRUE;
        default:
            return SDL_FALSE;
    }
}

void
OS4_ResetNormalKeys(void)
{
    SDL_Scancode i = 0;
    int count = 0;
    const Uint8* state = SDL_GetKeyboardState(&count);

    dprintf("Resetting keyboard\n");

    // This is called during fullscreen toggle. Modifier keys keep
    // their state and are synced separately. Releasing all keys could
    // lead to a situation where Alt key would "stick" depending on
    // when user released the key.

    while (i < count) {
        if (state[i] == SDL_PRESSED) {
            if (OS4_IsModifier(i)) {
                dprintf("Ignore pressed modifier key %d\n", i);
            } else {
                SDL_SendKeyboardKey(0, SDL_RELEASED, i);
            }
        }
        i++;
    }
}

// We could possibly use also Window.userdata field to contain SDL_Window,
// and thus avoid searching
static SDL_Window *
OS4_FindWindow(SDL_VideoDevice *_this, struct Window * syswin)
{
    SDL_Window *sdlwin;

    for (sdlwin = _this->windows; sdlwin; sdlwin = sdlwin->next) {

        SDL_WindowData *data = sdlwin->driverdata;

        if (data->syswin == syswin) {

            //dprintf("Found window %p\n", syswin);
            return sdlwin;
        }
    }

    dprintf("No SDL window found\n");

    return NULL;
}

static char
OS4_TranslateUnicode(SDL_VideoDevice *_this, uint16 code, uint32 qualifier)
{
    struct InputEvent ie;
    uint16 res;
    char buffer[10];

    ie.ie_Class = IECLASS_RAWKEY;
    ie.ie_SubClass = 0;
    ie.ie_Code  = code & ~(IECODE_UP_PREFIX);
    ie.ie_Qualifier = qualifier;
    ie.ie_EventAddress = NULL;

    res = IKeymap->MapRawKey(&ie, buffer, sizeof(buffer), 0);

    if (res != 1)
        return 0;
    else
        return buffer[0];
}

static void
OS4_DetectNumLock(const SDL_Scancode s)
{
    static SDL_bool oldState = SDL_FALSE;
    SDL_bool currentState = SDL_FALSE;

    // This function tries to determine whether NumLock is enabled or not,
    // based on the reported scancodes

    switch (s) {
        case SDL_SCANCODE_KP_0:
        case SDL_SCANCODE_KP_1:
        case SDL_SCANCODE_KP_2:
        case SDL_SCANCODE_KP_3:
        case SDL_SCANCODE_KP_4:
        case SDL_SCANCODE_KP_6:
        case SDL_SCANCODE_KP_7:
        case SDL_SCANCODE_KP_8:
        case SDL_SCANCODE_KP_9:
        case SDL_SCANCODE_KP_COMMA:
            currentState = SDL_TRUE;
            dprintf("Numlock on\n");
            break;
        case SDL_SCANCODE_HOME:
        case SDL_SCANCODE_UP:
        case SDL_SCANCODE_PAGEUP:
        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_RIGHT:
        case SDL_SCANCODE_END:
        case SDL_SCANCODE_PAGEDOWN:
        case SDL_SCANCODE_INSERT:
        case SDL_SCANCODE_DELETE:
            dprintf("Numlock off?\n");
            break;
        default:
            return;
    }

    if (currentState != oldState) {
        oldState = currentState;
        dprintf("Toggling numlock state\n");
        SDL_SendKeyboardKey(0, SDL_PRESSED, SDL_SCANCODE_NUMLOCKCLEAR);
    }
}

static void
OS4_HandleKeyboard(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    const uint8 rawkey = imsg->Code & 0x7F;

    if (rawkey < sizeof(amiga_scancode_table) / sizeof(amiga_scancode_table[0])) {

        SDL_Scancode s = amiga_scancode_table[rawkey];

        if (imsg->Code < 0x80) {
            char text[2];

            text[0] = OS4_TranslateUnicode(_this, imsg->Code, imsg->Qualifier);
            text[1] = '\0';

            OS4_DetectNumLock(s);

            SDL_SendKeyboardKey(0, SDL_PRESSED, s);

            if (text[0] && text[0] < 0x80) {
                /* SDL wants UTF-8 strings. Filter out codes above 7-bit to avoid
                interpretation issues later. */
                SDL_SendKeyboardText(text);
            }
        } else {
            SDL_SendKeyboardKey(0, SDL_RELEASED, s);
        }
    }
}

static void
OS4_HandleHitTestMotion(SDL_VideoDevice *_this, SDL_Window * sdlwin, struct MyIntuiMessage * imsg)
{
    HitTestInfo *hti = &((SDL_WindowData *)sdlwin->driverdata)->hti;

    int16 newx = imsg->ScreenMouseX;
    int16 newy = imsg->ScreenMouseY;

    int16 deltax = newx - hti->point.x;
    int16 deltay = newy - hti->point.y;

    int16 x, y, w, h;

    if (deltax == 0 && deltay == 0) {
        return;
    }

    x = sdlwin->x;
    y = sdlwin->y;
    w = sdlwin->w;
    h = sdlwin->h;

    hti->point.x = newx;
    hti->point.y = newy;

    switch (hti->htr) {
        case SDL_HITTEST_DRAGGABLE:
            x += deltax;
            y += deltay;
            break;

        case SDL_HITTEST_RESIZE_TOPLEFT:
            x += deltax;
            y += deltay;
            w -= deltax;
            h -= deltay;
            break;

        case SDL_HITTEST_RESIZE_TOP:
            y += deltay;
            h -= deltay;
            break;

        case SDL_HITTEST_RESIZE_TOPRIGHT:
            y += deltay;
            w += deltax;
            h -= deltay;
            break;

        case SDL_HITTEST_RESIZE_RIGHT:
            w += deltax;
            break;

        case SDL_HITTEST_RESIZE_BOTTOMRIGHT:
            w += deltax;
            h += deltay;
            break;

        case SDL_HITTEST_RESIZE_BOTTOM:
            h += deltay;
            break;

        case SDL_HITTEST_RESIZE_BOTTOMLEFT:
            x += deltax;

            w -= deltax;
            h += deltay;
            break;

        case SDL_HITTEST_RESIZE_LEFT:
            x += deltax;
            w -= deltax;
            break;

        default:
            break;
    }

    dprintf("newx %d, newy %d (dx %d, dy %d) w=%d h=%d\n", newx, newy, deltax, deltay, w, h);

    sdlwin->x = x;
    sdlwin->y = y;
    sdlwin->w = w;
    sdlwin->h = h;

    OS4_SetWindowBox(_this, sdlwin);
}

static SDL_bool
OS4_IsHitTestResize(HitTestInfo * hti)
{
    switch (hti->htr) {
        case SDL_HITTEST_RESIZE_TOPLEFT:
        case SDL_HITTEST_RESIZE_TOP:
        case SDL_HITTEST_RESIZE_TOPRIGHT:
        case SDL_HITTEST_RESIZE_RIGHT:
        case SDL_HITTEST_RESIZE_BOTTOMRIGHT:
        case SDL_HITTEST_RESIZE_BOTTOM:
        case SDL_HITTEST_RESIZE_BOTTOMLEFT:
        case SDL_HITTEST_RESIZE_LEFT:
            return SDL_TRUE;

        default:
            return SDL_FALSE;
    }
}

static void
OS4_HandleMouseMotion(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
        HitTestInfo *hti = &((SDL_WindowData *)sdlwin->driverdata)->hti;

        dprintf("X:%d Y:%d, ScreenX: %d ScreenY: %d\n",
            imsg->WindowMouseX, imsg->WindowMouseY, imsg->ScreenMouseX, imsg->ScreenMouseY);

        globalMouseState.x = imsg->ScreenMouseX;
        globalMouseState.y = imsg->ScreenMouseY;

        if (SDL_GetRelativeMouseMode()) {
            SDL_SendMouseMotion(0, sdlwin, 0 /*mouse->mouseID*/, 1,
                imsg->RelativeMouseX,
                imsg->RelativeMouseY);
        } else {
            SDL_SendMouseMotion(0, sdlwin, 0 /*mouse->mouseID*/, 0,
                imsg->WindowMouseX,
                imsg->WindowMouseY);
        }

        if (hti->htr != SDL_HITTEST_NORMAL) {
            OS4_HandleHitTestMotion(_this, sdlwin, imsg);
        }
    }
}

static SDL_bool
OS4_HandleHitTest(SDL_VideoDevice *_this, SDL_Window * sdlwin, struct MyIntuiMessage * imsg)
{
    if (sdlwin->hit_test) {
        const SDL_Point point = { imsg->WindowMouseX, imsg->WindowMouseY };
        const SDL_HitTestResult rc = sdlwin->hit_test(sdlwin, &point, sdlwin->hit_test_data);

        HitTestInfo *hti = &((SDL_WindowData *)sdlwin->driverdata)->hti;

        switch (rc) {
            case SDL_HITTEST_DRAGGABLE:
            case SDL_HITTEST_RESIZE_TOPLEFT:
            case SDL_HITTEST_RESIZE_TOP:
            case SDL_HITTEST_RESIZE_TOPRIGHT:
            case SDL_HITTEST_RESIZE_RIGHT:
            case SDL_HITTEST_RESIZE_BOTTOMRIGHT:
            case SDL_HITTEST_RESIZE_BOTTOM:
            case SDL_HITTEST_RESIZE_BOTTOMLEFT:
            case SDL_HITTEST_RESIZE_LEFT:
                // Store the action and mouse coordinates for later use
                hti->htr = rc;
                hti->point.x = imsg->ScreenMouseX;
                hti->point.y = imsg->ScreenMouseY;

                return SDL_TRUE;

            default:
                return SDL_FALSE;
        }
    }

    return SDL_FALSE;
}

static int
OS4_GetButtonState(uint16 code)
{
    return (code & IECODE_UP_PREFIX) ? SDL_RELEASED : SDL_PRESSED;
}

static int
OS4_GetButton(uint16 code)
{
    switch (code & ~IECODE_UP_PREFIX) {
        case IECODE_LBUTTON:
            return SDL_BUTTON_LEFT;
        case IECODE_RBUTTON:
            return SDL_BUTTON_RIGHT;
        case IECODE_MBUTTON:
            return SDL_BUTTON_MIDDLE;
        default:
            return 0;
    }
}

static void
OS4_HandleMouseButtons(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
        uint8 button = OS4_GetButton(imsg->Code);
        uint8 state = OS4_GetButtonState(imsg->Code);

        globalMouseState.buttonPressed[button] = state;

        dprintf("X:%d Y:%d button:%d state:%d\n",
            imsg->WindowMouseX, imsg->WindowMouseY, button, state);

        if (button == SDL_BUTTON_LEFT) {
            if (state == SDL_PRESSED) {

                if (OS4_HandleHitTest(_this, sdlwin, imsg)) {
                    return;
                }
            } else {
                HitTestInfo *hti = &((SDL_WindowData *)sdlwin->driverdata)->hti;

                hti->htr = SDL_HITTEST_NORMAL;
                // TODO: shape resize? OpenGL resize?
                SDL_SendWindowEvent(sdlwin, SDL_EVENT_WINDOW_RESIZED,
                    imsg->Width, imsg->Height);
            }
        }

        // TODO: can we support more buttons?
        SDL_SendMouseButton(0, sdlwin, 0, state, button);
    }
}

static void
OS4_HandleMouseWheel(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
        struct IntuiWheelData *data = (struct IntuiWheelData *)imsg->Gadget;

        if (data->WheelY < 0) {
            SDL_SendMouseWheel(0, sdlwin, 0, 0, 1, SDL_MOUSEWHEEL_NORMAL);
        } else if (data->WheelY > 0) {
            SDL_SendMouseWheel(0, sdlwin, 0, 0, -1, SDL_MOUSEWHEEL_NORMAL);
        }

        if (data->WheelX < 0) {
            SDL_SendMouseWheel(0, sdlwin, 0, 1, 0, SDL_MOUSEWHEEL_NORMAL);
        } else if (data->WheelX > 0) {
            SDL_SendMouseWheel(0, sdlwin, 0, -1, 0, SDL_MOUSEWHEEL_NORMAL);
        }
    }
}

static void
OS4_HandleResize(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
        HitTestInfo *hti = &((SDL_WindowData *)sdlwin->driverdata)->hti;

        if (OS4_IsHitTestResize(hti)) {
            // Intuition notifies about resize during hit test action,
            // but it will confuse hit test logic.
            // That is why we ignore these for now.
            dprintf("Resize notification ignored because resize is still in progress\n");
        } else {
            dprintf("Window resized to %d*%d\n", imsg->Width, imsg->Height);

            if (imsg->Width != sdlwin->w || imsg->Height != sdlwin->h) {
                SDL_WindowData *data = (SDL_WindowData *)sdlwin->driverdata;

                SDL_SendWindowEvent(sdlwin, SDL_EVENT_WINDOW_RESIZED,
                    imsg->Width,
                    imsg->Height);

                if (SDL_IsShapedWindow(sdlwin)) {
                    OS4_ResizeWindowShape(sdlwin);
                }

                if (data->glContext /*sdlwin->flags & SDL_WINDOW_OPENGL*/ ) {
                    OS4_ResizeGlContext(_this, sdlwin);
                }
            }
        }
    }
}

static void
OS4_HandleMove(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
            SDL_SendWindowEvent(sdlwin, SDL_EVENT_WINDOW_MOVED,
                imsg->IDCMPWindow->LeftEdge,
                imsg->IDCMPWindow->TopEdge);

        dprintf("Window %p changed\n", sdlwin);
    }
}

static void
OS4_HandleActivation(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg, SDL_bool activated)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
        if (activated) {
            SDL_SendWindowEvent(sdlwin, SDL_EVENT_WINDOW_SHOWN, 0, 0);
            OS4_SyncKeyModifiers(_this);

            if (SDL_GetKeyboardFocus() != sdlwin) {
                SDL_SetKeyboardFocus(sdlwin);
                // TODO: do we want to set mouse colors as in SDL1?
            }
        } else {
            if (SDL_GetKeyboardFocus() == sdlwin) {
                SDL_SetKeyboardFocus(NULL);
                // TODO: do we want to reset mouse colors as in SDL1?
            }
        }

        dprintf("Window %p activation %d\n", sdlwin, activated);
    }
}

static void
OS4_HandleClose(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
       SDL_SendWindowEvent(sdlwin, SDL_EVENT_WINDOW_CLOSE_REQUESTED, 0, 0);
    }
}

static void
OS4_HandleTicks(SDL_VideoDevice *_this, struct MyIntuiMessage * imsg)
{
    SDL_Window *sdlwin = OS4_FindWindow(_this, imsg->IDCMPWindow);

    if (sdlwin) {
        if ((sdlwin->flags & SDL_WINDOW_MOUSE_GRABBED) && !(sdlwin->flags & SDL_WINDOW_FULLSCREEN) &&
            (SDL_GetKeyboardFocus() == sdlwin)) {

            SDL_WindowData *data = sdlwin->driverdata;

            dprintf("Window %p ticks %d\n", imsg->IDCMPWindow, data->pointerGrabTicks);

            // Re-grab the window after our ticks have passed
            if (++data->pointerGrabTicks >= POINTER_GRAB_TIMEOUT) {
                data->pointerGrabTicks = 0;

                OS4_SetWindowGrabPrivate(_this, imsg->IDCMPWindow, TRUE);
            }
        }
    }
}

static void
OS4_HandleGadget(SDL_VideoDevice *_this, struct MyIntuiMessage * msg)
{
    dprintf("Gadget event %p\n", msg->Gadget);

    if (msg->Gadget->GadgetID == GID_ICONIFY) {
        SDL_Window *sdlwin = OS4_FindWindow(_this, msg->IDCMPWindow);

        if (sdlwin) {
            dprintf("Iconify button pressed\n");
            OS4_IconifyWindow(_this, sdlwin);
        }
    }
}

static void
OS4_HandleAppWindow(SDL_VideoDevice *_this, struct AppMessage * msg)
{
    SDL_Window *window = (SDL_Window *)msg->am_UserData;

    int i;
    for (i = 0; i < msg->am_NumArgs; i++) {
        const size_t maxPathLen = 255;
        char buf[maxPathLen];

        if (IDOS->NameFromLock(msg->am_ArgList[i].wa_Lock, buf, sizeof(buf))) {
            if (IDOS->AddPart(buf, msg->am_ArgList[i].wa_Name, sizeof(buf))) {
                dprintf("%s\n", buf);
                SDL_SendDropFile(window, buf, "TODO: file");
            }
        }
    }

    SDL_SendDropComplete(window);
}

static void
OS4_HandleAppIcon(SDL_VideoDevice *_this, struct AppMessage * msg)
{
    SDL_Window *window = (SDL_Window *)msg->am_UserData;
    dprintf("Window ptr = %p\n", window);

    OS4_UniconifyWindow(_this, window);
}

static void
OS4_CopyIdcmpMessage(struct IntuiMessage * src, struct MyIntuiMessage * dst)
{
    // Copy relevant fields. This makes it safer if the window goes away during
    // this loop (re-open due to keystroke)
    dst->Class           = src->Class;
    dst->Code            = src->Code;
    dst->Qualifier       = src->Qualifier;

    dst->Gadget          = (struct Gadget *) src->IAddress;

    dst->RelativeMouseX  = src->MouseX;
    dst->RelativeMouseY  = src->MouseY;

    dst->IDCMPWindow     = src->IDCMPWindow;

    if (src->IDCMPWindow) {
        dst->WindowMouseX = src->IDCMPWindow->MouseX - src->IDCMPWindow->BorderLeft;
        dst->WindowMouseY = src->IDCMPWindow->MouseY - src->IDCMPWindow->BorderTop;

        dst->ScreenMouseX = src->IDCMPWindow->WScreen->MouseX;
        dst->ScreenMouseY = src->IDCMPWindow->WScreen->MouseY;

        dst->Width        = src->IDCMPWindow->Width  - src->IDCMPWindow->BorderLeft - src->IDCMPWindow->BorderRight;
        dst->Height       = src->IDCMPWindow->Height - src->IDCMPWindow->BorderTop  - src->IDCMPWindow->BorderBottom;
    }
}

// TODO: we need to handle Intuition's window move (repositioning) event and update sdlwin's x&y
static void
OS4_HandleIdcmpMessages(SDL_VideoDevice *_this, struct MsgPort * msgPort)
{
    struct IntuiMessage *imsg;
    struct MyIntuiMessage msg;

    while ((imsg = (struct IntuiMessage *)IExec->GetMsg(msgPort))) {

        OS4_CopyIdcmpMessage(imsg, &msg);

        IExec->ReplyMsg((struct Message *) imsg);

        switch (msg.Class) {
            case IDCMP_MOUSEMOVE:
                OS4_HandleMouseMotion(_this, &msg);
                break;

            case IDCMP_RAWKEY:
                OS4_HandleKeyboard(_this, &msg);
                break;

            case IDCMP_MOUSEBUTTONS:
                OS4_HandleMouseButtons(_this, &msg);
                break;

            case IDCMP_EXTENDEDMOUSE:
                OS4_HandleMouseWheel(_this, &msg);
                break;

            case IDCMP_NEWSIZE:
                OS4_HandleResize(_this, &msg);
                break;

            case IDCMP_CHANGEWINDOW:
                OS4_HandleMove(_this, &msg);
                OS4_HandleResize(_this, &msg);
                break;

            case IDCMP_ACTIVEWINDOW:
                OS4_HandleActivation(_this, &msg, SDL_TRUE);
                break;

            case IDCMP_INACTIVEWINDOW:
                OS4_HandleActivation(_this, &msg, SDL_FALSE);
                break;

            case IDCMP_CLOSEWINDOW:
                OS4_HandleClose(_this, &msg);
                break;

            case IDCMP_INTUITICKS:
                OS4_HandleTicks(_this, &msg);
                break;

            case IDCMP_GADGETUP:
                OS4_HandleGadget(_this, &msg);
                break;

            default:
                dprintf("Unknown event received class %d, code %d\n", msg.Class, msg.Code);
                break;
        }
    }
}

static void
OS4_HandleAppMessages(SDL_VideoDevice *_this, struct MsgPort * msgPort)
{
    struct AppMessage *msg;

    while ((msg = (struct AppMessage *)IExec->GetMsg(msgPort))) {
        switch (msg->am_Type) {
            case AMTYPE_APPWINDOW:
                OS4_HandleAppWindow(_this, msg);
                break;
            case AMTYPE_APPICON:
                OS4_HandleAppIcon(_this, msg);
                break;
            default:
                dprintf("Unknown AppMsg %d %p\n", msg->am_Type, (APTR)msg->am_UserData);
                break;
        }

        IExec->ReplyMsg((struct Message *) msg);
    }
}

void
OS4_PumpEvents(SDL_VideoDevice *_this)
{
    SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;

    OS4_HandleIdcmpMessages(_this, data->userPort);
    OS4_HandleAppMessages(_this, data->appMsgPort);
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS4 */

/* vi: set ts=4 sw=4 expandtab: */
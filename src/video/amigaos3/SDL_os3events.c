/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  IDCMP event pump: translate Intuition messages to SDL events.

  Reference: cybergraphx-reference.md -- IDCMP Event Processing section
             crash-patterns.md -- pitfall #10 (ReplyMsg BEFORE processing)

  CRITICAL: ReplyMsg() must be called before any processing that could
  block or allocate memory. The IntuiMessage is in Intuition's memory
  and must be returned promptly.

  Raw key code table: Amiga rawkey codes 0x00-0x77.
  Source: Amiga Hardware Reference Manual (ADCD 2.1), Appendix B.
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include "SDL_os3video.h"
#include "SDL_os3events.h"
#include "../../events/SDL_events_c.h"
#include "../../events/SDL_keyboard_c.h"
#include "../../events/SDL_mouse_c.h"
#include "../../events/SDL_windowevents_c.h"
#include "SDL_keyboard.h"
#include "SDL_mouse.h"

/* Amiga raw key release flag */
#define AMIGA_KEY_UP  0x80

/*
 * Amiga rawkey -> SDL scancode table.
 * Index = rawkey code (0x00 .. 0x77), value = SDL_Scancode.
 * SDL_SCANCODE_UNKNOWN (0) means no mapping.
 *
 * Layout based on Amiga QWERTY keyboard (US layout).
 * Reference: ADCD 2.1 input.device, Appendix B: raw keycodes.
 */
static const SDL_Scancode os3_scancode_table[0x78] = {
    /* 0x00 */ SDL_SCANCODE_GRAVE,       /* ` ~ */
    /* 0x01 */ SDL_SCANCODE_1,
    /* 0x02 */ SDL_SCANCODE_2,
    /* 0x03 */ SDL_SCANCODE_3,
    /* 0x04 */ SDL_SCANCODE_4,
    /* 0x05 */ SDL_SCANCODE_5,
    /* 0x06 */ SDL_SCANCODE_6,
    /* 0x07 */ SDL_SCANCODE_7,
    /* 0x08 */ SDL_SCANCODE_8,
    /* 0x09 */ SDL_SCANCODE_9,
    /* 0x0A */ SDL_SCANCODE_0,
    /* 0x0B */ SDL_SCANCODE_MINUS,
    /* 0x0C */ SDL_SCANCODE_EQUALS,
    /* 0x0D */ SDL_SCANCODE_BACKSLASH,   /* international key left of backspace */
    /* 0x0E */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x0F */ SDL_SCANCODE_KP_0,

    /* 0x10 */ SDL_SCANCODE_Q,
    /* 0x11 */ SDL_SCANCODE_W,
    /* 0x12 */ SDL_SCANCODE_E,
    /* 0x13 */ SDL_SCANCODE_R,
    /* 0x14 */ SDL_SCANCODE_T,
    /* 0x15 */ SDL_SCANCODE_Y,
    /* 0x16 */ SDL_SCANCODE_U,
    /* 0x17 */ SDL_SCANCODE_I,
    /* 0x18 */ SDL_SCANCODE_O,
    /* 0x19 */ SDL_SCANCODE_P,
    /* 0x1A */ SDL_SCANCODE_LEFTBRACKET,
    /* 0x1B */ SDL_SCANCODE_RIGHTBRACKET,
    /* 0x1C */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x1D */ SDL_SCANCODE_KP_1,
    /* 0x1E */ SDL_SCANCODE_KP_2,
    /* 0x1F */ SDL_SCANCODE_KP_3,

    /* 0x20 */ SDL_SCANCODE_A,
    /* 0x21 */ SDL_SCANCODE_S,
    /* 0x22 */ SDL_SCANCODE_D,
    /* 0x23 */ SDL_SCANCODE_F,
    /* 0x24 */ SDL_SCANCODE_G,
    /* 0x25 */ SDL_SCANCODE_H,
    /* 0x26 */ SDL_SCANCODE_J,
    /* 0x27 */ SDL_SCANCODE_K,
    /* 0x28 */ SDL_SCANCODE_L,
    /* 0x29 */ SDL_SCANCODE_SEMICOLON,
    /* 0x2A */ SDL_SCANCODE_APOSTROPHE,
    /* 0x2B */ SDL_SCANCODE_UNKNOWN,     /* international (#~ on UK) */
    /* 0x2C */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x2D */ SDL_SCANCODE_KP_4,
    /* 0x2E */ SDL_SCANCODE_KP_5,
    /* 0x2F */ SDL_SCANCODE_KP_6,

    /* 0x30 */ SDL_SCANCODE_UNKNOWN,     /* international (</> on DE) */
    /* 0x31 */ SDL_SCANCODE_Z,
    /* 0x32 */ SDL_SCANCODE_X,
    /* 0x33 */ SDL_SCANCODE_C,
    /* 0x34 */ SDL_SCANCODE_V,
    /* 0x35 */ SDL_SCANCODE_B,
    /* 0x36 */ SDL_SCANCODE_N,
    /* 0x37 */ SDL_SCANCODE_M,
    /* 0x38 */ SDL_SCANCODE_COMMA,
    /* 0x39 */ SDL_SCANCODE_PERIOD,
    /* 0x3A */ SDL_SCANCODE_SLASH,
    /* 0x3B */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x3C */ SDL_SCANCODE_KP_DECIMAL,
    /* 0x3D */ SDL_SCANCODE_KP_7,
    /* 0x3E */ SDL_SCANCODE_KP_8,
    /* 0x3F */ SDL_SCANCODE_KP_9,

    /* 0x40 */ SDL_SCANCODE_SPACE,
    /* 0x41 */ SDL_SCANCODE_BACKSPACE,
    /* 0x42 */ SDL_SCANCODE_TAB,
    /* 0x43 */ SDL_SCANCODE_KP_ENTER,
    /* 0x44 */ SDL_SCANCODE_RETURN,
    /* 0x45 */ SDL_SCANCODE_ESCAPE,
    /* 0x46 */ SDL_SCANCODE_DELETE,
    /* 0x47 */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x48 */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x49 */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x4A */ SDL_SCANCODE_KP_MINUS,
    /* 0x4B */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x4C */ SDL_SCANCODE_UP,
    /* 0x4D */ SDL_SCANCODE_DOWN,
    /* 0x4E */ SDL_SCANCODE_RIGHT,
    /* 0x4F */ SDL_SCANCODE_LEFT,

    /* 0x50 */ SDL_SCANCODE_F1,
    /* 0x51 */ SDL_SCANCODE_F2,
    /* 0x52 */ SDL_SCANCODE_F3,
    /* 0x53 */ SDL_SCANCODE_F4,
    /* 0x54 */ SDL_SCANCODE_F5,
    /* 0x55 */ SDL_SCANCODE_F6,
    /* 0x56 */ SDL_SCANCODE_F7,
    /* 0x57 */ SDL_SCANCODE_F8,
    /* 0x58 */ SDL_SCANCODE_F9,
    /* 0x59 */ SDL_SCANCODE_F10,
    /* 0x5A */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x5B */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x5C */ SDL_SCANCODE_KP_DIVIDE,
    /* 0x5D */ SDL_SCANCODE_KP_MULTIPLY,
    /* 0x5E */ SDL_SCANCODE_KP_PLUS,
    /* 0x5F */ SDL_SCANCODE_HELP,        /* Amiga Help key */

    /* 0x60 */ SDL_SCANCODE_LSHIFT,
    /* 0x61 */ SDL_SCANCODE_RSHIFT,
    /* 0x62 */ SDL_SCANCODE_CAPSLOCK,
    /* 0x63 */ SDL_SCANCODE_LCTRL,
    /* 0x64 */ SDL_SCANCODE_LGUI,        /* Left Amiga key */
    /* 0x65 */ SDL_SCANCODE_RGUI,        /* Right Amiga key */
    /* 0x66 */ SDL_SCANCODE_LALT,
    /* 0x67 */ SDL_SCANCODE_RALT,
    /* 0x68 */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x69 */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x6A */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x6B */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x6C */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x6D */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x6E */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */
    /* 0x6F */ SDL_SCANCODE_UNKNOWN,     /* (undefined) */

    /* 0x70 */ SDL_SCANCODE_UNKNOWN,
    /* 0x71 */ SDL_SCANCODE_UNKNOWN,
    /* 0x72 */ SDL_SCANCODE_UNKNOWN,
    /* 0x73 */ SDL_SCANCODE_UNKNOWN,
    /* 0x74 */ SDL_SCANCODE_UNKNOWN,
    /* 0x75 */ SDL_SCANCODE_UNKNOWN,
    /* 0x76 */ SDL_SCANCODE_UNKNOWN,
    /* 0x77 */ SDL_SCANCODE_UNKNOWN,
};

/* Translate an IDCMP_RAWKEY code to SDL scancode and send keyboard event. */
static void OS3_HandleRawKey(SDL_Window *sdlwin, UWORD code)
{
    SDL_Scancode scancode;
    Uint8        state;
    UWORD        rawcode;

    if (code & AMIGA_KEY_UP) {
        state   = SDL_RELEASED;
        rawcode = code & ~AMIGA_KEY_UP;
    } else {
        state   = SDL_PRESSED;
        rawcode = code;
    }

    if (rawcode >= 0x78) {
        return; /* out of table */
    }

    scancode = os3_scancode_table[rawcode];
    if (scancode == SDL_SCANCODE_UNKNOWN) {
        return;
    }

    SDL_SendKeyboardKey(state, scancode);
}

/* Translate IDCMP_MOUSEBUTTONS code to SDL mouse button event. */
static void OS3_HandleMouseButton(SDL_Window *sdlwin, UWORD code)
{
    Uint8  state;
    Uint8  button;
    UWORD  btn;

    if (code & IECODE_UP_PREFIX) {
        state = SDL_RELEASED;
        btn   = code & ~IECODE_UP_PREFIX;
    } else {
        state = SDL_PRESSED;
        btn   = code;
    }

    switch (btn) {
    case IECODE_LBUTTON: button = SDL_BUTTON_LEFT;   break;
    case IECODE_RBUTTON: button = SDL_BUTTON_RIGHT;  break;
    case IECODE_MBUTTON: button = SDL_BUTTON_MIDDLE; break;
    default:             return;
    }

    SDL_SendMouseButton(sdlwin, 0, state, button);
}

void OS3_PumpEvents(_THIS)
{
    SDL_Window      *sdlwin;
    OS3_WindowData  *data;
    struct IntuiMessage *imsg;
    ULONG  class;
    UWORD  code;
    WORD   mousex, mousey;
    struct Window *intuiwin;

    /* Walk all open SDL windows and drain their IDCMP queues */
    for (sdlwin = _this->windows; sdlwin; sdlwin = sdlwin->next) {
        data = (OS3_WindowData *)sdlwin->driverdata;
        if (!data || !data->window) {
            continue;
        }

        intuiwin = data->window;

        while ((imsg = (struct IntuiMessage *)GetMsg(intuiwin->UserPort)) != NULL) {
            /* Copy fields BEFORE ReplyMsg -- message memory is Intuition's */
            class  = imsg->Class;
            code   = imsg->Code;
            mousex = imsg->MouseX;
            mousey = imsg->MouseY;

            /* CRITICAL: reply immediately so Intuition can reuse the message */
            ReplyMsg((struct Message *)imsg);

            /* Now process the copied data */
            switch (class) {
            case IDCMP_RAWKEY:
                OS3_HandleRawKey(sdlwin, code);
                break;

            case IDCMP_MOUSEBUTTONS:
                OS3_HandleMouseButton(sdlwin, code);
                break;

            case IDCMP_MOUSEMOVE:
                /* WA_GimmeZeroZero: coordinates are relative to inner area */
                SDL_SendMouseMotion(sdlwin, 0, 0, (int)mousex, (int)mousey);
                break;

            case IDCMP_CLOSEWINDOW:
                SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_CLOSE, 0, 0);
                break;

            case IDCMP_NEWSIZE:
                SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_RESIZED,
                                    (int)intuiwin->GZZWidth,
                                    (int)intuiwin->GZZHeight);
                break;

            case IDCMP_ACTIVEWINDOW:
                SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_FOCUS_GAINED, 0, 0);
                break;

            case IDCMP_INACTIVEWINDOW:
                SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_FOCUS_LOST, 0, 0);
                break;

            default:
                break;
            }
        }
    }
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

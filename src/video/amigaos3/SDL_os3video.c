/*
  SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX)
  Phase 0: Stub -- registers bootstrap, returns success for VideoInit.
  Phase 1: Real CyberGraphX RTG implementation.
*/

#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS3

#include "SDL_os3video.h"
#include "../SDL_sysvideo.h"
#include "../../events/SDL_events_c.h"

#define OS3VID_DRIVER_NAME "amigaos3"

/* Forward declarations */
static int OS3_VideoInit(_THIS);
static void OS3_VideoQuit(_THIS);
static void OS3_DeleteDevice(SDL_VideoDevice *device);
static void OS3_PumpEvents(_THIS);

static SDL_VideoDevice *OS3_CreateDevice(void)
{
    SDL_VideoDevice *device;

    device = (SDL_VideoDevice *)SDL_calloc(1, sizeof(SDL_VideoDevice));
    if (device == NULL) {
        SDL_OutOfMemory();
        return NULL;
    }

    /* Set Phase 0 stub function pointers */
    device->VideoInit = OS3_VideoInit;
    device->VideoQuit = OS3_VideoQuit;
    device->PumpEvents = OS3_PumpEvents;
    device->free = OS3_DeleteDevice;

    /* All other function pointers are NULL (calloc) */
    /* Phase 1 will fill in: CreateSDLWindow, DestroyWindow,
       CreateWindowFramebuffer, UpdateWindowFramebuffer, etc. */

    return device;
}

VideoBootStrap OS3_bootstrap = {
    OS3VID_DRIVER_NAME, "AmigaOS 3.x CyberGraphX/P96",
    OS3_CreateDevice, NULL /* ShowMessageBox */
};

static int OS3_VideoInit(_THIS)
{
    /* Phase 0: just succeed */
    /* Phase 1: OpenLibrary("cybergraphics.library", 41),
       enumerate display modes via NextDisplayInfo() */
    return 0;
}

static void OS3_VideoQuit(_THIS)
{
    /* Phase 0: nothing to clean up */
    /* Phase 1: CloseLibrary(CyberGfxBase), close screens */
}

static void OS3_PumpEvents(_THIS)
{
    /* Phase 0: no-op */
    /* Phase 2: GetMsg(window->UserPort), translate IDCMP -> SDL events */
}

static void OS3_DeleteDevice(SDL_VideoDevice *device)
{
    SDL_free(device);
}

#endif /* SDL_VIDEO_DRIVER_AMIGAOS3 */

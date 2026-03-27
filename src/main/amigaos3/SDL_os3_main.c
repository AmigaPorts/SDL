/*
 * SDL2 Main -- AmigaOS 3.x entry point
 *
 * Handles SDL_main redirection and AmigaOS-specific init.
 */

#include "../../video/amigaos3/SDL_os3video.h"
#include "../../audio/amigaos3/SDL_os3audio.h"

/* Phase 0: Minimal SDL_Init / SDL_Quit */

static int sdl_initialized = 0;

int SDL_Init(unsigned int flags)
{
    (void)flags;

    if (sdl_initialized) {
        return 0;  /* already initialized */
    }

    /* TODO: Initialize requested subsystems based on flags */
    /* For Phase 0, just mark as initialized */

    sdl_initialized = 1;
    return 0;  /* success */
}

void SDL_Quit(void)
{
    if (!sdl_initialized) {
        return;
    }

    OS3_AudioQuit();
    OS3_VideoQuit();

    sdl_initialized = 0;
}

const char *SDL_GetError(void)
{
    /* TODO: Proper error string management */
    return "";
}

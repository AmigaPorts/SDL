/*
 * SDL2 Video Driver -- AmigaOS 3.x (CyberGraphX / Picasso96)
 *
 * Phase 0: Stub -- returns SDL_FALSE for everything.
 * Phase 1: CyberGraphX RTG backend with software renderer.
 * Phase 6: Optional AGA backend with chunky-to-planar.
 */

#include "SDL_os3video.h"

/* Phase 0: Stub implementation */

int OS3_VideoInit(void)
{
    /* TODO Phase 1: Detect CyberGraphX/P96, enumerate display modes */
    return 0;  /* success */
}

void OS3_VideoQuit(void)
{
    /* TODO Phase 1: Close screens, free resources */
}

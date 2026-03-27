/*
 * SDL2 Audio Driver -- AmigaOS 3.x (AHI)
 *
 * Phase 0: Stub.
 * Phase 3: AHI callback-based audio.
 */

#include "SDL_os3audio.h"

int OS3_AudioInit(void)
{
    /* TODO Phase 3: Open AHI, enumerate audio modes */
    return 0;
}

void OS3_AudioQuit(void)
{
    /* TODO Phase 3: Close AHI, free resources */
}

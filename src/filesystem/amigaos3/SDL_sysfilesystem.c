/*
  SDL2 Filesystem -- AmigaOS 3.x (dos.library)
  Phase 0: Stub -- returns NULL for all paths.
  Phase 1+: Real PROGDIR: / ENVARC: paths.
*/

#include "../../SDL_internal.h"

#if SDL_FILESYSTEM_AMIGAOS3

#include "SDL_filesystem.h"
#include "SDL_error.h"

char *SDL_GetBasePath(void)
{
    /* Phase 0: return NULL (not implemented) */
    /* Phase 1+: return PROGDIR: as SDL_strdup'd string */
    return NULL;
}

char *SDL_GetPrefPath(const char *org, const char *app)
{
    /* Phase 0: return NULL (not implemented) */
    /* Phase 1+: return ENVARC:{org}/{app}/ as SDL_strdup'd string */
    (void)org;
    (void)app;
    return NULL;
}

#endif /* SDL_FILESYSTEM_AMIGAOS3 */

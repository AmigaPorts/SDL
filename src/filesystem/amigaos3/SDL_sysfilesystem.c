/*
 * SDL2 Filesystem -- AmigaOS 3.x (dos.library)
 *
 * Phase 0: Stub.
 * Phase 5: dos.library Lock/Examine, PROGDIR:, T: paths.
 */

char *OS3_GetBasePath(void)
{
    /* TODO Phase 5: Use PROGDIR: or GetProgramDir() */
    return 0;
}

char *OS3_GetPrefPath(const char *org, const char *app)
{
    (void)org;
    (void)app;
    /* TODO Phase 5: Use ENVARC: or S: */
    return 0;
}

/* Source: ADCD 2.1
 * Section: v-1-genlockdemo-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-1-genlockdemo-c.md
 */

        struct Screen *screen;
        ULONG modeID = LORES_KEY;
        struct DisplayInfo displayinfo;
        BOOL IsPAL;

        if (GfxBase->LibNode.lib_Version >= 36)
        {
        /*
         * We got V36, so lets use the new calls to find out what
         * kind of videomode the user (hopefully) prefers.
         */

                if (screen = LockPubScreen(screenname))
                {
                        /*
                         * Use graphics.library/GetVPModeID() to get the ModeID of the specified screen.
                         * Will use the default public screen (Workbench most of the time) if NULL It is
                         * _very_ unlikely that this would be invalid, heck it's impossible.
                         */
                        if ((modeID = GetVPModeID(&(screen->ViewPort))) != INVALID_ID)
                        {
                                /*
                                 * If the screen is in VGA mode, we can't tell whether the system is PAL or NTSC. So
                                 * to be fullproof we fall back to the displayinfo of the default.monitor by
                                 * inquiring about just the LORES_KEY displaymode if we don't know. The
                                 * default.monitor reflects the initial video setup of the system, thus is an alias
                                 * for either ntsc.monitor or pal.monitor. We only use the displaymode of the
                                 * specified public screen if it's display mode is PAL or NTSC and NOT the default.
                                 */

                                if (!((modeID & MONITOR_ID_MASK) == NTSC_MONITOR_ID ||
                                      (modeID & MONITOR_ID_MASK) == PAL_MONITOR_ID))
                                        modeID = LORES_KEY;
                        }
                        UnlockPubScreen(NULL, screen);
                } /* if fails modeID = LORES_KEY. Can't lock screen, so fall back on default monitor. */

                if (GetDisplayInfoData(NULL, (UBYTE *) & displayinfo,
                    sizeof(struct DisplayInfo), DTAG_DISP, modeID))
                {
                        if (displayinfo.PropertyFlags & DIPF_IS_PAL)
                            IsPAL = TRUE;
                        else
                            IsPAL = FALSE;  /* Currently the default monitor is always either
                                             * PAL or NTSC.
                                             */
                }
        }
        else /* < V36. The enhancements to the videosystem in V36 cannot be better expressed than
                * with the simple way to determine PAL in V34.
                */
                IsPAL= (GfxBase->DisplayFlags & PAL) ? TRUE : FALSE;

        return(IsPAL);

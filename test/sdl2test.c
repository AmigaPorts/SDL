/*
 * sdl2test.c -- exercises sdl2.library: window, surface drawing and sound
 *
 * Opens PROGDIR:sdl2_*.library, walks a ladder of checks that each name
 * the step that failed, plays cuckoo.raw and fills the window surface
 * with random squares.
 *
 * Links NOTHING of SDL2: every call goes through the library's jump
 * table via the inlines generated from sdl2_lib.fd, so it exercises the
 * real interface. It does include SDL2's headers, because caller and
 * library must agree on struct layout -- the .fd fixes registers, not
 * layout.
 *
 * One fopen/fclose per log line, so if a call takes the machine down the
 * last line names the call that did it.
 *
 * Part of SDL2.Library-Amiga-m68K.
 * Copyright (c) 2026 JennaScvl
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. See LICENCE.MD (zlib License) for the full terms.
 */

#include <exec/types.h>
#include <exec/libraries.h>
#include <exec/execbase.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

struct Library *SDL2Base;

#include "sdl2version.h"

#define LOGPATH "PROGDIR:sdl2test.log"
#define LIBPATH "PROGDIR:" SDL2LIB_NAME
/* An arbitrary sound rather than a synthesised tone. A real recording
 * makes it obvious when playback is actually right, where a sine wave
 * sounds much the same whether the rate, sign or channel count are
 * correct or not.
 *
 * Produced from cuckoo.wav by tools/wav2raw.py:
 *   signed 8-bit mono, 11025 Hz, 13852 samples, 1.26 s.
 * The source rate is kept as-is -- resampling would invent samples and
 * gain nothing, and Paula plays 11025 Hz natively. */
#define RAWPATH  "PROGDIR:cuckoo.raw"
#define SNDRATE  11025
#define SNDMAX   65536

#define WIDTH   640
#define HEIGHT  480
#define SQUARES 150

/*
 * SDL2's TYPES come from SDL2's own headers. Nothing of SDL2 enters the
 * LINK -- every call still goes through the library's jump table -- but
 * the struct layouts must be the ones the library was compiled against.
 *
 * These were hand-copied before, and SDL_Rect was declared as four WORDs
 * when it is four ints: 8 bytes against 16. SDL_FillRect then read x as
 * (x<<16|y), y as (w<<16|h), and w/h from whatever followed on the stack,
 * so every rectangle landed outside the surface and was clipped away.
 * FillRect returned success each time having drawn nothing, and the
 * window stayed black while the log said everything worked.
 *
 * The .fd file guarantees REGISTER marshalling. It guarantees nothing
 * about struct layout -- that agreement has to come from shared headers,
 * so it now does.
 *
 * SDL_MAIN_HANDLED keeps SDL_main.h from redefining main().
 */
#define SDL_MAIN_HANDLED
#include "SDL_rect.h"
#include "SDL_pixels.h"
#include "SDL_surface.h"
#include "SDL_audio.h"
#include "SDL_video.h"
#include "SDL_syswm.h"

/* The generated inlines. AFTER SDL's headers: clib/sdl2_protos.h
 * carries no includes of its own, because fd2pragma copies any it
 * finds into the inline header in a form that is not valid C. */
#include "sdl2.h"

/* SDL_INIT_* live in SDL.h, which also drags in SDL_main.h and the whole
 * API surface. These two flag bits are all we need and they are ABI, not
 * layout -- a wrong value would show up immediately as a failed Init. */
#define SDL_INIT_AUDIO_FLAG 0x00000010UL
#define SDL_INIT_VIDEO_FLAG 0x00000020UL

static void Say(const char *fmt, ...)
{
    va_list ap;
    FILE *f;

    va_start(ap, fmt); vprintf(fmt, ap); va_end(ap);
    f = fopen(LOGPATH, "a");
    if (f) {
        va_start(ap, fmt); vfprintf(f, fmt, ap); va_end(ap);
        fclose(f);
    }
}

static ULONG seed = 2463534242UL;

static ULONG Rnd(ULONG limit)
{
    seed ^= seed << 13; seed ^= seed >> 17; seed ^= seed << 5;
    return seed % limit;
}

/*
 * Display choice comes from a CONFIG FILE, not a compiled-in constant,
 * so it can be changed on the Amiga side without a rebuild -- and so it
 * stays an APPLICATION decision rather than a driver policy.
 *
 * PROGDIR:sdl2test.cfg, one key=value per line:
 *
 *     screen=workbench   normal titled window on the Workbench screen
 *     screen=screen      private screen, borderless window
 *     screen=auto        let the driver's own probe decide (default)
 *
 * The value goes straight to SDL_SetHint as SDL_VIDEO_AMIGAOS3_SCREEN,
 * which the AmigaOS3 driver reads before choosing a screen. Nothing about
 * the choice is compiled into sdl2.library.
 */
#define CFGPATH "PROGDIR:sdl2test.cfg"

static char cfg_screen[32] = "auto";

static void ReadConfig(void)
{
    BPTR f = Open((STRPTR)CFGPATH, MODE_OLDFILE);
    char line[128];

    if (!f) {
        Say("no %s -- screen=%s (default)\n", CFGPATH, cfg_screen);
        return;
    }
    while (FGets(f, (STRPTR)line, sizeof(line))) {
        char *eq, *k, *v, *q;

        for (q = line; *q; q++) {
            if (*q == '#' || *q == ';' || *q == '\n' || *q == '\r') {
                *q = '\0';
                break;
            }
        }
        eq = strchr(line, '=');
        if (!eq) {
            continue;
        }
        *eq = '\0';
        k = line;
        v = eq + 1;
        while (*v == ' ' || *v == '\t') {
            v++;
        }
        if (strcmp(k, "screen") == 0) {
            strncpy(cfg_screen, v, sizeof(cfg_screen) - 1);
            cfg_screen[sizeof(cfg_screen) - 1] = '\0';
        }
    }
    Close(f);
    Say("config: screen=%s\n", cfg_screen);
}


static BYTE sound[SNDMAX];

int main(void)
{
    APTR window, surface;
    SDL_AudioSpec want, have;
    ULONG dev = 0;
    BPTR raw;
    LONG got = 0;
    int i;

    /*
     * Sweep up whatever earlier builds left behind.
     *
     * AmigaOS keeps a library resident after its last client closes, and
     * a run that HANGS never closes it at all -- so an old copy can sit
     * in RAM with OpenCnt > 0 forever. That used to be fatal, because
     * every build was called "sdl2.library" and exec's OpenLibrary finds
     * a resident library BY NAME: the pinned corpse was what came back,
     * with the old jump table, and newly added exports called off the end
     * of it and gurued. The only cure was a reboot.
     *
     * Verified against Kickstart 3.1 (exec OpenLibrary at LVO -552, ROM
     * F81AEC): it is Forbid, FindName on SysBase->LibList, a lib_Version
     * check, then the library's own Open. FindName compares the name
     * byte-for-byte to the NUL -- no path stripping, no case folding.
     *
     * So the fix is the NAME, not the version: each development build is
     * sdl2_r<rev>.library, and an exact-match lookup cannot confuse two
     * of them. A pinned corpse becomes inert rather than dangerous.
     *
     * This sweep is therefore only housekeeping -- it reclaims the memory
     * of builds that CAN still be expunged and reports the ones that
     * cannot. Nothing here has to succeed for the run to be valid.
     *
     * It belongs in a TEST, not in shipping code: a normal program has no
     * business expunging libraries out from under the system.
     */
    {
        struct Library *found[8];
        char  names[8][32];
        UWORD revs[8];
        UWORD opens[8];
        int   n = 0, k;
        struct Node *nd;

        Forbid();
        for (nd = SysBase->LibList.lh_Head; nd->ln_Succ && n < 8;
             nd = nd->ln_Succ) {
            if (nd->ln_Name && strncmp(nd->ln_Name, "sdl2", 4) == 0) {
                found[n] = (struct Library *)nd;
                strncpy(names[n], nd->ln_Name, sizeof(names[0]) - 1);
                names[n][sizeof(names[0]) - 1] = '\0';
                revs[n]  = found[n]->lib_Revision;
                opens[n] = found[n]->lib_OpenCnt;
                n++;
            }
        }
        Permit();

        if (!n)
            Say("no resident sdl2 libraries\n");
        for (k = 0; k < n; k++) {
            if (opens[k]) {
                Say("resident %s rev %d OpenCnt=%d -- pinned by a hung run,"
                    " leaving it (harmless: different name)\n",
                    names[k], (int)revs[k], (int)opens[k]);
            } else {
                Say("resident %s rev %d OpenCnt=0 -- expunging\n",
                    names[k], (int)revs[k]);
                RemLibrary(found[k]);
            }
        }
    }

    Say("sdl2test: opening %s\n", LIBPATH);
    SDL2Base = OpenLibrary((STRPTR)LIBPATH, 0);
    if (!SDL2Base) {
        Say("FAIL: OpenLibrary returned NULL\n");
        return 20;
    }
    /* lib_NegSize is the jump table's size, so NegSize/6 is how many
     * entries exec actually built. Logging it makes a stale library
     * obvious at a glance instead of after a crash. */
    Say("open: '%s' v%d.%d, NegSize=%d (%d entries), PosSize=%d\n",
        SDL2Base->lib_Node.ln_Name,
        (int)SDL2Base->lib_Version, (int)SDL2Base->lib_Revision,
        (int)SDL2Base->lib_NegSize, (int)(SDL2Base->lib_NegSize / 6),
        (int)SDL2Base->lib_PosSize);

    /*
     * Belt and braces. Per-build naming should make this unreachable --
     * the name we asked for encodes the revision we expect -- so if it
     * ever fires, the naming scheme itself is broken and that is worth
     * knowing loudly rather than debugging as a mystery guru.
     */
    if (SDL2Base->lib_Revision != SDL2LIB_REVISION) {
        Say("BUG: opened %s but it reports revision %d, expected %d.\n"
            "The per-build naming scheme is not doing its job.\n",
            LIBPATH, (int)SDL2Base->lib_Revision, SDL2LIB_REVISION);
        CloseLibrary(SDL2Base);
        return 20;
    }

    /* Health check FIRST: this reaches the jump table and nothing else --
     * no SDL2 code, no libc, no data. 142 means the whole library
     * mechanism is sound (ROMTag, MakeFunctions, the table and its
     * terminator, the register ABI, the generated inlines) and any later
     * failure belongs to SDL2 rather than to the interface. */
    Say("SDL2_Ping(100) -> %ld (expect 142)\n", (long)SDL2_Ping(100));

    /*
     * Bisect the init. SDL_Init hung with VIDEO|AUDIO and returned
     * nothing, so take the subsystems one at a time -- each line lands
     * on disk before the next call, so the last line in the log names
     * exactly which subsystem does not come back.
     *
     * SDL_Init is refcounted per subsystem, so calling it repeatedly
     * with different flags is legitimate rather than a trick.
     */
    /*
     * SDL_Init(0) hangs, and with no subsystems requested it does almost
     * nothing except touch SDL2's error buffer -- which is per-thread,
     * so it goes through TLS and locking. These two calls probe that
     * path directly and separately, before Init is involved at all.
     *
     * GetError touches the error buffer and nothing else.
     * Delay touches the timer and nothing else.
     */
    /*
     * BSS check BEFORE anything that could hang. Both must read 0. If
     * they do not, the library's BSS was never cleared, and SDL2's
     * static spinlock in SDL_GetErrBuf starts held -- which makes
     * SDL_AtomicLock spin forever on the first call touching the error
     * buffer. That would explain a hang with no crash and no output.
     */
    Say("SDL2_ProbeBSS -> a=%ld b=%ld (both must be 0)\n",
        (long)SDL2_ProbeBSS(0), (long)SDL2_ProbeBSS(1));

    /*
     * The two primitives SDL_GetErrBuf needs before it can do anything.
     * ProbeSpin uses a local lock (no SDL2 globals); ProbeCAS goes
     * through the EMULATE_CAS path and takes one of SDL2's own static
     * locks[32]. If ProbeSpin passes and ProbeCAS hangs, that array is
     * the culprit.
     */
    Say("SDL2_ProbeSpin() [Forbid/Permit lock]...\n");
    Say("  -> %ld (expect 1)\n", (long)SDL2_ProbeSpin());

    Say("SDL2_ProbeCAS() [EMULATE_CAS, SDL2's locks[32]]...\n");
    Say("  -> %ld (expect 7)\n", (long)SDL2_ProbeCAS());

    /*
     * Spin and CAS both passed, so the atomics are sound and the hang in
     * SDL_GetErrBuf is further along. Walk the rest of that function in
     * the order it runs, cheapest first. Each line reaches disk before
     * the next call, so the last line written names the step that hangs.
     *
     * Malloc comes before the TLS probes on purpose: every TLS call
     * allocates, and a library has no startup module, which makes
     * libnix's heap the thing most likely to differ from a program.
     */
    Say("SDL2_ProbeFindTask() [exec call from library code]...\n");
    Say("  -> %08lx (expect non-zero)\n", (unsigned long)SDL2_ProbeFindTask());

    Say("SDL2_ProbeSem() [InitSemaphore/Obtain/Release]...\n");
    Say("  -> %ld (expect 1)\n", (long)SDL2_ProbeSem());

    Say("SDL2_ProbeMalloc() [libnix heap inside a library]...\n");
    Say("  -> %ld (expect 1; -1 no memory, -2 not writable)\n",
        (long)SDL2_ProbeMalloc());

    Say("SDL2_ProbeTLSCreate() [SDL_AtomicIncRef]...\n");
    Say("  -> %ld (expect non-zero)\n", (long)SDL2_ProbeTLSCreate());

    Say("SDL2_ProbeTLSGet() [SDL_SYS_GetTLSData: FindTask + semaphore]...\n");
    Say("  -> %ld (expect 0)\n", (long)SDL2_ProbeTLSGet());

    Say("SDL2_ProbeTLSSet() [realloc + calloc + list insert]...\n");
    Say("  -> %lx (expect 1234)\n", (unsigned long)SDL2_ProbeTLSSet());

    Say("SDL2_GetError() [error buffer / TLS]...\n");
    {
        const char *e = SDL2_GetError();
        Say("  -> '%s'\n", e ? e : "(null)");
    }

    Say("SDL2_Delay(1) [timer]...\n");
    SDL2_Delay(1);
    Say("  -> returned\n");

    Say("SDL2_Init(0) [no subsystems]...\n");
    Say("  -> %d\n", SDL2_Init(0));

    Say("SDL2_Init(AUDIO)...\n");
    Say("  -> %d\n", SDL2_Init(SDL_INIT_AUDIO_FLAG));

    Say("SDL2_Init(VIDEO)...\n");
    Say("  -> %d\n", SDL2_Init(SDL_INIT_VIDEO_FLAG));

    Say("SDL2_Init(VIDEO|AUDIO)...\n");
    if (SDL2_Init(SDL_INIT_VIDEO_FLAG | SDL_INIT_AUDIO_FLAG) != 0) {
        Say("FAIL: %s\n", SDL2_GetError());
        CloseLibrary(SDL2Base);
        return 20;
    }
    Say("SDL2_Init ok\n");

    /* Read the preference and hand it to SDL BEFORE SDL_CreateWindow --
     * the driver consults the hint while deciding which screen to use. */
    ReadConfig();
    Say("SetHint(SDL_VIDEO_AMIGAOS3_SCREEN, \"%s\") -> %d\n",
        cfg_screen, SDL2_SetHint("SDL_VIDEO_AMIGAOS3_SCREEN", cfg_screen));

    /*
     * Why we get a borderless own-screen window instead of a Workbench
     * one. The driver's test is:
     *
     *   is_cyber = GetCyberMapAttr(wb_bm, CYBRMATTR_ISCYBERGFX)
     *              || GetBitMapAttr(wb_bm, BMA_DEPTH) >= 15
     *   use_wb   = is_cyber && w <= wb->Width && h <= wb->Height
     *
     * On a Picasso96 Workbench every one of those should pass, and SDL 1.2
     * opens a normal window on this same machine, so one of these inputs
     * is not what it looks like. Printed after SDL_Init(VIDEO) because
     * IntuitionBase does not exist before it.
     */
    {
        long cgb   = SDL2_ProbeWB(0);
        long ver   = SDL2_ProbeWB(1);
        long wbw   = SDL2_ProbeWB(2);
        long wbh   = SDL2_ProbeWB(3);
        long depth = SDL2_ProbeWB(4);
        long cyber = SDL2_ProbeWB(5);

        Say("WB check: CyberGfxBase=%08lx '%s' v%ld\n",
            (unsigned long)cgb, SDL2_ProbeWBName(), ver);
        Say("  pubscreen %ldx%ld depth=%ld ISCYBERGFX=%ld\n",
            wbw, wbh, depth, cyber);
        Say("  is_cyber=%d fits=%d -> use_wb=%d\n",
            (int)(cyber || depth >= 15),
            (int)(WIDTH <= wbw && HEIGHT <= wbh),
            (int)((cyber || depth >= 15) && WIDTH <= wbw && HEIGHT <= wbh));
    }

    raw = Open((STRPTR)RAWPATH, MODE_OLDFILE);
    if (raw) {
        got = Read(raw, sound, sizeof(sound));
        Close(raw);
        Say("sound: %ld bytes, %ld ms at %d Hz\n",
            (long)got, (long)(got * 1000L / SNDRATE), SNDRATE);
    } else {
        Say("no %s -- continuing without sound\n", RAWPATH);
    }

    if (got > 0) {
        want.freq = SNDRATE; want.format = AUDIO_S8; want.channels = 1;
        want.silence = 0; want.samples = 1024; want.padding = 0;
        want.size = 0; want.callback = NULL; want.userdata = NULL;

        Say("SDL2_OpenAudioDevice...\n");
        dev = SDL2_OpenAudioDevice(NULL, 0, &want, &have, 0);
        if (!dev) {
            Say("audio did not open: %s\n", SDL2_GetError());
        } else {
            Say("audio dev %lu (freq=%d ch=%d)\n", (unsigned long)dev,
                have.freq, (int)have.channels);
            SDL2_QueueAudio(dev, sound, (ULONG)got);
            SDL2_PauseAudioDevice(dev, 0);
            Say("queued and unpaused\n");
        }
    }

    Say("SDL2_CreateWindow %dx%d...\n", WIDTH, HEIGHT);
    window = SDL2_CreateWindow("sdl2.library test",
                               (int)SDL_WINDOWPOS_CENTERED,
                               (int)SDL_WINDOWPOS_CENTERED,
                               WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        Say("FAIL: CreateWindow: %s\n", SDL2_GetError());
        SDL2_Quit();
        CloseLibrary(SDL2Base);
        return 20;
    }
    Say("window ok\n");

    surface = SDL2_GetWindowSurface(window);
    if (!surface) {
        Say("FAIL: GetWindowSurface: %s\n", SDL2_GetError());
    } else {
        SDL_Surface *surf = (SDL_Surface *)surface;
        SDL_PixelFormat *fmt = surf->format;
        SDL_Palette *pal = fmt->palette;
        long bpp = fmt->BitsPerPixel;

        /*
         * Say what the driver actually gave us before drawing a thing.
         *
         * The AmigaOS3 driver picks its whole strategy from CyberGfxBase:
         * no RTG means an 8-bit CUSTOMSCREEN with a BORDERLESS window and
         * an INDEX8 surface; RTG means ARGB8888. The borderless window
         * says AGA, but says it by inference, and a blank window has a
         * different cause in each case. One line of log settles it.
         *
         * Read straight from the surface: this program has SDL2's headers,
         * so caller and library agree on the layout and no accessor export
         * is needed to look at a struct.
         */
        Say("surface: %dx%d pitch=%d bpp=%ld fmt=%08lx pal=%d colours\n",
            surf->w, surf->h, surf->pitch, bpp,
            (unsigned long)fmt->format, pal ? pal->ncolors : 0);
        if (pal && pal->ncolors > 1) {
            Say("  palette[0]=%02x%02x%02x palette[1]=%02x%02x%02x\n",
                pal->colors[0].r, pal->colors[0].g, pal->colors[0].b,
                pal->colors[1].r, pal->colors[1].g, pal->colors[1].b);
        }

        /*
         * An INDEX8 surface arrives with SDL_AllocPalette's default, which
         * is every one of the 256 entries memset to 0xFF -- identical.
         * SDL_MapRGB on an indexed format is a nearest-colour search, so
         * against a uniform palette EVERY colour returns the same index,
         * every FillRect writes the same byte, and the display is one flat
         * colour no matter what is drawn.
         *
         * Installing a real ramp is the application's job under SDL2, not
         * the library's, which is why it happens here. 3-3-2 is the
         * standard choice: 8 reds x 8 greens x 4 blues across 256 slots.
         */
        if (bpp == 8) {
            if (!pal) {
                Say("  8-bit surface with NO palette -- cannot colour it\n");
            } else {
                static SDL_Color ramp[256];
                int c;

                for (c = 0; c < 256; c++) {
                    ramp[c].r = (Uint8)(((c >> 5) & 7) * 255 / 7);
                    ramp[c].g = (Uint8)(((c >> 2) & 7) * 255 / 7);
                    ramp[c].b = (Uint8)((c & 3) * 255 / 3);
                    ramp[c].a = 255;
                }
                Say("  installing 3-3-2 palette -> %d\n",
                    SDL2_SetPaletteColors(pal, ramp, 0, 256));
                Say("  palette[255]=%02x%02x%02x\n",
                    pal->colors[255].r, pal->colors[255].g, pal->colors[255].b);
            }
        }

        Say("surface ok, drawing %d squares\n", SQUARES);
        for (i = 0; i < SQUARES; i++) {
            SDL_Rect r;
            ULONG colour;

            r.w = (int)(20 + Rnd(80));
            r.h = r.w;
            r.x = (int)Rnd(WIDTH - r.w);
            r.y = (int)Rnd(HEIGHT - r.h);
            {
                ULONG cr = Rnd(256), cg = Rnd(256), cb = Rnd(256);

                colour = SDL2_MapRGB(fmt, cr, cg, cb);
                /* First few only: if distinct RGB triplets all map to the
                 * same value, the palette is uniform and every square is
                 * being painted the same colour. */
                if (i < 4)
                    Say("  MapRGB(%3ld,%3ld,%3ld) -> %lu\n",
                        (long)cr, (long)cg, (long)cb, (unsigned long)colour);
            }
            SDL2_FillRect(surface, &r, colour);
            SDL2_UpdateWindowSurface(window);
            SDL2_Delay(20);
        }
        Say("squares done\n");
    }

    if (dev)
        SDL2_CloseAudioDevice(dev);
    SDL2_DestroyWindow(window);
    Say("SDL2_Quit...\n");
    SDL2_Quit();
    Say("SDL2_Quit returned\n");
    CloseLibrary(SDL2Base);
    Say("closed. DONE.\n");
    return 0;
}

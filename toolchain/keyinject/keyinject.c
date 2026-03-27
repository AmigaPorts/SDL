/* KeyInject -- inject keyboard events into AmigaOS input stream
 *
 * Uses commodities.library AddIEvents() + keymap.library MapANSI()
 * following the canonical ADCD mapansi.c example.
 *
 * Used by the automated FS-UAE test runner (make test-fsemu) to send
 * keystrokes to interactive programs (Category 3+ ports).
 *
 * Usage: KeyInject <comma-separated-key-sequence>
 *   KeyInject q                          - single key
 *   KeyInject SPACE,WAIT500,q            - scroll then quit
 *   KeyInject /,F,I,N,D,M,E,RETURN      - type "/FINDME" + Enter
 *   KeyInject CTRL_X,WAIT300,CTRL_C      - C-x C-c (Emacs quit)
 *   KeyInject ALT_v,WAIT300,q            - M-v (page up) then quit
 *
 * Token types:
 *   Named keys: SPACE, RETURN, ESC, TAB, BACKSPACE, DELETE,
 *               UP, DOWN, LEFT, RIGHT, F1-F10, HELP
 *   Modifier+key: CTRL_<key> (IEQUALIFIER_CONTROL), ALT_<key> (IEQUALIFIER_LALT)
 *     <key> is any single char or named special key
 *     e.g., CTRL_X, CTRL_C, CTRL_SLASH, ALT_g, ALT_v, CTRL_SPACE
 *   Single char: a-z, 0-9, /, ., -, etc. (via MapANSI)
 *   Delay: WAIT<ms> (e.g., WAIT500 = 500ms delay)
 *
 * API references (ADCD 2.1):
 *   - MapANSI()   : keymap.library V37 (Lib_examples/mapansi.c)
 *   - AddIEvents() : commodities.library V37
 *   - Delay()      : dos.library (50 ticks/sec on PAL)
 *   - InputEvent   : devices/inputevent.h
 *   - IECODE_UP_PREFIX (0x80) for key-up events
 *   - IECLASS_RAWKEY (0x01) for keyboard events
 *   - ADCD warns: "contents of input event are destroyed" after
 *     AddIEvents -- must re-populate struct before each injection
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <devices/inputevent.h>
#include <libraries/commodities.h>   /* IEQUALIFIER_CONTROL, IEQUALIFIER_LALT */

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/keymap.h>
#include <proto/commodities.h>

#include <string.h>

static const char *verstag = "$VER: KeyInject 1.1 (24.03.2026)";

/* Library bases -- opened manually, used by proto/ inline stubs */
struct Library *KeymapBase = NULL;
struct Library *CxBase = NULL;

/* Named special key -> Amiga rawkey code mapping.
 * Codes from ADCD: devices/inputevent.h + Keymap Library chapter. */
struct SpecialKey {
    const char *name;
    UWORD code;
};

static const struct SpecialKey specials[] = {
    /* Editing keys */
    {"SPACE",     0x40},
    {"BACKSPACE", 0x41},
    {"TAB",       0x42},
    {"RETURN",    0x44},
    {"ESC",       0x45},
    {"DELETE",    0x46},
    /* Cursor keys */
    {"UP",        0x4C},
    {"DOWN",      0x4D},
    {"RIGHT",     0x4E},
    {"LEFT",      0x4F},
    /* Function keys */
    {"F1",        0x50},
    {"F2",        0x51},
    {"F3",        0x52},
    {"F4",        0x53},
    {"F5",        0x54},
    {"F6",        0x55},
    {"F7",        0x56},
    {"F8",        0x57},
    {"F9",        0x58},
    {"F10",       0x59},
    /* Help key */
    {"HELP",      0x5F},
    /* Sentinel */
    {NULL,        0}
};

/* Default inter-key delay: 2 ticks = 40ms on PAL (50 ticks/sec).
 * Gives the input handler chain time to process each event. */
#define DEFAULT_KEY_DELAY 2

/* Send one rawkey event (key-down then key-up) via AddIEvents.
 * ADCD warns that AddIEvents destroys the InputEvent contents,
 * so we re-populate all fields before each call. */
static void send_rawkey(struct InputEvent *ie, UWORD code, UWORD qualifier)
{
    /* Key-down */
    memset(ie, 0, sizeof(struct InputEvent));
    ie->ie_Class = IECLASS_RAWKEY;
    ie->ie_SubClass = 0;
    ie->ie_Code = code;
    ie->ie_Qualifier = qualifier;
    ie->ie_NextEvent = NULL;
    AddIEvents(ie);

    /* Key-up */
    memset(ie, 0, sizeof(struct InputEvent));
    ie->ie_Class = IECLASS_RAWKEY;
    ie->ie_SubClass = 0;
    ie->ie_Code = code | IECODE_UP_PREFIX;
    ie->ie_Qualifier = qualifier;
    ie->ie_NextEvent = NULL;
    AddIEvents(ie);
}

/* Send one ASCII character using MapANSI() for rawkey conversion.
 * Follows the ADCD mapansi.c example (lines 77-134) exactly.
 * Returns 0 on success, -1 if MapANSI cannot convert the character. */
static int send_char(struct InputEvent *ie, char ch)
{
    UBYTE iebuffer[6];  /* Space for 2 dead keys + 1 key + qualifiers */
    LONG count;
    UBYTE *p;

    /* MapANSI: convert one ASCII char to rawkey code + qualifier.
     * Args: string, length, output buffer, max events, keymap (NULL=default) */
    count = MapANSI((STRPTR)&ch, 1, iebuffer, 3, NULL);
    if (count < 1) {
        Printf((STRPTR)"KeyInject: cannot map character '%lc' (0x%02lx)\n",
               (LONG)ch, (LONG)(unsigned char)ch);
        return -1;
    }

    /* Build InputEvent from MapANSI output.
     * Following mapansi.c: handle dead key sequences (count 2 or 3). */
    memset(ie, 0, sizeof(struct InputEvent));
    ie->ie_Class = IECLASS_RAWKEY;
    ie->ie_NextEvent = NULL;

    p = iebuffer;
    if (count >= 3) {
        ie->ie_Prev2DownCode = *p++;
        ie->ie_Prev2DownQual = *p++;
    }
    if (count >= 2) {
        ie->ie_Prev1DownCode = *p++;
        ie->ie_Prev1DownQual = *p++;
    }
    ie->ie_Code = *p++;
    ie->ie_Qualifier = (UWORD)*p;

    /* Key-down */
    AddIEvents(ie);

    /* Key-up -- ADCD: contents destroyed, must rebuild */
    {
        UWORD saved_code = ie->ie_Code;  /* save before destruction */
        UWORD saved_qual = (UWORD)*p;
        memset(ie, 0, sizeof(struct InputEvent));
        ie->ie_Class = IECLASS_RAWKEY;
        ie->ie_NextEvent = NULL;
        ie->ie_Code = saved_code | IECODE_UP_PREFIX;
        ie->ie_Qualifier = saved_qual;
        AddIEvents(ie);
    }

    return 0;
}

/* Case-insensitive string comparison for key name matching */
static int streq_nocase(const char *a, const char *b)
{
    while (*a && *b) {
        char ca = *a, cb = *b;
        if (ca >= 'a' && ca <= 'z') ca -= 32;
        if (cb >= 'a' && cb <= 'z') cb -= 32;
        if (ca != cb) return 0;
        a++;
        b++;
    }
    return (*a == *b);
}

/* Parse a decimal number from a string */
static LONG parse_number(const char *s)
{
    LONG val = 0;
    while (*s >= '0' && *s <= '9') {
        val = val * 10 + (*s - '0');
        s++;
    }
    return val;
}

/* Send one ASCII character with an additional qualifier (e.g., Ctrl or Alt).
 * Uses MapANSI to get the rawkey code, then ORs in the extra qualifier. */
static int send_char_with_qual(struct InputEvent *ie, char ch, UWORD extra_qual)
{
    UBYTE iebuffer[6];
    LONG count;
    UBYTE *p;
    UWORD code, qual;

    count = MapANSI((STRPTR)&ch, 1, iebuffer, 3, NULL);
    if (count < 1) {
        Printf((STRPTR)"KeyInject: cannot map character '%lc' (0x%02lx)\n",
               (LONG)ch, (LONG)(unsigned char)ch);
        return -1;
    }

    memset(ie, 0, sizeof(struct InputEvent));
    ie->ie_Class = IECLASS_RAWKEY;
    ie->ie_NextEvent = NULL;

    p = iebuffer;
    if (count >= 3) {
        ie->ie_Prev2DownCode = *p++;
        ie->ie_Prev2DownQual = *p++;
    }
    if (count >= 2) {
        ie->ie_Prev1DownCode = *p++;
        ie->ie_Prev1DownQual = *p++;
    }
    code = *p++;
    qual = (UWORD)*p | extra_qual;
    ie->ie_Code = code;
    ie->ie_Qualifier = qual;
    AddIEvents(ie);

    /* Key-up */
    {
        memset(ie, 0, sizeof(struct InputEvent));
        ie->ie_Class = IECLASS_RAWKEY;
        ie->ie_NextEvent = NULL;
        ie->ie_Code = code | IECODE_UP_PREFIX;
        ie->ie_Qualifier = qual;
        AddIEvents(ie);
    }
    return 0;
}

/* Process one token from the comma-separated key sequence */
static int process_token(struct InputEvent *ie, const char *token, LONG len)
{
    char buf[32];
    const struct SpecialKey *sk;
    LONG delay_ms;
    LONG delay_ticks;

    /* Copy token to null-terminated buffer for string comparison */
    if (len <= 0 || len >= (LONG)sizeof(buf)) {
        Printf((STRPTR)"KeyInject: token too long or empty\n");
        return -1;
    }
    memcpy(buf, token, len);
    buf[len] = '\0';

    /* Check for WAIT<ms> delay token */
    if (len > 4 && buf[0] == 'W' && buf[1] == 'A' &&
        buf[2] == 'I' && buf[3] == 'T') {
        delay_ms = parse_number(buf + 4);
        /* Convert ms to ticks: 50 ticks/sec on PAL, so 1 tick = 20ms */
        delay_ticks = delay_ms / 20;
        if (delay_ticks < 1) delay_ticks = 1;
        Delay(delay_ticks);
        return 0;
    }

    /* Check for CTRL_<key> -- sends key with IEQUALIFIER_CONTROL */
    if (len > 5 && buf[0] == 'C' && buf[1] == 'T' && buf[2] == 'R' &&
        buf[3] == 'L' && buf[4] == '_') {
        const char *keypart = buf + 5;
        int klen = len - 5;
        int rc;

        /* Check if keypart is a named special key */
        for (sk = specials; sk->name != NULL; sk++) {
            if (streq_nocase(keypart, sk->name)) {
                send_rawkey(ie, sk->code, IEQUALIFIER_CONTROL);
                Delay(DEFAULT_KEY_DELAY);
                return 0;
            }
        }
        /* Single char with Control qualifier */
        if (klen == 1) {
            rc = send_char_with_qual(ie, keypart[0], IEQUALIFIER_CONTROL);
            if (rc == 0) Delay(DEFAULT_KEY_DELAY);
            return rc;
        }
        Printf((STRPTR)"KeyInject: unknown CTRL_ target '%s'\n", (LONG)keypart);
        return -1;
    }

    /* Check for ALT_<key> -- sends key with IEQUALIFIER_LALT (Meta/Alt) */
    if (len > 4 && buf[0] == 'A' && buf[1] == 'L' && buf[2] == 'T' &&
        buf[3] == '_') {
        const char *keypart = buf + 4;
        int klen = len - 4;
        int rc;

        /* Check if keypart is a named special key */
        for (sk = specials; sk->name != NULL; sk++) {
            if (streq_nocase(keypart, sk->name)) {
                send_rawkey(ie, sk->code, IEQUALIFIER_LALT);
                Delay(DEFAULT_KEY_DELAY);
                return 0;
            }
        }
        /* Single char with Alt qualifier */
        if (klen == 1) {
            rc = send_char_with_qual(ie, keypart[0], IEQUALIFIER_LALT);
            if (rc == 0) Delay(DEFAULT_KEY_DELAY);
            return rc;
        }
        Printf((STRPTR)"KeyInject: unknown ALT_ target '%s'\n", (LONG)keypart);
        return -1;
    }

    /* Check for named special key */
    for (sk = specials; sk->name != NULL; sk++) {
        if (streq_nocase(buf, sk->name)) {
            send_rawkey(ie, sk->code, 0);
            Delay(DEFAULT_KEY_DELAY);
            return 0;
        }
    }

    /* Single character -- use MapANSI for conversion */
    if (len == 1) {
        int rc = send_char(ie, buf[0]);
        if (rc == 0) Delay(DEFAULT_KEY_DELAY);
        return rc;
    }

    Printf((STRPTR)"KeyInject: unknown token '%s'\n", (LONG)buf);
    return -1;
}

int main(int argc, char **argv)
{
    struct InputEvent *ie = NULL;
    const char *seq;
    const char *p;
    const char *token_start;
    LONG rc = 0;

    (void)verstag;

    if (argc < 2) {
        Printf((STRPTR)"KeyInject 1.1 - Inject keyboard events into input stream\n");
        Printf((STRPTR)"Usage: KeyInject <key-sequence>\n");
        Printf((STRPTR)"  key-sequence: comma-separated tokens\n");
        Printf((STRPTR)"  Keys: SPACE RETURN ESC TAB BACKSPACE DELETE\n");
        Printf((STRPTR)"        UP DOWN LEFT RIGHT F1-F10 HELP\n");
        Printf((STRPTR)"        Single chars: a-z 0-9 / . - etc.\n");
        Printf((STRPTR)"  Modifiers: CTRL_<key> (hold Ctrl), ALT_<key> (hold Alt/Meta)\n");
        Printf((STRPTR)"        e.g., CTRL_X CTRL_C ALT_g CTRL_SLASH\n");
        Printf((STRPTR)"  Delay: WAIT<ms> (e.g., WAIT500)\n");
        Printf((STRPTR)"  Example: KeyInject CTRL_X,WAIT300,CTRL_C\n");
        return 5;  /* RETURN_WARN */
    }

    /* Open required libraries (V37 = AmigaOS 2.0+) */
    KeymapBase = OpenLibrary((STRPTR)"keymap.library", 37);
    if (KeymapBase == NULL) {
        Printf((STRPTR)"KeyInject: cannot open keymap.library V37\n");
        rc = 10;
        goto cleanup;
    }

    CxBase = OpenLibrary((STRPTR)"commodities.library", 37);
    if (CxBase == NULL) {
        Printf((STRPTR)"KeyInject: cannot open commodities.library V37\n");
        rc = 10;
        goto cleanup;
    }

    /* Allocate InputEvent in public memory (ADCD requirement) */
    ie = (struct InputEvent *)AllocMem(sizeof(struct InputEvent),
                                       MEMF_PUBLIC | MEMF_CLEAR);
    if (ie == NULL) {
        Printf((STRPTR)"KeyInject: cannot allocate InputEvent\n");
        rc = 10;
        goto cleanup;
    }

    /* Parse and process comma-separated key sequence from argv[1] */
    seq = argv[1];
    p = seq;
    token_start = seq;

    while (*p != '\0') {
        if (*p == ',') {
            if (p > token_start) {
                if (process_token(ie, token_start, p - token_start) != 0) {
                    rc = 10;
                    goto cleanup;
                }
            }
            token_start = p + 1;
        }
        p++;
    }
    /* Process final token (after last comma or entire string) */
    if (p > token_start) {
        if (process_token(ie, token_start, p - token_start) != 0) {
            rc = 10;
            goto cleanup;
        }
    }

cleanup:
    if (ie != NULL)
        FreeMem(ie, sizeof(struct InputEvent));
    if (CxBase != NULL)
        CloseLibrary(CxBase);
    if (KeymapBase != NULL)
        CloseLibrary(KeymapBase);

    return rc;
}

/* UAEQuit — trigger FS-UAE/WinUAE shutdown from inside AmigaOS
 *
 * Calls the UAE emulation library trap function 13 (emulib_ExitEmu).
 * This is the standard way to programmatically quit the emulator.
 *
 * Used by the automated FS-UAE test runner (make test-fsemu) to shut
 * down the emulator after tests complete.
 */

static const char *verstag = "$VER: UAEQuit 1.0 (21.03.2026)";

int main(void)
{
    (void)verstag;

    /* Call UAE trap function 13 (ExitEmu) at the fixed UAELIB_DEMUX
     * address 0xF0FF3C. This is the same mechanism used by the
     * original UAEQuit from Aminet. */
    __asm__ __volatile__ (
        "move.l #13,%%d0\n\t"
        "jsr 0xf0ff3c\n\t"
        :
        :
        : "d0", "d1", "a0", "a1"
    );

    return 0;
}

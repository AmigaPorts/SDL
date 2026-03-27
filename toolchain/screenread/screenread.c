/* ScreenRead -- trigger FS-UAE screen state trap (ADR-025)
 *
 * Fires FS-UAE trap mode 150 to read ConUnit cursor position
 * and screen dimensions. The trap uses unit_logs[] on the host
 * side to find the active console -- ScreenRead does NOT discover
 * the ConUnit itself (it runs in a different process than the
 * program being tested).
 *
 * Requirements: Forked FS-UAE with ADR-025 consolehook trap.
 *
 * Safety: Probes 3 candidate rtarea addresses for A-line trap
 * opcode before calling. Exits cleanly on non-UAE systems.
 */

#include <exec/types.h>
#include <proto/exec.h>
#include <proto/dos.h>

#include <stdio.h>

static const char __attribute__((used)) *verstag =
	"$VER: ScreenRead 1.0 (24.03.2026)";

/* UAE rtarea can be at 3 addresses depending on config (autoconf.h).
 * mousehack_done trap lives at rtarea_base + 0xFF38. */
static const ULONG rtarea_candidates[] = {
	0x00F0FF38UL,  /* RTAREA_DEFAULT (0xF00000) + 0xFF38 */
	0x00EFFF38UL,  /* RTAREA_BACKUP  (0xEF0000) + 0xFF38 */
	0x00DBFF38UL,  /* RTAREA_BACKUP_2 (0xDB0000) + 0xFF38 */
	0
};

static ULONG find_trap_addr(void)
{
	int i;
	UWORD opcode;
	for (i = 0; rtarea_candidates[i]; i++) {
		volatile UWORD *p = (volatile UWORD *)rtarea_candidates[i];
		opcode = *p;
		printf("ScreenRead: probe 0x%08lx -> opcode 0x%04x",
		       (unsigned long)rtarea_candidates[i], (unsigned int)opcode);
		if ((opcode & 0xF000) == 0xA000) {
			printf(" [A-line trap -- FOUND]\n");
			return rtarea_candidates[i];
		}
		printf(" [not A-line]\n");
	}
	return 0;
}

/* Defined in call_screen_trap.s */
extern LONG call_screen_trap(ULONG trap_addr);

int main(void)
{
	ULONG trap_addr;
	LONG result;

	printf("ScreenRead: starting (ADR-025 trap trigger)\n");
	printf("ScreenRead: SysBase = 0x%08lx\n", (unsigned long)SysBase);

	trap_addr = find_trap_addr();
	if (!trap_addr) {
		printf("ScreenRead: ERROR -- no UAE trap found at any candidate address\n");
		printf("ScreenRead: not running in FS-UAE with ADR-025 consolehook?\n");
		fflush(stdout);
		return 10;
	}

	printf("ScreenRead: calling trap at 0x%08lx (D1=150, A1=0)\n",
	       (unsigned long)trap_addr);
	fflush(stdout);

	result = call_screen_trap(trap_addr);

	printf("ScreenRead: trap returned %ld\n", (long)result);
	fflush(stdout);

	if (!result) {
		printf("ScreenRead: ERROR -- trap returned 0 (no ConUnit or no log dir)\n");
		fflush(stdout);
		return 10;
	}

	printf("ScreenRead: SUCCESS -- .screen file written to host\n");
	fflush(stdout);
	return 0;
}

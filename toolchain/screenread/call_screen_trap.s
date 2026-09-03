| call_screen_trap.s -- call FS-UAE mousehack_done mode 150
| Input: trap_addr on stack (4(sp))
| Registers: D1 = mode (150), A1 = 0 (use unit_logs[] auto-detect)
| Returns: D0 = trap result
|
| mousehack_done reads mode from D1 (NOT D0) -- confirmed filesys.cpp:8346.
| A1 = ConUnit address; 0 means auto-detect from unit_logs[].
| The trap at rtarea+0xFF38 is an A-line opcode that triggers the UAE
| trap handler. It executes, sets D0, then falls through to the RTS
| placed after the trap opcode (dw(RTS) in filesys_install).

	.globl	_call_screen_trap
_call_screen_trap:
	move.l	4(sp),a0	| trap address (discovered by find_trap_addr)
	sub.l	a1,a1		| conunit_addr = 0 (auto-detect)
	move.l	#150,d1		| mode 150 (mousehack_done reads D1)
	jsr	(a0)		| fire trap
	rts			| D0 = return value

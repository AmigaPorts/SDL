---
title: SAD/--Overview--
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-overview
functions: [CacheClearU, Forbid]
libraries: [exec.library]
---

# SAD/--Overview--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	Simple Amiga Debugging Kernel, known as "SAD"
	It is in EXEC starting in V39


		-- General description --

 The Simple Amiga Debugging Kernel (SAD) is a set of very simple control
 routines stored in the Kickstart ROM that would let debuggers control the
 Amiga's development enviroment from the outside.  These tools would make
 it possible to do remote machine development/debugging via just the
 on-board serial port.

 This set of control routines is very simple and yet completely flexible,
 thus making it possible to control the whole machine.


		-- Technical Issues --

 SAD will make use of the motherboard serial port that exists in all
 Amiga systems.  The connection via the serial port lets the system be
 able to execute SAD without needing any of the system software up and
 running. (SAD will play with the serial port directly)

 With some minor changes to the Amiga hardware, an NMI-like line could
 be hooked up to a pin on the serial port.  This would let external
 control of the machine and would let the external controller stop the
 machine no matter what state it is in.  (NMI is that way)

 In order to function correctly, SAD requires the some of the EXEC
 CPU control functions work and that [ExecBase](autodocs-3.5/include-exec-execbase-h.md) be valid.  Beyond that,
 SAD does not require the OS to be running.


		-- Command Overview --

 The basic commands needed to operate SAD are as follows:

 [Read](autodocs-3.5/dos-library-read-2.md) and [Write](autodocs-3.5/dos-library-write-2.md) memory as byte, word, and longword.
 Get the register frame address (contains all registers)
 JSR to Address
 Return to system operation  (return from interrupt)

 These basic routines will let the system do whatever is needed.
 Since the JSR to address and memory read/write routines can be used
 to download small sections of code that could be used to do more
 complex things, this basic command set is thus flexible enough
 to even replace itself.

 Caches will automatically be flushed as needed after each write.
 (A call to [CacheClearU()](autodocs-3.5/exec-library-cacheclearu-2.md) will be made after the write and before
 the command done sequence)


		-- Technical Command Descriptions --

 Since the communications with SAD is via a serial port, data formats
 have been defined for minimum overhead while still giving reasonable data
 reliability.  SAD will use the serial port at default 9600 baud but the
 external tools can change the serial port's data rate if it wishes.  It
 would need to make sure that it will be able to reconnect.  SAD sets
 the baud rate to 9600 each time it is entered.  However, while within
 SAD, a simple command to write a WORD to the SERPER register would
 change the baud rate.  This will remain in effect until you exit and
 re-enter SAD or until you change the register again.  (This can be usefull
 if you need to transfer a large amount of data)

 All commands have a basic format that they will follow.  All commands have
 both an ACK and a completion message.

 Basic command format is:

 SENDER:	$AF <command byte> [<data bytes as needed by command>]

 Receive:
 Command ACK:  $00 <command byte>

 Command Done: $1F <command byte> [<data if needed>]

 Waiting: $53 $41 $44 $BF

 Waiting when called from Debug():	$53 $41 $44 $3F

 Waiting when in dead-end crash:	$53 $41 $44 $21

 The data sequence will be that SAD will emit a $BF and then wait for a
 command. If no command is received within <2> seconds, it will emit $BF
 again and loop back.  (This is the "heart beat" of SAD)  When called from
 [Debug()](autodocs-3.5/exec-library-debug-2.md) and not the NMI hook, SAD will use $3F as the "heart beat"

 If SAD does not get a responce after <10> heartbeats, it will return to
 the system.  (Execute an RTS or RTE as needed)  This is to prevent a full
 hang.  The debugger at the other end can keep SAD happy by sending a
 NO-OP command.

 All I/O in SAD times out.  During the transmition of a command, if
 more than 2 seconds pass between bytes of data SAD will time out
 and return to the prompt.  This is mainly to help make sure that
 SAD can never get into an i-loop situation.


		-- Data Structure Issues --

 While executing in SAD, you may have full access to machine from the CPU
 standpoint.  However, this could also be a problem.  It is important to
 understand that when entered via NMI that many system lists may be in
 unstable state.  (NMI can happen in the middle of the [AllocMem](autodocs-3.5/exec-library-allocmem-2.md) routine
 or task switch, etc)

 Also, since you are doing debugging, it is up to you to determin what
 operations can be done and what can not be done.  A good example is
 that if you want to write a WORD or [LONG](autodocs-3.5/include-exec-types-h.md) that the address will need to
 be even on 68000 processors.  Also, if you read or write memory that does
 not exist, you may get a bus error.  Following system structures may
 require that you check the pointers at each step.

 When entered via [Debug()](autodocs-3.5/exec-library-debug-2.md), you are now running as a "task" so you will
 be able to assume some things about system structures.  This means that
 you are in supervisor state and that you can assume that the
 system is at least not between states.  However, remember that since
 you are debugging the system, some bad code could cause data structures
 to be invalid.  Again, standard debugging issues are in play.  SAD just
 gives you the hooks to do whatever you need.

 Note:  When SAD prompts with $BF you will be in full disable/forbid
 state.  When $3F prompting, SAD will only do a [Forbid()](autodocs-3.5/exec-library-forbid-2.md).  It is possible
 for you to then disable interrupts as needed.  This is done such that it
 is possible to "run" the system from SAD when called with [Debug()](autodocs-3.5/exec-library-debug-2.md).


		-- Data Frames and the Registers --

 SAD generates a special data frame that can be used to read what
 registers contain and to change the contents of the registers.
 See the entry for [GET_CONTEXT_FRAME](autodocs-3.5/sad-get-context-frame.md) for more details

 ----------------------------------------------------------------------------
-

 BUGS
	In V39 EXEC, the [WRITE_BYTE](autodocs-3.5/sad-write-byte.md) command was not connected and this
	caused all of the command numbers to be off-by-one.  For example,
	the [READ_WORD](autodocs-3.5/sad-read-word.md) command is listed as command $05 but in V39 is $04.
	However, the ACK of the commands are still correct.

	Also, in V39 EXEC, the [READ_WORD](autodocs-3.5/sad-read-word.md) command would return the wrong
	data.

	To determin if you are in V39 or V40 SAD, you can issue a simple
	SAD command at the start of the session.  By sending a [READ_WORD](autodocs-3.5/sad-read-word.md)
	command, you may either get a [READ_WORD](autodocs-3.5/sad-read-word.md) (V40) or a [READ_LONG](autodocs-3.5/sad-read-long.md) (V39)
	ACK'ed back.  So the data stream for a safe test would be:

	Send: $AF $05 $00 $F8 $00 $00               ; [Read](autodocs-3.5/dos-library-read-2.md) start of ROM...
	Recv: $00 $05 ....   You have V40 SAD
	Recv: $00 $06 ....   You have V39 SAD

	Note that you should be ready to read either 2 or 4 bytes of
	result depending on the ACK sent by the system.

---

## See Also

- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
